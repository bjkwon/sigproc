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

#define ID_DEFAULT	99
#define ID_ERR		-111
#define ID_PLOT		100
#define ID_PLAY		101
#define ID_PLAYCONTINUE	111
#define ID_PLAYOVERLAP 112
#define ID_PLAYLOOP 113
#define ID_PLAYENDLOOP 114
#define ID_STOP		115
#define ID_SHOWFS	102
#define ID_SHOWVAR	103
#define ID_CLEARVAR	104 
#define ID_SAVE		105 
#define ID_LOAD		106
#define ID_HISTORY	107
#define ID_DEBUG_STEP 108
#define ID_DEBUG_CONTINUE 109
#define ID_DEBUG_EXIT 110
#define ID_DEBUG 111


class xcom
{
public:
//	CAstSig cast;
	vector<CAstSig*> vecast;
	vector<const AstNode*> vecnodeUDF;

	xcom();
	virtual ~xcom();
	int computeandshow(const char *AppPath, int code, string input, const AstNode *pCall=NULL);
	void showarray(int code, const AstNode *pnode);
	int ClearVar(const char *var);
	int load_axl(FILE *fp, char *errstr);
	int save_axl(FILE *fp, const char * var, char *errstr);
	void out4console(string varname, CSignals *psig, string &out);
};

extern xcom mainSpace;


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

void CAstSig::initGlobals(const CAstSig *env)
{
	if (env) {
		pEnv = env->pEnv;
//		pEnv->RefCount++;
	} else
		pEnv = new CAstSigEnv(DefaultFs);
}


CAstSig::CAstSig(const CAstSig &org)
{
	throw "Internal error: Copy constructor is prohibited. You probably meant to call CAstSig(&env)." ;
}


CAstSig::CAstSig(const CAstSig *env)
: pAst(NULL), Script(""), statusMsg(""), fAllocatedAst(false), beginLine(2), pLast(NULL), CallbackCIPulse(NULL), CallbackHook(env->CallbackHook)
{
	initGlobals(env);
}

CAstSig::CAstSig(const char *str, const CAstSig *env)
: pAst(NULL), statusMsg(""), fAllocatedAst(false), beginLine(2), pLast(NULL), CallbackCIPulse(NULL), CallbackHook(env->CallbackHook)
{
	initGlobals(env);
	SetNewScript(str);
}

CAstSig::CAstSig(AstNode *pnode, const CAstSig *env)
: pAst(pnode), Script(""), statusMsg(""), fAllocatedAst(false), beginLine(2), pLast(NULL), CallbackCIPulse(NULL), CallbackHook(env->CallbackHook)
{
	initGlobals(env);
}


CAstSig::CAstSig(const int fs)
: pAst(NULL), Script(""), statusMsg(""), fAllocatedAst(false), beginLine(2), pLast(NULL), pEnv(new CAstSigEnv(fs)), CallbackCIPulse(NULL), CallbackHook(NULL)
{
}

CAstSig::CAstSig(const char *str, const int fs)
: pAst(NULL), statusMsg(""), fAllocatedAst(false), beginLine(2), pLast(NULL), pEnv(new CAstSigEnv(fs)), CallbackCIPulse(NULL), CallbackHook(NULL)
{
	SetNewScript(str);
}

CAstSig::CAstSig(AstNode *pnode, const int fs)
: pAst(pnode), Script(""), statusMsg(""), fAllocatedAst(false), beginLine(2), pLast(NULL), pEnv(new CAstSigEnv(fs)), CallbackCIPulse(NULL), CallbackHook(NULL)
{
}


CAstSig::~CAstSig()
{
//	if (pEnv->RefCount > 0)
//		pEnv->RefCount--;
//	else
//		delete pEnv;
	if (fAllocatedAst)
		yydeleteAstNode(pAst, 0);
}


CAstSig &CAstSig::SetNewScript(const char *str, AstNode *pAstOut)
{
	int res;
	char *errmsg;

	if (pAst && Script == str)
		return *this;
	if (fAllocatedAst) {
		yydeleteAstNode(pAst, 0);
		fAllocatedAst = false;
	}

	pAst = NULL;
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


CAstSig &CAstSig::SetNewFile(FILE *fp)
{
	if (fseek(fp, 0, SEEK_END)) throw "fseek error in AUX file";
	long int fsize = ftell(fp);
	if (fseek(fp, 0, SEEK_SET)) throw "fseek error in AUX file";
	char *buf = new char[fsize+1];
	memset(buf,0,fsize+1);
	try {
	if( fread(buf, fsize, 1, fp) ) 	throw "fread error in AUX file";
	buf[fsize]=0;
	SetNewScript(buf, NULL);
	delete[] buf;
	return *this;
	
	} catch (const char *errmsg)
	{
		delete[] buf;
		throw errmsg;
	}
}


CAstException::CAstException(const AstNode *p, const string s1, const string s2)
: pnode(p), str1(s1), str2(s2), int1(0)
{
	makeOutStr();
}

CAstException::CAstException(const AstNode *p, const string s1, const int x, const string s2)
: pnode(p), str1(s1), str2(s2), int1(x)
{
	makeOutStr();
}

void CAstException::makeOutStr(const AstNode *p)
{
	ostringstream oss;
	oss << "Line " << p->line << ", Col " << p->column << ": " << str1;
	if (!str2.empty())
		oss << " \"" << str2 << '"';
	if (int1)
		oss << int1;
	outstr = oss.str();
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
		char errmsg[500];
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

void CAstSig::debug(const CAstSig *debugAstSig, int debug_status, int line)
{
	if (debug_status==2) // stepping
		SendMessage(GetHWND_SIGPROC(), WM_APP+4000, (WPARAM)&debug_status, (LPARAM)line);
	else
		SendMessage(GetHWND_SIGPROC(), WM_APP+4000, (WPARAM)&debug_status, (LPARAM)debugAstSig);
}

AstNode *CAstSig::get_tree_on_line(const AstNode *pnode, int line)
{
	AstNode *p = (AstNode *)pnode;
	for (; p; p=p->next)
		if (p->line == line) return p;
	return p;
}

void CAstSig::CallUDF(const AstNode *lhs, const char *lhsvar, const AstNode *pCall, bool debugging)
{	//pCall: ast used in the actual calling context
	
	vector<string> argout;
	AstNode *pUDF = pEnv->UDFs[pCall->str];
	ostringstream oss;
	set<int> breakpoint;
	AstNode *p, *pf, *pa;	 // formal & actual parameter
	size_t cnt, nArgout;
	// output parameter binding
	AstNode *pOutParam = pUDF->alt;
	if (pOutParam) {
		switch (pOutParam->type) 
		{
		case T_ID:
			Sig.Reset();
			argout.push_back(pOutParam->str);
			break;
		case NODE_VECTOR:
			for (cnt=0, pf = pOutParam->child; pf ; pf = pf->next, cnt++)
				argout.push_back(pf->str);
			break;
		default:
			throw CAstException(pOutParam, "Internal error! Unexpected node type - ", pOutParam->type);
		}
	}
	if (lhs) 
		for (nArgout=0, p=lhs->child; p; p=p->next, nArgout++) {}
	else
		nArgout=1;	
	if ( nArgout > argout.size() ) {
		oss << "Maximum number of return arguments for function '" << pCall->str << "' is " << argout.size() << ".";
		throw CAstException(pCall, oss.str());
	}

	if (!debugging)
	{
		sub = new CAstSig;
		sub->pAst = pUDF->child->next;
		sub->Script = sub->statusMsg = "";
		sub->fAllocatedAst = false;
		sub->beginLine = 2;
		sub->currentLine = 2;
		sub->endLine = 65525;
		sub->CallbackCIPulse = CallbackCIPulse;
		sub->CallbackHook = CallbackHook;
		sub->pEnv = new CAstSigEnv(pEnv->Fs);
		sub->pLast=NULL;

		// This is probably not necessary 6/8/2017
		if (pEnv->UDFs.find(pCall->str)==pEnv->UDFs.end())
			if (!ReadUDF(pCall->str, pCall))	
				return;

		// input parameter binding
		pa = pCall->child;
		pf = pUDF->child->child;
		if (pa && pa->type == NODE_ARGS)
			pa = pa->child;
		for (cnt=0; pa && pf; pa=pa->next, pf=pf->next, cnt++)
			sub->SetTag(pf->str, Compute(pa));
								// The following lines should be commented out to use less number of input arguments in a UDF.
/*	for (nArgin=0, p=pUDF->child->child; p; p=p->next, nArgin++) {}
	if ( cnt < nArgin ) {
		oss << "Required number of input arguments for function '" << pCall->str << "' is " << nArgin << ".";
		throw CAstException(pCall, oss.str());
	} */
	//end of not necessary

		sub->SetTag("nargin", (double)cnt);
		sub->SetTag("nargout", (double)nArgout);
		sub->pEnv->UDFs = pEnv->UDFs;	// copy other function definitions - especially for recursive calls.
		sub->pEnv->AuxPath = pEnv->AuxPath;
		if (pEnv->DebugBreaks.find(pCall->str)!=pEnv->DebugBreaks.end())
		{
			sub->endLine = pEnv->DebugBreaks[pCall->str].front();
			sub->Script = pCall->str; // To send UDF name to the debugger window (a hack for debugger)
			debug(sub, 0); // entering
		}
		for (p=pUDF->next; p; p=p->next)	// AUX file local functions
			if (p->type == T_FUNCTION)	sub->pEnv->UDFs[p->str] = p;
	}

	try {
		if (!debugging)
			p = sub->pAst;
//			p = sub->pAst->type==T_IF ? sub->pAst : sub->pAst->child;
		else
			p = pLast;
		while (p)
		{
			if (p) sub->Compute(p);
			else	break;
			if (sub->fExit) break;
			p=p->next;
			if (debugging) pLast = p;
		}
		if (sub->GetScript().size()>0) debug(sub, 3); //if in debug mode, exit here. (sub script has udf name when it's in debug mode, otherwise null)
		sub->pEnv->UDFs.clear();	// clear it so that function definitions will not be deleted by the destructor of SubAstSig
	} 
	catch (const char *errmsg) 
	{
		sub->pEnv->UDFs.clear();
		throw CAstException(pCall, "Calling "+string(pCall->str)+"( )\n\nIn function definition:\n"+errmsg);
	}
	catch(CAstSig* main) // stopped at a breakpoint
	{
		HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
		char buf[256];
		DWORD dw;
		vector<string> tar;
		int code, res;
		char *buff;
		debug(sub, 1); // progress
		mainSpace.computeandshow(sub->pEnv->AuxPath.c_str(), ID_DEBUG, "dummy;");
		p=sub->pAst;
//		p = sub->pAst->type==T_IF ? sub->pAst : sub->pAst->child;
		while (p)
		{
			res = ReadConsole(hStdin, buf, 256, &dw, NULL);
			if (buf[0]=='#')
			{
				str2vect (tar, buf+1, " \r\n");
				if (tar[0]=="step")	
				{
					sub->Compute(pnodeLast);
					p=p->next;
					code = ID_DEBUG;
					if (p)	debug(sub, 2, p->line); // progress with the current line
					else	debug(sub, 3); // debug exit
				}
				else if (tar[0]=="cont")	
				{
					// Updating sub.endLine with the next line
					for (vector<int>::iterator it = pEnv->DebugBreaks[pCall->str].begin(); it!=pEnv->DebugBreaks[pCall->str].end(); it++)
					{
						if (it+1 == pEnv->DebugBreaks[pCall->str].end()) sub->endLine = 0;
//							sub->endLine = pEnv->DebugBreaks[pCall->str].back();
						else if (*it==p->line) { sub->endLine = *(it+1); break; }
					}
					break;
				}
				else if (tar[0]=="dbexit")	code = ID_DEBUG_EXIT;
				else						code = ID_ERR;
			}
			else
				code = ID_DEFAULT;
			buff = buf;
			if (code != ID_DEFAULT) buff += tar[0].length()+1;
			if (!buff[0]) strcpy(buff,"dummy;");
			mainSpace.computeandshow(sub->pEnv->AuxPath.c_str(), code, string (buff));
		}
		sub->sub=sub;
		sub->CallUDF(lhs, lhsvar, pCall, true);
	}

	vector<CSignals*> holder;
	cnt=0;
	for (vector<string>::iterator itstr = argout.begin(); itstr!=argout.end() && cnt<nArgout; itstr++)
	{
		bool loop(true);
		for (map<string,CSignals>::iterator it = sub->pEnv->Tags.begin(); it!=sub->pEnv->Tags.end() && loop; it++)
		{
			string dfgdfg = *itstr;
			string sss = it->first;
			if (*itstr==it->first) 
			{
				loop=false;
				cnt++;
				holder.push_back(&it->second);
			}
		}
	}
	if (lhs)
		for (cnt=0, pa=lhs->child; pa; pa=pa->next, cnt++)
			SetTag(pa->str, *holder[cnt]);
	else if (lhsvar)
		SetTag(lhsvar, *holder[0]);
	else 
		Sig = *holder[0];
	if (!debugging)	
		delete sub;

	if (!pOutParam)	Sig = sub->Sig; // no output parameter specified.
}

void CAstSig::ddebug(CAstSig *debugAstSig)
{


}

void AddConditionMeetingBlockAsChain(CSignals *Sig, CSignal *psig, int iBegin, int iNow, CSignal &part)
{
	part.UpdateBuffer(iNow-iBegin);
	memcpy(part.buf, (void*)(psig->buf+iBegin), (iNow-iBegin)*sizeof(double));
	part.tmark = 1.e3*iBegin/psig->GetFs();
	if (Sig->nSamples==0)	*Sig = part;
	else					Sig->AddChain(part);
}

bool CAstSig::searchtree(AstNode *p, int type)
{ // if there's a node with "type" in the tree, return true
	if (p)
		if (p->child)
			if (p->child->type==type) return true;
			else return searchtree(p->child, type);
		else if (p->next)
			if (p->next->type==type) return true;
			else return searchtree(p->next, type);
	return false;
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
			out.cbuf[i] = in.cbuf[INT(isig.buf[i])-1];
	}
	else if (in.IsLogical())
	{
		out.MakeLogical();
		for (int i=0; i<isig.nSamples; i++)
			out.logbuf[i] = in.logbuf[INT(isig.buf[i])-1];
	}
	else if (in.IsString())
	{
		out.UpdateBuffer(isig.nSamples+1); // make room for null 
		for (int i=0; i<isig.nSamples; i++)
			out.strbuf[i] = in.strbuf[INT(isig.buf[i])-1];
		out.strbuf[out.nSamples-1]=0;
	}
	else
	{
		out.SetReal();
		for (int i=0; i<isig.nSamples; i++)
			out.buf[i]=in.buf[INT(isig.buf[i])-1];
	}
	return (Sig=out);
}

CSignals &CAstSig::getlhs(const AstNode *pnode, CSignal *inout, CSignals &indsig)
{
	CSignals out(inout->GetFs());
	AstNode *p = pnode->alt; 
	if (indsig.IsScalar())
		out.SetValue(inout->buf[(int)(indsig.value()+.5)-1]);
	else
	{
		if (pnode->type==NODE_EXTRACT)
			inout->Take(out, indsig.buf[0], indsig.buf[1]);
		else if (pnode->type==NODE_IXASSIGN || pnode->type==NODE_INITCELL )
		{
			int id1, id2;
			if (inout->GetType()==CSIG_AUDIO) 
			{
				bool ch = searchtree(pnode->child, T_REPLICA);
				if (p->type==NODE_IDLIST || (p->next && p->next->type==NODE_IDLIST) )
			               // s(tp1~tp2)   or  cel{n}(tp1~tp2)
					inout->Take(out, indsig.buf[0], indsig.buf[1]);
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
					if (!isContiguous(indsig, id1, id2)) throw "to replace audio signal, the indices must be contiguous.";
					checkindexrange(pnode, inout, id1, "LHS (first)");
					checkindexrange(pnode, inout, id2, "LHS (second)");
					inout->Take(out, id1, id2);				  // id or time points?
				}
				else 
					 throw CAstException(pnode, "Internal logic error (insertreplace:1) --unexpected node type.");
			}
			else
			{
				// v(1:5) or v([contiguous]) = (any array) to replace
				// v(1:2:5) or v([non-contiguous]) = RHS; //LHS and RHS must match length.
				return extract(*inout, indsig);
			}
		}
		else 
			 throw CAstException(pnode, "Internal logic error (insertreplace:2) --unexpected node type.");
	}
	return (Sig=out);
}


bool CAstSig::checkcond(const AstNode *p)
{
	Compute(p);
	if (!Sig.IsScalar())	throw CAstException(p, "--conditional op requires a scalar.");
	if (Sig.IsLogical()) return Sig.logbuf[0];
	else				return !(Compute(p).value()==0.);
}

void CAstSig::checkindexrange(const AstNode *pnode, CSignal *inout, int id, string errstr)
{
	if (id>inout->nSamples) 
	{
		string out("Index on ");
		out += errstr;
		out += " out of range.";
		throw CAstException(pnode, out);
	}
}

CAstSig &CAstSig::insertreplace(const AstNode *pnode, CSignal *inout, CSignals &sec, CSignals &indsig)
{
	if (!indsig.IsLogical() && inout->GetType()== CSIG_AUDIO && sec.GetType()!=CSIG_AUDIO && sec.GetType()!=CSIG_EMPTY)
		throw CAstException(pnode, "Referencing timepoint(s) in an audio variable requires another audio signal on the RHS.");
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
			if (sec.GetType()!=CSIG_SCALAR) throw CAstException(pnode, "RHS must be a scalar");
			int id = (int)(indsig.value()+.5);
			checkindexrange(pnode, inout, id, "LHS");
			inout->buf[id-1] = sec.value();
		}
	}
	else
	{
		if (pnode->type==NODE_IXASSIGN || pnode->type==NODE_INITCELL )
		{
			int id1, id2;
			if (inout->GetType()==CSIG_AUDIO) 
			{
				bool ch = searchtree(pnode->child, T_REPLICA);
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
						if (!isContiguous(indsig, id1, id2)) throw "to replace audio signal, the indices must be contiguous.";
						checkindexrange(pnode, inout, id1, "LHS (first)");
						checkindexrange(pnode, inout, id2, "LHS (second)");
						inout->Replace(sec, 1000.*(id1-1)/inout->GetFs(), 1000.*(id2-1)/inout->GetFs());
					}
				}
				else if (!p->next && !p->str) // if s(conditional) is on the LHS, the RHS must be either a scalar, or the replica, i.e., s(conditional)
				{
					if (!ch && !indsig.IsLogical()) throw CAstException(pnode, "Internal logic error (insertreplace:0)--s(conditional?).");
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
					 throw CAstException(pnode, "Internal logic error (insertreplace:1) --unexpected node type.");
			}
			else
			{
				// v(1:5) or v([contiguous]) = (any array) to replace
				// v(1:2:5) or v([non-contiguous]) = RHS; //LHS and RHS must match length.
				bool contig = isContiguous(indsig, id1, id2);
				if (!contig && sec.nSamples!=1 && sec.nSamples!=indsig.nSamples) throw "the number of replaced items must be the same as that of replacing items."; 
				if (contig)
					inout->replace(sec, id1-1, id2-1);
				else 
					inout->replace(sec, indsig);
			}
		}
		else 
			 throw CAstException(pnode, "Internal logic error (insertreplace:2) --unexpected node type.");
	}
	return *this;
}



AstNode *CAstSig::ReadUDF(const char *udf_filename, const AstNode *pnode)
{ // THis is where the udf file is read and processed from the path
	FILE *auxfile = OpenFileInPath(udf_filename, "aux");
	if (!auxfile) return NULL;
	// process Aux files
	try 
	{
		CAstSig aux;
		aux.SetNewFile(auxfile);
		fclose(auxfile);
		//If a udf contains sub-function(s) on the bottom, it's NODE_BLOCK
		AstNode *p = (aux.pAst->type == NODE_BLOCK) ? aux.pAst->child : aux.pAst;
		for (AstNode *pp=p; pp; pp=pp->next)
			if (pp->type != T_FUNCTION)
				throw CAstException(pp, "All codes in AUX file must be inside function definitions.");
		if (strcmp(udf_filename, p->str))
			throw CAstException(pnode, "inconsistent function name");

		pEnv->UDFs[udf_filename] = p;	// p->next might be valid, which is a local function. It will be taken care of in CallSub()
		// The following should be after all the throws. Otherwise, the UDF AST will be dangling.
		// To prevent de-allocation of the AST of the UDF when the aux is destroyed.
		if (aux.pAst->type == NODE_BLOCK)
			aux.pAst->child = NULL;
		else
			aux.pAst = NULL;
		return p;
	}
	catch (const char *errmsg) 
	{
		fclose(auxfile);
		throw CAstException(pnode, "Calling "+string(pnode->str)+"( )\n\nIn file '"+udf_filename+"':\n"+errmsg);
	} 
	catch (const CAstException &e) 
	{
		fclose(auxfile);
		throw CAstException(pnode, "Calling "+string(pnode->child->str)+"( )\n\nIn file '"+udf_filename+"':\n"+e.getErrMsg());
	}
}


//#define  T_NUMBER 284
//#define  T_STRING 285
//#define  T_ID 286

CSignals &CAstSig::Compute(const AstNode *pnode)
{
	static AstNode *pbreak;
	static CAstSigEnv copyEnv(22050);

	CSignals tsig, isig, *psig, lsig, rsig;
	CSignals rms, rms2;
	char *pstr;
	int count(0);
	bool check, trinary(false);
	if (!pnode) 
	{	Sig.Reset(1); return Sig; }
	if (GfInterrupted)
		throw CAstException(pnode, "Script execution has been interrupted.");
	AstNode *p = pnode->child;
try {
	switch (pnode->type) {
	case T_NUMBER:
		Sig.SetValue(pnode->dval);
		return Sig; // just to make it easy for debugging.. this line can be removed.
		break;
	case T_STRING:
		Sig.SetString(pnode->str);
		break;
	case T_ID:
		if (p) {	// celled-CSignals object with an index. /* child is for cell array index */  
			isig = Compute(p);
			if (!isig.IsScalar())	throw CAstException(p, "Array index must be a scalar.");
			int id = (int)(isig.value()+.5);
			if (id<=0) throw CAstException(p, "Array index must be a positive integer.");
			if (!(psig = RetrieveTag(pnode->str)))
				throw CAstException(pnode, "Unknown array - ", pnode->str);
			tsig = psig->cell.at(id-1); // because AUX is one-based
			if (p->next) // x{n}(id1:step:id2)  or x{n}(index_array)
			{
				isig = Compute(p->next);
				Sig = extract(tsig,isig);
			}
			else
				Sig = tsig;
//			Sig.cell.clear(); // if it is a single extraction, any trailing cells should be removed. // ==>This is probably not necessary 4/23/2016 bjk 
		} else { // a celled-CSignals object without an index or an CSignals object with an extractor operator
			if (!(psig = RetrieveTag(pnode->str)))
				throw CAstException(pnode, "Unknown variable - ", pnode->str);
			Sig = *psig;
		}
		break;
	case T_REPLICA:
		Sig = replica;
		break;
	case '=':
		if (!p)	throw CAstException(pnode, "Internal error: Empty assignment!");
		// if there's a 292 node (REPLICA) down in p, do something (here, NODE_INITCELL and NODE_IXASSIGN)
		if (searchtree(p, T_REPLICA))
		{
			if ((psig = RetrieveTag(pnode->str)))
				replica = *psig;
			else
				throw CAstException(p, "LHS variable not available to replicate on the RHS.");
		}
		if (pstr=pnode->child->str)
		{
			if ((pEnv->UDFs.find(pstr)==pEnv->UDFs.end() && ReadUDF(pstr, pnode)) ||
				pEnv->UDFs.find(pstr)!=pEnv->UDFs.end() )
			{
				if (pnode->str) // LHS is a variable name
					CallUDF(NULL, pnode->str, pnode->child);
				else	// LHS is a vector
					CallUDF(pnode->alt, NULL, pnode->child);
				break;
			}
		}

		if (pLast) p=pLast->child;
		if ( (currentLine = p->line) == endLine) typeLast = pnode->type, pnodeLast=pnode, pLast=p, throw this;
		SetTag(pnode->str, Compute(p));
		break;
	case NODE_INITCELL: 
		// always update with the new statement, discard what was in there previously.
		if (!pnode->alt)
		{ // x={"bjk",noise(300), 4.5555}
			for (; p;count++, p=p->next)
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
		{
			isig = Compute(pnode->alt);
			if (!isig.IsScalar())	throw CAstException(p->alt, "Cell index must be a scalar.");
			int id = (int)(isig.value()+.5);
			CSignals *psig = RetrieveTag(pnode->str);
			if (!psig) throw CAstException(pnode, "Cell variable not available.");
			if (id>(int)psig->cell.size()) throw CAstException(pnode, "Cell index is out of range.");
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
						replica = getlhs(pnode, cellsig, isig);
					// rhs compute should be done after replica is ready
					insertreplace(pnode, cellsig, tsig, isig);
					tsig = *cellsig;
				}
				else
					if (searchtree(p, T_REPLICA))	replica = *cellsig;
				SetCell(pnode->str, id, tsig);
			}
		}
		break;
	case '+':
		tsig = Compute(p);
		blockCell(pnode,  tsig);
		Compute(p->next);
		blockCell(pnode,  Sig);
		Sig += tsig;
		break;
	case '-':
		tsig = Compute(p); 
		blockCell(pnode,  Sig);
		-Compute(p->next);
		Sig += tsig;
		break;
	case '*':
		tsig = Compute(p);
		blockCell(pnode,  Sig);
		blockString(pnode,  Sig);
		Compute(p->next);
		blockString(pnode,  Sig);
		Sig *= tsig;
		break;
	case '/':
		tsig = Compute(p);
		blockCell(pnode,  Sig);
		blockString(pnode,  Sig);
		Compute(p->next).Reciprocal();
		blockString(pnode,  Sig);
		Sig *= tsig;
		break;
	case T_NEGATIVE:
		blockString(pnode,  Sig);
		-Compute(p);
		break;
	case '@':
		tsig = Compute(p->next);
		blockCell(pnode,  Sig);
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
		// Now Sig always has the first operand
		checkAudioSig(pnode,  Sig);
		if (!Sig.next && tsig.next) throw CAstException(p->next, "Mono signal should be scaled with a scalar.");
		if (tsig.nSamples > 1 || (tsig.next && tsig.next->nSamples > 1) )	
			if (Sig.next)	throw CAstException(p->next, "Level scaling operand should be scalar. (Did you forget to put ; between two values?)");
			else			throw CAstException(p->next, "Level scaling operand should be scalar.");
		
		rms = -Sig.RMS();
		if (Sig.next) isig = -Sig.next->RMS(), rms.SetNextChan(&isig);
		rms += rms2;
		rms += tsig;
		rms *= LOG10DIV20;
		if (rms.GetType()==CSIG_AUDIO || rms.GetType()==CSIG_VECTOR)
			Sig *= rms;
		else
			Sig *= rms.each(exp).transpose1();
		break;
	case NODE_INTERPOL:
		tsig = Compute(p->next);
		blockCell(pnode,  Sig);
		tsig.MakeChainless();
		for (int i=0; i<tsig.nSamples; ++i)
			tsig.buf[i] = exp(tsig.buf[i] * LOG10DIV20);
		isig = Compute(p->next->next);
		Compute(p);
		for (int k(0); k<isig.nSamples-1; k++)
			if (isig.buf[k] > Sig.alldur())
				throw CAstException(p->next, "Level scaling operand timepoint should be within the time range of the operand.");
		tsig = Sig.Reset(GetFs()).Interp(tsig, isig);
		Compute(p);
		Sig *= tsig;
		break;
	case T_OP_SHIFT:
		tsig = Compute(p->next);
		blockCell(pnode,  Sig);
		if (!tsig.IsScalar())
			throw CAstException(p->next, "Second operand of '>>' must be a scalar.");
		Compute(p);
		checkAudioSig(pnode,  Sig);
		Sig >>= tsig.value();
		break;
	case T_OP_SHIFT2:
		tsig = Compute(p->next);
		blockCell(pnode,  Sig);
		if (!tsig.IsScalar())
			throw CAstException(p->next, "Second operand of '<<' must be a scalar.");
		Compute(p);
		checkAudioSig(pnode,  Sig);
		Sig <<= tsig.value();
		break;
	case T_OP_CONCAT:
		tsig = Compute(p->next);
		Compute(p);
		if ( (bool) (tsig.GetType()-CSIG_CELL) ^ (bool) (Sig.GetType()-CSIG_CELL) )
			throw CAstException(pnode, "Both operands must be cell or non-cell to be concatenated.");
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
		// find p that is on deck--for debug continue situation
//		if (pLast) p=pLast; // This causes a problem for funbody1 if breakpoint is set on line 2
		for (fExit=fBreak=fContinue=false; p && !fExit && !fBreak && !fContinue; p=p->next)
		{
			if ( (currentLine = p->line) == endLine) typeLast = pnode->type, pnodeLast=pnode, pLast=p, throw this;
			Compute(p);
		}
		break;
	case T_IF:
		// if condition, action, end
		// condition is specified in the child of the T_IF node (p or pnode->child)
		// action is specified in the next of the T_IF node (pnode->next)
		// if cond action1, else action2, end
		// cond: pnode->child
		// action1: pnode->next
		// action2: pnode->alt
		// if cond1 action1, elseif cond2 action2, end
		// cond1: pnode->child
		// action1: pnode->next
		// pnode->alt is T_IF
		// cond2:	p->alt->child	(another if begining from p->alt) 
		// action2: p->alt->next
		// if cond1 action1, elseif cond2 action2, else action3, end
		// cond1: pnode->child
		// action1: pnode->next
		// pnode->alt is T_IF
		// cond2: pnode->alt->child
		// action2: pnode->alt->next
		// action3: pnode->alt->alt
		
		if (pLast) p=pLast;
		else p = (AstNode*)pnode;
		if (p->child)
			if (checkcond(p->child))	
			{
				if ( (currentLine = p->next->line) == endLine) typeLast = pnode->type, pnodeLast=pnode, pLast=p->next, throw this;
				Compute(p->next);	
				// because NODE_BLOCK checks further lines with p=p->next, let's set the break point now.
				fBreak = true; 
			}
			else				
			{
				if ( (currentLine = p->alt->line) == endLine) { 
					typeLast = pnode->type; 
					pnodeLast=pnode; 
					pLast=p->alt; 	
					throw this; }
				Compute(p->alt);	
				// because NODE_BLOCK checks further lines with p=p->next, let's set the break point now.
				fBreak = true; 
			}
		else
			throw CAstException(pnode, "T_IF: node with NULL conditional. Please report this bug."); 
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
		for (; checkcond(p) && !fExit && !fBreak ;)
			Compute(p->next);
		fBreak = false;
		break;
	case T_FOR:
		fExit=fBreak=false;
		isig = Compute(p->child);
		for (int i=0; i<isig.nSamples && !fExit && !fBreak; i++) {
			SetTag(p->str, CSignals(isig.buf[i]));
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
				SubAstSig.SetTag(p->str, tsig.buf[n]);
				if (n)
					Sig += SubAstSig.Compute();
				else
					Sig = SubAstSig.Compute();
			}
		} catch (const char *errmsg) {
			throw CAstException(pnode, "Calling sigma( )\n\nIn sigma expression:\n"+string(errmsg));
		}
		break;
	case T_RETURN:
		fExit = true;
//		currentLine = -1;
		break;
	case NODE_VECTOR:
		if (!p) {
			Sig.Reset(1);
			break;
		}
		tsig = Compute(p);
		for (p=p->next; p; p=p->next) {
			Compute(p);
			tsig += &Sig;	// concatenate
		}
		Sig = tsig;
		break;
	case NODE_MATRIX:
		if (!p) {
			Sig.Reset(1);
			break;
		}
		tsig = Compute(p);
		blockCell(pnode,  Sig);
		psig = &tsig;
		for (p=p->next; p; p=p->next,psig=(CSignals*)psig->next) {
			Compute(p);
			if (Sig.GetType()!=CSIG_AUDIO && Sig.GetType()!=CSIG_SCALAR)
			{
				//if it is scalar, allow it as an exception (so that stereo scaling can be put in..)
				throw CAstException(p, "Audio signal required to construct a stereo signal. (Or, scaling for stereo provided for a mono signal)");
			}
			psig->SetNextChan(&Sig);
		}
		Sig = tsig;
		break;
	case NODE_RESTRING:
		break;
#ifndef CISIGPROC
	case T_ENDPOINT:
		Sig.SetValue(endpoint);
		break;
#endif //CISIGPROC
	case NODE_EXTRACT:
		psig = RetrieveTag(p->str);
		if (!psig) throw CAstException(pnode, "variable not available.");
		checkAudioSig(pnode,  *psig);
		if (searchtree(p, T_ENDPOINT))
		{
			CAstSig tp(this);
			char buff[256];
			sprintf(buff, "endt(%s)", pnode->child->str);
			tp.SetNewScript(buff);
			tp.Compute();
			endpoint = tp.Sig.value();
		}
		isig = Compute(p->next);
		isig += &Compute(p->next->next);
		Sig = getlhs(pnode, psig, isig);
		break;
	case NODE_IDLIST:
		// used in x(tp1~tp2) only
		tsig = Compute(pnode->child);
		Compute(pnode->LastChild);
		Sig += &tsig;
		break;
	case NODE_IXASSIGN:
		// when part of variable (i.e., range of index) is on the LHS, 
		// i.e., x(n)=(something), x(m:n)=(something), or x(t1~t2)=(something)
		psig = RetrieveTag(pnode->str);
		if (!psig) throw CAstException(pnode, "variable not available.");
		check = pnode->next!=NULL; // this is from T_ID '(' condition ')' '=' exp_range
		if (pnode->alt->type==NODE_ARGS) // x(5) = something
			isig = Compute(pnode->alt->child);
		else 
			isig = Compute(pnode->alt);
		if (!p)
			throw CAstException(pnode, "Internal error: Empty assignment!");
		//if (p->alt && p->next->alt)
		//	;// cell array indexed assignment
		//else if (!check && !(p->next && p->next->child && !p->next->child->next))
		//	throw CAstException(pnode, "Indexed assignment must have one argument.");

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
		break;
	case NODE_CALL: // 1) Built-in functions, 2) UDFs, 3) Extraction by index
		psig = RetrieveTag(pnode->str);
		// assert p ? When can p be NULL and come here?

		if (psig && !p->next /* only one argument */) 
		{
			if (psig->GetType()==CSIG_CELL) throw CAstException(p, "A cell array cannot be accessed with ( ).");
			if (searchtree(p, T_ENDPOINT))
			{
				CAstSig tp(this);
				char buff[256];
				sprintf(buff, "length(%s)", pnode->str);
				tp.SetNewScript(buff);
				tp.Compute();
				endpoint = tp.Sig.value();
			}
			isig = Compute(p);
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
			break;
		} 

		if (pstr=pnode->str)
		{
			if ((pEnv->UDFs.find(pstr)==pEnv->UDFs.end() && ReadUDF(pstr, pnode)) ||
				pEnv->UDFs.find(pstr)!=pEnv->UDFs.end() )
				CallUDF(NULL, NULL, pnode);
			else
				HandleAuxFunctions(pnode);
		}
		else
			HandleAuxFunctions(pnode);
		break;
	case NODE_CIPULSE3:
	case NODE_CIPULSE4:
	case NODE_CIPULSE5:
	case NODE_CIPULSE6:
		if (CallbackCIPulse)
			CallbackCIPulse(pnode, this);
		else
			throw CAstException(pnode, "Internal error! CI Pulse without handler!");
		break;
	case T_FUNCTION:
		// should have already been removed by Compute(void)
		throw CAstException(pnode, "Internal error! Unexpected node - T_FUNCTION");
		break;
	default:
		throw CAstException(pnode, "Internal error! Unknown node type - ", pnode->type);
	}
} catch (const char *errmsg) {
	throw CAstException(pnode, errmsg);
} catch (const exception &e) {
	throw CAstException(pnode, string("Internal error! ") + e.what());
}
	return Sig;
}

CAstSig &CAstSig::Reset(const int fs, const char* path)
{
	map<string,AstNode *>::iterator it;
	for (it=pEnv->UDFs.begin(); it!=pEnv->UDFs.end(); it++)
		yydeleteAstNode(it->second, 0);
	pEnv->UDFs.clear();
//	pEnv->Refs.clear();
	pEnv->Tags.clear();
//	pEnv->ArrRefs.clear();
//	pEnv->Arrays.clear();
	if (path)	pEnv->AuxPath=path; // I don't know if this might cause a trouble.
	if (fs > 1)
		pEnv->Fs = fs;
	return *this;
}


CSignals *CAstSig::RetrieveTag(const char *tagname)
{
	if (!tagname) return NULL;
	map<string,CSignals>::iterator itTag;

	itTag = pEnv->Tags.find(tagname);
	if (itTag != pEnv->Tags.end())
		return &itTag->second;
	return NULL;
}

CSignal *CAstSig::RetrieveCell(const char *cellvar, int id)
{ // one-based index
	if (!cellvar) return NULL;
	CSignals *psig = RetrieveTag(cellvar);	// Find and retrive a variable
	if (!psig) return NULL;
	if (psig->cell.size()<(size_t)id) return NULL;
	return &(psig->cell[id-1]);
}

CAstSig &CAstSig::SetTag(const char *name, const CSignals &sig)
{
	CSignals *psig = RetrieveTag(name);	// RetrieveTag() takes care of reference variables.
	if (psig)
		*psig = sig;
	else	// new variable, create it.
		pEnv->Tags[name] = sig;
	return *this;
}


CAstSig &CAstSig::AddCell(const char *name, const CSignals &sig)
{
	//DO I need RetrieveTag() to take care of reference variable, like this???

//	CSignals *psig = RetrieveTag(name);
//	if (psig==NULL) // new variable
	{
		CSignals tp(sig);
		Sig.cell.push_back(tp);
		Sig.Reset();
		if (name)	SetTag(name, Sig);
	}
	return *this;
}

CAstSig &CAstSig::SetCell(const char *name, const unsigned int i, const CSignal &sig)
{
	CSignal tp(sig);
	CSignals *psig = RetrieveTag(name);	// Find and retrive a variable
	if (psig!=NULL) Sig = *psig;
	else 
		Sig.cell.clear();
	if (Sig.cell.size()<i) Sig.cell.resize(i);
	Sig.cell[i-1] = tp;
	Sig.Reset();
	SetTag(name, Sig);
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


CSignals &CAstSig::GetTag(const char *name)
{
	return pEnv->Tags[name];
}


CAstSig &CAstSig::SetPath(const char *path)
{
	string strPath = path;
	size_t len = strlen(path);
	if (len && path[len-1] != '\\')	strPath += '\\';
	pEnv->AuxPath = strPath;
	return *this;
}

CAstSig &CAstSig::AddPath(const char *path)
{
	size_t len = pEnv->AuxPath.length();
	if ( (len>0) && (pEnv->AuxPath[len-1] != ';') )
		pEnv->AuxPath += ';';
	pEnv->AuxPath += path;
	return *this;
}

FILE *CAstSig::OpenFileInPath(string fname, const string ext)
{
	size_t pdot = fname.rfind('.');
	char type[4];
	if (ext=="axl" || ext=="AXL") strcpy(type,"rb");
	else						strcpy(type,"r");
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
				return file;
			if (p == string::npos)
				break;
		}
	}
	return NULL;
}

string CAstSig::MakeFilename(string fname, const string ext)
{
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
: Fs(fs)/*, RefCount(0)*/
{
	if (fs <= 1)
		throw "Internal error: Fs must be greater than 1. You probably failed to provide a valid Fs.";
}

CAstSigEnv::~CAstSigEnv()
{
	map<string,AstNode *>::iterator it;
	for (it=UDFs.begin(); it!=UDFs.end(); it++)
		yydeleteAstNode(it->second, 0);
}

int CAstSigEnv::ClearVar(const char *var)
{
	if (var[0]==0) // clear all
	{
		Tags.erase(Tags.begin(), Tags.end());
		UDFs.erase(UDFs.begin(), UDFs.end());
		return 1;
	}
	else
	{
		vector<string> vars;
		size_t res = str2vect(vars, var, " ");
		for (size_t k=0; k<res; k++)
		{
			for (map<string, CSignals>::iterator what=Tags.begin(); what!=Tags.end(); what++)
			{
				if (what->first==vars[k])
				{
					Tags.erase(what);
					return 1;
				}
			}
		}
		for (size_t k=0; k<res; k++)
		{
			for (map<string, AstNode *>::iterator what=UDFs.begin(); what!=UDFs.end(); what++)
			{
				if (what->first==vars[k])
				{
					UDFs.erase(what);
					break;
				}
			}
		}
		return 0;
	}
}

void CAstSigEnv::EnumVar(vector<string> &var)
{
	var.clear();
	for (map<string, CSignals>::iterator what=Tags.begin(); what!=Tags.end(); what++)
		var.push_back(what->first);
}

CSignals *CAstSigEnv::GetSig(const char *var)
{
	map<string, CSignals>::iterator what = Tags.find(var);
	if (what == Tags.end())
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

		map<string,CSignals> xx = rhs.Tags;
		map<string,AstNode *> yy = rhs.UDFs;
		for (map<string,CSignals>::iterator it = xx.begin(); it!=rhs.Tags.end(); it++)
			Tags[it->first] = it->second;
		for (map<string,AstNode *>::iterator it = yy.begin(); it!=rhs.UDFs.end(); it++)
			UDFs[it->first] = it->second;
	}
	return *this;
}

void CAstSigEnv::AddDelDebugging(string udfname, int add)
{
	//if (add)
	//	UDFsDebugging.insert(udfname);
	//else
	//	UDFsDebugging.erase(udfname);
}