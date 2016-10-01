// WndDlg.cpp: implementation of the CWndDlg class.
//
//////////////////////////////////////////////////////////////////////

#include "WndDlg.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWndDlg::CWndDlg()
: hDlg(NULL)
{

}

CWndDlg::~CWndDlg()
{

}

int CWndDlg::OnInitDialog(HWND hwndFocus, LPARAM lParam)
{
	return 1;
}

void CWndDlg::OnClose()
{
	PostQuitMessage(0);
}

UINT_PTR CWndDlg::SetTimer(UINT_PTR nIDEvent, UINT uElapse, TIMERPROC lpTimerFunc)
{
	return ::SetTimer(hDlg, nIDEvent, uElapse, lpTimerFunc);
}

BOOL CWndDlg::KillTimer(UINT_PTR nIDEvent)
{
	return ::KillTimer(hDlg, nIDEvent);
}

void CWndDlg::OnCommand(int idc, HWND hwndCtl, UINT event)
{
	switch(idc)
	{
	case IDCANCEL:
		::SendMessage (hDlg, WM_CLOSE, 0, 0);
		break;
	}
}

int CWndDlg::SetDlgItemText(int idc, LPCTSTR str) const
{
	return ::SetDlgItemText(hDlg, idc, str);
}

int CWndDlg::SetDlgItemInt(int idc, UINT uValue, BOOL bSigned) const
{
	return ::SetDlgItemInt(hDlg, idc, uValue, bSigned);
}

int CWndDlg::GetDlgItemText(int idc, char *strOut, int len) const
{
	return ::GetDlgItemText(hDlg, idc, strOut, len);
}

int CWndDlg::GetDlgItemText(int idc, CStdString &strOut) const
{
	int res, size=MAX_PATH;
	char *buf=new char[size];
	res = ::GetDlgItemText (hDlg, idc, buf, size);
	while (res==size-1)
	{
		delete[] buf;
		size *=2;
		buf=new char[size];
		res = ::GetDlgItemText (hDlg, idc, buf, size);
	}
	strOut = buf;
	delete[] buf;
	return res;
}

int CWndDlg::GetDlgItemInt(int idc, BOOL *lpTranslated, int bSigned) const
{
	return ::GetDlgItemInt(hDlg, idc, lpTranslated, bSigned);
}

LRESULT CWndDlg::SendDlgItemMessage(int nIDDlgItem, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	return ::SendDlgItemMessage(hDlg, nIDDlgItem, Msg, wParam, lParam);
}

int CWndDlg::MessageBox (LPCTSTR lpszText, LPCTSTR lpszCaption, UINT nType)
{
	return ::MessageBox (hDlg, lpszText, lpszCaption, nType);
}

LRESULT CWndDlg::SendMessage(UINT Msg, WPARAM wParam, LPARAM lParam)
{
	return ::SendMessage (hDlg, Msg, wParam, lParam);
}

int CWndDlg::PostMessage(UINT Msg, WPARAM wParam, LPARAM lParam)
{
	return ::PostMessage (hDlg, Msg, wParam, lParam);
}

void CWndDlg::GetLastErrorStr(CStdString &errstr)
{
	char  string[256];

	GetLastErrorStr(string);
	errstr = string;
	return;
}

LONG CWndDlg::SetWindowLong(int nIndex, LONG dwNewLong) 
{
	return ::SetWindowLong(hDlg, nIndex, dwNewLong);
}

LONG CWndDlg::GetWindowLong(int nIndex) 
{
	return ::GetWindowLong(hDlg, nIndex);
}

void CWndDlg::GetLastErrorStr(char *errstr)
{
	DWORD WindowsError, nchar;
	WindowsError = GetLastError();

	nchar = FormatMessage( FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
							NULL, WindowsError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
							(LPTSTR) errstr, sizeof(errstr), NULL  );
	if (nchar == 0)	MessageBox ("Failed to translate Windows error");
}