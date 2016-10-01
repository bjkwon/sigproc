#include "mex.h"
#pragma once
#include "sigproc.h"


#define MAX_CHANNELS	10

CAstSig *pAst = NULL;
int _fs(0);

void destroyAst(void)
{
	if (pAst) {
		delete pAst;
		pAst = NULL;
	}
}

void addpath(mxArray *pm)
{
	if(mxIsChar(pm)) 
		pAst->AddPath(mxArrayToString(pm));
	else
		mexErrMsgTxt("A path field must be a string.");
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

void HandleErrorFSField(mxArray *pm)
{
	if(mxIsNumeric(pm)) 
		mexErrMsgTxt("'fs' must be a positive number.");
	else
		mexErrMsgTxt("'fs' field must be numeric.");
}

void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{
	double *outbufs[MAX_CHANNELS];
	const char *fieldName;
	mxArray *pm;
	char *strname;
	string holder;
	int nChan(0), i, m, n, outlen(0);

	if(nrhs > 2)	// Input arguments.
		mexErrMsgTxt("2 or less input arguments required.");
	if(nrhs == 0 )	
		mexErrMsgTxt("auxmex(AUX_string)\nTo set up AUX environment (to reset),\nauxmex(number_for_fs) --> this will reset\n or auxmex(cell_string_for_path)\n");

	mexAtExit(destroyAst);

	int irhs(0);

	if (mxIsStruct (prhs[0]))
	{
		CAstSig *temp_pAst=NULL;
		int nFields = mxGetNumberOfFields (prhs[0]);
		for (i=0; i<nFields; i++)
		{
			holder = fieldName = mxGetFieldNameByNumber(prhs[0], i);
			pm = mxGetField (prhs[0], 0, holder.c_str());
			_fs = 0; // Reset
			if (holder == "fs")
			{
				if (mxIsNumeric(pm) && *(mxGetPr(pm))>0)
				{
					_fs = round(*(mxGetPr(pm)));
					if (temp_pAst==NULL) temp_pAst = new CAstSig(_fs);
					else temp_pAst->pEnv->Fs = _fs;
				}
				else
					HandleErrorFSField(pm);
			}
			else if (holder == "auxpath" || holder == "path")
				addpath(pm);
			else
				mexErrMsgTxt("For struct array input, only the following fields are allowed to set: fs auxpath (or just ""path"")");
		}
		if (pAst!=NULL) delete pAst;
		pAst = temp_pAst;
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
			// concatenate argument strings to make a multi-line string.
			string auxstr;
			for (; irhs<nrhs; ++irhs)
				auxstr += getString(prhs[irhs]);
			// Call the actual function.
			if (pAst==NULL) { pAst = new CAstSig();	_fs=pAst->pEnv->Fs;}
			outlen = auxeval(auxstr.c_str(), outbufs, nChan);
		}
	}

	double *pdbl;
	mxArray *envInfo, *mxAns, **var;
	mwSize dim[]={1,1,};
	char *strBuffer=NULL;
	const char **fieldNames, *envName[5];
	int j, k(2), nFields = pAst->pEnv->Tags.size() + 2 ; // number of variables plus ans and EnvInfo
	
	envName[0] = "fs";
	envName[1] = "auxpath";
	envName[2] = "nVars";

	envInfo = mxCreateStructArray (1, dim, 3, envName);
	mxSetField (envInfo, 0, "nVars", mxCreateDoubleScalar(nFields-2));
	mxSetField (envInfo, 0, "fs", mxCreateDoubleScalar(pAst->pEnv->Fs));
	mxSetField (envInfo, 0, "auxpath", mxCreateString(pAst->pEnv->AuxPath.c_str()));

	fieldNames = new const char*[nFields];
	fieldNames[0] = "EnvInfo";
	fieldNames[1] = "ans";

	for ( map<string,CSignals>::iterator tag = pAst->pEnv->Tags.begin(); tag != pAst->pEnv->Tags.end(); tag++)
		fieldNames[k++] = tag->first.c_str();
	k=0;

	plhs[0] = mxCreateStructArray (1, dim, nFields, fieldNames);

	mxSetField (plhs[0], 0, fieldNames[0], envInfo);
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
		pdbl = mxGetPr(mxAns);
		for (CSignals *p=&(pAst->Sig); p; pdbl+=p->GetLength(),p=p->GetNextChan())
			memcpy(pdbl, p->buf, p->GetLength()*sizeof(double));
	}
	mxSetField (plhs[0], 0, fieldNames[1], mxAns);

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

