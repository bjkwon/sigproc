/* Psycon syntax parser */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "psycon.yacc.h"
#define strdup _strdup
#define YYPRINT(file, type, value) print_token_value (file, type, value)
/*#define DEBUG*/

char *ErrorMsg = NULL;
int yylex (void);
void yyerror (AstNode **pproot, char **errmsg, char const *s);
%}

/* Bison declarations. */
%locations
%token-table
%error-verbose
%debug

%union {
	double dval;
	char *str;
	AstNode *pnode;
}
%token T_UNKNOWN
%token T_NEWLINE	"end of line"
%token T_IF		"if"
%token T_ELSE		"else"
%token T_ELSEIF		"elseif"
%token T_END		"end"
%token T_WHILE		"while"
%token T_FOR		"for"
%token T_BREAK		"break"
%token T_CONTINUE	"continue"
%token T_SWITCH		"switch"
%token T_CASE		"case"
%token T_OTHERWISE	"otherwise"
%token T_FUNCTION	"function"
%token T_ENDFUNCTION	"endfunction"
%token T_RETURN		"return"
%token T_SIGMA		"sigma"
%token T_EOF	0	"end of text"
%token T_OP_SHIFT	">>"
%token T_OP_SHIFT2	"<<"
%token T_OP_CONCAT	"++"
%token T_COMP_EQ	"=="
%token T_COMP_NE	"!="
%token T_COMP_LE	"<="
%token T_COMP_GE	">="
%token T_LOGIC_AND	"&&"
%token T_LOGIC_OR	"||"
%token T_REPLICA	".."

%token <dval> T_NUMBER "number"
%token <str> T_STRING "string"	T_ID "identifier" T_HOOKCMD "HookCommand"
%token T_ENDPOINT	

%type <pnode> block block_func line line_func stmt funcdef elseif_list condition conditional case_list id_list arg arg_list vector matrix range exp_range assign exp initcell exp_time

%right '='
%left T_LOGIC_OR
%left T_LOGIC_AND
%left T_COMP_EQ T_COMP_NE 
%left '<' '>' T_COMP_LE T_COMP_GE
%left ':'
%left '-' '+' T_OP_CONCAT
%left T_OP_SHIFT T_OP_SHIFT2 '$' '%' '@'
%left '*' '/'
%right '^' /* exponentiation */
%left T_LOGIC_NOT T_POSITIVE T_NEGATIVE /* unary plus/minus */


/* the following two tokens MUST be the last two, for compatibility between cipsycon.tab.h and psycon.tab.h */
%token T_USEC		"us"
%token T_MSEC		"ms"

%parse-param {AstNode **pproot}
%parse-param {char **errmsg}

%initial-action
{
  if (ErrorMsg) {
	free(ErrorMsg);
	ErrorMsg = NULL;
  }
  *errmsg = NULL;
};

%destructor
{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName($$));
#endif
  yydeleteAstNode($$, 0);
} <pnode>
%destructor
{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", $$);
#endif
  free($$);
} <str>

%{
AstNode *newAstNode(int type, YYLTYPE loc);
AstNode *makeFunctionCall(char *name, AstNode *first, AstNode *second, YYLTYPE loc);
AstNode *makeBinaryOpNode(int op, AstNode *first, AstNode *second, YYLTYPE loc);
AstNode *makeCompoundLevelOpNode(char *first, AstNode *second, YYLTYPE loc1, YYLTYPE loc2);
AstNode *makeCompoundOpNode(int op, char *first, AstNode *second, YYLTYPE loc1, YYLTYPE loc2);
AstNode *makeCompoundOpNodeFunctionCall(int op, char *first, AstNode *second, YYLTYPE loc1, YYLTYPE loc2);
AstNode *Restring(char *oper, char* dummy1, AstNode *dumm2, AstNode *dummy3, AstNode *dummy4, YYLTYPE loc);
void print_token_value(FILE *file, int type, YYSTYPE value);
%}

%% /* The grammar follows. */
input: /* empty */
	{ *pproot = NULL;}
	| block_func	/* can be NULL */
	{ *pproot = $1;} //yyn=3
;

block_func: line_func	/* block_func can be NULL */
	{ $$ = $1; }
	| block_func line_func
	{ //yyn=5
		if ($2) {
			if ($1 == NULL)
				$$ = $2;
			else if ($1->type == NODE_BLOCK) 
			{
//				$$ = $1;
				$1->tail->next = $2;
				$1->tail = $2;
			} 
			else 
			{ // a=1; b=2; ==> $1->type is '='. So first, a NODE_BLOCK tree should be made.
				$$ = newAstNode(NODE_BLOCK, @$);
				$$->next = $1;
				$1->next = $$->tail = $2;
#ifdef _DEBUG				
				$$->str = (char*)malloc(32);
				strcpy_s ($$->str, 32, "block_begins,yyn=5");
#endif
			}
		} else
			$$ = $1;
	}
;

block:	line	/* complicated to prevent NULL (make empty block instead) or single statement block */
	{
		if ($1) // if cond1, x=1, end ==> x=1 comes here.
			$$ = $1;
		else
			$$ = newAstNode(NODE_BLOCK, @$);
	}
	| block line //yyn=7
	{
		if ($2) {
			if ($1->type == NODE_BLOCK) {
				if ($$->next) {
//					$$ = $1;
					$1->tail->next = $2;
					$1->tail = $2;
				} else {
					$$ = $2;
					free($1);
				}
			} else { //if the second argument doesn't have NODE_BLOCK, make one
				$$ = newAstNode(NODE_BLOCK, @$);
				$$->next = $1;
				$1->next = $$->tail = $2;
#ifdef _DEBUG				
				$$->str = (char*)malloc(32);
				strcpy_s ($$->str, 32, "block_begins,yyn=7");
#endif				
			}
		}
		else // only "block" is given
			$$ = $1;
	}
;

line:	T_NEWLINE 
	{ $$ = NULL;} //yyn=8
	| error T_NEWLINE 
	{ //yyn=9
		$$ = NULL;
		yyerrok;
	} 
	| stmt eol
	{ $$ = $1;} //yyn=10
;

line_func: line
	{ $$ = $1;} //yyn=11
	| funcdef
	{ $$ = $1;} //yyn=12
;

eol: ',' | ';' | T_NEWLINE | T_EOF
;

func_end: /* empty */ | T_ENDFUNCTION | T_EOF
;


exp_time: exp
	{ $$ = $1;}
	| exp T_MSEC
	{
		$$ = newAstNode(NODE_MSEC, @$);
		$$->child = $1;
	}
	| exp T_USEC
	{
		$$ = newAstNode(NODE_USEC, @$);
		$$->child = $1;
	}
;

conditional: condition
	{	$$ = $1;	}
	| condition eol
	{	$$ = $1;	}
	| exp
	{	$$ = $1;	}
	| exp eol
	{	$$ = $1;	}
;

elseif_list: /*empty*/
	{
		$$ = newAstNode(T_IF, @$);
	}
	| T_ELSEIF conditional block elseif_list 
	{
		$$ = newAstNode(T_IF, @$);
		$$->child = $2;
		$2->next = $3;
		$2->alt = $4;
	}
	| elseif_list T_ELSE block
	{
		if ($1->child==NULL) // in this case $1 is T_IF created as /*empty*/ 
		{  
			yydeleteAstNode($1, 1);
			$$ = $3;
		}
		else
		{
			$$ = $1;
			$1->alt = $3;
		}
	}
;

stmt: exp
	{ $$ = $1;}
	| assign
	{ $$ = $1;} //yyn=28
	| condition
	{ $$ = $1;}
	| initcell
	{ $$ = $1;}
	| T_HOOKCMD
	{
		$$ = newAstNode(NODE_CALL, @$);
 		$$->str = malloc(strlen($1)+1);
 		strcpy($$->str, $1);
 		free($1);
	}
	| T_IF conditional block elseif_list T_END
	{ // This works, too, for "if cond, act; end" without else, because elseif_list can be empty
		$$ = newAstNode(T_IF, @$);
		$$->child = $2;
		$2->next = $3;
		$2->alt = $4;
		if ($4->child==NULL && $4->next==NULL) // When elseif_list is empty, T_IF is made, but no child and next
		{
			yydeleteAstNode($$->alt, 1);
			$$->alt=NULL;
		}
		$$->line = @$.first_line;
		$$->col = @$.first_column;
	}
	| T_SWITCH exp case_list T_END
	{
		$$ = $3;
		$2->next = $3->child;
		$$->child = $2;
		$$->line = @$.first_line;
		$$->col = @$.first_column;
	}
	| T_SWITCH exp case_list T_OTHERWISE block T_END
	{
		$$ = $3;
		$2->next = $3->child;
		$3->tail->next = $5;
		$$->child = $2;
		$$->line = @$.first_line;
		$$->col = @$.first_column;
	}
	| T_WHILE conditional block T_END
	{
		$$ = newAstNode(T_WHILE, @$);
		$2->next = $3;
		$$->child = $2;
	}
	| T_FOR T_ID '=' exp_range block T_END
	{
		$$ = newAstNode(T_FOR, @$);
		$$->child = newAstNode('=', @2);
		$$->child->str = $2;
		$$->child->child = $4;
		$$->child->next = $5;
	}
	| T_FOR T_ID '=' exp_range ',' block T_END
	{
		$$ = newAstNode(T_FOR, @$);
		$$->child = newAstNode('=', @2);
		$$->child->str = $2;
		$$->child->child = $4;
		$$->child->next = $6;
	}
	| T_RETURN
	{
		$$ = newAstNode(T_RETURN, @$);
	}
	| T_BREAK
	{ $$ = newAstNode(T_BREAK, @$);}
	| T_CONTINUE
	{ $$ = newAstNode(T_CONTINUE, @$);}
	| '(' exp ',' exp ')' exp_time ',' exp ',' exp
	{
		$$ = newAstNode(NODE_CIPULSE3, @$);
		$$->child = $2;
		$2->next = $4;
		$4->next = $6;
		$6->next = $8;
		$8->next = $10;
	}
	| '('  exp ',' exp ')' exp_time ',' exp ',' exp ',' exp_time
	{
		$$ = newAstNode(NODE_CIPULSE4, @$);
		$$->child = $2;
		$2->next = $4;
		$4->next = $6;
		$6->next = $8;
		$8->next = $10;
		$10->next = $12;
	}
	| '('  exp ',' exp ')' exp_time ',' exp ',' exp ',' exp ',' exp
	{
		$$ = newAstNode(NODE_CIPULSE5, @$);
		$$->child = $2;
		$2->next = $4;
		$4->next = $6;
		$6->next = $8;
		$8->next = $10;
		$10->next = $12;
		$12->next = $14;
	}
	| '('  exp ',' exp ')' exp_time ',' exp ',' exp ',' exp ',' exp ',' exp_time
	{
		$$ = newAstNode(NODE_CIPULSE6, @$);
		$$->child = $2;
		$2->next = $4;
		$4->next = $6;
		$6->next = $8;
		$8->next = $10;
		$10->next = $12;
		$12->next = $14;
		$14->next = $16;
	}	
;

funcdef: T_FUNCTION T_ID '(' id_list ')' block func_end
	{
		$$ = newAstNode(T_FUNCTION, @$);
		$$->str = $2;
		$$->child = $4;
		$4->next = $6;
	}
	| T_FUNCTION T_ID '=' T_ID '(' id_list ')' block func_end
	{
		$$ = newAstNode(T_FUNCTION, @$);
		$$->str = $4;
		$$->child = $6;
		$6->next = $8;
		$$->alt = newAstNode(NODE_VECTOR, @2);
		$$->alt->child = $$->alt->tail = newAstNode(T_ID, @3);
		$$->alt->child->str = $$->alt->tail->str = $2;
	}
	| T_FUNCTION '[' vector ']' '=' T_ID '(' id_list ')' block func_end
	{
		$$ = newAstNode(T_FUNCTION, @$);
		$$->str = $6;
		$$->child = $8;
		$8->next = $10;
		$$->alt = $3;

		}
	| T_FUNCTION T_ID '{' '}' '=' T_ID '(' id_list ')' block func_end
	{
		$$ = newAstNode(T_FUNCTION, @$);
		$$->str = $6;
		$$->child = $8;
		$8->next = $10;
		$10->next = newAstNode(NODE_INITCELL, @2);
		$10->next->str = $2;
	}
;

case_list: /* empty */
	{ $$ = newAstNode(T_SWITCH, @$);}
	| T_NEWLINE
	{ $$ = newAstNode(T_SWITCH, @$);}
	| case_list T_CASE exp T_NEWLINE block
	{
		if ($1->child)
			$1->tail->next = $3;
		else
			$1->child = $3;
		$3->next = $5;
		$1->tail = $5;
		$$ = $1;
	}
	| case_list T_CASE '{' arg_list '}' block
	{
		if ($1->child)
			$1->tail->next = $4;
		else
			$1->child = $4;
		$4->next = $6;
		$1->tail = $6;
		$$ = $1;
	}
;

condition: exp '<' exp
	{ $$ = makeBinaryOpNode('<', $1, $3, @$);}
	| range '<' exp
	{ $$ = makeBinaryOpNode('<', $1, $3, @$);}
	| exp '<' range
	{ $$ = makeBinaryOpNode('<', $1, $3, @$);}
	| exp '>' exp
	{ $$ = makeBinaryOpNode('>', $1, $3, @$);}
	| range '>' exp
	{ $$ = makeBinaryOpNode('>', $1, $3, @$);}
	| exp '>' range
	{ $$ = makeBinaryOpNode('>', $1, $3, @$);}
	| exp T_COMP_EQ exp
	{ $$ = makeBinaryOpNode(T_COMP_EQ, $1, $3, @$);}
	| range T_COMP_EQ exp
	{ $$ = makeBinaryOpNode(T_COMP_EQ, $1, $3, @$);}
	| exp T_COMP_EQ range
	{ $$ = makeBinaryOpNode(T_COMP_EQ, $1, $3, @$);}
	| exp T_COMP_NE exp
	{ $$ = makeBinaryOpNode(T_COMP_NE, $1, $3, @$);}
	| range T_COMP_NE exp
	{ $$ = makeBinaryOpNode(T_COMP_NE, $1, $3, @$);}
	| exp T_COMP_NE range
	{ $$ = makeBinaryOpNode(T_COMP_NE, $1, $3, @$);}
	| exp T_COMP_GE exp
	{ $$ = makeBinaryOpNode(T_COMP_GE, $1, $3, @$);}
	| range T_COMP_GE exp
	{ $$ = makeBinaryOpNode(T_COMP_GE, $1, $3, @$);}
	| exp T_COMP_GE range
	{ $$ = makeBinaryOpNode(T_COMP_GE, $1, $3, @$);}
	| exp T_COMP_LE exp
	{ $$ = makeBinaryOpNode(T_COMP_LE, $1, $3, @$);}
	| range T_COMP_LE exp
	{ $$ = makeBinaryOpNode(T_COMP_LE, $1, $3, @$);}
	| exp T_COMP_LE range
	{ $$ = makeBinaryOpNode(T_COMP_LE, $1, $3, @$);}
	| '(' condition ')'
	{
		$$ = $2;
		$$->line = @$.first_line;
		$$->col = @$.first_column;
	}
	| '!' condition %prec T_LOGIC_NOT
	{
		$$ = newAstNode(T_LOGIC_NOT, @$);
		$$->child = $2;
	}
	| '!' exp %prec T_LOGIC_NOT
	{
		$$ = newAstNode(T_LOGIC_NOT, @$);
		$$->child = $2;
	}
	| condition T_LOGIC_AND condition
	{ $$ = makeBinaryOpNode(T_LOGIC_AND, $1, $3, @$);}
	| exp T_LOGIC_AND exp
	{ $$ = makeBinaryOpNode(T_LOGIC_AND, $1, $3, @$);}
	| condition T_LOGIC_AND exp
	{ $$ = makeBinaryOpNode(T_LOGIC_AND, $1, $3, @$);}
	| exp T_LOGIC_AND condition
	{ $$ = makeBinaryOpNode(T_LOGIC_AND, $1, $3, @$);}
	| condition T_LOGIC_OR condition
	{ $$ = makeBinaryOpNode(T_LOGIC_OR, $1, $3, @$);}
	| exp T_LOGIC_OR exp
	{ $$ = makeBinaryOpNode(T_LOGIC_OR, $1, $3, @$);}
	| condition T_LOGIC_OR exp
	{ $$ = makeBinaryOpNode(T_LOGIC_OR, $1, $3, @$);}
	| exp T_LOGIC_OR condition
	{ $$ = makeBinaryOpNode(T_LOGIC_OR, $1, $3, @$);}
;

id_list: /* empty */
	{
		$$ = newAstNode(NODE_IDLIST, @$);
	}
	| T_ID
	{
		$$ = newAstNode(NODE_IDLIST, @$);
		$$->child = $$->tail = newAstNode(T_ID, @$);
		$$->tail->str = $1;
	}
	| T_ID '{' '}'
	{
		$$ = newAstNode(NODE_IDLIST, @$);
		$$->child = $$->tail = newAstNode(NODE_INITCELL, @$);
		$$->tail->str = $1;
	}
	| id_list ',' T_ID
	{
		$1->tail = $1->tail->next = newAstNode(T_ID, @3);
		$$ = $1;
		$$->tail->str = $3;
	}
	| id_list ',' T_ID '{' '}'
	{
		$1->tail = $1->tail->next = newAstNode(NODE_INITCELL, @3);
		$$ = $1;
		$$->tail->str = $3;
	}
;

arg: exp_range
	{ $$ = $1; } //yyn=85
	| initcell
	{ $$ = $1; }
;

arg_list: arg
	{
		$$ = newAstNode(NODE_ARGS, @$);
		$$->child = $$->tail = $1;
	}
	| arg_list ',' arg
	{
		$1->tail = $1->tail->next = $3;
		$$ = $1;
	}
;

matrix: /* empty */
	{
		$$ = newAstNode(NODE_MATRIX, @$);
	}
	| vector
	{
		$$ = newAstNode(NODE_MATRIX, @$);
		$$->child = $$->tail = $1;
	}
	| matrix ';' vector
	{
		$1->tail = $1->tail->next = $3;
		$$ = $1;
	}
;

vector: exp_range
	{
		$$ = newAstNode(NODE_VECTOR, @$);
		$$->child = $$->tail = $1;
	}
	| vector exp_range
	{
		$1->tail = $1->tail->next = $2;
		$$ = $1;
	}
	| vector ',' exp_range
	{
		$1->tail = $1->tail->next = $3;
		$$ = $1;
	}
;

range: exp ':' exp
	{
		$$ = makeFunctionCall(":", $1, $3, @$);
	}
	| exp ':' exp ':' exp
	{
		$$ = makeFunctionCall(":", $1, $5, @$);
		$$->tail = $5->next = $3;
	}
;

exp_range: exp
	{ $$ = $1;}
	| range
	{ $$ = $1;}
;

assign: T_ID '=' exp_range
	{
		$$ = newAstNode('=', @$);
		$$->str = $1;
		$$->child = $3;
	}
	| '[' vector ']' '=' exp_range
	{ // Only to be used when RHS is a UDF. 5/18/2017 bjkwon
		$$ = newAstNode('=', @$);
		$$->child = $5;
		$$->alt = $2;
	}
	| T_ID '=' condition
	{
		$$ = newAstNode('=', @$);
		$$->str = $1;
		$$->child = $3;
	}
	| T_ID "+=" exp_range
	{
		$$ = newAstNode('=', @$);
		$$->str = $1;
		$$->child = makeCompoundOpNode('+', $1, $3, @3, @1);
	}
	| T_ID "-=" exp_range
	{
		$$ = newAstNode('=', @$);
		$$->str = $1;
		$$->child = makeCompoundOpNode('-', $1, $3, @3, @1);
	}
	| T_ID "*=" exp_range
	{
		$$ = newAstNode('=', @$);
		$$->str = $1;
		$$->child = makeCompoundOpNode('*', $1, $3, @3, @1);
	}
	| T_ID "/=" exp_range
	{
		$$ = newAstNode('=', @$);
		$$->str = $1;
		$$->child = makeCompoundOpNode('/', $1, $3, @3, @1);
	}
	| T_ID "^=" exp_range
	{
		$$ = newAstNode('=', @$);
		$$->str = $1;
		$$->child = makeCompoundOpNodeFunctionCall('^', $1, $3, @3, @1);
	}
	| T_ID "@=" exp_range
	{
		$$ = newAstNode('=', @$);
		$$->str = $1;
		$$->child = makeCompoundOpNode('@', $1, $3, @3, @1);
	}
	| T_ID "@@=" exp_range
	{ 
		$$ = newAstNode('=', @$);
		$$->str = $1; 
		$$->child = makeCompoundLevelOpNode($1, $3, @1, @3);
	}
	| T_ID "++=" exp_range
	{
		$$ = newAstNode('=', @$);
		$$->str = $1;
		$$->child = makeCompoundOpNode(T_OP_CONCAT, $1, $3, @3, @1);
	}
	| T_ID '{' exp '}' '=' exp_range
	{
		$$ = newAstNode(NODE_INITCELL, @$);
		$$->str = $1;
		$$->child = $6;
		$$->alt = $3;
	}
	| T_ID '(' exp '~' exp ')' "+=" exp_range
	{
		$$ = Restring("+=", $1, $3, $5, $8, @$);
	}
	| T_ID '(' exp '~' exp ')' "-=" exp_range
	{
		$$ = Restring("-=", $1, $3, $5, $8, @$);
	}
	| T_ID '(' exp '~' exp ')' "*=" exp_range
	{
		$$ = Restring("*=", $1, $3, $5, $8, @$);
	}
	| T_ID '(' exp '~' exp ')' "/=" exp_range
	{
		$$ = Restring("/=", $1, $3, $5, $8, @$);
	}
	| T_ID '(' exp '~' exp ')' "@=" exp_range
	{
		$$ = Restring("@=", $1, $3, $5, $8, @$);
	}
	| T_ID '(' exp '~' exp ')' "@@=" exp_range
	{
		$$ = Restring("@@=", $1, $3, $5, $8, @$);
	}
	| T_ID '(' arg_list ')' '=' exp_range 
	{ /* x(45)=723 or x(id1:id2) = id1:id2  or x(array) = scalar */
		$$ = newAstNode(NODE_IXASSIGN, @$);
		$$->str = $1;
		$$->child = $6;
		$$->alt = $3;
	}
	| T_ID '(' condition ')' '=' exp_range
	{ /* x(x>0) = scalar */
		$$ = newAstNode(NODE_IXASSIGN, @$);
		$$->str = $1;
		$$->child = $6;
		$$->alt = $3;
	}
	| T_ID '(' exp '~' exp ')' '=' exp
	{
		$$ = newAstNode(NODE_IXASSIGN, @$);
		$$->str = $1;
		$$->child = $8;
		$$->alt = newAstNode(NODE_IDLIST, @$);
		$$->alt->child = $5;
		$$->alt->alt = $3;
	}
	| T_ID '{' exp '}' '(' exp '~' exp ')' '=' exp
	{
		$$ = newAstNode(NODE_INITCELL, @$);
		$$->str = $1;
		$$->child = $11;
		$$->alt = $3;
		$3->alt = newAstNode(NODE_IDLIST, @$);
		$3->alt->child = $8;
		$3->alt->alt = $6;
	}
	//T_ID '{' exp '}' '(' arg_list ')' '=' exp_range  -->  does not work 4/8/2017 bjk
	| T_ID '{' exp '}' '(' exp ')' '=' exp_range
	{ // v{2}(4)=1 
		$$ = newAstNode(NODE_INITCELL, @$);
		$$->str = $1;
		$$->child = $9;
		$$->alt = $3;
		$3->next = $6;
	}	
	| T_ID '{' exp '}' '(' exp_range ')' '=' exp_range
	{ // v{2}(4:6)=1 
		$$ = newAstNode(NODE_INITCELL, @$);
		$$->str = $1;
		$$->child = $9;
		$$->alt = $3;
		$3->next = $6;
	}
	| T_ID '=' assign
	{
		$$ = newAstNode('=', @$);
		$$->str = $1;
		$$->child = $3;
	}
	| T_ID '{' exp '}' '=' assign
	{
		$$ = newAstNode('=', @$);
		$$->str = $1;
		$$->child = $6;
		$6->alt = $3;
	}
	| T_ID '(' arg_list ')' '=' assign
	{
		$$ = newAstNode(NODE_IXASSIGN, @$);
		$$->str = $1;
		$$->child = $6;
		$6->alt = $3;
	}
	| T_ID '{' exp '}' '(' exp ')' '=' assign
	{
		$$ = newAstNode(NODE_IXASSIGN, @$);
		$$->str = $1;
		$$->child = $9;
		$9->alt = $6;
		$6->alt = $3;
	}
	| T_ID '=' initcell 
	{ // x={"bjk",noise(300), 4.5555}
		$$ = $3;
		$$->str = $1;
		$$->line = @$.first_line;
		$$->col = @$.first_column;
	}
;

exp: T_NUMBER
	{
		$$ = newAstNode(T_NUMBER, @$);
		$$->dval = $1;
	}
	| T_STRING
	{
		$$ = newAstNode(T_STRING, @$);
		$$->str = $1;
	}
	| T_ENDPOINT
	{
		$$ = newAstNode(T_ENDPOINT, @$);
		$$->str = NULL;
	}
	| initcell
	{
		$$ = $1;
	}
	| T_ID
	{
		$$ = newAstNode(T_ID, @$);
		$$->str = $1;
//		yyPrintf("T_ID", $$);
	}
	| T_ID '{' exp '}'
	{
		$$ = newAstNode(T_ID, @$);
		$$->str = $1;
		$$->child = $3;
	}
	| T_ID '{' exp '}' '(' exp ')'
	{
		$$ = newAstNode(T_ID, @$);
		$$->str = $1;
		$$->child = $3;
		$3->alt = $6;
	}
	| T_ID '{' exp '}' '(' exp_range ')'
	{
		$$ = newAstNode(T_ID, @$);
		$$->str = $1;
		$$->child = $3;
		$3->alt = $6;
	}
	| '{' '}'
	{
		$$ = newAstNode(NODE_INITCELL, @$);
	}
	| T_ID '{' '}'
	{
		$$ = newAstNode(NODE_INITCELL, @$);
		$$->str = $1;
	}
	| T_ID '(' ')'
	{ // I don't know what this is doing.... bjk 3/28/2017 
		$$ = newAstNode(NODE_CALL, @$);
 		$$->str = $1;
	}
	| T_ID '(' arg_list ')'
	{
		$$ = $3;
		$$->type = NODE_CALL;
 		$$->str = $1;
		$$->line = @$.first_line;
		$$->col = @$.first_column;
	}
	| T_REPLICA '(' arg_list ')'
	{
		$$ = newAstNode(T_REPLICA, @$);
		$$->child = $3;
		$$->child->type = NODE_CALL;
		// At this point, this makes NODE_CALL with NULL str. This is to be resolved in AstSig.cpp-----AstNode *tp = searchtree(p, NODE_CALL);
	}
	| T_ID '(' condition ')'
	{
		$$ = newAstNode(NODE_CALL, @$);
 		$$->str = $1;
		$$->child = $3;
		$$->tail = $3; // leaving a mark for conditional indexing 3/28/2017 bjk
		$$->line = @$.first_line;
		$$->col = @$.first_column;
	}
	| '#' T_ID '(' arg_list ')' // don't need any more.  left here for backw comp. 7/4/2017.
	{
		$$ = $4;
		$$->type = NODE_CALL;
 		$$->str = malloc(strlen($2)+2);
 		$$->str[0] = '#';
 		strcpy($$->str+1, $2);
 		free($2);
		$$->line = @$.first_line;
		$$->col = @$.first_column;
	}
	| T_ID '(' exp '~' exp ')'
	{
		$$ = newAstNode(NODE_EXTRACT, @$);
		$$->child = newAstNode(T_ID, @1);
		$$->child->str = $1;
		$$->child->next = $3;
		$3->next = $5;
	}
	| '-' exp %prec T_NEGATIVE
	{
		$$ = newAstNode(T_NEGATIVE, @$);
		$$->child = $2;
	}
	| '+' exp %prec T_POSITIVE
	{
		$$ = $2;
		$$->line = @$.first_line;
		$$->col = @$.first_column;
	}
	| '(' exp_range ')'
	{
		$$ = $2;
		$$->line = @$.first_line;
		$$->col = @$.first_column;
	}
	| T_SIGMA '(' T_ID '=' exp_range ',' exp ')'
	{
		$$ = newAstNode(T_SIGMA, @$);
		$$->child = newAstNode('=', @3);
		$$->child->str = $3;
		$$->child->child = $5;
		$$->child->next = $7;
	}
	| exp '+' exp
	{ $$ = makeBinaryOpNode('+', $1, $3, @$);}
	| exp '-' exp
	{ $$ = makeBinaryOpNode('-', $1, $3, @$);}
	| exp '*' exp
	{ $$ = makeBinaryOpNode('*', $1, $3, @$);}
	| exp '/' exp
	{ $$ = makeBinaryOpNode('/', $1, $3, @$);}
	| exp '^' exp
	{ $$ = makeFunctionCall("^", $1, $3, @$);}
	| exp '%' exp
	{ $$ = makeFunctionCall("caret", $1, $3, @$);}
	| exp '$' exp
	{ $$ = makeFunctionCall("shift_spectrum", $1, $3, @$);}
	| exp '@' exp
	{ $$ = makeBinaryOpNode('@', $1, $3, @$);}
	| exp '@' exp '|' exp
	{
		$$ = newAstNode(NODE_INTERPOL, @$);
		$$->child = $1;
		$1->next = $3;
		$3->next = $5;
		$$->tail = $5;
	}
	| exp T_OP_SHIFT exp
	{ $$ = makeBinaryOpNode(T_OP_SHIFT, $1, $3, @$);}
	| exp T_OP_SHIFT2 exp
	{ $$ = makeBinaryOpNode(T_OP_SHIFT2, $1, $3, @$);}
	| exp T_OP_CONCAT exp
	{ $$ = makeBinaryOpNode(T_OP_CONCAT, $1, $3, @$);}
	| '[' matrix ']'
	{
		$$ = $2;
		$$->line = @$.first_line;
		$$->col = @$.first_column;
	}
	| '[' vector ']'
	{
		$$ = $2;
		$$->line = @$.first_line;
		$$->col = @$.first_column;
	}
	| T_REPLICA
	{
		$$ = newAstNode(T_REPLICA, @$);
		$$->str = NULL;
	}
;

initcell: '{' arg_list '}'
	{
		$$ = $2;
		$$->type = NODE_INITCELL;
		$$->line = @$.first_line;
		$$->col = @$.first_column;
	}
;

%%

/* Called by yyparse on error. */
void yyerror (AstNode **pproot, char **errmsg, char const *s)
{
  static size_t errmsg_len = 0;
#define ERRMSG_MAX 999
  char msgbuf[ERRMSG_MAX], *p;
  size_t msglen;

  sprintf_s(msgbuf, ERRMSG_MAX, "Line %d, Col %d: %s.\n", yylloc.first_line, yylloc.first_column, s + (strncmp(s, "syntax error, ", 14) ? 0 : 14));
  if ((p=strstr(msgbuf, "$undefined"))) {
	sprintf_s(p, 10, "'%c'(%d)", yychar, yychar);
    strcpy(p+strlen(p), p+10);
  }
  if ((p=strstr(msgbuf, "end of text or ")))
    strcpy(p, p+15);
  if ((p=strstr(msgbuf, " or ','")))
    strcpy(p, p+7);
  msglen = strlen(msgbuf);
  if (ErrorMsg == NULL)
    errmsg_len = 0;
  ErrorMsg = (char *)realloc(ErrorMsg, errmsg_len+msglen+1);
  strcpy_s(ErrorMsg+errmsg_len, msglen+1, msgbuf);
  errmsg_len += msglen;
  *errmsg = ErrorMsg;
}


int getTokenID(const char *str)
{
	size_t len, i;
	len = strlen(str);
	for (i = 0; i < YYNTOKENS; i++) {
		if (yytname[i] != 0
			&& yytname[i][0] == '"'
			&& !strncmp (yytname[i] + 1, str, len)
			&& yytname[i][len + 1] == '"'
			&& yytname[i][len + 2] == 0)
				break;
	}
	if (i < YYNTOKENS)
		return yytoknum[i];
	else
		return T_UNKNOWN;
}


void print_token_value(FILE *file, int type, YYSTYPE value)
{
	if (type == T_ID)
		fprintf (file, "%s", value.str);
	else if (type == T_NUMBER)
		fprintf (file, "%f", value.dval);
}


char *getAstNodeName(AstNode *p)
{
#define NODE_NAME_MAX 99
  static char buf[NODE_NAME_MAX];

  if (!p)
	return NULL;
  switch (p->type) {
  case '=':
    sprintf_s(buf, NODE_NAME_MAX, "[%s=]", p->str);
    break;
  case T_ID:
    sprintf_s(buf, NODE_NAME_MAX, "[%s]", p->str);
    break;
  case T_STRING:
    sprintf_s(buf, NODE_NAME_MAX, "\"%s\"", p->str);
    break;
  case NODE_CALL:
    sprintf_s(buf, NODE_NAME_MAX, "%s()", p->str);
    break;
  case T_NUMBER:
    sprintf_s(buf, NODE_NAME_MAX, "%.1f", p->dval);
    break;
  case NODE_BLOCK:
    sprintf_s(buf, NODE_NAME_MAX, "BLOCK");
    break;
  case NODE_ARGS:
    sprintf_s(buf, NODE_NAME_MAX, "ARGS");
    break;
  case NODE_MATRIX:
    sprintf_s(buf, NODE_NAME_MAX, "MATRIX");
    break;
  case NODE_VECTOR:
    sprintf_s(buf, NODE_NAME_MAX, "VECTOR");
    break;
  case NODE_IDLIST:
    sprintf_s(buf, NODE_NAME_MAX, "ID_LIST");
    break;
  case NODE_EXTRACT:
    sprintf_s(buf, NODE_NAME_MAX, "EXTRACT");
    break;
  case NODE_INITCELL:
    sprintf_s(buf, NODE_NAME_MAX, "INITCELL");
    break;
  case NODE_IXASSIGN:
    sprintf_s(buf, NODE_NAME_MAX, "ASSIGN1");
    break;
  case NODE_INTERPOL:
    sprintf_s(buf, NODE_NAME_MAX, "INTERPOL");
    break;
  case NODE_RESTRING:
    sprintf_s(buf, NODE_NAME_MAX, "RESTRING");
    break;
  default:
    if (YYTRANSLATE(p->type) == 2)
      sprintf_s(buf, NODE_NAME_MAX, "[%d]", p->type);
    else
      sprintf_s(buf, NODE_NAME_MAX, "%s", yytname[YYTRANSLATE(p->type)]);
  }
  return buf;
}


AstNode *makeFunctionCall(char *name, AstNode *first, AstNode *second, YYLTYPE loc)
{
	AstNode *nn;

	nn = newAstNode(NODE_CALL, loc);
	nn->str = strdup(name);
	nn->child = first;
	nn->tail = first->next = second;
	return nn;
}

AstNode *makeBinaryOpNode(int op, AstNode *first, AstNode *second, YYLTYPE loc)
{
	AstNode *nn;

	nn = newAstNode(op, loc);
	nn->child = first;
	nn->tail = first->next = second;
	return nn;
}

AstNode *makeCompoundOpNode(int op, char *first, AstNode *second, YYLTYPE loc1, YYLTYPE loc2)
{
	AstNode *nn;
	char *tempstrpt;
	nn = newAstNode(op, loc1);
	nn->child = newAstNode(T_ID, loc1);
	tempstrpt = (char*)malloc(strlen(first)+1); /* This will be cleaned up during yydeleteAstNode().*/
	strcpy_s(tempstrpt, strlen(first)+1, first);
	nn->child->str = tempstrpt;
	nn->tail = nn->child->next = second;
	return nn;
}

AstNode *makeCompoundOpNodeFunctionCall(int op, char *first, AstNode *second, YYLTYPE loc1, YYLTYPE loc2)
{
	AstNode *nn;
	char *tempstrpt, *tempstrpt2;
	
	nn = newAstNode(NODE_CALL, loc2);
	tempstrpt = (char*)calloc(2,1); /* This will be cleaned up during yydeleteAstNode().*/ /* because this is for op which is a char*/
	tempstrpt[0] = op;
	nn->str = strdup(tempstrpt);
	nn->tail = second;
	
	nn->child = newAstNode(T_ID, loc1);
	tempstrpt2 = (char*)malloc(strlen(first)+1); /* This will be cleaned up during yydeleteAstNode().*/
	strcpy_s(tempstrpt2, strlen(first)+1, first);
	nn->child->str = tempstrpt2;
	nn->tail = nn->child->next = second;
	return nn;
}

AstNode *makeCompoundLevelOpNode(char *first, AstNode *second, YYLTYPE loc1, YYLTYPE loc2)
{
	AstNode *nn;
	
	char *tempstrpt, *tempstrpt2;
	tempstrpt = malloc(strlen(first)+1); /* To be cleaned up automatically by yydeleteAstNode */
	strcpy_s(tempstrpt, strlen(first)+1, first); 
	tempstrpt2 = malloc(strlen(first)+1); /* To be cleaned up automatically by yydeleteAstNode */
	strcpy_s(tempstrpt2, strlen(first)+1, first); 
	
	nn = newAstNode('@', loc2);
	nn->child = newAstNode('@', loc2);
	nn->child->child = newAstNode(T_ID, loc1);
	nn->child->child->str = tempstrpt;
	nn->child->tail = nn->child->child->next = newAstNode(T_ID, loc1);
	nn->child->tail->str = tempstrpt2;
	nn->tail = nn->child->next = second;
	return nn;
}

AstNode *Restring(char *oper, char* dummy1, AstNode *dumm2, AstNode *dummy3, AstNode *dummy4, YYLTYPE loc)
{
	AstNode *nn;
	char *tempstrpt;
	tempstrpt = (char*)malloc(8); /* To be cleaned up during yydeleteAstNode().*/
	strcpy_s(tempstrpt, 8, oper);
	nn = newAstNode(NODE_RESTRING, loc);
	nn->str = tempstrpt;
	return nn;
}

AstNode *newAstNode(int type, YYLTYPE loc)
{
#ifdef DEBUG
    static int cnt=0;
#endif
  AstNode *nn;

  nn = (AstNode *)malloc(sizeof(AstNode));
  if (nn==NULL)
    exit(2);
  memset(nn, 0, sizeof(AstNode));
  nn->type = type;
#ifdef DEBUG
    printf("created node %d: %s\n", ++cnt, getAstNodeName(nn));
#endif
  nn->line = loc.first_line;
  nn->col = loc.first_column;
  return nn;
}


int yydeleteAstNode(AstNode *p, int fSkipNext)
{
#ifdef DEBUG
    static int cnt=0;
#endif
  AstNode *tmp, *next;
  
  if (!p)
	return 0;
#ifdef DEBUG
    printf("deleting node %d: %s\n", ++cnt, getAstNodeName(p));
#endif
  if (p->str)
    free(p->str);
  if (p->child)
    yydeleteAstNode(p->child, 0);
  if (!fSkipNext && p->next) {
	for (tmp=p->next; tmp; tmp=next) {
      next = tmp->next;
      yydeleteAstNode(tmp, 1);
    }
  }
  free(p);
  return 0;
}

int yyPrintf(const char *msg, AstNode *p)
{
	if (p)
		printf("[%16s]token type: %d, %s, \n", msg, p->type, p->str);
	return 1;
}