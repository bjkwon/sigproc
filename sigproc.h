#pragma once

#ifndef SIGPROC
#define SIGPROC


#define PI	3.141592
#define LOG10DIV20 0.1151292546497
#define round(x)	((int)((x)+((x)<0?-.5:.5)))

//If this library is linked statically define LINK_STATIC_SIGPROC in the application project.
#ifndef LINK_STATIC_SIGPROC
#ifdef SIGPROC_INTERNAL
#define EXP_CS __declspec (dllexport)
#else
#define EXP_CS __declspec (dllimport)
#endif // SIGPROC_INTERNAL
#else
#define EXP_CS
#endif

#define CSIG_TYPEERROR	0
#define CSIG_STRING		1
#define CSIG_EMPTY		2
#define CSIG_NULL		3
#define CSIG_SCALAR		4
#define CSIG_AUDIO		5
#define CSIG_VECTOR		6
#define CSIG_CELL		7
#define CSIG_COMPLEX	8



#ifdef _WINDOWS
#ifndef _MFC_VER // If MFC is used.
#include <windows.h>
#else 
#include "afxwin.h"
#endif 
#endif 

#include <string>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <set>
#include <complex>

#ifndef PSYCONYACC
#include "psycon.yacc.h"
#endif

using namespace std;

class datachunk
{
public:
	int nSamples;
	union 
	{
		double *buf;
		char *strbuf;
		complex<double> *cbuf;
	};
	unsigned char bufBlockSize;
	datachunk();
	datachunk(const datachunk& src);
	datachunk(double value);
	datachunk(complex<double> value);
	datachunk(double *y, int  len);

	datachunk& operator=(const datachunk& rhs);
	virtual ~datachunk();
	EXP_CS datachunk& UpdateBuffer(int  length);
	EXP_CS void Reset() {nSamples = 0;}
	EXP_CS double value(void) const {if (nSamples==1) return buf[0]; else if (nSamples==0) throw "value( ) on null."; else throw "value( ) on vector.";}
	void SetValue(double v) {delete[] buf; buf = new double[1]; nSamples=1; buf[0]=v; }
	void SetValue(complex<double> v) {delete[] buf; buf = new double[2]; bufBlockSize=2; nSamples=1; cbuf[0]=v; }
	EXP_CS void SetComplex();
	EXP_CS void SetReal();
	EXP_CS bool IsComplex() const  { return (bufBlockSize==2); } 
	EXP_CS void SwapContents1node(datachunk &sec);

	EXP_CS datachunk &addmult(char type, datachunk &arg);

	datachunk &each(double (*fn)(double));
	datachunk &each(double (*fn)(complex<double>));
	datachunk &each(complex<double> (*fn)(complex<double>));
	datachunk &each(double (*fn)(double, double), datachunk &arg2); 
	datachunk &each(complex<double> (*fn)(complex<double>, complex<double>), datachunk &arg2);

	datachunk &transpose1();

	EXP_CS datachunk& OPERATE(datachunk &rhs, int type);

	//EXP_CS datachunk& operator<(datachunk &sec) {	return OPERATE(sec, '<'); }
	//EXP_CS datachunk& operator>(datachunk &sec) {	return OPERATE(sec, '>'); }
	//EXP_CS datachunk& operator<=(datachunk &sec) {	return OPERATE(sec, "<="); }
	//EXP_CS datachunk& operator>=(datachunk &sec) {	return OPERATE(sec, ">="); }
	//EXP_CS datachunk& operator||(datachunk &sec) {	return OPERATE(sec, "||"); }
	//EXP_CS datachunk& operator&&(datachunk &sec) {	return OPERATE(sec, "&&"); }
//	EXP_CS datachunk& operator!() {	datachunk dummy(0); return OPERATE(dummy, "!"); }

	EXP_CS double Sum();
	EXP_CS double Min(int  &id);
	EXP_CS double Min() {int id; return Min(id);}
	EXP_CS double Max(int  &id);
	EXP_CS double Max() {int id; return Max(id);}
	EXP_CS double Mean() {return Sum()/(double)nSamples;}
	EXP_CS datachunk &Min(double crit);
	EXP_CS datachunk &Max(double crit);
};

class CSignal : public datachunk
{
public:
	double tmark;
	CSignal *chain;

	// Signal generation (no stereo handling)
	EXP_CS double * fm(double midFreq, double fmWidth, double fmRate, int  nsamples, double beginFMPhase=0.);
	EXP_CS double * fm(double midFreq, double fmWidth, double fmRate, double dur_ms, double beginFMPhase=0.);
	EXP_CS double * fm2(CSignal flutter, int  multiplier, char *errstr);
	EXP_CS double * Silence(int  nsamples);
	EXP_CS double * Silence(double dur_ms);
	EXP_CS double * DC(double dur_ms);
	EXP_CS double * DC(int  nsamples);
	EXP_CS double * Tone(vector<double> freqs, int  nsamples);
	EXP_CS double * Tone(vector<double> freqs, double dur_ms);
	EXP_CS double * Tone(double freq, int  nsamples, double beginPhase=0.);
	EXP_CS double * Tone(double freq, double dur_ms, double beginPhase=0.);
	EXP_CS double * Noise(double dur_ms);
	EXP_CS double * Noise(int  nsamples);
	EXP_CS double * Noise2(double dur_ms);
	EXP_CS double * Noise2(int  nsamples);
	EXP_CS double * Truncate(double time_ms1, double time_ms2);
	EXP_CS double * Truncate(int  id1, int  id2, int  code=0);

	// Window functions
	//EXP_CS double * Hann(int  len);	// Use Blackman with alpha=0
	EXP_CS double * Hamming(int  len);
	EXP_CS double * Blackman(int  len, double alp=0.16);

	// Signal alteration (stereo handling with a clean, inarguable convention)
#ifndef NO_IIR
	EXP_CS int IIR(int  kind, int  type, int  order, double *freqs, double passRipple_dB, double stopFreqORAttenDB, char *errstr);
#endif // NO_IIR
	int filtfilt(const CSignal& num, const CSignal& den, char *errstr);
	virtual void filtfilt(int  nTabs, double *num, double *den);
	void filtfilt(int  nTabs, double *num);
	void Filter(int  nTabs, double *num);
	virtual void Filter(int  nTabs, double *num, double *den);
	int Filter(const CSignal& num, const CSignal& den, char *errstr);
#ifndef NO_FFTW
	virtual double * Hilbert(int  len);
	virtual double * HilbertEnv(int  len);
	virtual double * ShiftFreq(double shift);
	virtual double * TCTS(double freq, double ratio);
#endif
	virtual void DownSample(int  q);
	virtual void UpSample(int  p);
	virtual CSignal& Reset(int  fs2set=0);
#ifndef NO_RESAMPLE
	virtual double * Resample(int  newfs, char *errstr);
	virtual double * Resample(vector<int> newfs, vector<int> lengths, char *errstr);
#endif //NO_RESAMPLE
	virtual void Dramp(double dur_ms, int  beginID=0);
	EXP_CS void ReverseTime();
	EXP_CS CSignal& Interp(const CSignal& gains, const CSignal& tmarks);
	EXP_CS CSignal& operator=(const CSignal& rhs);
	EXP_CS CSignal& operator*=(const double con);
	EXP_CS CSignal& operator*=(CSignal &scaleArray);
	EXP_CS CSignal& operator+=(CSignal &sec);
	EXP_CS CSignal& operator+=(const double con);
	EXP_CS CSignal& operator-(void);	// Unary minus
	EXP_CS CSignal& operator-=(CSignal &sec);
	EXP_CS CSignal& Reciprocal(void);	// Multiplicative inverse
	EXP_CS CSignal& operator/=(CSignal &scaleArray);
	EXP_CS CSignal& operator/=(double scaleFactor);

	virtual CSignal& operator>>=(const double delta);
	EXP_CS CSignal& operator<<=(const double delta);

	//EXP_CS CSignal& operator<(const CSignal &sec);
	//EXP_CS CSignal& operator>(const CSignal &sec);
	//EXP_CS CSignal& operator<=(const CSignal &sec);
	//EXP_CS CSignal& operator>=(const CSignal &sec);
	//bool operator==(const CSignal &sec) const;
	//bool operator!=(const CSignal &sec) const {return !(*this == sec);}
	//EXP_CS CSignal& operator!();
	//EXP_CS CSignal& operator&&(const CSignal &sec);
	//EXP_CS CSignal& operator||(const CSignal &sec);

	EXP_CS void SwapContents1node(CSignal &sec);
	// Signal alteration (stereo handling with an established convention)
	virtual const CSignal& operator+=(CSignal *yy); // Concatenation

	// Signal extraction (stereo handling with a clean, inarguable convention)
	EXP_CS CSignal& Take(CSignal& out, int  id1);
	EXP_CS CSignal& Take(CSignal& out, double begin_ms);
	EXP_CS CSignal& Take(CSignal& out, int  id1, int  id2);
	EXP_CS CSignal& Take(CSignal& out, double begin_ms, double end_ms);

	virtual CSignal& Trim(double begin_ms, double end_ms);
	virtual CSignal& timeshift(double tp_ms);
	virtual CSignal& removeafter(double timems);


	EXP_CS int WriteAXL(FILE* fp);

	// Retrieve signal characteristics (single channel ONLY)
	EXP_CS int GetType() const; 
	vector<double> Sum();
	vector<double> Mean();
	vector<int> MinId();
	vector<double> Min();
	CSignal& Min(double crit);
	vector<int> MaxId();
	vector<double> Max();
	CSignal& Max(double crit);
	EXP_CS double RMS();
	EXP_CS int GetFs() const {return fs; };
	EXP_CS int length() const {if (GetType() == CSIG_STRING) return (int)strlen(strbuf); else return nSamples;};
	EXP_CS void SetFs(int  newfs) {fs = newfs; };
	EXP_CS double* GetBuffer() {return buf;}
	EXP_CS double dur() {return (double)nSamples/fs*1000.;}// duration in miliseconds
	EXP_CS double endt() {return tmark + dur();}// end time poEXP_CS int in miliseconds
	EXP_CS bool IsScalar() const {return (GetType() == CSIG_SCALAR);}
	EXP_CS bool IsEmpty() const {return (GetType() == CSIG_EMPTY);}
	EXP_CS bool IsSingle() const {return ( (GetType() == CSIG_SCALAR || GetType() == CSIG_COMPLEX || GetType() == CSIG_STRING) && nSamples==1);}
	EXP_CS bool IsString() const {return (fs == 2);}
	EXP_CS bool IsComplex() const  { return (bufBlockSize==2); } 
	EXP_CS int IsNull(double timept);
	EXP_CS CSignal& Insert(double timept, CSignal &newchunk);
	EXP_CS CSignal& Replace(CSignal &newsig, double t1, double t2);

	CSignal(); // default construct
	CSignal(int  sampleRate); // construct with a specified sample rate.
	CSignal(double value); // construct a scala with the specified value
	CSignal(const CSignal& src); // copy constructor
	CSignal(double *y, int  len);
	CSignal(FILE* fp);
	CSignal(string str); // make a string CSignal

	virtual ~CSignal();	// standard destructor

	EXP_CS void SetChain(CSignal *unit, double time_shifted=0.);
	EXP_CS void SetChain(double time_shifted);
	EXP_CS void AddChain(CSignal &sec);
	CSignal * GetDeepestChain();
	CSignal * ExtractDeepestChain(CSignal *deepchain);
	EXP_CS int CountChains();
	EXP_CS void AddMultChain(char type, CSignal *forthis);
	CSignal * BreakChain(CSignal *chainedout);
	EXP_CS double alldur();
	virtual double MakeChainless();
	EXP_CS CSignal& MakeChains(std::vector<double> tmarks);
	EXP_CS CSignal& MC(CSignal &out, std::vector<double> tmarks, int  id1, int  id2);
	EXP_CS CSignal& MergeChains();
	EXP_CS CSignal& ConnectChains();
	EXP_CS string string();
	EXP_CS char *getString(char *str, const int size);
	EXP_CS CSignal &SetString(const char *str);
	EXP_CS CSignal &SetString(const char c);

	CSignal &each(double (*fn)(double));
	CSignal &each(double (*fn)(complex<double>));
	CSignal &each(double (*fn)(double, double), datachunk &arg2);
	CSignal &each(complex<double> (*fn)(complex<double>));
	CSignal &each(complex<double> (*fn)(complex<double>, complex<double>), datachunk &arg2);
	CSignal &transpose1();

protected:
	int fs;
};



class CSignals : public CSignal
{
public:
	CSignal *next;
	vector<CSignal> cell;

	EXP_CS CSignals();
	EXP_CS CSignals(int  sampleRate);
	EXP_CS CSignals(FILE* fp);
	EXP_CS CSignals(double value);
	EXP_CS CSignals(double *y, int  len);
	EXP_CS CSignals(const CSignal& src);
	EXP_CS CSignals(const CSignals& src);
	EXP_CS ~CSignals();
	EXP_CS CSignals& operator=(const CSignals& rhs);
	EXP_CS CSignals& operator+=(const double con);
	EXP_CS CSignals& operator+=(CSignal &sec);
	EXP_CS CSignals& operator+=(CSignals &sec);
	EXP_CS const CSignals& operator+=(CSignals *yy);
	EXP_CS const CSignals& operator+=(CSignal *yy);
	EXP_CS CSignals& operator*=(CSignals &sec);
	EXP_CS CSignals& operator*=(const double con);
	EXP_CS CSignals& operator*=(CSignal &sec);
	EXP_CS int IsStereo() { return 0 + (next!=NULL); }

	EXP_CS double MakeChainless();

	//EXP_CS CSignals& OPERATE(const CSignals &sec, std::string op);

	//EXP_CS CSignals& operator<(const CSignals &sec) {	return OPERATE(sec, "<"); }
	//EXP_CS CSignals& operator<(const CSignal &sec)  {	return OPERATE(CSignals(sec), "<"); }
	//EXP_CS CSignals& operator>(const CSignals &sec) {	return OPERATE(sec, ">"); }
	//EXP_CS CSignals& operator>(const CSignal &sec)  {	return OPERATE(CSignals(sec), ">"); }
	//EXP_CS CSignals& operator<=(const CSignals &sec) {	return OPERATE(sec, "<="); }
	//EXP_CS CSignals& operator<=(const CSignal &sec) {	return OPERATE(CSignals(sec), "<="); }
	//EXP_CS CSignals& operator>=(const CSignals &sec) {	return OPERATE(sec, ">="); }
	//EXP_CS CSignals& operator>=(const CSignal &sec) {	return OPERATE(CSignals(sec), ">="); }
	//EXP_CS CSignals& operator||(const CSignals &sec) {	return OPERATE(sec, "||"); }
	//EXP_CS CSignals& operator||(const CSignal &sec) {	return OPERATE(CSignals(sec), "||"); }
	//EXP_CS CSignals& operator&&(const CSignals &sec) {	return OPERATE(sec, "&&"); }
	//EXP_CS CSignals& operator&&(const CSignal &sec) {	return OPERATE(CSignals(sec), "&&"); }
	//EXP_CS CSignals& operator!() {	CSignals dummy(0); return OPERATE(dummy, "!"); }

	//EXP_CS bool operator==(const CSignals &sec) const;
	//EXP_CS bool operator!=(const CSignals &sec) const {return !(*this == sec);}

	EXP_CS int ReadAXL(FILE* fp);
	EXP_CS int WriteAXL(FILE* fp);

	EXP_CS int GetType() const;

	EXP_CS void SetValue(double v);
	EXP_CS void SetNextChan(CSignal *second);
	EXP_CS double value() const;
	EXP_CS CSignal *DetachNextChan() {CSignal *p=next;next=NULL;return p;}
	EXP_CS CSignals& Reset(int  fs2set=0);
	EXP_CS CSignals& Reciprocal(void);
	EXP_CS CSignals& operator-(void);
	EXP_CS CSignals& operator>>=(const double delta);
	EXP_CS CSignals& Take(CSignals& out, int  id1, int  id2);
	EXP_CS CSignals& Trim(double begin_ms, double end_ms);
//	EXP_CS CSignals& timeshift(double tp_ms);
	EXP_CS void Dramp(double dur_ms, int  beginID=0);
	EXP_CS double * Modulate (double *env, int  lenEnv);
	EXP_CS CSignals& Insert(double timept, CSignals &newchunk);
	EXP_CS CSignals& Replace(CSignals &newsig, double t1, double t2);

	EXP_CS double * Mag();
	EXP_CS CSignal Angle();
#ifndef NO_RESAMPLE
	EXP_CS double * Resample(int  newfs, char *errstr);
	EXP_CS double * Resample(vector<int> newfs, vector<int> lengths, char *errstr);
	EXP_CS double * fm2(CSignal flutter, int  multiplier, char *errstr);
#endif // NO_RESAMPLE
	EXP_CS void DownSample(int  q);
	EXP_CS void UpSample(int  p);
	EXP_CS void Filter(int  nTabs, double *num, double *den);
	EXP_CS void filtfilt(int  nTabs, double *num, double *den);
#ifndef NO_FFTW
	EXP_CS double * FFT(int  len);
	EXP_CS double * iFFT(void);
	EXP_CS double * Hilbert(int  len);
	EXP_CS double * HilbertEnv(int  len);
	EXP_CS double * ShiftFreq(double shift);
	EXP_CS double * TCTS(double freq, double ratio);
#endif
	EXP_CS CSignals &each(double (*fn)(double));
	EXP_CS CSignals &each(double (*fn)(complex<double>));
	EXP_CS CSignals &each(double (*fn)(double, double), datachunk &arg2);
	EXP_CS CSignals &each(complex<double> (*fn)(complex<double>));
	EXP_CS CSignals &each(complex<double> (*fn)(complex<double>, complex<double>), datachunk &arg2);
	CSignals &transpose1() {CSignal::transpose1(); if (next) next->transpose1(); return *this;}

#ifdef _WINDOWS
#ifndef NO_PLAYSND
	// Sound Playback functions
	EXP_CS int PlayArray(int DevID, UINT userDefinedMsgID, HWND hApplWnd, double *block_dur_ms, char *errstr, int  loop=0); // playing with event notification by specified time block
	EXP_CS int PlayArray(int DevID, UINT userDefinedMsgID, HWND hApplWnd, int  nProgReport, char *errstr, int  loop=0); // full format
	EXP_CS int PlayArrayNext(int DevID, UINT userDefinedMsgID, HWND hApplWnd, double *block_dur_ms, char *errstr);
	EXP_CS int PlayArrayNext(int DevID, UINT userDefinedMsgID, HWND hApplWnd, int  nProgReport, char *errstr); // full format
	EXP_CS int PlayArray(int DevID, char *errstr); // (blocking play)
	EXP_CS int PlayArray(char *errstr); //assuming the first device
#endif // NO_PLAYSND

#ifndef NO_SF
	EXP_CS CSignals(const char* wavname);
	EXP_CS int Wavwrite(const char *wavname, char *errstr, std::string wavformat="");
	EXP_CS int Wavread(const char *wavname, char *errstr);
#endif // NO_SF
#endif //_WINDOWS
private:
	short * makebuffer(int  &nChan);
};

class CAstException {
public:
	const AstNode *pnode;
	string str1, str2, outstr;
	int int1;

	EXP_CS CAstException(const AstNode *p, const string s1, const string s2="");
	EXP_CS CAstException(const AstNode *p, const string s1, const int x, const string s2="");
	EXP_CS CAstException(const AstNode *p0, const AstNode *p, const char** FuncSigs, const string msg);
	EXP_CS CAstException(const AstNode *p0, const char* msg);
	string getErrMsg() const {return outstr;};
private:
	EXP_CS void makeOutStr() {makeOutStr(pnode);}
	EXP_CS void makeOutStr(const AstNode *p);
};

class CAstSig;

class CAstSigEnv
{
	friend class CAstSig;
public:
	CAstSigEnv(const int fs = 1);
	~CAstSigEnv();
	map<string,CSignals> Tags;
	map<string,AstNode *> UDFs;
	map<string,map<int,CSignals>> Arrays;  //soon to be deleted 4/23
	int Fs;
	string AuxPath;
private:
	map<string,CSignals *> Refs; // used to store output arguments inside UDF
	map<string,map<int,CSignals> *> ArrRefs; // where are these used??
	set<string> NoAuxFiles; // where are these used??
	int RefCount; // where are these used??
};

class CAstSig
{
private:
	static const int DefaultFs = 22050;
	AstNode *pAst;
	AstNode *pAst_context;
	string Script;
	bool fAllocatedAst, fExit, fBreak, fContinue;

	EXP_CS void initGlobals(const CAstSig *env);
	EXP_CS void HandleAuxFunctions(const AstNode *pnode);
	CSignals &CallSub(const AstNode *pUDF, const AstNode *pCall);
	map<int,CSignals> *RetrieveArray(const char *arrayname);
	AstNode *RetrieveUDF(const char *fname);
public:
	CSignals Sig;
	string statusMsg;
	CAstSigEnv *pEnv;
	unsigned long Tick0, Tick1;
	void (*CallbackCIPulse)(const AstNode *, CAstSig *);
	int (*CallbackHook)(CAstSig &ast, const AstNode *pnode, const AstNode *p);
	EXP_CS CSignals *RetrieveTag(const char *tagname);

    EXP_CS CAstSig(const CAstSig &org);
	EXP_CS CAstSig(const CAstSig *env);
	EXP_CS CAstSig(const char *str, const CAstSig *env);
	EXP_CS CAstSig(AstNode *pNode, const CAstSig *env);
	EXP_CS CAstSig(const int fs = DefaultFs);
	EXP_CS CAstSig(const char *str, const int fs = DefaultFs);
	EXP_CS CAstSig(AstNode *pNode, const int fs = DefaultFs);
	EXP_CS ~CAstSig();

	EXP_CS CAstSig &SetNewScript(const char *str, AstNode *pAstOut = NULL);
	EXP_CS CAstSig &SetNewFile(FILE *source);
	EXP_CS CSignals &Compute(void);
	EXP_CS CSignals &Compute(const AstNode *pnode);
	EXP_CS CSignals &Eval(AstNode *pnode);
	EXP_CS CAstSig &Reset(const int fs = 0, const char* path=NULL);
	EXP_CS CAstSig &SetTag(const char *name, const CSignals &sig);
	EXP_CS CSignals &GetTag(const char *name);
	EXP_CS CAstSig &AddCell(const char *name, const CSignals &sig);
	EXP_CS CAstSig &SetCell(const char *name, const unsigned int i, const CSignals &sig);
	EXP_CS void SetRef(const char *ref, const char *var);
	EXP_CS CAstSig &SetPath(const char *path);
	EXP_CS CAstSig &AddPath(const char *path);
	EXP_CS const char *GetPath() {return pEnv->AuxPath.c_str();}
	EXP_CS AstNode *GetAst(void) {return pAst;}
	EXP_CS int GetFs(void) {return pEnv->Fs;}
	EXP_CS static bool IsCondition(const AstNode *pnode);
	EXP_CS string ComputeString(const AstNode *p);
	EXP_CS string GetScript() {return Script;}
	EXP_CS void interrupt(void);
	EXP_CS bool isInterrupted(void);

	EXP_CS string MakeFilename(string fname, const string ext);
	EXP_CS FILE *OpenFileInPath(string &fname, const string ext);
};


#ifdef _WINDOWS
//Global functions

EXP_CS void LoopPlay(int  onoff);
EXP_CS void TerminatePlay();
EXP_CS void PauseResumePlay(void *pWavePlay, bool fOnOff);
EXP_CS void TerminateLoop(void *pWavePlay);
EXP_CS void SetHWND_SIGPROC(HWND hAppl);
EXP_CS HWND GetHWND_SIGPROC();
EXP_CS DWORD WinMMGetVolume();
EXP_CS int WinMMSetVolume(DWORD vol);

#endif // _WINDOWS
EXP_CS void checkNumArgs(const AstNode *pnode, const AstNode *p, const char** FuncSigs, const int minArgs, const int maxArgs);

#endif // SIGPROC