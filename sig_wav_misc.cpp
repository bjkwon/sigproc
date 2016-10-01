// signalplus.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include "sigplus_internal.h"

EXP_CS double LeveldBrms (const char *wave, double *level2, char *errstr)
{
	CSignals xx, xx2;
	if (!xx.Wavread(wave, errstr))	return 9999;
	if (xx.GetNextChan()!=NULL)
		*level2 = xx.GetNextChan()->Levels();
	else
		*level2 = -9999.9;
	errstr[0] = '\0'; // If no error, errstr is empty
	return xx.Levels();
}

EXP_CS double LeveldBpeak (const char *wave, char *errstr)
{ // DO THIS LATER!!!!! 5-2-07
	CSignals xx;
	double peak;
	if (xx.Wavread(wave, errstr)==NULL)	return 9999;
	errstr[0] = '\0'; // If no error, errstr is empty
	peak = max(xx.Max(), -xx.Min());
	return 20*log10(peak);
}

EXP_CS int Rescale(const char *waveOut, const char *waveIn, double scaleFactor_dB, char *errstr)
{
	/* Returns 1 for success,
	           -1 for success, but possible clipping
			   0 for failure.
  */
	CSignals x, x2;
	double factor;
	bool clipped1(false), clipped2(false);

	if (!x.Wavread(waveIn, errstr))		return 0;
	factor = exp (scaleFactor_dB/20.*log(10.));
	if (factor==1.)
	{
		if (CopyFile(waveIn, waveOut, 0)==0)
		{
			sprintf (errstr, "Could not copy the wave file. GetLastError()=%d", GetLastError());
			return 0;
		}
	}
	else if (factor<1) // no need to worry about clipping
	{
		x *= factor; // next (second channel is taken care of here)
		if (x.Wavwrite(waveOut, errstr)==NULL)	return 0;
	}
	else // need to worry about clipping
	{
		clipped1 = IsMagnitudeClipped (x.buf, x.GetLength(), 1.);
		x *= factor;
		if (x.Wavwrite(waveOut, errstr)==NULL)	return 0;
		if (clipped1 | clipped2) return -1;
	}
	return 1;
}

EXP_CS int ReadwavInfo(const char *wave, int *fs, int *nChan, int *lengthPerChan, char *errstr)
{
	CSignals x;
	if (!x.Wavread(wave, errstr)) 		return 0;
	if (fs!=NULL) *fs = x.GetFs();
	if (nChan!=NULL) *nChan = (x.GetNextChan()==NULL) ? 1:2;
	if (lengthPerChan!=NULL) *lengthPerChan = x.GetLength();
	return 1;
}

EXP_CS int MakeMono(const char *waveIn, const char *waveOut,char *errstr)
{
	CSignals x, x2;

	if (!x.Wavread(waveIn, errstr))		return 0;
	if (x.GetNextChan()==NULL)	return (CopyFile(waveIn, waveOut, 0)==1);
	x2 = *x.GetNextChan();
	x += x2;
	return x.Wavwrite(waveOut, errstr);
}

EXP_CS 
