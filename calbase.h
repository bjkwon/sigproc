#pragma once
#include <float.h>
#include <list>
#include "sigproc.h"

class calbase
{
public:
	CEqSig body;
	calbase(void) {n_names=0;}
	virtual ~calbase(void) {if (n_names>0) delete[] names;}
	string name;
	string *names;
	int n_names; // actual number of names minus one
	string GetName() {return name;}
	EXP_CS 	void getArguments(list<CEqSig *> arg, CEqSig *args, int &nArgs);
	virtual CEqSig& calc(list<CEqSig *> arg) {body.sig.Reset(body.sig.GetFs()); return body;}
	EXP_CS double getTimeMarks(CEqSig& eqIn, string funcname, int paramID, double *tmarks);
};

class CalcManager
{
	list<calbase *> flst;
	list<CEqSig *> arg;

public:
	EXP_CS CalcManager();
	virtual ~CalcManager(void)
	{
		list <calbase *>::iterator c1_Iter;
		for ( c1_Iter = flst.begin( ); c1_Iter != flst.end( ); c1_Iter++ )
		{
			calbase *p = *c1_Iter;
			delete p;
		}
	}

	int GetCount()			{	return (int)flst.size();}

	void Add(calbase* a)	{	flst.push_back(a);	}

	void AddArg(CEqSig *a)	{	arg.push_back(a);	}
	void ChangeLastArg(CEqSig *a)	{	arg.pop_back(); arg.push_back(a);	}
	void ClearArg()			{	arg.clear();	}

	CEqSig& Calc(const char* name, int fs=0)
	{
		list <calbase *>::iterator c1_Iter;
		calbase *p;
		char buf[256];
		size_t n = arg.size();
		
		for ( c1_Iter = flst.begin( ); c1_Iter != flst.end( ); c1_Iter++ )
		{
			p = *c1_Iter;
			if (p->n_names==0)
			{
				if (p->GetName()==name)
				{	
					p->body.sig.Reset(fs);
					p->calc(arg);
					return 		p->body;	}
			}
			else
			{
				for (int i=0; i<p->n_names; i++)
				{
					if (p->names[i]==name)
					{	
						p->body.sig.Reset(fs);
						p->name = name;
						p->calc(arg);
						return 		p->body;	}
				}
			}
		}
		sprintf(buf, "function '%s' not defined.", name);
		throw buf; // If you arrive on this line, it will crash.
	}
};

#define IN1OUT1(DERIVEDCLASSNAME, NAMEINC, NAMEINPSYCON) \
class DERIVEDCLASSNAME : public calbase	{public:	\
DERIVEDCLASSNAME(void) {name = #NAMEINPSYCON;} \
virtual ~DERIVEDCLASSNAME(void)	{} \
CEqSig& calc(list<CEqSig *> arg) \
{	char errStr[256]; \
	if (arg.size()!=1)	{ sprintf (errStr, "%s must have one argument.", name); throw errStr; }\
	else 	{ CEqSig  *inarg = arg.back(); if (inarg->len()<2) body.sig.SetValue(NAMEINC(inarg->sig.value()));	else { body.sig.UpdateBuffer(inarg->sig.nSamples()); for (int i=0; i<body.len(); i++) body.sig.buf[i] = NAMEINC(inarg->sig.buf[i]); body.sig.tmark = inarg->sig.tmark;}	} \
	return body; } };

#define IN1OUT1_EXPRESSION(DERIVEDCLASSNAME, NAMEINPSYCON, EXPRESSION) \
class DERIVEDCLASSNAME : public calbase	{public:	\
DERIVEDCLASSNAME(void) {name = #NAMEINPSYCON;} \
virtual ~DERIVEDCLASSNAME(void)	{} \
CEqSig& calc(list<CEqSig *> arg) \
{	char errStr[256]; \
	if (arg.size()!=1)	{ sprintf (errStr, "%s must have one argument.", name); throw errStr; }\
	else 	{ CEqSig  *inarg = arg.back(); body.sig.SetValue(EXPRESSION); }	\
	return body; } };

IN1OUT1(cal_sin,sin,sin)
IN1OUT1(cal_cos,cos,cos)
IN1OUT1(cal_tan,tan,tan)
IN1OUT1(cal_log,log,log)
IN1OUT1(cal_log10,log10,log10)
IN1OUT1(cal_abs,fabs,abs)
IN1OUT1(cal_ceil,ceil,ceil)
IN1OUT1(cal_floor,floor,floor)
IN1OUT1_EXPRESSION(cal_dur, dur, inarg->sig.GetDuration())
IN1OUT1_EXPRESSION(cal_mean, mean, inarg->sig.Mean())
IN1OUT1_EXPRESSION(cal_max, max, inarg->sig.Max())
IN1OUT1_EXPRESSION(cal_min, min, inarg->sig.Min())
IN1OUT1_EXPRESSION(cal_tbegin, tbegin, inarg->sig.tmark)
IN1OUT1_EXPRESSION(cal_tend, tend, inarg->sig.CalculateTotalDuration())
IN1OUT1_EXPRESSION(cal_length, length, inarg->sig.nSamples())
//IN1OUT1_EXPRESSION(cal_rand, rand, (double)rand()/(double)RAND_MAX*inarg->sig.value())

int dcomp( const void * arg1, const void * arg2 );

class cal_dechain : public calbase
{
public:
	cal_dechain(void) {name = "dechain";}
	virtual ~cal_dechain(void)	{}
	CEqSig& calc(list<CEqSig *> arg)
	{
		char errStr[256];
		if (arg.size()!=1) {
			sprintf (errStr, "%s must have one argument.", name);
			throw errStr;
		} else {
			CEqSig  *inarg = arg.back();
			inarg->sig.MakeChainless();
			body.sig = inarg->sig;
		}
		return body;
	}
};

class cal_sort : public calbase
{
public:
	cal_sort(void) {name = "sort";}
	virtual ~cal_sort(void)	{}
	CEqSig& calc(list<CEqSig *> arg)
	{
		char errStr[256];
		if (arg.size()!=1) {
			sprintf (errStr, "%s must have one argument.", name);
			throw errStr;
		} else {
			CEqSig  *inarg = arg.back();
			qsort(inarg->sig.buf, inarg->sig.nSamples(), sizeof(inarg->sig.buf[0]), dcomp);
			body.sig = inarg->sig;
		}
		return body;
	}
};

//class cal_fix : public calbase
//{
//public:
//	cal_fix(void) {name = "fix";}
//	virtual ~cal_fix(void)	{}
//	CEqSig& calc(list<CEqSig *> arg)
//	{
//		char errStr[256];
//		if (arg.size()!=1) {
//			sprintf (errStr, "%s must have one argument.", name);
//			throw errStr;
//		} else {
//			CEqSig  *inarg = arg.back();
//			if (inarg->len()<2)
//				body.sig.SetValue(inarg->sig.value() >= 0 ? floor(inarg->sig.value()) : ceil(inarg->sig.value()));
//			else {
//				body.sig.UpdateBuffer(inarg->sig.nSamples());
//				for (int i=0; i<body.len(); i++)
//					body.sig.buf[i] = inarg->sig.buf[i] >= 0 ? floor(inarg->sig.buf[i]) : ceil(inarg->sig.buf[i]);
//				body.sig.tmark = inarg->sig.tmark;
//			}
//		}
//		return body;
//	}
//};
//
//class cal_sqrt : public calbase
//{
//public:
//	cal_sqrt(void) {name = "sqrt";}
//	virtual ~cal_sqrt(void)	{}
//	CEqSig& calc(list<CEqSig *> arg)
//	{
//		char errStr[256];
//		if (arg.size()!=1) {
//			sprintf (errStr, "%s must have one argument.", name);
//			throw errStr;
//		} else {
//			CEqSig  *inarg = arg.back();
//			if (inarg->len()<2)
//				body.sig.SetValue(sqrt(inarg->sig.value()));
//			else {
//				body.sig.UpdateBuffer(inarg->sig.nSamples());
//				for (int i=0; i<body.len(); i++)
//					body.sig.buf[i] = (inarg->sig.buf[i]>0) ? sqrt(inarg->sig.buf[i]) : 0;
//				body.sig.tmark = inarg->sig.tmark;
//			}
//		}
//		return body;
//	}
//};

class cal_colon : public calbase
{
public:
	cal_colon(void) {name = ":";}
	virtual ~cal_colon(void)	{}
	CEqSig& calc(list<CEqSig *> arg)
	{
		double args[3];
		int i, nItems;
		list<CEqSig *>::iterator it;
		calbase::calc(arg); // to reset
		for (i=0, it=arg.begin(); it!=arg.end() && i<3; it++, i++)
		{
			CEqSig *p = *it;
			if (!p->sig.IsScalar())
				throw "Operands of ':' must be scalas.";
			args[i] = p->sig.value();
		}
		if (i == 2)
			args[2] = (args[0]>args[1]) ? -1 : 1;
		if (args[2] == 0)
			throw "Interval of ':' cannot be zero.";
		nItems = max(1, (int)((args[1]-args[0])/args[2])+1);
		body.sig.UpdateBuffer(nItems);
		for (int i=0; i<nItems; i++)
			body.sig.buf[i] = args[0] + args[2]*i;
		return 	body;
	}
};

class cal_concat : public calbase
{
public:
	cal_concat(void) {name = " ";}
	virtual ~cal_concat(void)	{}
	CEqSig& calc(list<CEqSig *> arg)
	{
		list <CEqSig *>::iterator iter;
		calbase::calc(arg); // to reset
		for ( iter = arg.begin( ); iter != arg.end( ); iter++ )
		{
			CEqSig *p = *iter;
			body.sig += &p->sig;
		}
		return 	body;
	}
};

//class cal_plus : public calbase
//{ // + operation: argument 1 or less
//	// 0 argument: return as is
//	// 1 argument: add the argument to body.
//public:
//	cal_plus(void) {name = "+";}
//	virtual ~cal_plus(void)	{}
//	CEqSig& calc(list<CEqSig *> arg)
//	{
//		list <CEqSig *>::iterator iter;
//		calbase::calc(arg); // to reset
//		for ( iter = arg.begin( ); iter != arg.end( ); iter++ )
//		{
//			CEqSig *p = *iter;
//			body.sig += p->sig;
//		}
//		return 	body;
//	}
//};
//
//class cal_mult: public calbase
//{
//public:
//	cal_mult(void) {name = "*";}
//	virtual ~cal_mult(void)	{}
//	CEqSig& calc(list<CEqSig *> arg)
//	{
//		list <CEqSig *>::iterator iter;
//		body.sig.SetValue(1.); // to reset
//		for ( iter = arg.begin( ); iter != arg.end( ); iter++ )
//		{
//			CEqSig *p = *iter;
//			body.sig *= p->sig;
//		}
//		return 	body;
//	}
//};

//class cal_div: public calbase
//{
//public:
//	cal_div(void) {name = "/";}
//	virtual ~cal_div(void)	{}
//	CEqSig& calc(list<CEqSig *> arg)
//	{
//		if (arg.size()!=2)	throw "MUST HAVE TWO ARGUMENTS."; 
//		int nArgs(0); 
//		CEqSig args[2];
//		getArguments(arg, args, nArgs);
//		body.sig = args[0].sig;
//		body.sig /= args[1].sig;
//		return 	body;
//	}
//};
//
//class cal_mod: public calbase
//{
//public:
//	cal_mod(void) {name = "mod";}
//	virtual ~cal_mod(void)	{}
//	CEqSig& calc(list<CEqSig *> arg)
//	{
//		list <CEqSig *>::iterator arg1;
//		list <CEqSig *>::iterator arg2;
//		if (arg.size()!=2)	throw "MUST HAVE TWO ARGUMENTS."; 
//		arg1 = arg.begin();
//		arg2 = arg1++;
//
//		CEqSig *p1(*arg2), *p2(*arg1) ;
//		double x(p1->sig.value()), y(p2->sig.value());
//		body.sig.SetValue(x - (double)((int)(x/y) * y));
//		return 	body;
//	}
//};

//class cal_raiseby: public calbase
//{
//public:
//	cal_raiseby(void) {name = "^";}
//	virtual ~cal_raiseby(void)	{}
//	CEqSig& calc(list<CEqSig *> arg)
//	{
//		list <CEqSig *>::iterator arg1;
//		list <CEqSig *>::iterator arg2;
//		if (arg.size()!=2)	throw "MUST HAVE TWO ARGUMENTS."; 
//		arg1 = arg.begin();
//		arg2 = arg1++;
//
//		CEqSig *p1(*arg2), *p2(*arg1) ;
//		if (!p2->sig.IsScalar()) throw "Second operand must be a scalar."; 
//		if (p1->sig.IsScalar()) {
//			double v = pow(p1->sig.value(), p2->sig.value());
//			body.sig.SetValue(_isnan(v) ? 0 : v);
//		} else {
//			body.sig.UpdateBuffer(p1->sig.nSamples());
//			for (int i=0; i<body.len(); i++) {
//				double v = pow(p1->sig.buf[i], p2->sig.value());
//				body.sig.buf[i] = _isnan(v) ? 0 : v;
//			}
//		}
//		return 	body;
//	}
//};

//class cal_tone: public calbase //revised in Dec09---noted for JHPARK
//{
//public:
//	cal_tone(void) {name = "tone";}
//	virtual ~cal_tone(void)	{}
//	CEqSig& calc(list<CEqSig *> arg)
//	{
//		char errStr[256];
//		double freqs[2];
//		CSignals xout(body.sig.GetFs()); 
//		body.sig.Reset(body.sig.GetFs()); 
//		int nArgs(0);
//		list <CEqSig *>::iterator iter;
//		CEqSig args[10], tempEq, tempEq2;
// 		for ( iter = arg.begin( ); iter != arg.end( ); iter++ )
//		{
//			CEqSig *p = *iter;
//			args[nArgs++] = (CEqSig&)*p;
//		}
//		if ( nArgs>3 || nArgs<2 ) 
//		{
//			strcpy(errStr, "tone(freq, duration or [begin duration]), initial_phase_between_0_and_1)\n");
//			throw errStr;
//		}
//		if (args[0].len()>2) throw "FREQUENCY MUST BE SCALAR or a two-element vector for a tone glide."; 
//		if (args[2].len()>1) throw "Initial_phase MUST BE SCALAR."; 
//		double initphase(0.), tmark[2];
//		getTimeMarks(args[1], name, 2, tmark);
//		if (tmark[1]<0.) throw "invalid time marker(negative duration)";
//		if (nArgs==3) initphase = args[2].sig.value();
//		xout.Silence(tmark[0]); 
//		if (args[0].len()==2)
//		{
//			memcpy((void*)freqs, (void*)args[0].sig.buf, sizeof(double)*2);
//			body.sig.Tone(freqs, tmark[1], initphase);
//		}
//		else
//			body.sig.Tone(args[0].sig.value(), tmark[1], initphase);
//		body.sig.Insert(xout,0);
//		return 	body;
//	}
//};

class cal_fm: public calbase
{
public:
	cal_fm(void) {name = "fm";}
	virtual ~cal_fm(void)	{}
	CEqSig& calc(list<CEqSig *> arg);
};

//class cal_am: public calbase
//{
//public:
//	cal_am(void) {name = "am";}
//	virtual ~cal_am(void)	{}
//	CEqSig& calc(list<CEqSig *> arg);
//};

class cal_db: public calbase
{
public:
	cal_db(void) {name = "db";}
	virtual ~cal_db(void)	{}
	CEqSig& calc(list<CEqSig *> arg);
};

class cal_wave: public calbase
{
public:
	cal_wave(void) {name = "wave";}
	virtual ~cal_wave(void)	{}
	CEqSig& calc(list<CEqSig *> arg);
};

class cal_ramp: public calbase
{
public:
	cal_ramp(void) {name = "ramp";}
	virtual ~cal_ramp(void)	{}
	CEqSig& calc(list<CEqSig *> arg)
	{
		if (arg.size()!=2)	throw "ramp MUST HAVE TWO ARGUMENTS."; 
		int nArgs(0); 
		CEqSig args[2];
		getArguments(arg, args, nArgs);
		body.sig.Reset(body.sig.GetFs()); 
		if (args[1].sig.nSamples()>1) throw "SECOND PARAMATER MUST BE SCALAR (ramping time in ms)."; 
		if (args[0].sig.nSamples()<=1) throw "FIRST PARAMATER MUST BE A SIGNAL TO RAMP."; 
		body.sig = args[0].sig;
		body.sig.Dramp(args[1].sig.value(), args[0].GetNonZeroPt());
		return 	body;
	}
};

class cal_shift: public calbase
{
public:
	cal_shift(void) {n_names=3; names = new string[3]; names[0]="shift"; names[1]=">>"; names[2]="<<";}
	virtual ~cal_shift(void)	{}
	CEqSig& calc(list<CEqSig *> arg)
	{
		if (arg.size()!=2)	throw "shift MUST HAVE TWO ARGUMENTS."; 
		int nArgs(0); 
		CEqSig args[10];
		getArguments(arg, args, nArgs);
		body.sig.Reset(body.sig.GetFs()); 
		if (args[1].sig.nSamples()>1) throw "SECOND PARAMATER MUST BE SCALAR (shifting time in ms)."; 
		if (args[0].sig.nSamples()<=1) throw "FIRST PARAMATER MUST BE A SIGNAL TO SHIFT."; 
		body.sig = args[0].sig;
		body.sig>>=(args[1].sig.value() * (name == "<<" ? -1 : 1));
		return 	body;
	}
};


class cal_iir: public calbase
{
public:
	cal_iir(void) {n_names=4; 	names = new string[4]; 	names[0] = "lpf";	names[1] = "bpf";	names[2] = "hpf";	names[3] = "bsf";}
	virtual ~cal_iir(void)	{}
	CEqSig& calc(list<CEqSig *> arg);
};
/*
class cal_rms: public calbase
{
public:
	cal_rms(void) {name = "rms";}
	virtual ~cal_rms(void)	{}
	CEqSig& calc(list<CEqSig *> arg);
};
*/
class cal_tparamonly : public calbase
{
public:
	cal_tparamonly(void) {n_names=4; 	names = new string[n_names]; 	names[0] = "noise";	names[1] = "gnoise";	names[2] = "silence"; names[3] = "dc"; }
	virtual ~cal_tparamonly(void)	{}
	CEqSig& calc(list<CEqSig *> arg);
};

//class cal_irand: public cal_rand
//{
//public:
//	cal_irand(void) {name = "irand";}
//	virtual ~cal_irand(void)	{}
//	virtual CEqSig& calc(list<CEqSig *> arg);
//};

//class cal_randperm: public cal_irand
//{
//public:
//	cal_randperm(void) {name = "randperm";}
//	virtual ~cal_randperm(void)	{}
//	CEqSig& calc(list<CEqSig *> arg);
//};

#ifdef _WINDOWS
class cal_readtxt: public calbase
{
public:
	cal_readtxt(void) {name = "file";}
	virtual ~cal_readtxt(void)	{}
	CEqSig& calc(list<CEqSig *> arg);
};
#endif
/*
class cal_filt: public calbase
{
public:
	cal_filt(void) {name = "filt";}
	virtual ~cal_filt(void)	{}
	CEqSig& calc(list<CEqSig *> arg);
};

class cal_cisim : public calbase
{
public:
	cal_cisim(void) {name = "cisim";}
	virtual ~cal_cisim(void)	{}
	CEqSig& calc(list<CEqSig *> arg);
};
*/
//class cal_round : public calbase
//{
//public:
//	cal_round(void) {name = "round";}
//	virtual ~cal_round(void)	{}
//	CEqSig& calc(list<CEqSig *> arg)
//	{
//		int nArgs(0); 
//		CEqSig args[2];
//		if (arg.size()>2) throw "Too many arguments.";
//		getArguments(arg, args, nArgs);
//		if (nArgs!=1)	throw "round MUST HAVE ONE ARGUMENT."; 
//		if (args[0].sig.nSamples>0)
//		{
//			body.sig.UpdateBuffer(args[0].sig.nSamples); 
//			for (int i=0; i<body.sig.nSamples(); i++) 
//				body.sig.buf[i] = (double)round(args[0].sig.buf[i]);
//		}
//		else
//			body.sig.SetValue((double)round(args[0].sig.value()));
//		return 	body;
//	}
//};

class cal_int2str : public calbase
{
public:
	cal_int2str(void) {name = "int2str";}
	virtual ~cal_int2str(void)	{}
	CEqSig& calc(list<CEqSig *> arg);
};
/*
class cal_caret: public calbase // Revised in Dec09---noted for JHPARK
{
public:
	cal_caret(void) {name = "caret";}
	virtual ~cal_caret(void)	{}
	CEqSig& calc(list<CEqSig *> arg);
};

class cal_stereo: public calbase
{
public:
	cal_stereo(void) {name = "stereo";}
	virtual ~cal_stereo(void)	{}
	CEqSig& calc(list<CEqSig *> arg)
	{
		const int maxArgs = 2;
		int nArgs(0);
		CEqSig args[maxArgs];
		list <CEqSig *>::iterator iter;
 		for ( iter = arg.begin( ); iter != arg.end( ) && nArgs < maxArgs; iter++ )
		{
			if (nArgs==maxArgs) throw "stereo must have two parameters.";
			CEqSig *p = *iter;
			args[nArgs++] = (CEqSig&)*p;
		}
		if ( nArgs!=2 ) 
			throw "stereo(left_signal, right_signal)\n";
		if (body.sig.GetFs() != args[0].sig.GetFs() || body.sig.GetFs() != args[1].sig.GetFs())
			throw "FREQUENCY MUST BE THE SAME.";
		if (args[0].sig.nSamples() != args[1].sig.nSamples())
		{
			CSignals filler(body.sig.GetFs());
			filler.Silence(abs(args[0].sig.nSamples() - args[1].sig.nSamples()));
			(args[0].sig.nSamples() < args[1].sig.nSamples()) ? args[0].sig :	args[1].sig += &filler;
		}

		body.sig.Reset(body.sig.GetFs()); 
		body.sig = args[0].sig;
		body.sig.SetNextChan(&args[1].sig);
		return 	body;
	}
};
*/