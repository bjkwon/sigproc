#define yyparse_trace(fname) \
{  FILE *fpp=fopen(fname,"at");\
  if(yyn<=19) \
	  fprintf(fpp,"%d\n", yyn);\
  else\
	  fprintf(fpp,"%d\t", yyn);\
  fclose(fpp);\
}