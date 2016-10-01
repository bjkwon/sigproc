// CSignals.h : header file
//
#ifndef CSIGNALS
#define CSIGNALS

#ifdef _CHAR16T
#define CHAR16_T
#endif

//#include "mat.h" // For matOpen
//namespace mat {
//#include "matrix.h"
//}

#ifdef _WINDOWS
#include <windows.h>
#endif
#define PI	3.141592

#ifndef LINK_STATIC_SIGPROC
#define EXP_CS __declspec (dllexport)
#else
#define EXP_CS
#endif

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
	EXP_CS void Reset(int fs2set);
	EXP_CS const CSignals& Amplify(double dB);
	EXP_CS double * Resample(int newfs, char *errstr);
	EXP_CS double * Modulate (double *env, int lenEnv);
	EXP_CS double * Modulate (CSignals &secondsignal);
	EXP_CS void Dramp(double dur_ms, int beginID=0);
	EXP_CS void ReverseTime();
	EXP_CS const CSignals& operator=(const CSignals& rhs);
	EXP_CS const CSignals& operator*=(double scaleFactor);
	EXP_CS const CSignals& operator*(CSignals scaleArray);
	EXP_CS const CSignals& operator*=(CSignals scaleArray) { return *this * scaleArray; }
	EXP_CS const CSignals& operator+=(const double con);//
	EXP_CS const CSignals& operator+=(CSignals sec) { return *this + sec; }
	EXP_CS const CSignals& operator+(CSignals &sec);
	EXP_CS const CSignals& operator/=(double scaleFactor);
	EXP_CS const CSignals& operator/(CSignals scaleArray);
	EXP_CS const CSignals& operator/=(CSignals scaleArray)  { return *this / scaleArray; }

	// Signal alteration (stereo handling with an established convention)
	EXP_CS void Insert(const CSignals& insertee, int id);
	EXP_CS const CSignals& operator+=(const CSignals *yy); // Concatenation

	// Signal extraction (stereo handling with a clean, inarguable convention)
	EXP_CS CSignals& Take(CSignals& out, int id1);
	EXP_CS CSignals& Take(CSignals& out, double begin_ms);
	EXP_CS CSignals& Take(CSignals& out, int id1, int id2);
	EXP_CS CSignals& Take(CSignals& out, double begin_ms, double end_ms);

	// Signal extraction (single channel ONLY)
	EXP_CS CSignals Abs();

	// Retrieve signal characteristics (single channel ONLY)
	EXP_CS int GetType();
	EXP_CS double Sum();
	EXP_CS double Min(int &id);
	EXP_CS double Min();
	EXP_CS double Max(int &id);
	EXP_CS double Max();
	EXP_CS double Mean();
	EXP_CS double Levels();
	EXP_CS double LevelLT();
	EXP_CS double Levels(double *peak, int *index);
	EXP_CS int GetFs() {return fs; };
	EXP_CS void SetFs(int newfs) {fs = newfs; };
	EXP_CS double* GetBuffer();
	EXP_CS int GetLength() {return nSamples; } 
	EXP_CS double GetDuration(); // duration in miliseconds
	EXP_CS CSignals * GetNextChan() {return next;};
	EXP_CS double *MakeDoubleArray(double *DoubleArray);
	EXP_CS void SetBufferFromDoubleArray(double* scaledDoubleArray, int length);

	//Miscellaneous functions 
	EXP_CS int PlayArray(int DevID, UINT userDefinedMsgID, HWND hApplWnd, int nProgReport, char *errstr); // full format
	EXP_CS int PlayArray(int DevID, char *errstr); // (blocking play)
	EXP_CS int PlayArray(char *errstr); //assuming the first device
	EXP_CS int Wavwrite(const char *wavname, char *errstr, std::string wavformat="");
	EXP_CS int Wavread(const char *wavname, char *errstr);

	EXP_CS CSignals(); // default construct 
	EXP_CS CSignals(int sampleRate); // construct with a specified sample rate.
	EXP_CS CSignals(double value); // construct a scala with the specified value
	EXP_CS CSignals(const CSignals& src); // copy constructor
	EXP_CS CSignals(const char* wavname); // from a wave file
	EXP_CS ~CSignals();	// standard destructor
	EXP_CS void *Str2Sig(const char * strIn, char *errstr=NULL);
	EXP_CS void UpdateBuffer(int length);

	EXP_CS void SetNextChan(CSignals *second);
	EXP_CS void SetChain(CSignals *unit, double time_shifted=0.);
	EXP_CS void SetChain(double time_shifted);
	EXP_CS void AddChain(CSignals *sec);
	EXP_CS void AddChain(CSignals sec);
	EXP_CS CSignals * GetDeepestChain();
	EXP_CS CSignals * ExtractDeepestChain(CSignals *deepchain);
	EXP_CS int GetHowmanyChains();
	EXP_CS void PlusChain(CSignals *forthis);
	EXP_CS void Chain2Array(CSignals **chains, CSignals *forthis);
	EXP_CS CSignals * BreakChain(CSignals *chainedout);
	EXP_CS CSignals* totalDuration(CSignals temp, double &dur);
	EXP_CS void MakeChainless();
	//use value() function only when you are sure that the length is 1 or zero.
	EXP_CS double value() {if (nSamples<=0) return val; else return *buf;}
	union { double val; double tmark;};
	int nSamples;
	double *buf;

private:
	int fs;
	CSignals *next;
	CSignals *chain; 
	void* colonednums(double x1, double x2);
	void* colonednums(double x1, double x2, double x3);
};

#endif