#ifndef AUX_NO_EXTRA

#include "graffy.h"
#include "psycon.tab.h"
#include "audfret.h"
#include <process.h>

#define WM_PLOT_DONE	WM_APP+328
#define MARKERSTR	"o+*.xsd^v<>ph"
#define COLORSTR	"ymcrgbwk"

extern HWND hAppl;


HANDLE plotline;
HANDLE mutex;
uintptr_t hTread;

AUDFRET_EXP void ReplaceStr(string &str, const char *from, const char *to) { ReplaceStr(str, string(from), string(to)); }

int graffyLoaded=0;
HMODULE hLib;
void checkNumArgs(const AstNode *pnode, const AstNode *p, const char** FuncSigs, const int minArgs, const int maxArgs);

CSignals fourth, third, first, second;
DWORD colordw;
double blocksize;

void aux_plotThread (PVOID var);

void blockCell(const AstNode *pnode, CSignals &checkthis);
void blockScalar(const AstNode *pnode, CSignals &checkthis);
void blockString(const AstNode *pnode, CSignals &checkthis);
void checkString(const AstNode *pnode, CSignals &checkthis, string addmsg);

typedef  void (_cdecl  *PFUN_DEL) (HANDLE h);
typedef  HANDLE  (_cdecl *PFUN_OPEN) (RECT*, const CSignals &, HWND, int, double);
typedef  HANDLE  (_cdecl *PFUN_ADDAX) (HANDLE, double, double, double, double);
typedef  HANDLE  (_cdecl *PFUN_PLOTCSIGNALS1) (HANDLE, CSignals &, COLORREF col, char, LineStyle);
typedef  HANDLE  (_cdecl *PFUN_PLOTCSIGNALS11) (HANDLE, CSignal &, COLORREF col, char, LineStyle);
typedef  HANDLE  (_cdecl *PFUN_PLOTCSIGNALS2) (HANDLE, CSignals &, CSignals &, COLORREF, char, LineStyle);
typedef  HWND  (_cdecl *PFUN_GetHWND_PlotDlg) (HANDLE);

PFUN_DEL fp_deleteObj(NULL);
PFUN_OPEN fp_OpenFigure(NULL);
PFUN_ADDAX fp_AddAxis(NULL);
PFUN_PLOTCSIGNALS1 fp_PlotCSignals1(NULL);
PFUN_PLOTCSIGNALS11 fp_PlotCSignals11(NULL);
PFUN_PLOTCSIGNALS2 fp_PlotCSignals2(NULL);
PFUN_GetHWND_PlotDlg fp_GetHWND_PlotDlg(NULL);

int getmonitorheight (HWND hDlg)
{
	HMONITOR monitor = MonitorFromWindow(hDlg, MONITOR_DEFAULTTONEAREST);
	MONITORINFO info;
	info.cbSize = sizeof(MONITORINFO);
	GetMonitorInfo(monitor, &info);
	int monitor_width = info.rcMonitor.right - info.rcMonitor.left;
	int monitor_height = info.rcMonitor.bottom - info.rcMonitor.top;
	return monitor_height;
}

void graffytype2string(graffytype type, char *outBuf)
{
	switch(type)
	{
	case 'r':
		strcpy(outBuf, "root");
		break;
	case 'f':
		strcpy(outBuf, "figure");
		break;
	case 'a':
		strcpy(outBuf, "axis");
		break;
	case 't':
		strcpy(outBuf, "text");
		break;
	case 'p':
		strcpy(outBuf, "patch");
		break;
	case 'l':
		strcpy(outBuf, "line");
		break;
	case 'k':
		strcpy(outBuf, "tick");
		break;
	default:
		strcpy(outBuf, "");
	}
}

map<string, LineStyle> linestylelist;
map<char, int> linemarkerlist;
map<char, DWORD> linecolorlist;
multimap<char, string> graffyprop;

void initGraffyProperties()
{
	graffyprop.insert(make_pair('r',string("parent")));
	graffyprop.insert(make_pair('f',string("parent")));
	graffyprop.insert(make_pair('a',string("parent")));
	graffyprop.insert(make_pair('t',string("parent")));
	graffyprop.insert(make_pair('l',string("parent")));
	graffyprop.insert(make_pair('r',string("children")));
	graffyprop.insert(make_pair('f',string("children")));
	graffyprop.insert(make_pair('a',string("children")));
	graffyprop.insert(make_pair('t',string("children")));
	graffyprop.insert(make_pair('l',string("children")));
	graffyprop.insert(make_pair('r',string("pos")));
	graffyprop.insert(make_pair('f',string("pos")));
	graffyprop.insert(make_pair('a',string("pos")));
	graffyprop.insert(make_pair('t',string("pos")));
	graffyprop.insert(make_pair('l',string("pos")));
	graffyprop.insert(make_pair('r',string("color")));
	graffyprop.insert(make_pair('f',string("color")));
	graffyprop.insert(make_pair('a',string("color")));
	graffyprop.insert(make_pair('t',string("color")));
	graffyprop.insert(make_pair('l',string("color")));
	graffyprop.insert(make_pair('r',string("visible")));
	graffyprop.insert(make_pair('f',string("visible")));
	graffyprop.insert(make_pair('a',string("visible")));
	graffyprop.insert(make_pair('t',string("visible")));
	graffyprop.insert(make_pair('l',string("visible")));
	graffyprop.insert(make_pair('r',string("type")));
	graffyprop.insert(make_pair('f',string("type")));
	graffyprop.insert(make_pair('a',string("type")));
	graffyprop.insert(make_pair('t',string("type")));
	graffyprop.insert(make_pair('l',string("type")));

	//add new properties at the end of each type as needed

	graffyprop.insert(make_pair('a',string("axiscolor")));
	graffyprop.insert(make_pair('a',string("xlim")));
	graffyprop.insert(make_pair('a',string("ylim")));

	graffyprop.insert(make_pair('t',string("fontsize")));
	graffyprop.insert(make_pair('t',string("fontname")));
	graffyprop.insert(make_pair('t',string("fontangle")));
	graffyprop.insert(make_pair('t',string("fontweight")));
	graffyprop.insert(make_pair('t',string("string")));
	graffyprop.insert(make_pair('t',string("horizontalalignment")));
	graffyprop.insert(make_pair('t',string("verticalalignment")));

	graffyprop.insert(make_pair('l',string("xdata")));
	graffyprop.insert(make_pair('l',string("ydata")));
	graffyprop.insert(make_pair('l',string("marker")));
	graffyprop.insert(make_pair('l',string("markersize")));
	graffyprop.insert(make_pair('l',string("linestyle")));
	graffyprop.insert(make_pair('l',string("linewidth")));

}

void GetLineStyle (LineStyle out, string &in)
{
	for(map<string, LineStyle>::iterator it=linestylelist.begin(); it!=linestylelist.end(); it++)
		if (it->second == out) {in = it->first; return;}
}

void EnumGraffyProperties(char type, vector<string> &propname)
{
	propname.clear();
	pair <multimap<char,string>::iterator, multimap<char,string>::iterator> ret = graffyprop.equal_range(type);
	for (multimap<char,string>::iterator it=ret.first; it!=ret.second; ++it)
		propname.push_back(it->second);
}

void EnumGraffyTypesfromProp(string propname, vector<char> &type)
{
	type.clear();
	for(multimap<char,string>::iterator it=graffyprop.begin(); it!=graffyprop.end(); it++)
		if (it->second == propname) type.push_back(it->first);
}

void SetPropVal(CAstSig &ast, const AstNode *pnode, CGobj *hobj, string propname, CSignals in)
{
	vector<char> types;
	string revstr(propname);
	reverse_copy(begin(propname), end(propname), begin(revstr));
	EnumGraffyTypesfromProp(propname, types);
	if (propname=="parent" || propname=="children" || propname=="type")
		throw CAstException(pnode, string("Cannot modify ") +string("\"") + propname + string("\" property."));
	else if (propname=="pos")
	{
		if (in.GetType()!=CSIG_VECTOR)	throw CAstException(pnode, string("Invalid argument for ") + propname);
		switch(hobj->type)
		{
		case 'f':
		{
			HWND hDlg = hobj->m_dlg->hDlg;
			if (in.nSamples!=4)	throw CAstException(pnode, string("Invalid number of argument for ") + propname);
			int monitorH = getmonitorheight (hDlg);
			int left = (int)in.buf[0];
			int top = monitorH - (int)(in.buf[1]+in.buf[3]);
			int width = (int)in.buf[2];
			int height = (int)in.buf[3];
			SetWindowPos(hDlg, 0, left, top, width, height, SWP_NOZORDER);
			break;
		}
		case 'a':
			if (in.nSamples!=4)	throw CAstException(pnode, string("Invalid number of argument for ") + propname);
			hobj->setPos(in.buf[0], in.buf[1], in.buf[2], in.buf[3]);
			break;
		case 't':
			if (in.nSamples!=2)	throw CAstException(pnode, string("Invalid number of argument for ") + propname);
			hobj->setPos(in.buf[0], in.buf[1], 0, 0);
			break;
		}
	}
	else if (propname=="visible")
	{
		if (in.GetType()!=CSIG_SCALAR)	throw CAstException(pnode, string("\"") + propname + string("\" requires a scalar value."));
		hobj->visible = !(in.value()==0);
	}
	else if (propname=="axiscolor")
	{
		if (hobj->type!='a') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for an axis object"));
		BYTE r = (BYTE)(in.buf[0]*(double)0xff+.5);
		BYTE g = (BYTE)(in.buf[1]*(double)0xff+.5);
		BYTE b = (BYTE)(in.buf[2]*(double)0xff+.5);
		((CAxis*)hobj)->colorAxis = RGB(r,g,b);
	}
	else if (propname=="color")
	{
		BYTE r = (BYTE)(in.buf[0]*(double)0xff+.5);
		BYTE g = (BYTE)(in.buf[1]*(double)0xff+.5);
		BYTE b = (BYTE)(in.buf[2]*(double)0xff+.5);
		hobj->color = RGB(r,g,b);
	}
	else if (propname=="xlim")
	{
		if (hobj->type!='a') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for an axis object"));
		int nItems = in.nSamples;
		if (nItems!=2) throw CAstException(pnode, string("\"") + propname + string("\" requires a two-element vector."));
		memcpy(((CAxis*)hobj)->xlim, in.buf, sizeof(((CAxis*)hobj)->xlim));
	}
	else if (propname=="ylim")
	{
		if (hobj->type!='a') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for an axis object"));
		int nItems = in.nSamples;
		if (nItems!=2) throw CAstException(pnode, string("\"") + propname + string("\" requires a two-element vector."));
		memcpy(((CAxis*)hobj)->ylim, in.buf, sizeof(((CAxis*)hobj)->ylim));
	}
	else if (propname.substr(0,4)=="font" || propname=="string" || revstr.substr(0,strlen("alalignment"))=="tnemngilala")
	{
		if (hobj->type!='t') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for a text object"));
		bool donehere(false);
		if (propname=="fontsize")
		{
			if (in.GetType()!=CSIG_SCALAR)	throw CAstException(pnode, string("\"") + propname + string("\" requires a scalar value."));
			donehere=true, ((CText*)hobj)->fontsize = (int)in.value();
		}
		else if (propname.substr(0,4)=="font" || propname=="string" || revstr.substr(0,strlen("alalignment"))=="tnemngilala")
		{
			if (in.GetType()!=CSIG_STRING) throw CAstException(pnode, string("\"") + propname + string("\" requires a string input."));
			if (propname=="fontname")		donehere=true, strcpy(((CText*)hobj)->fontname, in.string().c_str());
			else if (propname=="fontangle")		donehere=true, ((CText*)hobj)->italic = (in.string()=="italic") ? true : false;
			else if (propname=="fontweight")	donehere=true, ((CText*)hobj)->bold = (in.string()=="bold") ? true : false;
			else if (propname=="fontunderline")	donehere=true, ((CText*)hobj)->underline = (in.string()=="underline") ? true : false;
			else if (propname=="fontstrike")	donehere=true, ((CText*)hobj)->strikeout = (in.string()=="strikeout") ? true : false;
			else if (propname=="string")		((CText*)hobj)->str = in.string();
			else	
			{
				if (propname=="horizontalalignment")	
				{
					if (in.string()=="left" || in.string()=="center" || in.string()=="right")
						((CText*)hobj)->SetAlignment(in.string().c_str());
					else
						throw CAstException(pnode, string("\"") + in.string() + string("\": invalid property value for property \"") + propname + string("\"."));
				}
				else if (propname=="verticalalignment")	
				{
					if (in.string()=="baseline" || in.string()=="bottom" || in.string()=="top")
						((CText*)hobj)->SetAlignment(in.string().c_str());
					else
						throw CAstException(pnode, string("\"") + in.string() + string("\": invalid property value for property \"") + propname + string("\"."));
				}
				else
					throw CAstException(pnode, string("\"") + propname + string("\": invalid property name."));
			}
		}
		if (donehere)
		{
			DWORD style(0);
			if (((CText*)hobj)->italic) style |= FONT_STYLE_ITALIC;
			if (((CText*)hobj)->bold) style |= FONT_STYLE_BOLD;
			if (((CText*)hobj)->underline) style |= FONT_STYLE_UNDERLINE;
			if (((CText*)hobj)->strikeout) style |= FONT_STYLE_STRIKEOUT;
			if (((CText*)hobj)->ChangeFont(((CText*)hobj)->fontname, ((CText*)hobj)->fontsize, style)==NULL) 
				throw CAstException(pnode, string("\"") + propname + string("\": Error in CreateFont."));
		}
	}
	else if (propname=="marker")
	{
		if (hobj->type!='l') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for a line object"));
		if (in.GetType()!=CSIG_STRING)	throw CAstException(pnode, string("\"") + propname + string("\" requires a character value"));
		if ( in.string().length()!=1 || !strpbrk(MARKERSTR, in.string().c_str())) throw CAstException(pnode, string("\"") + propname + string("\" requires a character from the following:  ") + string(MARKERSTR));
		((CLine*)hobj)->symbol = in.string().c_str()[0];
	}  
	else if (propname=="markersize")
	{
		if (hobj->type!='l') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for a line object"));
		if (in.GetType()!=CSIG_SCALAR)	throw CAstException(pnode, string("\"") + propname + string("\" requires a scalar value."));
		((CLine*)hobj)->markersize = (unsigned int)in.value();
	}
	else if (propname=="linewidth")
	{
		if (hobj->type!='l') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for a line object"));
		if (in.GetType()!=CSIG_SCALAR)	throw CAstException(pnode, string("\"") + propname + string("\" requires a scalar value."));
		((CLine*)hobj)->lineWidth = (unsigned int)in.value();
	}
	else	
		CAstException(pnode, string("\"") + propname + string("\": invalid property name."));
}

int GetPropVal(CAstSig &ast, const AstNode *pnode, CGobj *hobj, string propname, CSignals &out)
{
	char buf[64];
	vector<char> types;
	EnumGraffyTypesfromProp(propname, types);
	string revstr(propname);
	reverse_copy(begin(propname), end(propname), begin(revstr));
	if (propname=="parent")
	{
		out.UpdateBuffer(1);
		if (!hobj->hPar) out.Reset();
		else if (hobj->hPar->type!='f')
			out.buf[0] = (double)(int)hobj->hPar;
		else
		{
			int figID;
			HWND hDlg = fp_GetHWND_PlotDlg(hobj->hPar);
			if (hDlg==NULL) throw CAstException(pnode, string("(Unanticipated) fp_GetHWND_PlotDlg error...") + propname);
			GetWindowText(hDlg, buf, sizeof(buf));
			if (!strncmp(buf, "Figure ", strlen("Figure ")))
			{
				if (sscanf(buf+strlen("Figure "), "%d", &figID)>0)	
					out.buf[0] = (double)figID;
				else throw CAstException(pnode, string("(Unanticipated) sscanf error after Figure...") + propname);
			}
			else
			{
				if (strlen(buf)>0)	out.SetString(buf);
				else throw CAstException(pnode, string("(Unanticipated) Figure window with no caption...") + propname);
			}
		}
	}
	else if (propname=="children")
	{
		out.UpdateBuffer(hobj->child.size());
		for (size_t k=0; k<hobj->child.size(); k++)
			out.buf[k] = (double)(int)hobj->child[k];
	}
	else if (propname=="pos")
	{
		out.UpdateBuffer(4);
		switch(hobj->type)
		{
		case 'f':
			{
			HWND hDlg = fp_GetHWND_PlotDlg(hobj);
			RECT rt;
			GetWindowRect(hDlg, &rt);
			int monitorH = getmonitorheight (hDlg);
			out.buf[0] = rt.left;			out.buf[1] = monitorH - rt.bottom;
			out.buf[2] = rt.right-rt.left;	out.buf[3] = rt.bottom - rt.top;
			}
			break;
		case 't':
			out.UpdateBuffer(2);
			out.buf[0] = hobj->pos.x0;		out.buf[1] = hobj->pos.y0;
			break;
		default:
			out.buf[0] = hobj->pos.x0;		out.buf[1] = hobj->pos.y0;
			out.buf[2] = hobj->pos.width;	out.buf[3] = hobj->pos.height;
			break;
		}
	}
	else if (propname=="color")
	{
		out.UpdateBuffer(3);
		BYTE r = GetRValue(hobj->color);
		BYTE g = GetGValue(hobj->color);
		BYTE b = GetBValue(hobj->color);
		out.buf[0] = (double)r/(double)0xff;
		out.buf[1] = (double)g/(double)0xff;
		out.buf[2] = (double)b/(double)0xff;
	}
	else if (propname=="visible")
	{
		out.UpdateBuffer(1);
		int vis = hobj->visible;
		out.buf[0] = (double)vis;
	}
	else if (propname=="type")
	{
		graffytype2string(hobj->type, buf);
		out.SetString(buf);
	}
	else if (propname=="axiscolor")
	{
		if (hobj->type!='a') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for an axis object"));
		out.UpdateBuffer(3);
		BYTE r = GetRValue(((CAxis*)hobj)->colorAxis);
		BYTE g = GetGValue(((CAxis*)hobj)->colorAxis);
		BYTE b = GetBValue(((CAxis*)hobj)->colorAxis);
		out.buf[0] = (double)r/(double)0xff;
		out.buf[1] = (double)g/(double)0xff;
		out.buf[2] = (double)b/(double)0xff;
	}
	else if (propname=="xlim")
	{
		if (hobj->type!='a') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for an axis object"));
		out.UpdateBuffer(2);
		memcpy(out.buf, ((CAxis*)hobj)->xlim, sizeof(((CAxis*)hobj)->xlim));
	}
	else if (propname=="ylim")
	{
		if (hobj->type!='a') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for an axis object"));
		out.UpdateBuffer(2);
		memcpy(out.buf, ((CAxis*)hobj)->ylim, sizeof(((CAxis*)hobj)->ylim));
	}
	else if (propname.substr(0,4)=="font" || propname=="string" || revstr.substr(0,strlen("alalignment"))=="tnemngilala")
	{
		if (hobj->type!='t') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for a text object"));
		if (propname=="fontsize")
			out.SetValue(((CText*)hobj)->fontsize);
		else if (propname=="fontname")
			out.SetString(((CText*)hobj)->fontname);
		else 
		{
			strcpy(buf,"normal");
			if (propname=="fontangle") {
				if (((CText*)hobj)->italic) strcpy(buf,"italic"); }
			else if (propname=="fontweight") {
				if (((CText*)hobj)->bold) strcpy(buf,"bold"); }
			else if (propname=="fontstrike") {
				if (((CText*)hobj)->strikeout) strcpy(buf,"strikeout");	}
			else if (propname=="fontunderline") {
				if (((CText*)hobj)->underline) strcpy(buf,"underline"); }
			else if (propname=="string")
				out.SetString(((CText*)hobj)->str.c_str());
			else if (propname=="horizontalalignment" || propname=="verticalalignment")
			{
				string hori, vert;
				((CText*)hobj)->GetAlignment(hori, vert);
				if (propname=="horizontalalignment") strcpy(buf, hori.c_str());
				else							strcpy(buf, vert.c_str());		
			}
			else
				throw CAstException(pnode, string("\"") + propname + string("\": invalid property name."));
			out.SetString(buf);
		}
	}
	else if (propname=="xdata")
	{// this will not work when xdata is not given specifically
		if (hobj->type!='l') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for a line object"));
		out.UpdateBuffer(((CLine*)hobj)->orglength());
		memcpy(out.buf, ((CLine*)hobj)->xdata, ((CLine*)hobj)->orglength());
	}
	else if (propname=="ydata")
	{ // check this
		if (hobj->type!='l') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for a line object"));
		out = ((CLine*)hobj)->sig;
	}
	else if (propname=="marker")
	{
		if (hobj->type!='l') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for a line object"));
		out.SetString(((CLine*)hobj)->symbol);
	}
	else if (propname=="markersize")
	{
		if (hobj->type!='l') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for a line object"));
		out.SetValue(((CLine*)hobj)->markersize);
	}
	else if (propname=="linestyle")
	{
		if (hobj->type!='l') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for a line object"));
		GetLineStyle(((CLine*)hobj)->lineStyle, revstr);
		out.SetString(revstr.c_str());
	}
	else if (propname=="linewidth")
	{
		if (hobj->type!='l') throw CAstException(pnode, string("\"") + propname + string("\" is valid only for a line object"));
		out.SetValue(((CLine*)hobj)->lineWidth);
	}
	else if (propname=="axis")
	{
		if (hobj->type=='f')
		{
			CFigure *cfig = static_cast<CFigure *>(hobj);
			out.UpdateBuffer(cfig->ax.size());
			for (size_t k=0; k<cfig->ax.size(); k++)
				out.buf[k] = (double)(int)cfig->ax[k];
		}
		else
			out.Reset();
	}
	else if (propname=="text")
	{
		if (hobj->type=='f')
		{
			CFigure *cfig = static_cast<CFigure *>(hobj);
			out.UpdateBuffer(cfig->text.size());
			for (size_t k=0; k<cfig->text.size(); k++)
				out.buf[k] = (double)(int)cfig->text[k];
		}
		else
			out.Reset();
	}	
	else if (propname=="line")
	{
		if (hobj->type=='a')
		{
			CAxis *pax = static_cast<CAxis *>(hobj);
			out.UpdateBuffer(pax->m_ln.size());
			for (size_t k=0; k<pax->m_ln.size(); k++)
				out.buf[k] = (double)(int)pax->m_ln[k];
		}
		else
			out.Reset();
	}	
	else
	{
		throw CAstException(pnode, string("\"") + propname + string("\" is not a valid property name."));
	}
	ast.Sig = out;
	return 1;
}

void initLineList()
{
	linestylelist["(none)"] = LineStyle_noline; //no line
	linestylelist["-"] = LineStyle_solid; //solid line
	linestylelist["--"] = LineStyle_dash; //dashed line
	linestylelist[":"] = LineStyle_dot; //dotted line
	linestylelist["-."] = LineStyle_dashdot; //dash-dot line

	linemarkerlist[' '] = 0; // no marker
	linemarkerlist['o'] = 'o'; // circle
	linemarkerlist['+'] = '+'; // plus
	linemarkerlist['*'] = '*'; // asterisk
	linemarkerlist['.'] = '.'; // point
	linemarkerlist['x'] = 'x'; // cross
	linemarkerlist['s'] = 's'; // square
	linemarkerlist['d'] = 'd'; // diamond
	linemarkerlist['^'] = '^'; // triangle1
	linemarkerlist['v'] = 'v'; // triangle2
	linemarkerlist['>'] = '>'; // triangle3
	linemarkerlist['<'] = '<'; // triangle
	linemarkerlist['p'] = 'p'; // pentagram
	linemarkerlist['h'] = 'h'; // hexagram

	linecolorlist['y'] = RGB(255,255,0); // yellow
	linecolorlist['m'] = RGB(255,0,255); // magenta
	linecolorlist['c'] = RGB(0,255,255); // cyan
	linecolorlist['r'] = RGB(255,0,0); // red
	linecolorlist['g'] = RGB(0,255,0); // green
	linecolorlist['b'] = RGB(0,0,255); // blue
	linecolorlist['k'] = RGB(0,0,0); // black
	linecolorlist['w'] = RGB(255,255,255); // white 
}

void getLineSpecifier (const AstNode *pnode, string input, LineStyle &ls, int &mk, DWORD &col)
{ // markcol is set only if marker is drawn but no line is drawn (
	size_t id;
	string input2(input);
	ReplaceStr(input, "-.", "__");
	if (input.length() > 4)
		throw CAstException(pnode, "line format specifier cannot be longer than 4 characters.");
	id = input.find_first_of(COLORSTR);
	if (id!=string::npos) col = linecolorlist[input[id]], input.erase(id,1);
	else					col = RGB(0,0,0); // default: black
	while ((id=input.find_first_of(COLORSTR))!=string::npos) {
		throw CAstException(pnode, "more than two characters for line color");
		input.erase(id,1);
	}
	id = input.find_first_of(MARKERSTR);
	if (id!=string::npos) mk = linemarkerlist[input[id]], input.erase(id,1);
	else				mk = 0; // default: no marker
	while ((id=input.find_first_of(MARKERSTR))!=string::npos) {
		throw CAstException(pnode, "more than two characters for marker");
		input.erase(id,1);
	}
	ReplaceStr(input, "__", "-.");
	if (input.length()==0)	ls = LineStyle_noline;
	else if (input=="-" || input=="--" || input==":" || input=="-.")
		ls = linestylelist[input];
	else
		throw CAstException(pnode, (input + string("Invalid line style specifier")).c_str());

	if (input2.find_first_of(MARKERSTR)==string::npos) //marker is specified but
		if (input=="-" || input=="--" || input==":" || input=="-.") // linestyle is not
			ls = linestylelist["-"]; // set it solid 
}

#define LOADPF(OUT, DEFTYPE, FUNCSIGNATURE) if ((OUT = (DEFTYPE)GetProcAddress((HMODULE)hLib, FUNCSIGNATURE))==NULL) {char buf[64]; sprintf(buf, "cannot find %s", FUNCSIGNATURE); MessageBox(NULL, "LOADPF error", buf, 0); return 0;}
#define LOADPF2(OUT, DEFTYPE, INDEX, SIMPLESIGNATURE) if ((OUT = (DEFTYPE)GetProcAddress((HMODULE)hLib, (char*)INDEX))==NULL) {char buf[64]; sprintf(buf, "cannot find %s", SIMPLESIGNATURE); MessageBox(NULL, "LOADPF2 error", buf, 0); return 0;}

//HANDLE _OpenFigure(RECT *rt, const CSignals &data, int devID, double block);

DWORD double2RGB(double color[3])
{
	WORD r,g,b;
	r = (WORD)(color[0]*255.);
	g = (WORD)(color[1]*255.);
	b = (WORD)(color[2]*255.);
	DWORD out = b*0x10000 + g *0x100 + r;
	return out;
}

/*From now on, Make sure to update this function whenever functions are added/removed in graffy.cpp 
7/15/2016 bjk
*/
int LoadGRAFFY()
{
	char path[MAX_PATH], procname[MAX_PATH];
	GetCurrentProcInfo(path, procname, NULL);
#ifndef WIN64
	hLib = LoadLibrary(strcat(path, "graffy32.dll")); // fix this.... if the path has been changed in the middle, we are no longer in AppPath
	LOADPF(fp_AddAxis, PFUN_ADDAX, "?AddAxis@@YAPAXPAXNNNN@Z");
	LOADPF(fp_OpenFigure, PFUN_OPEN, "?OpenFigure@@YAPAXPAVCRect@Win32xx@@ABVCSignals@@PAUHWND__@@HN@Z");
	LOADPF(fp_PlotCSignals1, PFUN_PLOTCSIGNALS1, "?PlotCSignals@@YAPAXPAXAAVCSignals@@KDW4LineStyle@@@Z");
	LOADPF(fp_PlotCSignals2, PFUN_PLOTCSIGNALS2, "?PlotCSignals@@YAPAXPAXAAVCSignals@@1KDW4LineStyle@@@Z");
	LOADPF(fp_deleteObj, PFUN_DEL, "?deleteObj@@YAXPAX@Z");
	LOADPF(fp_GetHWND_PlotDlg, PFUN_GetHWND_PlotDlg, "?GetHWND_PlotDlg@@YAPAUHWND__@@PAX@Z");
#else
	hLib = LoadLibrary(strcat(path, "graffy64.dll")); // fix this.... if the path has been changed in the middle, we are no longer in AppPath
	LOADPF(fp_AddAxis, PFUN_ADDAX, "?AddAxis@@YAPEAXPEAXNNNN@Z");
	LOADPF(fp_OpenFigure, PFUN_OPEN, "?OpenFigure@@YAPEAXPEAVCRect@Win32xx@@AEBVCSignals@@PEAUHWND__@@HN@Z");
	LOADPF(fp_PlotCSignals1, PFUN_PLOTCSIGNALS1, "?PlotCSignals@@YAPEAXPEAXAEAVCSignals@@KDW4LineStyle@@@Z");
	LOADPF(fp_PlotCSignals2, PFUN_PLOTCSIGNALS2, "?PlotCSignals@@YAPEAXPEAXAEAVCSignals@@1KDW4LineStyle@@@Z");
	LOADPF(fp_deleteObj, PFUN_DEL, "?deleteObj@@YAXPEAX@Z");
	LOADPF(fp_GetHWND_PlotDlg, PFUN_GetHWND_PlotDlg, "?GetHWND_PlotDlg2@@YAPEAUHWND__@@PEAX@Z");
#endif
	
	fp_PlotCSignals11 = (PFUN_PLOTCSIGNALS11)fp_PlotCSignals1;
	initLineList();
	initGraffyProperties();
	vector<string> out;
	EnumGraffyProperties('f',out);
	graffyLoaded=1;
	return 1;
}

CGobj *aux_getset(CAstSig &ast, const AstNode *pnode, const AstNode *p0, const AstNode *pnext, string &propname)
{
	CGobj *hobj;
	if (!graffyLoaded)	if (!LoadGRAFFY()) throw CAstException(pnode, "Failed to load graffy.dll for plot");
	CSignals first, second;
	first = ast.Compute(p0);
	if ( first.GetType()!=CSIG_SCALAR && first.GetType()!=CSIG_STRING)
		throw CAstException(pnode, "1st argument must be the index (scalar) or an array of index (vector) or string of the variable of the figure window");
	if (!(hobj = (CGobj *)GCF(&first))) 	//if first does not indicate a figure window ID.
		if (!(hobj = (CGobj *)GetGraffyHandle((int)first.value()))) 
			throw CAstException(pnode, "1st argument is not a valid graphic object identifier.");
	if (pnext) //do this only needed (e.g., close() does not need this)
	{
		second=ast.Compute(pnext);
		if ( propname.length()==0 && second.GetType()!=CSIG_STRING )
			throw CAstException(pnode, "2nd argument must be string of the property.");
		propname = second.string();
	}
	return hobj;
}


void aux_set(CAstSig &ast, const AstNode *pnode, const AstNode *p0)
{
	int nArgs(0);
	for (const AstNode *cp(p0); cp; cp=cp->next)	++nArgs;
	if ((nArgs/2)*2 == nArgs) // if nArgs is even, error.
		throw CAstException(pnode, "set(graphic_identifier, propertyname1, propertyval1, propertyname2, propertyval2,...)");
	CSignals third, out;
	string propname;
	CGobj *hobj;
	for(const AstNode *p(p0->next); p ; p = p->next->next)
	{
		hobj = aux_getset (ast, pnode, p0, p, propname);
		third=ast.Compute(p->next);
		SetPropVal(ast, pnode, hobj, propname, third);
	}
	InvalidateRect(hobj->m_dlg->hDlg, NULL, TRUE);
}

void aux_get(CAstSig &ast, const AstNode *pnode, const AstNode *p0)
{
	CGobj *hobj;
	string propname("");
	int nArgs(0);
	for (const AstNode *cp(p0); cp; cp=cp->next)	++nArgs;

	if (nArgs==1)
	{
		vector<string> props;
		hobj = aux_getset (ast, pnode, p0, NULL, propname);
		EnumGraffyProperties(hobj->type, props);
		for (vector<string>::iterator it=props.begin(); it!=props.end(); it++)
			ast.AddCell("ans", CSignal(*it));
	}
	else if (nArgs==2)
	{
		CSignals out;
		const AstNode *p(p0->next);
		hobj = aux_getset (ast, pnode, p0, p, propname);
		GetPropVal(ast, pnode, hobj, propname, out);
	}
	else
		throw CAstException(pnode, "1st argument: graffic object, 2nd argument: propery_name");
}

void aux_delete_single(CAstSig &ast, const AstNode *pnode, const AstNode *p, CSignal &tp)
{
	if ( tp.GetType()!=CSIG_SCALAR && tp.GetType()!=CSIG_STRING)
		throw CAstException(pnode, "1st argument must be the index (scalar) or an array of index (vector) or string of the variable of the figure window");
	CGobj *hobj;
	if (!(hobj = (CGobj *)GetGraffyHandle((int)tp.value()))) 
		throw CAstException(pnode, "1st argument is not a valid graphic object identifier.");
	fp_deleteObj(hobj);
	InvalidateRect(fp_GetHWND_PlotDlg(hobj), NULL, TRUE);
}

void aux_delete(CAstSig &ast, const AstNode *pnode, const AstNode *p, CSignal *carry)
{
	CGobj *hobj(NULL);
	CSignals tp;
	if (carry==NULL)
	{
		if (!graffyLoaded)	if (!LoadGRAFFY()) throw CAstException(pnode, "Failed to load graffy.dll for plot");
		const char *fnsigs[] = {"(graffy object(s) to delete)", 0};
		checkNumArgs(pnode, p, fnsigs, 1, 1);
		tp=ast.Compute(p);
	}
	else
		tp = *carry;
	if (tp.GetType()==CSIG_AUDIO || tp.GetType()==CSIG_EMPTY)
		throw CAstException(pnode, "Argument must be a scalar or an array or cell array of the graffy object to delete.");
	if (tp.GetType()==CSIG_CELL)
	{
		for (size_t k=0; k<tp.cell.size(); k++)
		{
			if (tp.cell[k].GetType()==CSIG_AUDIO || tp.cell[k].GetType()==CSIG_EMPTY)
				throw CAstException(pnode, "Argument must be a scalar or an array or cell array of the graffy object to delete.");
		}
		vector<HANDLE> hobj2del;
		CSignals tpp;
		for (size_t k=0; k<tp.cell.size(); k++)
		{
			if (tp.GetType()==CSIG_STRING)
				tpp.SetString(tp.string().c_str());
			else
				tpp = tp.buf[k];
			hobj2del.push_back(GCF(&tpp));
		}
		for (size_t k=0; k<tp.cell.size(); k++)
			aux_delete(ast, pnode, p, &tp.cell[k]);
		return;
	}
	for (int k=0; k<tp.nSamples; k++)
	{ // if vector, all must be figure or non-figure
		CSignals tpp;
		if (tp.GetType()==CSIG_STRING)
			tpp.SetString(tp.string().c_str());
		else
			tpp = tp.buf[k];
		CGobj *hobj0(hobj);
		hobj = (CGobj *)GCF(&tpp);
		if (k>0 && !hobj0 && hobj)
			throw CAstException(pnode, "Aarray argument must be all figure or all non-figure.");
	}
	if (hobj) // figures to delete
	{
		vector<HANDLE> hobj2del;
		CSignals tpp;
		for (int k=0; k<tp.nSamples; k++)
		{
			if (tp.GetType()==CSIG_STRING)
				tpp.SetString(tp.string().c_str());
			else
				tpp = tp.buf[k];
			hobj2del.push_back(GCF(&tpp));
		}
		//the above and below for loop should be separated... or CGF will not work properly while figure is deleted.
		for (int k=0; k<tp.nSamples; k++)	PostMessage(fp_GetHWND_PlotDlg(hobj2del[k]), WM_CLOSE, 0, 0);
	}
	else
	{
		for (int k=0; k<tp.nSamples; k++)
		{
			CSignal carry;
			carry.SetValue(tp.buf[k]);
			aux_delete_single(ast, pnode, p, carry);
		}
	}
}

void aux_close(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	if (!graffyLoaded)	if (!LoadGRAFFY()) throw CAstException(pnode, "Failed to load graffy.dll for plot");
	const char *fnsigs[] = {"(figure ID(s) to delete)", 0};
	checkNumArgs(pnode, p, fnsigs, 1, 1);
	CSignals tp=ast.Compute(p);
	const AstNode *p0(p->next);
	CGobj *hobj = aux_getset (ast, pnode, p, p0, string("dummy"));
	if (hobj->type=='f')
		aux_delete(ast, pnode, p, NULL);
	else
		throw CAstException(pnode, "Argument must be the index (scalar) or an array of index (vector) or string of the variable to delete figure window");
}

void aux_text(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{ // text (x, y, "string")
	if (!graffyLoaded)	if (!LoadGRAFFY()) throw CAstException(pnode, "Failed to load graffy.dll for plot");
	const char *fnsigs[] = {"(figure ID(s) to delete)", 0};
	checkNumArgs(pnode, p, fnsigs, 3, 3);
	CSignals *gcf = ast.RetrieveTag("gcf");
	if (gcf==NULL) 	throw CAstException(pnode, "gcf not ready (There is no plot window to draw text)");
	CSignals first, second, third;
	first = ast.Compute(p);
	second = ast.Compute(p->next);
	third = ast.Compute(p->next->next);
	if (first.GetType()!=CSIG_SCALAR || second.GetType()!=CSIG_SCALAR) throw CAstException(pnode, "First two arguments must be scalar.");
	if (third.GetType()!=CSIG_STRING) throw CAstException(pnode, "Third argument must be string.");
	HANDLE h = GCF(gcf);
	HANDLE hText = AddText(h, third.string().c_str(), first.value(), second.value(), 0, 0);
	ast.Sig.SetValue((double)(int)hText);
	InvalidateRect(fp_GetHWND_PlotDlg(h), NULL, TRUE);
}

CAstSig *mainast;

void aux_plot(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	mainast = &ast;
	if (!graffyLoaded)	if (!LoadGRAFFY()) throw CAstException(pnode, "Failed to load graffy.dll for plot");
	
	if (mutex==NULL) mutex = CreateMutex(0, 0, 0);
//	dw = WaitForSingleObject(mutex, INFINITE);

	// plot(audio), plot(x,y), plot(x,y,"specifiers") such as plot(x,y,"co:") (cyan, marker o, dotted line)
	// plot(nonaudio, "*") : x axis is just the index of the array
//	memset(color, 0, sizeof(double)*3);
	const char *fnsigs[] = {
		"(vector_x, vector_y)", 0};
	checkNumArgs(pnode, p, fnsigs, 1, 3);

	int nArgs(0);
	for (const AstNode *cp=p; cp; cp=cp->next)		++nArgs;
	if (nArgs==1) {
		blockCell(pnode,  ast.Compute(p));
		blockString(pnode,  ast.Compute(p));
		blockScalar(pnode,  ast.Compute(p));
	}

	static	CSignals dumma;
	static	vector<CSignals> args;
	args.clear();
//	blocksize = ast.pEnv->GetPlayBlockSize();
	dumma.SetValue(nArgs);
	for (int k=0; k<nArgs; k++) 
		args.push_back(dumma);
	switch(nArgs)
	{
	case 3:
		args[2] = ast.Compute(p->next->next);
		checkString(pnode, args[2], "Third argument--");
	case 2:
		args[1] = ast.Compute(p->next);
	case 1:
		args[0] = ast.Compute(p);
		break;
	}
	int marker;
	LineStyle linestyle;
	DWORD col;
	switch(nArgs)
	{
	case 3:
		if (args[2].nSamples>4) throw CAstException(pnode, p->next, fnsigs, "String argument must be 4 characters or less.");
	case 2:// both signals must be non-audio
		if ( (args[0].GetType()==CSIG_VECTOR && args[1].GetType()==CSIG_VECTOR) ) 
		{
			if (args[0].nSamples != args[1].nSamples)
				throw CAstException(pnode, p->next, fnsigs, "The length of 1st and 2nd arguments must be the same.");
		}
		else
		{
			if (args[0].GetType()!=CSIG_AUDIO && args[0].GetType()!=CSIG_VECTOR) 
				throw CAstException(pnode, p->next, fnsigs, "1st argument must be audio or non-audio.");
			if (args[1].GetType()!=CSIG_STRING)
				throw CAstException(pnode, p->next, fnsigs, "When two arguments are specified and 2nd arg is not vector or audio, 2nd arg must be plot style string.");
		}
//		args[nArgs-1].getString(buf, 64); // debuggin purposes only
		break;
	}
	if (nArgs<3 && args[nArgs-1].GetType()!=CSIG_STRING) args.push_back(dumma), args.back().SetString("-b");
	getLineSpecifier (pnode, args.back().string(), linestyle, marker, col); // check if the line format string is valid
	CSignals threadID((double)GetCurrentThreadId());
	args.push_back(threadID);
	HANDLE hTread = CreateThread (NULL, 0, (LPTHREAD_START_ROUTINE) aux_plotThread, (LPVOID)&args, 0, NULL);
	MSG         msg ;
	while (GetMessage (&msg, NULL, 0, 0))
	{
		switch (msg.message)
		{
		case WM_PLOT_DONE:
			ast.Sig.SetValue((double)(int)plotline);
			HANDLE h = (HANDLE)msg.wParam;
			CSignals gcf;
			GetFigID(h, gcf);
			ast.SetTag("gcf", gcf);
			return;
		}
	}

}

void aux_plotThread (PVOID var)
{
	DWORD dw;
	HANDLE fig;

	dw = WaitForSingleObject(mutex, INFINITE);
	vector<CSignals> *args;

	args = (vector<CSignals> *)var;
	int marker;
	LineStyle linestyle;
	DWORD col;
	int nargs = (int)args[0].size();
	DWORD callingthread = (DWORD)args[0][--nargs].value();
	switch(nargs)
	{
	case 3:
		third = args[0][2];
	case 2: 
		second = args[0][1];
	case 1:
		first = args[0][0];
		break;
	}
	CSignals plotstyle = args[0][--nargs];
	MSG         msg ;
	HANDLE ax;
	CRect rt(0, 0, 500, 280);
	fig = fp_OpenFigure(&rt, first, GetHWND_SIGPROC(), 0, blocksize); // blocksize is ignored here 7/15/2016 bjk
	ax = fp_AddAxis (fig, .08, .2, .86, .75);
	getLineSpecifier (NULL, plotstyle.string(), linestyle, marker, col); // we know that this will always succeed, so pnode can be NULL
	switch(nargs)
	{
	case 1:
		plotline = fp_PlotCSignals1(ax, first, col, marker, linestyle);
		if (first.next)
			fp_PlotCSignals11(ax, *first.next, RGB(200,0,50), 0, linestyle);
		break;
	case 3:
	case 4:
	case 2:
		plotline = fp_PlotCSignals2(ax, first, second, col, marker, linestyle); 
		break;
	}
	HWND hr = GetConsoleWindow();
	HWND h = SetFocus(fp_GetHWND_PlotDlg(fig));
	ReleaseMutex(mutex);
	HACCEL hAcc = GetAccel(fig);
	CFigure *cfig = static_cast<CFigure *>(fig);
	HWND hFigDlg = fp_GetHWND_PlotDlg((HANDLE)cfig);
	PostThreadMessage(callingthread, WM_PLOT_DONE, (WPARAM)fig, 0);
	while (GetMessage (&msg, NULL, 0, 0))
	{ 
		if (msg.message==WM_DESTROY || !cfig->m_dlg)	break;
		if (msg.hwnd && !IsWindow(msg.hwnd)) 	break;
		if (msg.message==WM_KEYDOWN && msg.wParam==17 && GetParent(msg.hwnd)==hFigDlg)
			msg.hwnd = hFigDlg;
		if (!TranslateAccelerator (cfig->m_dlg->hDlg, hAcc, &msg))
		{
			TranslateMessage (&msg) ;
			DispatchMessage (&msg) ;
		}
	}
	if (mutex!=NULL) {CloseHandle(mutex); mutex=NULL;}
	fp_deleteObj(ax);
	fp_deleteObj(fig);
}

#endif
