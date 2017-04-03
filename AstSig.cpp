#include <sstream>
#include <list>
#include <exception>
#include <math.h>
#include <time.h>
#include "sigproc.h"

#ifndef CISIGPROC
#include "psycon.tab.h"
#else
#include "cipsycon.tab.h"
#endif

void checkVector(const AstNode *pnode, CSignals &checkthis, string addmsg="");
void checkAudioSig(const AstNode *pnode, CSignals &checkthis, string addmsg="");
void blockCell(const AstNode *pnode, CSignals &checkthis);

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
		pEnv->RefCount++;
	} else
		pEnv = new CAstSigEnv(DefaultFs);
}


CAstSig::CAstSig(const CAstSig &org)
{
	throw "Internal error: Copy constructor is prohibited. You probably meant to call CAstSig(&env)." ;
}


CAstSig::CAstSig(const CAstSig *env)
: pAst(NULL), pAst_context(NULL), Script(""), statusMsg(""), fAllocatedAst(false), CallbackCIPulse(NULL), CallbackHook(env->CallbackHook)
{
	initGlobals(env);
}

CAstSig::CAstSig(const char *str, const CAstSig *env)
: pAst(NULL), pAst_context(NULL), statusMsg(""), fAllocatedAst(false), CallbackCIPulse(NULL), CallbackHook(env->CallbackHook)
{
	initGlobals(env);
	SetNewScript(str);
}

CAstSig::CAstSig(AstNode *pnode, const CAstSig *env)
: pAst(pnode), pAst_context(NULL), Script(""), statusMsg(""), fAllocatedAst(false), CallbackCIPulse(NULL), CallbackHook(env->CallbackHook)
{
	initGlobals(env);
}


CAstSig::CAstSig(const int fs)
: pAst(NULL), pAst_context(NULL), Script(""), statusMsg(""), fAllocatedAst(false), pEnv(new CAstSigEnv(fs)), CallbackCIPulse(NULL), CallbackHook(NULL)
{
}

CAstSig::CAstSig(const char *str, const int fs)
: pAst(NULL), pAst_context(NULL), statusMsg(""), fAllocatedAst(false), pEnv(new CAstSigEnv(fs)), CallbackCIPulse(NULL), CallbackHook(NULL)
{
	SetNewScript(str);
}

CAstSig::CAstSig(AstNode *pnode, const int fs)
: pAst(pnode), pAst_context(NULL), Script(""), statusMsg(""), fAllocatedAst(false), pEnv(new CAstSigEnv(fs)), CallbackCIPulse(NULL), CallbackHook(NULL)
{
}


CAstSig::~CAstSig()
{
	if (pAst_context)
	{ int y=5;}
	if (pEnv->RefCount > 0)
		pEnv->RefCount--;
	else
		delete pEnv;
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
	Sig.bufBlockSize=1;
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

void AddConditionMeetingBlockAsChain(CSignals *Sig, CSignals *psig, int iBegin, int iNow, CSignal &part)
{
	part.UpdateBuffer(iNow-iBegin);
	memcpy(part.buf, (void*)(psig->buf+iBegin), (iNow-iBegin)*sizeof(double));
	part.tmark = 1.e3*iBegin/psig->GetFs();
	if (Sig->nSamples==0)	*Sig = part;
	else					Sig->AddChain(part);
}


//#define  T_NUMBER 284
//#define  T_STRING 285
//#define  T_ID 286

CSignals &CAstSig::Compute(const AstNode *pnode)
{
	Sig.bufBlockSize=1;
	int count(0);
	int mn, mx;
	CSignals tsig, isig, *psig, lsig, rsig;
	CSignals rms, rms2;
	bool trinary(false);
	if (!pnode)
		throw "Null AST node!";
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
			tsig = Compute(p);
			if (!tsig.IsScalar())	throw CAstException(p, "Array index must be a scalar.");
			int id = (int)tsig.value();
			if ((double)id!=tsig.value()) throw CAstException(p, "Array index must be a positive integer.");
			if (!(psig = RetrieveTag(pnode->str)))
				throw CAstException(pnode, "Unknown array - ", pnode->str);
			Sig = psig->cell.at(id-1); // because AUX is one-based
//			Sig.cell.clear(); // if it is a single extraction, any trailing cells should be removed. // ==>This is probably not necessary 4/23/2016 bjk 
		} else { // a celled-CSignals object without an index or an CSignals object with an extractor operator
			if (!(psig = RetrieveTag(pnode->str)))
				throw CAstException(pnode, "Unknown variable - ", pnode->str);
			Sig = *psig;
		}
		break;
	case '=':
		if (!p)
			throw CAstException(pnode, "Internal error: Empty assignment!");
		if (p->next) {	/* another child means cell array index */
			isig = Compute(p->next);
			if (!isig.IsScalar())
				throw CAstException(p->next, "Array index must be a scalar.");
			SetCell(pnode->str, round(isig.value()), Compute(p));
		} else
		{
			if (p->next && p->next->type==NODE_VECTOR) 
			{}
			SetTag(pnode->str, Compute(p));
		}
		break;
	case NODE_INITCELL: // x={"bjk",noise(300), 4.5555}
		// always update with the new statement, discard what was in there previously.
		for (; p;count++, p=p->next)
			;
		p = pnode->child;
		if (!p) throw CAstException(pnode, "Empty cell definition.");
		Sig.cell.reserve(count);
		for (int i=0; p;i++, p=p->next)
		{
			AddCell(pnode->str, CAstSig(p).Compute(p));
		}
		if (pnode->str)
			Sig.cell.clear(); // Sig needs to clear cell here, so anything following won't have lingering cells.
		break;
	case '+':
		tsig = Compute(p);
		blockCell(pnode,  Sig);
		Compute(p->next);	// Sig gets the result.
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
		Compute(p->next);
		Sig *= tsig;
		break;
	case '/':
		tsig = Compute(p);
		blockCell(pnode,  Sig);
		Compute(p->next).Reciprocal();
		Sig *= tsig;
		break;
	case T_NEGATIVE:
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
		Sig += &tsig;
		Sig.MergeChains();
		break;
	case '<':
	case '>':
	case T_COMP_LE:
	case T_COMP_GE:
	case T_COMP_EQ:
	case T_COMP_NE:
	case T_LOGIC_AND:
	case T_LOGIC_OR:
		blockCell(pnode,  Sig);
		rsig = Compute(p->next); 
		Compute(p); 
		Sig.OPERATE(rsig,pnode->type);
		break;
	case T_LOGIC_NOT:
		blockCell(pnode,  Sig);
		Sig = Compute(p);
		Sig.OPERATE(rsig,pnode->type); // rsig is a dummy for func signature.
		break;
	case T_IF:
		for (; p && p->next; p=p->next->next)	// p is a condition of 'if' or 'elseif', p->next is the code block.
			if (Compute(p).value())
				return Compute(p->next);	// no further processing of this 'if' statement.
		// now p is at the end of 'if' statement, without executing any conditional code.
		if (p)	// if not null, it's the 'else' code block
			Compute(p);
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
		{
		double ss = Compute(p).value();
		while (Compute(p).value() && !fExit && !fBreak)
			Compute(p->next);
		fBreak = false;
		}
		break;
	case T_FOR:
		fExit=fBreak=false;
		tsig = Compute(p->child);
		for (int i=0; i<tsig.nSamples && !fExit && !fBreak; i++) {
			SetTag(p->str, CSignals(tsig.buf[i]));
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
		break;
	case NODE_BLOCK:
		for (fExit=fBreak=fContinue=false; p && !fExit && !fBreak && !fContinue; p=p->next)
			Compute(p);
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
	case T_DUR:
		Sig = Compute(pAst_context).alldur();
		break;
#endif //CISIGPROC
	case NODE_EXTRACT:
		double t[2];
		pAst_context = (AstNode*)calloc(1, sizeof(AstNode));
		pAst_context->type = T_ID;
		pAst_context->str = (char*)malloc(strlen(pnode->child->str)+1);
		strcpy(pAst_context->str, pnode->child->str);
		p = p->next;
		for (int k(0); k<2; k++, p=p->next) {
			Sig = Compute(p);
				if (!Sig.IsScalar())
					throw CAstException(p, "The arguments of extraction must be scalars.");
			t[k] = Sig.value();
		}
		yydeleteAstNode(pAst_context, 0);
		pAst_context=NULL;
		Compute(pnode->child);
		checkAudioSig(pnode,  Sig);
		Sig.Trim(t[0], t[1]);
		break;
	case NODE_IXASSIGN:
		if (!p)
			throw CAstException(pnode, "Internal error: Empty assignment!");
		if (p->next && p->next->next)
			;// cell array indexed assignment
		else if (!(p->next && p->next->child && !p->next->child->next))
			throw CAstException(pnode, "Indexed assignment must have one argument.");
		psig = RetrieveTag(pnode->str);
		if (p->next->child) // insert
			isig = Compute(p->next->child); // index (non-audio) or time point (audio)
		else	//replace
		{
			if (!p->next->next)
				throw CAstException(pnode, "Time-range assignment must have two arguments.");
			isig = Compute(p->next); 
			Compute(p->next->next); 
			isig += &Sig;
		}
		tsig = Compute(p); // rhs
		if (!psig)
		{
			if (tsig.nSamples==0)		Sig = *psig;
			else if (tsig.nSamples==1)	
			{
				if (isig.nSamples!=1) 
					throw CAstException(pnode, "Referencing a non-existent variable is allowed only with a scalar or single char is on the RHS and with a single index on the LHS.");
				char buf[64], buf2[16];
				sprintf(buf, "%s=zeros(%d);%s(%d)=", pnode->str, isig.value(), pnode->str, isig.value());
				string tempstr = (tsig.GetType()==CSIG_SCALAR) ? "%g)" : "%s)";
				sprintf(buf2, tempstr.c_str(), tsig.value());
				strcat(buf, tempstr.c_str());  strcat(buf, buf2); 
				CAstSig temp(buf, tsig.GetFs());
				temp.Compute();
				Sig = temp.Sig;
			}
			else
				throw CAstException(pnode, "Referencing a non-existent variable is allowed only when a scalar or single char is on the RHS.");
		}
		else if (psig->GetType()==CSIG_AUDIO)
		{
			if (tsig.GetType()!=CSIG_AUDIO && tsig.GetType()!=CSIG_EMPTY)
				throw CAstException(pnode, "Referencing timepoint(s) in an audio variable requires another audio signal on the RHS.");
			if (p->next->child) 
				psig->Insert(isig.value(), tsig);
			else
				psig->Replace(tsig, isig.buf[0], isig.buf[1]);
			Sig = *psig;
		}
		else if (psig->GetType()==CSIG_VECTOR || psig->GetType()==CSIG_CELL)
		{
			mn = round(((datachunk)isig).Min());
			mx = round(((datachunk)isig).Max());
			if (mn < 1)
				throw CAstException(p->next->child, "Index cannot be smaller than 1.");
			if (tsig.GetType()==CSIG_EMPTY)
			{
				if (isig.GetType()==CSIG_EMPTY) Sig=*psig;
				else
				{
					Sig.UpdateBuffer(psig->nSamples);
					int id = (int)(isig.buf[0]+.5);
					memcpy(&Sig.buf[0], &psig->buf[0], (id-1)*sizeof(double));
					int nextid = id-1;
					int adv, k(1);
					for (; k<isig.nSamples; k++)
					{
						adv = (id = (int)(isig.buf[k]+.5)) - (int)(isig.buf[k-1]+.5) - 1;
						memcpy(&Sig.buf[nextid], &psig->buf[nextid+k], adv*sizeof(double));
						nextid += adv;
					}
					adv = (id = psig->nSamples) - (int)(isig.buf[k-1]+.5);
					memcpy(&Sig.buf[nextid], &psig->buf[nextid+k], adv*sizeof(double));
					nextid += adv;
					Sig.nSamples = nextid;
					SetTag(pnode->str, Sig);
				}
			}
			else
			{
				if (isig.nSamples != tsig.nSamples)
					throw CAstException(pnode, "Number of indices and number of elements on right side must be the same.");
				while (!(psig = RetrieveTag(pnode->str)))
					SetTag(pnode->str, CSignals(pEnv->Fs));
				if (int maxIndex=mx)
					if (maxIndex > psig->nSamples)
						psig->UpdateBuffer(maxIndex);
				for (int i=0; i<isig.nSamples; i++)
					psig->buf[round(isig.buf[i])-1] = tsig.buf[i];
			}
		}
		break;
#ifndef CISIGPROC
	case T_LENGTH:
		tsig = Compute(pAst_context);
		Sig.SetValue(tsig.nSamples);
		break;
#endif //CISIGPROC
	case NODE_CALL: // built-in function calls come here
		if (p && !p->next /* only one argument */ && (psig = RetrieveTag(pnode->str))) {
			if (psig->GetType()==CSIG_CELL) throw CAstException(p, "A cell array cannot be accessed with ( ).");
			if (p->type!=NODE_CALL && p->LastChild) // This means conditional indexing
			{
				isig = Compute(p);
				Sig.Reset(psig->GetFs());
				if (psig->GetType()==CSIG_AUDIO)
				{
					bool prev = isig.buf[0]>0;
					int k, id1(0);
					CSignals part(psig->GetFs());
					for (k=1; k<isig.nSamples; k++)
					{
						//First, find the continguous range that satisfy the condition
						if (isig.buf[k]>0) 
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
						if (isig.buf[k]>0) indexholder[id++]=k;
					}
					Sig.UpdateBuffer(id);
					Sig.SetReal();
					Sig.SetFs(psig->GetFs());
					for (int k=0; k<id; k++)
						Sig.buf[k] = psig->buf[indexholder[k]];	// -1 for one-based indexing
					delete[] indexholder;
				}
			}
			else
			{
				pAst_context = (AstNode*)calloc(1, sizeof(AstNode));
				pAst_context->type = T_ID;
				pAst_context->str = (char*)malloc(strlen(pnode->str)+1);

				strcpy(pAst_context->str, pnode->str);
				// Extraction by indices
				isig = Compute(p);
				yydeleteAstNode(pAst_context, 0);
				pAst_context=NULL;

				mn = round(((datachunk)isig).Min());
				mx = round(((datachunk)isig).Max());
				if (mn < 1)
					throw CAstException(p, "Index cannot be smaller than 1.");
				if (mx > psig->nSamples)
					throw CAstException(p, "Index exceeds size of vector.");
				Sig.UpdateBuffer(isig.nSamples);
				if (psig->bufBlockSize==2) 
				{
					Sig.SetComplex();
					for (int i=0; i<isig.nSamples; i++)
						Sig.cbuf[i] = psig->cbuf[round(isig.buf[i])-1];	// -1 for one-based indexing
				}
				else
				{
					Sig.SetReal();
					Sig.SetFs(psig->GetFs());
					for (int i=0; i<isig.nSamples; i++)
						Sig.buf[i] = psig->buf[round(isig.buf[i])-1];	// -1 for one-based indexing
				}
			}
			break;
		} else if (AstNode *pUDF=RetrieveUDF(pnode->str)) {
			CallSub(pUDF, pnode);
			break;
		}	else if (pEnv->NoAuxFiles.find(pnode->str) == pEnv->NoAuxFiles.end()) {	// if the Aux file hasn't been tried,
			string auxfilename = pnode->str;
			if (FILE *auxfile = OpenFileInPath(auxfilename, "aux")) { // THis is where the udf file is read and processed from the path
				// process Aux files
				try {
					CAstSig aux;
					aux.SetNewFile(auxfile);
					fclose(auxfile);
					if (aux.pAst->type == NODE_BLOCK) {
						// multiple function definitions expected
						for (p=aux.pAst->child; p; p=p->next)
							if (p->type != T_FUNCTION)
								throw CAstException(p, "All codes in AUX file must be inside function definitions.");
						p = aux.pAst->child;
					} else
						p = aux.pAst;
					if (p->type != T_FUNCTION)
						throw CAstException(p, "AUX file must start with a function definition.");
					if (strcmp(p->str, pnode->str))
						throw CAstException(p, "The name of the first function in AUX file must be the same as the filename.");
					pEnv->UDFs[pnode->str] = p;	// p->next might be valid, which is a local function. It will be taken care of in CallSub()
					// The following should be after all the throws. Otherwise, the UDF AST will be dangling.
					// To prevent de-allocation of the AST of the UDF when the aux is destroyed.
					if (aux.pAst->type == NODE_BLOCK)
						aux.pAst->child = NULL;
					else
						aux.pAst = NULL;
				} catch (const char *errmsg) {
					fclose(auxfile);
					throw CAstException(pnode, "Calling "+string(pnode->str)+"( )\n\nIn file '"+auxfilename+"':\n"+errmsg);
				} catch (const CAstException &e) {
					fclose(auxfile);
					throw CAstException(pnode, "Calling "+string(pnode->str)+"( )\n\nIn file '"+auxfilename+"':\n"+e.getErrMsg());
				}
				CallSub(p, pnode);
				break;
			} 	else
				pEnv->NoAuxFiles.insert(pnode->str);	// mark it was tried.
				// go through remaining of this 'case' block.
		}
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


CSignals &CAstSig::CallSub(const AstNode *pUDF, const AstNode *pCall)
{
	ostringstream oss;
	// pUDF->child : parameter list
	// pUDF->child->next : UDF body

	if (!(pUDF && pUDF->type == T_FUNCTION))
		throw CAstException(pUDF, "Not a function definition!");
	if (!(pUDF->child && pUDF->child->type == NODE_IDLIST))
		throw CAstException(pUDF, "No parameter list!");

	CAstSig SubAstSig(pUDF->child->next, this->pEnv->Fs);	// does not pass 'this' so that SubAstSig has its own variable scope. Global variables are not available inside the function, for now. Might need 'global' keyword?
	SubAstSig.CallbackCIPulse = this->CallbackCIPulse;
	SubAstSig.CallbackHook = this->CallbackHook;
	AstNode *pf, *pa;	 // formal & actual parameter
	int cnt, cnt2;
	// output parameter binding
	AstNode *pOutParam = pUDF->child->next->next;
	if (pOutParam) {
		CSignals *psig;
		switch (pOutParam->type) {
		case T_ID:
			Sig.Reset();
			SubAstSig.pEnv->Refs[pOutParam->str] = &Sig;
			SubAstSig.SetTag("nargout", 1.0);
			break;
		case NODE_INITCELL:	// cell array return
			if (!(pCall->child && pCall->child->type == NODE_ARGS && pCall->child->next && pCall->child->next->type == NODE_INITCELL)) {
				oss << "Function '" << pCall->str << "' returns a cell array.";
				throw CAstException(pCall, oss.str());
			}
			pf=pOutParam, pa=pCall->child->next;
			map<int,CSignals> *pArray;
			while (!(pArray = RetrieveArray(pa->str)))	// new array, create
				pEnv->Arrays[pa->str];
			SubAstSig.pEnv->ArrRefs[pf->str] = pArray;
			SubAstSig.SetTag("nargout", 1.0);
			break;
		case NODE_VECTOR:	// multi-value return
			pf = pOutParam->child;
			if (!(pCall->child && pCall->child->type == NODE_ARGS && pCall->child->next && pCall->child->next->type == NODE_VECTOR)) {
				if (pf->type == T_ID) {
					SubAstSig.pEnv->Refs[pOutParam->child->str] = &Sig;
					SubAstSig.SetTag("nargout", 1.0);
					break;
				} else if (pf->type == NODE_INITCELL) {
					oss << "Function '" << pCall->str << "' returns a cell array at first element.";
					throw CAstException(pCall, oss.str());
				} else
					throw CAstException(pCall, "Calling "+string(pCall->str)+"( )\n\nIn function definition:\n"
								"All elements of vector on the left-hand side of assignment must be variables.");
			}
			for (pa=pCall->child->next->child, cnt=0; pf && pa; pf=pf->next, pa=pa->next, cnt++) {
				if (pf->type != T_ID && pf->type != NODE_INITCELL)
					throw CAstException(pCall, "Calling "+string(pCall->str)+"( )\n\nIn function definition:\n"
								"All elements of vector on the left-hand side of assignment must be variables.");
				switch (pa->type) {
				case T_ID:
					if (pf->type == NODE_INITCELL) {
						oss << "Function '" << pCall->str << "' returns a cell array at " << cnt+1 << "th element.";
						throw CAstException(pCall, oss.str());
					}
					while (!(psig = RetrieveTag(pa->str)))	// new variable, create
						SetTag(pa->str, CSignals());
					psig->nSamples = 0;
					SubAstSig.pEnv->Refs[pf->str] = psig;
					break;
				case NODE_INITCELL:
					if (pf->type == T_ID) {
						oss << "Function '" << pCall->str << "' returns a regular variable at " << cnt+1 << "th element.";
						throw CAstException(pCall, oss.str());
					}
					while (!(pArray = RetrieveArray(pa->str)))	// new array, create
						pEnv->Arrays[pa->str];
					SubAstSig.pEnv->ArrRefs[pf->str] = pArray;
					break;
				default:
					throw CAstException(pa, "All elements of vector on the left-hand side of assignment must be variables.");
				}
			}
			if (pa) {
				for (cnt2=0; pa; pa=pa->next, cnt2++)
					;
				oss << "Too many return arguments for function '" << pCall->str << "' - expecting " << cnt << ", supplied " << cnt+cnt2 << ".";
				throw CAstException(pCall, oss.str());
			}
			SubAstSig.SetTag("nargout", (double)cnt);
			break;
		default:
			throw CAstException(pOutParam, "Internal error! Unexpected node type - ", pOutParam->type);
		}
	}
	// input parameter binding
	pa = pCall->child;
	if (pa && pa->type == NODE_ARGS)
		pa = pa->child;
	for (pf=pUDF->child->child, cnt=0; pf && pa; pf=pf->next, pa=pa->next, cnt++) {
		if (pa->type == NODE_INITCELL) {
			if (pf->type != NODE_INITCELL) {
				oss << "Function '" << pCall->str << "' expects a non-array value at " << cnt+1 << "th parameter.";
				throw CAstException(pCall, oss.str());
			}
			if (pa->str)
				SubAstSig.pEnv->Arrays[pf->str] = pEnv->Arrays[pa->str];
			else {	// unnamed cell array, which means it's an actual initialization list.
				AstNode *p = pa->child;
				for (int i=1; p;i++, p=p->next)
					SubAstSig.SetCell(pf->str, i, Compute(p));
				// Check if this is working.... 4/3/2016 bjk
			}
		} else {
			if (pf->type == NODE_INITCELL) {
				oss << "Function '" << pCall->str << "' expects a cell array at " << cnt+1 << "th parameter.";
				throw CAstException(pCall, oss.str());
			}
			SubAstSig.SetTag(pf->str, Compute(pa));
		}
	}
	if (pa) {
		for (cnt2=0; pa; pa=pa->next, cnt2++)
			;
		oss << "Too many arguments for function '" << pCall->str << "' - expecting " << cnt << ", supplied " << cnt+cnt2 << ".";
		throw CAstException(pCall, oss.str());
	}
	SubAstSig.SetTag("nargin", (double)cnt);
	SubAstSig.pEnv->UDFs = pEnv->UDFs;	// copy other function definitions - especially for recursive calls.
	SubAstSig.pEnv->NoAuxFiles = pEnv->NoAuxFiles;
	SubAstSig.pEnv->AuxPath = pEnv->AuxPath;
	for (AstNode *p=pUDF->next; p; p=p->next)	// AUX file local functions
		if (p->type == T_FUNCTION)
			SubAstSig.pEnv->UDFs[p->str] = p;
	try {
		SubAstSig.Compute();
		SubAstSig.pEnv->UDFs.clear();	// clear it so that function definitions will not be deleted by the destructor of SubAstSig
	} catch (const char *errmsg) {
		SubAstSig.pEnv->UDFs.clear();
		throw CAstException(pCall, "Calling "+string(pCall->str)+"( )\n\nIn function definition:\n"+errmsg);
	}
	if (!pOutParam)	// no output parameter specified.
		Sig = SubAstSig.Sig;
	return Sig;
}


CAstSig &CAstSig::Reset(const int fs, const char* path)
{
	map<string,AstNode *>::iterator it;
	for (it=pEnv->UDFs.begin(); it!=pEnv->UDFs.end(); it++)
		yydeleteAstNode(it->second, 0);
	pEnv->UDFs.clear();
	pEnv->Refs.clear();
	pEnv->Tags.clear();
	pEnv->ArrRefs.clear();
	pEnv->Arrays.clear();
	pEnv->NoAuxFiles.clear();
	if (path)	pEnv->AuxPath=path; // I don't know if this might cause a trouble.
	if (fs > 1)
		pEnv->Fs = fs;
	return *this;
}


CSignals *CAstSig::RetrieveTag(const char *tagname)
{
	if (!tagname) return NULL;
	map<string,CSignals *>::iterator itRef;
	map<string,CSignals>::iterator itTag;

	itRef = pEnv->Refs.find(tagname);
	if (itRef != pEnv->Refs.end())
		return itRef->second;
	itTag = pEnv->Tags.find(tagname);
	if (itTag != pEnv->Tags.end())
		return &itTag->second;
	return NULL;
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


map<int,CSignals> *CAstSig::RetrieveArray(const char *arrayname)
{
	map<string,map<int,CSignals> *>::iterator itArrRef;
	map<string,map<int,CSignals>>::iterator itArr;

	itArrRef = pEnv->ArrRefs.find(arrayname);
	if (itArrRef != pEnv->ArrRefs.end())
		return itArrRef->second;
	itArr = pEnv->Arrays.find(arrayname);
	if (itArr != pEnv->Arrays.end())
		return &itArr->second;
	return NULL;
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

CAstSig &CAstSig::SetCell(const char *name, const unsigned int i, const CSignals &sig)
{
	CSignals tp(sig);
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


void CAstSig::SetRef(const char *ref, const char *var)
{
	CAstSig astsig(this);
	CSignals *psig;
	char errmsg[250];

	astsig.SetNewScript(var);
	if (astsig.pAst->type != T_ID)
		throw "SetRef( ) : Expects only a single variable in the second parameter.";
	AstNode *p = astsig.pAst->child;
	if (p) {	/* child means cell array index */
		CSignals tsig = astsig.Compute(p);
		if (!tsig.IsScalar())
			throw "SetRef( ) : Array index must be a scalar.";
		map<int,CSignals> *pArray;
		if (!(pArray = RetrieveArray(astsig.pAst->str))) {
			sprintf(errmsg, "SetRef( ) : Unknown array - %s.", astsig.pAst->str);
			throw errmsg;
		}
		psig = &(*pArray)[round(tsig.value())];
	} else {
		if (!(psig = RetrieveTag(astsig.pAst->str))) {
			sprintf(errmsg, "SetRef( ) : Unknown tag - %s.", astsig.pAst->str);
			throw errmsg;
		}
	}
	pEnv->Refs[ref] = psig;
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

FILE *CAstSig::OpenFileInPath(string &fname, const string ext)
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
: Fs(fs), RefCount(0)
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
