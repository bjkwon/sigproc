#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <process.h>
#include "sigplus_internal.h"

//FYI: These two message are sent to different threads.
#define WM__RETURN		WM_APP+10
#define MM_DONE			WM_APP+11
#define MM_ERROR		WM_APP+12

static char errmsg[2048];
HWND hMainAppl(NULL);

EXP_CS void SetHWND_SIGPROC(HWND h)
{
	hMainAppl = h;
}

EXP_CS HWND GetHWND_SIGPROC()
{
	return hMainAppl;
}

#ifndef NO_PLAYSND

//This handles MM error for the function (PlayArray) return only inside Thread4MM
#define MMERR(X) if ((X)!=MMSYSERR_NOERROR) {char *__rpst, *__rpst2, __fbuff[2048]; strcpy(__fbuff, #X); \
	__rpst2 =__fbuff + 5; __rpst = strchr(__rpst2, '('); __rpst2[__rpst-__rpst2]=0; \
	strcpy(errmsg, "Error on "); strcat(errmsg, __rpst2);\
	PostThreadMessage (pWP->callingThreadID, MM_ERROR, (WPARAM)(-1*rc), (LPARAM)errmsg); return -1;}

//This handles MM error outside Thread4MM, but inside the CWavePlay class
//i.e., PostThreadMessage may not be effective if PlayArray has already returned.
//So sending error code to the application HWND via SendMessage
#define MMERR2(X) if ((X)!=MMSYSERR_NOERROR) {char *__rpst, *__rpst2, __fbuff[2048]; strcpy(__fbuff, #X); \
	__rpst2 =__fbuff + 5; __rpst = strchr(__rpst2, '('); __rpst2[__rpst-__rpst2]=0; \
	strcpy(errmsg, "Error on "); strcat(errmsg, __rpst2);\
	PostThreadMessage (callingThreadID, MM_ERROR, (WPARAM)(-1*rc), (LPARAM)errmsg); SendMessage (hWnd_calling, msgID, 0xFFFF, (LPARAM)rc); return -1;}

//HANDLE mt;

//to create a log file for soundplay define this
//#define LOGGING  

#define OK			0
#define ERR			-1
#define NO_LOOP			0
#define LOOP_PLAY		1

#define FINISHED_PLAYING_CLEANUP	11

double _24bit_to_double(int x);

DWORD threadIDs[64]; // to track thread handle in the present thread (e.g., to track history)  
int len_threadIDs(0); // to track thread handle in the present thread (e.g., to track history) 

#define WM__SETNEXTPLAY		WM_APP+712
#define WM__LOOP			WM_APP+713
#define WM__STOP			WM_APP+715

#define MMCHECK(x) { rc = (x); if (rc!=MMSYSERR_NOERROR) {sprintf (errstr,"Error at "#x); return rc;}}

#define MMCHECK_THREAD(x) { rc = (x); if (rc!=MMSYSERR_NOERROR) \
{char errstr[256], estr[256]; sprintf (errstr,"Error with code %d at "#x,rc); GetLastErrorStr(rc, estr); MessageBox(NULL, errstr, estr,0); return rc;}}

#define LOG(X) fprintf(fp,(X));

typedef struct 
{
	VOID*	playBuffer;
	int		length;
	int		nChan;
	int		nProgReport;
	int		DevID;
} NP;

class CWavePlay
{
public:
	HWND			hWnd_calling;
	uintptr_t		hThread;
	DWORD			threadID;
	DWORD			callingThreadID;
	UINT			msgID;
	DWORD			totalSamples;
	DWORD			curPt;
	int				ReportIndex;
	bool			blockMode;
	bool			stopped;
	bool			ready2Clean;
	bool			loop;
	DWORD			playBufferLen;
	VOID*			playBuffer;
	vector<NP>		nextPlay;
	HWAVEOUT		hwo;
	WAVEOUTCAPS		woc;
	WAVEHDR			wh[2];
	WAVEFORMATEX	wfx;
	vector<short*>	buffer2Clean;
	CWavePlay();
	~CWavePlay();
	void fillDataBuffer(WAVEHDR* pwh, DWORD offset, int nBlock);
	int OnBlockDone (WAVEHDR* lpwh);
	int playnextchunk(char *errstr);
private:
	int	cleanUp(int threadIDalreadycut=0);
};

__declspec( thread ) CWavePlay *pWP = NULL;

#define FILEOUT {HANDLE hf; DWORD dw; hf = CreateFile("wavex.txt", GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);\
	SetFilePointer(hf, NULL,NULL, FILE_END); WriteFile(hf, fout, strlen(fout), &dw, NULL); CloseHandle(hf);}

CWavePlay::CWavePlay()
: playBuffer(NULL), hThread(NULL), loop(false)
{
}

CWavePlay::~CWavePlay()
{
	// Do we need to free up any memory blocks that were somehow not taken care of?
	// Probably not, because buffer2Clean takes care of cleaning well. 
	// But think about a possibility where somehow cleanUp() is not called properly. 7/11/2016 bjk
}


int CWavePlay::cleanUp(int IDcut)
{
	if (ready2Clean) {
		int rc = 0;
		for (int k=0; k<2 ; ++k)
			MMERR2(rc = waveOutUnprepareHeader(hwo, wh+k, sizeof(WAVEHDR)))
		MMERR2(rc = waveOutClose(hwo))
		if (blockMode)	PostThreadMessage (callingThreadID, WM__RETURN, OK, 0);
		for (size_t k=buffer2Clean.size()-1; k>0; k--)
		{
			if (buffer2Clean.back() == buffer2Clean[k-1])
				buffer2Clean.pop_back();
		}
		for (UINT k=0; k<buffer2Clean.size(); k++)
			delete[] buffer2Clean[k];
		PostThreadMessage (callingThreadID, MM_DONE, 0, 0); // doesn't matter if the message loop is already closed. Just send this in case of blocking mode (i.e., the message loop is still active)
		if (IDcut==0)
			threadIDs[len_threadIDs---1]=0;
		PostQuitMessage(totalSamples);
		return FINISHED_PLAYING_CLEANUP;
	} else {
		 ready2Clean=true;
		 return 1;
	}
}

void CWavePlay::fillDataBuffer (WAVEHDR* pwh, DWORD offset, int nBlock)
{	
	if (wfx.wBitsPerSample ==8)
		pwh->lpData=(char*)playBuffer+offset;
	else if (wfx.wBitsPerSample ==16)
		pwh->lpData=(char*)((short*)playBuffer+offset);
	pwh->dwBufferLength = nBlock * wfx.wBitsPerSample / 8 ;
	pwh->dwFlags = 0;
}
// bjkwon 4/29/2016... Not using it any more because...
//map<WAVEHDR *, CWavePlay *> mapWavePlays; 
// because in a multi-thread environment (where several different hWnd's attempts to play from different threads)
// this global variable mapWavePlays changes mysteriously in callbacks of mmBaseProc (for WOM_DONE)
// as a result, when the application plays a sound from a hWnd in thread A, it fails to play from another hWnd in thread B.
// Solution: WAVEHDR dwUser field now shows the pointer of CWavePlay object that was created in PlayBufAsynch16(),
// sacfrificing the looping function... if needed, put it back somehow later.

int CWavePlay::OnBlockDone(WAVEHDR* lpwh)
{
	int blockLen;
	MMRESULT	rc;
	char errstr[256];
	int id = GetCurrentThreadId ();

//	FILE *pot = fopen("playback_track.txt","at");

	// Insert LOGGING1
	if (stopped)  
	{	SendMessage (hWnd_calling, msgID, 0, ReportIndex);	return cleanUp(1); }
	if (++ReportIndex>=0 && !blockMode) 
	{
		SendMessage (hWnd_calling, msgID, curPt/wfx.nChannels, ReportIndex+1);
//		fprintf(pot, "curPt=%d, curPt/wfx.nChannels=%d, ReportIndex+1=%d\n", curPt, curPt/wfx.nChannels, ReportIndex+1);
	}
//	fclose(pot);
	if (curPt<totalSamples)
	{  // blockLen could be all the same if it is not integer. In reality, because it is integer, there will be 
		// some leftover if blockLen always the same as playBufferLen. So the last block should be treated differently.
		if (totalSamples-curPt>=2*playBufferLen) 
			blockLen = playBufferLen;
		else
			blockLen = totalSamples-curPt;
		fillDataBuffer (lpwh, curPt, blockLen);
		MMERR2(rc = waveOutPrepareHeader (hwo, lpwh, sizeof(WAVEHDR)))
		MMERR2(rc = waveOutWrite (hwo, lpwh, sizeof(WAVEHDR)))
		curPt += blockLen;
// Insert LOGGING2
		return 0;
	}
	else if (nextPlay.size()>0)
	{
		playnextchunk(errstr);
		return 0;
	}
	else // curPt must be equal to totalSamples
	{
// Insert LOGGING3
		return cleanUp();
	}
}


int CWavePlay::playnextchunk(char *errstr)
{
	MMRESULT	rc;
	int nSamplesInBlock; // this is per each channel
	NP thisnp = nextPlay.at(nextPlay.size()-1);

	bool openclose (thisnp.nChan!=wfx.nChannels);

	playBuffer = thisnp.playBuffer;
	// then 
	wfx.nChannels		= thisnp.nChan;
	wfx.nBlockAlign		= 2 * wfx.nChannels;
	wfx.nAvgBytesPerSec	= wfx.nSamplesPerSec * wfx.nBlockAlign;
	totalSamples = thisnp.length * wfx.nChannels;
	nSamplesInBlock = thisnp.length / max(thisnp.nProgReport,1);
	playBufferLen = nSamplesInBlock * wfx.nChannels;

	if (openclose) 
		if ((rc = waveOutClose(hwo))!=MMSYSERR_NOERROR)
			rc = waveOutOpen (&hwo, thisnp.DevID, &wfx, (DWORD_PTR)threadID, (DWORD_PTR)545, CALLBACK_THREAD);

	//initiate playing 
	fillDataBuffer (wh, 0, playBufferLen);
	curPt = playBufferLen;
	playBufferLen = (totalSamples-playBufferLen) / max((thisnp.nProgReport-1),1); //only meaningful within this loop (only for when i=1)

	if (!loop)	nextPlay.pop_back();

	MMCHECK(waveOutPrepareHeader (hwo, wh, sizeof(WAVEHDR)));
	MMCHECK(waveOutWrite (hwo, wh, sizeof(WAVEHDR)));

	buffer2Clean.push_back((short*)playBuffer);

	return rc;
}

void EndwavBuffer2snd(CWavePlay *pWavePlay)
{
	int rc;
	pWavePlay->stopped = true;
	if ((rc=waveOutReset(pWavePlay->hwo))!=MMSYSERR_NOERROR)
		SendMessage (pWavePlay->hWnd_calling, pWavePlay->msgID, 0xFFFF, (LPARAM)rc);
}

typedef struct {
	int DevID;
	SHORT *dataBuffer;
	int length;
	int nChan;
	int fs;
	UINT userDefinedMsgID;
	HWND hApplWnd;
	int nProgReport;
	DWORD callingthreadID;
} PARAM4sndplay;

static vector<PARAM4sndplay> pbparam;

/*
What (and how) messages are sent to the main application 

In Thread4MM, 
	when the device is opened
		SendMessage (pWP->hWnd_calling, pWP->msgID, 0, 0);
	when the device is closed
		SendMessage (pWP->hWnd_calling, pWP->msgID, 0, -1);

In OnBlockDone, 
	during the normal operation,
		SendMessage (hWnd_calling, msgID, number_of_bytes_per_channel, cumulative_report_index);
	when stopped prior to the end
		SendMessage (hWnd_calling, msgID, 0, ReportIndex);	

If there is an error,
	SendMessage (hWnd_calling, msgID, 0xFFFF, (LPARAM)rc);  // rc is MMRESULT--the return value of the MM function



*/


unsigned int WINAPI Thread4MM (PVOID p)
{
//	WaitForSingleObject(mt, INFINITE);
	MSG        msg ;
	bool ch(false);
	bool hist(false);
	int nSamplesInBlock; // this is per each channel
	MMRESULT	rc;
	PARAM4sndplay param = pbparam.back();
	pbparam.pop_back();

	pWP = new CWavePlay();
	pWP->ready2Clean=false;
	pWP->ReportIndex=-1;	// because of double-buffering, this needs to be -1
	pWP->blockMode = (param.userDefinedMsgID==0);	// userDefinedMsgID == 0 : blocking (synchronous)
	pWP->playBuffer = param.dataBuffer;
	pWP->hWnd_calling = param.hApplWnd;
	pWP->msgID = param.userDefinedMsgID;
	pWP->callingThreadID = param.callingthreadID;
	pWP->threadID = GetCurrentThreadId ();
	pWP->wfx.nChannels		= param.nChan;
	pWP->wfx.wFormatTag		= WAVE_FORMAT_PCM;
	pWP->wfx.nSamplesPerSec	= param.fs;
	pWP->wfx.nBlockAlign		= 2 * param.nChan;
	pWP->wfx.nAvgBytesPerSec	= pWP->wfx.nSamplesPerSec * pWP->wfx.nBlockAlign;
	pWP->wfx.wBitsPerSample	= 16;
	pWP->wfx.cbSize			= 16;

	MMERR(rc = waveOutOpen (&pWP->hwo, param.DevID, &pWP->wfx, (DWORD_PTR)pWP->threadID, (DWORD_PTR)0, CALLBACK_THREAD))

	pWP->totalSamples = param.length * param.nChan;
	nSamplesInBlock = param.length / max(param.nProgReport,1);
	pWP->playBufferLen = nSamplesInBlock * param.nChan;
	pWP->callingThreadID = param.callingthreadID;
	pWP->stopped = false;
	// Initiate playing after double-buffering, any leftover is processed in hMmBase
	pWP->curPt = 0;

// Insert LOGGING4
	for (int i=0; i<2; i++) // if playBufferLen is odd, the first and second will be even-odd order.
	{ // if its multi-channel(i.e., stereo), playBufferLen must be multiple of nChan, otherwise left-right channels might be swapped around in the middle
		pWP->fillDataBuffer (pWP->wh+i, pWP->curPt, pWP->playBufferLen);
		pWP->curPt += pWP->playBufferLen;
		pWP->playBufferLen = (pWP->totalSamples-pWP->playBufferLen) / max((param.nProgReport-1),1); //only meaningful within this loop (only for when i=1)
		pWP->wh[i].dwLoops=0;
		if (i==0) pWP->wh[i].dwFlags |= WHDR_BEGINLOOP;
		else pWP->wh[i].dwFlags |= WHDR_ENDLOOP;
		MMERR(rc = waveOutPrepareHeader (pWP->hwo, pWP->wh+i, sizeof(WAVEHDR)))
		MMERR(rc = waveOutWrite (pWP->hwo, pWP->wh+i, sizeof(WAVEHDR)))
		if (i==0) MMERR(rc = waveOutPause(pWP->hwo))
		else  MMERR(rc = waveOutRestart(pWP->hwo))
	}
// Insert LOGGING5
	 // IMPORTANT--DO NOT ASSUME THAT pWP->playBuffer == param->dataBuffer in a multithread environment.
	pWP->buffer2Clean.push_back((SHORT*)pWP->playBuffer);
//	pWP->buffer2Clean.push_back(param->dataBuffer); // this will lead to an incorrect pointer and proper buffer is not stored and something else might be stored twice, which will crash the application. 7/11/2016 bjk
	
	NP *thisnp;
	DWORD dw;
	MMRESULT res;
	while (GetMessage (&msg, NULL, 0, 0))
	{
		switch (msg.message)
		{
		//WM_APP+WOM_OPEN sent to hMainAppl (showvarDlg) to notify the beginning and ending of playback
		case WOM_OPEN:
			SendMessage (pWP->hWnd_calling, pWP->msgID, 0, 0);
			SendMessage (hMainAppl, WM_APP+WOM_OPEN, 0, 0); // send the status to the main application 
			if (!pWP->blockMode)
				PostThreadMessage (pWP->callingThreadID, MM_DONE, 0, 0);
			break;
		case WOM_CLOSE:
			SendMessage (pWP->hWnd_calling, pWP->msgID, 0, -1);
			SendMessage (hMainAppl, WM_APP+WOM_CLOSE, 0, 0); // send the status to the main application 
			break;
		case WOM_DONE:
			// This is a hack for auxlab or any application that requires constant updates of playback (is it done yet kind of thing)--
			// For a multiple sound playback, when one sound is finished, WM_APP+WOM_CLOSE is sent and the STOP button in showvarDlg is disabled even though the other sound is still playing. 
			// Ideal solution: track each instance of sound playback and don't send WM_APP+WOM_CLOSE until the last playback is finished----seems complicated
			// Quick solution: Send WM_APP+WOM_OPEN again whenever WOM_DONE is posted, so that the STOP button gets enabled back and the user would see the button blink, which is kind of an OK extra feature.
			// 7/11/2016 bjk
			SendMessage (hMainAppl, WM_APP+WOM_OPEN, 0, 0); // send the status to the main application 
			// End of Quick solution
			pWP->OnBlockDone((WAVEHDR *)msg.lParam);
			break;
		case WM__SETNEXTPLAY:
			SendMessage (hMainAppl, WM_APP+WOM_OPEN, 0, 0); // send the status to the main application 
			thisnp = (NP *)msg.wParam;
			pWP->nextPlay.push_back(*thisnp);
			break;
		case WM__LOOP:
			res = waveOutGetVolume(pWP->hwo, &dw);
			SendMessage (hMainAppl, WM_APP+WOM_OPEN, 0, 0);
			pWP->loop = !((WPARAM)msg.wParam==0);
			break;
		case WM__STOP:
			pWP->loop = false;
			EndwavBuffer2snd(pWP);
			break;
		}
	}
	delete pWP;
//	ReleaseMutex(mt);
	return (unsigned int)msg.wParam;
}

EXP_CS void LoopPlay(int onoff)
{
	if (len_threadIDs==0 || threadIDs[len_threadIDs-1]==0) return;
	if (PostThreadMessage(threadIDs[len_threadIDs-1], WM__LOOP, onoff, 0)==0)
	{
		if (GetLastError()==1444)
		{
			while(PostThreadMessage(threadIDs[len_threadIDs-1], WM__LOOP, onoff, 0)==0)
			{ Sleep(30);}
		}
	}
}

int continuePlay(UINT DevID, SHORT *dataBuffer, int length, int nChan, UINT userDefinedMsgID, int nProgReport, char *errstr)
{
	DWORD id = 	threadIDs[len_threadIDs-1];
	if (id==0) 	return -1;
	static NP thisnp;
	thisnp.length = length;
	thisnp.nChan = nChan;
	thisnp.nProgReport = nProgReport;
	thisnp.playBuffer = dataBuffer;
	thisnp.DevID = DevID;
	if(PostThreadMessage(id, WM__SETNEXTPLAY, (WPARAM)&thisnp, 0)==0)
	{
		if (GetLastError()==1444) //Invalid thread identifier
		{
			while(PostThreadMessage(id, WM__SETNEXTPLAY, (WPARAM)&thisnp, 0)==0)
			{ Sleep(30);}
		}
	}
	return 0;
}

int wavBuffer2snd(UINT DevID, SHORT *dataBuffer, int length, int nChan, int fs, UINT userDefinedMsgID, HWND hApplWnd, int nProgReport, int loop, char *errstr)
// userDefinedMsgID == 0 : blocking (synchronous)
{	
	PARAM4sndplay param;
	param.dataBuffer = dataBuffer;
	param.DevID = DevID;
	param.fs = fs;
	param.hApplWnd = hApplWnd;
	param.length = length;
	param.nChan = nChan;
	param.nProgReport = nProgReport;
	param.userDefinedMsgID = userDefinedMsgID;
	param.callingthreadID = GetCurrentThreadId ();
	pbparam.push_back(param);

//	if (mt==NULL)  mt = CreateMutex(0,0,0);

	if (loop)
	{
		threadIDs[len_threadIDs++] = GetThreadId ( (HANDLE) _beginthreadex(NULL, 0, Thread4MM, NULL, NULL, 0));
		continuePlay(DevID, dataBuffer, length, nChan, userDefinedMsgID, nProgReport, errstr);
		LoopPlay(1);
	}
	else
		threadIDs[len_threadIDs++] = GetThreadId ( (HANDLE) _beginthreadex(NULL, 0, Thread4MM, NULL, NULL, 0));

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		switch(msg.message)
		{
		case MM_ERROR:
			strcpy(errstr, (char*)msg.lParam);
			return (int)msg.wParam;
		case MM_DONE:
			if (msg.wParam==OK)
				return 0;
			else
				return (int)msg.lParam;
		}
	}
	// Does the while loop above ever exit? 3/18/2017 bjkwon
	return 0;
}

//DO NOT CALL PlayBufAsynch16 DIRECTLY FROM OUTSIDE.... IT WILL CRASH AS IT TRIES TO FREE dataBuffer
// Instead, call the member function PlayArray to play something.

int PlayBufAsynch16(UINT DevID, short *dataBuffer, int length, int nChan, int fs, UINT userDefinedMsgID, HWND hApplWnd, int nProgReport, int loop, char* errstr)
// loop play when nProgReport == -1
{
	if (nProgReport==-1 && userDefinedMsgID==0)
		userDefinedMsgID = WM_USER+293;	// default message for event notification
	return wavBuffer2snd(DevID, dataBuffer, length, nChan, fs, userDefinedMsgID, hApplWnd, nProgReport, loop, errstr);
}

EXP_CS void TerminatePlay()
{
	if (len_threadIDs==0 || threadIDs[len_threadIDs-1]==0) return;
	PostThreadMessage(threadIDs[len_threadIDs-1], WM__STOP, 0, 1); //
	threadIDs[len_threadIDs---1]=0;
}

EXP_CS DWORD WinMMGetVolume()
{
	DWORD dw;
	MMRESULT res = waveOutGetVolume(pWP->hwo, &dw);
	if (res!=MMSYSERR_NOERROR) return dw;
	else		return res;
}


EXP_CS void PauseResumePlay(void *pWavePlay, bool fOnOff)
{
	if (pWavePlay==NULL) return;
	bool fFound = false;
	CWavePlay *pWP = (CWavePlay *)pWavePlay;
	//for (map<WAVEHDR *, CWavePlay *>::iterator it=mapWavePlays.begin(); it!=mapWavePlays.end(); ++it)
	//	if (it->second == pWP)
	//		fFound = true;
	//if (!fFound)
	//	return;
	int rc;
	if (fOnOff)
		rc = waveOutRestart(pWP->hwo);
	else
		rc = waveOutPause(pWP->hwo);
	if (rc!=MMSYSERR_NOERROR)
		SendMessage (pWP->hWnd_calling, pWP->msgID, 0xFFFF, (LPARAM)rc);
}

EXP_CS void TerminateLoop(void *pWavePlay)
{
	CWavePlay *pWP = (CWavePlay *)pWavePlay;
	waveOutBreakLoop(pWP->hwo);
}

#endif // NO_PLAYSND



// LOGGING1
//#ifdef LOGGING
//	SYSTEMTIME lt;
//	char buf[256];
//    GetLocalTime(&lt);	
//	FILE *fp=fopen("Playlog.txt","at");
//	sprintf(buf, "[%02d:%02d:%02d] (Entering OnBlockDone) (%d, %x), curPt=%d.\n", lt.wHour, lt.wMinute, lt.wSecond, id, this, curPt);  LOG(buf)
//	fclose(fp);
//#endif
//// LOGGING2
//#ifdef LOGGING
//		fp=fopen("Playlog.txt","at");
//		sprintf(buf, "[%02d:%02d:%02d] waveOutWrite() success. curPt=%d.\n", lt.wHour, lt.wMinute, lt.wSecond, curPt);  LOG(buf)
//		fclose(fp);
//#endif
//// LOGGING3
//#ifdef LOGGING
//		fp=fopen("Playlog.txt","at");
//		sprintf(buf, "[%02d:%02d:%02d] going to cleanup.\n", lt.wHour, lt.wMinute, lt.wSecond);  LOG(buf)
//		fclose(fp);
//#endif
//// LOGGING4
//#ifdef LOGGING
//	SYSTEMTIME lt;
//	char buf[256];
//    GetLocalTime(&lt);	
//	FILE *fp=fopen("Playlog.txt","at");
//	sprintf(buf, "[%02d/%02d/%4d, %02d:%02d:%02d]\n", lt.wMonth, lt.wDay, lt.wYear, lt.wHour, lt.wMinute, lt.wSecond);  LOG(buf)
//	sprintf(buf, "\t(wavBuffer2snd) calling threadID=%d, pWP:%x, length=%d\n", pWP->callingThreadID, pWP, param->length);  LOG(buf)
//	if (ch)
//		sprintf(buf, "\t\t thread ID=%d created\n", pWP->threadID), LOG(buf)
//	else
//		sprintf(buf, "\t\t thread ID=%d found\n", pWP->threadID), LOG(buf)
//	sprintf(buf, "\tcurProcPt=%d, Entering initial double-buffer...\n", pWP->curPt);  LOG(buf)
//	fclose(fp);
//#endif
//// LOGGING5
//#ifdef LOGGING
//	fp=fopen("Playlog.txt","at");
//	sprintf(buf, "[%02d:%02d:%02d] curPt=%d. Initial double-buffer success.\n", lt.wHour, lt.wMinute, lt.wSecond, pWP, pWP->curPt);
//	fclose(fp);
//#endif