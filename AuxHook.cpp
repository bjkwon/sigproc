#include <sstream>
#include <algorithm>
#include "sigproc.h"
#include "psycon.tab.h"
#include "audfret.h"

void aux_sprintf(CAstSig &ast, const AstNode *pnode, const AstNode *p);
	

void aux_show(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(format_string, ...)", 0};
	checkNumArgs(pnode, p, fnsigs, 1, 0);

	ostringstream caption;
	caption << "Line " << pnode->line;
	aux_sprintf(ast, pnode, p);
	MessageBox(NULL, ast.Sig.string().c_str(), caption.str().c_str(), MB_ICONINFORMATION);
};


void aux_file(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	const char *fnsigs[] = {
		"(filename)", 0};
	checkNumArgs(pnode, p, fnsigs, 1, 1);

	HANDLE hFile = INVALID_HANDLE_VALUE;
	char *buf = NULL;
	try {
		string filename = ast.MakeFilename(ast.ComputeString(p), "txt");
		if ((hFile = CreateFile(filename.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL,
					OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL ))== INVALID_HANDLE_VALUE)
			throw CAstException(pnode, "Cannot read file", filename);
		DWORD dw, fsize = GetFileSize(hFile, &dw);
		if (fsize==INVALID_FILE_SIZE)
			throw CAstException(pnode, "Cannot get the size of file", filename);
		buf = new char[fsize+1];
		if(!ReadFile (hFile, buf, fsize, &dw, NULL))
			throw CAstException(pnode, "Error reading file", filename);
		buf[dw]='\0';
		char errStr[256];
		if (ast.Sig.Str2Sig(buf, errStr)==NULL)
			throw CAstException(pnode, "Str2Sig Error.", errStr);
	} catch (const CAstException &) {
		if (buf) delete[] buf;
		if (hFile != INVALID_HANDLE_VALUE) CloseHandle(hFile);
		throw;
	}
	if (buf) delete[] buf;
	if (hFile != INVALID_HANDLE_VALUE) CloseHandle(hFile);
}

void aux_HOOK(CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	string HookName;
	const AstNode *args;
	if (pnode->str[0] == '#') {
		HookName = pnode->str+1;
		args = p;
	} else {
		const char *fnsigs[] = {
			"(name_string, ...)", 0};
		HookName = ast.ComputeString(p);
		checkNumArgs(pnode, p, fnsigs, 1, 0);
		args = p->next;
	}

	CSignals first;
	char buf[512];

	if (ast.CallbackHook && ast.CallbackHook(ast, pnode, p)==0)
		;

	else if (HookName == "PLAY") {
		const char *fnsigs[] = {
			"(signal [, async_flag])",
			"(\"stop\", handle_scalar)", 0};
		checkNumArgs(pnode, args, fnsigs, 1, 2);
		first = ast.Compute(args);
		unsigned long second = 0;
		if (args->next) {
			ast.Compute(args->next);
			if (!ast.Sig.IsScalar())
				throw CAstException(pnode, args->next, fnsigs, "argument must be a scalar.");
			second = (unsigned long)(ast.Sig.value()+(ast.Sig.value()<0?-.5:.5));
		}
		int flag = 0;	
		if (first.IsString()) {
			string cmd = first.string();
			std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
			void *pvoid = (void *)second;
			if (cmd == "stop")
				TerminatePlay(pvoid);
			else if (cmd == "pause")
				PauseResumePlay(pvoid, 0);
			else if (cmd == "resume")
				PauseResumePlay(pvoid, 1);
			else
				throw CAstException(args, "Unknown command in the string -", cmd);
			return;
		}
		char *errstr = buf;
		// second == 0:Synchronous, 1:Asynchronous, 2:Loop
		void *res = first.PlayArray(0, (second==0)?0:WM_USER+293, NULL, (second==2)?-1:0, errstr);
		if (!res)
			throw CAstException(pnode, "PlayArray() failed:", errstr);
		ast.Sig.SetValue((double)(unsigned long)res);
	}
	else if (HookName == "INPUT") {
		const char *fnsigs[] = {
			"(message_string [, title_string])", 0};
		checkNumArgs(pnode, args, fnsigs, 1, 2);
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
		checkNumArgs(pnode, args, fnsigs, 1, 3);
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
			throw CAstException(pnode, "CallNamedPipe(" + pipename + ") failed:", errstr);
		}
		reply[nRead]='\0';
		ast.Sig.UpdateBuffer((int)nRead);
		for (int i=0; reply[i]; ++i)
			ast.Sig.buf[i] = reply[i];
	} else if (HookName == "ELAPSE") {
		const char *fnsigs[] = {
			"( )", 0};
		checkNumArgs(pnode, args, fnsigs, 0, 0);
		ast.Sig.SetValue(GetTickCount() - ast.Tick0);
	} 
	else if (HookName == "SLEEP") {
		const char *fnsigs[] = {
			"(millisecond)", 0};
		checkNumArgs(pnode, args, fnsigs, 1, 1);
		ast.Compute(args);
		if (!ast.Sig.IsScalar())
			throw CAstException(pnode, args, fnsigs, "argument must be a scalar.");
		int n = round(ast.Sig.value());
		Sleep(n);
	} else
		throw CAstException(pnode, "Undefined HOOK name:", HookName);
}

void aux_winproc(const char* name, CAstSig &ast, const AstNode *pnode, const AstNode *p)
{
	if (!strcmp(name,"file"))		aux_file(ast, pnode, p);
	else if (!strcmp(name,"show"))		aux_show(ast, pnode, p);
	else if (!strcmp(name,"HOOK"))		aux_HOOK(ast, pnode, p);
	else if (name[0]=='#')				aux_HOOK(ast, pnode, p);
}