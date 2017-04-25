#ifdef _WINDOWS
#ifndef _MFC_VER // If MFC is used.
#include <windows.h>
#else 
#include "afxwin.h"
#endif 
#endif 
#include <math.h>
#include <limits> 
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

#include "sigplus_internal.h"
#include "samplerate.h"
#include "sndfile.h"
//#include "common.h"

#include <complex>
#include <cmath>

#include <math.h> // ceil

#ifndef CISIGPROC
#include "psycon.tab.h"
#else
#include "cipsycon.tab.h"
#endif


#define CRIT  100. // Threshold for computing rms is above 100th of its max

#define RETURN_0_MSG(str) {	strcpy(errstr, str);		return 0;	}

void filter(int nTabs, double *num, double *den, int length, double *in, double *out);
void filter(int nTabs, double *num, int length, double *in, double *out);

int PlayBufAsynch16(UINT DevID, short *dataBuffer, int length, int nChan, int fs, UINT userDefinedMsgID, HWND hApplWnd, int nProgReport, int loop, char* errstr);
int continuePlay(UINT DevID, SHORT *dataBuffer, int length, int nChan, UINT userDefinedMsgID, int nProgReport, char *errstr);
void SetLoop();

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
void SwapCSignalsPutScalarSecond(CSignals &sig1, CSignals &sig2)
{
	if (!sig1.IsStereo() && sig2.IsStereo())
	{
		CSignals copy(sig1);
		sig1 = sig2, sig2 = copy;
	}
}

/*bufBlockSize is 1 (for logical, string), sizeof(double) (regular), or sizeof(double)*2 (complex).     4/4/2017 bjkwon */
body::body()
:nSamples(0), bufBlockSize(sizeof(double)), buf(new double[0])
{
}

body::body(double value)
:nSamples(1), bufBlockSize(sizeof(double)), buf(new double[1])
{
	SetValue(value);
}

body::body(complex<double> value)
:nSamples(1), bufBlockSize(sizeof(double)*2), buf(new double[2])
{
	cbuf[0]=value; 
}

body::body(const body& src) 
:nSamples(0), bufBlockSize(sizeof(double)), buf(new double[0])
{
	*this = src;
}

body::body(double *y, int len)
:nSamples(len), bufBlockSize(sizeof(double)), buf(new double[len])
{
	memcpy(buf, y, bufBlockSize*len);
}

body::body(bool *y, int len)
:nSamples(len), bufBlockSize(1), logbuf(new bool[len])
{
	memcpy(buf, y, bufBlockSize*len);
}


body& body::operator=(const body& rhs)
{
	if (this != &rhs) 
	{
		size_t currentBufSize = bufBlockSize * nSamples; 
		size_t reqBufSize = rhs.bufBlockSize * rhs.nSamples;
		if (currentBufSize < reqBufSize) 
		{
			if (nSamples>0) delete[] buf; 
			logbuf = new bool[reqBufSize];
		}
		nSamples = rhs.nSamples;
		bufBlockSize = rhs.bufBlockSize;
		memcpy(buf, rhs.buf, nSamples*bufBlockSize);
	}
	return *this;
}

body& body::operator+=(const double con)
{
	size_t blockSize = bufBlockSize/sizeof(double);
	for (int k=0; k<nSamples; k++) buf[k*blockSize] += con; 
	return *this;
}

body& body::operator*=(const double con)
{
	size_t blockSize = bufBlockSize/sizeof(double);
	for (int k=0; k<nSamples; k++) buf[k*blockSize] *= con; 
	return *this;
}

body& body::operator-(void)
{
	if (bufBlockSize==sizeof(double))
		for (int k=0; k<nSamples; k++) buf[k] = -buf[k];
	if (bufBlockSize==2*sizeof(double))
		for (int k=0; k<nSamples; k++) cbuf[k] = -cbuf[k];
	return *this;
}

body::~body()
{
	if (buf) delete[] buf;
}

void body::SetValue(double v) 
{
	bufBlockSize=sizeof(double); 
	if (buf) delete[] buf; 
	buf = new double[1]; 
	nSamples=1; buf[0]=v; 
}

void body::SetValue(complex<double> v) 
{
	bufBlockSize=2*sizeof(double); 
	if (buf) delete[] buf; 
	buf = new double[2]; 
	nSamples=1; cbuf[0]=v; 
}


EXP_CS body& body::UpdateBuffer(int length)	// Set nSamples. Re-allocate buf if necessary to accommodate new length.
{
	size_t currentBufsize = bufBlockSize * nSamples; 
	size_t reqBufSize = bufBlockSize * length; 
	if (length < 0 || currentBufsize == reqBufSize)
		return *this;
	if (length > nSamples) {
		bool *newlogbuf = new bool[reqBufSize];
		if (nSamples>0)
			memcpy(newlogbuf, buf, nSamples*bufBlockSize);
		delete[] buf;
		logbuf = newlogbuf;
	}
	if (length > nSamples)
		memset(logbuf+nSamples*bufBlockSize, 0, (length-nSamples)*bufBlockSize); //initializing with zeros for the rest
	nSamples = length;
	return *this;
}

EXP_CS void body::Reset()
{
	if (buf) 
		delete[] buf;
	buf = NULL;
	nSamples = 0;
	bufBlockSize = sizeof(double);
}

EXP_CS double body::value() const 
{
	if (nSamples==1) 
		return buf[0]; 
	else if (nSamples==0) 
		throw "value( ) on null."; 
	else 
		throw "value( ) on vector/array.";
}

EXP_CS complex<double> body::cvalue() const 
{
	if (nSamples==1) 
		return cbuf[0]; 
	else if (nSamples==0) 
		throw "value( ) on null."; 
	else 
		throw "value( ) on vector/array.";
}

void body::SetReal() 
{ // This converts a complex array into real (decimating the imaginary part).
  // Must not be used when the buf is properly prepared--in that case just bufBlockSize = 1; is sufficient.
	if (IsComplex())
	{
		bufBlockSize = sizeof(double); 
		for (int k=0; k<nSamples; k++) buf[k] = buf[2*k];
	}
}

void body::SetComplex() 
{
	if (bufBlockSize!=sizeof(double)*2) 
	{
		bufBlockSize = sizeof(double)*2;  
		if (nSamples>0)
		{
			double *newbuf = new double[2*nSamples]; 
			memset(newbuf, 0, sizeof(double)*2*nSamples);
			for (int k=0; k<nSamples; k++) newbuf[2*k] = buf[k];
			delete[] buf; 
			buf = newbuf;
		}
	} 
}

void body::SwapContents1node(body &sec)
{	// swaps  fs, buf(shallow), chain(shallow), tmark, nSamples  (cell added but not sure if that's OK. bjkwon 4/3/2016)
	body tmp;
	tmp.buf = buf, tmp.nSamples = nSamples, tmp.bufBlockSize = bufBlockSize;
	buf = sec.buf, nSamples = sec.nSamples, bufBlockSize = sec.bufBlockSize;
	sec.buf = tmp.buf, sec.nSamples = tmp.nSamples, sec.bufBlockSize = tmp.bufBlockSize;
	// clean up, so that destructor don't destroy chain and buf which are being used by sec
	tmp.buf = NULL, tmp.nSamples = 0;
}

body &body::addmult(char type, body &arg)
{ // arg must be a vector
	if (nSamples<arg.nSamples) SwapContents1node(arg);
	switch(type)
	{
	case '+':
		for (int k=0; k<min(nSamples, arg.nSamples); k++) 
			buf[k] += arg.buf[k];
		break;
	case '*':
		for (int k=0; k<min(nSamples, arg.nSamples); k++) 
			buf[k] *= arg.buf[k];
		break;
	}
	return *this;
}

body &body::each(double (*fn)(double))
{
	if (bufBlockSize==1)
		for (int i=0; i<nSamples; ++i)	logbuf[i] = fn(logbuf[i]);
	else
		for (int i=0; i<nSamples; ++i)	buf[i] = fn(buf[i]);
	return *this;
}

body &body::each(double (*fn)(complex<double>))
{
	double *out = new double[nSamples];
	for (int i=0; i<nSamples; ++i)
		out[i] = fn(cbuf[i]);
	delete[] buf;
	buf = out;
	bufBlockSize=sizeof(double);
	return *this;
}

body &body::each(complex<double> (*fn)(complex<double>))
{
	for (int i=0; i<nSamples; ++i)
		cbuf[i] = fn(cbuf[i]);
	return *this;
}

body &body::each(double (*fn)(double, double), body &arg)
{
	if (arg.nSamples==1) 
	{
		double val = arg.value();
		if (bufBlockSize==1 && arg.bufBlockSize==1)
			for (int k=0; k<nSamples; k++)	logbuf[k] = fn(logbuf[k],arg.logbuf[0]); 
		else if (bufBlockSize==1 && arg.bufBlockSize!=1)
			for (int k=0; k<nSamples; k++)	logbuf[k] = fn(logbuf[k],val); 
		else
			for (int k=0; k<nSamples; k++)	buf[k] = fn(buf[k],val); 
	}
	else if (nSamples==1) 
	{
		double baseval = buf[0];
		UpdateBuffer(arg.nSamples);
		if (bufBlockSize==1 && arg.bufBlockSize==1)
			for (int k=0; k<arg.nSamples; k++) logbuf[k] = fn(baseval, arg.logbuf[k]); 
		else if (bufBlockSize==1 && arg.bufBlockSize!=1)
			for (int k=0; k<arg.nSamples; k++) logbuf[k] = fn(baseval, arg.buf[k]); 
		else
			for (int k=0; k<arg.nSamples; k++) buf[k] = fn(baseval, arg.buf[k]); 
	}
	else
	{
		nSamples = min(nSamples, arg.nSamples);
		if (bufBlockSize==1 && arg.bufBlockSize==1)
			for (int k=0; k<nSamples; k++) logbuf[k] = fn(logbuf[k], arg.logbuf[k]); 
		else if (bufBlockSize==1 && arg.bufBlockSize!=1)
			for (int k=0; k<nSamples; k++) logbuf[k] = fn(logbuf[k], arg.buf[k]); 
		else
			for (int k=0; k<nSamples; k++) buf[k] = fn(buf[k], arg.buf[k]); 
	}
	return *this;
}

body &body::each(complex<double> (*fn)(complex<double>, complex<double>), body &arg)
{
	if (arg.nSamples==1) 
	{
		complex<double> val = arg.cbuf[0];
		for (int k=0; k<nSamples; k++)	cbuf[k] = fn(cbuf[k],val); 
	}
	else if (nSamples==1) 
	{
		complex<double> val = arg.cbuf[0];
		UpdateBuffer(arg.nSamples);
		for (int k=0; k<arg.nSamples; k++) cbuf[k] = fn(val, arg.cbuf[k]); 
	}
	else
	{
		nSamples = min(nSamples, arg.nSamples);
		for (int k=0; k<nSamples; k++) cbuf[k] = fn(cbuf[k], arg.buf[k]); 
	}
	return *this;
}

double lt (double a, double b)
{ return a<b;}
double le (double a, double b)
{ return a<=b;}
double gt (double a, double b)
{ return a>b;}
double ge (double a, double b)
{ return a>=b;}
double eq (double a, double b)
{ return a==b;}
double ne (double a, double b)
{ return a!=b;}
double and (double a, double b)
{ return a&&b;}
double or (double a, double b)
{ return a||b;}
double not (double a)
{ if (a==0) return 1.;
else  return 0.;}


EXP_CS body& body::LogOp(body &rhs, int type)
{
	double (*fn)(double, double);
	switch(type)
	{
	case '<':
		fn = lt;
		break;
	case '>':
		fn = gt;
		break;
	case T_COMP_LE:
		fn = le;
		break;
	case T_COMP_GE:
		fn = ge;
		break;
	case T_COMP_EQ:
		fn = eq;
		break;
	case T_COMP_NE:
		fn = ne;
		break;
	case T_LOGIC_AND:
		fn = and;
		break;
	case T_LOGIC_OR:
		fn = or;
		break;
	case T_LOGIC_NOT:
		each(not);
		return *this;
	}
	each(fn, rhs);
	MakeLogical();
	return *this;
}


EXP_CS body& body::MakeLogical()
{
	if (bufBlockSize ==1) return *this;
	body out; 
	out.bufBlockSize = 1; // logical array
	out.UpdateBuffer(nSamples); // This over-reserve the memory, but there's no harm. 4/4/2017 bjk
	for (int k=0; k<nSamples; k++) 
	{
		if (buf[k]==0.) out.logbuf[k] = false;
		else			out.logbuf[k] = true;
	}
	return (*this=out);
}

body &body::insert(body &sec, int id)
{
	if (sec.nSamples==0) return *this;
	if (id<0) throw "insert index cannot be negative."; 
	if (sec.bufBlockSize!=bufBlockSize) throw "insert must be between the same data structure."; 
	int nToMove = nSamples - id;
	UpdateBuffer(nSamples+sec.nSamples);
	bool *temp = new bool[nToMove*bufBlockSize];
	memcpy(temp, logbuf+id*bufBlockSize, nToMove*bufBlockSize);
	memcpy(logbuf+id*bufBlockSize, sec.buf, sec.nSamples*bufBlockSize);
	memcpy(logbuf+(id+sec.nSamples)*bufBlockSize, temp, nToMove*bufBlockSize);
	delete[] temp;
	return *this;
}

body &body::replace(body &sec, body &index)
{
//	this is to be used when items are replaced without changing the size.
	if (sec.bufBlockSize!=bufBlockSize) throw "replace must be between the same data structure."; 
	for (int k=0; k<index.nSamples; k++)
	{
		int id = (int)(index.buf[k]+.5)-1;
		if (id<0) throw "replace index cannot be negative."; 
		if (id>nSamples) throw "replace index exceeds the range.";
		if (sec.nSamples==1) // items from id1 to id2 are to be replaced with sec.value()
			buf[id] = sec.value();
		else
			buf[id] = sec.buf[k];
	}
	return *this;
}

bool body::isstring()
{
	int dummy;
	if (nSamples==0) return false;
	if (nSamples==1 && !strbuf[0]) return false;
	int mn = (int) Min(dummy,nSamples-1);
	if (mn>' ') return true;
	int mx = (int) Max(dummy,nSamples-1);
	if (mx == 1) return false;
	return false;
}

body &body::replace(body &sec, int id1, int id2)
{ // this replaces the data body between id1 and id2 (including edges) with sec
	if (id1<0||id2<0) throw "replace index cannot be negative."; 
	if (sec.bufBlockSize!=bufBlockSize) throw "replace must be between the same data structure."; 
	//id1 and id2 are zero-based here.
	if (id1>nSamples-1) throw "replace index exceeds the range.";
	if (id2>nSamples-1) throw "replace index exceeds the range.";
	int secnsamples = sec.nSamples;
	bool ch = sec.isstring();
	if (sec.isstring()) secnsamples--;
	if (secnsamples==1) // no change in length--items from id1 to id2 are to be replaced with sec.value()
	{
		if (ch) 
			for (int k=id1; k<=id2; k++) strbuf[k] = sec.strbuf[0];
		else
			for (int k=id1; k<=id2; k++) buf[k] = sec.value();
	}
	else
	{
		int nAdd = secnsamples;
		int nSubtr = id2-id1+1;
		int newLen = nSamples + nAdd - nSubtr;
		int nToMove = nSamples - id2 - 1;
		if (nAdd>nSubtr) UpdateBuffer(newLen);
		bool *temp = new bool[nToMove*bufBlockSize];
		memcpy(temp, logbuf+(id2+1)*bufBlockSize, nToMove*bufBlockSize);
		memcpy(logbuf+id1*bufBlockSize, sec.buf, secnsamples*bufBlockSize);
		memcpy(logbuf+(id1+secnsamples)*bufBlockSize, temp, nToMove*bufBlockSize);
		delete[] temp;
		nSamples = newLen;
	}
	return *this;
}

double body::Sum()
{
	double sum(0.);
	for (int i=0; i<nSamples; i++)		sum += buf[i];
	return sum;
}

body &body::Min(double crit)
{
	for (int k=0; k<nSamples; k++)
		if (buf[k]>crit) buf[k] = crit;
	return *this;
}

body &body::Max(double crit)
{
	for (int k=0; k<nSamples; k++)
		if (buf[k]<crit) buf[k] = crit;
	return *this;
}

template <class T>
T maxarray(int &id, T *buf, int len)
{
	T local;
	char ctemp(0);
	double dtemp(-1.e100);
	if (sizeof(T)==1)
		memcpy(&local, &ctemp, sizeof(T)); 
	else			
		memcpy(&local, &dtemp, sizeof(T)); 
	for (int k=0; k<len; k++)
		if (buf[k] > local)
			{	local = buf[k];	id=k+1;		} // one-based index
	return buf[id-1];
}

template <class T>
T minarray(int &id, T *buf, int len)
{
	T local;
	unsigned char ctemp(255);
	double dtemp(1.e100);
	if (sizeof(T)==1)
		memcpy(&local, &ctemp, sizeof(T)); 
	else			
		memcpy(&local, &dtemp, sizeof(T)); 
	for (int k=0; k<len; k++) 
		if (buf[k] < local)
			{	local = buf[k];	id=k+1;		} // one-based index
	return buf[id-1];
}

double body::Max(int &id, int len)
{
	int k(0);
	bool shouldbestring(false);
	if (len==-1) len = nSamples;
	if (bufBlockSize==1) // logical
	{
		do {
			if ((char)logbuf[k]>=' ') shouldbestring = true;
			if (logbuf[k]) 
			{id=k; return 1.;}
		} while (k++<len-1 && !shouldbestring);
		if (shouldbestring)
			return maxarray(id, (unsigned char*)strbuf, len);
		if (k==len) return 0.;
	}
	return maxarray(id, buf, len);
}

double body::Min(int &id, int len)
{
	int k(0);
	bool shouldbestring(false);
	if (len==-1) len = nSamples;
	if (bufBlockSize==1) // logical
	{
		do {
			if ((char)logbuf[k]>=' ') shouldbestring = true;
			if (!logbuf[k]) {id=k; return 0.;}
		} while (k++<len && !shouldbestring);
		if (shouldbestring)
			return minarray(id, (unsigned char*)strbuf, len);
		if (k==len) return 1.;
	}
	return minarray(id, buf, len);
}

CSignal::CSignal()
:fs(1), chain(NULL), tmark(0.)
{
}

CSignal::CSignal(int sampleRate)
:fs(max(sampleRate,1)), chain(NULL), tmark(0.)
{
	if (fs==2) bufBlockSize=1;
}

CSignal::CSignal(double value)
:fs(1), chain(NULL), tmark(0.)
{
	SetValue(value);
}

CSignal::CSignal(std::string str)
:fs(1), chain(NULL), tmark(0.)
{
	SetString(str.c_str());
}

CSignal::CSignal(const CSignal& src)
:fs(1), chain(NULL), tmark(0.)
{
	*this = src;
}

CSignal::CSignal(double *y, int len)
:fs(1), chain(NULL), tmark(0.)
{
	UpdateBuffer(len);
	memcpy((void*)buf, (void*)y, sizeof(double)*len);
}


CSignal::~CSignal()
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

CSignal& CSignal::Reset(int fs2set)	// Empty all data fields - sets nSamples to 0.
{
	body::Reset();
	if (fs2set)	// if fs2set == 0 (default), keep the current fs.
		fs = max(fs2set,1);	// not to allow minus.
	tmark = 0;
	if (chain) {
		delete chain;
		chain=NULL;
	}
	return *this;
}

EXP_CS void CSignal::SetChain(CSignal *unit, double time_shifted)
{
	if (unit!=NULL)
	{
		if (nSamples>0)  delete[] buf;
		buf = NULL; 
		chain = unit;
	}
}

EXP_CS void CSignal::SetChain(double time_shifted)
{
	if (nSamples>0)
	{
		tmark = time_shifted;
		chain = this;
		buf = NULL;
	}
}

EXP_CS CSignal& CSignal::operator=(const CSignal& rhs)
{   // Make a deep copy only for buf, but not for sc, because sc is not necessarily dynamically allocated.
	// Thus, BE Extra careful when making writing an assignment statement about the scaling..
	if (this != &rhs) 
	{
		Reset(rhs.fs);
		tmark = rhs.tmark;
		if (rhs.nSamples>0)
			body::operator=(rhs); 
		if (rhs.chain) 
		{
			chain = new CSignal;
			*chain = *rhs.chain;
		}
		else
		{
			delete chain;
			chain=NULL;
		}
	}
	return *this; // return self-reference so cascaded assignment works
}

EXP_CS void CSignal::SwapContents1node(CSignal &sec)
{	// swaps  fs, buf(shallow), chain(shallow), tmark, tfraction, BufSize, nSamples  (cell added but not sure if that's OK. bjkwon 4/3/2016)
	// *** Leaves "next" intact!!!
	CSignal tmp(fs);
	tmp.buf = buf, tmp.chain = chain, tmp.tmark = tmark, tmp.nSamples = nSamples; tmp.bufBlockSize = bufBlockSize; // tmp = *this
	fs = sec.fs, buf = sec.buf, chain = sec.chain, tmark = sec.tmark, nSamples = sec.nSamples;	bufBlockSize = sec.bufBlockSize; // *this = sec
	sec.fs = tmp.fs, sec.buf = tmp.buf, sec.chain = tmp.chain, sec.tmark = tmp.tmark, sec.nSamples = tmp.nSamples; sec.bufBlockSize = tmp.bufBlockSize; // sec = tmp
	// clean up, so that destructor don't destroy chain and buf which are being used by sec
	tmp.buf = NULL, tmp.chain = NULL, tmp.tmark = 0, /*tmp.tfraction = 0,*/ /*tmp.BufSize = 0,*/ tmp.nSamples = 0;
}

EXP_CS CSignal& CSignal::operator+=(const double con) 
{ 
	body::operator+=(con);
	if (chain) *chain += con; 
	return *this; 
} 

EXP_CS CSignal& CSignal::operator*=(const double con)
{ 
	body::operator*=(con);
	if (chain) *chain *= con; 
	return *this; 
} 

EXP_CS CSignal& CSignal::operator-(void)	// Unary minus
{
	body::operator-();
	if (chain)	-*chain;
	return *this;
}

EXP_CS CSignal& CSignal::operator/=(double con)
{
	return *this *= 1.0/con;
}

EXP_CS CSignal& CSignal::operator+=(CSignal &sec) 
{ 
	if (IsEmpty() || GetType()==CSIG_NULL) return (*this=sec);
	if (sec.IsEmpty() || sec.GetType()==CSIG_NULL) return *this;
	if (IsSingle() && !sec.IsSingle()) 
		SwapContents1node(sec); 
	if (sec.IsSingle()) 
	{ 
		if (sec.IsComplex()) SetComplex();
		if (IsComplex()) 
		{
			sec.SetComplex();
			for (int k=0; k<nSamples; k++)
				cbuf[k] += sec.cbuf[0];
		}
		else
		{
			for (CSignal *p=this; p; p=p->chain)
				if (p->IsString()) for (int k=0; k<p->length(); k++)	p->strbuf[k] += INT(sec.value());
				else				for (int k=0; k<p->nSamples; k++)	p->buf[k] += sec.buf[0];
		}
	} else	/* now for two vectors */ 
	{
		if (sec.IsString() || IsString()) throw "Addition of string is allowed only with a scalar.";
		AddMultChain( '+', &sec ); 
	}
	return *this; 
} 


EXP_CS CSignal& CSignal::operator*=(CSignal &sec) 
{ 
	if (IsEmpty() || GetType()==CSIG_NULL) return (*this=sec);
	if (sec.IsEmpty() || sec.GetType()==CSIG_NULL) return *this;
	if (IsSingle() && !sec.IsSingle()) 
		SwapContents1node(sec); 
	if (sec.IsSingle()) 
	{ 
		if (sec.IsComplex()) SetComplex();
		if (IsComplex()) 
		{
			sec.SetComplex();
			for (int k=0; k<nSamples; k++)
				cbuf[k] *= sec.cbuf[0];
		}
		else
		{
			for (CSignal *p=this; p; p=p->chain)
				for (int k=0; k<p->nSamples; k++)
					p->buf[k] *= sec.buf[0];
		}
	} else	/* now for two vectors */ 
		AddMultChain( '*', &sec ); 
	return *this; 
} 

const CSignal& CSignal::operator+=(CSignal *yy)
{ // a little jumbled up with jhpark's previous codes and bjkwon's current codes... 7/6/2016
	if (yy==NULL) return *this;
	if (IsEmpty()) return (*this=*yy);
	if (GetType()==CSIG_NULL) return *this=*yy>>=tmark;
	// Concatenation of CSignal
  // yy might lose its value.
	if (GetFs()<2)
		SetFs(yy->GetFs());

	CSignal *ptail = GetDeepestChain();
	if ((GetType()==CSIG_AUDIO && yy->GetType()==CSIG_AUDIO) && (yy->chain || yy->tmark) ) {
		// when insertee has chain(s), chain it instead of copying. yy loses its value.
		CSignal *pNew = new CSignal();
//		if (next && !yy->next) // I don't know what would be the consequences of this leaving out  5/12/2016 ---check later??
//			*pNew = *yy;	// make a copy, leaving the original intact for the next channel
//		else
			pNew->SwapContents1node(*yy);		// pNew takes the insertee. As yy lost all its pointers, yy can be destroyed later without destroying any data it used to have.
		*pNew >>= ptail->tmark+ptail->dur();	// to make the insertee the next chain(s) of ptail.
		ptail->chain = pNew;					// link it to *this.
	} else {
		// otherwise, just copy at the end.
		if (yy->nSamples>0)
		{
			int nSamples0 = ptail->nSamples;
			if (yy->IsComplex()) ptail->SetComplex();
			ptail->UpdateBuffer(yy->nSamples + nSamples0);
			if (GetType()==CSIG_STRING)
				strcat(ptail->strbuf, yy->strbuf);
			else
				memcpy(&ptail->logbuf[nSamples0*bufBlockSize], yy->buf, bufBlockSize*yy->nSamples);
		}
	}
	return *this;
}

EXP_CS void CSignal::AddMultChain(char type, CSignal *sec) 
{ 
	if (fs!=1 && sec->fs!=1 && fs != sec->fs)  throw "The sampling rates of both operands must be the same."; 

	CSignal *pm=this;
	CSignal *ps=sec;
	CSignal *p;
	CSignal out(sec->GetFs()), part(sec->GetFs());
	if (IsComplex() || sec->IsComplex()) { SetComplex(); sec->SetComplex(); part.SetComplex();}

	if (sec->GetType()==CSIG_AUDIO || GetType()!=CSIG_AUDIO) SwapContents1node(*sec); // now, there's no case where sec is audio and primary is nonaudio
	if (GetType()!=CSIG_AUDIO) // if both are nonaudio
	{
		addmult(type, *sec);
		return;
	}
	if (sec->GetType()!=CSIG_AUDIO) // primary audio, sec nonaudio
	{
		for (p=this; p; (p=p->chain) && (sec->nSamples>0) ) 
		{
			p->addmult(type, *sec);
			sec->nSamples -= p->nSamples;
			if (sec->nSamples>0)	sec->buf += sizeof(sec->buf)*p->nSamples;
		}
		return ;
	}
	//Now the rest is if both are audio...
	vector<double> thistmark;
	vector<double> sectmark;
	for (p=this; p; p=p->chain)
	{
		thistmark.push_back(p->tmark);
		thistmark.push_back(p->endt());
	}
	for (p=sec; p; p=p->chain)
	{
		sectmark.push_back(p->tmark);
		sectmark.push_back(p->endt());
	}
	size_t k, im(0), is(0); // im: index for master (this), is: index for sec
	double anc1, anc0;
	short status(0);
	vector<double> anc; // just for debugging/tracking purposes... OK to delete.
	int count;
	anc0 = min(thistmark[im],sectmark[is]);
	anc.push_back(anc0);
	do{
	if ( im==thistmark.size() && is==sectmark.size() )
		break;
	if ( is==sectmark.size() ) //only thistmark is left
		status += (short)(pow(-1.,(int)im)), im++; 
	else if ( im==thistmark.size() ) //only sectmark is left
		status += (short)(2*pow(-1.,(int)is)), is++;
	else if (thistmark[im]<=sectmark[is]) // both are available. check them
		status += (short)(pow(-1.,(int)im)), im++; 
	else
		status += (short)(2*pow(-1.,(int)is)), is++;
	if (im==thistmark.size() && is==sectmark.size() )
		break;
	else if (im<thistmark.size() && is<sectmark.size() )
		anc1 = min(thistmark[im],sectmark[is]);
	else // this means only one of the two, thistmark and sectmark, is left, just pick the available one.
		if (sectmark.size()-is>0)
			anc1 = sectmark[is];
		else
			anc1 = thistmark[im];
	anc.push_back(anc1);

	if (status>0) // if status is 0, skip this cycle--no need to add chain
	{
		// status indicates in the time range between the last two values of anc, what signal is present
		// 1 means this, 2 means sec, 3 means both
		count = round(( anc1-anc0 )/1000.*fs); 
		size_t blockSize = bufBlockSize/sizeof(double);
		{
			part.UpdateBuffer(count);
			part.tmark = anc0;
			if (status&1) 
			{
				for (k=0, p=pm; k<im/2; k++/*, p=p->chain*/)
				{
					if (p->chain!=NULL) p=p->chain;
					else				break;
				}
				int id = round(( anc0-p->tmark )/1000.*fs);
				memcpy(part.buf, p->logbuf+id*bufBlockSize, part.nSamples*bufBlockSize);
			}
			if (status&2) 
			{
				for (k=0, p=ps; k<is/2; k++)
					if (p->chain!=NULL) p=p->chain;
				int id = round(( anc0-p->tmark )/1000.*fs);
				if (status&1) // type=='+' add the two,  type=='*' multiply
				{
					if (type=='+')	for (int k=0; k<count; k++)	part.buf[k] += p->buf[k+id];
					else if (type=='*')	
					{
						if (part.IsComplex()) for (int k=0; k<count; k++)	part.cbuf[k] *= p->cbuf[k+id];
						else				 for (int k=0; k<count; k++)	part.buf[k] *= p->buf[k+id];
					}
				}
				else 
				{
					memcpy(part.buf, p->logbuf+id*bufBlockSize, part.nSamples*bufBlockSize);
				}
			}
		}
		if (out.tmark==0. && out.nSamples==0) // the very first time
			out = part;
		else if (count>0 && part.nSamples>0) // if count==0, don't add part (which might be leftover from the previous round)
			out.AddChain(part);
	}
	anc0 = anc1;
	} while (im<thistmark.size() || is<sectmark.size() );
	*this = out.ConnectChains();
}

EXP_CS CSignal& CSignal::ConnectChains()
{
	CSignal *p(this), out(fs);
	if (p==NULL || p->chain==NULL) return *this;
	if (tmark>0)
	{
		double shift(tmark);
		for (; p; p=p->chain)	p->tmark -= shift;
		ConnectChains();
		p=this;
		for (; p; p=p->chain)	p->tmark += shift;
		return *this;
	}
	while(1)
	{
		CSignal part(fs);
		if (IsComplex()) part.SetComplex();

		part.tmark = p->tmark;
		int count(0);
		// Get the count needed to consolidate 
		for (CSignal *tp(p); ;) {
			count += tp->nSamples;
			//at this point tmark should have been adjusted to be very close to align with the fs grid, i.e., tp->chain->tmark/1000.*fs would be very close to an integer
			// if it is an integer, tmark was already aligned with the grid so no need to adjust
			// if it is not an integer (but very close to one), it should be forced to be the one.. now I'm adding .01 
			// this raises a possibility to make tp->chain->tmark/1000.*fs overrun (end up making one greater than it should be) if its decimal is 0.49, but that's not likely...
			// 6/4/2016 bjk
			// if nSamples so far is the same as the following chain tmark, it means continuing (i.e., the chain consolidated)
			// "Being the same" is too restrictive. Allow error margin of 2.
			// 7/18/2016 bjk
			if (tp->chain!=NULL && fabs(tp->chain->tmark/1000.*fs - count ) <=2 )
				tp=tp->chain;
			else
				break;
		}
		// Consolidate 
		part.UpdateBuffer(count);
		int offset(0);
		while (1) {
			memcpy(part.logbuf+offset, p->buf, p->nSamples*bufBlockSize);
			offset += p->nSamples*bufBlockSize;
//			int dd;
//			if (p->chain) dd = (int)(p->chain->tmark/1000.*fs+.1);
			if (p->chain!=NULL && offset==(int)(p->chain->tmark/1000.*fs+.1)*bufBlockSize)
				p=p->chain;
			else
				break;
		}
		if (out.tmark==0. && out.nSamples==0) // the very first time
			out = part;
		else
			out.AddChain(part);
		if (p->chain==NULL) break;
		p=p->chain;
	}
	return (*this=out);
}

EXP_CS CSignal& CSignal::Diff()
{
	for (int k=0; k<nSamples-1; k++)	buf[k] = buf[k+1]-buf[k];
	UpdateBuffer(nSamples-1);
	return *this;
}

EXP_CS CSignal& CSignal::Cumsum()
{
	for (int k=1; k<nSamples; k++)	buf[k] = buf[k-1]+buf[k];
	return *this;
}

EXP_CS CSignal& CSignal::operator-=(CSignal &sec)
{
	return *this += -sec;
}

EXP_CS CSignal& CSignal::operator/=(CSignal &scaleArray)
{
	return *this *= scaleArray.Reciprocal();
}

EXP_CS CSignal& CSignal::Reciprocal(void)
{
	if (IsScalar())
		SetValue(1.0/value());
	else {
		for (int i=0; i<nSamples; i++)
			buf[i] = 1.0/buf[i];
		if (chain)
			chain->Reciprocal();
	}
	return *this;
}

EXP_CS CSignal& CSignal::operator<<=(const double delta)
{
	*this>>=(-delta);
	return *this;
}

CSignal& CSignal::operator>>=(const double delta)
{
	if (delta == 0)
		return *this;
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
	//quantize delta with granularity of fs // 3/31/2016 bjkwon
	int pt = round(delta/1000.*fs);
	double newdelta = (double)pt * 1000. / (double)fs;
	tmark += newdelta;
	if (chain)
		*chain>>=delta;
	return *this;
}

EXP_CS void CSignal::AddChain(CSignal &sec)
{ // assume that nSamples>1 in both. 
	//MAKE SURE TO AVOID CIRCULAR CHAINING....IT WILL CREATE A STACK OVERFLOW

	if (chain==NULL) 
	{
		chain = new CSignal;
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

int CSignal::CountChains()
{
	int res(1);
	CSignal *p;
	for (p=this; p->chain; p=p->chain)
		res++;
	return res;
}

EXP_CS double CSignal::alldur()
{
	CSignal *p = GetDeepestChain();
	if (p!=NULL)	return p->tmark + p->dur()+(double)1./fs*1000.;
	else			return tmark+dur()+(double)1./fs*1000.;

}

double CSignal::MakeChainless()
{ //This converts the null intervals of the signal to zero.
	fs = max(fs, 1);
	double newdur = alldur();	// doing this here as fs might have changed.
	if (!tmark && !chain)	// already chainless && no padding required.
		return newdur;

	CSignal nsig(fs);
	nsig.UpdateBuffer(round(newdur/1000.*fs));
	for (CSignal *p=this; p; p=p->chain) {
		if (p->tmark + p->dur() <= 0)
			continue;
		int iorg = (p->tmark < 0) ? round(-p->tmark/1000.*fs) : 0;
		int inew = (p->tmark > 0) ? round(p->tmark/1000.*fs) : 0;
		int cplen = p->nSamples-iorg;
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


EXP_CS double CSignal::RMS()
{ // This does not go into next.... for stereo signals, call RMS specifically, like next->RMS()  bjk 4/23/2016
	double cum(0);
	int count(0);
	CSignal *p(this);
	for (; p; p=p->chain)
	{
		for (int i=0; i<p->nSamples; ++i, ++count) 
			cum += p->buf[i] * p->buf[i];
	}
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
	out.Reset();
	if (id2<id1)		// Time reversal
	{
		if (id2>nSamples-1) return *this;
		id1 = min (nSamples-1, id1);
		id2 = max (0, id2);
		int nSamplesNeeded = id1-id2+1;
		out.UpdateBuffer(nSamplesNeeded);
		for (int k=0; k<nSamplesNeeded; k++)
			out.buf[k] = buf[id1-k];
	}
	else
	{
		if (id1>nSamples-1) return *this;
		id1 = max (0, id1);
		id2 = min (nSamples-1, id2);
		int nSamplesNeeded = id2-id1+1;
		out.UpdateBuffer(nSamplesNeeded);
		memcpy((void*)&out.buf[-min(0,id1)], (void*)&buf[max(0,id1)], sizeof(double)*(id2-max(0,id1)+1));
	}
	return out;
}

EXP_CS CSignal& CSignal::Take(CSignal& out, double begin_ms, double end_ms)
{ /* if id1 is negative, zero's are added before the waveform.
  if id2 is greater than current length, the end of current array will be taken.
	
// If there's an error, extracting is not happening and this pointer will be the output.
// Error will occur in one of the following:
	1) when id2 is the same or smaller than id1.
*/
	//these indices are inclusive of time points but "fix" of sample time grid 4/23/2017 bjk
	int id1 = (int)(begin_ms/1000.*fs);
	int id2 = (int)(end_ms/1000.*fs);
	Take(out, id1, id2);
	return out;
}

EXP_CS CSignal& CSignal::Squeeze()
{
	int nSamplesTotal(0), nSamples0(nSamples);
	for (CSignal* p(this); p; p=p->chain)
		nSamplesTotal += p->nSamples;
	UpdateBuffer(nSamplesTotal);
	nSamplesTotal=nSamples0;
	for (CSignal* p(chain); p; p=p->chain)
		memcpy(&buf[nSamplesTotal], p->buf, p->nSamples*sizeof(p->buf[0])),nSamplesTotal+=p->nSamples;
	delete chain;
	chain = NULL;
	return *this;
}

EXP_CS double CSignal::totaldur()
{
	double out;
	for (CSignal*p(this); p; p=p->chain)
		out = p->endt();
	return out;
}


EXP_CS CSignal& CSignal::MergeChains()
{// This tidy things up by removing unnecessary chains and rearranging them.
	CSignal temp;
	if (nSamples==0 && chain) {temp = *chain; chain=NULL; *this = temp; }

	for (CSignal* p(this); p && p->chain; p=p->chain)
	{
		double et = p->endt();
		if (p->endt()>=p->chain->tmark) // consolidate 
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
	}

	return *this;

}

EXP_CS CSignal& CSignal::MC(CSignal &out, vector<double> tmarks, int id1, int id2)
{
	CSignal parts;
	double tp1 = ((double)id1/fs)*1000.;
	double tp2 = ((double)id2/fs)*1000.;
	for (vector<double>::reverse_iterator iter=tmarks.rbegin(); iter!=tmarks.rend(); iter +=2)
	{
		int idtmark = round((*iter*fs)/1000.);
		int idendt = round((*(iter+1)*fs)/1000.);
		if (id1>idendt) continue;
		vector<double>::reverse_iterator it = iter+2;
		if (it!=tmarks.rend() && tp2 > *it)
		{// id2 over-reaches beyond the block, we need to limit in within a block
			if (out.nSamples==0 && out.tmark==0) 
				MC(out, tmarks, idtmark, idendt);
			else
			{
				MC(out, tmarks, idtmark, idendt);
	//			out.AddChain(out);
			}
//			out.AddChain(MC(tmarks, idendt+1, id2));
		}
		else // if it does not over-reach
		{
			int iBegin = max(idtmark, id1);
			int iEnd = min(id2, idendt)-1;
			if (iEnd<iBegin) 
				return out; // both two points in the null interval
			int count = iEnd - iBegin + 1;
			parts.Reset(fs);
			parts.UpdateBuffer(count);
			memcpy(parts.buf, buf + iBegin, sizeof(double)*count);
			parts.tmark = ((double)iBegin/fs)*1000.;
			if (out.nSamples==0 && out.tmark==0) out = parts;
			else out.AddChain(parts);
			return out;
		}
	}
	return *this = out;
}

EXP_CS CSignal& CSignal::MakeChains(vector<double> tmarks)
{ // check if this runs OK with Trim
	CSignal out(fs), parts, copy(*this), *p(this);
	for (vector<double>::reverse_iterator iter=tmarks.rbegin(); iter!=tmarks.rend(); iter +=2, p=p->chain)
	{
		parts.Reset(fs);
		Take(parts, 0., *(iter+1)-*iter);
		if (out.nSamples==0 && out.tmark==0) out = parts;
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

EXP_CS CSignal& CSignal::LogOp(CSignal &rhs, int type)
{
	for(CSignal *p = this; p; p=p->chain)
		p->body::LogOp(rhs, type);
	return *this;
}

CSignal& CSignal::removeafter(double timems)
{ // if timems is in the grid, the point is removed (but dur will be until that grid point)
	CSignal *last;
	for (CSignal *p(this); p; p=p->chain)
	{
		if (timems > p->tmark+p->dur()) {last=p; continue; }
		else if (timems > p->tmark) 
		{
			// no need to worry about p->tmark
			// all points occuring on and after timems will be removed (dur will still be timems)
			// if timems exceeds the grid of p->tmark, it won't be removed, so it is ceil.
			p->nSamples = (int)ceil((timems-p->tmark)*fs/1000.);
		}
		else
		{
			delete[] p;
			last->chain=NULL;
			break;
		}
		last=p;
	}
	return *this;
}

CSignal& CSignal::timeshift(double timems)
{ // if timems is in the grid, the point is kept.
	int chainlevel(0);
	CSignal *p(this);
	for (; p ; p=p->chain)
	{
		if (timems > p->tmark+p->dur()) { chainlevel++; continue; }
		if (timems < p->tmark) 
			p->tmark -= timems;
		else
		{
			// p->tmark should be zero, except for the small off-granular timing based on the difference between timems and p->tmark
			// the decrease of points will step-up if timems exceeds the grid, so it is ceil.
			int pointsless = (int)ceil((timems-p->tmark)*fs/1000.);
			p->nSamples -= pointsless;
			double *tbuf = new double[p->nSamples];
			memcpy(tbuf, p->buf+pointsless, p->nSamples*sizeof(double));
			delete[] p->buf;
			p->buf = tbuf;
			p->tmark = ( (double)pointsless - (timems-p->tmark)*fs/1000. ) * 1000./fs;
		}
	}
	//all chains at and prior to chainlevel are cleared here.
	p = this;
	for (int k(0); k<chainlevel ; k++, p=p->chain)
		delete[] p->buf;
	if (p!=this) // or if chainlevel is non-zero 
	{
		// Make new chain after chainlevel. If p is NULL (make an empty CSignal object to return);
		if (!p) {p = new CSignal;}
		nSamples = p->nSamples;
		tmark = p->tmark;
		buf = p->buf;
		chain = NULL;
	}
	return *this;
}

CSignal& CSignal::Trim(double begin_ms, double end_ms)
{
	if (begin_ms == end_ms) {Reset(); return *this;}
	vector<double> tmarks;
	if (begin_ms > end_ms) {
		Trim(end_ms, begin_ms);
		ReverseTime();
		return *this;
	}
	removeafter(end_ms);
	CSignal p = timeshift(begin_ms);
	return *this;
}

void CSignal::Dramp(double dur_ms, int beginID)
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

EXP_CS double * CSignal::Noise(double dur_ms)
{
	int nSamplesNeeded = round(dur_ms/1000.*fs);
	double *p = Noise(nSamplesNeeded);
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

#ifndef NO_RESAMPLE

EXP_CS double * CSignal::fm2(CSignal flutter, int multiplier, char *errstr)
{   // Modulate the entire signal by the array flutter ( > 1, fast-forward, higher-pitched, < 1 slow-down, lower-pitched
	// the length of flutter should be A LOT shorter than nSamples (e.g., 1 tendth of it), but that is checked and exception is handled in AuxFunc.cpp
	flutter *= multiplier;
	for (int k(0); k<flutter.nSamples; k++) flutter.buf[k] = (double)((int)(flutter.buf[k]+.5));
	flutter /= multiplier;
	CSignals newaudio(*this);
	//First estimate the buffer length at the end of the processing, so we don't call UpdateBuffer multiple times.
	//assume that chain==NULL
	int nSamples0(nSamples);
	double MeanRate = flutter.Mean().front();
	if (MeanRate<1.03) newaudio.UpdateBuffer((int)(nSamples/MeanRate*1.1)); // if MeanRate is less than 1, buf should be expanded. 1.03 just as a buffer, add 10% as another shock buffer.
	if (Resample(multiplier*fs, errstr)==NULL) return NULL;
	SetFs(fs);
	vector<int> chunks;
	splitevenindices(chunks, nSamples, flutter.nSamples); // check about here....nSamples0 or nSamples.. not sure....
	int m(0), cum(0), id(0), idbig(cum);
	for (vector<int>::iterator chit=chunks.begin(); chit!=chunks.end(); chit++, m++)
	{
		int bigskip((int)(multiplier*flutter.buf[m]));
		for (id=idbig=0; idbig<*chit; id++, idbig += bigskip)
		{
			newaudio.buf[cum+id] = buf[cum+idbig]; // multiplier*flutter.buf[m] should be an integer.
		}
		cum += id;
	}
	newaudio.nSamples = cum;
	*this = newaudio; 
	return buf;
}

#endif //NO_RESAMPLE

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
	return p;
}

EXP_CS double * CSignal::Tone(vector<double> freqs, int len)
{ // freqs: array of desired instantaneous frequencies requested
  // fval: coefficient inside the sine term in each instance
  // for a constant frequency, fval is always the same as specfied frequency, but in general, it is not
  // 7/24/2016 bjk
	Reset();
	UpdateBuffer(len); //allocate memory if necessary
	double t(0), tgrid(1./fs);
	buf[0] = 0;
	if (freqs.size()==2)
	{
		double duration((double)len/(double)fs),  glidelta(freqs[1] - freqs[0]);
		double f1(freqs[0]), f2(freqs[1]), ratio(f2/f1);
		for (int k(1); k<len; k++)
		{
			t += tgrid;
//			buf[k] = sin(2*PI*t*(f1/log(ratio)*pow(ratio, t/duration)));
			buf[k] = sin(2*PI*t*(freqs[0]+glidelta/2./duration*t));
		}
	}
	else
	{
		double fval(freqs[0]);
		for (int k(1); k<len; k++)
		{
			fval = (freqs[k]*tgrid + fval*t) / (t + tgrid);
			t += tgrid;
			buf[k] = sin(2*PI*fval*t);
		}
	}
	return buf;
}

EXP_CS double * CSignal::Tone(vector<double> freqs, double dur_ms)
{
	int nSamplesNeeded = round(dur_ms/1000.*fs); 
	double *p = Tone(freqs, nSamplesNeeded);
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
	return p;
}
#ifndef NO_FFTW

#include "fftw3.h"

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

	for (int k(1); k<half; ++k) 
	{
		in[k][0] = 2 * mid[k][0];
		in[k][1] = 2 * mid[k][1];
	}

	if (len%2 == 0)	// len is even
		in[half][0] = mid[half][0];
	// leave the rest zero

	// iFFT
	fftw_plan p2 = fftw_plan_dft_1d(len, in, out, FFTW_BACKWARD, FFTW_ESTIMATE);
	fftw_execute(p2);

	fftw_destroy_plan(p1);
	fftw_destroy_plan(p2);

	for (int k(0); k<len; ++k)
	{// scale back down since the resulting array is scaled by len.
//		buf[k] = out[k][0] / len;	// This line fills buf with the identical signal with the input
		buf[k] = out[k][1] / len;	// This line is about the imaginary part of the analytic signal.
	}
	fftw_free(in); 
	fftw_free(out);
	return buf;
}


EXP_CS double * CSignal::ShiftFreq(double shift)
{
	CSignals copy(*this);
	Hilbert(nSamples);
	double t(0), grid(1./fs);
	const complex<double> j(0.0,1.0); 
	complex<double> datum;
	for (int k=0; k<nSamples; k++)
	{
		datum = copy.buf[k] + buf[k] * j;
		datum *= exp(j * shift *  2. * PI * t);
		buf[k] = real(datum);
		t += grid;
	}
	return buf;
}

EXP_CS double * CSignal::TCTS(double freq, double ratio)
{
	CSignals copy(*this);
	char errstr[256]="";




	ShiftFreq(freq*(ratio-1.));
	Resample((int)(fs*ratio), errstr);
	SetFs(copy.GetFs());
	return buf;
}



EXP_CS double * CSignal::HilbertEnv(int len)
{
	CSignal phaseshifted(*this), out(fs);
	phaseshifted.Hilbert(len);
	SetComplex();
	for (int k=0; k<len; k++) buf[2*k+1] = phaseshifted.buf[k];
	out.UpdateBuffer(len);
	for (int k=0; k<len; k++) out.buf[k] = abs(cbuf[k]);
	*this = out;
	return buf;
}

#endif 
/* This works but is slower.....
EXP_CS double * CSignal::HilbertEnv(int len)
{
	CSignals copy(*this);
	Hilbert(len);
	vector<complex<double>> data;
	data.resize(nSamples);
	int k(0);
	const complex<double> j(0.0,1.0); 
	for (vector<complex<double>>::iterator it=data.begin(); it!=data.end(); it++)
	{
		*it = copy.buf[k] + buf[k] * j;
		buf[k++] = abs(*it);
	}
	return buf;
}
*/

EXP_CS CSignal& CSignal::Replace(CSignal &newsig, double t1, double t2)
{ // signal portion between t1 and t2 is replaced by newsig
 // t1 and t2 are in ms
//	double lastendtofnewsig = newsig.GetDeepestChain()->endt();

	CSignal *p(this);
	CSignal copy(*this);
	double samplegrid = 1./fs;
	double deviationfromgrid = t1-((double)(int)(t1*fs))/fs;
	bool inbet(false); // true means t1 is in between chains.
	for (p=this; p && !inbet; p=p->chain)
	{
		if (t1>p->endt() && p->chain && t1<p->chain->tmark)
			inbet=true;
	}
	if (t1>0. && fabs(deviationfromgrid)>1.e-8 && deviationfromgrid>-samplegrid && deviationfromgrid < samplegrid) 
		t1 -= 1000.*samplegrid;  // because its in ms
	Trim(0, t1);
	if (inbet)
		newsig >>= t1-endt();
	if (newsig.chain) {delete newsig.chain; newsig.chain = NULL;}
	*this += &newsig;
	//if t2 coincides with the sampling grid, don't take that point here (it will be taken twice)
	deviationfromgrid = t2-((double)(int)(t2*fs))/fs;
	// deviationfromgrid of zero can masquerade as a very small number
	if (fabs(deviationfromgrid)>1.e-8 && deviationfromgrid>-samplegrid && deviationfromgrid < samplegrid)
		t2 += 1000.*samplegrid;  // because its in ms
	copy.Trim(t2, std::numeric_limits<double>::infinity());
	*this += &copy;
	MergeChains();
	return *this;
}


EXP_CS CSignal& CSignal::Insert(double timept, CSignal &newchunk)
{
	int id ;
	// Be careful, this is not a virtual function. So, when called from CSignals, this is a pointer to CSignal
	// casting won't work---i.e., you cannot declare it like this---CSignal *p((CSignal*)this)
	CSignal copy(*this), out(*this);
	CSignal *p(this);
	double insertduration = newchunk.GetDeepestChain()->dur();
	if (IsNull(timept))
	{
		for (; p; p=p->chain)
		{
			if (timept > p->endt() && timept < p->chain->tmark) 
				break;
		}
			// The line below looks precarious but when IsNull is true
			// if timept > p->endt(), then it has at least one p->chain available
			// so let's not worry about p->chain being NULL
		//at this point, p->chain and all forward need to time-shift right.
		p=p->chain; 
		*p >>= insertduration;

		*this = copy;
		//Now, *this is prepared (the new signal buffer can be inserted)
		for (p=&newchunk;  p; p=p->chain)
			p->tmark += timept;
		*this += newchunk;
		return *this;
	}
	else
	{
		for (bool done(0); p; p=p->chain)
		{
			if (!done && timept >= p->tmark && timept <= p->endt())
			{
				CSignal *orgchain(chain);
				CSignal *trailingchain = new CSignal(fs);
				id = (int)((timept-p->tmark) * fs/1000. +.5);
				int lenTrailingchain(p->nSamples-id);
				// divide p into the point prior to id and after id.
				trailingchain->UpdateBuffer(lenTrailingchain);
				memcpy(trailingchain->buf, &buf[id], sizeof(double)*lenTrailingchain);
				trailingchain->chain = orgchain;
				p->UpdateBuffer(id);
				*p += &newchunk; //this is concatenation
				*p += trailingchain; // concatenation
				done = true;
				continue;
			}
			if (done) // this means this chain is present after timept and needs time-shift right.
				*p >>= insertduration;
		}
		return *this;
	}
	//if (IsNull(timept))
	//{
	//	//insert here in the null portion
	//}
	//else
	//{
	//	for (; p; p=p->chain)
	//	{
	//		if (timept >= p->tmark && timept <= p->endt())
	//		{
	//			int id = (int)((timept-p->tmark) * fs/1000. +.5);
	//			int lenMoved = nSamples-id;
	//			double *dbuf = new double [lenMoved];
	//			memcpy(dbuf, &buf[id], sizeof(double)*(nSamples-id));
	//			p->UpdateBuffer(nSamples+newchunk.nSamples);
	//			memcpy(&buf[id], newchunk.buf, sizeof(double)*newchunk.nSamples);
	//			memcpy(&buf[id+newchunk.nSamples], dbuf, sizeof(double)*lenMoved);
	//			delete[] dbuf;
	//		}
	//	}

	//}
	
	return *this;

}

EXP_CS double * CSignal::Truncate(double time_ms1, double time_ms2)
{ // Returns integer buffer pointer, to "extract" a signals object, use Take() member function
	int id1 = round(time_ms1/1000.*fs);
	int id2 = round(time_ms2/1000.*fs)-1;
	return Truncate(id1, id2);
}

EXP_CS double * CSignal::Truncate(int id1, int id2, int code)
{
	id1 = max(0, id1);
	if (id1>id2) {
		nSamples = 0;
		return buf;
	}
	if (code)
	{
		// This will not work, if the signal has null portion in the middle and id1 and id2 cover beyond the null portion... 7/15/2016 bjk
		if (tmark>0)
		{
			CSignal copy(*this);
			double _tmark(copy.tmark);
			copy.tmark = 0;
			id1 -= (int)(_tmark/1000.*fs+.5);
			id2 -= (int)(_tmark/1000.*fs+.5);
			copy.Truncate(id1, id2);
			copy.tmark = _tmark;
			*this = copy;
			return buf;
		}
	}
	if (id2>nSamples-1) id2 = nSamples-1;
	nSamples = max(0,id2-id1+1);
	memmove(buf, logbuf+id1*bufBlockSize, nSamples*bufBlockSize);
	return buf;
}

EXP_CS double * CSignal::Silence(double dur_ms)
{
	int nSamplesNeeded = round(dur_ms/1000.*fs); 
	double *p = Silence(nSamplesNeeded);
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
	return p;
}

EXP_CS double * CSignal::DC(int nsamples)
{
	Reset();
	UpdateBuffer(nsamples);
	for (int i=0; i<nsamples; i++) buf[i] = 1.;
	return buf;
}

int CSignal::IsNull(double timept)
{
	if (GetType()!=CSIG_AUDIO) return 0;
	CSignal *p(this);
	for (; p; p=p->chain)
		if (timept >= p->tmark)
		{
			if (timept > p->endt()) return 0;
			else
				continue;
		}
		else 
			return 1;
	return 1;
}

int CSignal::GetType() const
{
	if (nSamples==0) // empty
	{
		if (tmark==0.)	return CSIG_EMPTY;
		else			return CSIG_NULL;	
	}
	else if (fs==2) // string
		return CSIG_STRING;
	else if (IsComplex()) // 
		return CSIG_COMPLEX;
	else if (nSamples==1 && fs==1) // scalar 
		return CSIG_SCALAR;
	else if (fs>10) // audio
		return CSIG_AUDIO;
	else
		return CSIG_VECTOR;
}

int CSignal::GetTypePlus() const
{
	int res = GetType();
	if (res==CSIG_VECTOR || res==CSIG_AUDIO)
		return res - (int)(bufBlockSize==1);
	else 
		return res;
}

vector<double> CSignal::Sum()
{
	vector<double> out ;
	for (CSignal *p=this; p; p=p->chain)
	{
		double sum(0.);
		for (int i=0; i<p->nSamples; i++)		sum += buf[i];
		out.push_back(sum);
	}
	return out;
}

vector<double> CSignal::Mean()
{
	vector<double> out ;
	for (CSignal *p=this; p; p=p->chain)
	{
		double sum(0.);
		for (int i=0; i<p->nSamples; i++)		sum += buf[i];
		out.push_back(sum/(double)p->nSamples);
	}
	return out;
}

vector<int> CSignal::MaxId()
{
	vector<int> out;
	double localMax(-1.e100);
	for (CSignal *p=this; p; p=p->chain)
	{
		int id;
		for (int i=0; i<p->nSamples; i++)
		{	
			if (buf[i] > localMax)
				localMax = buf[i], id=i+1;  // one-based index
		}
		out.push_back(id);
	}
	return out;
}

vector<double> CSignal::Max()
{
	vector<double> out ;
	for (CSignal *p=this; p; p=p->chain)
		out.push_back(((body*)p)->Max());
	return out;
}

CSignal& CSignal::Max(double crit)
{
	vector<double> out ;
	for (CSignal *p=this; p; p=p->chain)
		((body*)p)->Max(crit);
	return *this;
}

vector<double> CSignal::Min()
{
	vector<double> out ;
	for (CSignal *p=this; p; p=p->chain)
		out.push_back(((body*)p)->Min());
	return out;
}

CSignal& CSignal::Min(double crit)
{
	vector<double> out ;
	for (CSignal *p=this; p; p=p->chain)
		((body*)p)->Min(crit);
	return *this;
}

vector<int> CSignal::MinId()
{
	vector<int> out ;
	double localMin(1.e100);
	for (CSignal *p=this; p; p=p->chain)
	{
		int id;
		for (int i=0; i<p->nSamples; i++)
		{	
			if (buf[i] < localMin)
				localMin = buf[i], id=i+1;  // one-based index
		}
		out.push_back(id);
	}
	return out;
}


#ifndef NO_RESAMPLE

EXP_CS double * CSignal::Resample(vector<int> newfs, vector<int> lengths, char *errstr)
{ // This is not really for resampling but only used for the % operator with a vector (variable_ratio)
	//Therefore, fs is not updated.
	MakeChainless();
	errstr[0]=0;
	SRC_DATA sd;
	vector<float> data_in, data_out;
	int errcode;
	//First estimate the buffer length at the end of the processing, so we don't call UpdateBuffer multiple times.
	double mean(0.);
	int isum(0), id(0);
	for (vector<int>::iterator it=lengths.begin(); it!=lengths.end(); ++it)
		isum += *it;
	for (vector<int>::iterator it=newfs.begin(); it!=newfs.end(); ++it, id++)
	{
		double temp = *it*lengths[id]/isum;
		mean += *it*lengths[id]/isum;
	}
	if (mean>fs) UpdateBuffer((int)(nSamples * (mean/fs) + .5));

	SRC_STATE* handle;
	size_t cumid2(0);
	for (size_t k(0), cumid1(0); k<newfs.size(); k++)
	{
		handle = src_new (SRC_SINC_MEDIUM_QUALITY, 1, &errcode);
		data_in.resize(lengths[k]);
		sd.data_in = &data_in[0]; // data_in[0] doesn't change in the loop, but just keep it here
		for (int i(0); i<lengths[k]; i++) sd.data_in[i] = (float)buf[cumid1+i];
		cumid1 += lengths[k];
		sd.src_ratio = (double)newfs[k]/fs;
		sd.input_frames = lengths[k];
		sd.output_frames =  (long) (lengths[k] * (sd.src_ratio) + .5) ; // sd.src_ratio+1 should be right, but just in case 
		data_out.resize(sd.output_frames);
		sd.data_out = &data_out[0];
		int res = src_process (handle, &sd);
		if (!res)
		{
			for (int i(0); i<sd.output_frames_gen; i++) 			buf[cumid2+i] = sd.data_out[i];
			cumid2 += sd.output_frames_gen;
			sd.end_of_input = (int)(k==newfs.size()-1);
		}
		else
		{
			strcpy(errstr, src_strerror(res));
			return NULL;
		}
	}
	nSamples = (int)cumid2;
	return buf;
}

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

#endif //NO_RESAMPLE

void CSignal::UpSample(int cc)
{
	MakeChainless();

	if (cc==1) return;
	int newLength = nSamples * cc;
	CSignal temp(fs*cc);
	temp.UpdateBuffer(newLength);
	memset((void*)temp.buf, 0, sizeof(double)*newLength);
	for (int i=0; i<nSamples; i++)
		temp.buf[i*cc] = buf[i];
	*this = temp;
}

void CSignal::DownSample(int cc)
{
	MakeChainless();

	if (cc==1) return;
	int newLength = nSamples / cc;
	CSignal temp(fs/cc);
	temp.UpdateBuffer(newLength);
	for (int i=0; i<newLength; i++)
		temp.buf[i] = buf[cc*i];
	*this = temp;
}

int CSignal::Filter(const CSignal& num, const CSignal& den, char *errstr)
{
	int reqLeng = max(1, max(num.nSamples,den.nSamples) );
	Filter(reqLeng, num.buf, den.buf);
	return 1;
}

int CSignal::filtfilt(const CSignal& num, const CSignal& den, char *errstr)
{
	int reqLeng = max(1, max(num.nSamples,den.nSamples) );
	filtfilt(reqLeng, num.buf, den.buf);
	return 1;
}

void CSignal::Filter(int nTabs, double *num, double *den)
{
	double *out = new double[(int)(nSamples*1.1)+1];
	if (den[0]!=0.)
		filter(nTabs, num, den, nSamples, buf, out);
	else
		filter(nTabs, num, nSamples, buf, out);
	if (buf) delete[] buf;
	buf = out;
}

void CSignal::Filter(int nTabs, double *num) // for FIR
{
	double den(0.);
	Filter(nTabs, num, &den);
}

void CSignal::filtfilt(int nTabs, double *num, double *den)
{
	MakeChainless();
	//Transient edges not handled, only zero-padded edges 
	CSignal temp(fs), temp2(fs), out(fs);
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

void CSignal::filtfilt(int nTabs, double *num)
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

	CSignal temp(*this);
	double *tempBuf = temp.GetBuffer();
	for (int i=0; i<nSamples ; i++)
		tempBuf[nSamples-i-1]=buf[i];
	*this = temp;
}

//#define RETURNNULL {	for (int i=0; i<nColons; i++) delete[] holder[i]; delete[] holder; return NULL;	}

#ifndef NO_IIR

int CSignal::IIR(int kind, int type, int order, double *freqs, double passRipple_dB, double stopFreqORAttenDB, char *errstr)
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

#endif // NO_IIR

EXP_CS std::string CSignal::string()
{
	int k;
	std::string out;
	out.resize(nSamples);
	for (k=0; k<nSamples && strbuf[k]; k++)
		out[k] = *(strbuf+k);
	out.resize(k);
	return out;
}

EXP_CS char *CSignal::getString(char *str, const int size)
{
	memcpy(str, strbuf, min(nSamples, size-1));
	str[ min(nSamples, size-1) ] = '\0';
	return str;
}

EXP_CS CSignal &CSignal::SetString(const char *str)
{
	Reset(2);
	bufBlockSize = 1;
	UpdateBuffer((int)strlen(str)+1);
	strcpy(strbuf, str);
	return *this;
}

EXP_CS CSignal &CSignal::SetString(const char c)
{
	Reset(2);
	bufBlockSize = 1;
	if (c==0) return *this;
	UpdateBuffer(2);
	memset(strbuf, 0, 2);
	strbuf[0] = c;
	nSamples = 1;
	return *this;
}

CSignal &CSignal::each(double (*fn)(double))
{
	if (GetType()==CSIG_VECTOR || GetType()==CSIG_SCALAR)
		body::each(fn); 
	else if (GetType()==CSIG_AUDIO)
	{
		for (CSignal *p=this; p; p=p->chain)
			for (int k(0); k<p->nSamples; k++)
			{
				if (p->buf[k]<0) 
					p->buf[k] = -fn(-p->buf[k]);
				else
					p->buf[k] = fn(p->buf[k]);
			}
	}
	else
		throw "each()--only for vector/scalar or audio"; 
	return *this;
}

CSignal &CSignal::each(complex<double> (*fn)(complex<double>))
{
	if (GetType()==CSIG_COMPLEX)
		body::each(fn); 
	else
		throw "each()--expecting complex number"; 
	return *this;
}

CSignal &CSignal::each(double (*fn)(complex<double>))
{
	if (GetType()==CSIG_COMPLEX)
		body::each(fn); 
	else
		throw "each()--expecting complex number"; 
	return *this;
}

CSignal &CSignal::each(double (*fn)(double, double), body &arg2)
{
	if (GetType()==CSIG_VECTOR || GetType()==CSIG_SCALAR)
		body::each(fn,arg2); 
	else if (GetType()==CSIG_AUDIO)
	{
		if (arg2.nSamples==1) 
		{
			double val = arg2.value();
			for (CSignal *p=this; p; p=p->chain)
//				for (int i=0; i<p->nSamples; ++i)
//					p->buf[i] = (p->buf[i]>0 ?1:-1)*fn(p->buf[i]>0 ? p->buf[i]: -p->buf[i], val);
				for (int k(0); k<p->nSamples; k++)
				{
					if (p->buf[k]<0) 
						p->buf[k] = -fn(val, -p->buf[k]);
					else
						p->buf[k] = fn(val, p->buf[k]);
				}
		}
		else
		{
			for (CSignal *p=this; p; p=p->chain)
				for (int i=0; i<min(nSamples, arg2.nSamples); ++i) 
					p->buf[i] = fn(p->buf[i], arg2.buf[i]); 
		}
	}
	else
		throw "each()--only for vector/scalar or audio"; 
	return *this;
}

CSignal &CSignal::each(complex<double> (*fn)(complex<double>, complex<double>), body &arg2)
{
	if (GetType()==CSIG_COMPLEX)
		body::each(fn, arg2);  
	else
		throw "each()--expecting complex number"; 
	return *this;

}


CSignal &CSignal::transpose1()
{
	if (nSamples == 1)
		return *this;

	CSignal t(buf[0]);
	SwapContents1node(t);
	return *this;
}


double *CSignal::Hamming(int len)
{
	if (len <= 0)
		throw "Length must be a positive integer.";
	Reset();
	UpdateBuffer(len);	// allocates memory if necessary
	for (int i=0; i<len; ++i)
		buf[i] = 0.54 - 0.46*cos(2.0*PI*i/(len-1.0));
	return buf;
}


double *CSignal::Blackman(int len, double alp)
{
	if (len <= 0)
		throw "Length must be a positive integer.";
	Reset();
	UpdateBuffer(len);	// allocates memory if necessary
	for (int i=0; i<len; ++i)
		buf[i] = (1-alp)/2 - 0.5*cos(2.0*PI*i/(len-1.0)) + alp/2*cos(4.0*PI*i/(len-1.0));
	return buf;
}

int CSignal::WriteAXL(FILE* fp)
{
	CSignal *p(this);
	size_t res;
	int nChains = CountChains();
	res = fwrite((void*)&fs, sizeof(fs),1,fp);
	res = fwrite((void*)&nChains, sizeof(nChains),1,fp);
	for (int k=0; k<nChains; k++, p=p->chain)
	{
		res = fwrite((void*)&p->nSamples, sizeof(nSamples),1,fp);
		res = fwrite((void*)&p->tmark, sizeof(tmark),1,fp);
		res = fwrite((void*)p->buf, p->bufBlockSize,p->nSamples,fp);
	}
	return (int)res;
}

EXP_CS CSignals::CSignals()
: next(NULL)
{
}

EXP_CS CSignals::CSignals(int sampleRate)
:next(NULL)
{
	SetFs(max(sampleRate,1));
}

EXP_CS CSignals::CSignals(double value)
:next(NULL)
{
	SetFs(1);
	SetValue(value);
}

EXP_CS CSignals::CSignals(const CSignals& src)
:next(NULL)
{
	*this = src;
}

EXP_CS CSignals::CSignals(const CSignal& src)
:next(NULL)
{
	bufBlockSize = src.bufBlockSize;
	UpdateBuffer(src.nSamples);
	nSamples = src.nSamples;
	tmark = src.tmark;
	fs = src.GetFs();
	memcpy(buf, src.buf, nSamples*bufBlockSize);
	if (src.chain)
	{
		chain = new CSignal;
		*chain = *src.chain;
	}
}

EXP_CS CSignals::CSignals(double *y, int len)
:next(NULL)
{
	SetFs(1);
	UpdateBuffer(len);
	memcpy(buf, y, sizeof(double)*len);
}

//EXP_CS CSignals::CSignals(FILE* fp)
//:next(NULL)
//{
//	ReadAXL(fp);
//}

EXP_CS CSignals::~CSignals()
{
	if (next) {
		delete next;
	}
}

EXP_CS void CSignals::SetNextChan(CSignal *second)
{
	if (second) {
		if (next) {
			delete next;
			next = NULL;
		}
		next = new CSignal;
		*next = *second;
	}
}

void CSignals::SetValue(double v) 
{
	Reset(1);
	body::SetValue(v);
}

void CSignals::SetValue(complex<double> v) 
{
	Reset(1);
	body::SetValue(v);
}

EXP_CS CSignals& CSignals::Reset(int fs2set)	// Empty all data fields - sets nSamples to 0.
{
	CSignal::Reset(fs2set);
	if (next) {
		delete next;
		next=NULL;
	}
	//cell should not be cleared here because of CAstSig::SetCell and CAstSig::AddCell calls
	return *this;
}

EXP_CS CSignals& CSignals::operator=(const CSignals& rhs)
{   // Make a deep copy only for buf, but not for sc, because sc is not necessarily dynamically allocated.
	// Thus, BE Extra careful when making writing an assignment statement about the scaling..
	if (this != &rhs) 
	{
		CSignal::operator=(rhs);
		SetNextChan(rhs.next);
		cell = rhs.cell;
	}
	return *this; // return self-reference so cascaded assignment works
}
EXP_CS CSignals& CSignals::operator-(void)	// Unary minus
{
	CSignal::operator-();
	if (next)	-*next;
	return *this;
}

EXP_CS CSignals& CSignals::operator+=(const double con) 
{
	CSignals _sec(con); 
	return (*this+=(_sec)); 
}

EXP_CS CSignals& CSignals::operator+=(CSignal &sec)
{
	CSignals _sec(sec); 
	return (*this+=(_sec)); 
}

EXP_CS CSignals& CSignals::operator+=(CSignals &sec)
{
	SwapCSignalsPutScalarSecond(*this, sec);
	CSignal::operator+=(sec);
	if (next)
		if (sec.next)	*next += *sec.next;
		else			*next += sec;
	return *this;
}

EXP_CS const CSignals& CSignals::operator+=(CSignal *yy)
{
	CSignal::operator+=(yy);
	if (next) 	*next += yy;
	return *this;
}

EXP_CS const CSignals& CSignals::operator+=(CSignals *yy)
{
	CSignal::operator+=(yy);
	if (next) {
		if (yy->next)
			*next += yy->next;	// stereo += stereo
		else
			*next += yy;		// stereo += mono
	}
	return *this;
}

EXP_CS CSignals& CSignals::operator*=(const double con) 
{
	CSignals _sec(con); 
	return (*this*=(_sec)); 
}
EXP_CS CSignals& CSignals::operator*=(CSignal &sec)
{
	CSignals _sec(sec); 
	return (*this*=(_sec)); 
}

EXP_CS CSignals& CSignals::operator*=(CSignals &sec)
{
	SwapCSignalsPutScalarSecond(*this, sec);
	CSignal::operator*=(sec);
	if (next)
		if (sec.next)	*next *= *sec.next;
		else			*next *= sec;
	return *this;
}


EXP_CS CSignals& CSignals::Reciprocal(void)
{
	CSignal::Reciprocal();
	if (next)	next->Reciprocal();
	return *this;
}


EXP_CS CSignals& CSignals::operator>>=(const double delta)
{
	CSignal::operator>>=(delta);
	if (next)	*next>>=delta;
	return *this;
}

EXP_CS CSignals& CSignals::Take(CSignals& out, int id1, int id2)
{
	CSignal::Take(out, id1, id2);
	if (next!=NULL) next->Take(*out.next, id1, id2);
	return out;
}

EXP_CS void CSignals::Dramp(double dur_ms, int beginID)
{
	CSignal::Dramp(dur_ms, beginID);
	if (next!=NULL) next->Dramp(dur_ms, beginID);
}

EXP_CS CSignals& CSignals::Trim(double begin_ms, double end_ms)
{
	CSignal::Trim(begin_ms, end_ms);
	if (next)		next->Trim(begin_ms, end_ms);
	return *this;
}

EXP_CS CSignals& CSignals::Replace(CSignals &newsig, double t1, double t2)
{
	CSignal::Replace(newsig, t1, t2);
	if (next)		next->Replace(newsig, t1, t2);
	return *this;
}

EXP_CS CSignals& CSignals::Insert(double timept, CSignals &newchunk)
{
	CSignal::Insert(timept, newchunk);
	if (next)		next->Insert(timept, newchunk);
	return *this;
}

EXP_CS double * CSignals::Modulate (double *env, int lenEnv)
{
	// Modulate this object with env 
	// If lenEnv may be greater than nSamples, then the samples in env after nSamples are ignored.
	for (int i=0; i<nSamples && i<lenEnv; i++)	
		buf[i] *= env[i];
	if (next!=NULL) 
	{
		for (int i=0; i<nSamples && i<lenEnv; i++)	
			next->buf[i] *= env[i];
	}
	return buf;
}


EXP_CS double * CSignals::Mag()
{ // I don't remember any more when I used this last time. 11/28/2016
	// output of FFT ... if used in other context, note...to generalize // 11/26/2016
	CSignal out(*this);
	if (!IsComplex()) return buf; // if real, return as is.
	out.UpdateBuffer(nSamples);
	for (int k(0); k<nSamples; k++) 		
		out.buf[k] = sqrt(buf[2*k]*buf[2*k]+buf[2*k+1]*buf[2*k+1]);
	SetReal();
	memcpy(buf, out.buf, sizeof(double)*nSamples);
	return buf;
}

EXP_CS CSignal CSignals::Angle()
{// I don't remember any more when I used this last time. 11/28/2016
	//"imaginary" --- output of FFT
	CSignal out(*this);
	double *x1 = buf;
	double *x2 = next->buf;
	out.UpdateBuffer(nSamples);
	for (int i=0; i<nSamples; i++) 		
		buf[i] = atan(x2[i]/x1[i]);
	return *this;
}

EXP_CS void CSignals::DownSample(int cc)
{
	CSignal::DownSample(cc);
	if (next!=NULL) next->DownSample(cc);
}

EXP_CS void CSignals::UpSample(int cc)
{
	CSignal::UpSample(cc);
	if (next!=NULL) next->UpSample(cc);
}

#ifndef NO_RESAMPLE
EXP_CS double * CSignals::Resample(int newfs, char *errstr)
{
	CSignal::Resample(newfs, errstr);
	if (next!=NULL) next->Resample(newfs, errstr);
	return buf;
}

EXP_CS double * CSignals::Resample(vector<int> newfs, vector<int> lengths, char *errstr)
{
	CSignal::Resample(newfs, lengths, errstr);
	if (next!=NULL) next->Resample(newfs, lengths, errstr);
	return buf;
}

EXP_CS double * CSignals::fm2(CSignal flutter, int multiplier, char *errstr)
{
	CSignal::fm2(flutter, multiplier, errstr);
	if (next!=NULL) next->fm2(flutter, multiplier, errstr);
	return buf;
}

#endif // NO_RESAMPLE

EXP_CS void CSignals::Filter(int nTabs, double *num, double *den)
{
	CSignal::Filter(nTabs, num, den);
	if (next!=NULL) next->Filter(nTabs, num, den);
}

EXP_CS void CSignals::filtfilt(int nTabs, double *num, double *den)
{
	CSignal::filtfilt(nTabs, num, den);
	if (next!=NULL) next->filtfilt(nTabs, num, den);
}

EXP_CS CSignals& CSignals::LogOp(CSignals &rhs, int type)
{
	CSignal::LogOp(rhs,type);
	if (next) next->LogOp(rhs,type);
	return *this;
}

EXP_CS double CSignals::MakeChainless()
{
	CSignal::MakeChainless();
	if (next!=NULL) 
	{
		next->MakeChainless();
		int diff = nSamples - next->nSamples;
		CSignal sil(fs);
		sil.Silence(abs(diff));
		if (diff>0)
			*next += &sil;
		else if (diff<0)
			*(CSignal*)this += &sil;
	}
	return alldur();
}

EXP_CS CSignals &CSignals::each(double (*fn)(double))
{
	CSignal::each(fn);
	if (next) 	next->each(fn);
	return *this;
}

EXP_CS CSignals &CSignals::each(complex<double> (*fn)(complex<double>))
{
	CSignal::each(fn);
	if (next) 	next->each(fn);
	return *this;
}

EXP_CS CSignals &CSignals::each(double (*fn)(complex<double>))
{
	CSignal::each(fn);
	if (next) 	next->each(fn);
	return *this;
}

EXP_CS CSignals &CSignals::each(double (*fn)(double, double), body &arg2)
{
	CSignal::each(fn, arg2);
	if (next) 	next->each(fn, arg2);
	return *this;
}

EXP_CS CSignals &CSignals::each(complex<double> (*fn)(complex<double>, complex<double>), body &arg2)
{
	CSignal::each(fn, arg2);
	if (next) 	next->each(fn, arg2);
	return *this;
}


#ifndef NO_SF

EXP_CS CSignals::CSignals(const char* wavname)
:next(NULL)
{
	char errstr[256];
	Wavread(wavname, errstr);

}

EXP_CS int CSignals::Wavread(const char *wavname, char *errstr)
{
	SNDFILE *wavefileID;
	SF_INFO sfinfo ;
	sf_count_t count ;
	if ((wavefileID = sf_open (wavname, SFM_READ, &sfinfo)) == NULL)
	{	sprintf(errstr, "Unable to open audio file '%s'\n", wavname);
		sf_close (wavefileID) ;
		return NULL;	}
	if (sfinfo.channels>2) { strcpy(errstr, "Up to 2 channels (L R) are allowed in AUX--we have two ears, dude!"); return NULL;}
	Reset(sfinfo.samplerate);
	if (sfinfo.channels==1)
	{
		UpdateBuffer((int)sfinfo.frames);
		count = sf_read_double (wavefileID, buf, sfinfo.frames);  // common.h
	}
	else
	{
		double *buffer = new double[(size_t)sfinfo.channels*(int)sfinfo.frames];
		count = sf_read_double (wavefileID, buffer, sfinfo.channels*sfinfo.frames);  // common.h

		double (*buf3)[2];
		next = new CSignal(sfinfo.samplerate);
		int m(0);
		buf3 = (double (*)[2])&buffer[m++];
		UpdateBuffer((int)sfinfo.frames);
		for (int k=0; k<sfinfo.frames; k++)			buf[k] = buf3[k][0];
		buf3 = (double (*)[2])&buffer[m++];
		next->UpdateBuffer((int)sfinfo.frames);
		for (int k=0; k<sfinfo.frames; k++)			next->buf[k] = buf3[k][0];
		delete[] buffer;
	}
	sf_close (wavefileID) ;
	return 1;
}

EXP_CS int CSignals::Wavwrite(const char *wavname, char *errstr, std::string wavformat)
{
	MakeChainless();
	SF_INFO sfinfo ;
	SNDFILE *wavefileID;
	sfinfo.channels = (next) ? 2 : 1; 
	if (wavformat.length()==0)
		sfinfo.format = SF_FORMAT_WAV + SF_FORMAT_PCM_16; // default
	else if (wavformat=="8")
		sfinfo.format = SF_FORMAT_WAV + SF_FORMAT_PCM_U8;
	else if (wavformat=="16")
		sfinfo.format = SF_FORMAT_WAV + SF_FORMAT_PCM_16;
	else if (wavformat=="24")
		sfinfo.format = SF_FORMAT_WAV + SF_FORMAT_PCM_24;
	else if (wavformat=="32")
		sfinfo.format = SF_FORMAT_WAV + SF_FORMAT_PCM_32;
	else if (wavformat=="ulaw")
		sfinfo.format = SF_FORMAT_WAV + SF_FORMAT_ULAW;
	else if (wavformat=="alaw")
		sfinfo.format = SF_FORMAT_WAV + SF_FORMAT_ALAW;
	else if (wavformat=="adpcm1")
		sfinfo.format = SF_FORMAT_WAV + SF_FORMAT_IMA_ADPCM;
	else if (wavformat=="adpcm2")
		sfinfo.format = SF_FORMAT_WAV + SF_FORMAT_MS_ADPCM;
//	else if (wavformat=="vorbis")
//		sfinfo.format = SF_FORMAT_OGG + SF_FORMAT_VORBIS; // not available ...  ogg.c requires external lib which I don't have yet. bjkwon 03/19/2016
	else
	{	sprintf(errstr, "Supported waveformat---8, 16, 24, 32, ulaw, alaw, adpcm1 or adpcm2.\n", wavname);
		return NULL;	}
	sfinfo.frames = nSamples;
	sfinfo.samplerate = fs;
	sfinfo.sections = sfinfo.seekable = 1;
	if ((wavefileID = sf_open (wavname, SFM_WRITE, &sfinfo)) == NULL)
	{	sprintf(errstr, "Unable to open/write audio file to '%s'\n", wavname);
		sf_close (wavefileID) ;
		return NULL;	}
	if (sfinfo.channels==1)
		sf_writef_double(wavefileID, buf, nSamples);
	else
	{
		double *buffer = new double[(size_t)sfinfo.channels*nSamples];
		double (*buf3)[2];
		int m(0);
		// it should not be p && m<2 but just m<2, because p will never be NULL (why? next is CSignal, not CSignals)
		for (CSignals *p = this; p && m<2; p=(CSignals*)p->next, m++)
		{
			buf3 = (double (*)[2])&buffer[m];
			for (int k=0; k<nSamples; k++)			
				buf3[k][0] = p->buf[k];
		}
		sf_writef_double(wavefileID, buffer, nSamples);
		delete[] buffer;
	}
	sf_close (wavefileID) ;
	return 1;
}
#endif // NO_SF

#ifdef _WINDOWS

#ifndef NO_PLAYSND

EXP_CS int CSignals::PlayArray(char *errstr)
{
	return PlayArray(0, errstr);
}

EXP_CS int CSignals::PlayArray(int DevID, char *errstr)
{ // returns a negative number if error occurrs
	return PlayArray(DevID, 0, NULL, 2, errstr); 
	// This is how you play in blocking mode (specify 2 for the nProgReport even though you are not utilizing any messaging back to hWnd.. This is just due to the way wavBuffer2snd is written in waves.cpp)
	// Jan 19, 2013. BJ Kwon
}

EXP_CS int CSignals::PlayArray(int DevID, UINT userDefinedMsgID, HWND hApplWnd, double *block_dur_ms, char *errstr, int loop)
{// returns a negative number if error occurrs
 // This play the sound by specified block duration, generating event notification in every block
 // block_dur_ms is adjusted by the quantization of fs. Therefore, user should check if it has beend adjusted during this call.
 	int nSamples4Block = (int)(*block_dur_ms/(1000./(double)fs)+.5);
	*block_dur_ms = (double) nSamples4Block *1000. /(double)fs;
	double _nBlocks = (double)nSamples / nSamples4Block;
	int nBlocks = (int)_nBlocks;
	if (_nBlocks - (double)nBlocks > 0.1) nBlocks++;
	return PlayArray(DevID, userDefinedMsgID, hApplWnd, nBlocks, errstr, loop);
}

EXP_CS int CSignals::PlayArrayNext(int DevID, UINT userDefinedMsgID, HWND hApplWnd, double *block_dur_ms, char *errstr)
{// returns a negative number if error occurrs
 // This play the sound by specified block duration, generating event notification in every block
 // block_dur_ms is adjusted by the quantization of fs. Therefore, user should check if it has beend adjusted during this call.
 	int nSamples4Block = (int)(*block_dur_ms/(1000./(double)fs)+.5);
	*block_dur_ms = (double) nSamples4Block *1000. /(double)fs;
	double _nBlocks = (double)nSamples / nSamples4Block;
	int nBlocks = (int)_nBlocks;
	if (_nBlocks - (double)nBlocks > 0.1) nBlocks++;
	return PlayArrayNext(DevID, userDefinedMsgID, hApplWnd, nBlocks, errstr);
}

short * CSignals::makebuffer(int &nChan)
{	//For now this is only 16-bit playback (Sep 2008)
	short *Buffer2Play;
	MakeChainless();
	if (next!=NULL)
	{
		double *buf2 = next->buf;
		Buffer2Play = new short[nSamples*2];
		for (int i=0; i<nSamples; ++i) {
			Buffer2Play[i*2] = (short)(_double_to_24bit(buf[i]) >> 8);
			Buffer2Play[i*2+1] = (short)(_double_to_24bit(buf2[i]) >> 8);
		}
		nChan=2;
	}
	else
	{
		Buffer2Play = new short[nSamples];
		_double_to_short(buf, Buffer2Play, nSamples);
		nChan=1;
	}
	return Buffer2Play;
}

EXP_CS int CSignals::PlayArray(int DevID, UINT userDefinedMsgID, HWND hApplWnd, int nProgReport, char *errstr, int loop)
{// Re-do error treatment 6/1/2016 bjk
	errstr[0]=0;
	int nChan, ecode(MMSYSERR_NOERROR);
	short *Buffer2Play = makebuffer(nChan);
	return PlayBufAsynch16(DevID, Buffer2Play, nSamples, nChan, fs, userDefinedMsgID, hApplWnd, nProgReport, loop, errstr);
}

EXP_CS int CSignals::PlayArrayNext(int DevID, UINT userDefinedMsgID, HWND hApplWnd, int nProgReport, char *errstr)
{
	errstr[0]=0;
	int nChan, ecode(MMSYSERR_NOERROR);
	short *Buffer2Play = makebuffer(nChan);
	return continuePlay(DevID, Buffer2Play, nSamples, nChan, userDefinedMsgID, nProgReport, errstr);
}

#endif // NO_PLAYSND

#endif

#ifndef NO_FFTW

EXP_CS double * CSignals::FFT(int len)
{
	MakeChainless();
	len = min(nSamples,len);
	int nFFTr2cOut = len/2+1;

	double *in, *out2;
	fftw_complex *out;
	fftw_plan p, p2;

	in = (double*) fftw_malloc(sizeof(double) * len);
	out2 = (double*) fftw_malloc(sizeof(double) * len);
	out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * nFFTr2cOut);
	memcpy(in, buf, sizeof(double)*len);

	p = fftw_plan_dft_r2c_1d(len, in, out, FFTW_ESTIMATE);
	fftw_execute(p);

	//FILE *fp=fopen("fftout.txt","wt");
	//for (int k=0; k<nFFTr2cOut; k++)
	//{
	//	fprintf(fp, "%d:\t%8.5e\t%8.5e\n", k, out[k][0], out[k][1]);
	//}
	//fclose(fp);

	SetComplex();
	memcpy(cbuf, out, sizeof(*cbuf)*nFFTr2cOut);

	complex<double> *tp = reinterpret_cast<complex<double> *> (out);
	for (int k(1); k<nFFTr2cOut; k++)
		cbuf[nSamples-k] = conj(tp[k]);

	p2 = fftw_plan_dft_c2r_1d(len, out, out2, FFTW_ESTIMATE);
	fftw_execute(p2);

	fftw_destroy_plan(p);
	fftw_destroy_plan(p2);
	fftw_free(in); 
	fftw_free(out);
	fftw_free(out2);
	*this /= (double)len;
	return buf;
}

EXP_CS double * CSignals::iFFT(void)
{
	MakeChainless();
	int len = nSamples;
	bool loop(true);
	fftw_plan p;

	//Check if it's complex
	if (IsComplex())
	{
		//check if it's Hermitian
		for (int k=1; loop && k<len/2; k=k+2)
		{
			if (cbuf[k] != conj(cbuf[len-k])) loop = false;
		}
		if (!loop) { /*do c2c */ return buf;}

		fftw_complex *in;
		double *out;

		out = (double*) fftw_malloc(sizeof(double) * len);
		in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * (len/2+1) );
		memcpy(in, cbuf, sizeof(*cbuf)*(len/2));
		fftw_complex* tp = reinterpret_cast<fftw_complex*>(cbuf);
		if ( len%2 == 0 )
		{
			memcpy(&in[len/2], &cbuf[len/2], sizeof(*cbuf));
		}

		p = fftw_plan_dft_c2r_1d(len, in, out, FFTW_ESTIMATE);

		fftw_execute(p);
		memcpy(buf, out, sizeof(double)*len);
		bufBlockSize = sizeof(double); 
		*this /= (double)len;
		fftw_free(in); 
		fftw_free(out);
	}
	fftw_destroy_plan(p);
	return buf;
}

EXP_CS double * CSignals::Hilbert(int len)
{
	CSignal::Hilbert(len);
	if (next!=NULL) next->Hilbert(len);
	return buf;
}

EXP_CS double * CSignals::HilbertEnv(int len)
{
	CSignal::HilbertEnv(len);
	if (next!=NULL) next->HilbertEnv(len);
	return buf;
}

EXP_CS double * CSignals::ShiftFreq(double shift)
{
	CSignal::ShiftFreq(shift);
	if (next!=NULL) next->ShiftFreq(shift);
	return buf;
}

EXP_CS double * CSignals::TCTS(double freq, double ratio)
{
	CSignal::TCTS(freq, ratio);
	if (next!=NULL) next->TCTS(freq, ratio);
	return buf;
}



#endif

EXP_CS int CSignals::GetType() const
{
	if (cell.size()>0)
		return CSIG_CELL;
	else 
		return CSignal::GetType();
}

EXP_CS int CSignals::ReadAXL(FILE* fp, bool logical)
{
	size_t res;
	int res2, nChains;
	res = fread((void*)&fs, sizeof(fs), 1, fp);
	res2 = ftell(fp);
	Reset(fs);
	res = fread((void*)&nChains, sizeof(nChains), 1, fp);
	res2 = ftell(fp);
	for (int k=0; k<nChains; k++)
	{
		int cum(0), _nSamples;
		CSignal readsig(fs);
		res = fread((void*)&_nSamples, sizeof(nSamples), 1, fp); // readsig.nSamples shouldn't be directly modified, it should be done inside UpdateBuffer()
		res2 = ftell(fp);
		readsig.UpdateBuffer(_nSamples);
		if (logical) readsig.MakeLogical();
		res = fread((void*)&readsig.tmark, sizeof(tmark), 1, fp);
		res2 = ftell(fp);
		while(cum<readsig.nSamples)
		{
			res = fread((void*)&readsig.logbuf[cum], readsig.bufBlockSize, readsig.nSamples-cum, fp);
			cum += (int)res;
		}
		AddChain(readsig);
		res2 = ftell(fp);
	}
	MergeChains();
	return 1;
}

EXP_CS int CSignals::WriteAXL(FILE* fp)
{
	int res = CSignal::WriteAXL(fp);
	if (next)
		res += next->WriteAXL(fp);
	return res;
}