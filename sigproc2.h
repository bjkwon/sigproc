#pragma once

#define PI	3.141592
#define LOG10DIV20 0.1151292546497
#define round(x)	((int)((x)+((x)<0?-.5:.5)))

//If this library is linked statically define LINK_STATIC_SIGPROC in the application project.
#ifndef LINK_STATIC_SIGPROC
#define EXP_CS __declspec (dllexport)
#else
#define EXP_CS
#endif

namespace std2 {
#include <windows.h>
}
#include <string>
#include <iostream>
#include <list>
#include <map>
#include <set>

#include "psycon.yacc.h"

class CSignals
{
public:
	// Signal generation (no stereo handling)
	EXP_CS double * fm(double midFreq, double fmWidth, double fmRate, int nsamples, double beginFMPhase=0.);
	EXP_CS double * fm(double midFreq, double fmWidth, double fmRate, double dur_ms, double beginFMPhase=0.);
	EXP_CS double * Silence(int nsamples);
	EXP_CS double * Silence(double dur_ms);
	EXP_CS double * DC(double dur_ms);
	EXP_CS double * DC(int nsamples);
	EXP_CS double * Tone(double *freq, int nsamples, double beginPhase=0.);
	EXP_CS double * Tone(double *freq, double dur_ms, double beginPhase=0.);
	EXP_CS double * Tone(double freq, int nsamples, double beginPhase=0.);
	EXP_CS double * Tone(double freq, double dur_ms, double beginPhase=0.);
	EXP_CS double * Noise(double dur_ms);
	EXP_CS double * Noise(int nsamples);
	EXP_CS double * Noise2(double dur_ms);
	EXP_CS double * Noise2(int nsamples);
	EXP_CS double * Truncate(double time_ms1, double time_ms2);
	EXP_CS double * Truncate(int id1, int id2);

	// Window functions
	//EXP_CS double * Hann(int len);	// Use Blackman with alpha=0
	EXP_CS double * Hamming(int len);
	EXP_CS double * Blackman(int len, double alp=0.16);

	EXP_CS double * FFT(int len);
	EXP_CS double * iFFT(void);
	EXP_CS double * cFFT(int len);
	EXP_CS double * icFFT(void);
	EXP_CS double * Hilbert(int len);

	// Signal alteration (stereo handling with a clean, inarguable convention)
	EXP_CS int IIR(int kind, int type, int order, double *freqs, double passRipple_dB, double stopFreqORAttenDB, char *errstr);
	EXP_CS int filtfilt(const CSignals& num, const CSignals& den, char *errstr);
	EXP_CS void filtfilt(int nTabs, double *den, double *num);
	EXP_CS void filtfilt(int nTabs, double *num);
	EXP_CS void Filter(int nTabs, double *num);
	EXP_CS void Filter(int nTabs, double *num, double *den);
	EXP_CS int Filter(const CSignals& num, const CSignals& den, char *errstr);
	EXP_CS void DownSample(int q);
	EXP_CS void UpSample(int p);
	EXP_CS CSignals& Reset(int fs2set=0);
	EXP_CS const CSignals& Amplify(double dB);
	EXP_CS double * Resample(int newfs, char *errstr);
	EXP_CS double * Modulate (double *env, int lenEnv);
	EXP_CS double * Modulate (CSignals &secondsignal);
	EXP_CS void Dramp(double dur_ms, int beginID=0);
	EXP_CS void ReverseTime();
	EXP_CS CSignals& Interp(const CSignals& gains, const CSignals& tmarks);
	EXP_CS CSignals& operator=(const CSignals& rhs);
	EXP_CS CSignals& operator*=(const double scaleFactor);
	EXP_CS CSignals& operator*=(CSignals &scaleArray);
	EXP_CS CSignals& operator+=(CSignals &sec);
	EXP_CS CSignals& operator+=(const double con);
	EXP_CS CSignals& operator-(void);	// Unary minus
	EXP_CS CSignals& operator-=(CSignals &sec);
	EXP_CS CSignals& Reciprocal(void);	// Multiplicative inverse
	EXP_CS CSignals& operator/=(CSignals &scaleArray);
	EXP_CS CSignals& operator/=(double scaleFactor);

	EXP_CS CSignals& operator<<=(const double delta);
	EXP_CS CSignals& operator>>=(const double delta);

	EXP_CS CSignals& operator<(const CSignals &sec);
	EXP_CS CSignals& operator>(const CSignals &sec);
	EXP_CS CSignals& operator<=(const CSignals &sec);
	EXP_CS CSignals& operator>=(const CSignals &sec);
	EXP_CS bool operator==(const CSignals &sec) const;
	EXP_CS bool operator!=(const CSignals &sec) const {return !(*this == sec);}
	EXP_CS CSignals& operator!();
	EXP_CS CSignals& operator&&(const CSignals &sec);
	EXP_CS CSignals& operator||(const CSignals &sec);

	void SwapContents1node(CSignals &sec);
	// Signal alteration (stereo handling with an established convention)
	EXP_CS void Insert(CSignals& insertee, int id);
	EXP_CS const CSignals& operator+=(CSignals *yy); // Concatenation

	// Signal extraction (stereo handling with a clean, inarguable convention)
	EXP_CS CSignals& Take(CSignals& out, int id1);
	EXP_CS CSignals& Take(CSignals& out, double begin_ms);
	EXP_CS CSignals& Take(CSignals& out, int id1, int id2);
	EXP_CS CSignals& Take(CSignals& out, double begin_ms, double end_ms);

	EXP_CS CSignals& Trim(double begin_ms, double end_ms);

	// Signal extraction (single channel ONLY)
	EXP_CS CSignals Abs();

	// Retrieve signal characteristics (single channel ONLY)
	EXP_CS double Min(int &id);
	EXP_CS double Min();
	EXP_CS double Max(int &id);
	EXP_CS double Max();
	EXP_CS double Mean();
	EXP_CS double Levels();
	EXP_CS double LevelLT();
	EXP_CS CSignals LevelLTmc();
	EXP_CS double Levels(double *peak, int *index);
	EXP_CS int GetFs() {return fs; };
	EXP_CS void SetFs(int newfs) {fs = newfs; };
	EXP_CS double* GetBuffer();
	EXP_CS int GetLength();
	EXP_CS double GetDuration(); // duration in miliseconds
	EXP_CS CSignals * GetNextChan() {return next;};
	EXP_CS int GetNumChan() const {return next?1+next->GetNumChan():0;}
	EXP_CS double *MakeDoubleArray(double *DoubleArray);
	EXP_CS void SetBufferFromDoubleArray(double* scaledDoubleArray, int length);
	EXP_CS bool IsScalar() const {return (nSamples == 1 && chain == NULL && next == NULL);}
	bool IsSingle() const {return (nSamples == 1 && chain == NULL);}
	bool IsString() const {return (fs == 2);}

	//Miscellaneous functions
	EXP_CS void *PlayArray(int DevID, std2::UINT userDefinedMsgID, std2::HWND hApplWnd, double *block_dur_ms, char *errstr); // playing with event notification by specified time block
	EXP_CS void *PlayArray(int DevID, std2::UINT userDefinedMsgID, std2::HWND hApplWnd, int nProgReport, char *errstr); // full format
	EXP_CS void *PlayArray(int DevID, char *errstr); // (blocking play)
	EXP_CS void *PlayArray(char *errstr); //assuming the first device
	EXP_CS int Wavwrite(const char *wavname, char *errstr);
	EXP_CS int Wavread(const char *wavname, char *errstr);

	EXP_CS CSignals(); // default construct
	EXP_CS CSignals(int sampleRate); // construct with a specified sample rate.
	EXP_CS CSignals(double value); // construct a scala with the specified value
	EXP_CS CSignals(const CSignals& src); // copy constructor
	EXP_CS CSignals(const char* wavname); // from a wave file
	EXP_CS ~CSignals();	// standard destructor
	EXP_CS double* Str2Sig(const char * strIn, char *errstr=NULL);
	EXP_CS CSignals& UpdateBuffer(int length);

	EXP_CS void SetNextChan(CSignals *second);
	EXP_CS CSignals *DetachNextChan() {CSignals *p=next;next=NULL;return p;}
	EXP_CS void SetChain(CSignals *unit, double time_shifted=0.);
	EXP_CS void SetChain(double time_shifted);
	//EXP_CS void AddChain(CSignals *sec);
	EXP_CS void AddChain(CSignals &sec);
	EXP_CS CSignals * CSignals::GetDeepestChain();
	EXP_CS CSignals * CSignals::ExtractDeepestChain(CSignals *deepchain);
	EXP_CS int CSignals::GetHowmanyChains();
	EXP_CS void PlusChain(CSignals *forthis);
	EXP_CS void MultChain(CSignals *forthis);
	EXP_CS void CSignals::Chain2Array(CSignals **chains, CSignals *forthis);
	EXP_CS CSignals * CSignals::BreakChain(CSignals *chainedout);
	EXP_CS double CalculateTotalDuration();
	EXP_CS double MakeChainless(double dur=0., int *pNewFS=NULL);
	EXP_CS double value(void) const {if (nSamples==1) return buf[0]; else if (nSamples==0) throw "Internal error! value( ) on null."; else throw "Internal error! value( ) on vector.";}
	EXP_CS void SetValue(double v) {Reset(1); nSamples=1; buf[0]=v;}
	EXP_CS std::string string();
	EXP_CS char *getString(char *str, const int size);
	CSignals &each(double (*fn)(double));
	CSignals &transpose1();

	int nSamples;
	double tmark, tfraction;
	double *buf;

private:
	size_t BufSize;
	int fs;
	CSignals *next;
	CSignals *chain;
	void* colonednums(double x1, double x2);
	void* colonednums(double x1, double x2, double x3);
};

using namespace std;

class CAstException {
public:
	const AstNode *pnode;
	string str1, str2, outstr;
	int int1;

	EXP_CS CAstException(const AstNode *p, const string s1, const string s2="");
	EXP_CS CAstException(const AstNode *p, const string s1, const int x, const string s2="");
	EXP_CS CAstException(const AstNode *p0, const AstNode *p, const char** FuncSigs, const string msg);
	string getErrMsg() const {return outstr;};
private:
	void makeOutStr();
};

class CAstSig;

class CAstSigEnv
{
	friend class CAstSig;
public:
	CAstSigEnv(const int fs = 1);
	~CAstSigEnv();
private:
	map<string,CSignals> Tags;
	map<string,CSignals *> Refs;
	map<string,map<int,CSignals>> Arrays;
	map<string,map<int,CSignals> *> ArrRefs;
	map<string,AstNode *> UDFs;
	set<string> NoAuxFiles;
	string WavePath, AuxPath, DataPath;
	int Fs, RefCount;
};

class CAstSig
{
private:
	static const int DefaultFs = 22050;
	AstNode *pAst;
	string Script;
	bool fAllocatedAst, fExit, fBreak, fContinue;
	CAstSigEnv *pEnv;

	void initGlobals(const CAstSig *env);
	void HandleAuxFunctions(const AstNode *pnode);
	CSignals &CallSub(const AstNode *pUDF, const AstNode *pCall);
	CSignals *RetrieveTag(const char *tagname);
	map<int,CSignals> *RetrieveArray(const char *arrayname);
	AstNode *RetrieveUDF(const char *fname);
	CAstSig &SetCell(const char *name, const int i, const CSignals &sig);

public:
	CSignals Sig;
	DWORD Tick0, Tick1;
	void (*CallbackCIPulse)(const AstNode *, CAstSig *);
	int (*CallbackHook)(CAstSig &ast, const AstNode *pnode, const AstNode *p);

    EXP_CS CAstSig(const CAstSig &org);
	EXP_CS CAstSig(const CAstSig *env);
	EXP_CS CAstSig(const char *str, const CAstSig *env);
	EXP_CS CAstSig(AstNode *pNode, const CAstSig *env);
	EXP_CS CAstSig(const int fs = DefaultFs);
	EXP_CS CAstSig(const char *str, const int fs = DefaultFs);
	EXP_CS CAstSig(AstNode *pNode, const int fs = DefaultFs);
	EXP_CS ~CAstSig();

	EXP_CS CAstSig &SetNewScript(const char *str);
	EXP_CS CAstSig &SetNewFile(FILE *source);
	EXP_CS CSignals &Compute(void);
	EXP_CS CSignals &Compute(const AstNode *pnode);
	EXP_CS CSignals &Eval(AstNode *pnode);
	EXP_CS CAstSig &Reset(const int fs = 0);
	EXP_CS CAstSig &SetTag(const char *name, const CSignals &sig);
	EXP_CS CSignals &GetTag(const char *name);
	EXP_CS void SetRef(const char *ref, const char *var);
	EXP_CS CAstSig &SetPath(const char *ext, const char *path);
	EXP_CS const char *GetPath(const char *ext);
	EXP_CS AstNode *GetAst(void) {return pAst;}
	EXP_CS int GetFs(void) {return pEnv->Fs;}
	EXP_CS static bool IsCondition(const AstNode *pnode);
	EXP_CS string ComputeString(const AstNode *p);
	EXP_CS void interrupt(void);
	EXP_CS bool isInterrupted(void);

	string MakeFilename(string fname, const string ext);
	FILE *OpenFileInPath(string &fname, const string ext);

};
