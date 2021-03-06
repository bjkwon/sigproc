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

#define CSIG_EMPTY		0
#define CSIG_STRING		1
#define CSIG_NULL		2
#define CSIG_SCALAR		4
#define CSIG_CELL		8
#define CSIG_VECTOR		17
#define CSIG_COMPLEX	19 // let's not use GetType for this.... use IsComplex
#define CSIG_AUDIO		65

// Used for communication bet sigproc and xcom (i.e., AstSig.cpp and showvar.cpp)
#define WM__DEBUG		WM_APP+4000 
#define ID_DEFAULT	99
#define ID_DEBUG_STEP 108
#define ID_DEBUG_STEPIN 109
#define ID_DEBUG_CONTINUE 110
#define ID_DEBUG_EXIT 111
#define ID_DEBUG 112

enum DEBUG_STATUS
{
    null=-1,
    entering,
    progress,
	stepping,
	stepping_in,
	continuing,
    exiting,
    cleanup,
	aborting,
};

//End of Used for communication bet sigproc and xcom (i.e., AstSig.cpp and showvar.cpp)

#ifdef _WINDOWS
#ifndef _MFC_VER // If MFC is NOT used.
#include <windows.h>

#ifndef NO_PLAYSND
#include "wavplay.h"
#endif // NO_PLAYSND

#else 
#include "afxwin.h"
#endif 
#endif 

#include <string>
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>
#include <complex>

#ifndef PSYCONYACC
#include "psycon.yacc.h"
#endif

using namespace std;

class body
{
public:
	int nSamples;
	union 
	{
		complex<double> *cbuf;
		char *strbuf;
		double *buf;
		bool *logbuf;
	};
	unsigned char bufBlockSize;

	body();
	body(const body& src);
	body(double value);
	body(complex<double> value);
	body(double *y, int  len);
	body(bool *y, int len);
	virtual ~body();

	body& operator=(const body& rhs);
	body& operator+=(const double con);
	body& operator*=(const double con);
	body& operator-(void);	// Unary minus

	EXP_CS body& UpdateBuffer(int  length);
	EXP_CS void Reset();

	EXP_CS double value() const;
	EXP_CS complex<double> cvalue() const;
	void SetValue(double v);
	void SetValue(complex<double> v);
	bool isstring();
	EXP_CS void SetComplex();
	EXP_CS void SetReal();
	EXP_CS bool IsComplex() const  { return (bufBlockSize==2*sizeof(double)); } 
	EXP_CS void SwapContents1node(body &sec);

	EXP_CS body &addmult(char type, body &arg);

	body &each(double (*fn)(double));
	body &each(double (*fn)(complex<double>));
	body &each(complex<double> (*fn)(complex<double>));
	body &each(double (*fn)(double, double), body &arg2); 
	body &each(complex<double> (*fn)(complex<double>, complex<double>), body &arg2);

	body &transpose1();
	EXP_CS body& MakeLogical();
	EXP_CS body& LogOp(body &rhs, int type);
	body &insert(body &sec, int id);
	body &replace(body &sec, int id1, int id2);
	body &replace(body &sec, body &index);

	EXP_CS double Sum();
	EXP_CS double Min(int  &id, int len=-1);
	EXP_CS double Min() {int id; return Min(id);}
	EXP_CS double Max(int  &id, int len=-1);
	EXP_CS double Max() {int id; return Max(id);}
	EXP_CS double Mean() {return Sum()/(double)nSamples;}
	EXP_CS double Stdev(int flag=0);
	EXP_CS body &Min(double crit);
	EXP_CS body &Max(double crit);
};

class CSignal : public body
{
public:
	double tmark;
	CSignal *chain;

	// Signal generation (no stereo handling)
	EXP_CS double * fm(double midFreq, double fmWidth, double fmRate, int  nsamples, double beginFMPhase=0.);
	EXP_CS double * fm(double midFreq, double fmWidth, double fmRate, double dur_ms, double beginFMPhase=0.);
	EXP_CS double * fm2(CSignal flutter, int  multiplier, char *errstr);
	EXP_CS double * Silence(int nsamples);
	EXP_CS double * Silence(double dur_ms);
	EXP_CS double * DC(double dur_ms);
	EXP_CS double * DC(int nsamples);
	EXP_CS double * Tone(vector<double> freqs, int  nsamples);
	EXP_CS double * Tone(vector<double> freqs, double dur_ms);
	EXP_CS double * Tone(double freq, int  nsamples, double beginPhase=0.);
	EXP_CS double * Tone(double freq, double dur_ms, double beginPhase=0.);
	EXP_CS double * Noise(double dur_ms);
	EXP_CS double * Noise(int nsamples);
	EXP_CS double * Noise2(double dur_ms);
	EXP_CS double * Noise2(int  nsamples);
	EXP_CS double * Truncate(double time_ms1, double time_ms2);
	EXP_CS double * Truncate(int id1, int id2, int code=0);
	EXP_CS CSignal& Diff();
	EXP_CS CSignal& Cumsum();

	// Window functions
	//EXP_CS double * Hann(int len);	// Use Blackman with alpha=0
	EXP_CS double * Hamming(int len);
	EXP_CS double * Blackman(int len, double alp=0.16);

	// Signal alteration (stereo handling with a clean, inarguable convention)
#ifndef NO_IIR
	EXP_CS int IIR(int kind, int type, int order, double *freqs, double passRipple_dB, double stopFreqORAttenDB, char *errstr);
#endif // NO_IIR
	int filtfilt(const CSignal& num, const CSignal& den, char *errstr);
	virtual void filtfilt(int nTabs, double *num, double *den);
	void filtfilt(int  nTabs, double *num);
	void Filter(int  nTabs, double *num);
	virtual void Filter(int nTabs, double *num, double *den);
	int Filter(const CSignal& num, const CSignal& den, char *errstr);
#ifndef NO_FFTW
	virtual double * Hilbert(int len);
	virtual double * HilbertEnv(int len);
	virtual double * ShiftFreq(double shift);
	virtual double * TCTS(double freq, double ratio);
#endif
	virtual void DownSample(int q);
	virtual void UpSample(int p);
	virtual CSignal& Reset(int  fs2set=0);
#ifndef NO_RESAMPLE
	virtual double * Resample(int newfs, char *errstr);
	virtual double * Resample(vector<int> newfs, vector<int> lengths, char *errstr);
#endif //NO_RESAMPLE
	virtual void Dramp(double dur_ms, int beginID=0);
	EXP_CS void ReverseTime();
	EXP_CS CSignal& Interp(const CSignal& gains, const CSignal& tmarks);
	EXP_CS CSignal& operator=(const CSignal& rhs);
	EXP_CS CSignal& operator+=(const double con);
	EXP_CS CSignal& operator*=(const double con);
	EXP_CS CSignal& operator/=(double con);
	EXP_CS CSignal& operator-(void);	// Unary minus
	EXP_CS CSignal& operator*=(CSignal &scaleArray);
	EXP_CS CSignal& operator+=(CSignal &sec);
	EXP_CS CSignal& operator-=(CSignal &sec);
	EXP_CS CSignal& Reciprocal(void);	// Multiplicative inverse
	EXP_CS CSignal& operator/=(CSignal &scaleArray);

	virtual CSignal& operator>>=(const double delta);
	EXP_CS CSignal& operator<<=(const double delta);

	EXP_CS void SwapContents1node(CSignal &sec);
	// Signal alteration (stereo handling with an established convention)
	virtual const CSignal& operator+=(CSignal *yy); // Concatenation

	EXP_CS CSignal& LogOp(CSignal &rhs, int type);
	// Signal extraction (stereo handling with a clean, inarguable convention)
	EXP_CS CSignal& Take(CSignal& out, int  id1);
	EXP_CS CSignal& Take(CSignal& out, double begin_ms);
	EXP_CS CSignal& Take(CSignal& out, int  id1, int  id2);
	EXP_CS CSignal& Take(CSignal& out, double begin_ms, double end_ms);

	EXP_CS CSignal& Squeeze();

	virtual CSignal& Trim(double begin_ms, double end_ms);
	virtual CSignal& timeshift(double tp_ms);
	virtual CSignal& removeafter(double timems);

	EXP_CS int WriteAXL(FILE* fp);

	// Retrieve signal characteristics (single channel ONLY)
	EXP_CS int GetType() const; 
	EXP_CS int GetTypePlus() const;
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
	EXP_CS double endt() {return tmark + dur();}// end time point in miliseconds
	EXP_CS double totaldur();

	EXP_CS bool IsScalar() const {return (GetType() == CSIG_SCALAR);}
	EXP_CS bool IsEmpty() const {return (GetType() == CSIG_EMPTY);}
	EXP_CS bool IsSingle() const {return ( (GetType() == CSIG_SCALAR || GetType() == CSIG_COMPLEX || GetType() == CSIG_STRING) && nSamples==1);}
	EXP_CS bool IsString() const {return (fs == 2);}
	EXP_CS bool IsLogical() const {return (bufBlockSize==1 && fs != 2);} // logical can be either audio or non-audio, so GetType() of logical array will not tell you whether that's logical or not.
	EXP_CS bool IsComplex() const  { return (bufBlockSize==2*sizeof(double)); } 
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
	CSignal &each(double (*fn)(double, double), body &arg2);
	CSignal &each(complex<double> (*fn)(complex<double>));
	CSignal &each(complex<double> (*fn)(complex<double>, complex<double>), body &arg2);
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
	EXP_CS void SetValue(double v);
	EXP_CS void SetValue(complex<double> v);	

	EXP_CS int ReadAXL(FILE* fp, bool logical);
	EXP_CS int WriteAXL(FILE* fp);

	EXP_CS int GetType() const;

	EXP_CS void SetNextChan(CSignal *second);
	EXP_CS CSignal *DetachNextChan() {CSignal *p=next;next=NULL;return p;}
	EXP_CS CSignals& Reset(int  fs2set=0);
	EXP_CS CSignals& Reciprocal(void);
	EXP_CS CSignals& operator-(void);
	EXP_CS CSignals& operator>>=(const double delta);
	EXP_CS CSignals& Take(CSignals& out, int  id1, int  id2);
	EXP_CS CSignals& Trim(double begin_ms, double end_ms);
	EXP_CS void Dramp(double dur_ms, int  beginID=0);
	EXP_CS double * Modulate (double *env, int  lenEnv);
	EXP_CS CSignals& Insert(double timept, CSignals &newchunk);
	EXP_CS CSignals& Replace(CSignals &newsig, double t1, double t2);
	EXP_CS CSignals& LogOp(CSignals &rhs, int type);

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
	EXP_CS CSignals &each(double (*fn)(double, double), body &arg2);
	EXP_CS CSignals &each(complex<double> (*fn)(complex<double>));
	EXP_CS CSignals &each(complex<double> (*fn)(complex<double>, complex<double>), body &arg2);
	CSignals &transpose1() {CSignal::transpose1(); if (next) next->transpose1(); return *this;}

#ifdef _WINDOWS
#ifndef NO_PLAYSND
	// Sound Playback functions
	EXP_CS int PlayArray(int DevID, UINT userDefinedMsgID, HWND hApplWnd, double *block_dur_ms, char *errstr, int  loop=0); // playing with event notification by specified time block
	EXP_CS int PlayArray(int DevID, UINT userDefinedMsgID, HWND hApplWnd, int  nProgReport, char *errstr, int  loop=0); // full format
	EXP_CS int PlayArrayNext(int DevID, UINT userDefinedMsgID, double *block_dur_ms, char *errstr);
	EXP_CS int PlayArrayNext(int DevID, UINT userDefinedMsgID, int  nProgReport, char *errstr); // full format
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

class CAstSig;

class CAstException {
public:
	const AstNode *pnode;
	CAstSig *pAst;
	string str1, str2, outstr;
	int int1;

	EXP_CS CAstException(const AstNode *p, CAstSig *pAst, const string s1, const string s2="");
	EXP_CS CAstException(const AstNode *p, CAstSig *pAst, const string s1, const int x, const string s2="");
	EXP_CS CAstException(const AstNode *p0, CAstSig *pAst, const char** FuncSigs, const string msg);
	EXP_CS CAstException(const AstNode *p0, CAstSig *past, const char* msg);
	string getErrMsg() const {return outstr;};
private:
	EXP_CS void makeOutStr();
};

class CAstSigEnv
{
	friend class CAstSig;
public:
	map<string,AstNode *> UDFs;
	map<string,string> UDFsPath;
	map<string,string> UDF_body;
	map<string, vector<int>> DebugBreaks;
	int Fs;
	int curLine; // used for control F10
	string AuxPath;

	CAstSigEnv(const int fs = 1);
	~CAstSigEnv();
	CAstSigEnv& operator=(const CAstSigEnv& rhs);
	EXP_CS CAstSigEnv &SetPath(const char *path);
	EXP_CS CAstSigEnv &AddPath(const char *path);
};

class CAstSig
{
public:
	map<string, CSignals> Vars;
	AstNode *pAst;
	CSignals Sig;
	string Script;
	CAstSigEnv *pEnv;
	int nextBreakPoint, currentLine;
	AstNode *pCall;
	AstNode *lhs;
	CAstSig *son;
	CAstSig *dad;
	AstNode *pLast;
	DEBUG_STATUS dstatus;
	string statusMsg;
	unsigned long Tick0, Tick1;
private:
	static const int DefaultFs = 22050;
	CSignals replica;
	double endpoint;
	bool debugon;
	bool fAllocatedAst, fExit, fBreak, fContinue;

private:
	void HandleAuxFunctions(const AstNode *pnode);
	AstNode *RetrieveUDF(const char *fname);
	CSignals &getlhs(const AstNode *pnode, CSignals *tagsig, CSignals &isig);
	CAstSig &insertreplace(const AstNode *pnode, CSignal *inout, CSignals &sec, CSignals &indsig);
	void checkindexrange(const AstNode *pnode, CSignal *inout, int id, string errstr);
	bool isContiguous(body &id, int &begin, int &end);
	AstNode *searchtree(AstNode *pp, int type);
	CSignals &extract(CSignal &Sig, body &isig);
	bool checkcond(const AstNode *p);
	AstNode *get_tree_on_line(const AstNode *pnode, int line);

public:
	bool IsThisBreakpoint(const AstNode *pnode);
	void checkAudioSig(const AstNode *pnode, CSignals &checkthis, string addmsg="");
	void checkComplex (const AstNode *pnode, CSignals &checkthis);
	void checkVector(const AstNode *pnode, CSignals &checkthis, string addmsg="");
	void checkString(const AstNode *pnode, CSignals &checkthis, string addmsg="");
	void blockCell(const AstNode *pnode, CSignals &checkthis);
	void blockScalar(const AstNode *pnode, CSignals &checkthis);
	void blockString(const AstNode *pnode, CSignals &checkthis);
	void blockComplex(const AstNode *pnode, CSignals &checkthis);
	void cleanup_sons();
	const char* baseudfname();
	bool CheckPrepareCallUDF(const AstNode *pnode);
	void CallUDF();
	void (*CallbackCIPulse)(const AstNode *, CAstSig *);
	int (*CallbackHook)(CAstSig &ast, const AstNode *pnode, const AstNode *p);
	EXP_CS CSignals *RetrieveVar(const char *tagname);
	EXP_CS CSignal *RetrieveCell(const char *cellvar, int id);

    EXP_CS CAstSig(const CAstSig &org);
	EXP_CS CAstSig(const CAstSig *src);
	EXP_CS CAstSig(const char *str, const CAstSig *src);
	EXP_CS CAstSig(AstNode *pNode, const CAstSig *src);
	EXP_CS CAstSig(CAstSigEnv *env);
	EXP_CS CAstSig(const char *str, CAstSigEnv *env);
	EXP_CS CAstSig(AstNode *pNode, CAstSigEnv *env);
	EXP_CS ~CAstSig();

	EXP_CS CAstSig &SetNewScript(const char *str, AstNode *pAstOut = NULL);
	EXP_CS AstNode* SetNewScriptFromFile(const char *str, FILE *source);
	EXP_CS vector<CSignals> Compute(void);
	EXP_CS CSignals &Compute(const AstNode *pnode);
	EXP_CS CSignals &CellAssign(const AstNode *pnode, AstNode *p);
	EXP_CS CSignals &Assign(const AstNode *pnode, AstNode *p);
	
	EXP_CS CSignals &t_id(const AstNode *pnode, AstNode *p);
	EXP_CS CSignals &NodeInterpol(const AstNode *pnode, AstNode *p);
	EXP_CS CSignals &SetLevel(const AstNode *pnode, AstNode *p);
	EXP_CS CSignals &NodeVector(const AstNode *pnode, AstNode *p);
	EXP_CS CSignals &NodeMatrix(const AstNode *pnode, AstNode *p);
	EXP_CS CSignals &IxAssign(const AstNode *pnode, AstNode *p);
	EXP_CS CSignals &NodeExtract(const AstNode *pnode, AstNode *p);
	EXP_CS CSignals &NodeCall(const AstNode *pnode, AstNode *p);
	EXP_CS CSignals &Eval(AstNode *pnode);
	EXP_CS CAstSig &Reset(const int fs = 0, const char* path=NULL);
	EXP_CS CAstSig &SetVar(const char *name, const CSignals &sig);
	EXP_CS CSignals *GetVar(const char *name);
	EXP_CS CAstSig &AddCell(const char *name, const CSignals &sig);
	EXP_CS CAstSig &SetCell(const char *name, const unsigned int i, const CSignal &sig);
	EXP_CS const char *GetPath() {return pEnv->AuxPath.c_str();}
	EXP_CS AstNode *GetAst(void) {return pAst;}
	EXP_CS int GetFs(void) {return pEnv->Fs;}
	EXP_CS static bool IsCondition(const AstNode *pnode);
	EXP_CS string ComputeString(const AstNode *p);
	EXP_CS string GetScript() {return Script;}
	EXP_CS void interrupt(void);
	EXP_CS bool isInterrupted(void);

	EXP_CS int isthislocaludf(void);


	EXP_CS int ClearVar(const char *var);
	EXP_CS void EnumVar(vector<string> &var);
	EXP_CS CSignals *GetSig(const char *var);

	EXP_CS string MakeFilename(string fname, const string ext);
	EXP_CS FILE *OpenFileInPath(string fname, const string ext, string &fullfilename);
	EXP_CS AstNode *ReadUDF(const char *udf_filename, const AstNode *pnode);
	void checkNumArgs(const AstNode *pnode, const AstNode *p, const char** FuncSigs, const int minArgs, const int maxArgs);
};


#ifdef _WINDOWS
//Global functions

EXP_CS void LoopPlay(int  onoff);
EXP_CS void TerminatePlay();
EXP_CS void PauseResumePlay(void *pWavePlay, bool fOnOff);
EXP_CS void TerminateLoop(void *pWavePlay);
EXP_CS DWORD WinMMGetVolume();
EXP_CS int WinMMSetVolume(DWORD vol);

#endif // _WINDOWS
EXP_CS void checkNumArgs(const AstNode *pnode, const AstNode *p, const char** FuncSigs, const int minArgs, const int maxArgs);

#endif // SIGPROC