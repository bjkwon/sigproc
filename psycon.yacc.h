#ifndef PSYCONYACC
#define PSYCONYACC
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define NODE_BLOCK		10000
#define NODE_ARGS		10001
#define NODE_MATRIX		10002
#define NODE_VECTOR		10003
#define NODE_CALL		10004
#define NODE_FUNC		10005
#define NODE_IDLIST		10006
#define NODE_EXTRACT	10007
#define NODE_INITCELL	10008
#define NODE_IXASSIGN	10009
#define NODE_INTERPOL	10010
#define NODE_RESTRING	10011

#define NODE_USEC		10101
#define NODE_MSEC		10102
#define NODE_CIPULSE3	10103
#define NODE_CIPULSE4	10104
#define NODE_CIPULSE5	10105
#define NODE_CIPULSE6	10106

typedef struct AstNode_t {
  int type, line, column;
  double dval;
  char *str;
  struct AstNode_t *child;
  struct AstNode_t *alt;
#ifndef CISIGPROC  
  struct AstNode_t *tail;
#else  
  struct AstNode_t *LastChild;
#endif
  struct AstNode_t *next;
} AstNode;

extern int yydebug;

int getTokenID(const char *str);
char *getAstNodeName(AstNode *p);
__declspec (dllexport) int yyparse(AstNode **pproot, char **errmsg);
__declspec (dllexport) int yydeleteAstNode(AstNode *p, int fSkipNext);

__declspec (dllexport) int yysetNewStringToScan(const char *source);
__declspec (dllexport) int yysetNewFileToScan(FILE *source);

#ifdef __cplusplus
}
#endif 