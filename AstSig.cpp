#include <sstream>
#include <list>
#include <exception>
#include <math.h>
#include <time.h>
#include "sigproc.h"
#include "audfret.h"

#ifndef CISIGPROC
#include "psycon.tab.h"
#else
#include "cipsycon.tab.h"
#endif

/* NOTE 9/23/2017
Don't use------- throw CAstException(p, this, "error message");
when p->type is NODE_XXXXXX, because it will make an error msg like 

ERROR: NODE_EXTRACT : variable not available.

which is not helpful to users.
*/


#ifdef XCOM

#ifndef CISIGPROC  

class xcom
{
public:
	vector<CAstSig*> vecast;
	vector<const AstNode*> vecnodeUDF;

	vector<string> history;
	size_t nHistFromFile;
	size_t comid; // command ID
	char AppPath[256];
	INPUT_RECORD debug_command_frame[6];
	string comPrompt;

	xcom();
	virtual ~xcom();
	void console();
	void gendebugcommandframe();
	bool isdebugcommand(INPUT_RECORD *in, int len);
	void getinput(char* readbuffer);
	size_t ReadHist();
	void ShowWS_CommandPrompt(CAstSig *pcast);
	int computeandshow(const char *input, const AstNode *pCall=NULL);
	int cleanup_debug();
	void showarray(const AstNode *pnode);
	int ClearVar(const char *var);
	int load_axl(FILE *fp, char *errstr);
	int save_axl(FILE *fp, const char * var, char *errstr);
	void out4console(string varname, CSignals *psig, string &out);
	size_t ctrlshiftright(const char *buf, DWORD offset);
	size_t ctrlshiftleft(const char *buf, DWORD offset);
	int hook(CAstSig *ast, string HookName, const char* args);
	void LogHistory(vector<string> input);
	bool debugcommand(const char* cmd);
	bool dbmapfind(const char* udfname);
	int breakpoint(CAstSig *past, const AstNode *pnode);
	void debug_appl_manager(const CAstSig *debugAstSig, int debug_status, int line=-1);
	bool IsThisBreakpoint(CAstSig *past, const AstNode *pnode);
};

extern xcom mainSpace;
#endif
#endif // XCOM

void checkVector(const AstNode *pnode, CSignals &checkthis, string addmsg="");
void checkAudioSig(const AstNode *pnode, CSignals &checkthis, string addmsg="");
void blockCell(const AstNode *pnode, CSignals &checkthis);
void blockString(const AstNode *pnode, CSignals &checkthis);



#ifndef LINK_STATIC_SIGPROC
HMODULE hDllModule;
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	hDllModule = hModule;
	if (ul_reason_for_call == 1 || ul_reason_for_call == 2)
		srand((unsigned int)time(NULL) ^ (unsigned int)GetCurrentThreadId());
    return TRUE;
}
#endif

//DO NOT USE THIS MACRO for a negative input*********
#define INT(X) (int)(X+.5)

#ifdef _WINDOWS
#define GetTickCount0 GetTickCount
#else if
unsigned long GetTickCount0()
{
	return 0;
}
#endif

CAstSig::CAstSig(const CAstSig &org)
{
	throw "Internal error: Copy constructor is prohibited. You probably meant to call CAstSig(&env)." ;
}

//RECOMMENDED CONSTRUCTOR 1  7/8/2017
CAstSig::CAstSig(CAstSigEnv *env) // Use this constructor for auxlab. env has been defined prior to this.
: pAst(NULL), pCall(NULL), Script(""), statusMsg(""), fAllocatedAst(false), nextBreakPoint(0xffff), fExit(false), debugon(false), dstatus(null), pLast(NULL), son(NULL), dad(NULL), pEnv(env), CallbackCIPulse(NULL), CallbackHook(NULL)
{
}
//RECOMMENDED CONSTRUCTOR 2  7/8/2017
CAstSig::CAstSig(const CAstSig *src)
: pAst(NULL), pCall(NULL), Script(""), statusMsg(""), fAllocatedAst(false), nextBreakPoint(0xffff), fExit(false), debugon(false), dstatus(null), pLast(NULL), son(NULL), dad(NULL), CallbackCIPulse(NULL), CallbackHook(src->CallbackHook)
{
	Vars = src->Vars;
	if (src) {
		pEnv = src->pEnv;
	} else
		pEnv = new CAstSigEnv(DefaultFs);
}

CAstSig::CAstSig(const char *str, const CAstSig *src) // Used in auxfunc.cpp and psyntegDlgNIC.cpp
: pAst(NULL), pCall(NULL), Script(""), statusMsg(""), fAllocatedAst(false), nextBreakPoint(0xffff), fExit(false), debugon(false), dstatus(null), pLast(NULL), son(NULL), dad(NULL), CallbackCIPulse(NULL), CallbackHook(NULL)
{
	Vars = src->Vars;
	if (src) {
		pEnv = src->pEnv;
	} else
		pEnv = new CAstSigEnv(DefaultFs);
	SetNewScript(str);
}

CAstSig::CAstSig(const char *str, CAstSigEnv *env) // Used in dancer
: pAst(NULL), pCall(NULL), Script(""), statusMsg(""), fAllocatedAst(false), nextBreakPoint(0xffff), fExit(false), debugon(false), dstatus(null), pLast(NULL), son(NULL), dad(NULL), pEnv(env), CallbackCIPulse(NULL), CallbackHook(NULL)
{
	SetNewScript(str);
}

CAstSig::CAstSig(AstNode *pnode, const CAstSig *env)
: pAst(pnode), pCall(NULL), Script(""), statusMsg(""), fAllocatedAst(false), nextBreakPoint(0xffff), dstatus(null), pLast(NULL), son(NULL), dad(NULL), pEnv(env->pEnv), CallbackCIPulse(NULL), CallbackHook(env->CallbackHook)
{
}

CAstSig::CAstSig(AstNode *pnode, CAstSigEnv *env)
: pAst(pnode), pCall(NULL), Script(""), statusMsg(""), fAllocatedAst(false), nextBreakPoint(0xffff), dstatus(null), pLast(NULL), son(NULL), dad(NULL), pEnv(env), CallbackCIPulse(NULL), CallbackHook(NULL)
{
}

CAstSig::~CAstSig()
{
	if (fAllocatedAst)
		yydeleteAstNode(pAst, 0);
}

CAstSig &CAstSig::SetNewScript(const char *str, AstNode *pAstOut)
{
	int res;
	char *errmsg;
	if (strlen(str)==0) return *this;

	if (pAst && Script == str)
		return *this;
	if (fAllocatedAst) {
		yydeleteAstNode(pAst, 0);
		fAllocatedAst = false;
	}

	pAst = pCall = NULL;
	if ((res = yysetNewStringToScan(str)))
		throw "yysetNewStringToScan() failed!";

 	res = yyparse(&pAst, &errmsg);
	fAllocatedAst = pAst ? true : false;

	if (!errmsg && res == 2)
		errmsg = "Out of memory!";
	if (errmsg) {
		if (fAllocatedAst) {
			yydeleteAstNode(pAst, 0);
			fAllocatedAst = false;
			pAst = NULL;
		}
		throw errmsg;
	}
	else if (res)
		return *this;

	Script = str;
	if ((pAstOut!=NULL) && (pAst!=NULL)) 
		*pAstOut = *pAst;
	if (pAst->type==NODE_RESTRING) // remake the string here before calling Compute()
	{
		size_t leftdiv = Script.find(pAst->str); 
		string LHS(Script.substr(0, leftdiv)); // left hand side, to appear on the right side as well
		string oper(pAst->str); //operator with '=' at the end
		oper.replace(oper.find('='),1," ");
		string newstr(LHS + '=' + LHS);
		if (oper=="@@") newstr += oper + LHS; // just an exception 
		newstr += oper + Script.substr(leftdiv+strlen(pAst->str));
		return SetNewScript(newstr.c_str(), pAstOut);
	}
	return *this;
}


AstNode *CAstSig::SetNewScriptFromFile(const char *udf_filename, FILE *fp)
{
	if (fseek(fp, 0, SEEK_END)) throw "fseek error in SetNewScriptFromFile";
	long int fsize = ftell(fp);
	if (fseek(fp, 0, SEEK_SET)) throw "fseek error in SetNewScriptFromFile";
	char *buf = new char[fsize+1];
	memset(buf,0,fsize+1);
	if( fread(buf, fsize, 1, fp) ) 	throw "fread error in SetNewScriptFromFile";
	buf[fsize]=0;
	// Check if the content of udf file has changed; if so, set new script
	if (pEnv->UDF_body[udf_filename] != buf)
	{
		if (pEnv->UDF_body[udf_filename].size()>0)
			SendMessage(GetHWND_SIGPROC(), WM__DEBUG, (WPARAM)0, (LPARAM)udf_filename);
		SetNewScript(buf, NULL);
		pEnv->UDF_body[udf_filename] = buf;
	}
	else
	{
		pAst = pEnv->UDFs[udf_filename];
	}
	delete[] buf;
	return pAst;
}

// as long as CAstSig *past is used to construct CAstException, cleanup_sons() is called
// and necessary clean up is taken care of, upon exception thrown (error)
// Take care of CAstException constructors not using CAstSig *past... 

CAstException::CAstException(const AstNode *p, CAstSig *past, const string s1, const string s2)
: pAst(past), pnode(p), str1(s1), str2(s2), int1(0)
{
	makeOutStr();
}

CAstException::CAstException(const AstNode *p, CAstSig *past, const string s1, const int x, const string s2)
: pAst(past), pnode(p), str1(s1), str2(s2), int1(x)
{
	makeOutStr();
}

CAstException::CAstException(const AstNode *p, CAstSig *past, const char** FuncSigs, const string msg)
: pAst(past), pnode(p), int1(0)
{
	const string fname = p->str;
	string fnsig;
	for (int i=0; FuncSigs[i]; ++i)
		fnsig += "\n\t" + fname + FuncSigs[i];
	str1 = fname + "( ) " + msg + "\n Usage:" + fnsig;
	makeOutStr();
}

string GetNodeType(int type)
{ // from psycon.yacc.h
	switch(type)
	{
	case NODE_BLOCK:
		return "NODE_BLOCK";
	case NODE_ARGS:
		return "NODE_ARGS";
	case NODE_MATRIX:
		return "NODE_MATRIX";
	case NODE_VECTOR:
		return "NODE_VECTOR";
	case NODE_CALL:
		return "NODE_CALL";
	case NODE_FUNC:
		return "NODE_FUNC";
	case NODE_IDLIST:
		return "NODE_IDLIST";
	case NODE_EXTRACT:
		return "NODE_EXTRACT";
	case NODE_INITCELL:
		return "NODE_INITCELL";
	case NODE_IXASSIGN:
		return "NODE_IXASSIGN";
	case NODE_INTERPOL:
		return "NODE_INTERPOL";
	case NODE_RESTRING:
		return "NODE_RESTRING";

	case NODE_USEC:
		return "NODE_USEC";
	case NODE_MSEC:
		return "NODE_MSEC";
	case NODE_CIPULSE3:
		return "NODE_CIPULSE3";
	case NODE_CIPULSE4:
		return "NODE_CIPULSE4";
	case NODE_CIPULSE5:
		return "NODE_CIPULSE5";
	case NODE_CIPULSE6:
		return "NODE_CIPULSE6";
	default:
		return "Unknown NODE";
	}
}


CAstException::CAstException(const AstNode *p0, CAstSig *past, const char* msg)
: pAst(past), pnode(p0), int1(0)
{
	char buf[64];
	string unknown;
	if (p0->str)	unknown = p0->str;
	else {			// needed for calls from CSignals &CAstSig::Compute(const AstNode *pnode)
		if (p0->type>256) { sprintf(buf, "%s", GetNodeType(p0->type).c_str()); unknown = buf; }
		else			unknown = p0->type; 
	}
	str1 = " ";
	str1 += unknown + " : " + msg + "\n";
	outstr = str1;
	makeOutStr();
}


AstNode *_searchstr(AstNode *p, const char* pstr)
{ // if there's a node with "type" in the tree, return that node
	if (p)
	{
		if (p->str==pstr) return p;
		if (p->child)
			if (p->child->str==pstr) return p->child;
			else return _searchstr(p->child, pstr);
		else if (p->next)
			if (p->next->str==pstr) return p->next;
			else return _searchstr(p->next, pstr);
	}
	return NULL;
}

int _findcol(AstNode *past, const char* pstr, int line)
{
	for (AstNode *pn=past; pn; pn = pn->next)
	{
		if (pn->line<line) continue;
		AstNode *pm = _searchstr(pn->child, pstr);
		if (pm) return pm->col;
		else	return -1;
	}
	return -1;
}

void CAstException::makeOutStr()
{
	ostringstream oss;
	int res;
	oss << str1 + ' ';
	if (!str2.empty())
		oss << " \"" << str2 << "\" ";
	if (pAst)
	{
		vector<int> lines;
		vector<int> cols;
		cols.push_back(pnode->col);
		vector<string> strs;
		CAstSig *p = pAst;
		char *pstr=NULL;
		while (p)
		{
			if (p->pCall && (pstr = p->pCall->str) )
			{
				strs.push_back(pstr);
				if (p->pLast)
				{
					lines.push_back(p->pLast->line);
					if ((res = _findcol(p->pAst, pstr, p->pLast->line))>0)
						cols.push_back(res);
				}
			}
			p=p->dad;
		}
		if (!strs.empty())
		{
			vector<string>::iterator it2 = strs.begin()+1;
			vector<int>::iterator it3 = cols.begin();
			//at this point strs can have more items than lines and cols, because son->son is son during CallUDF()
			//so don't use strs iterator for for 
			for (vector<int>::iterator it=lines.begin(); it!=lines.end(); it++, it2++, it3++)
			{
				oss << '\n' << "line " << *it << ", col " << *it3 << " in [udf] " << *it2;
				if ((*it)==lines.back()) oss << ".aux";
			}
		}
	}
	else
		oss << "\nIn line " << pnode->line << ", col " << pnode->col;
	if (int1)
		oss << int1;
	outstr = oss.str();
	if (pAst->pAst && pAst->pAst->type==NODE_BLOCK) // pAst->pAst is checked to avoid crash during wavwrite(undefined_var,"filename")
		pAst->cleanup_sons();
}



bool GfInterrupted;	// needs to be global to interrupt even inside UDF
void CAstSig::interrupt(void)
{
	GfInterrupted = true;
}
bool CAstSig::isInterrupted(void)
{
	return GfInterrupted;
}


CSignals &CAstSig::Compute(void)
{
	Sig.cell.clear();
	try {
		if (!pAst)
			return Sig;
		GfInterrupted = false;
		Tick0 = GetTickCount0();
		if (pAst->type == NODE_BLOCK) {	// main workspace, scan for local functions
			AstNode *pp = NULL;
			for (AstNode *p=pAst->child; p;) {
				if (p->type == T_FUNCTION) {
					if (AstNode *pOld=RetrieveUDF(p->str))
						yydeleteAstNode(pOld, 0);	// delete AST tree of existing function with the same name
					pEnv->UDFs[p->str] = p;
					// detach it from pAst tree so that it will remain available even after pAst is replaced by SetNewScript()
					if (pp) {	// take p out of pAst tree
						pp->next = p->next;
						p->next = NULL;
						p = pp;
					} else {	// replacing head node (first line is function definition)
						pAst->child = p->next;
						p->next = NULL;
						p = pAst->child;
						continue;
					}
				}
				pp = p;
				p = p->next;
			}
		}
		Compute(pAst);
		Tick1 = GetTickCount0();
		return Sig;
	} catch (const CAstException &e) {
		char errmsg[2048];
		strncpy(errmsg, e.getErrMsg().c_str(), sizeof(errmsg)/sizeof(*errmsg));
		errmsg[sizeof(errmsg)/sizeof(*errmsg)-1] = '\0';
		throw errmsg;
	}
}


CSignals &CAstSig::Eval(AstNode *pnode)
{
	try {
		if (!pnode)
			return Sig;
		return Compute(pnode); 
	} catch (const CAstException &e) {
		char errmsg[500];
		strncpy(errmsg, e.getErrMsg().c_str(), sizeof(errmsg)/sizeof(*errmsg));
		errmsg[sizeof(errmsg)/sizeof(*errmsg)-1] = '\0';
		throw errmsg;
	}
}

AstNode *CAstSig::get_tree_on_line(const AstNode *pnode, int line)
{
	AstNode *p = (AstNode *)pnode;
	for (; p; p=p->next)
		if (p->line == line) return p;
	return p;
}


void CAstSig::CallUDF(int debug_status)
{	//pCall: AstNode when the actual calling was made in the calling workspace (except LHS, which is treated separately)
	//pUDF: AstNode created after ReadUDF ("formal" context--i.e., how the udf file was read with variables used in the file)
	//pOutParam: AstNode for formal output variable (or LHS), just used inside of this function.
	// Output parameter dispatching (sending the output back to the calling worksapce) is done with pOutParam and lhs at the bottom.

	vector<CSignals*> holder;
	vector<string> argout;
	AstNode *pUDF = pEnv->UDFs[pCall->str];
	ostringstream oss;
	set<int> breakpoint;
	AstNode *p, *pf, *pa;	 // formal & actual parameter
	size_t cnt, nArgout;
	CAstSigEnv *pLocalEnv(NULL);
	// output parameter binding
	AstNode *pOutParam = pUDF->alt;
	if (pOutParam) {
		if (pOutParam->type==NODE_VECTOR) 
			for (cnt=0, pf = pOutParam->child; pf ; pf = pf->next, cnt++)
				argout.push_back(pf->str);
		else
			throw CAstException(pOutParam, this, "Internal error! pOutParam in CallUDF: Unexpected node type - ", pOutParam->type);
	}
	if (lhs) 
	{
		for (nArgout=0, p=lhs->child; p; p=p->next, nArgout++) {}
		if ( nArgout > argout.size() ) {
			oss << "Maximum number of return arguments for function '" << pCall->str << "' is " << argout.size() << ".";
			throw CAstException(pCall, this, oss.str());
		}
	}
	else
		nArgout=argout.size();	

	son = new CAstSig(pEnv);
	son->pAst = pUDF->child->next;
	son->fBreak = false;
	son->currentLine = 2;
	son->pCall = pCall;
	son->lhs = lhs;
	son->dad = this; // necessary when debugging exists with stepping (F10), the stepping can continue in tbe calling scope without breakpoints. --=>check 7/25
	son->CallbackCIPulse = CallbackCIPulse;
	son->CallbackHook = CallbackHook;

	// input parameter binding
	pa = pCall->child;
	pf = pUDF->child->child;
	if (pa && pa->type == NODE_ARGS)
		pa = pa->child;
	for (cnt=0; pa && pf; pa=pa->next, pf=pf->next, cnt++)
		son->SetVar(pf->str, Compute(pa));
	son->SetVar("nargin", (double)cnt);
	son->SetVar("nargout", (double)nArgout);
	son->pEnv->UDFs = pEnv->UDFs;	// copy other function definitions - especially for recursive calls.
	son->pEnv->AuxPath = pEnv->AuxPath;
	son->fullUDFpath = fullUDFpath;

	son->Script = pCall->str;

#ifndef CISIGPROC  
//	const char *baseudf = son->baseudfname();
	if (pEnv->DebugBreaks.find(fullUDFpath)!=pEnv->DebugBreaks.end())
	{	
//		son->Script = pCall->str; // To send UDF name to the debugger window (a hack for debugger)
		// needed to change this way to avoid crash at the above line--pCall->str is ambiguous... is it the local udf or base udf... need
		// needed to make local udf to make debugger window function scope, but 
		// it has a problem when DebugBreaks does not store br points by local udf name... 
		// Right now, it works but it may not show debugger window function scope properly.		Do something.. 9/21/2017 bjk
//		son->Script = baseudf; 

		son->nextBreakPoint = pEnv->DebugBreaks[fullUDFpath].front();
		debugon = son->debugon = true;
		mainSpace.debug_appl_manager(son, entering);
	}
	else if (dstatus==stepping_in) 
	{
		son->nextBreakPoint = 2;
		son->dstatus = stepping;
		son->Script = pCall->str; // To send UDF name to the debugger window (a hack for debugger)
		son->debugon = true;
		mainSpace.debug_appl_manager(son, entering);
	}
	for (p=pUDF->next; p; p=p->next)	// This is where local functions are registered in a UDF 
		if (p->type == T_FUNCTION)	
		{
			if (!pLocalEnv)
			{
				pLocalEnv = new CAstSigEnv(pEnv->Fs);
				*pLocalEnv = *pEnv;
				son->pEnv = pLocalEnv;
			}
			son->pEnv->UDFs[p->str] = p; // this updates the entire UDFs. Need to make it local...
		}
#endif
	
	p = son->pAst->type==NODE_BLOCK ? son->pAst->next: son->pAst;
	son->son=son; // is this necessary? 7/25
#ifdef _DEBUG
	Beep(400, 300);
#endif
	while (p)
	{
		son->pLast=p;
		if (p->type=='=' || p->type==T_FOR || p->type==T_WHILE || p->type==NODE_INITCELL || p->type==NODE_IXASSIGN || p->type==NODE_IDLIST)
			mainSpace.breakpoint(this, p);
		son->Compute(p);
		if (son->fExit) break;
		p=p->next;
	}
#ifdef XCOM
#ifndef CISIGPROC  
	if (son->debugon) //if in debug mode, exit here.
	{
		mainSpace.debug_appl_manager(son, exiting);
		if (son->currentLine > son->nextBreakPoint) // stepping out
		{ 
			if ( son->dstatus==exiting)
			{ // Exiting a function scope with stepping to the next higher scope
				if (mainSpace.dbmapfind(son->dad->GetScript().c_str()))
				{
					mainSpace.debug_appl_manager(son->dad, entering); 
					son->dad->dstatus=stepping;
					//if there's already break point set up, skip this line
//						son->dad->nextBreakPoint = 2; // to continue stepping in the dad scope from the beginning
				}
				else if (son->dad && son->dad->dad) 
				{
//					son->dad->Script = son->dad->dad->pCall->str; 
					mainSpace.debug_appl_manager(son->dad, entering); 
					son->dad->dstatus = stepping;
//						son->dad->nextBreakPoint = son->dad->currentLine+1; // to ensure to continue stepping in the dad scope.
				}
				else
					printf("\n");
			}
		}
		else if (son->dstatus==continuing) // continuing till the end
		{
			if (son->dad && son->dad->dad)
			{
				mainSpace.debug_appl_manager(son->dad, entering); 
			}
			else
				printf("\n");
		}
	}
#endif 
#endif // #ifdef XCOM
	//	son->pEnv->UDFs.clear();	// clear it so that function definitions will not be deleted by the destructor of SubAstSig
	if (son)
	{
		//preparing output transfer
		cnt=0;
		for (vector<string>::iterator itstr = argout.begin(); itstr!=argout.end() && cnt<nArgout; itstr++)
		{
			bool loop(true);
			for (map<string,CSignals>::iterator it = son->Vars.begin(); it!=son->Vars.end() && loop; it++)
				if (*itstr==it->first) 
					loop=false, cnt++, holder.push_back(&it->second);
		}
		if (holder.size()>0)
		{
			//executing output transfer
			if (!lhs) // when no output args are specified
				Sig = *holder[0];
			else if (lhs->type==NODE_VECTOR) // [a,b]=udf(......)
				for (cnt=0, pa=lhs->child; pa; pa=pa->next, cnt++)
					SetVar(pa->str, *holder[cnt]);
			else if (lhs->str) // a=udf(.....)
				SetVar(lhs->str, *holder[0]);
			else //unexpected error here.
				throw CAstException(pCall, this, "Internal error! During executing output transfer in CallUDF()");
			if (!pOutParam)	Sig = son->Sig; // no output parameter specified.
		}
	}
	son->son=NULL;
	delete son;
	son=NULL;
}

void CAstSig::cleanup_sons()
{
#ifdef XCOM
#ifndef CISIGPROC  
	CAstSig *up=NULL, *tp = this; 
	for (; tp && tp->son; tp=tp->son)
	{
		if (tp==tp->son) break; //Right now, son of son is son.... if you change it back to NULL, do it differently here... 7/27
	}
	while (mainSpace.vecast.size()>1)
	{
		up = tp->dad;
		mainSpace.debug_appl_manager(tp, exiting); 
		delete tp;
		tp = up;
	}
	tp->son = NULL;
#endif 
#endif // #ifdef XCOM
}

void AddConditionMeetingBlockAsChain(CSignals *Sig, CSignal *psig, int iBegin, int iNow, CSignal &part)
{
	part.UpdateBuffer(iNow-iBegin);
	memcpy(part.buf, (void*)(psig->buf+iBegin), (iNow-iBegin)*sizeof(double));
	part.tmark = 1.e3*iBegin/psig->GetFs();
	if (Sig->nSamples==0)	*Sig = part;
	else					Sig->AddChain(part);
}

AstNode *CAstSig::searchtree(AstNode *p, int type)
{ // if there's a node with "type" in the tree, return that node
	if (p)
	{
		if (p->type==type) return p;
		if (p->child)
			if (p->child->type==type) return p->child;
			else return searchtree(p->child, type);
		else if (p->next)
			if (p->next->type==type) return p->next;
			else return searchtree(p->next, type);
	}
	return NULL;
}

bool CAstSig::isContiguous(body &ind, int &begin, int &end)
{ // in out out
	bool contig(true);
	double id, id0(ind.buf[0]);
	double diff = ind.buf[1] - id0;
	for (int k=1; k<ind.nSamples && contig; k++)
	{
		id = ind.buf[k];
		if (id-id0 != diff || diff!=1. && diff!=-1.)
			contig = false;
		id0 = id;
	}
	if (diff>0) begin =  INT(ind.buf[0]), end =  INT(ind.buf[ind.nSamples-1]);
	else	end =  INT(ind.buf[0]), begin =  INT(ind.buf[ind.nSamples-1]);
	return contig;
}


CSignals &CAstSig::extract(CSignal &in, body &isig)
{
	CSignal out(in.GetFs());
	out.UpdateBuffer(isig.nSamples);
	//CSignal::Min() makes a vector
	//body::Min() makes a scalar.
	if (((body)isig).Min()<=0.) throw "index must be positive.";
	if (((body)isig).Max()>in.nSamples) throw "index out of range.";
	if (in.IsComplex()) 
	{
		out.SetComplex();
		for (int i=0; i<isig.nSamples; i++)
			out.cbuf[i] = in.cbuf[(int)isig.buf[i]-1];
	}
	else if (in.IsLogical())
	{
		out.MakeLogical();
		for (int i=0; i<isig.nSamples; i++)
			out.logbuf[i] = in.logbuf[(int)isig.buf[i]-1];
	}
	else if (in.IsString())
	{
		out.UpdateBuffer(isig.nSamples+1); // make room for null 
		for (int i=0; i<isig.nSamples; i++)
			out.strbuf[i] = in.strbuf[(int)isig.buf[i]-1];
		out.strbuf[out.nSamples-1]=0;
	}
	else
	{
		out.SetReal();
		for (int i=0; i<isig.nSamples; i++)
			out.buf[i]=in.buf[(int)isig.buf[i]-1];
	}
	return (Sig=out);
}

CSignals &CAstSig::getlhs(const AstNode *pnode, CSignals *inout, CSignals &indsig)
{
	int fs = pEnv->Fs;
	CSignals out(inout->GetFs());
#ifndef CISIGPROC  
	AstNode *p = pnode->alt; 
	if (indsig.IsScalar())
		out.SetValue(inout->buf[(int)(indsig.value()+.5)-1]);
	else
	{
		if (pnode->type==NODE_EXTRACT)
		{
			int id0 = round(indsig.buf[0]/1000.*fs);
			int id1 = round(indsig.buf[1]/1000.*fs)-1;
			inout->Take(out, id0, id1);
		}
		else if (pnode->type==NODE_IXASSIGN || pnode->type==NODE_INITCELL )
		{
			int id1, id2;
			if (inout->GetType()==CSIG_AUDIO) 
			{
				if (p->type==NODE_IDLIST || (p->next && p->next->type==NODE_IDLIST) )
				{          // s(tp1~tp2)   or  cel{n}(tp1~tp2)
					int id0 = round(indsig.buf[0]/1000.*fs);
					int id1 = round(indsig.buf[1]/1000.*fs)-1;
					inout->Take(out, id0, id1);
				}
				else	if (indsig.IsLogical()) // s(conditional_var)
				{
					bool prev = indsig.logbuf[0];
					int k, id1(0);
					CSignals part(inout->GetFs());
					for (k=1; k<indsig.nSamples; k++)
					{
						//First, find the continguous range that satisfy the condition
						if (indsig.logbuf[k]) 
						{
							if (!prev)	id1 = k;
							prev = true;
							if (k==indsig.nSamples-1) // if the last point is true, the lask block should be taken.
								AddConditionMeetingBlockAsChain(&out, inout, id1, k+1, part);
						}
						else
						{
							if (prev) //if previously true, but currently false, take this block since id1
								AddConditionMeetingBlockAsChain(&out, inout, id1, k, part);
							prev = false;
						}
					}
				}
				else if (p->type==NODE_ARGS || (p->next && p->next->type==NODE_CALL) )
				{ // s(id1:id2) or cel{n}(id1:id2)
					// this must be contiguous
					if (!isContiguous(indsig, id1, id2)) throw CAstException(pnode, this, "to replace audio signal, the indices must be contiguous.");
					checkindexrange(pnode, inout, id1, "LHS (first)");
					checkindexrange(pnode, inout, id2, "LHS (second)");
					inout->Take(out, id1, id2);				  // id or time points?
				}
				else 
					 throw CAstException(pnode, this, "Internal logic error (insertreplace:1) --unexpected node type.");
			}
			else
			{
				// v(1:5) or v([contiguous]) = (any array) to replace
				// v(1:2:5) or v([non-contiguous]) = RHS; //LHS and RHS must match length.
				return extract(*inout, indsig);
			}
		}
		else 
			 throw CAstException(pnode, this, "Internal logic error (insertreplace:2) --unexpected node type.");
	}
#endif //CISIGPROC
	return (Sig=out);
}


bool CAstSig::checkcond(const AstNode *p)
{
	Compute(p);
	if (!Sig.IsScalar())	throw CAstException(p, this, "--conditional op requires a scalar.");
	if (Sig.IsLogical()) 
		return Sig.logbuf[0];
	else				
		return !(Compute(p).value()==0.);
}

void CAstSig::checkindexrange(const AstNode *pnode, CSignal *inout, int id, string errstr)
{
	if (id>inout->nSamples) 
	{
		string out("Index on ");
		out += errstr;
		out += " out of range.";
		throw CAstException(pnode, this, out);
	}
}

CAstSig &CAstSig::insertreplace(const AstNode *pnode, CSignal *inout, CSignals &sec, CSignals &indsig)
{
	if (!indsig.IsLogical() && inout->GetType()== CSIG_AUDIO && sec.GetType()!=CSIG_AUDIO && sec.GetType()!=CSIG_EMPTY)
		throw CAstException(pnode, this, "Referencing timepoint(s) in an audio variable requires another audio signal on the RHS.");
	bool logicalindex = indsig.IsLogical();
	AstNode *p = pnode->alt; 
	if (inout->GetType()!= CSIG_AUDIO && indsig.IsLogical())
	{ // For non-audio, if isig is the result of logical operation, get the corresponding indices 
		CSignals trueID(1);
		trueID.UpdateBuffer(indsig.nSamples);
		int m=0;
		for (int k(0); k<indsig.nSamples; k++)
			if (indsig.logbuf[k]) 
				trueID.buf[m++]=k; // because aux is one-based index
		trueID.UpdateBuffer(m);
		indsig = trueID;
	}

	if (indsig.IsScalar())
	{
		if (inout->GetType()==CSIG_AUDIO) 				// s(tp) = sound; //insert
			inout->Insert(indsig.value(), sec);
		else
		{
			if (sec.GetType()!=CSIG_SCALAR) throw CAstException(pnode, this, "RHS must be a scalar");
			int id = (int)(indsig.value()+.5);
			checkindexrange(pnode, inout, id, "LHS");
			if (sec.IsComplex()) 
			{
				inout->SetComplex();
				inout->cbuf[id-1]=sec.cbuf[0];
			}
			else
				inout->buf[id-1] = sec.value();
		}
	}
	else // not done yet if sec is complex
	{
		if (pnode->type==NODE_IXASSIGN || pnode->type==NODE_INITCELL )
		{
			int id1, id2;
			if (inout->GetType()==CSIG_AUDIO) 
			{
#ifndef CISIGPROC
				AstNode *tp = searchtree(pnode->child, T_REPLICA);
#else
				AstNode *tp(NULL);
#endif //CISIGPROC

				if (p->type==NODE_IDLIST || (p->next && p->next->type==NODE_IDLIST) )
			               // s(tp1~tp2)   or  cel{n}(tp1~tp2)
					inout->Replace(sec, indsig.buf[0], indsig.buf[1]);
				else if (p->type==NODE_ARGS || (p->next && p->next->type==NODE_CALL) )
				{
					if (indsig.IsLogical()) // s(conditional_var)
					{
						for (CSignal *p=&sec; p; p = p->chain)
						{
							int id((int)(p->tmark*GetFs()/1000+.5)); 
							for (int k=0; k<p->nSamples; k++)
								if (indsig.logbuf[id+k]) 
									inout->buf[id+k] = p->buf[k];
						}
					}
					else // s(id1:id2) or cel{n}(id1:id2)
					{
						// this must be contiguous
						if (!isContiguous(indsig, id1, id2)) throw CAstException(pnode, this, "to replace audio signal, the indices must be contiguous.");
						checkindexrange(pnode, inout, id1, "LHS (first)");
						checkindexrange(pnode, inout, id2, "LHS (second)");
						inout->Replace(sec, 1000.*(id1-1)/inout->GetFs(), 1000.*(id2-1)/inout->GetFs());
					}
				}
				else if (!p->next && !p->str) // if s(conditional) is on the LHS, the RHS must be either a scalar, or the replica, i.e., s(conditional)
				{
					if (!tp && !indsig.IsLogical()) throw CAstException(pnode, this, "Internal logic error (insertreplace:0)--s(conditional?).");
					if (sec.IsScalar()) 
					{
						double val = sec.value();
						for (CSignal *piece(inout), *index(&indsig); piece; piece = piece->chain, index = index->chain)
						{
							for (int k=0; k<index->nSamples; k++)
								if (index->logbuf[k]) piece->buf[k] = val;
						}
					}
					else
					{ // RHS is conditional (can be replica)
					  // At this point no need to worry about replacing null with non-null (i.e., signal is always non-null in the signal portions of sec. 
					  //   4/13/2017
						for (CSignal *p=&sec; p; p = p->chain)
						{
							int id((int)(p->tmark*GetFs()/1000+.5)); 
							for (int k=0; k<p->nSamples; k++)
								inout->buf[id+k] = p->buf[k];
						}
					}
				}
				else 
					 throw CAstException(pnode, this, "Internal logic error (insertreplace:1) --unexpected node type.");
			}
			else
			{
				// v(1:5) or v([contiguous]) = (any array) to replace
				// v(1:2:5) or v([non-contiguous]) = RHS; //LHS and RHS must match length.
				bool contig = isContiguous(indsig, id1, id2);
				if (!contig && sec.nSamples!=1 && sec.nSamples!=indsig.nSamples) throw CAstException(pnode, this, "the number of replaced items must be the same as that of replacing items."); 
				if (contig)
					inout->replace(sec, id1-1, id2-1);
				else 
					inout->replace(sec, indsig);
			}
		}
		else 
			 throw CAstException(pnode, this, "Internal logic error (insertreplace:2) --unexpected node type.");
	}
	return *this;
}

AstNode *CAstSig::ReadUDF(const char *udf_filename, const AstNode *pnode)
{ // This is where the udf file is read and processed from the path
  // After this call, pEnv->UDFs[udf_filename] wil have AstNode with T_FUNCTION type (if there are local functions, they will be at pEnv->UDFs[udf_filename]->next and continue to be linked with next
	if (!udf_filename) return NULL;
	string dummy;
	FILE *auxfile = OpenFileInPath(udf_filename, "aux", dummy);
	if (!auxfile)
	{
		//if udf_filename is local function it should continue down, otherwise return NULL
		if (pEnv->UDFs.find(udf_filename)==pEnv->UDFs.end())
			return NULL;
		else 
			return pEnv->UDFs[udf_filename];
	}
	// process Aux files
	try 
	{
		CAstSig aux(pEnv);
		aux.pAst = aux.SetNewScriptFromFile(udf_filename, auxfile);
		fclose(auxfile);
		//The type of pnode4Func is normally T_FUNCTION; or NODE_BLOCK if there's a location function found in the file
		AstNode *pnode4Func = (aux.pAst->type == NODE_BLOCK) ? aux.pAst->next : aux.pAst;
		for (AstNode *pp=pnode4Func; pp; pp=pp->next)
			if (pp->type != T_FUNCTION)
				throw CAstException(pp, this, "All codes in AUX file must be inside function definitions.");
		if (strcmp(udf_filename, pnode4Func->str)) // pnode4Func is NULL for local function call and it will crash.....8/1/
			throw CAstException(pnode, this, "inconsistent function name", string(string(string(udf_filename)+" vs ")+pnode4Func->str).c_str());

		pEnv->UDFs[udf_filename] = pnode4Func;	// pnode4Func->next might be valid, which is a local function. It will be taken care of in CallSub()
		for (map<string, vector<int>>::iterator it=pEnv->DebugBreaks.begin(); it!=pEnv->DebugBreaks.end(); it++)
		{
			char fname[256];
			_splitpath(it->first.c_str(), NULL, NULL, fname, NULL);
			if (!strcmp(udf_filename,fname)) {
				fullUDFpath = it->first;
				break;
			}
		}
		// The following should be after all the throws. Otherwise, the UDF AST will be dangling.
		// To prevent de-allocation of the AST of the UDF when the aux is destroyed.
		if (aux.pAst->type == NODE_BLOCK)
			aux.pAst->next = NULL;
		else
			aux.pAst = NULL;
		return pnode4Func;
	}
	catch (const char *errmsg) 
	{
		fclose(auxfile);
		if (pnode->str)
			throw CAstException(pnode, this, "Calling "+string(pnode->str)+"( )\n\nIn file '"+udf_filename+"':\n"+errmsg);
		else
			throw CAstException(pnode, this, "Calling "+string(pnode->child->str)+"( )\n\nIn file '"+udf_filename+"':\n"+errmsg);
	} 
	catch (const CAstException &e) 
	{
		fclose(auxfile);
		throw CAstException(pnode, this, "Calling "+string(pnode->child->str)+"( )\n\nIn file '"+udf_filename+"':\n"+e.getErrMsg());
	}
}


//#define  T_NUMBER 284
//#define  T_STRING 285
//#define  T_ID 286

bool CAstSig::CheckPrepareCallUDF(const AstNode *p)
{
	char *pstr=p->str;
	if (!pstr) return false;
	if ( pEnv->UDFs.find(pstr)!=pEnv->UDFs.end() )
	{
		pCall = (AstNode*)p;
		currentLine = p->line; // check this between the two cases ('=' and just NODE_CALL)
		CallUDF();
		return true;
	}
	return false;
}

const char* CAstSig::baseudfname()
{
	CAstSig *p = dad;
	while (p)
	{
		if (!p->dad) break;
		p = p->dad;
	}
	// At this point, p is ast used when the call was made in the base workplace.
	if (p->pAst)
	{
		if (p->pAst->type==NODE_CALL)
			return p->pAst->str; 
		else if (p->pAst->type=='=')
		{
			if (p->pAst->child->type==NODE_CALL)
				return p->pAst->child->str; 
		}
	}
	return NULL;
}

CSignals &CAstSig::SetLevel(const AstNode *pnode, AstNode *p)
{
	bool trinary(false);
	CSignals tsig, isig,  rms, rms2;
	tsig = Compute(p->next);
	if (p->type == '@') {	// trinary?
		CSignals second = Compute(p->child->next);
		if (!second.IsScalar()) {	// trinary!
			trinary = true;
			rms2 = second.RMS();
			if (second.next) isig = second.next->RMS(), rms2.SetNextChan(&isig);
			Compute(p->child);	// Sig gets the first operand
		}
	}
	if (!trinary) {	// binary! - the first operand was not computed yet.
		rms2.SetValue(-0.000262);	// the calculated rms value of a full scale sinusoid (this is necessary to avoid the clipping of rms adjusted full scale sinusoid)
		Compute(p);
	}
	blockCell(pnode,  Sig);
	// Now Sig always has the first operand
	checkAudioSig(pnode,  Sig);
	if (!Sig.next && tsig.next) throw CAstException(p->next, this, "Mono signal should be scaled with a scalar.");
	if (tsig.nSamples > 1 || (tsig.next && tsig.next->nSamples > 1) )	
		if (Sig.next)	throw CAstException(p->next, this, "Level scaling operand should be scalar. (Did you forget to put ; between two values?)");
		else			throw CAstException(p->next, this, "Level scaling operand should be scalar.");
		
	rms = -Sig.RMS();
	if (Sig.next) isig = -Sig.next->RMS(), rms.SetNextChan(&isig);
	rms += rms2;
	rms += tsig;
	rms *= LOG10DIV20;
	if (rms.GetType()==CSIG_AUDIO || rms.GetType()==CSIG_VECTOR)
		Sig *= rms;
	else
		Sig *= rms.each(exp).transpose1();
	return Sig;
}

CSignals &CAstSig::CellAssign(const AstNode *pnode, AstNode *p)
{
	// always update with the new statement, discard what was in there previously.
	if (!pnode->alt)
	{ // x={"bjk",noise(300), 4.5555}
		int count(0);
		for (; p; count++, p=p->next)
			;
		p = pnode->child;
		Sig.cell.reserve(count);
		if (pnode->str)
		{
			for (; p; p=p->next)
				AddCell(pnode->str, Compute(p));
			Sig.cell.clear(); // Sig needs to clear cell here, so anything following won't have lingering cells.
		}
		else
			for (; p; p=p->next)
				Sig.cell.push_back(Compute(p));
	}
	else
	{ //x{2}(20~50)=silence(10)
		CSignals tsig, isig;
		isig = Compute(pnode->alt);
		if (!isig.IsScalar())	throw CAstException(p->alt, this, "Cell index must be a scalar.");
		int id = (int)(isig.value()+.5);
		CSignals *psig = RetrieveVar(pnode->str);
		if (!psig) throw CAstException(pnode, this, "Cell variable not available.", pnode->str);
		if (id>(int)psig->cell.size()) 
		{
			string str;
			if (pnode->alt->str)
				sformat(str, "%s", pnode->alt->str);
			else
				sformat(str, "%d", id);
			throw CAstException(pnode, this, "Cell index is out of range.", str);
		}
		CSignal *cellsig = RetrieveCell(pnode->str, id);
		tsig = Compute(p); 
		if (!cellsig) 
			AddCell(pnode->str, tsig);
		else
		{
			if (pnode->alt->next)
			{
				isig = Compute(pnode->alt->next); // should be scalar, T_ID, or p:q (but no p:r:q)
				// if cell{n}(tp1~tp2), pnode->next->next->type is NODE_IDLIST
				// if cell{n}(id1:id2), pnode->next->next->type is NODE_CALL 
				if (searchtree(p, T_REPLICA))	
					replica = getlhs(pnode, (CSignals*)cellsig, isig); // check the second arg... CSignals vs CSignal
				// rhs compute should be done after replica is ready
				insertreplace(pnode, cellsig, tsig, isig);
				tsig = *cellsig;
			}
			else
				if (searchtree(p, T_REPLICA))	replica = *cellsig;
			SetCell(pnode->str, id, tsig);
		}
	}
	return Sig;
}

CSignals &CAstSig::Assign(const AstNode *pnode, AstNode *p)
{
	char *pstr;
	if (!p)	throw CAstException(pnode, this, "Internal error: Empty assignment!");
	// if there's a 292 node (REPLICA) down in p, do something (here, NODE_INITCELL and NODE_IXASSIGN)
	if (searchtree(p, T_REPLICA))
	{
		CSignals *psig;
		if ((psig = RetrieveVar(pnode->str)))
			replica = *psig;
		else
			throw CAstException(p, this, "LHS variable not available to replicate on the RHS.", pnode->str);
		AstNode *tp = searchtree(p, NODE_CALL);
		if (tp && !tp->str)
		{
			tp->str = (char*)malloc(strlen(pnode->str)+1);
			strcpy(tp->str, pnode->str);
		}
	}
	// if child of pnode is string (i.e., a="bjsk") go directly SetVar; otherwise, check if p is a built-in function (NODE_FUNCTION) or UDF

	//check if a local function is checked by ReadUDF
	if (ReadUDF(p->str, p)) // udf
	{
		if (pnode->str) // LHS is a variable name
			lhs = (AstNode*)pnode;
		else	// LHS is a vector
			lhs = pnode->alt;
		CheckPrepareCallUDF(p);
	}
	else
	{
		if (!(pstr=pnode->str))
		{ // pnode->str can NULL if
			if (pnode->alt)
			{
				if (!pnode->alt->child->next) // this means only one variable in LHS is bracketted... i.e., [out]=noise(300)
					pstr = pnode->alt->child->str;
				else
					throw CAstException(p, this, "Return of multiple variable not allowed for a built-in function.", p->str);
			}
			else
				throw CAstException(p, this, "Unknown error in Assign function", p->str);
		}
		SetVar(pstr, Compute(p));
	}
	return Sig;
}


CSignals &CAstSig::NodeExtract(const AstNode *pnode, AstNode *p)
{
	CSignals *psig = RetrieveVar(p->str);
	if (!psig) throw CAstException(p, this, "variable not available.");
	checkAudioSig(pnode,  *psig);
#ifndef CISIGPROC
	if (searchtree(p, T_ENDPOINT))
	{
		CAstSig tp(this);
		tp.Vars = Vars;
		char buff[256];
		sprintf(buff, "endt(%s)", pnode->child->str);
		tp.SetNewScript(buff);
		tp.Compute();
		endpoint = tp.Sig.value();
	}
#endif //CISIGPROC
	CSignals isig = Compute(p->next);
	isig += &Compute(p->next->next);
	Sig = getlhs(pnode, psig, isig);
	return Sig;
}

CSignals &CAstSig::NodeCall(const AstNode *pnode, AstNode *p)
{
	char *pstr;
	CSignals *psig = RetrieveVar(pnode->str);
	// assert p ? When can p be NULL and come here?
	// --> p must not be NULL, no assert p needed. 8/24/2017
	if (psig && !p->next /* only one argument */) 
	{
		if (psig->GetType()==CSIG_CELL) throw CAstException(p, this, "A cell array cannot be accessed with ( ).");
#ifndef CISIGPROC
		if (searchtree(p, T_ENDPOINT))
		{
			CAstSig tp(this);
			tp.Vars = Vars;
			char buff[256];
			sprintf(buff, "length(%s)", pnode->str);
			tp.SetNewScript(buff);
			tp.Compute();
			endpoint = tp.Sig.value();
		}
#endif //CISIGPROC
		CSignals tsig, isig = Compute(p);
		if (isig.IsLogical()) // This means conditional indexing
		{
			Sig.Reset(psig->GetFs());
			if (psig->GetType()==CSIG_AUDIO)
			{
				bool prev = isig.logbuf[0];
				int k, id1(0);
				CSignals part(psig->GetFs());
				for (k=1; k<isig.nSamples; k++)
				{
					//First, find the continguous range that satisfy the condition
					if (isig.logbuf[k]) 
					{
						if (!prev)	id1 = k;
						prev = true;
						if (k==isig.nSamples-1) // if the last point is true, the lask block should be taken.
							AddConditionMeetingBlockAsChain(&Sig, psig, id1, k+1, part);
					}
					else
					{
						if (prev) //if previously true, but currently false, take this block since id1
							AddConditionMeetingBlockAsChain(&Sig, psig, id1, k, part);
						prev = false;
					}
				}
			}
			else
			{
				int *indexholder = new int[isig.nSamples];
				//keep the indices with 'true' value
				int id(0);
				for (int k=0; k<isig.nSamples; k++)
				{
					if (isig.logbuf[k]) indexholder[id++]=k;
				}
				Sig.UpdateBuffer(id);
				Sig.SetReal();
				Sig.SetFs(psig->GetFs());
				for (int k=0; k<id; k++)
					Sig.buf[k] = psig->buf[indexholder[k]];	// -1 for one-based indexing
				delete[] indexholder;
			}
		}
		else // Extraction by indices
			extract(*psig, isig);
	} 
	else
	{
		if (pstr=pnode->str)
		{
			lhs = NULL;
			//check if a local function is checked by ReadUDF
			if (ReadUDF(pstr, p) && CheckPrepareCallUDF(pnode))
				return Sig;
		}
		HandleAuxFunctions(pnode);
	}
	return Sig;
}

CSignals &CAstSig::IxAssign(const AstNode *pnode, AstNode *p)
{
	// when part of variable (i.e., range of index) is on the LHS, 
	// i.e., x(n)=(something), x(m:n)=(something), or x(t1~t2)=(something)
	CSignals isig, tsig, *psig = RetrieveVar(pnode->str);
	if (!psig) throw CAstException(pnode, this, "variable not available.");
	bool check = pnode->next!=NULL; // this is from T_ID '(' condition ')' '=' exp_range
	if (pnode->alt->type==NODE_ARGS) // x(5) = something
		isig = Compute(pnode->alt->child);
	else 
		isig = Compute(pnode->alt);
	if (!p)
		throw CAstException(pnode, this, "Internal error: Empty assignment!");
	if (searchtree(p, T_REPLICA))
		replica = getlhs(pnode, psig, isig);
	//rhs compute should be done after replica is ready
	tsig = Compute(p); // rhs
	//if x(tp1~tp2), pnode->next->type is NODE_IDLIST
	//if x(id1:id2), pnode->next->type is NODE_ARGS
	//if x(var),	pnode->next->type is 
	//if x(conditional),  pnode->next->type is conditional op and pnode->next-next is NULL
	insertreplace(pnode, psig, tsig, isig);
	Sig = *psig;
	return Sig;
}

CSignals &CAstSig::NodeMatrix(const AstNode *pnode, AstNode *p)
{
	CSignals tsig = Compute(p);
	blockCell(pnode,  Sig);
	CSignals *psig = &tsig;
	for (p=p->next; p; p=p->next,psig=(CSignals*)psig->next) {
		Compute(p);
		if (Sig.GetType()!=CSIG_AUDIO && Sig.GetType()!=CSIG_SCALAR)
		{
			//if it is scalar, allow it as an exception (so that stereo scaling can be put in..)
			throw CAstException(p, this, "Audio signal required to construct a stereo signal. (Or, scaling for stereo provided for a mono signal)");
		}
		psig->SetNextChan(&Sig);
	}
	Sig = tsig;
	return Sig;
}

CSignals &CAstSig::NodeVector(const AstNode *pnode, AstNode *p)
{
	CSignals tsig = Compute(p);
	tsig = Compute(p);
	for (p=p->next; p; p=p->next) {
		Compute(p);
		tsig += &Sig;	// concatenate
	}
	Sig = tsig;
	return Sig;
}

CSignals &CAstSig::NodeInterpol(const AstNode *pnode, AstNode *p)
{
	CSignals tsig = Compute(p->next);
	blockCell(pnode,  Sig);
	tsig.MakeChainless();
	for (int i=0; i<tsig.nSamples; ++i)
		tsig.buf[i] = exp(tsig.buf[i] * LOG10DIV20);
	CSignals isig = Compute(p->next->next);
	Compute(p);
	for (int k(0); k<isig.nSamples-1; k++)
		if (isig.buf[k] > Sig.alldur())
			throw CAstException(p->next, this, "Level scaling operand timepoint should be within the time range of the operand.");
	tsig = Sig.Reset(GetFs()).Interp(tsig, isig);
	Compute(p);
	Sig *= tsig;
	return Sig;
}

CSignals &CAstSig::t_id(const AstNode *pnode, AstNode *p)
{// celled-CSignals object with an index. /* child is for cell array index */  
	CSignals tsig, isig, *psig;
	isig = Compute(p);
	if (!isig.IsScalar())	throw CAstException(p, this, "Array index must be a scalar.");
	int id = (int)(isig.value()+.5);
	if (id<=0) throw CAstException(p, this, "Array index must be a positive integer.");
	if (!(psig = RetrieveVar(pnode->str)))
		throw CAstException(pnode, this, "Unknown array - ", pnode->str);
	tsig = psig->cell.at(id-1); // because AUX is one-based
	if (p->next) // x{n}(id1:step:id2)  or x{n}(index_array)
	{
		isig = Compute(p->next);
		Sig = extract(tsig,isig);
	}
	else
		Sig = tsig;
	return Sig;
}

CSignals &CAstSig::Compute(const AstNode *pnode)
{
	CSignals tsig, isig, *psig, lsig, rsig;
	bool trinary(false);
	if (!pnode) 
	{	Sig.Reset(1); return Sig; }
	if (GfInterrupted)
		throw CAstException(pnode, this, "Script execution has been interrupted.");
	AstNode *p = pnode->child;
try {
	switch (pnode->type) {
	case '=':
		return Assign(pnode, p);
	case NODE_CALL: // 1) Built-in functions, 2) UDFs, 3) Extraction by index
		return NodeCall(pnode, p);
	case NODE_INITCELL: // x={"bjk",noise(300), 4.5555} or x{2}(20~50)=silence(10)
		return CellAssign(pnode, p);
	case NODE_EXTRACT:
		return NodeExtract(pnode, p);
	case NODE_IXASSIGN: // x(n)=(something), x(m:n)=(something), or x(t1~t2)=(something)
		return IxAssign(pnode, p);
	case NODE_IDLIST:
		tsig = Compute(p);
		if (p && pnode->alt && !pnode->tail && !pnode->str)
		{    // LHS is x(tp1~tp2)
			Compute(pnode->alt);
			Sig += &tsig;
		}
		return Sig;
	case T_ID:
		if (p) // celled-CSignals object with an index. /* child is for cell array index */  
			return t_id(pnode, p);
		else { // a celled-CSignals object without an index or an CSignals object with an extractor operator
			if (!(psig = RetrieveVar(pnode->str)))
				throw CAstException(pnode, this, "Unknown variable - ", pnode->str);
			Sig = *psig;
		}
		break;
	case T_NUMBER:
		Sig.SetValue(pnode->dval);
		return Sig; 
	case T_STRING:
		Sig.SetString(pnode->str);
		return Sig; 
	case NODE_MATRIX:
		if (p) 	return NodeMatrix(pnode, p);
		else	Sig.Reset(1);
		break;
	case NODE_VECTOR:
		if (p) 	return NodeVector(pnode, p);
		else	Sig.Reset(1);
		break;
	case NODE_INTERPOL:
		return NodeInterpol(pnode, p);
	case '@':
		return SetLevel(pnode, p);
	case T_REPLICA:
		if (pnode->str)
		{
			if (p)
				SetVar(pnode->str, Sig = Compute(p));
			else
				SetVar(pnode->str, Sig = replica);
		}
		else
		{
			if (p)
				Sig = Compute(p);
			else
				Sig = replica;
		}
		break;

	case '+':
	case '-':
		tsig = Compute(p);
		blockCell(pnode,  tsig);
		if (pnode->type=='+')	Compute(p->next);
		else					-Compute(p->next);
		blockCell(pnode,  Sig);
		Sig += tsig;
		break;
	case '*':
	case '/':
		tsig = Compute(p);
		blockCell(pnode,  Sig);
		blockString(pnode,  Sig);
		if (pnode->type=='*')	Compute(p->next);
		else		Compute(p->next).Reciprocal();	
		blockString(pnode,  Sig);
		Sig *= tsig;
		break;
	case T_NEGATIVE:
		-Compute(p);
		blockString(pnode,  Sig);
		break;
	case T_OP_SHIFT:
		tsig = Compute(p->next);
		blockCell(pnode,  Sig);
		if (!tsig.IsScalar())
			throw CAstException(p->next, this, "Second operand of '>>' must be a scalar.");
		Compute(p);
		checkAudioSig(pnode,  Sig);
		Sig >>= tsig.value();
		break;
	case T_OP_CONCAT:
		tsig = Compute(p->next);
		Compute(p);
		if ( (tsig.GetType()!=CSIG_CELL) ^ (Sig.GetType()!=CSIG_CELL) )
			throw CAstException(pnode, this, "Both operands must be cell or non-cell to be concatenated.");
		if (tsig.GetType()==CSIG_CELL)
		{
			for (size_t k=0; k<tsig.cell.size(); k++)
				Sig.cell.push_back(tsig.cell[k]);
		}
		else
		{
			Sig += &tsig;
			Sig.MergeChains();
		}
		break;
	case T_LOGIC_OR:
	case T_LOGIC_AND:
		tsig = Compute(p); 
		if (pnode->type==T_LOGIC_OR && Sig.nSamples==1 && Sig.logbuf[0]) return Sig;
		if (pnode->type==T_LOGIC_AND && Sig.nSamples==1 && !Sig.logbuf[0]) return Sig;
	case '<':
	case '>':
	case T_COMP_LE:
	case T_COMP_GE:
	case T_COMP_EQ:
	case T_COMP_NE:
		rsig = Compute(p->next); 
		blockCell(pnode,  rsig);
		Compute(p); 
		blockCell(pnode,  Sig);
		Sig.LogOp(rsig,pnode->type);
		if (Sig.IsString())
		{
			Sig.SetFs(1); // body::MakeLogical (which is part of LogOp) doesn't turn a string into a logical
			Sig.nSamples--; // get rid of the null space.
		}
		break;
	case T_LOGIC_NOT:
		blockCell(pnode,  Sig);
		rsig.Reset();
		rsig.MakeLogical();
		Sig = Compute(p);
		if ( !Sig.IsLogical() || !rsig.IsLogical() )
			throw "Logical operation is only for logical arrays.";
		Sig.LogOp(rsig,pnode->type); // rsig is a dummy for func signature.
		break;
	case NODE_BLOCK:
		for (p=pnode->next; p; p=p->next)
			Compute(p);
		break;
	case T_IF:
		if (p)
			if (checkcond(p))	
				Compute(p->next);
			else				
			{
				if (!p->alt) break;
				Compute(p->alt);
			}
		break;
	case T_SWITCH:
		//tsig = Compute(p);
		//for (p=p->next; p && p->next; p=p->next->next)	// p is a case exp, pcase->next is the code block.
		//	if (p->type == NODE_ARGS) {
		//		for (AstNode *pa=p->child; pa; pa=pa->next)
		//			if (tsig == Compute(pa))
		//				return Compute(p->next);	// no further processing of this 'switch' statement.
		//	} else if (tsig == Compute(p))
		//		return Compute(p->next);	// no further processing of this 'switch' statement.
		//// now p is at the end of 'case' list, without executing any conditional code.
		//if (p)	// if not null, it's the 'otherwise' code block
		//	Compute(p);
		break;
	case T_WHILE:
		fExit=fBreak=false;
		while (checkcond(p) && !fExit && !fBreak)
			Compute(p->next);
		fBreak = false;
		break;
	case T_FOR:
		fExit=fBreak=false;
		isig = Compute(p->child);
		for (int i=0; i<isig.nSamples && !fExit && !fBreak; i++) 
		{
			SetVar(p->str, CSignals(isig.buf[i]));
			Compute(p->next);
		}
		fBreak = false;
		break;
	case T_BREAK:
		fBreak = true;
		break;
	case T_CONTINUE:
		fContinue = true;
		break;
	case T_SIGMA:
		try {
			int n;
			tsig = Compute(p->child);
			blockCell(pnode,  Sig);
			n = 0;
			for (CAstSig SubAstSig(p->next, this); n<tsig.nSamples; n++) {
				SubAstSig.SetVar(p->str, tsig.buf[n]);
				if (n)
					Sig += SubAstSig.Compute();
				else
					Sig = SubAstSig.Compute();
			}
		} catch (const char *errmsg) {
			throw CAstException(pnode, this, "Calling sigma( )\n\nIn sigma expression:\n"+string(errmsg));
		}
		break;
	case T_RETURN:
		fExit = true;
		break;
	case NODE_RESTRING:
		break;
#ifndef CISIGPROC
	case T_ENDPOINT:
		Sig.SetValue(endpoint);
		break;
#endif //CISIGPROC
	case NODE_CIPULSE3:
	case NODE_CIPULSE4:
	case NODE_CIPULSE5:
	case NODE_CIPULSE6:
		if (CallbackCIPulse)
			CallbackCIPulse(pnode, this);
		else
			throw CAstException(pnode, this, "Internal error! CI Pulse without handler!");
		break;
	case T_FUNCTION:
		// should have already been removed by Compute(void)
		throw CAstException(pnode, this, "Internal error! Unexpected node - T_FUNCTION");
		break;
	default:
		throw CAstException(pnode, this, "Internal error! Unknown node type - ", pnode->type);
	}
} catch (const exception &e) {
	throw CAstException(pnode, this, string("Internal error! ") + e.what());
} 
return Sig;
}

CAstSig &CAstSig::Reset(const int fs, const char* path)
{
	map<string,AstNode *>::iterator it;
	for (it=pEnv->UDFs.begin(); it!=pEnv->UDFs.end(); it++)
		yydeleteAstNode(it->second, 0);
	pEnv->UDFs.clear();
	Vars.clear();
	if (path)	pEnv->AuxPath=path; // I don't know if this might cause a trouble.
	if (fs > 1)
		pEnv->Fs = fs;
	return *this;
}

CSignals *CAstSig::RetrieveVar(const char *tagname)
{
	if (!tagname) return NULL;
	map<string,CSignals>::iterator itVar;

	itVar = Vars.find(tagname);
	if (itVar != Vars.end())
		return &itVar->second;
	return NULL;
}

CSignal *CAstSig::RetrieveCell(const char *cellvar, int id)
{ // one-based index
	if (!cellvar) return NULL;
	CSignals *psig = RetrieveVar(cellvar);	// Find and retrive a variable
	if (!psig) return NULL;
	if (psig->cell.size()<(size_t)id) return NULL;
	return &(psig->cell[id-1]);
}

CAstSig &CAstSig::SetVar(const char *name, const CSignals &sig)
{
	CSignals *psig = RetrieveVar(name);	// RetrieveVar() takes care of reference variables.
	if (psig)
		*psig = sig;
	else	// new variable, create it.
		Vars[name] = sig;
	return *this;
}


CAstSig &CAstSig::AddCell(const char *name, const CSignals &sig)
{
	//DO I need RetrieveVar() to take care of reference variable, like this???

//	CSignals *psig = RetrieveVar(name);
//	if (psig==NULL) // new variable
	{
		CSignals tp(sig);
		CSignals *pvar=NULL;
		if ((pvar=GetVar(name)))
		{
			pvar->cell.push_back(tp);
		}
		else
			Sig.cell.push_back(tp);
		Sig.Reset();
		if (name)	
		{
			if (pvar) SetVar(name, *pvar);
			else
			{
				SetVar(name, Sig);
				Sig.cell.pop_back();
			}
		}
	}
	return *this;
}

CAstSig &CAstSig::SetCell(const char *name, const unsigned int i, const CSignal &sig)
{
	CSignal tp(sig);
	CSignals *psig = RetrieveVar(name);	// Find and retrive a variable
	if (psig!=NULL) Sig = *psig;
	else 
		Sig.cell.clear();
	if (Sig.cell.size()<i) Sig.cell.resize(i);
	Sig.cell[i-1] = tp;
	Sig.Reset();
	SetVar(name, Sig);
	Sig.cell.clear(); // Once Sig is stored in name, cell should be cleared 
	// (otherwise, the cell would linger in Sig... it would cause an error in the case of x{1}=1;x{2}="bjk" (on the same line..) 
	// 9/28/2016 bjk
	return *this;
}


AstNode *CAstSig::RetrieveUDF(const char *fname)
{
	map<string,AstNode *>::iterator itUDF;

	itUDF = pEnv->UDFs.find(fname);
	if (itUDF == pEnv->UDFs.end())
		return NULL;

	return itUDF->second;
}


CSignals *CAstSig::GetVar(const char *name)
{
	if (Vars.find(name)!=Vars.end())
		return &Vars[name];
	else
		return NULL;
}


CAstSigEnv &CAstSigEnv::SetPath(const char *path)
{
	string strPath = path;
	size_t len = strlen(path);
	if (len && path[len-1] != '\\')	strPath += '\\';
	AuxPath = strPath;
	return *this;
}

CAstSigEnv &CAstSigEnv::AddPath(const char *path)
{
	size_t len = AuxPath.length();
	if ( (len>0) && (AuxPath[len-1] != ';') )
		AuxPath += ';';
	AuxPath += path;
	return *this;
}

FILE *CAstSig::OpenFileInPath(string fname, const string ext, string &fullfilename)
{
	size_t pdot = fname.rfind('.');
	char type[4];
	if (ext=="axl" || ext=="AXL") strcpy(type,"rb");
	else						strcpy(type,"rt");
	if (pdot == fname.npos || pdot < fname.length()-4)
		fname += "." + ext;
	//if filename contains \ : or begins with . open it with the given name 
	if (fname[0] == '.' || fname.find('\\') != fname.npos || fname.find(':') != fname.npos)
		return fopen(fname.c_str(), type);
	else {
		string path, ofname(fname);
//		if (ext == "aux") // AuxPath is for all, not just for aux files.
			path = pEnv->AuxPath;
		for (size_t ps=0; size_t p=path.find(';', ps); ps=p+1) {
			int pe = (p==string::npos) ? (int)path.length() - 1 : (int)p - 1;
			for (; ps < path.length() && isspace(path[ps]); ps++)
				;
			for (; pe >= 0 && isspace(path[pe]); pe--)
				;
			if ((int)ps <= pe)
				fname = path.substr(ps,pe-ps+1) + ofname;
			if (FILE *file = fopen(fname.c_str(), type))
			{
				fullfilename = fname;
				return file;
			}
			if (p == string::npos)
				break;
		}
	}
	return NULL;
}

string CAstSig::MakeFilename(string fname, const string ext)
{
	trim(fname,' ');
	size_t pdot = fname.rfind('.');
	if (pdot == fname.npos || pdot < fname.length()-4)
		fname += "." + ext;
	if (fname[0] != '\\' && fname[1] != ':')
		if (ext == "aux")
			return pEnv->AuxPath + fname;
	return fname;
}

bool CAstSig::IsCondition(const AstNode *pnode)
{
	switch (pnode->type) {
	case '<':
	case '>':
	case T_COMP_EQ:
	case T_COMP_NE:
	case T_COMP_LE:
	case T_COMP_GE:
	case T_LOGIC_NOT:
	case T_LOGIC_AND:
	case T_LOGIC_OR:
		return true;
	default:
		return false;
	}
}

string CAstSig::ComputeString(const AstNode *p)
{
	return (p->type==T_STRING) ? p->str : Compute(p).string();
}

CAstSigEnv::CAstSigEnv(const int fs)
: Fs(fs), curLine(-1)
{
	if (fs <= 1)
		throw "Internal error: Fs must be greater than 1.";
}

CAstSigEnv::~CAstSigEnv()
{
	map<string,AstNode *>::iterator it;
	for (it=UDFs.begin(); it!=UDFs.end(); it++)
		yydeleteAstNode(it->second, 0);
}

int CAstSig::ClearVar(const char *var)
{
	if (var[0]==0) // clear all
	{
		Vars.erase(Vars.begin(), Vars.end());
		return 1;
	}
	else
	{
		vector<string> vars;
		size_t res = str2vect(vars, var, " ");
		for (size_t k=0; k<res; k++)
		{
			for (map<string, CSignals>::iterator what=Vars.begin(); what!=Vars.end(); what++)
			{
				if (what->first==vars[k])
				{
					Vars.erase(what);
					return 1;
				}
			}
		}
		return 0;
	}
}

void CAstSig::EnumVar(vector<string> &var)
{
	var.clear();
	for (map<string, CSignals>::iterator what=Vars.begin(); what!=Vars.end(); what++)
		var.push_back(what->first);
}


void CAstSig::checkNumArgs(const AstNode *pnode, const AstNode *p, const char** FuncSigs, const int minArgs, const int maxArgs)
{
	ostringstream msg;
	int nArgs(0);
	for (const AstNode *cp=p; cp; cp=cp->next)
		++nArgs;
	msg << "must have ";
	if (minArgs == 0 && maxArgs == 0 && nArgs > 0)
		msg << "no argument.";
	else if (nArgs < minArgs && maxArgs == 0)
		msg << "at least " << minArgs << (minArgs>1 ? " arguments." : " argument.");
	else if (nArgs < minArgs || maxArgs > 0 && nArgs > maxArgs) {
		msg << minArgs;
		for (int i=minArgs+1; i<maxArgs; ++i)
			msg << ", " << i;
		if (minArgs != maxArgs)
			msg << " or " << maxArgs;
		msg << (maxArgs>1 ? " arguments." : " argument.");
	} else
		return;
	throw CAstException(pnode, this, FuncSigs, msg.str());
}

CSignals *CAstSig::GetSig(const char *var)
{
	map<string, CSignals>::iterator what = Vars.find(var);
	if (what == Vars.end())
		return NULL;
	else
		return &(what->second);
}


CAstSigEnv& CAstSigEnv::operator=(const CAstSigEnv& rhs)
{
	if (this != &rhs) 
	{
		Fs = rhs.Fs;
		AuxPath = rhs.AuxPath;

		map<string,AstNode *> yy = rhs.UDFs;
		for (map<string,AstNode *>::iterator it = yy.begin(); it!=yy.end(); it++)
			UDFs[it->first] = it->second;
		map<string, vector<int>> ss = rhs.DebugBreaks;
		for (map<string,vector<int>>::iterator it = ss.begin(); it!=ss.end(); it++)
			DebugBreaks[it->first] = it->second;
	}
	return *this;
}
