// WndDlg.h: interface for the CWndDlg class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(CWndDlg_DEFINED)
#define CWndDlg_DEFINED

#include <windows.h>
#include <StdString.h>

class CWndDlg  
{
public:
	HWND GetDlgItem(int nIDDlgItem) {return ::GetDlgItem(hDlg,nIDDlgItem); };
	void GetLastErrorStr(char *errstr);
	void GetLastErrorStr(CStdString &errstr);
	int PostMessage(UINT Msg, WPARAM wParam = NULL, LPARAM lParam = NULL);
	LRESULT SendMessage(UINT Msg, WPARAM wParam = NULL, LPARAM lParam = NULL);
	int SetDlgItemText(int idc, LPCTSTR str) const;
	int SetDlgItemInt(int idc, UINT uValue, BOOL bSigned=0) const;
	int MessageBox (LPCTSTR lpszText, LPCTSTR lpszCaption = NULL, UINT nType = MB_OK);
	LRESULT SendDlgItemMessage(int nIDDlgItem, UINT Msg, WPARAM wParam=NULL, LPARAM lParam=NULL);
	int GetDlgItemInt(int idc, BOOL* lpTranslated=NULL, int bSigned=0) const;
	int GetDlgItemText(int idc, CStdString& strOut) const;
	int GetDlgItemText(int idc, char *strOut, int len) const;
	LONG SetWindowLong(int nIndex, LONG dwNewLong);
	LONG GetWindowLong(int nIndex);
	UINT_PTR SetTimer(UINT_PTR nIDEvent, UINT uElapse, TIMERPROC lpTimerFunc);
	BOOL KillTimer(UINT_PTR nIDEvent);
	void OnCommand(int idc, HWND hwndCtl, UINT event);
	void OnClose();
	virtual int OnInitDialog(HWND hwndFocus, LPARAM lParam);
	CWndDlg* hParent;
	HWND hDlg;
	HINSTANCE hInst;
	CWndDlg();
	virtual ~CWndDlg();

};


#endif // !defined(CWndDlg_DEFINED)
