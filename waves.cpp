#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <process.h>
#include "sigplus_internal.h"

//FYI: These two message are sent to different threads.
#define WM__RETURN			WM_APP+10

HWND hMainAppl(NULL);

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
{char errstr[256]; sprintf (errstr,"Error at "#x); MessageBox(NULL, errstr, "thread4MM",0); return rc;}}

#define LOG(X) fprintf(fp,(X));

typedef struct 
{
	VOID*	playBuffer;
	int		length;
	int		nChan;
	int		nProgReport;
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
		for (int i=0; i<2 && (rc=waveOutUnprepareHeader(hwo, wh+i, sizeof(WAVEHDR)))==MMSYSERR_NOERROR; ++i)
			;
		if (rc==MMSYSERR_NOERROR)
			rc = waveOutClose(hwo);
		if (rc==MMSYSERR_NOERROR) {
			if (blockMode)
				PostThreadMessage (callingThreadID, WM__RETURN, OK, 0);
		} else {
			SendMessage (hWnd_calling, msgID, 0xFFFF, (LPARAM)rc);
			PostThreadMessage (callingThreadID, WM__RETURN, ERR, (LPARAM)rc);
		}
		for (size_t k=buffer2Clean.size()-1; k>0; k--)
		{
			if (buffer2Clean.back() == buffer2Clean[k-1])
				buffer2Clean.pop_back();
		}
		for (UINT k=0; k<buffer2Clean.size(); k++)
			delete[] buffer2Clean[k];

		PostThreadMessage (callingThreadID, WM_APP+11, 0, 0);
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

#ifdef LOGGING
	SYSTEMTIME lt;
	char buf[256];
    GetLocalTime(&lt);	
	FILE *fp=fopen("Playlog.txt","at");
	sprintf(buf, "[%02d:%02d:%02d] (Entering OnBlockDone) (%d, %x), curPt=%d.\n", lt.wHour, lt.wMinute, lt.wSecond, id, this, curPt);  LOG(buf)
	fclose(fp);
#endif
	if (stopped)  
	{	SendMessage (hWnd_calling, msgID, 0, ReportIndex);	return cleanUp(1); }
	if (++ReportIndex>=0 && !blockMode) 	
		SendMessage (hWnd_calling, msgID, curPt/wfx.nChannels, ReportIndex+1);
	if (curPt<totalSamples)
	{  // blockLen could be all the same if it is not integer. In reality, because it is integer, there will be 
		// some leftover if blockLen always the same as playBufferLen. So the last block should be treated differently.
		if (totalSamples-curPt>=2*playBufferLen) 
			blockLen = playBufferLen;
		else
			blockLen = totalSamples-curPt;
		fillDataBuffer (lpwh, curPt, blockLen);
		rc = waveOutPrepareHeader (hwo, lpwh, sizeof(WAVEHDR));
		if (rc==MMSYSERR_NOERROR)
			rc = waveOutWrite (hwo, lpwh, sizeof(WAVEHDR));
		if (rc!=MMSYSERR_NOERROR)
		{
			SendMessage (hWnd_calling, msgID, 0xFFFF, (LPARAM)rc);
			PostThreadMessage (callingThreadID, WM__RETURN, ERR, (LPARAM)rc);
			return -1;
		}
		curPt += blockLen;
#ifdef LOGGING
		fp=fopen("Playlog.txt","at");
		sprintf(buf, "[%02d:%02d:%02d] waveOutWrite() success. curPt=%d.\n", lt.wHour, lt.wMinute, lt.wSecond, curPt);  LOG(buf)
		fclose(fp);
#endif
		return 0;
	}
	else if (nextPlay.size()>0)
	{
		playnextchunk(errstr);
		return 0;
	}
	else // curPt must be equal to totalSamples
	{
#ifdef LOGGING
		fp=fopen("Playlog.txt","at");
		sprintf(buf, "[%02d:%02d:%02d] going to cleanup.\n", lt.wHour, lt.wMinute, lt.wSecond);  LOG(buf)
		fclose(fp);
#endif
		return cleanUp();
	}
}


int CWavePlay::playnextchunk(char *errstr)
{
	MMRESULT	rc;
	int nSamplesInBlock; // this is per each channel
	NP thisnp = nextPlay.at(nextPlay.size()-1);

	playBuffer = thisnp.playBuffer;
	// then 
	wfx.nChannels		= thisnp.nChan;
	wfx.nBlockAlign		= 2 * wfx.nChannels;
	wfx.nAvgBytesPerSec	= wfx.nSamplesPerSec * wfx.nBlockAlign;
	totalSamples = thisnp.length * wfx.nChannels;
	nSamplesInBlock = thisnp.length / max(thisnp.nProgReport,1);
	playBufferLen = nSamplesInBlock * wfx.nChannels;

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

unsigned int WINAPI Thread4MM (PVOID p)
{
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
	pWP->callingThreadID = 0xFFFF;
	pWP->threadID = GetCurrentThreadId ();

	pWP->wfx.nChannels		= param.nChan;
	pWP->wfx.wFormatTag		= WAVE_FORMAT_PCM;
	pWP->wfx.nSamplesPerSec	= param.fs;
	pWP->wfx.nBlockAlign		= 2 * param.nChan;
	pWP->wfx.nAvgBytesPerSec	= pWP->wfx.nSamplesPerSec * pWP->wfx.nBlockAlign;
	pWP->wfx.wBitsPerSample	= 16;
	pWP->wfx.cbSize			= 16;

	MMCHECK_THREAD(waveOutOpen (&pWP->hwo, param.DevID, &pWP->wfx, (DWORD_PTR)pWP->threadID, (DWORD_PTR)545, CALLBACK_THREAD))

	pWP->totalSamples = param.length * param.nChan;
	nSamplesInBlock = param.length / max(param.nProgReport,1);
	pWP->playBufferLen = nSamplesInBlock * param.nChan;
	pWP->callingThreadID = param.callingthreadID;

	pWP->stopped = false;

	// Initiate playing after double-buffering, any leftover is processed in hMmBase
	pWP->curPt = 0;

#ifdef LOGGING
	SYSTEMTIME lt;
	char buf[256];
    GetLocalTime(&lt);	
	FILE *fp=fopen("Playlog.txt","at");
	sprintf(buf, "[%02d/%02d/%4d, %02d:%02d:%02d]\n", lt.wMonth, lt.wDay, lt.wYear, lt.wHour, lt.wMinute, lt.wSecond);  LOG(buf)
	sprintf(buf, "\t(wavBuffer2snd) calling threadID=%d, pWP:%x, length=%d\n", pWP->callingThreadID, pWP, param->length);  LOG(buf)
	if (ch)
		sprintf(buf, "\t\t thread ID=%d created\n", pWP->threadID), LOG(buf)
	else
		sprintf(buf, "\t\t thread ID=%d found\n", pWP->threadID), LOG(buf)
	sprintf(buf, "\tcurProcPt=%d, Entering initial double-buffer...\n", pWP->curPt);  LOG(buf)
	fclose(fp);
#endif
	for (int i=0; i<2; i++) // if playBufferLen is odd, the first and second will be even-odd order.
	{ // if its multi-channel(i.e., stereo), playBufferLen must be multiple of nChan, otherwise left-right channels might be swapped around in the middle
		pWP->fillDataBuffer (pWP->wh+i, pWP->curPt, pWP->playBufferLen);
		pWP->curPt += pWP->playBufferLen;
		pWP->playBufferLen = (pWP->totalSamples-pWP->playBufferLen) / max((param.nProgReport-1),1); //only meaningful within this loop (only for when i=1)
		pWP->wh[i].dwLoops=0;
		if (i==0) pWP->wh[i].dwFlags |= WHDR_BEGINLOOP;
		else pWP->wh[i].dwFlags |= WHDR_ENDLOOP;
		MMCHECK_THREAD(waveOutPrepareHeader (pWP->hwo, pWP->wh+i, sizeof(WAVEHDR)))
		MMCHECK_THREAD(waveOutWrite (pWP->hwo, pWP->wh+i, sizeof(WAVEHDR)))
		if (i==0) rc=waveOutPause(pWP->hwo);
		else  rc=waveOutRestart(pWP->hwo);
	}

#ifdef LOGGING
	fp=fopen("Playlog.txt","at");
	sprintf(buf, "[%02d:%02d:%02d] curPt=%d. Initial double-buffer success.\n", lt.wHour, lt.wMinute, lt.wSecond, pWP, pWP->curPt);
	fclose(fp);
#endif
	 // IMPORTANT--DO NOT ASSUME THAT pWP->playBuffer == param->dataBuffer in a multithread environment.
	pWP->buffer2Clean.push_back((SHORT*)pWP->playBuffer);
//	pWP->buffer2Clean.push_back(param->dataBuffer);
	// pWP->buffer2Clean.push_back(param->dataBuffer) will lead to an incorrect pointer and proper buffer is not stored and something else might be stored twice, which will crash the application. 7/11/2016 bjk
	
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
			SendMessage (hMainAppl, WM_APP+WOM_OPEN, 0, 0);
			break;
		case WOM_CLOSE:
			SendMessage (pWP->hWnd_calling, pWP->msgID, 0, -1);
			SendMessage (hMainAppl, WM_APP+WOM_CLOSE, 0, 0);
			break;
		case WOM_DONE:
			// For a multiple sound playback, when one sound is finished, WM_APP+WOM_CLOSE is sent and the STOP button in showvarDlg is disabled even though the other sound is still playing. 
			// Ideal solution: track each instance of sound playback and don't send WM_APP+WOM_CLOSE until the last playback is finished----seems complicated
			// Quick solution: Send WM_APP+WOM_OPEN again whenever WOM_DONE is posted, so that the STOP button gets enabled back and the user would see the button blink, which is kind of an OK extra feature.
			// 7/11/2016 bjk
			SendMessage (hMainAppl, WM_APP+WOM_OPEN, 0, 0);
			// End of Quick solution
			pWP->OnBlockDone((WAVEHDR *)msg.lParam);
			break;
		case WM__SETNEXTPLAY:
			SendMessage (hMainAppl, WM_APP+WOM_OPEN, 0, 0);
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

void continuePlay(UINT DevID, SHORT *dataBuffer, int length, int nChan, UINT userDefinedMsgID, int nProgReport, char *errstr)
{
	DWORD id = 	threadIDs[len_threadIDs-1];
	if (id==0) 	return;
	static NP thisnp;
	thisnp.length = length;
	thisnp.nChan = nChan;
	thisnp.nProgReport = nProgReport;
	thisnp.playBuffer = dataBuffer;
	if(PostThreadMessage(id, WM__SETNEXTPLAY, (WPARAM)&thisnp, 0)==0)
	{
		if (GetLastError()==1444)
		{
			while(PostThreadMessage(id, WM__SETNEXTPLAY, (WPARAM)&thisnp, 0)==0)
			{ Sleep(30);}
		}
	}
}

int wavBuffer2snd(UINT DevID, SHORT *dataBuffer, int length, int nChan, int fs, UINT userDefinedMsgID, HWND hApplWnd, int nProgReport, int loop, char *errstr)
// userDefinedMsgID == 0 : blocking (synchronous)
{	
	PARAM4sndplay param;
	if (waveOutGetNumDevs()<=DevID)
	{	strcpy(errstr, "Specified audio device not available.");	return -8;	}

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

	if (loop)
	{
		threadIDs[len_threadIDs++] = GetThreadId ( (HANDLE) _beginthreadex(NULL, 0, Thread4MM, NULL, NULL, 0));
		continuePlay(DevID, dataBuffer, length, nChan, userDefinedMsgID, nProgReport, errstr);
		LoopPlay(1);
	}
	else
		threadIDs[len_threadIDs++] = GetThreadId ( (HANDLE) _beginthreadex(NULL, 0, Thread4MM, NULL, NULL, 0));


	//MSG msg;
	//if (pWP->blockMode)
	//{
	//	while (GetMessage(&msg, NULL, 0, 0))
	//	{
	//		if (msg.message==WM__RETURN)
	//		{
	//			if (msg.wParam==OK)
	//				return 0;
	//			else
	//				return (int)msg.lParam;
	//		}
	//	}
	//	return -1;
	//}
	//else
		return 0;
}


//DO NOT CALL PlayBufAsynch16 DIRECTLY FROM OUTSIDE.... IT WILL CRASH AS IT TRIES TO FREE dataBuffer
// Instead, call the member function PlayArray to play something.



void PlayBufAsynch16(UINT DevID, short *dataBuffer, int length, int nChan, int fs, UINT userDefinedMsgID, HWND hApplWnd, int nProgReport, int *errcode, int loop, char* errstr)
// loop play when nProgReport == -1
{
	int ecode;
	if (nProgReport==-1 && userDefinedMsgID==0)
		userDefinedMsgID = WM_USER+293;	// default message for event notification
	if ((ecode= wavBuffer2snd(DevID, dataBuffer, length, nChan, fs, userDefinedMsgID, hApplWnd, nProgReport, loop, errstr))!=MMSYSERR_NOERROR) {
		*errcode = ecode;
	} 
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

EXP_CS void SetHWND_SIGPROC(HWND h)
{
	hMainAppl = h;
}

EXP_CS HWND GetHWND_SIGPROC()
{
	return hMainAppl;
}