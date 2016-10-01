#include "mex.h"
#pragma once
#include "sigproc.h"


#define MAX_CHANNELS	10

CAstSig *pAst = NULL;
int _fs(0);

void destroyAst(void)
{
	if (pAst!=NULL) delete pAst;
	pAst = NULL;
}

void HandleErrorFSField(const mxArray *pm)
{
	if(mxIsNumeric(pm)) 
		mexErrMsgTxt("'fs' must be a positive number.");
	else
		mexErrMsgTxt("'fs' field must be numeric.");
}


string getString(const mxArray *pm)
{
	if(pm == NULL)
		return "\n";

	string outstr;
	if(mxIsChar(pm)) {
		char *p;
		if (p=mxArrayToString(pm)) {
			outstr = p;
			outstr += "\n";
		} else
			mexErrMsgTxt("mxGetString failed!");
		mxFree(p);
	} else if (mxIsCell(pm)) {
		mwSize nCells = mxGetNumberOfElements(pm);
		for (mwIndex i=0; i<nCells; ++i)
			outstr += getString(mxGetCell(pm, i));
	} else
		mexErrMsgTxt("Argument must be a string or a cell array of strings.");
	return outstr;
}

void addpath(const mxArray *pm)
{
	string outstr;
	if(mxIsChar(pm)) 
		pAst->AddPath(mxArrayToString(pm));
	else if (mxIsCell(pm))
	{
		mwSize nCells = mxGetNumberOfElements(pm);
		outstr += getString(mxGetCell(pm, 0));
		for (mwIndex i=1; i<nCells; ++i)
			outstr += ';' + getString(mxGetCell(pm, i));
		pAst->AddPath(outstr.c_str());
	}
	else
		mexErrMsgTxt("A path must be a string.");
}

void setfs(const mxArray *pm)
{
	if (mxIsNumeric(pm) && *(mxGetPr(pm))>0)
	{
		_fs = round(*(mxGetPr(pm)));
		pAst->Reset(_fs);
	}
	else
		HandleErrorFSField(pm);
}

int auxeval(const char *strIn, double **buffers, int &nChan /* in & out */ )
{
	try {
		pAst->SetNewScript(strIn).Compute().MakeChainless();
	} catch (const char *errmsg) {
		mexErrMsgTxt(errmsg);
	}
	buffers[0] = pAst->Sig.buf;

	// for multi-channel output
	int i;
	CSignals *pSig;
	for (i=1, pSig = pAst->Sig.GetNextChan(); pSig; ++i, pSig=pSig->GetNextChan())
		buffers[i] = pSig->buf;
	nChan = i;

	return pAst->Sig.GetLength();
}

void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{
	double *outbufs[MAX_CHANNELS];
	mxArray *pm;
	char *strname;
	string holder, tpstr;
	int nChan(0), i, outlen(0);
	size_t  nFields, m, n;
	static int resetcount(0), last_new_fs;

	if(nrhs > 2)	// Input arguments.
		mexErrMsgTxt("2 or less input arguments required.");
	if(nrhs == 0 )	
	{
		mexWarnMsgIdAndTxt("AUX:helpzero","AUX interpret in MATLAB\nUsage:\n\tauxx(AUX_string)\n\tauxx(number_for_fs)  -- This will reset\n\tauxx(cell_string_for_path) -- This will update AUXPath\n\tauxx(matlab_variable,string_aux_variable)\n(Examples):\n\tauxx(\"varinaux=tone(440,500)@-20\")\n\tauxx varinaux=tone(440,500)@-20\n\tauxx(8000)\n\tauxx({'c:\\AUXPATH1','c:\\AUXPATH2'})\n\tauxx({'c:\\AUXPATH1;c:\\AUXPATH2'})\n\tauxx(x,\"a\") --- x is a variable in MATLAB, a is a variable in AUX environment.\n");
		return;
	}

	mexAtExit(destroyAst);

	int irhs(0);

	if (mxIsStruct (prhs[0]))
	{
		nFields = mxGetNumberOfFields (prhs[0]);
		if ( (nFields==0) || (nFields>2) ) mexErrMsgTxt("For struct array input, 2 or less fields are set: fs or auxpath (or just ""path"")");
		for (i=0; i<nFields; i++)
		{
			holder = mxGetFieldNameByNumber(prhs[0], i);
			if (holder != "fs" && holder != "auxpath" && holder != "path")
				mexErrMsgTxt("For struct array input, only the following fields are allowed to set: fs auxpath (or just ""path"")");
		}
		pm = mxGetField (prhs[0], 0, "fs");
		if (pm!=NULL)	
		{	
			if (pAst==NULL) pAst = new CAstSig;
			setfs(pm);  		
			//mxDestroyArray(pm); 		pm=NULL;  // This line will make MATLAB behave abnormal (after the MEX call, MATLAB will not respond to any command, even failing to close MATLAB). 3/7/2016
		}
		pm = mxGetField (prhs[0], 0, "auxpath");
		if (pm==NULL) pm = mxGetField (prhs[0], 0, "path");
		if (pm!=NULL)	
		{	
			if (pAst==NULL) pAst = new CAstSig;
			addpath(pm); // Update AuxPath of global pAst
		}
		pAst->Sig.Reset();
	}
	else
	{
		if (nrhs == 2) // The first one should be a variable and second one is string variable
		{
			mxClassID cid = mxGetClassID(prhs[0]);
			mxClassID cid2 = mxGetClassID(prhs[1]);
			if (cid==mxUNKNOWN_CLASS || cid==mxCELL_CLASS || cid==mxSTRUCT_CLASS || cid==mxLOGICAL_CLASS || cid==mxFUNCTION_CLASS)
				mexErrMsgTxt("When 2 arguments are used, the first one must be either real number array or string.");
			else if (cid2 != mxCHAR_CLASS)
				mexErrMsgTxt("When 2 arguments are used, the second one must be string.");
			strname = new char[1+max(mxGetM(prhs[1]), mxGetN(prhs[1]))];
			mxGetString(prhs[1], strname, 1+max(mxGetM(prhs[1]), mxGetN(prhs[1])));

			m = mxGetM(prhs[0]);
			n = mxGetN(prhs[0]);
			// check the length

			if (pAst==NULL) pAst = new CAstSig();
			CSignals xx(_fs=pAst->pEnv->Fs);
			xx.SetBufferFromDoubleArray(mxGetPr(prhs[0]), max(m,n));
			pAst->SetTag(strname, xx);
			delete[] strname;
		}
		else if (nrhs == 1) 
		{
			if(mxIsNumeric(prhs[0])) // set FS and reset the environment
			{
				int new_fs = round(*(mxGetPr(prhs[0])));
				if (pAst==NULL)
				{
					if (new_fs>0)
					{
						last_new_fs = new_fs;
						resetcount++;
					}
				}

				if (new_fs!=_fs)
				{
					if (resetcount++==0)	
					{
						last_new_fs = new_fs;
						mexWarnMsgIdAndTxt ("AUX:Reset_with_new_fs","Repeat the same line to reset AUX environment with a new fs.");
						return;
					}
					else
					{
						resetcount=0;
						if (new_fs==last_new_fs)
						{
							if (pAst==NULL) pAst = new CAstSig;
							setfs(prhs[0]); 
							pAst->Sig.Reset();
						}
						else
						{
							resetcount++;
							last_new_fs = new_fs;
							mexWarnMsgIdAndTxt ("AUX:Reset_with_new_fs","Repeat the same line to reset AUX environment with a new fs.");
							return;
						}
					}
				}
			}
			else if (mxIsCell(prhs[0])) // add path and update the environment
			{
				if (pAst==NULL) pAst = new CAstSig;
				addpath(prhs[0]); // Update AuxPath of global pAst
				pAst->Sig.Reset();

			}
			else // process string argument
			{
				// concatenate argument strings to make a multi-line string.
				string auxstr;
				for (; irhs<nrhs; ++irhs)
					auxstr += getString(prhs[irhs]);
				// Call the actual function.
				if (pAst==NULL) { pAst = new CAstSig();	_fs=pAst->pEnv->Fs;}
				outlen = auxeval(auxstr.c_str(), outbufs, nChan);
			}
		}
	}

	double *pdbl;
	mxArray *envInfo, *mxAns, **var;
	mwSize dim[]={1,1,};
	char *strBuffer=NULL;
	const char **fieldNames, *envName[5];
	int j, k(2);
	
	nFields = pAst->pEnv->Tags.size() + 2 ; // number of variables plus ans and EnvInfo
	
	envName[0] = "fs";
	envName[1] = "auxpath";
	envName[2] = "nVars";

	envInfo = mxCreateStructArray (1, dim, 3, envName);
	mxSetField (envInfo, 0, "nVars", mxCreateDoubleScalar((double)nFields-2));
	mxSetField (envInfo, 0, "fs", mxCreateDoubleScalar(pAst->pEnv->Fs));
	mxSetField (envInfo, 0, "auxpath", mxCreateString(pAst->pEnv->AuxPath.c_str()));

	fieldNames = new const char*[nFields];
	fieldNames[0] = "EnvInfo";
	fieldNames[1] = "ans";

	for ( map<string,CSignals>::iterator tag = pAst->pEnv->Tags.begin(); tag != pAst->pEnv->Tags.end(); tag++)
		fieldNames[k++] = tag->first.c_str();
	k=0;

	plhs[0] = mxCreateStructArray (1, dim, nFields, fieldNames);

	mxSetField (plhs[0], 0, "EnvInfo", envInfo);
	if (pAst->Sig.GetFs()==2) // this means output is a string.. check with JH Park.
	{
		outlen = pAst->Sig.GetLength();
		strBuffer = new char[outlen+1];
		for (j=0; j<outlen; j++) strBuffer[j] = (char)pAst->Sig.buf[j];
		strBuffer[outlen] = '\0';
		mxAns = mxCreateString(strBuffer);
		delete[] strBuffer;
	}
	else
	{
		pAst->Sig.MakeChainless();
		mxAns = mxCreateDoubleMatrix(pAst->Sig.GetLength(), nChan, mxREAL);
		if (pAst->Sig.GetLength()>0)
		{
		pdbl = mxGetPr(mxAns);
		for (CSignals *p=&(pAst->Sig); p; pdbl+=p->GetLength(),p=p->GetNextChan())
			memcpy(pdbl, p->buf, p->GetLength()*sizeof(double));
		}
	}
	mxSetField (plhs[0], 0, "ans", mxAns);

	var = new mxArray* [pAst->pEnv->Tags.size()];

	for ( map<string,CSignals>::iterator tag = pAst->pEnv->Tags.begin(); tag != pAst->pEnv->Tags.end(); tag++)
	{
		outlen = tag->second.GetLength();
		if (tag->second.GetFs()==2) // this means output is a string.. check with JH Park.
		{
			strBuffer = new char[outlen+1];
			for (j=0; j<outlen; j++) strBuffer[j] = (char)tag->second.buf[j];
			strBuffer[outlen] = '\0';
			var[k] = mxCreateString(strBuffer);
			delete[] strBuffer;
		}
		else
		{
			nChan = tag->second.GetNumChan()+1; // Check with JH Park.
			tag->second.MakeChainless();
			var[k] = mxCreateDoubleMatrix(tag->second.GetLength(), nChan, mxREAL);
			pdbl = mxGetPr(var[k]);
			for (CSignals *p=&(tag->second); p; pdbl+=p->GetLength(),p=p->GetNextChan())
				memcpy(pdbl, p->buf, p->GetLength()*sizeof(double));
		}
		mxSetField (plhs[0], 0, fieldNames[k+2], var[k]);
		k++;
	}
	delete[] fieldNames;
	delete[] var;
}

