#include <math.h>
#include <stdlib.h>
#include <string.h> // aux_file
#include <time.h>
#include <atlrx.h>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

#ifdef _WINDOWS
#include "audfret.h"
#endif

#include "sigproc.h"
#ifndef CISIGPROC
#include "psycon.tab.h"
#else
#include "cipsycon.tab.h"
#endif

map<double, FILE *> file_ids;


#ifndef AUX_NO_EXTRA
void aux_text(CAstSig &ast, const AstNode *pnode, const AstNode *p);
void aux_pause(CAstSig &ast, const AstNode *pnode, const AstNode *p);
void aux_plot(CAstSig &ast, const AstNode *pnode, const AstNode *p);
void aux_close(CAstSig &ast, const AstNode *pnode, const AstNode *p);
void aux_delete(CAstSig &ast, const AstNode *pnode, const AstNode *p, CSignal *carry=NULL);
void aux_set(CAstSig &ast, const AstNode *pnode, const AstNode *p);
void aux_get(CAstSig &ast, const AstNode *pnode, const AstNode *p);
#endif

complex<double> ddsqrt(complex<double> x) {	return sqrt(x); }
complex<double> cmpexp(complex<double> x) {	return exp(x); }
complex<double> cmpcos(complex<double> x) {	return cos(x); }
complex<double> cmpcosh(complex<double> x) { return cosh(x); }
complex<double> cmplog(complex<double> x) {	return log(x); }
complex<double> cmplog10(complex<double> x) { return log10(x); }
complex<double> cmpsin(complex<double> x) {	return sin(x); }
complex<double> cmpsinh(complex<double> x) { return sinh(x); }
complex<double> cmptan(complex<double> x) {	return tan(x); }
complex<double> cmptanh(complex<double> x) { return tanh(x); }

double cmpreal(complex<double> x) { return real(x); }
double cmpimag(complex<double> x) { return imag(x); }
double cmpabs(complex<double> x) {	return abs(x); }
complex<double> cmpconj(complex<double> x) {	return conj(x); }
//double cmpnorm(complex<double> x) { return norm(x); }
double cmpangle(complex<double> x) { return arg(x); }

void EnumAudioVariables(CAstSig &ast, vector<string> &var)
{
	var.clear();
	for (map<string, CSignals>::iterator what=ast.Vars.begin(); what!=ast.Vars.end(); what++)
		if (what->second.GetType()==CSIG_AUDIO) var.push_back(what->first);
}

void CAstSig::checkAudioSig(const AstNode *pnode, CSignals &checkthis, string addmsg)
{
	if (checkthis.GetType()==CSIG_AUDIO) return;
	string msg("An audio signal is required ");
	if (checkthis.GetType()==CSIG_CELL && ((CSignal)checkthis).GetType()==CSIG_AUDIO) return;
	throw CAstException(pnode, this, (msg+addmsg).c_str());
}

void CAstSig::checkComplex (const AstNode *pnode, CSignals &checkthis)
{
	string msg("A complex vector is required ");
	if (!checkthis.IsComplex())
		throw CAstException(pnode, this, msg.c_str());
}

void CAstSig::checkVector(const AstNode *pnode, CSignals &checkthis, string addmsg)
{
	string msg("A non-audio array is required ");
	if (!checkthis.IsEmpty() && checkthis.GetType()!=CSIG_VECTOR && checkthis.GetType()!=CSIG_SCALAR)
		throw CAstException(pnode, this, (msg+addmsg).c_str());
}

void CAstSig::checkString(const AstNode *pnode, CSignals &checkthis, string addmsg)
{
	if (checkthis.GetType()==CSIG_STRING) return;
	string msg("A string is required ");
	if (checkthis.GetType()==CSIG_CELL && ((CSignal)checkthis).GetType()==CSIG_STRING) return;
	throw CAstException(pnode, this, (msg+addmsg).c_str());
}

void CAstSig::blockCell(const AstNode *pnode, CSignals &checkthis)
{
	string msg("Not valid with a cell variable ");
	if (checkthis.GetType()==CSIG_CELL)
		if (((CSignal)checkthis).GetType()==CSIG_EMPTY)
			throw CAstException(pnode, this, msg.c_str());
}

void CAstSig::blockScalar(const AstNode *pnode, CSignals &checkthis)
{
	string msg("Not valid with a scalar variable ");
	if (checkthis.GetType()==CSIG_SCALAR || checkthis.GetType()==CSIG_EMPTY)
		throw CAstException(pnode, this, msg.c_str());
}

void CAstSig::blockString(const AstNode *pnode, CSignals &checkthis)
{
	string msg("Not valid with a string variable ");
	if (checkthis.GetType()==CSIG_STRING)
		throw CAstException(pnode, this, msg.c_str());
}

void CAstSig::blockComplex(const AstNode *pnode, CSignals &checkthis)
{
	string msg("Not valid with a complex variable ");
	if (checkthis.IsComplex())
		throw CAstException(pnode, this, msg.c_str());
}

double aux_db(const double x)
{
	return pow(10, x/20);
}

double aux_sgn(const double x)
{
	return (x==0.)?0.:((x>0.)?1.:-1.);
}

double aux_round(const double x)
{
	return (double)(int)(x+.5);
}

double aux_fix(const double x)
{
	return (double)(int)x;
}

double aux_exp(const double base, const double exponent)
{
	return pow(base,exponent);
}

complex<double> aux_cexp(complex<double> base, complex<double> exponent)
{
	return pow(base,exponent);
}

double aux_mod(const double numer, const double denom)
{
	return fmod(numer,denom);
}

void aux_diff(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(array)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.checkVector(pnode, ast.Sig);
	ast.Compute(p); 
	ast.Sig.Diff();
}

void aux_cumsum(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(array)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.checkVector(pnode, ast.Sig);
	ast.Compute(p); 
	ast.Sig.Cumsum();
}

void aux_std(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(array, [biased])", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 2);
	int nArgs(0);
	for (const AstNode *cp=p; cp; cp=cp->next)	++nArgs;
	int flag(0);
	if (nArgs>1) 
	{
		CSignals arg = ast.Compute(p->next);
		if (!arg.IsScalar()) throw CAstException(pnode, &ast, fnsigs, string("second arg must be scalar"));
		if (arg.value()==1.) flag=1;
	}
	ast.Compute(p);
	CSignal out(1);
	out.SetValue(ast.Sig.Stdev(flag));
	ast.Sig = out;
}

void aux_minmax(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(minimum or maximum value)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 2);
	int nArgs(0);
	for (const AstNode *cp=p; cp; cp=cp->next)	++nArgs;
	ast.Compute(p);
	if (ast.Sig.IsEmpty()) return; //for empty input, empty outpu
	string fname = pnode->str;
	if (nArgs==1)
	{
		CSignal dummy, *extracted, out(1);
		int nChains = ast.Sig.CountChains();
		out.UpdateBuffer(nChains); // need a separate output variable because, otherwise, Sig gets changed with this UpdateBuffer call.
		int m(0), temp(-1), dum;
		bool loop(true);
		while( (extracted = ast.Sig.ExtractDeepestChain(&dummy))!=&ast.Sig || loop )
		{
			if (ast.Sig.IsString()) 
				temp=extracted->nSamples-1;
			if (fname == "max") out.buf[m++] = (double)((body*)extracted)->Max(dum,temp);
			else if (fname == "min") out.buf[m++] = (double)((body*)extracted)->Min(dum,temp);
			if (extracted == &ast.Sig) loop = false;
		}
		out.ReverseTime();
		if (ast.Sig.IsLogical()) out.MakeLogical();
		ast.Sig = out; // put it back.
	}
	else // 2
	{
		CSignals arg = ast.Compute(p->next);
		ast.Compute(p);
		if (arg.nSamples>1)
		{
			const char *fnsigs2[] = {"(For two arguments, at least one argument must be a scalar)", 0};
			if (ast.Sig.nSamples>1)
				throw CAstException(pnode, &ast, fnsigs2, "");
			ast.Sig.SwapContents1node(arg);
		}
		if (fname=="max") 	ast.Sig.Max(arg.value());
		else if (fname=="min") 	ast.Sig.Min(arg.value());
	}
}

void aux_getfs(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"()", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 0, 0);
	ast.Sig.SetValue(ast.GetFs());
}

void aux_rand(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(maximum value)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	double val;
	ast.Compute(p); val=ast.Sig.GetBuffer()[0];
	static bool initialized(false);
	if (!initialized)
	{
		srand((unsigned) time(0));
		initialized = true;
	}
	ast.Sig.SetValue((double)rand()/(double)RAND_MAX*val);
}

void aux_irand(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(maximum integer value)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	aux_rand(ast, pnode, p);
	ast.Sig.GetBuffer()[0] = (double)ceil(ast.Sig.GetBuffer()[0]);
}

void aux_randperm(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	static bool initialized(false);
	if (!initialized)
	{
		srand((unsigned) time(0));
		initialized = true;
	}
	const char *fnsigs[] = {"(integer)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Compute(p);
	int ival  = (int)ast.Sig.GetBuffer()[0];
	ast.Sig.Reset(1);
	ast.Sig.UpdateBuffer(ival);
	int m,n;
	double hold;
	for (int i=0; i<ival; i++)ast.Sig.buf[i] = (double)(i+1);
	int repeat = (int)sqrt(ival*100.); // swapping sqrt(ival*100.) times
	for (int i=0; i<repeat; i++)
	{
		m = (int)((double)rand()/(double)RAND_MAX*ival);
		do { n = (int)((double)rand()/(double)RAND_MAX*ival); }
		while (m==n);
		hold = ast.Sig.buf[m];
		ast.Sig.buf[m] = ast.Sig.buf[n];
		ast.Sig.buf[n] = hold;
	}
}



void aux_pitchange(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{


}

#ifndef NO_RESAMPLE

void aux_caret(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{ // % operator
	const char *fnsigs[] = {
		"(signal, scalar)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 2);
	char errstr[256] = "";
	ast.Compute(p->next);
	if (ast.Sig.IsScalar())
	{
		double param = ast.Sig.value();
		ast.Compute(p);
		if (ast.Sig.nSamples <= 1)
			throw CAstException(pnode, &ast, fnsigs, "1st argument must be a signal.");
		int orgfs = ast.Sig.GetFs();
		if (!ast.Sig.Resample(round(orgfs/param), errstr)) throw CAstException(pnode, &ast, string(errstr));
		ast.Sig.SetFs(orgfs);
	}
	else if (ast.Sig.GetType()==CSIG_VECTOR)
	{
		CSignal param((CSignal)ast.Sig);
		int len(ast.Sig.nSamples);
		vector<int> fsholder, lengthholder;
		ast.Compute(p);
		if (ast.Sig.nSamples <= 1)
			throw CAstException(pnode, &ast, fnsigs, "1st argument must be a signal.");
		int fs = ast.Sig.GetFs();
		for (int k(0); k<param.nSamples; k++) fsholder.push_back((int)(fs/param.buf[k]+.5));
		splitevenindices(lengthholder, ast.Sig.nSamples, len);
		if (!ast.Sig.Resample(fsholder, lengthholder, errstr)) throw CAstException(pnode, &ast, string(errstr));
	}
}

void aux_fmm(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(audio_signal, freq_variation_array)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 2);
	CSignals audio = ast.Compute(p);
	ast.checkAudioSig(pnode, audio, "first arg must be audio.");
	char errstr[256];
	int multiplier = 10;
	CSignals param = ast.Compute(p->next);
	if (param.GetType()==CSIG_STRING || param.GetType()==CSIG_CELL) 
		throw CAstException(pnode, &ast, fnsigs, "2nd argument must be either audio or vector.");
	if (param.nSamples >= audio.nSamples/10)
		throw CAstException(pnode, &ast, fnsigs, "2nd argument must have 1/10 or less the length of the 1st arg.");
	ast.Sig = audio;
	if (ast.Sig.fm2(param, multiplier, errstr)==NULL)
		throw CAstException(pnode, &ast, fnsigs, string(errstr));
}
#endif //NO_RESAMPLE

void processEscapes(string &str)
{
	size_t pos;
	for (size_t start=0; (pos=str.find('\\', start))!=string::npos; start=pos+1)
		switch (str[pos+1]) {
		case 'n':
			str.replace(pos, 2, "\n");
			break;
		case 't':
			str.replace(pos, 2, "\t");
			break;
		default:
			str.erase(pos, 1);
		}
}

void aux_sprintf(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(format_string, ...)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 0);

	CAtlRegExp<> regexp;
	REParseError status = regexp.Parse("%([-+ #0]+)?({\\z|\\*})?(\\.{\\z|\\*})?[hlL]?{[cuoxXideEgGfs]}" );
	if (REPARSE_ERROR_OK != status)
		throw CAstException(pnode, &ast, string("Internal error! RegExp.Parse( ) failed.")); ;

	ast.Sig.Reset(2);	// to get the output string
	CAstSig tast(&ast);	// to preserve this->Sig
	CAtlREMatchContext<> mcFormat;
	string fmtstring = tast.ComputeString(p);
	processEscapes(fmtstring);
	const char *fmtstr = fmtstring.c_str();
	for (const char *next; fmtstr && regexp.Match(fmtstr, &mcFormat, &next); fmtstr=next) {
		const CAtlREMatchContext<>::RECHAR* szStart = 0;
		const CAtlREMatchContext<>::RECHAR* szEnd = 0;
		string vstring;
		double v;
		string fmt1str(fmtstr, mcFormat.m_Match.szEnd-fmtstr);
		vector<char> outStr;
		outStr.resize(100);
		for (UINT nGroupIndex = 0; nGroupIndex < mcFormat.m_uNumGroups; ++nGroupIndex) {
			mcFormat.GetMatch(nGroupIndex, &szStart, &szEnd);
			if (nGroupIndex == 2 || (nGroupIndex < 2 && szStart && *szStart == '*')) {	// condition for consuming an argument
				if ((p = p->next) == NULL)
					throw CAstException(pnode, &ast, fnsigs, "Not enough arguments.");
				if (nGroupIndex == 2 && *szStart == 's')
					vstring = tast.ComputeString(p);
				else if (tast.Compute(p).IsScalar())
					v = tast.Sig.value();
				else
					throw CAstException(pnode, &ast, fnsigs, "Scalar value expected for this argument.");
				if (nGroupIndex != 2) {
					char width[20];
					sprintf(width, "%d", round(v));
					fmt1str.replace(szStart-fmtstr, 1, width);
				}
			}
		}
		switch (*szStart) {
		case 'e': case 'E':
		case 'g': case 'G':
		case 'f':
			sprintf(&outStr[0], fmt1str.c_str(), v);
			break;
		case 'c': case 'o':
		case 'x': case 'X':
		case 'i': case 'u':
		case 'd':
			sprintf(&outStr[0], fmt1str.c_str(), round(v));
			break;
		case 's':
			outStr.resize(vstring.size()+100);
			sprintf(&outStr[0], fmt1str.c_str(), vstring.c_str());
			break;
		}
		int n = ast.Sig.length();
		ast.Sig.UpdateBuffer(n + (int)strlen(&outStr[0]));
		strcpy(&ast.Sig.strbuf[n], &outStr[0]);
	}
	int n = ast.Sig.length();
	ast.Sig.UpdateBuffer(n + (int)strlen(fmtstr));
	strcpy(&ast.Sig.strbuf[n], &fmtstr[0]);
}

void aux_fopen(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(filename, mode)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 2);
	string filename = ast.MakeFilename(ast.ComputeString(p),"");
	char mode[8];
	strcpy(mode, ast.ComputeString(p->next).c_str());

	FILE *fl;
	if (!(fl = fopen(filename.c_str(), mode)))
		throw CAstException(pnode, &ast, "Cannot open file", filename);
	ast.Sig.SetValue((double)(int)fl);
	file_ids[(double)(int)fl] = fl;
}

void aux_fclose(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(file_ID)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Compute(p);
	if (!ast.Sig.IsScalar())
		throw CAstException(pnode, &ast, fnsigs, "First arg must be a file identifider");
	double fl = ast.Sig.value();
	FILE *file = file_ids[fl];
	if (!file || fclose(file)==EOF)
		throw CAstException(pnode, &ast, fnsigs, "Invalid file identifier");
	ast.Sig.SetValue(0);
	file_ids.erase(fl);
}

void aux_fprintf(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(filename_or_fileID, format_string, ...)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 0);

	FILE *file;
	bool openclosehere(1);
	CAtlRegExp<> regexp;
	REParseError status = regexp.Parse("%([-+ #0]+)?({\\z|\\*})?(\\.{\\z|\\*})?[hlL]?{[cuoxXideEgGfs]}" );
	if (REPARSE_ERROR_OK != status)
		throw CAstException(pnode, &ast, string("Internal error! RegExp.Parse( ) failed.")); ;
	//is first argument string?
	ast.Compute(p);
	if (ast.Sig.IsString())
	{
		string filename = ast.MakeFilename(ast.ComputeString(p), "txt");
		if (!(file = fopen(filename.c_str(), "a")))
			throw CAstException(pnode, &ast, "Cannot open file", filename);
	}
	else
	{
		if (!ast.Sig.IsScalar())
			throw CAstException(pnode, &ast, fnsigs, "fopen: first arg must be either string or a file identifider");
		file = file_ids[ast.Sig.value()];
		openclosehere = false;
	}
	try {	// need this to close the file on exception
		CAtlREMatchContext<> mcFormat;
		p = p->next;
		string fmtstring = ast.ComputeString(p);
		processEscapes(fmtstring);
		const char *fmtstr = fmtstring.c_str();
		for (const char *next; fmtstr && regexp.Match(fmtstr, &mcFormat, &next); fmtstr=next) {
			const CAtlREMatchContext<>::RECHAR* szStart = 0;
			const CAtlREMatchContext<>::RECHAR* szEnd = 0;
			string vstring;
			double v;
			string fmt1string(fmtstr, mcFormat.m_Match.szEnd-fmtstr);
			for (UINT nGroupIndex = 0; nGroupIndex < mcFormat.m_uNumGroups; ++nGroupIndex) {
				mcFormat.GetMatch(nGroupIndex, &szStart, &szEnd);
				if (nGroupIndex == 2 || (nGroupIndex < 2 && szStart && *szStart == '*')) {	// condition for consuming an argument
					if ((p = p->next) == NULL)
						throw CAstException(pnode, &ast, fnsigs, "Not enough arguments.");
					if (nGroupIndex == 2 && *szStart == 's')
						vstring = ast.ComputeString(p);
					else if (ast.Compute(p).IsScalar())
						v = ast.Sig.value();
					else
						throw CAstException(pnode, &ast, fnsigs, "Scalar value expected for this argument.");
					if (nGroupIndex != 2) {
						char width[20];
						sprintf(width, "%d", round(v));
						fmt1string.replace(szStart-fmtstr, 1, width);
					}
				}
			}
			switch (*szStart) {
			case 'e': case 'E':
			case 'g': case 'G':
			case 'f':
				fprintf(file, fmt1string.c_str(), v);
				break;
			case 'c': case 'o':
			case 'x': case 'X':
			case 'i': case 'u':
			case 'd':
				fprintf(file, fmt1string.c_str(), round(v));
				break;
			case 's':
				fprintf(file, fmt1string.c_str(), vstring.c_str());
				break;
			}
		}
		fprintf(file, fmtstr);
		if (openclosehere) fclose(file);
	} catch (const char *) {
		if (openclosehere) fclose(file);
		throw;
	} catch (const CAstException &) {
		if (openclosehere) fclose(file);
		throw;
	}
}

void aux_colon(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(scalar:scalar) or (scalar:scalar:scalar)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 3);
	double val1, val2, step;
	CSignals third, second = ast.Compute(p->next);
	if (!second.IsScalar()) throw CAstException(pnode, &ast, string("All arguments must be scalars (check 2nd arg).")); 
	CSignals first = ast.Compute(p);
	if (!first.IsScalar()) throw CAstException(pnode, &ast, string("All arguments must be scalars (check 1st arg).")); 
	val1 = first.value();
	val2 = second.value();
	if (p->next->next) {
		third = ast.Compute(p->next->next);
		if (!third.IsScalar()) throw CAstException(pnode, &ast, string("All arguments must be scalars (check 3rd arg).")); 
		step = third.value();
	}
	else 
		step = (val1>val2) ? -1. : 1.;
	ast.Sig.Reset(1);
	int nItems = max(1, (int)((val2-val1)/step)+1);
	ast.Sig.UpdateBuffer(nItems);
	for (int i=0; i<nItems; i++)
		ast.Sig.buf[i] = val1 + step*i;
}

void aux_sscanf(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(string, format_string)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 0);

	string srcstring = ast.ComputeString(p);
	p = p->next;
	string fmtstring = ast.ComputeString(p);
	processEscapes(fmtstring);
	const char *fmtstr = fmtstring.c_str();
	const char *srcstr = srcstring.c_str();

	CAtlRegExp<> regexp;
	REParseError status = regexp.Parse("{%}([-+ #0]+)?({\\*})?({\\z})?[hlL]?{[cuoxXideEgGfs]}" );
	if (REPARSE_ERROR_OK != status)
		throw CAstException(pnode, &ast, string("Internal error! RegExp.Parse( ) failed.")); ;
	CAtlREMatchContext<> mcFormat;
	char fmttype;
	const char *fmtspec;	// pointer to '%', for the error message.
	int CharWidth, fmtcnt = 0;
	for (const char *next; fmtstr && regexp.Match(fmtstr, &mcFormat, &next); fmtstr=next) {
		const CAtlREMatchContext<>::RECHAR* szStart = 0;
		const CAtlREMatchContext<>::RECHAR* szEnd = 0;
		bool fIgnore = false;
		for (UINT nGroupIndex = 0; nGroupIndex < mcFormat.m_uNumGroups; ++nGroupIndex) {
			mcFormat.GetMatch(nGroupIndex, &szStart, &szEnd);
			switch (nGroupIndex) {
			case 3:	// type specifier
				if (++fmtcnt > 1)
					throw CAstException(pnode, &ast, string("Only one value can be read and returned."));
				fmttype = *szStart;
				break;
			case 2:	// width specifier
				CharWidth = -1;
				if (szStart && sscanf(szStart, "%d", &CharWidth) != 1)
					throw CAstException(pnode, &ast, string("Invalid width."));
				break;
			case 1:	// starting asterisk : read and ignore (don't store)
				if (szStart)
					fIgnore = true;
				break;
			case 0:	// '%'
				fmtspec = szStart;
				break;
			}
			if (fIgnore)
				break;
		}
		if (fIgnore)
			continue;	
	}
	int res, iv;
	unsigned uv;
	float fv;
	vector<char> vbuf;
	switch (fmttype) {
	case 'e': case 'E':
	case 'g': case 'G':
	case 'f':
		if ((res = sscanf(srcstr, fmtstring.c_str(), &fv)) == 1)
			ast.Sig.SetValue(fv);
		break;
	case 'd': case 'o':
	case 'x': case 'X':
	case 'i':
		if ((res = sscanf(srcstr, fmtstring.c_str(), &iv)) == 1)
			ast.Sig.SetValue(iv);
		break;
	case 'u':
		if ((res = sscanf(srcstr, fmtstring.c_str(), &uv)) == 1)
			ast.Sig.SetValue(uv);
		break;
	case 's': case 'c':
		if (CharWidth == -1)
			CharWidth = fmttype=='s'?(int)srcstring.size():1;
		vbuf.resize(CharWidth+1);
		if ((res = sscanf(srcstr, fmtstring.c_str(), &vbuf[0])) == 1) {
			ast.Sig.UpdateBuffer((int)strlen(&vbuf[0]));
			for (int i=0; vbuf[i]; ++i)
				ast.Sig.buf[i] = vbuf[i];
		}
	}
	if (res != 1)
		throw CAstException(pnode, &ast, "sscanf failed at", fmtspec);
	return;
}


void aux_fdelete(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(filename)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	string filename = ast.MakeFilename(ast.ComputeString(p), "txt");
	remove(filename.c_str());
}


void aux_error(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(message)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	string errmsg = ast.ComputeString(p);
	throw CAstException(pnode, &ast, "User raised error - " + errmsg);
}

#ifndef NO_SF

void aux_wave(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(filename)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	string filename = ast.MakeFilename(ast.ComputeString(p), "wav");
	char errStr[256];
	if (!ast.Sig.Wavread(filename.c_str(), errStr))
		throw CAstException(pnode, &ast, string(errStr));
	vector<string> audiovars;
	EnumAudioVariables(ast, audiovars);
	if (audiovars.size()>0)
	{
		int old = ast.Sig.GetFs();
		if (ast.Sig.GetFs()!=ast.GetFs() && !ast.Sig.Resample(ast.GetFs(),errStr))
			throw CAstException(pnode, &ast, string(errStr) + " " + filename);
		if (old != ast.Sig.GetFs())
			sformat(ast.statusMsg, 256, "(NOTE)File fs=%d Hz. The audio data resampled to %d Hz.", old, ast.Sig.GetFs());
	}
	else
	{
		ast.pEnv->Fs = ast.Sig.GetFs();
		sformat(ast.statusMsg, 64, "(NOTE)Sample Rate of AUXLAB Environment is now set to %d Hz.", ast.pEnv->Fs);
	}
}

void aux_wavwrite(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	char secondbuf[MAX_PATH];
	const char *fnsigs[] = {
		"(signal, filename)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 3);
	string filename = ast.MakeFilename(ast.ComputeString(p->next), "wav");
	CAstSig _ast(&ast);
	_ast.Compute(p);
	ast.checkAudioSig(pnode, _ast.Sig);
	if (p->next->next!=NULL)
	{
		CSignals second = ast.Compute(p->next->next);
		if (second.GetFs()!=2) throw CAstException(pnode, &ast, string("3rd argument must be a string."));
		second.getString(secondbuf,MAX_PATH);
	}
	else
		secondbuf[0]=0;
	char errStr[256];
	if (!_ast.Sig.Wavwrite(filename.c_str(), errStr, secondbuf))
		throw CAstException(pnode, &ast, string(errStr));
}


#endif // NO_SF



#ifdef _WINDOWS
#ifndef NO_PLAYSND
void aux_playstop(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	TerminatePlay();
}

void aux_playloop(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(audio_signal1, ...)", 0};
	int nArgs(0), k(0);
	for (const AstNode *cp=p; cp; cp=cp->next)
		++nArgs;
	if (nArgs==0) throw CAstException(pnode, &ast, fnsigs, string("An audio signal is required."));
	ast.Compute(p);
	char errstr[64];
	for (const AstNode *cp=p; cp; cp=cp->next, k++)
	{
		ast.Compute(cp);
		sprintf(errstr, "argument %d is not an audio signal.", k);
		ast.checkAudioSig(pnode,  ast.Sig, errstr);
	}
	double dontcare(300.);
	for (const AstNode *cp=p; cp; cp=cp->next, k++)
	{
		ast.Compute(cp);
		ast.Sig.PlayArray(0, WM_APP+100, GetHWND_WAVPLAY(), &dontcare, errstr,1);
	}
}

void aux_play(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(audio_signal1, ...)", 0};
	int nArgs(0), k(0);
	for (const AstNode *cp=p; cp; cp=cp->next)
		++nArgs;
	if (nArgs==0) throw CAstException(pnode, &ast, fnsigs, string("An audio signal is required."));
	ast.Compute(p);
	char errstr[64];
	for (const AstNode *cp=p; cp; cp=cp->next, k++)
	{
		ast.Compute(cp);
		sprintf(errstr, "argument %d is not an audio signal.", k);
		ast.checkAudioSig(pnode,  ast.Sig, errstr);
	}
	double dontcare(300.);
	for (const AstNode *cp=p; cp; cp=cp->next, k++)
	{
		ast.Compute(cp);
		ast.Sig.PlayArray(0, 0, NULL, &dontcare, errstr);
	}
}
#endif // NO_PLAYSND

void aux_cont(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	ast.Compute(p);
}

void aux_show(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(format_string, ...)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 0);

	ostringstream caption;
	caption << "Line " << pnode->line;
	aux_sprintf(ast, pnode, p);
	MessageBox(NULL, ast.Sig.string().c_str(), caption.str().c_str(), MB_ICONINFORMATION);
}

int dcomp( const void * arg1, const void * arg2 )
{
	if (*(double*)arg1>*(double*)arg2)	return 1;
	else if (*(double*)arg1==*(double*)arg2) return 0;
	else	return -1;
}

void aux_sort(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(vector)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Compute(p);
	ast.checkVector(pnode, ast.Sig);
	qsort(ast.Sig.buf, ast.Sig.nSamples, sizeof(ast.Sig.buf[0]), dcomp);
}

void aux_file(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(filename)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	char fname[MAX_PATH], ext[MAX_PATH];
	HANDLE hFile = INVALID_HANDLE_VALUE;
	try {
		_splitpath(ast.ComputeString(p).c_str(), NULL, NULL, fname, ext);
		if (string(_strlwr(ext))==".txt")
		{
			if ((hFile = CreateFile(fname, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL,
						OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL ))== INVALID_HANDLE_VALUE)
				throw CAstException(pnode, &ast, "Cannot read file", string(fname));
			DWORD dw, fsize = GetFileSize(hFile, &dw);
			if (fsize==INVALID_FILE_SIZE)
				throw CAstException(pnode, &ast, "Cannot get the size of file", string(fname));
			char *buf = new char[fsize+1];
			if(!ReadFile (hFile, buf, fsize, &dw, NULL))
				throw CAstException(pnode, &ast, "Error reading file", string(fname));
			buf[dw]=0;
			if (hFile != INVALID_HANDLE_VALUE) CloseHandle(hFile);

			string newstr("[");
			newstr += buf;
			newstr += ']';
			delete[] buf;

			CAstSig tempast(ast.pEnv);
			tempast.SetNewScript(newstr.c_str());
			tempast.Compute();

			ast.Sig = tempast.Sig;
		}
#ifndef NO_SF
		else if (string(_strlwr(ext))==".wav")
		{
			aux_wave(ast,pnode,p);
		}
#endif // NO_SF
	} catch (const CAstException &) {
		throw;
	}
}

void aux_HOOK(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{// any "hook command" in the application, which begins with # goes through here
	string HookName;
	const AstNode *args;
	if (pnode->str[0] == '#') {
		HookName = pnode->str+1;
		HookName=HookName.substr(0, HookName.find(' '));
		args = p;
	} else {
		const char *fnsigs[] = {
			"(name_string, ...)", 0};
		HookName = ast.ComputeString(p);
		ast.checkNumArgs(pnode, p, fnsigs, 1, 0);
		args = p->next;
	}

	CSignals first;
	char buf[512];

	if (ast.CallbackHook && ast.CallbackHook(ast, pnode, p)==0)
		;

	else if (HookName == "INPUT") {
		const char *fnsigs[] = {
			"(message_string [, title_string])", 0};
		ast.checkNumArgs(pnode, args, fnsigs, 1, 2);
		string msg, title;
		msg = ast.ComputeString(args);
		if (args->next)
			title = ast.ComputeString(args->next);
		else {
			ostringstream caption;
			caption << "Line " << pnode->line;
			title = caption.str();
		}
		buf[0] = '\0';
		InputBox(title.c_str(), msg.c_str(), buf, sizeof(buf));
		ast.Sig.UpdateBuffer((int)strlen(buf));
		for (int i=0; buf[i]; ++i)
			ast.Sig.buf[i] = buf[i];
	} else if (HookName == "PIPE") {
		const char *fnsigs[] = {
			"(message_string [, node_name_string [, pipe_name_string]])", 0};
		ast.checkNumArgs(pnode, args, fnsigs, 1, 3);
#define SIGNAL_INTERFACE_PIPENAME  "CochlearAudioSignalInterfacePipe"
		string pipemsg = ast.ComputeString(args);
		string nodename = ".";
		string pipename = SIGNAL_INTERFACE_PIPENAME;
		if (args->next) {
			nodename = ast.ComputeString(args->next);
			if (args->next->next)
				pipename = ast.ComputeString(args->next->next);
		}
		pipename = "\\\\" + nodename + "\\pipe\\" + pipename;
		char reply[50000] = "";
		unsigned long nRead;
		if (!CallNamedPipe(pipename.c_str(), (LPVOID)pipemsg.c_str(), (DWORD)pipemsg.size()+1, reply, (DWORD)sizeof(reply), &nRead, NMPWAIT_WAIT_FOREVER)) {
			char *errstr = buf;
			GetLastErrorStr(errstr);
			throw CAstException(pnode, &ast, "CallNamedPipe(" + pipename + ") failed:", errstr);
		}
		reply[nRead]='\0';
		ast.Sig.UpdateBuffer((int)nRead);
		for (int i=0; reply[i]; ++i)
			ast.Sig.buf[i] = reply[i];
	} else if (HookName == "ELAPSE") {
		const char *fnsigs[] = {
			"( )", 0};
		ast.checkNumArgs(pnode, args, fnsigs, 0, 0);
		ast.Sig.SetValue(GetTickCount() - ast.Tick0);
	} 
	else if (HookName == "SLEEP") {
		const char *fnsigs[] = {
			"(millisecond)", 0};
		ast.checkNumArgs(pnode, args, fnsigs, 1, 1);
		ast.Compute(args);
		if (!ast.Sig.IsScalar())
			throw CAstException(pnode, &ast, fnsigs, "argument must be a scalar.");
		int n = round(ast.Sig.value());
		Sleep(n);
	} else
		throw &ast;
}

#endif //_WINDOWS this

void aux_include(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	string dummy;
	const char *fnsigs[] = {
		"(filename)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	string filename = ast.ComputeString(p);
	if (FILE *auxfile = ast.OpenFileInPath(filename, "aux", dummy)) {
		try {
			CAstSig tast(&ast);
			tast.SetNewScriptFromFile(filename.c_str(), auxfile);
			fclose(auxfile);
			vector<CSignals> res = tast.Compute();
			ast.Sig = res.back();
		} catch (const char *errmsg) {
			fclose(auxfile);
			throw CAstException(pnode, &ast, "Including "+filename+"\n\nIn the file: \n"+errmsg);
		}
	} else
		throw CAstException(pnode, &ast, "Cannot read file", filename);
}

void aux_eval(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(string)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	string str = ast.ComputeString(p);
	try {
		CAstSig tast(str.c_str(), &ast);
		vector<CSignals> res = tast.Compute();
		ast.Sig = res.back();
	} catch (const char *errmsg) {
		throw CAstException(pnode, &ast, "Evaluating\n"+str+"\n\nIn the string: \n"+errmsg);
	}
}

void aux_zeros(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(scalar)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Compute(p);
	if (!ast.Sig.IsScalar())
		throw CAstException(pnode, &ast, fnsigs, "argument must be a scalar.");
	int n = round(ast.Sig.value());
	if (n <= 0)
		throw CAstException(pnode, &ast, fnsigs, "argument must be a positive number.");
	ast.Sig.Reset(1).UpdateBuffer(n);
	for (int i=0; i<n; ++i)
		ast.Sig.buf[i] = 0;
}

void aux_ones(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(scalar)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Compute(p);
	if (!ast.Sig.IsScalar())
		throw CAstException(pnode, &ast, fnsigs, "argument must be a scalar.");
	int n = round(ast.Sig.value());
	if (n <= 0)
		throw CAstException(pnode, &ast, fnsigs, "argument must be a positive number.");
	ast.Sig.Reset(1).UpdateBuffer(n);
	for (int i=0; i<n; ++i)
		ast.Sig.buf[i] = 1;
}


#ifndef NO_FFTW

void aux_time_comp_stret(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{ // time compression or time stretch
	const char *fnsigs[] = {
		"(signal, scalar)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 3);
	char errstr[256] = "";
	CSignals third, second = ast.Compute(p->next);
	if (p->next->next) {	// 3 args
		third = ast.Compute(p->next->next);
		if (!third.IsScalar())	throw CAstException(pnode, &ast, fnsigs, "3rd argument must be a scalar.");
	} else {				// 2 args
		if (!second.IsScalar())	throw CAstException(pnode, &ast, fnsigs, "2nd argument must be a scalar.");
	}
	ast.Compute(p);
	if (ast.Sig.nSamples <= 1)
		throw CAstException(pnode, &ast, fnsigs, "1st argument must be a signal.");
	ast.Sig.TCTS(second.value(), third.value() );
}

void aux_shift_spectrum(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{ // $ operator
	const char *fnsigs[] = {
		"(signal, scalar)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 2);
	char errstr[256] = "";
	ast.Compute(p->next);
	if (ast.Sig.IsScalar())
	{
		double param = ast.Sig.value();
		ast.Compute(p);
		if (ast.Sig.nSamples <= 1)
			throw CAstException(pnode, &ast, fnsigs, "1st argument must be a signal.");
		int orgfs = ast.Sig.GetFs();
		ast.Sig.ShiftFreq(param);
	}
	else
		throw CAstException(pnode, &ast, fnsigs, "2nd argument must be a scalar.");
}

void aux_fft(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const string fname = pnode->str;
	const char *fnsigs[] = {
		"(signal, [nSamples=(length of signal)])", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 2);

	CSignals prim = ast.Compute(p);
	ast.blockCell(pnode, prim);
	ast.blockScalar(pnode, prim);
	ast.blockString(pnode, prim);
	int n = prim.nSamples;
	if (p->next) {
		CSignals sec = ast.Compute(p->next);
		if (!sec.IsScalar())
			throw CAstException(pnode, &ast, fnsigs, "2nd argument must be a scalar.");
		n = round(sec.value());
		if (n <= 0)
			throw CAstException(pnode, &ast, fnsigs, "2nd argument must be a positive number.");
	}
	ast.Sig = prim;
	ast.Sig.SetFs(1);
	ast.Sig.UpdateBuffer(n); // is this a good idea to update the length here? 4/3/2017 bjk
	ast.Sig.FFT(n);
};

void aux_isnull(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{ // if the signal is null at specified time_pt
	const char *fnsigs[] = {
		"(signal, timept_ms)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 2);
	ast.Compute(p->next);
	if (ast.Sig.GetType()!=CSIG_SCALAR)
		throw CAstException(pnode, &ast, fnsigs, "argument must be a scalar.");
	double vv = ast.Sig.value();
	ast.Compute(p);
	ast.checkAudioSig(pnode, ast.Sig);
	ast.Sig.SetValue(ast.Sig.IsNull(vv));
	ast.Sig.MakeLogical();
}

void aux_isaudio(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(variable)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Compute(p);
	ast.Sig.SetValue(ast.Sig.GetType()==CSIG_AUDIO ? 1 : 0);
	ast.Sig.MakeLogical();
}

void aux_isempty(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(variable)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Compute(p);
	ast.Sig.SetValue(ast.Sig.IsEmpty());
	ast.Sig.MakeLogical();
}

void aux_or(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	double res(0.);
	const char *fnsigs[] = {
		"(logical variable)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Compute(p);
	if (!ast.Sig.IsLogical())
		throw CAstException(pnode, &ast, fnsigs, "argument must be a logical variable.");
	for (int k=0; k<ast.Sig.nSamples; k++)
		if (ast.Sig.logbuf[k]) res=1., k=ast.Sig.nSamples+1;
	ast.Sig.SetValue(res);
	ast.Sig.MakeLogical();
}

void aux_and(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	double res(1.);
	const char *fnsigs[] = {
		"(logical variable)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Compute(p);
	if (!ast.Sig.IsLogical())
		throw CAstException(pnode, &ast, fnsigs, "argument must be a logical variable.");
	for (int k=0; k<ast.Sig.nSamples; k++)
		if (!ast.Sig.logbuf[k]) res=0., k=ast.Sig.nSamples+1;
	ast.Sig.SetValue(res);
	ast.Sig.MakeLogical();
}

void aux_ifft(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const string fname = pnode->str;
	const char *fnsigs[] = {
		"(vector)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Compute(p);
	ast.checkComplex(pnode, ast.Sig);
	if (ast.Sig.nSamples <= 1)
		throw CAstException(pnode, &ast, fnsigs, "argument must be a vector.");
	ast.Sig.SetFs(ast.GetFs());
	ast.Sig.iFFT();
};

void aux_shift(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(signal)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 2);
	CSignals second = ast.Compute(p->next);
	ast.Compute(p);
	ast.checkAudioSig(pnode,  ast.Sig);
	ast.Sig.ShiftFreq(second.value());
}

void aux_envelope(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(signal)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Compute(p);
	ast.checkAudioSig(pnode,  ast.Sig);
	ast.Sig.HilbertEnv(ast.Sig.nSamples);
}


void aux_hilbert(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(signal)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Compute(p);
	ast.checkAudioSig(pnode,  ast.Sig);
	ast.Sig.Hilbert(ast.Sig.nSamples);
};

#endif //NO_FFTW

void aux_filt(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const string fname = pnode->str;
	const char *fnsigs[] = {
		"(signal, Numerator_array [, Denominator_array=1 for FIR])", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 3);

	CSignals third, second = ast.Compute(p->next);
	if (p->next->next) {	// 3 args
		third = ast.Compute(p->next->next);
		if (!second.IsScalar() && !third.IsScalar() && second.nSamples != third.nSamples)
			throw CAstException(pnode, &ast, fnsigs, "2nd & 3rd argument must be of the same length, unless they're scalars.");
	} else {				// 2 args
		if (second.nSamples <= 1)
			throw CAstException(pnode, &ast, fnsigs, "2nd argument must be a vector(the numerator array for filtering).");
		third.SetValue(1);
	}
	ast.Compute(p);
	ast.checkAudioSig(pnode,  ast.Sig);

	int len = max(second.nSamples, third.nSamples);
	if (second.IsScalar())
		second.UpdateBuffer(len);
	else if (third.IsScalar())
		third.UpdateBuffer(len);
	if (fname == "filt")
		ast.Sig.Filter(len, second.buf, third.buf);
	else if (fname == "filtfilt")
		ast.Sig.filtfilt(len, second.buf, third.buf);
}

void aux_am(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	double modRate, amDepth(1.), initPhase(0.); 
	const char *fnsigs[] = {"(signal, AM_rate [, AM_depth_m, initial_phase_between_0&1])", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 4);
	CSignals fourth, third, second = ast.Compute(p->next);
	if (p->next->next)
	{
		if (p->next->next->next) {	// 4 args
			fourth = ast.Compute(p->next->next->next);
			if (!fourth.IsScalar())
				throw CAstException(pnode, &ast, fnsigs, "Initial_phase must be a scalar.");
		} else {
			fourth.SetValue(0);
			if (p->next->next) {	// 3 args
				third = ast.Compute(p->next->next);
				if (!third.IsScalar())
					throw CAstException(pnode, &ast, fnsigs, "AM_depth must be a scalar (in m).");
			} 
			else
				third.SetValue(1.);
		}
	}
	else
	{
		fourth.SetValue(0);
		third.SetValue(1.);
	}
	if (!second.IsScalar()) throw CAstException(pnode, &ast, fnsigs, "AM_rate must be a scalar.");
	modRate = second.value();
	amDepth = third.value();
	initPhase = fourth.value();
	ast.Compute(p);
	ast.checkAudioSig(pnode,  ast.Sig);
	double fs=(double)ast.Sig.GetFs();
	int nzPoint = 0;
	for (CSignals *p = &ast.Sig; p; p=(CSignals *)p->chain)
	{
		double *env = new double[p->nSamples];
		for (int i=0; i<p->nSamples; i++) 
		{
			int id = round(p->tmark/1000.*fs) + i;
			env[i] = (1.+amDepth*sin(2*PI*(modRate*(double)id/fs+initPhase-.25)))/(1.+amDepth);
		}
		p->Modulate(env,p->nSamples);
		delete[] env;
	}
}

void aux_ramp(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const string fname = pnode->str;
	const char *fnsigs[] = {"(signal, ramp_duration)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 2);
	CSignals second = ast.Compute(p->next);
	if (!second.IsScalar())
		throw CAstException(pnode, &ast, fnsigs, "2nd argument must be a scalar.");
	ast.Compute(p);	
	ast.checkAudioSig(pnode,  ast.Sig);
	ast.Sig.Dramp(second.value());
}

void aux_rms(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(signal)",
		"(signal, TargetRmsValue)",
		"(signal, Ref, Signal2RefRatio_dB)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 3);
	if (!p->next) {		// one argument
		ast.Compute(p);
		ast.checkAudioSig(pnode, ast.Sig);
		//I don't remember why I wrote it like this..... 5/28/2016 bjk
//		int mn = (int)(((body)ast.Sig).Min()+.5);
//		int mx = (int)(((body)ast.Sig).Max()+.5);
//		if (mn==0. && mx==0.)
//			ast.Sig.SetValue(-9999.99);
//		else
			ast.Sig.SetValue(ast.Sig.RMS());
		return;
	}
	CSignals rms2, lastArg;
	if (p->next->next) {// three arguments
		CSignals second = ast.Compute(p->next);
		if (second.IsScalar())
			throw CAstException(pnode, &ast, fnsigs, "2nd argument of 3-argument rms( ) must be a signal.");
		rms2 = second.RMS();
		lastArg = ast.Compute(p->next->next);
	} else {			// two arguments
		rms2.SetValue(-0.000262);	// the calculated rms value of a full scale sinusoid (this is necessary to avoid the clipping of rms adjusted full scale sinusoid)
		lastArg = ast.Compute(p->next);
	}
	ast.Compute(p);	// Sig gets the first operand
	ast.checkAudioSig(pnode,  ast.Sig);
	if (ast.Sig.nSamples <= 1)
		throw CAstException(pnode, &ast, fnsigs, "1st argument must be a signal.");
	CSignals rms = -ast.Sig.RMS();
	if (rms.nSamples == 1) {
		if (rms2.nSamples > 1)
			throw CAstException(pnode, &ast, fnsigs, "2nd signal must be mono when 1st one is mono.");
		if (lastArg.nSamples > 1)
			throw CAstException(pnode, &ast, fnsigs, "Last argument must be scalar when 1st one is mono.");
	}
	//ast.Sig *= exp((lastArg - rms + rms2) * LOG10DIV20);
	rms += rms2;
	rms += lastArg;
	rms *= LOG10DIV20;
	ast.Sig *= rms.each(exp).transpose1();
}

#ifndef NO_IIR

void aux_iir(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	int type, kind(1), norder(4);
	char errstr[256];
	double freqs[2], rippledB(0.5), stopbandFreqORAttenDB(-40.);
	const char *fnsigs[2];
	const AstNode *args;
	CSignals sigX;
	string emsg1(" (signal, freq, [order=4], [kind=1], [dB_passband_ripple=0.5], [dB_stopband_atten=-40])");
	string emsg2(" (signal, freq1, freq2, [order=4], [kind=1], [dB_passband_ripple=0.5], [dB_stopband_atten=-40])");
	string emsg3("  --- kind: 1 for Butterworth, 2 for Chebyshev, 3 for Elliptic");
	emsg1 += emsg3;
	emsg2 += emsg3;
	char emsg[256];
	if  (!strcmp(pnode->str,"lpf")) {	type=1; sprintf(emsg, "%s%s\n", pnode->str, emsg1.c_str()); }
	else if  (!strcmp(pnode->str,"bpf")) { type=2; sprintf(emsg, "%s%s\n", pnode->str, emsg2.c_str()); }
	else if  (!strcmp(pnode->str,"hpf")) { type=3; sprintf(emsg, "%s%s\n", pnode->str, emsg1.c_str()); }
	else if  (!strcmp(pnode->str,"bsf")) { type=4; sprintf(emsg, "%s%s\n", pnode->str, emsg2.c_str()); }
	args = p;
	switch(type)
	{
	case 1:
	case 3:
		fnsigs[0]=emsg1.c_str(); fnsigs[1]=0;
		ast.checkNumArgs(pnode, p, fnsigs, 2, 6);
		p = args->next->next;
		if (p) {
			ast.Compute(p);		norder = round(ast.Sig.value()); 
			p = p->next;
			if (p) {
				ast.Compute(p);	kind = round(ast.Sig.value()); 
				p = p->next;
				if (p) {
					ast.Compute(p);		rippledB = ast.Sig.value(); 
					p = p->next;
					if (p) {ast.Compute(p);		stopbandFreqORAttenDB = ast.Sig.value(); }
				}
			}
		}
		break;
	case 2:
	case 4:
		fnsigs[0]=emsg2.c_str(); fnsigs[1]=0;
		ast.checkNumArgs(pnode, p, fnsigs, 3, 7);
		p = args->next->next;
		if (p) {
			ast.Compute(p);		freqs[1] = ast.Sig.value(); 
			p = p->next;
			if (p) {
				ast.Compute(p);	norder = round(ast.Sig.value()); 
				p = p->next;
				if (p) {
					ast.Compute(p);		kind = round(ast.Sig.value()); 
					p = p->next;
					if (p) {
						ast.Compute(p);		rippledB = ast.Sig.value(); 
						p = p->next;
						if (p)
							{ast.Compute(p);		stopbandFreqORAttenDB = ast.Sig.value(); }
					}
				}
			}
		}
		break;
	}
	ast.Compute(args);
	ast.checkAudioSig(pnode,  ast.Sig);
	sigX = ast.Sig;
	ast.Compute(args->next);
	freqs[0] = ast.Sig.value();

	if (sigX.IIR(kind, type, norder, freqs, rippledB, stopbandFreqORAttenDB, errstr)<0)
	{
		sprintf(emsg, "%sError in %s. %s", emsg, pnode->str, errstr);
		throw emsg;
	}
	ast.Sig = sigX; 
}
#endif // NO_IIR


void aux_csqrt(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	complex<double> (*cfn1)(complex<double>) = ddsqrt;
	double (*fn1)(double) = sqrt;

	const char *fnsigs[] = { "(complex_signal)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Compute(p);
	if (ast.Sig.GetType()==CSIG_AUDIO)
		ast.Sig.each(fn1);
	else
	{
		//Sig should be either negative or complex
		if (!ast.Sig.IsComplex())
			ast.Sig.SetComplex();
		ast.Sig.each(cfn1);
	}
}

void aux_stereo(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(left_signal, right_signal)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 2);
	CSignals right = ast.Compute(p->next);
	ast.checkAudioSig(pnode, right);
	ast.Compute(p);	// ast.Sig gets the left signal
	ast.checkAudioSig(pnode, ast.Sig);
	ast.Sig.SetNextChan(&right);
};

void aux_left_right(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const string fname = pnode->str;
	const char *fnsigs[] = {
		"(stereo_signal)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Compute(p);
//	ast.checkAudioSig(pnode, ast.Sig);
	if (fname == "right" || fname == "imag") {
		CSignal *right = ast.Sig.DetachNextChan();
		if (right == NULL) {
			ast.Sig.Reset();
			return;
		}
		ast.Sig.SwapContents1node(*right);
		delete right;	// deleting left channel since 'right' now points to the left channel
	}
	delete ast.Sig.next;
	ast.Sig.next = NULL;
};

void aux_squeeze(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const string fname = pnode->str;
	const char *fnsigs[] = {"(remove the null interval)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Sig.Squeeze();
}

void aux_audio(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const string fname = pnode->str;
	const char *fnsigs[] = {"(non_audio_vector)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	CSignals first = ast.Compute(p);
	ast.checkVector(pnode, first);
	ast.Sig = first;
	ast.Sig.SetFs(ast.GetFs());
}

void aux_vector(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const string fname = pnode->str;
	const char *fnsigs[] = {"(audio_vector)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Sig = ast.Compute(p);
	ast.Sig.MakeChainless();
	ast.Sig.SetFs(1);
}


void aux_interp(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(vector, vector)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 2);
	CSignals first = ast.Compute(p);
	ast.checkVector(pnode, first, "for 1st arg.");
	CSignals second = ast.Compute(p->next);
	ast.checkVector(pnode, second, "for 2nd arg.");
	ast.Sig.Reset(ast.GetFs()).Interp(first, second);
}

void aux_hann_hamming(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const string fname = pnode->str;
	const char *fnsigs[] = {
		"(length)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Compute(p);
	if (!ast.Sig.IsScalar())
		throw CAstException(pnode, &ast, fnsigs, "argument must be a scalar.");
	int n = round(ast.Sig.value());
	if (n <= 0)
		throw CAstException(pnode, &ast, fnsigs, "argument must be a positive number.");
	if (fname == "hann")
		ast.Sig.Blackman(n, 0);
	else if (fname == "hamming")
		ast.Sig.Hamming(n);
};

void aux_blackman(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(length, [alpha=0.16])", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 2);
	ast.Compute(p);
	if (!ast.Sig.IsScalar())
		throw CAstException(pnode, &ast, fnsigs, "argument must be a scalar.");
	int n = round(ast.Sig.value());
	if (n <= 0)
		throw CAstException(pnode, &ast, fnsigs, "argument must be a positive number.");
	if (!p->next) {
		ast.Sig.Blackman(n);
		return;
	}
	ast.Compute(p->next);
	if (!ast.Sig.IsScalar())
		throw CAstException(pnode, &ast, fnsigs, "2nd argument must be a scalar.");
	ast.Sig.Blackman(n, ast.Sig.value());
};


void aux_fm(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(freq1, freq2, mod_rate, duration, [init_phase=0])", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 4, 5);
	CSignals fifth, second = ast.Compute(p->next);
	CSignals third = ast.Compute(p->next->next);
	CSignals fourth = ast.Compute(p->next->next->next);
	if (!second.IsScalar()) throw CAstException(pnode, &ast, fnsigs, "freq2 must be a scalar.");
	if (!third.IsScalar()) throw CAstException(pnode, &ast, fnsigs, "mod_rate must be a scalar.");
	if (!fourth.IsScalar()) throw CAstException(pnode, &ast, fnsigs, "duration must be a scalar.");
	if (fourth.value()<=0) throw CAstException(pnode, &ast, fnsigs, "duration must be positive.");
	if (p->next->next->next->next) {	// 5 args
		fifth = ast.Compute(p->next->next->next->next);
		if (!fifth.IsScalar()) throw CAstException(pnode, &ast, fnsigs, "init_phase must be a scalar."); }
	else fifth.SetValue(0);

	ast.Compute(p);
	double freq1 = ast.Sig.value();
	double freq2 = second.value();
	double midFreq = (freq1+freq2)/2.;
	double width = fabs(freq1-freq2)/2.;
	double modRate = third.value();
	double initPhase = fifth.value();
	double dur = fourth.value();
	ast.Sig.Reset(ast.GetFs());
	if (modRate!=0.)
		ast.Sig.fm(midFreq, width, modRate, dur, initPhase-.25);
	else
	{
		vector<double> freqs(2);
		freqs[0] = freq1; freqs[1] = freq2; 
		ast.Sig.Tone(freqs, dur);
	}
}


void aux_tone(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {"(frequency, duration_in_ms [, initial_phase_between_0&1])", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 2, 3);
	CSignals third, second = ast.Compute(p->next);
	if (p->next->next) {	// 3 args
		third = ast.Compute(p->next->next);
		if (!third.IsScalar())
			throw CAstException(pnode, &ast, fnsigs, "Initial_phase must be a scalar.");
	} else {				// 2 args
		if (!second.IsScalar()) throw CAstException(pnode, &ast, fnsigs, "Duration must be a scalar.");
		if (second.value()<=0) throw CAstException(pnode, &ast, fnsigs, "Duration must be positive.");
		third.SetValue(0);
	}
	ast.Compute(p);
	int len = ast.Sig.nSamples;
	if (len==1) 
	{
		double freq = ast.Sig.value();
		if (freq>=ast.GetFs()/2) throw CAstException(pnode, &ast, fnsigs, "Frequency exceeds Nyquist frequency.");
		ast.Sig.Reset(ast.GetFs());
		ast.Sig.Tone(freq, second.value(), third.value());
	}
	else // if two elements, frequency glide; else arbitrary frequencies
	{
		vector<double> freqs(len);
		memcpy((void*)&freqs[0], (void*)ast.Sig.GetBuffer(), len*sizeof(double));
		if (freqs[0]>=ast.GetFs()/2 || freqs[1]>=ast.GetFs()/2) throw CAstException(pnode, &ast, fnsigs, "Frequency exceeds Nyquist frequency.");
		ast.Sig.Reset(ast.GetFs());
		ast.Sig.Tone(freqs, second.value());
	}
}

void aux_tparamonly(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	static bool initialized(false);
	if (!initialized)
	{
		srand((unsigned) time(0));
		initialized = true;
	}

	const char *fnsigs[] = {
		"(duration_in_ms)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	ast.Compute(p);
	if (!ast.Sig.IsScalar())	throw CAstException(pnode, &ast, fnsigs, "argument must be a scalar.");
	double durms = ast.Sig.value();
	if (durms < 0)	throw CAstException(pnode, &ast, fnsigs, "argument must be a non-negative number.");
	ast.Sig.SetFs(ast.GetFs());
	if (!strcmp(pnode->str,"noise"))
		ast.Sig.Noise(durms);
	else if (!strcmp(pnode->str,"gnoise"))
		ast.Sig.Noise2(durms);
	else if (!strcmp(pnode->str,"silence"))
		ast.Sig.Silence(durms);
	else if (!strcmp(pnode->str,"dc"))
		ast.Sig.DC(durms);
}

void HandleExp1(CAstSig &ast, const AstNode *pnode, CSignals &Sig)
{
	int nChains;
	string fname = pnode->str;
	AstNode *p=pnode->child;
	if (p && p->type == NODE_ARGS)
		p = p->child;

	const char *fnsigs[] = {"(signal)", 0};
	ast.checkNumArgs(pnode, p, fnsigs, 1, 1);
	if (fname == "length" && Sig.IsString()) {Sig.SetValue(Sig.length()); return;}
	CSignals SecondCh;
	if (Sig.next)
	{
		SecondCh = *(CSignal*)Sig.next; // this way, SecondCh.next is NULL
		HandleExp1(ast, pnode, SecondCh);
	}
	if (fname == "begint" || fname == "endt" || fname == "dur") 	ast.checkAudioSig(pnode, Sig); 
	int res; 
	if (fname == "begint" || fname == "endt" || fname == "dur" || fname == "max" || fname == "min" || fname == "length" || fname == "mean" || fname == "sum" || fname == "maxid" || fname == "minid")
	{
		CSignal dummy, *extracted, out(1);
		nChains = Sig.CountChains();
		out.UpdateBuffer(nChains); // need a separate output variable because, otherwise, Sig gets changed with this UpdateBuffer call.
		int m(0);
		bool loop(true);
		while( (extracted = Sig.ExtractDeepestChain(&dummy))!=&Sig || loop )
		{
			if (fname == "begint") out.buf[m++] = extracted->tmark;
			else if (fname == "endt") out.buf[m++] = extracted->tmark + extracted->dur();
			else if (fname == "dur") out.buf[m++] = extracted->dur();
			else if (fname == "max") out.buf[m++] = (double)((body*)extracted)->Max();
			else if (fname == "min") out.buf[m++] = (double)((body*)extracted)->Min();
			else if (fname == "mean") out.buf[m++] = (double)((body*)extracted)->Mean();
			else if (fname == "sum") out.buf[m++] = (double)((body*)extracted)->Sum();
			else if (fname == "maxid") {((body*)extracted)->Max(res);  out.buf[m++] = (double)res;}
			else if (fname == "minid") {((body*)extracted)->Min(res);  out.buf[m++] = (double)res;}
			else if (fname == "length") {
				if (Sig.cell.size()>0) out.buf[m++] = (double)Sig.cell.size();
				else			out.buf[m++] = (double)extracted->nSamples;
			}
			if (extracted == &Sig) loop = false;
		}
		out.ReverseTime();
		Sig = out; // put it back.
		if (!SecondCh.IsEmpty())
			Sig.SetNextChan(&SecondCh);
	}
	else
		throw ("Unhandled AUX function: " + fname).c_str();
}

AstNode *searchstr(AstNode *p, const char* pstr)
{ // if there's a node with "type" in the tree, return that node
	if (p)
	{
		if (p->str==pstr) return p;
		if (p->child)
			if (p->child->str==pstr) return p->child;
			else return searchstr(p->child, pstr);
		else if (p->next)
			if (p->next->str==pstr) return p->next;
			else return searchstr(p->next, pstr);
	}
	return NULL;
}

int findcol(AstNode *past, const char* pstr, int line)
{
	for (AstNode *pn=past; pn; pn = pn->next)
	{
		if (pn->line<line) continue;
		AstNode *pm = searchstr(pn->child, pstr);
		if (pm) return pm->col;
		else	return -1;
	}
	return -1;
}

void CAstSig::HandleAuxFunctions(const AstNode *pnode)
{
	string fname = pnode->str;
	AstNode *p=pnode->child;
	if (p && p->type == NODE_ARGS)
		p = p->child;

	double (*fn1)(double) = NULL;
	double (*fn2)(double, double) = NULL;
	double (*cfn0)(complex<double>) = NULL;
	complex<double> (*cfn1)(complex<double>) = NULL;
	complex<double> (*cfn2)(complex<double>, complex<double>) = NULL;

	//The following functions produces audio output(s).
	if (fname == "tone")			aux_tone(*this, pnode, p);
	else if (fname == "fm")			aux_fm(*this, pnode, p);
	else if (fname == "noise" ||
			 fname == "gnoise" ||
			 fname == "silence" ||
			 fname == "dc" )		aux_tparamonly(*this, pnode, p);
#ifndef NO_SF
	else if (fname == "wave")		aux_wave(*this, pnode, p);
	else if (fname == "wavwrite")	aux_wavwrite(*this, pnode, p);
#endif // NO_IIR
	else if (fname == "audio")		aux_audio(*this, pnode, p); 
	else if (fname == "squeeze")	aux_squeeze(*this, pnode, p); 
	else if (fname == "interp")		aux_interp(*this, pnode, p); // Special kind... not an audio signal in a strict sense
	else if (fname == "hann" ||
			 fname == "hamming")	aux_hann_hamming(*this, pnode, p);
	else if (fname == "blackman")	aux_blackman(*this, pnode, p);

	//The following functions take only audio argument(s)---anything that involves time, fs or rms
	else if (fname == "ramp")		aux_ramp(*this, pnode, p);
	else if (fname == "am")			aux_am(*this, pnode, p);
#ifndef NO_IIR
	else if (fname == "rms")		aux_rms(*this, pnode, p);
	else if (fname == "lpf" ||
			 fname == "hpf" ||
			 fname == "bpf" ||
			 fname == "bsf" )		aux_iir(*this, pnode, p);
#endif // NO_IIR
	else if (fname == "stereo")		aux_stereo(*this, pnode, p);
	else if (fname == "left" ||
			 fname == "right" )		aux_left_right(*this, pnode, p);
	else if (fname == "vector")		aux_vector(*this, pnode, p); 
	else if (fname == "abs")	{ if (Compute(p).IsComplex()) cfn0 = cmpabs; 	else	fn1 = fabs;}
	else if (fname == "conj")	{ if (Compute(p).IsComplex()) cfn1 = cmpconj; 	else	fn1 = fabs;}
	else if (fname == "real")	{ if (Compute(p).IsComplex()) cfn0 = cmpreal; 	else	{ Sig.SetReal(); return;} 	}
	else if (fname == "imag")	{ if (Compute(p).IsComplex()) cfn0 = cmpimag; 	else	{ Sig.SetReal(); Sig.SetValue(0); return;} 	}
	else if (fname == "angle")	{ 
		Compute(p); 
		Sig.SetComplex(); 
		Sig.each(cmpangle);	
		Sig.SetReal();}
	//	else if (fname == "")	{ if (Compute(p).IsComplex()) cfn0 = cmp; 	else	fn1 = ;}
	else if (fname == "db")		fn1 = aux_db;
	else if (fname == "sgn")	fn1 = aux_sgn;
	else if (fname == "sin")	if (Compute(p).IsComplex())	cfn1=cmpsin; else fn1=sin;
	else if (fname == "cos")	if (Compute(p).IsComplex())	cfn1=cmpcos; else fn1=cos;
	else if (fname == "tan")	if (Compute(p).IsComplex())	cfn1=cmptan; else fn1=tan;
	else if (fname == "asin")	fn1=asin;
	else if (fname == "acos")	fn1=acos;
	else if (fname == "atan")	fn1=atan;
	else if (fname == "log")	if (Compute(p).IsComplex())	cfn1=cmplog; else fn1=log;
	else if (fname == "log10")	if (Compute(p).IsComplex())	cfn1=cmplog10; else fn1=log10;
	else if (fname == "exp")	if (Compute(p).IsComplex())	cfn1=cmpexp; else fn1=exp;
	else if (fname == "sqrt")	{ 
		CSignals sg = Compute(p); 
		if (sg.IsComplex() || ((body)sg).Min()<0) 
			aux_csqrt(*this, pnode, p); 
		else 
			fn1 = sqrt;}
	else if (fname == "round")	fn1 = aux_round;
	else if (fname == "fix")	fn1 = aux_fix;
	else if (fname == "ceil")	fn1 = ceil;
	else if (fname == "floor")	fn1 = floor;
	else if (fname == "^")		fn2 = aux_exp;
	else if (fname == "mod")	fn2 = aux_mod;
	else if (fname == "min")	aux_minmax (*this, pnode, p);
	else if (fname == "max")	aux_minmax (*this, pnode, p);
	else if (fname == "std")	aux_std (*this, pnode, p);

	else if (fname == "length" || 
			 fname == "dur" ||  fname == "begint" || fname == "endt" || // Only an audio arg
			 fname == "sum" ||
			 fname == "mean" ||
			 fname == "maxid" ||
			 fname == "minid" )
			 HandleExp1(*this, pnode, p?Compute(p):Sig);

	else if (fname == "diff")		aux_diff(*this, pnode, p);
	else if (fname == "cumsum")		aux_cumsum(*this, pnode, p);
	else if (fname == "getfs")		aux_getfs(*this, pnode, p);
	else if (fname == "rand")		aux_rand(*this, pnode, p);
	else if (fname == "irand")		aux_irand(*this, pnode, p);
	else if (fname == "randperm")	aux_randperm(*this, pnode, p);
	else if (fname == ":")			aux_colon(*this, pnode, p);
	else if (fname == "pch")		aux_pitchange(*this, pnode, p);
#ifndef NO_RESAMPLE
	else if (fname == "fmm")		aux_fmm(*this, pnode, p);
	else if (fname == "caret")		aux_caret(*this, pnode, p);
#endif //NO_RESAMPLE
	else if (fname == "sscanf")		aux_sscanf(*this, pnode, p);
	else if (fname == "sprintf")	aux_sprintf(*this, pnode, p);
	else if (fname == "fprintf")	aux_fprintf(*this, pnode, p);
	else if (fname == "fopen")		aux_fopen(*this, pnode, p);
	else if (fname == "fclose")		aux_fclose(*this, pnode, p);
	else if (fname == "fdelete")	aux_fdelete(*this, pnode, p);
	else if (fname == "error")		aux_error(*this, pnode, p);
	else if (fname == "file")		aux_file(*this, pnode, p);
	else if (fname == "include")	aux_include(*this, pnode, p);
	else if (fname == "eval")		aux_eval(*this, pnode, p);
	else if (fname == "zeros")		aux_zeros(*this, pnode, p);
	else if (fname == "ones")		aux_ones(*this, pnode, p);
#ifndef NO_FFTW
	else if (fname == "fft")		aux_fft(*this, pnode, p);
	else if (fname == "ifft")		aux_ifft(*this, pnode, p);
	else if (fname == "isnull")		aux_isnull(*this, pnode, p);
	else if (fname == "isempty")	aux_isempty(*this, pnode, p);
	else if (fname == "isaudio")	aux_isaudio(*this, pnode, p);
	else if (fname == "and")		aux_and(*this, pnode, p);
	else if (fname == "or")			aux_or(*this, pnode, p);
	else if (fname == "envelope")	aux_envelope(*this, pnode, p);
	else if (fname == "hilbert")	aux_hilbert(*this, pnode, p);
	else if (fname == "shift")		aux_shift(*this, pnode, p);
	else if (fname == "shift_spectrum")	aux_shift_spectrum(*this, pnode, p);
	else if (fname == "tcts")	aux_time_comp_stret(*this, pnode, p);
	else if (fname == "filt" ||
			 fname == "filtfilt")	aux_filt(*this, pnode, p);
#endif //NO_FFTW
	//The following functions take only vector argument(s)--prohibiting the use of audio signal applied to this 
	else if (fname == "sort")		aux_sort(*this, pnode, p);

	// extra functions for graffy
#ifndef AUX_NO_EXTRA
	else if (fname == "plot")		aux_plot(*this, pnode, p);
	else if (fname == "pause")		aux_pause(*this, pnode, p);
	else if (fname == "text")		aux_text(*this, pnode, p);
	else if (fname == "close")		aux_close(*this, pnode, p);
	else if (fname == "delete")		aux_delete(*this, pnode, p);
	else if (fname == "get")		aux_get(*this, pnode, p);
	else if (fname == "set")		aux_set(*this, pnode, p);
#endif

#ifdef _WINDOWS
#ifndef NO_PLAYSND
	else if (fname == "play")		aux_play(*this, pnode, p);
	else if (fname == "stop")	aux_playstop(*this, pnode, p);
	else if (fname == "playloop")	aux_playloop(*this, pnode, p);
#endif // NO_PLAYSND
	else if (fname == "cont")		aux_cont(*this, pnode, p);
	else if (fname == "show")		aux_show(*this, pnode, p);
	else if (fname == "HOOK" ||
			 fname[0] == '#')		aux_HOOK(*this, pnode, p);
#endif
	else {
		char msg[] = "Unknown function or variable";
		unordered_map<int,string> layers;
		vector<int> lines;
		vector<int> cols;
		vector<string> strs;
		cols.push_back(pnode->col);
		lines.push_back(pnode->line);
		CAstSig *p = dad;
		while (p)
		{
			char *pstr = p->pCall->str;
			if (pstr) strs.push_back(pstr);
			if (p->pLast)
			{
				lines.push_back(p->pLast->line);
				cols.push_back(findcol(p->pAst, pstr, p->pLast->line));
			}
			p=p->dad;
		}
		throw CAstException(pnode, this, msg, fname);
		}

	if (cfn1) {
		const char *fnsigs[] = {"(scalar or vector)", 0};
		checkNumArgs(pnode, p, fnsigs, 1, 1);
		Compute(p);
		if (!Sig.IsComplex())	Sig.SetComplex();	
		Sig.each(cfn1);	
	} 
	else if (fn1) 
	{
		const char *fnsigs[] = {"(scalar or vector)", 0};
		checkNumArgs(pnode, p, fnsigs, 1, 1);
		Compute(p);
		Sig.each(fn1);	
	} 	
	else if (cfn0) 
	{
		const char *fnsigs[] = {"(scalar or vector)", 0};
		checkNumArgs(pnode, p, fnsigs, 1, 1);
		Compute(p);
		Sig.each(cfn0);	
//		Sig.SetReal(); // SetReal should not be called here. Instead, it is taken care of by directly handling buf inside body::each(double (*fn)(complex<double>)) 
	} 
	else if (fn2)
	{
		const char *fnsigs[] = {"(scalar or vector, scalar or vector_of_equal_length)", 0};
		checkNumArgs(pnode, p, fnsigs, 2, 2);
		CSignals arg = Compute(p->next); // do not change the order of these two lines
		Compute(p); //  to update Sig
		if (fn2 == aux_exp && (Sig.IsComplex() || arg.IsComplex() || ((body)Sig).Min()<0))  
		{	Sig.SetComplex(); arg.SetComplex(); cfn2 = aux_cexp; Sig.each(cfn2,arg); }
		else
			Sig.each(fn2,arg);
	}
}
