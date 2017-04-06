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

%token <dval> T_NUMBER "number"
%token <str> T_STRING "string"	T_ID "identifier" T_DUR	"fT" T_LENGTH	"fP"
%type <pnode> block block_func line line_func stmt funcdef elseif_list condition case_list id_list arg arg_list vector matrix range exp_range assign exp initcell

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
	{ *pproot = $1;}
;

block_func: line_func	/* block_func can be NULL */
	{ $$ = $1; }
	| block_func line_func
	{
		if ($2) {
			if ($1 == NULL)
				$$ = $2;
			else if ($1->type == NODE_BLOCK) {
				$1->LastChild = $1->LastChild->next = $2;
				$$ = $1;
			} else {
				$$ = newAstNode(NODE_BLOCK, @$);
				$$->child = $1;
				$$->LastChild = $$->child->next = $2;
			}
		} else
			$$ = $1;
	}
;

block:	line	/* complicated to prevent NULL (make empty block instead) or single statement block */
	{
		if ($1)
			$$ = $1;
		else
			$$ = newAstNode(NODE_BLOCK, @$);
	}
	| block line
	{
		if ($2) {
			if ($1->type == NODE_BLOCK) {
				if ($1->LastChild) {
					$1->LastChild = $1->LastChild->next = $2;
					$$ = $1;
				} else {
					$$ = $2;
					free($1);
				}
			} else {
				$$ = newAstNode(NODE_BLOCK, @$);
				$$->child = $1;
				$$->LastChild = $$->child->next = $2;
			}
		} else
			$$ = $1;
	}
;

line:	T_NEWLINE
	{ $$ = NULL;}
	| error T_NEWLINE
	{
		$$ = NULL;
		yyerrok;
	}
	| stmt eol
	{ $$ = $1;}
;

line_func: line
	{ $$ = $1;}
	| funcdef
	{ $$ = $1;}
;

eol: ',' | ';' | T_NEWLINE | T_EOF
;

func_end: /* empty */ | T_ENDFUNCTION | T_EOF
;

stmt: exp
	{ $$ = $1;}
	| assign
	{ $$ = $1;}
	| condition
	{ $$ = $1;}
	| T_IF condition block elseif_list T_END
	{
		$$ = $4;
		$2->next = $3;
		$3->next = $4->child;
		$$->child = $2;
		$$->line = @$.first_line;
		$$->column = @$.first_column;
	}
	| T_IF condition ',' block elseif_list T_END
	{
		$$ = $5;
		$2->next = $4;
		$4->next = $5->child;
		$$->child = $2;
		$$->line = @$.first_line;
		$$->column = @$.first_column;
	}
	| T_IF condition block elseif_list T_ELSE block T_END
	{
		$$ = $4;
		$2->next = $3;
		if ($4->LastChild) {
			$3->next = $4->child;
			$4->LastChild->next = $6;
		} else
			$3->next = $6;
		$$->child = $2;
		$$->line = @$.first_line;
		$$->column = @$.first_column;
	}
	| T_IF condition ',' block elseif_list T_ELSE block T_END
	{
		$$ = $5;
		$2->next = $4;
		if ($5->LastChild) {
			$4->next = $5->child;
			$5->LastChild->next = $7;
		} else
			$4->next = $7;
		$$->child = $2;
		$$->line = @$.first_line;
		$$->column = @$.first_column;
	}
	| T_IF exp block elseif_list T_END
	{
		$$ = $4;
		$2->next = $3;
		$3->next = $4->child;
		$$->child = $2;
		$$->line = @$.first_line;
		$$->column = @$.first_column;
	}
	| T_IF exp ',' block elseif_list T_END
	{
		$$ = $5;
		$2->next = $4;
		$4->next = $5->child;
		$$->child = $2;
		$$->line = @$.first_line;
		$$->column = @$.first_column;
	}
	| T_IF exp block elseif_list T_ELSE block T_END
	{
		$$ = $4;
		$2->next = $3;
		if ($4->LastChild) {
			$3->next = $4->child;
			$4->LastChild->next = $6;
		} else
			$3->next = $6;
		$$->child = $2;
		$$->line = @$.first_line;
		$$->column = @$.first_column;
	}
	| T_IF exp ',' block elseif_list T_ELSE block T_END
	{
		$$ = $5;
		$2->next = $4;
		if ($5->LastChild) {
			$4->next = $5->child;
			$5->LastChild->next = $7;
		} else
			$4->next = $7;
		$$->child = $2;
		$$->line = @$.first_line;
		$$->column = @$.first_column;
	}
	| T_SWITCH exp case_list T_END
	{
		$$ = $3;
		$2->next = $3->child;
		$$->child = $2;
		$$->line = @$.first_line;
		$$->column = @$.first_column;
	}
	| T_SWITCH exp case_list T_OTHERWISE block T_END
	{
		$$ = $3;
		$2->next = $3->child;
		$3->LastChild->next = $5;
		$$->child = $2;
		$$->line = @$.first_line;
		$$->column = @$.first_column;
	}
	| T_WHILE condition block T_END
	{
		$$ = newAstNode(T_WHILE, @$);
		$2->next = $3;
		$$->child = $2;
	}
	| T_WHILE exp block T_END
	{
		$$ = newAstNode(T_WHILE, @$);
		$2->next = $3;
		$$->child = $2;
	}
	| T_WHILE condition ',' block T_END
	{
		$$ = newAstNode(T_WHILE, @$);
		$2->next = $4;
		$$->child = $2;
	}
	| T_WHILE exp ',' block T_END
	{
		$$ = newAstNode(T_WHILE, @$);
		$2->next = $4;
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
		$8->next = newAstNode(T_ID, @2);
		$8->next->str = $2;
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
	| T_FUNCTION '[' vector ']' '=' T_ID '(' id_list ')' block func_end
	{
		$$ = newAstNode(T_FUNCTION, @$);
		$$->str = $6;
		$$->child = $8;
		$8->next = $10;
		$10->next = $3;
	}
;

elseif_list: /* empty */
	{ $$ = newAstNode(T_IF, @$);}
	| elseif_list T_ELSEIF condition block
	{
		if ($1->child)
			$1->LastChild->next = $3;
		else
			$1->child = $3;
		$3->next = $4;
		$1->LastChild = $4;
		$$ = $1;
	}
;

case_list: /* empty */
	{ $$ = newAstNode(T_SWITCH, @$);}
	| T_NEWLINE
	{ $$ = newAstNode(T_SWITCH, @$);}
	| case_list T_CASE exp T_NEWLINE block
	{
		if ($1->child)
			$1->LastChild->next = $3;
		else
			$1->child = $3;
		$3->next = $5;
		$1->LastChild = $5;
		$$ = $1;
	}
	| case_list T_CASE '{' arg_list '}' block
	{
		if ($1->child)
			$1->LastChild->next = $4;
		else
			$1->child = $4;
		$4->next = $6;
		$1->LastChild = $6;
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
		$$->column = @$.first_column;
	}
	| '!' condition %prec T_LOGIC_NOT
	{
		$$ = newAstNode(T_LOGIC_NOT, @$);
		$$->child = $2;
	}
	| condition T_LOGIC_AND condition
	{ $$ = makeBinaryOpNode(T_LOGIC_AND, $1, $3, @$);}
	| exp T_LOGIC_AND exp
	{ $$ = makeBinaryOpNode(T_LOGIC_AND, $1, $3, @$);}
	| condition T_LOGIC_OR condition
	{ $$ = makeBinaryOpNode(T_LOGIC_OR, $1, $3, @$);}
	| exp T_LOGIC_OR exp
	{ $$ = makeBinaryOpNode(T_LOGIC_OR, $1, $3, @$);}
;

id_list: /* empty */
	{
		$$ = newAstNode(NODE_IDLIST, @$);
	}
	| T_ID
	{
		$$ = newAstNode(NODE_IDLIST, @$);
		$$->child = $$->LastChild = newAstNode(T_ID, @$);
		$$->LastChild->str = $1;
	}
	| T_ID '{' '}'
	{
		$$ = newAstNode(NODE_IDLIST, @$);
		$$->child = $$->LastChild = newAstNode(NODE_INITCELL, @$);
		$$->LastChild->str = $1;
	}
	| id_list ',' T_ID
	{
		$1->LastChild = $1->LastChild->next = newAstNode(T_ID, @3);
		$$ = $1;
		$$->LastChild->str = $3;
	}
	| id_list ',' T_ID '{' '}'
	{
		$1->LastChild = $1->LastChild->next = newAstNode(NODE_INITCELL, @3);
		$$ = $1;
		$$->LastChild->str = $3;
	}
;

arg: exp_range
	{ $$ = $1; }
	| initcell
	{ $$ = $1; }
;

arg_list: arg
	{
		$$ = newAstNode(NODE_ARGS, @$);
		$$->child = $$->LastChild = $1;
	}
	| arg_list ',' arg
	{
		$1->LastChild = $1->LastChild->next = $3;
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
		$$->child = $$->LastChild = $1;
	}
	| matrix ';' vector
	{
		$1->LastChild = $1->LastChild->next = $3;
		$$ = $1;
	}
;

vector: exp_range
	{
		$$ = newAstNode(NODE_VECTOR, @$);
		$$->child = $$->LastChild = $1;
	}
	| vector exp_range
	{
		$1->LastChild = $1->LastChild->next = $2;
		$$ = $1;
	}
	| vector ',' exp_range
	{
		$1->LastChild = $1->LastChild->next = $3;
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
		$$->LastChild = $5->next = $3;
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
	{ /* Reverse engineered from the tree generated in x = x @ x @ (value) */
	  /* Should be decluttered up by someone else..... 7/20/2016 bjk*/
		$$ = newAstNode('=', @$);
		$$->str = $1; 
		$$->child = makeCompoundLevelOpNode($1, $3, @1, @3);
	}
	| T_ID '{' exp '}' '=' exp_range
	{
		$$ = newAstNode('=', @$);
		$$->str = $1;
		$$->child = $6;
		$6->next = $3;
	}
	| T_ID '(' exp '~' exp ')' '=' exp
	{
		$$ = newAstNode(NODE_IXASSIGN, @$);
		$$->str = $1;
		$$->child = $8;
		$8->next = $3;
		$3->next = $5;
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
	{
		$$ = newAstNode(NODE_IXASSIGN, @$);
		$$->str = $1;
		$$->child = $6;
		$6->next = $3;
	}
	| T_ID '{' exp '}' '(' exp ')' '=' exp_range
	{
		$$ = newAstNode(NODE_IXASSIGN, @$);
		$$->str = $1;
		$$->child = $9;
		$9->next = $6;
		$6->next = $3;
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
		$6->next = $3;
	}
	| T_ID '(' arg_list ')' '=' assign
	{
		$$ = newAstNode(NODE_IXASSIGN, @$);
		$$->str = $1;
		$$->child = $6;
		$6->next = $3;
	}
	| T_ID '{' exp '}' '(' exp ')' '=' assign
	{
		$$ = newAstNode(NODE_IXASSIGN, @$);
		$$->str = $1;
		$$->child = $9;
		$9->next = $6;
		$6->next = $3;
	}
	| T_ID '=' initcell
	{
		$$ = $3;
		$$->str = $1;
		$$->line = @$.first_line;
		$$->column = @$.first_column;
	}
	| T_ID '{' '}' '=' T_ID '(' arg_list ')'
	{
		$$ = newAstNode(NODE_CALL, @$);
		$$->str = $5;
		$$->child = $7;
		$7->next = newAstNode(NODE_INITCELL, @1);
		$7->next->str = $1;
	}
	| '[' vector ']' '=' T_ID '(' arg_list ')'
	{
		$$ = newAstNode(NODE_CALL, @$);
		$$->str = $5;
		$$->child = $7;
		$7->next = $2;
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
	| T_DUR
	{
		$$ = newAstNode(T_DUR, @$);
		$$->str = $1;
	}
	| T_LENGTH
	{
		$$ = newAstNode(T_LENGTH, @$);
		$$->str = $1;
	}
	| T_ID
	{
		$$ = newAstNode(T_ID, @$);
		$$->str = $1;
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
		$3->next = $6;
	}
	| T_ID '{' '}'
	{
		$$ = newAstNode(NODE_INITCELL, @$);
		$$->str = $1;
	}
	| T_ID '(' exp')'
	{ 
		$$ = newAstNode(NODE_INITCELL, @$);
 		$$->str = $1;
		$$->child = $3;
		
	}
	| T_ID '(' ')'
	{ // I don't know what this is doing.... bjk 3/28/2017 
		$$ = newAstNode(NODE_CALL, @$);
 		$$->str = $1;
	}
	| T_ID '(' arg_list ')'
	{
		$$ = $3;
		$$->type = NODE_INITCELL;
 		$$->str = $1;
		$$->line = @$.first_line;
		$$->column = @$.first_column;
	}
	| T_ID '(' condition ')'
	{
		$$ = newAstNode(NODE_CALL, @$);
 		$$->str = $1;
		$$->child = $3;
		$$->LastChild = $3; // leaving a mark for conditional indexing 3/28/2017 bjk
		$$->line = @$.first_line;
		$$->column = @$.first_column;
	}
	| '#' T_ID '(' ')'
	{
		$$ = newAstNode(NODE_CALL, @$);
 		$$->str = malloc(strlen($2)+2);
 		$$->str[0] = '#';
 		strcpy($$->str+1, $2);
 		free($2);
	}
	| '#' T_ID '(' arg_list ')'
	{
		$$ = $4;
		$$->type = NODE_CALL;
 		$$->str = malloc(strlen($2)+2);
 		$$->str[0] = '#';
 		strcpy($$->str+1, $2);
 		free($2);
		$$->line = @$.first_line;
		$$->column = @$.first_column;
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
		$$->column = @$.first_column;
	}
	| '(' exp_range ')'
	{
		$$ = $2;
		$$->line = @$.first_line;
		$$->column = @$.first_column;
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
		$$->LastChild = $5;
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
		$$->column = @$.first_column;
	}
	| '[' vector ']'
	{
		$$ = $2;
		$$->line = @$.first_line;
		$$->column = @$.first_column;
	}
;

initcell: '{' arg_list '}'
	{
		$$ = $2;
		$$->type = NODE_INITCELL;
		$$->line = @$.first_line;
		$$->column = @$.first_column;
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
	nn->LastChild = first->next = second;
	return nn;
}

AstNode *makeBinaryOpNode(int op, AstNode *first, AstNode *second, YYLTYPE loc)
{
	AstNode *nn;

	nn = newAstNode(op, loc);
	nn->child = first;
	nn->LastChild = first->next = second;
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
	nn->LastChild = nn->child->next = second;
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
	nn->LastChild = second;
	
	nn->child = newAstNode(T_ID, loc1);
	tempstrpt2 = (char*)malloc(strlen(first)+1); /* This will be cleaned up during yydeleteAstNode().*/
	strcpy_s(tempstrpt2, strlen(first)+1, first);
	nn->child->str = tempstrpt2;
	nn->LastChild = nn->child->next = second;
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
	nn->child->LastChild = nn->child->child->next = newAstNode(T_ID, loc1);
	nn->child->LastChild->str = tempstrpt2;
	nn->LastChild = nn->child->next = second;
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
  nn->column = loc.first_column;
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
