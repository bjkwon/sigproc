#include "sigplus_internal.h"
#ifdef _WINDOWS
#include <windows.h>
#endif
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "fftw3.h"
#include <vector>
#include <algorithm>

#include "samplerate.h"
//#include "sndfile.h"
#include "common.h"

#define CRIT  100. // Threshold for computing rms is above 100th of its max

#define RETURN_0_MSG(str) {	strcpy(errstr, str);		return 0;	}

void *PlayBufAsynch16(int DevID, short *dataBuffer, int length, int nChan, int fs, UINT userDefinedMsgID, HWND hApplWnd, int nProgReport, int *errcode, DWORD repeatCount, char* errstr);

double tfraction(0.); // soon to be deleted... 4/23/2016 bjk

void bsortbytmark(CSignal **chains, int nItems)
{
// Bubble sort, ascending order
	int p, q;
	CSignals dummy;
	for (p = 0; p < nItems; p++)
	{
		for (q = 1; q <= p; q++)
		{
			if ((*chains[q-1]).tmark > (*chains[q]).tmark)
			{
				dummy = *chains[q-1];
				*chains[q-1] = *chains[q];
				*chains[q] = dummy;
			}
		}
	}
}

#define DOUBLE2SHORT(x)	((short)(max(min((x),1),-1)*(double)0x007fff))

int _double_to_24bit(double x)
{
	// This maps a double variable raning -1 to 1, to a short variable ranging -16388608 to 16388607.
	return (int)(max(min(x,1),-1)*MAX_24BIT-.5);
}

double _24bit_to_double(int x)
{ // converts a short variable into double in a scale of 16388608.
	return ((double)x+.5)/MAX_24BIT;
}

void _short_to_24bit(short* pshort, int* pint, int len)
{ // Assumes that memory blocks have been prepared.
	for (int i=0; i<len; i++) pint[i] = pshort[i]<<8;
}

void _24bit_to_short(int* pint, short* pshort, int len)
{ // Assumes that memory blocks have been prepared.
	for (int i=0; i<len; i++) pshort[i] = (short)(pint[i]>>8);
}

void _double_to_short(double* dint, short* pshort, int len)
{
	for (int i=0; i<len; i++) 
		pshort[i] = (short)(_double_to_24bit(dint[i]) >> 8);
}

int getmaxIndex (double *x, int len)
{
	int res=0;	
	double cmax=0.;
	for (int i=0; i<len; i++)	
	{
		if ( fabs(x[i]) > cmax )
			{ cmax = fabs(x[i]);	res = i; } 
	}
	return res;
}

void GetIndGreaterThanCrit(double *x, int len, double Crit, int *foundIndices)  
{ // equivalent to find command in Matlab
	int i,j=0;	
	for (i=0; i<len;i++)	
		if (x[i]>Crit)	
			foundIndices[j++] = i; 
		else if (x[i]<-Crit) 
			foundIndices[j++] = i;
}

double _getdB(double x)
{
	// 3 dB is added to make rms of full scale sinusoid 0 dB
	return 20*log10(x) + 3.0103;
}

double getrms (double *x, int len, int *indices) 
{
	int i;
	double cum=0.;
	if (indices==NULL)	// full computation of rms, no selection.
		for (i=0; i<len; i++) 
			cum += x[i]*x[i];
	else
		for (i=0; i<len && indices[i]!=-1; i++)
			cum += x[indices[i]]*x[indices[i]];
	cum /= i;	
	return sqrt(cum);
}

EXP_CS CSignal::CSignal()
:tmark(0), fs(1), BufSize(1), nSamples(0), buf(new double[1]), chain(NULL)
{
}

EXP_CS CSignal::CSignal(const CSignal& src)
:nSamples(0), buf(new double[1]), BufSize(1), chain(NULL)
{
	*this = src;
}


EXP_CS CSignal::CSignal(int sampleRate)
:tmark(0), nSamples(0), fs(max(sampleRate,1)), BufSize(1), buf(new double[1])
{
}

EXP_CS CSignal::~CSignal()
{
	if (buf) {
		delete[] buf; 
		buf=NULL;
	}
	if (chain) {
		delete chain;
		chain=NULL;
	}
}

EXP_CS CSignal& CSignal::UpdateBuffer(int length)	// Set nSamples. Re-allocate buf if necessary to accommodate new length.
{
	if (length < 0 || length == nSamples)
		return *this;
	if ((size_t)length > BufSize || (size_t)length < BufSize/10) {
		BufSize = (size_t)(length*1.1)+1;	// allocate extra space for growth.
		double *newbuf = new double[BufSize];
		if (nSamples>0)
			memcpy(newbuf, buf, sizeof(*buf)*min(nSamples,length));
		delete[] buf;
		buf = newbuf;
	}
	if (length > nSamples)
		memset(buf+nSamples, 0, sizeof(*buf)*(length-nSamples)); //initializing with zeros for the rest
	nSamples = length;
	return *this;
}

EXP_CS CSignal& CSignal::Reset(int fs2set)	// Empty all data fields - sets nSamples to 0.
{
	if (fs2set)	// if fs2set == 0 (default), keep the current fs.
		fs = max(fs2set,1);	// not to allow minus.
	tmark = 0;
	nSamples = 0;
	BufSize = 0;
	if (chain) {
		delete chain;
		chain=NULL;
	}
	//cell should not be cleared here because of CAstSig::SetCell and CAstSig::AddCell calls
	return *this;
}

EXP_CS CSignal& CSignal::operator=(const CSignal& rhs)
{   // Make a deep copy only for buf, but not for sc, because sc is not necessarily dynamically allocated.
	// Thus, BE Extra careful when making writing an assignment statement about the scaling..
	if (this != &rhs) 
	{
		Reset(rhs.fs);
		tmark = rhs.tmark;
		if (rhs.nSamples>0) {
			UpdateBuffer(rhs.nSamples);
			memcpy(buf, rhs.buf, nSamples * sizeof(*buf));
		}
		if (rhs.chain) {
			chain = new CSignals;
			*chain = *rhs.chain;
		}
	}
	return *this; // return self-reference so cascaded assignment works
}

void CSignal::SwapContents1node(CSignals &sec)
{	// swaps  fs, buf(shallow), chain(shallow), tmark, tfraction, BufSize, nSamples  (cell added but not sure if that's OK. bjkwon 4/3/2016)
	// *** Leaves "next" intact!!!
	CSignals tmp(fs);
	tmp.buf = buf, tmp.chain = chain, tmp.tmark = tmark, /*tmp.tfraction = tfraction,*/ tmp.BufSize = BufSize, tmp.nSamples = nSamples,	tmp.cell = cell;// tmp = *this
	fs = sec.fs, buf = sec.buf, chain = sec.chain, tmark = sec.tmark, /*tfraction = sec.tfraction,*/ BufSize = sec.BufSize, nSamples = sec.nSamples, cell = sec.cell;	// *this = sec
	sec.fs = tmp.fs, sec.buf = tmp.buf, sec.chain = tmp.chain, sec.tmark = tmp.tmark, /*sec.tfraction = tmp.tfraction,*/ sec.BufSize = tmp.BufSize, sec.nSamples = tmp.nSamples, sec.cell = tmp.cell; // sec = tmp
	// clean up, so that destructor don't destroy chain and buf which are being used by sec
	tmp.buf = NULL, tmp.chain = NULL, tmp.tmark = 0, /*tmp.tfraction = 0,*/ /*tmp.BufSize = 0,*/ tmp.nSamples = 0;
}

#define SIGNAL_OP(OP, CHAIN_FN) \
CSignal& CSignal::operator OP=(const double con) \
{ \
	for (int i=0; i<nSamples; i++) \
		buf[i] OP= con; \
	if (chain) \
		*chain OP= con; \
	return *this; \
} \
CSignal& CSignal::operator OP=(CSignals &sec) \
{ \
	if (IsSingle() && !sec.IsSingle()) \
		SwapContents1node(sec); \
	if (sec.next && !next) \
		next = new CSignals(*this); \
	if (sec.IsSingle()) { \
		if (IsSingle()) \
			buf[0] = value() OP sec.value(); \
		else \
			*this OP= sec.value(); \
	} else	/* now for two vectors */ \
		CHAIN_FN(&sec); \
	if (sec.next) \
		*next OP= *sec.next; \
	else if (next) \
		*next OP= sec; \
	return *this; \
} \
void CSignal::CHAIN_FN(CSignal *sec) \
{ \
	if (fs != sec->fs) { \
		if (fs>1 && sec->fs<=1) \
			sec->fs = fs; \
		else if (fs<=1 && sec->fs>1) \
			fs = sec->fs; \
		else \
			throw "The sampling rates of both operands must be the same."; \
	} \
	if (tmark > sec->tmark || (tmark == sec->tmark && nSamples < sec->nSamples)) \
		SwapContents1node(*sec); \
	/* now, (tmark <= sec->tmark) is always true */ \
	if (tmark + dur() > sec->tmark)	{ \
		/* overlapping signals */ \
		int id0 = round((sec->tmark-tmark)/1000.*fs); \
		if (nSamples-id0 >= sec->nSamples) { \
			for (int i=0; i<sec->nSamples; i++) \
				buf[id0+i] OP= sec->buf[i]; \
			if (sec->chain) \
				CHAIN_FN(sec->chain); \
		} else { \
			/* sec->buf will get the new samples and be kept */ \
			for (int i=0; i<nSamples-id0; i++) \
				sec->buf[i] OP= buf[id0+i]; \
			UpdateBuffer(id0);	/* waste the rest (overlapping portion) */ \
			if (chain) { \
				sec->CHAIN_FN(chain); \
				delete chain; \
			} \
			chain = new CSignals(); \
			chain->SwapContents1node(*sec); \
		} \
	} else \
		if (chain) { \
			CSignal *p; \
			for (p=chain; p->chain && p->tmark + p->dur() <= sec->tmark; p=p->chain) \
				; \
			p->CHAIN_FN(sec); \
		} else { \
			chain = new CSignals(); \
			chain->SwapContents1node(*sec);	/* swap, so sec will be empty and its destructor will not delete anything. */ \
		} \
}

//SIGNAL_OP(+, PlusChain)
SIGNAL_OP(*, MultChain)


CSignal& CSignal::operator +=(const double con) 
{ 
	for (int i=0; i<nSamples; i++) 
		buf[i] += con; 
	if (chain) 
		*chain += con; 
	return *this; 
} 

CSignal& CSignal::operator +=(CSignal &sec) 
{ 
	CSignal *p(this);
	if (fs != sec.fs) { 
		if (fs>1 && sec.fs<=1) 
			sec.fs = fs; 
		else if (fs<=1 && sec.fs>1) 
			fs = sec.fs; 
		else 
			throw "The sampling rates of both operands must be the same."; 
	} 
	for (; p; p=p->chain)
	{
		if (p->tmark > sec.tmark || (p->tmark == sec.tmark && p->nSamples < sec.nSamples)) 
			p->SwapContents1node(sec); 
		/* now, (tmark <= sec.tmark) is always true */ 
		if (p->tmark + p->dur() >= sec.tmark)	{ 
			/* overlapping signals --- two signals merge to one (not making a separate chain). 3/31/2016 bjkwon*/ 
			// id1: only the first sig, common: both, id2: only the second sig
			int id1 = round((sec.tmark-p->tmark)/1000.*fs); 
			int common = p->nSamples - id1;
			int oldnSamples(p->nSamples); 
			if (sec.nSamples - common > 0)			p->UpdateBuffer(p->nSamples+sec.nSamples-common);
			/* overlapping portion */ 
			for (int i=0; i<common; i++) p->buf[oldnSamples-common+i] += sec.buf[i];
			for (int k=0; k<sec.nSamples-common; k++)	p->buf[oldnSamples+k] = sec.buf[common+k];
			*p->chain += sec.chain;
			break;
		}
		else
		{
			p->AddChain(sec);
			break;
		}
	}
	MergeChains();
	return *this; 
} 


EXP_CS CSignal& CSignal::operator-(void)	// Unary minus
{
	for (int i=0; i<nSamples; i++)
		buf[i] = -buf[i];
	if (chain)	-*chain;
}

EXP_CS CSignal& CSignal::operator/=(CSignals &scaleArray)
{
	
}
EXP_CS CSignal& CSignal::Reciprocal(void)
{
	for (int i=0; i<nSamples; i++)	buf[i] = 1.0/buf[i];
	if (chain)		chain->Reciprocal();
	return *this;
}

EXP_CS double CSignal::alldur()
{
	CSignal *p = GetDeepestChain();
	if (p!=NULL)	return p->tmark + p->dur()+(double)1./fs*1000.;
	else			return tmark+dur()+(double)1./fs*1000.;
}


EXP_CS CSignal& CSignal::operator>>=(const double delta)
{
	if (delta == 0)		return *this;

	if (tmark+delta < 0) {
		// cut off negative time domain
		CSignal *p, *pp;
		double half_atom_time = 500./fs;
		for (pp=p=this; p && p->tmark+delta+p->dur()<=half_atom_time; pp=p, p=p->chain)
			;
		if (p == NULL) {	// nothing in the range.
			Reset();
			return *this;
		}
		if (p != this) {
			pp->chain = NULL;	// to stop destruction at pp. This has to be done before SwapContents1node() for the cases of this==pp. jhpark 5/29/2012.
			SwapContents1node(*p);	// *p gets *this
			delete p;	// delete from head through pp
		}
		if (tmark+delta < 0) {	// patial cut-off
			Truncate(-(tmark+delta), dur());
			tmark = -delta;	// in order to be zero later by tmark+=delta.
		}
	}
	//quantize delta with granularity of fs // 3/31/206 bjkwon
	int pt = round(delta/1000.*fs);
	double newdelta = (double)pt * 1000. / (double)fs;
	tmark += newdelta;
	if (chain)
		*chain>>=delta;
	return *this;
}


EXP_CS CSignal& CSignal::operator<(const CSignals &sec)
{
	if (!IsScalar() || !sec.IsScalar())
		throw "The operands of operator '<' must be scalars.";
	SetValue(value() < sec.value());
	return *this;
}

EXP_CS CSignal& CSignal::operator>(const CSignals &sec)
{
	if (!IsScalar() || !sec.IsScalar())
		throw "The operands of operator '>' must be scalars.";
	SetValue(value() > sec.value());
	return *this;
}

EXP_CS CSignal& CSignal::operator<=(const CSignals &sec)
{
	if (!IsScalar() || !sec.IsScalar())
		throw "The operands of operator '<=' must be scalars.";
	SetValue(value() <= sec.value());
	return *this;
}

EXP_CS CSignal& CSignal::operator>=(const CSignals &sec)
{
	if (!IsScalar() || !sec.IsScalar())
		throw "The operands of operator '>=' must be scalars.";
	SetValue(value() >= sec.value());
	return *this;
}

EXP_CS bool CSignal::operator==(const CSignals &sec) const
{
	if (IsScalar() && sec.IsScalar())
		return (value() == sec.value());
	else if (!IsScalar() && !sec.IsScalar()) {
		if (nSamples != sec.nSamples)
			return false;
		if (memcmp(buf, sec.buf, nSamples*sizeof(*buf)) == 0) {
			if (chain || sec.chain) {
				if (chain && sec.chain) {
					if (*chain != *sec.chain)
						return false;
				} else
					return false;
			}
			if (next || sec.next) {
				if (next && sec.next) {
					if (*next != *sec.next)
						return false;
				} else
					return false;
			}
			return true;
		}
	}
	return false;
}


/*
EXP_CS void CSignal::AddChain(CSignal *sec)
{ // assume that nSamples>1 in both. 
	//MAKE SURE TO AVOID CIRCULAR CHAINING....IT WILL CREATE A STACK OVERFLOW

	if (chain==NULL) chain = sec;	// By jhpark 12/10/2009
	else chain->AddChain(sec);
}
*/

EXP_CS void CSignal::AddChain(CSignals &sec)
{ // assume that nSamples>1 in both. 
	//MAKE SURE TO AVOID CIRCULAR CHAINING....IT WILL CREATE A STACK OVERFLOW

	if (chain==NULL) 
	{
		chain = new CSignals;
		*chain = sec;
	}
	else chain->AddChain(sec);
}

CSignal * CSignal::ExtractDeepestChain(CSignal *dummy)
{
	// breaks and returns the deepest chain. Without dummy it would try to return local variable
	if (chain==NULL) return this;
	else if (chain->chain==NULL) return BreakChain(dummy);
	else return chain->ExtractDeepestChain(dummy);
}

CSignal * CSignal::BreakChain(CSignal *dummy)
{
	// returns the broken chain
	if (chain==NULL) return NULL;
	dummy = chain;
	chain = NULL;
	return dummy;
}

CSignal * CSignal::GetDeepestChain()
{
	CSignal *p;
	for (p=this; p->chain; p=p->chain)
		;
	return p;
}

EXP_CS int CSignal::CountChains()
{
	int res(1);
	CSignal *p;
	for (p=this; p->chain; p=p->chain)
		res++;
	return res;
}

void CSignal::Chain2Array(CSignal **chains, CSignal *forthis)
{
	int res(0);
	CSignal dummy, *out;
	do
	{
		out = ExtractDeepestChain(&dummy);
		if (out==NULL) { *forthis = *this; chains[res] = forthis; }
		else chains[res] = out; 
		res++;
	} while (out!=NULL);
	bsortbytmark(chains, res);
}

EXP_CS double CSignal::alldur()
{
	CSignal *p = GetDeepestChain();
	if (p!=NULL)	return p->tmark + p->dur()+(double)1./fs*1000.;
	else			return tmark+dur()+(double)1./fs*1000.;

}

EXP_CS double CSignal::MakeChainless(double dur, int *pNewFS)
{ //This converts the null intervals of the signal to zero.
	if (pNewFS)
		fs = max(fs, *pNewFS);
	else
		fs = max(fs, 1);
	double totaldur = alldur();	// doing this here as fs might have changed.
	double newdur = max(totaldur, dur);

	if (pNewFS)
		*pNewFS = fs;
	if (!tmark && !chain && totaldur == newdur)	// already chainless && no padding required.
		return newdur;

	CSignals nsig(fs);
	nsig.UpdateBuffer(round(newdur/1000.*fs));
	for (CSignal *p=this; p; p=p->chain) {
		if (p->tmark + p->dur() <= 0)
			continue;
		int iorg = (p->tmark < 0) ? round(-p->tmark/1000.*fs) : 0;
		int inew = (p->tmark > 0) ? round(p->tmark/1000.*fs) : 0;
		int cplen = p->GetLength()-iorg;
		if (inew+cplen > nsig.nSamples) {
			if (p->chain == NULL && inew+cplen == nsig.nSamples+1 && newdur/1000.*fs-nSamples > 0.499999)	// last chain, only 1 sample difference, possile rounding error.
				nsig.UpdateBuffer(nsig.nSamples+1);
			else
				throw "Internal error: Buffer overrun detected.";
		}
		memcpy(nsig.buf+inew, p->buf+iorg, cplen*sizeof(*buf));
	}
	SwapContents1node(nsig);	// *this gets the chainless signal, nsig gets the chained signal and will be destroyed soon.
	return newdur;
}

EXP_CS const CSignal& CSignal::operator+=(CSignal *yy)
{ 
	// Concatenation of CSignals
  // yy might lose its value.

	if (fs!=yy->fs) throw "(operator+=) Both operands must have the same fs";

	CSignal *ptail = this;
	for (; ptail->chain; ptail=ptail->chain)	// get the tail of *this.
		;
	if (yy->chain || yy->tmark ) {
		// when insertee has chain(s), chain it instead of copying. yy loses its value.
		CSignal *pNew = new CSignal();
		/*I really don't know what this if loop is...  5/11/2016 bjk*/
//		if (next && !yy->next)
//			*pNew = *yy;	// make a copy, leaving the original intact for the next channel
//		else
			pNew->SwapContents1node(*yy);		// pNew takes the insertee. As yy lost all its pointers, yy can be destroyed later without destroying any data it used to have.
		*pNew >>= ptail->tmark+ptail->dur();	// to make the insertee the next chain(s) of ptail.
		ptail->chain = pNew;					// link it to *this.
	} else {
		// otherwise, just copy at the end.
		int nSamples0 = ptail->nSamples;
		ptail->UpdateBuffer(yy->nSamples + nSamples0);
		if (yy->nSamples>0)
			memcpy(ptail->buf+nSamples0, yy->buf, yy->nSamples*sizeof(*buf));
	}
	return *this;
}

EXP_CS double CSignal::RMS()
{ // This does not go into next.... for stereo signals, call RMS specifically, like next->RMS()  bjk 4/23/2016
	double cum(0);
	int count(0);
	for (CSignal *p=this; p; p=p->chain)
		for (int i=0; i<p->nSamples; ++i, ++count) 
			cum += p->buf[i] * p->buf[i];
	return _getdB(sqrt(cum/count));
}

EXP_CS CSignal& CSignal::Interp(const CSignal& gains, const CSignal& tmarks)
{
	if (gains.nSamples!=tmarks.nSamples)
		throw "The length of both arguments of interp( ) must be the same.";
	int id1(0), id2;
	double gain1(0.), slope;
	int newSampleCount = round(tmarks.buf[tmarks.nSamples-1]/1000.*fs);
	Reset();
	UpdateBuffer(newSampleCount);
	for (int i=0; i<tmarks.nSamples; i++)
	{
		id2 = round(tmarks.buf[i]/1000.*fs);
		slope = (gains.buf[i]-gain1) / (id2-id1);
		for (int j=id1; j<id2; j++) 
			buf[j] = slope * (j-id1) + gain1;
		gain1 = gains.buf[i];
		id1 = id2;
	}
	return *this;
}

EXP_CS CSignal& CSignal::Take(CSignal& out, int id1)
{ // if ending point is missed, it assumes the end of the whole duration.
	if (id1==0) {out = *this; return out;}
	return Take(out, id1, nSamples-1);
}

EXP_CS CSignal& CSignal::Take(CSignal& out, double begin_ms)
{ // if ending point is missed, it assumes the end of the whole duration.
	int id1 = round(begin_ms/1000.*fs);
	return Take(out, id1, nSamples-1);
}

EXP_CS CSignal& CSignal::Take(CSignal& out, int id1, int id2)
{
	id2 = min (nSamples, id2);
	if (id2<id1)		return *this;
	out.Reset();
	int nSamplesNeeded = id2-id1+1;
	out.UpdateBuffer(nSamplesNeeded);
	memcpy((void*)&out.buf[-min(0,id1)], (void*)&buf[max(0,id1)], sizeof(double)*(id2-max(0,id1)+1));
	return out;
}

EXP_CS CSignal& CSignal::Take(CSignal& out, double begin_ms, double end_ms)
{ /* if id1 is negative, zero's are added before the wave form.
  if id2 is greater than current length, the end of current array will be taken.
	
// If there's an error, extracting is not happening and this pointer will be the output.
// Error will occur in one of the following:
	1) when id2 is the same or smaller than id1.
*/
	int id1 = round(begin_ms/1000.*fs);
	int id2 = round(end_ms/1000.*fs)-1;
	Take(out, id1, id2);
//	out.tfraction = (end_ms-begin_ms) - (id2-id1+1)/(double)fs*1000.;
	return out;
}

EXP_CS CSignal& CSignal::MergeChains()
{// This tidy things up by removing unnecessary chains and rearranging them.
	CSignal temp, *p(this);
	if (nSamples==0 && chain) {temp = *chain; chain=NULL; *this = temp; }

	for (; p && p->chain; p=p->chain)
		if (p->tmark+p->dur()>=p->chain->tmark) // consolidate 
		{
			temp = *p->chain;
			int id1 = round((temp.tmark-p->tmark)/1000.*fs); 
			int common = p->nSamples - id1;
			int id2 = temp.nSamples - common;
			int oldnSamples(p->nSamples); 
			p->UpdateBuffer(p->nSamples+temp.nSamples-common);
			/* overlapping portion */ 
			for (int i=0; i<common; i++) 
				p->buf[oldnSamples-common+i] += temp.buf[i];
			for (int k=0; k<temp.nSamples-common; k++)
				p->buf[oldnSamples+k] = temp.buf[common+k];
			if (temp.chain==NULL)	p->chain = NULL;
			else *p->chain = *temp.chain; // deep copy is necessary (we are losing p).
		}

	return *this;

}

EXP_CS CSignal& CSignal::MakeChains(vector<double> tmarks)
{
	CSignals out, parts, copy(*this), *p;
	out.Reset(fs);
	for (vector<double>::reverse_iterator iter=tmarks.rbegin(); iter!=tmarks.rend(); iter +=2)
	{
		parts.Reset(fs);
		Take(parts, 0., *(iter+1)-*iter);
		if (out.nSamples==0) out = parts;
		else out.AddChain(parts);
	}
	p=&out;
	if (p->chain)
	{
		vector<double>::reverse_iterator iter=tmarks.rbegin()+2;
		p=p->chain;
		for(; p && iter!=tmarks.rend(); p=p->chain, iter +=2)
			p->tmark = *iter-tmarks.back();
	}
	return (*this = out);
}

EXP_CS CSignal& CSignal::Trim(double begin_ms, double end_ms)
{
	vector<double> tmarks;
	CSignals old(*this), old2(*this), dummy;
	if (begin_ms >= end_ms) {
		Trim(end_ms, begin_ms);
		ReverseTime();
		return *this;
	}
	// for subsequent channels
	if (next)		next->Trim(begin_ms, end_ms);

	if (CountChains()>1)
	{
		CSignal *extracted;
		bool loop(true);
		while( (extracted = old.ExtractDeepestChain(&dummy))!=&old || loop )
		{
			tmarks.push_back(extracted->tmark + extracted->dur());
			tmarks.push_back(extracted->tmark);
			if (extracted == &old) loop = false;
		}
		MakeChainless();
	}
	double endtime = tmark + dur();
	if (begin_ms>=tmark && end_ms<=endtime) // normal
	{
		int ind1 = (int)((begin_ms-tmark)/1000.*fs);
		int ind2 = min((int)((end_ms-tmark)/1000.*fs), nSamples-1);
		int nSamplesNeeded = ind2-ind1+1;
		UpdateBuffer(nSamplesNeeded);
		for (int k=0; k<nSamplesNeeded; k++) buf[k] = old2.buf[ind1+k];
		tmark=0;
	}
	else if (begin_ms>=tmark) // (begin_ms>=tmark && end_ms>endtime)
	{
		Trim(begin_ms, endtime);
	}
	else if (end_ms<=endtime) // (begin_ms<tmark && end_ms<=endtime)
	{
		double _tmark = tmark;
		Trim(tmark, end_ms);
		tmark = _tmark;
	}
	else 
	{
		double _tmark = tmark;
		Trim(tmark, endtime);
		tmark = _tmark;
	}
	if (CountChains()>1)
	{
		tmarks.erase(remove_if(tmarks.begin(), tmarks.end(), [begin_ms](double x){return (x<=begin_ms);}), tmarks.end());
		tmarks.erase(remove_if(tmarks.begin(), tmarks.end(), [end_ms](double x){return (x>=end_ms);}), tmarks.end());
		tmarks.insert(tmarks.begin(),end_ms);//This is the problem spot.... 4/24/12:35am
		tmarks.push_back(begin_ms);
		MakeChains(tmarks);
	}
	return *this;
}

EXP_CS void CSignal::Dramp(double dur_ms, int beginID)
{
	if (chain!=NULL) chain->Dramp(dur_ms, beginID);
	// Cosine square ramping and damping of the array
	double x, drampFs ;
	int nSamplesNeeded;

	drampFs = 1.e3/(4.*dur_ms);
	nSamplesNeeded = round(dur_ms/1000.*fs); 
	nSamplesNeeded = min (nSamples, nSamplesNeeded);

	for (int i=0; i<nSamplesNeeded; i++)
	{
		x = sin(2*PI*drampFs*(double)i/(double)fs);
		buf[beginID+i] = x * x * buf[beginID+i];
		buf[nSamples-i-1] = x * x * buf[nSamples-i-1]; 
	}
}

EXP_CS double * CSignal::Modulate (double *env, int lenEnv)
{
	// Modulate this object with env 
	// If lenEnv may be greater than nSamples, then the samples in env after nSamples are ignored.
	for (int i=0; i<nSamples && i<lenEnv; i++)	
		buf[i] *= env[i];
	return buf;
}

EXP_CS double * CSignal::Modulate (CSignal &secondsignal)
{ // Takes only first channel of secondsignal for modulation
	// New length is determined by the shorter signal
	double *buf2 = secondsignal.GetBuffer();
	for (int i=0; i<nSamples && i<secondsignal.GetLength(); i++)
		buf[i] *= secondsignal.buf[i];
	return buf;
}

EXP_CS double * CSignal::Noise(double dur_ms)
{
	int nSamplesNeeded = round(dur_ms/1000.*fs);
	double *p = Noise(nSamplesNeeded);
	tfraction = dur_ms - nSamplesNeeded/(double)fs*1000.;
	return p;
}

EXP_CS double * CSignal::Noise(int nsamples)
{
	Reset();
	UpdateBuffer(nsamples); //allocate memory if necessary
	for (int i=0; i<nsamples; i++)
	{
		buf[i] = 2.*((double)rand()/(double)RAND_MAX-.5);
//		buf[i] = _double_to_24bit(x);
	}
	return buf;
}

EXP_CS double * CSignal::Noise2 (double dur_ms)
{ //Gaussian noise
	int nSamplesNeeded = round(dur_ms/1000.*fs); 
	double *p = Noise2(nSamplesNeeded);
	tfraction = dur_ms - nSamplesNeeded/(double)fs*1000.;
	return p;
}

EXP_CS double * CSignal::Noise2 (int nsamples)
{ //Gaussian noise
	double fac, r, v1, v2, sum(0.);
	Reset();
	UpdateBuffer(nsamples); //allocate memory if necessary
	for (int i=0; i<nsamples; i++)
	{
		if (i==5557) v1=10.;
		do {
			do {
					v1 = (2.0 * (double)rand()/(double)RAND_MAX ) - 1.0;
					v2 = (2.0 * (double)rand()/(double)RAND_MAX ) - 1.0;
					r = (v1*v1) + (v2*v2);
				} while (r >= 1.0);
			fac = sqrt(-2.0 * log(r) / r);
		} while (v2*fac>=1.0 || v2*fac<=-1.0);
		buf[i] = v2*fac;
		sum += v2*fac;
	}
	return buf;
}

EXP_CS double * CSignal::fm(double midFreq, double fmWidth, double fmRate, int nsamples, double beginFMPhase)
{   // beginFMPhase is to be set. (beginPhase is zero here ==> Its not so meaningful to set both of them)
	double t;
	Reset();
	UpdateBuffer(nsamples); //allocate memory if necessary
	for (int i=0; i<nsamples; i++)
	{
		t = (double)i/(double)fs;
		buf[i] = sin(2*PI*t*midFreq-fmWidth/fmRate*cos(2*PI*(fmRate*t+beginFMPhase)));
	}
	return buf;
}

EXP_CS double * CSignal::fm(double midFreq, double fmWidth, double fmRate, double dur_ms, double beginFMPhase)
{   
	int nSamplesNeeded = round(dur_ms/1000.*fs); 
	double *p = fm(midFreq, fmWidth, fmRate, nSamplesNeeded, beginFMPhase);
	tfraction = dur_ms - nSamplesNeeded/(double)fs*1000.;
	return p;
}


//beginPhase is normalized. 1.0 == full phase (2*PI)

EXP_CS double * CSignal::Tone(double *freq, int nsamples, double beginPhase)
{//Frequency glide: freq is a two-element array with beginning freq and ending freq
	double t, glidelta(freq[1] - freq[0]),  duration((double)nsamples/(double)fs);
	Reset();
	UpdateBuffer(nsamples); //allocate memory if necessary
	for (int i=0; i<nsamples; i++)
	{
		t = (double)i/(double)fs;
		buf[i] = sin(2*PI*t*(freq[0]+glidelta/2./duration*t+beginPhase)); // check the phase
	}
	return buf;
}

EXP_CS double * CSignal::Tone(double *freq, double dur_ms, double beginPhase)
{
	int nSamplesNeeded = round(dur_ms/1000.*fs); 
	double *p = Tone(freq, nSamplesNeeded, beginPhase);
	tfraction = dur_ms - nSamplesNeeded/(double)fs*1000.;
	return p;
}

EXP_CS double * CSignal::Tone(double freq, int nsamples, double beginPhase)
{
	Reset();
	UpdateBuffer(nsamples); //allocate memory if necessary
	for (int i=0; i<nsamples; i++)
		buf[i] = sin(2*PI*(freq*(double)i/(double)fs+beginPhase));
	return buf;
}

EXP_CS double * CSignal::Tone(double freq, double dur_ms, double beginPhase)
{
	int nSamplesNeeded = round(dur_ms/1000.*fs);
	double *p = Tone(freq, nSamplesNeeded, beginPhase);
	tfraction = dur_ms - nSamplesNeeded/(double)fs*1000.;
	return p;
}

EXP_CS double * CSignal::Truncate(double time_ms1, double time_ms2)
{ // Returns integer buffer pointer, to "extract" a signals object, use Take() member function
	int id1 = round(time_ms1/1000.*fs);
	int id2 = round(time_ms2/1000.*fs)-1;
	tfraction = (time_ms2-time_ms1) - (id2-id1+1)/(double)fs*1000.;
	return Truncate(id1, id2);
}

EXP_CS double * CSignal::Truncate(int id1, int id2)
{
	if (next!=NULL) next->Truncate(id1, id2);
	if (id1<0)			return buf;
	if (id1>id2) {
		nSamples = 0;
		return buf;
	}
	if (id2>nSamples-1) id2 = nSamples-1;

	nSamples = max(0,id2-id1+1);
	memmove(buf, buf+id1, nSamples*sizeof(*buf));
	return buf;
}

EXP_CS double * CSignal::Silence(double dur_ms)
{
	int nSamplesNeeded = round(dur_ms/1000.*fs); 
	double *p = Silence(nSamplesNeeded);
	tfraction = dur_ms - nSamplesNeeded/(double)fs*1000.;
	return p;
}

EXP_CS double * CSignal::Silence(int nsamples)
{
	Reset();
	UpdateBuffer(nsamples); //allocate memory if necessary
	if (nsamples < 0)
		return NULL;
	memset((void*)buf, 0, nsamples*sizeof(double));
	return buf;
}

EXP_CS double * CSignal::DC(double dur_ms)
{
	int nSamplesNeeded = round(dur_ms/1000.*fs); 
	double *p = DC(nSamplesNeeded);
	tfraction = dur_ms - nSamplesNeeded/(double)fs*1000.;
	return p;
}

EXP_CS double * CSignal::DC(int nsamples)
{
	Reset();
	UpdateBuffer(nsamples); //allocate memory if necessary
	for (int i=0; i<nsamples; i++) buf[i] = 1.;
	return buf;
}

CSignals &CSignals::each(double (*fn)(double))
{
	for (CSignal *p=this; p; p=p->chain)
		for (int i=0; i<p->nSamples; ++i)
			p->buf[i] = (p->buf[i]>0 ?1:-1)*fn(p->buf[i]>0 ? p->buf[i]: -p->buf[i]);
	return *this;
}

CSignal &CSignal::each(double (*fn)(double, double), const CSignals &arg2)
{
	for (CSignal *p=this; p; p=p->chain)
	{
		if (((CSignals)arg2).GetType()==CSIG_SCALAR)
		{
			double val = arg2.value();
			for (int i=0; i<p->nSamples; ++i) p->buf[i] = (p->buf[i]>0 ?1:-1)*fn(p->buf[i]>0 ? p->buf[i]: -p->buf[i],val); 
		}
		else if (((CSignals)arg2).GetType()==CSIG_VECTOR) 
		{
			if (p->nSamples==arg2.dbuf.size())
			{
				for (size_t i=0; i<p->nSamples; ++i)	 p->buf[i] = (p->buf[i]>0 ?1:-1)*fn(p->buf[i]>0 ? p->buf[i]: -p->buf[i], arg2.dbuf[i]); 
			}
			else
				throw "(fn2) the argument must be either a scalar or vector with the same length as the audio signal.";
		}
		else if (((CSignals)arg2).GetType()==CSIG_AUDIO) 
		{
			for (size_t i=0; i<min(p->nSamples, arg2.dbuf.size()); ++i)	 p->buf[i] = (p->buf[i]>0 ?1:-1)*fn(p->buf[i]>0 ? p->buf[i]: -p->buf[i], arg2.dbuf[i]); 
		}
	}
	return *this;
}


EXP_CS void CSignal::Insert(CSignal& insertee, int id)
{
/* if *this is mono, insertee is mono, just do it 
               mono,             stereo, take first chan of insertee,
			   stereo,           mono, apply insertee equally to both channels
			   stereo,           stereo, just do it   */

	if (next!=NULL)			{
		if (insertee.next!=NULL) next->Insert(*insertee.next, id);
		else next->Insert(insertee, id);	}

	if (insertee.nSamples==0 || id<0) return;

	CSignals sig1, sig2;
	if (id==0)			sig1=insertee;
	else
	{
		Take(sig1, 0, id-1);
		sig1 += &insertee;
	}
	Take(sig2, id);
	sig1 += &sig2;
	*this = sig1;
}

EXP_CS int CSignal::GetType()
{
	if (cell.size()>0)
		return CSIG_CELL;
	else if (nSamples==0) // empty
		return CSIG_EMPTY;
	else if (fs==2) // string
		return CSIG_STRING;
	else if (nSamples==1) // scalar 
		return CSIG_SCALAR;
	else if (fs>2) // audio
		return CSIG_AUDIO;
	else
		return CSIG_VECTOR;
	
}


EXP_CS double CSignal::Sum()
{
	double sum(0.);
	for (int i=0; i<nSamples; i++)		sum += buf[i];
	return sum;
}

EXP_CS double CSignal::Mean()
{
	return Sum()/(double)nSamples;
}

EXP_CS double CSignal::Max(int &id)
{
	double localMax(-1.e100);
	for (int i=0; i<nSamples; i++)
	{	if (buf[i] > localMax)
		{	localMax = buf[i];			id=i+1; } // one-based index
	}
	return buf[id-1];
}

EXP_CS double CSignal::Max()
{
	int id;
	return Max(id);
}

EXP_CS double CSignal::Min(int &id)
{
	double localMin(1.e100);
	for (int i=0; i<nSamples; i++)
	{	if (buf[i] < localMin)
		{	localMin = buf[i];	id=i+1;		} // one-based index
	}
	return buf[id-1];
}

EXP_CS double CSignal::Min()
{
	int id;
	return Min(id);
}

#define FIRSIZE 225

EXP_CS double * CSignal::Resample(int newfs, char *errstr) // Revised in Dec09---noted for JHPARK
{
	MakeChainless();
	errstr[0]=0;
	SRC_DATA conv;
	vector<float> data_in, data_out;
	data_in.resize(nSamples);
	conv.data_in = &data_in[0];
	conv.src_ratio = (double)newfs/(double)fs;
	conv.input_frames = nSamples;
	conv.output_frames =  (long) (nSamples * (conv.src_ratio) + .5) ; // conv.src_ratio+1 should be right, but just in case 
	data_out.resize(conv.output_frames);
	conv.data_out = &data_out[0];
	for (int i=0; i<nSamples; i++) conv.data_in[i] = (float)buf[i];

	int res = src_simple(&conv, SRC_SINC_BEST_QUALITY, 1);
	if (!res)
	{
		if (conv.output_frames_gen!=newfs) strcpy(errstr, "resampled output generated less points than desired, zeros padded at the end.");

		//update nSamples and fs
		UpdateBuffer(conv.output_frames);
		fs = newfs;
		int i;
		for (i=0; i<conv.output_frames_gen; i++) 			buf[i] = conv.data_out[i];
		for (i=conv.output_frames_gen; i<conv.output_frames; i++)		buf[i] = 0;
	}
	else
	{
		strcpy(errstr, src_strerror(res));
		return NULL;
	}
	return buf;
}

EXP_CS void CSignal::UpSample(int cc)
{
	MakeChainless();

	if (cc==1) return;
	int newLength = nSamples * cc;
	CSignals temp(fs*cc);
	temp.UpdateBuffer(newLength);
	memset((void*)temp.buf, 0, sizeof(double)*newLength);
	for (int i=0; i<nSamples; i++)
		temp.buf[i*cc] = buf[i];
	*this = temp;
}

EXP_CS void CSignal::DownSample(int cc)
{
	MakeChainless();

	if (cc==1) return;
	int newLength = nSamples / cc;
	CSignals temp(fs/cc);
	temp.UpdateBuffer(newLength);
	for (int i=0; i<newLength; i++)
		temp.buf[i] = buf[cc*i];
	*this = temp;
}

EXP_CS int CSignal::Filter(const CSignal& num, const CSignal& den, char *errstr)
{
	int reqLeng = max(1, max(num.nSamples,den.nSamples) );
	Filter(reqLeng, num.buf, den.buf);
	return 1;
}

EXP_CS int CSignal::filtfilt(const CSignal& num, const CSignal& den, char *errstr)
{
	int reqLeng = max(1, max(num.nSamples,den.nSamples) );
	filtfilt(reqLeng, num.buf, den.buf);
	return 1;
}

EXP_CS void CSignal::Filter(int nTabs, double *num, double *den)
{
	if (next!=NULL) next->Filter(nTabs, num, den);
	double *out = new double[BufSize];
	if (den[0]!=0.)
		filter(nTabs, num, den, nSamples, buf, out);
	else
		filter(nTabs, num, nSamples, buf, out);
	if (buf) delete[] buf;
	buf = out;
}

EXP_CS void CSignal::Filter(int nTabs, double *num) // for FIR
{
	double den(0.);
	Filter(nTabs, num, &den);
}

EXP_CS void CSignal::filtfilt(int nTabs, double *num, double *den)
{
	MakeChainless();

	if (next!=NULL) next->filtfilt(nTabs, num, den);
	//Transient edges not handled, only zero-padded edges 
	CSignals temp(fs), temp2(fs), out(fs);
	int nfact = 3*(nTabs-1);
	temp.Silence(nfact);
	temp += this;
	temp2.Silence(nfact);
	temp += &temp2;
	temp.Filter(nTabs, num, den);
	temp.ReverseTime();
	temp.Filter(nTabs, num, den);
	temp.ReverseTime();
	temp.Take(out, nfact, nfact+nSamples-1);
	*this = out;
}

EXP_CS void CSignal::filtfilt(int nTabs, double *num)
{
	double *den = new double[nTabs];
	memset((void*)den, 0, nTabs*sizeof(double));
	den[0] = 1.;
	filtfilt(nTabs, num, den);
	delete[] den;
}

EXP_CS void CSignal::ReverseTime()
{
	MakeChainless();

	if (next!=NULL) next->ReverseTime();
	CSignals temp(*this);
	double *tempBuf = temp.GetBuffer();
	for (int i=0; i<nSamples ; i++)
		tempBuf[nSamples-i-1]=buf[i];
	*this = temp;
}

//#define RETURNNULL {	for (int i=0; i<nColons; i++) delete[] holder[i]; delete[] holder; return NULL;	}

EXP_CS void CSignal::SetNextChan(CSignal *second)
{
	if (next) {
		delete next;
		next = NULL;
	}
	if (second) {
		next = new CSignals;
		*next = *second;
	}
}


EXP_CS int CSignal::IIR(int kind, int type, int order, double *freqs, double passRipple_dB, double stopFreqORAttenDB, char *errstr)
{// kind: 1 butterworth, 2 Chebyshev, 3 Elliptic
	// type: 1 lowpass, 2 bandpass, 3 highpass, 4 bandstop
	MakeChainless();

	errstr[0]=0;
	double *den = new double [2*order+1];
	double *num = new double [2*order+1];

	// To obtaine the filter coefficients, the object must be a scalar, the sample rate. 
	// Then on success of this call , this object has the buffer of a and b (den and num) in that order.
	if (IsScalar()) fs = (int)value();
	int res = design_iir(num, den, GetFs(), kind, type, order, freqs, passRipple_dB, stopFreqORAttenDB);
	if (res <= 0) {
		switch (res) {
		case -1:
			strcpy(errstr, "((kind <= 0) || (kind > 3))");
			break;
		case -2:
			strcpy(errstr, "((type <= 0) || (type > 4))");
			break;
		case -3:
			strcpy(errstr, "(n <= 0)");
			break;
		case -4:
			strcpy(errstr, "(fs <= 0)");
			break;
		case -5:
			strcpy(errstr, "Filter frequency is greater than Nyquist rate.");
			break;
		default:
			sprintf(errstr, "Unknown error, code=%d", res);
		}
	} else {
		res = 1;
		if (IsScalar()) {
			if (type & 1)
				UpdateBuffer(2*order+2);
			else
				UpdateBuffer(4*order+2);
			memcpy(buf, den, sizeof(*buf)*(nSamples/2));
			memcpy(buf+(nSamples/2), num, sizeof(*buf)*(nSamples/2));
		} else {
			if (type & 1)
				Filter(order+1, num, den);
			else
				Filter(2*order+1, num, den);
		}
	}
	delete[] den; delete[] num;
	return res;
}

std::string CSignal::string()
{
	int i;
	std::string out;
	out.resize(nSamples);
	for (i=0; i<nSamples && (char)buf[i]; i++)
		out[i] = (char)buf[i];
	out.resize(i);
	return out;
}

char *CSignal::getString(char *str, const int size)
{
	int i;
	for (i=0; i<nSamples && i<size-1; ++i)
		str[i] = (char)buf[i];
	str[i] = '\0';
	return str;
}


CSignals &CSignal::each(double (*fn)(double))
{
	for (CSignal *c=this; c; c=c->next)
		for (CSignal *p=c; p; p=p->next)
			for (int i=0; i<p->nSamples; ++i)
			{
				if (p->fs<=2)	p->buf[i] = fn(p->buf[i]);
				else			p->buf[i] = (p->buf[i]>0 ?1:-1)*fn(p->buf[i]>0 ? p->buf[i]: -p->buf[i]);
			}
	return *this;
}


CSignals &CSignal::each(double (*fn)(double, double), const CSignals &arg2)
{
	bool loop(true);
	for (CSignal *c=this; c; c=c->next)
		for (CSignal *p=c; p; p=p->next)
			for (int i=0; i<p->nSamples && loop; ++i)
			{
				if (arg2.nSamples==1) {
					double val = arg2.value();
					if (p->fs<=2)	p->buf[i] = fn(p->buf[i],val); 
					else			p->buf[i] = (p->buf[i]>0 ?1:-1)*fn(p->buf[i]>0 ? p->buf[i]: -p->buf[i],val); 
				}
				else
				{
					if (p->nSamples==arg2.nSamples)
					{
						if (p->fs<=2)	p->buf[i] = fn(p->buf[i],arg2.buf[i]); 
						else			p->buf[i] = (p->buf[i]>0 ?1:-1)*fn(p->buf[i]>0 ? p->buf[i]: -p->buf[i],arg2.buf[i]); 
					}
					else if (p->nSamples==1)
					{
						double base = value();
						UpdateBuffer(arg2.nSamples);
						for (int k=0; k<arg2.nSamples; k++)
							p->buf[k] = fn(base,arg2.buf[k]); 
						loop=false;
					}
					else
						throw "First and second arguments must have the same length if both are vectors.";
				}
			}
	return *this;
}

EXP_CS double * CSignal::FFT(int len)
{
	MakeChainless();
	len = min(nSamples,len);

	double *in;
	fftw_complex *out;
	fftw_plan p;

	in = (double*) fftw_malloc(sizeof(double) * len);
	out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * len);
	memcpy(in, buf, sizeof(double)*len);

	p = fftw_plan_dft_r2c_1d(len, in, out, FFTW_ESTIMATE);
	fftw_execute(p);

	UpdateBuffer(len);
	memcpy(buf, out[0], sizeof(double)*len);
	if (next == NULL)	next = new CSignals(1);
	next->UpdateBuffer(len);
	memcpy(next->buf, out[1], sizeof(double)*len);
	fftw_destroy_plan(p);
	fftw_free(in); 
	fftw_free(out);
	return buf;
}

EXP_CS double * CSignal::iFFT(void)
{
	MakeChainless();
	int len = nSamples;

	fftw_complex *in;
	double *out;
	fftw_plan p;

	out = (double*) fftw_malloc(sizeof(double) * len);
	in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * len);
	memcpy(in[0], buf, sizeof(double)*len);
	memcpy(in[1], next->buf, sizeof(double)*len);

	p = fftw_plan_dft_c2r_1d(len, in, out, FFTW_ESTIMATE);

	fftw_execute(p);

	for (int k=0; k<len; k++) out[k] /= len;
	memcpy(buf, out, sizeof(double)*len);
	delete next; next = NULL;
	fftw_destroy_plan(p);
	fftw_free(in); 
	fftw_free(out);
	return buf;
}


EXP_CS double * CSignal::Hilbert(int len)
{
	if (len<1)		return NULL;
	len = min(nSamples,len);
	fftw_complex *in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * len);
	fftw_complex *mid = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * len);
	fftw_complex *out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * len);
	memset(in, 0, len*sizeof(fftw_complex));
	memset(mid, 0, len*sizeof(fftw_complex));
	memset(out, 0, len*sizeof(fftw_complex));

	// FFT
	for (int k=0; k<len; k++) in[k][0] = buf[k];
	fftw_plan p1 = fftw_plan_dft_1d(len, in, mid, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(p1);

	memset(in, 0, len*sizeof(fftw_complex));
	// converting halfcomplex array to complex array
	int half = len/2 + len%2;
	in[0][0] = mid[0][0];
	//for (int i=1; i<half-1; ++i) 
	//{
	//	in[i][0] *=2; in[i][1] *=2;
	//}

	for (int i=1; i<half; ++i) 
	{
		in[i][0] = 2 * mid[i][0];
		in[i][1] = 2 * mid[i][1];
	}

	if (len%2 == 0)	// len is even
		in[half][0] = mid[half][0];
	// leave the rest zero

	// iFFT
	fftw_plan p2 = fftw_plan_dft_1d(len, in, out, FFTW_BACKWARD, FFTW_ESTIMATE);
	fftw_execute(p2);

	fftw_destroy_plan(p1);
	fftw_destroy_plan(p2);

	next = new CSignals(fs);
	next->UpdateBuffer(len);
	for (int i=0; i<len; ++i)
	{
		buf[i] = out[i][0] / len;	// scale back down since the resulting array is scaled by len.
		next->buf[i] = out[i][1] / len;	// scale back down since the resulting array is scaled by len.
	}
	fftw_free(in); 
	fftw_free(out);
	return buf;
}