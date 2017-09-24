
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "psycon.y"

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


/* Line 189 of yacc.c  */
#line 88 "psycon.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_EOF = 0,
     T_UNKNOWN = 258,
     T_NEWLINE = 259,
     T_IF = 260,
     T_ELSE = 261,
     T_ELSEIF = 262,
     T_END = 263,
     T_WHILE = 264,
     T_FOR = 265,
     T_BREAK = 266,
     T_CONTINUE = 267,
     T_SWITCH = 268,
     T_CASE = 269,
     T_OTHERWISE = 270,
     T_FUNCTION = 271,
     T_ENDFUNCTION = 272,
     T_RETURN = 273,
     T_SIGMA = 274,
     T_OP_SHIFT = 275,
     T_OP_SHIFT2 = 276,
     T_OP_CONCAT = 277,
     T_COMP_EQ = 278,
     T_COMP_NE = 279,
     T_COMP_LE = 280,
     T_COMP_GE = 281,
     T_LOGIC_AND = 282,
     T_LOGIC_OR = 283,
     T_REPLICA = 284,
     T_NUMBER = 285,
     T_STRING = 286,
     T_ID = 287,
     T_HOOKCMD = 288,
     T_ENDPOINT = 289,
     T_NEGATIVE = 290,
     T_POSITIVE = 291,
     T_LOGIC_NOT = 292
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 22 "psycon.y"

	double dval;
	char *str;
	AstNode *pnode;



/* Line 214 of yacc.c  */
#line 170 "psycon.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */

/* Line 264 of yacc.c  */
#line 101 "psycon.y"

AstNode *newAstNode(int type, YYLTYPE loc);
AstNode *makeFunctionCall(char *name, AstNode *first, AstNode *second, YYLTYPE loc);
AstNode *makeBinaryOpNode(int op, AstNode *first, AstNode *second, YYLTYPE loc);
AstNode *makeCompoundLevelOpNode(char *first, AstNode *second, YYLTYPE loc1, YYLTYPE loc2);
AstNode *makeCompoundOpNode(int op, char *first, AstNode *second, YYLTYPE loc1, YYLTYPE loc2);
AstNode *makeCompoundOpNodeFunctionCall(int op, char *first, AstNode *second, YYLTYPE loc1, YYLTYPE loc2);
AstNode *Restring(char *oper, char* dummy1, AstNode *dumm2, AstNode *dummy3, AstNode *dummy4, YYLTYPE loc);
void print_token_value(FILE *file, int type, YYSTYPE value);


/* Line 264 of yacc.c  */
#line 207 "psycon.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  81
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1993

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  162
/* YYNRULES -- Number of states.  */
#define YYNSTATES  339

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    68,    41,    42,     2,     2,
      52,    53,    44,    40,    50,    39,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    51,
      36,    35,    37,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,    69,    57,    67,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      47,    48,    49,    59,    60,    61,    62,    63,    64,    65,
      66
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    16,    18,
      21,    24,    27,    29,    31,    33,    35,    37,    39,    40,
      42,    44,    46,    49,    51,    54,    55,    60,    64,    66,
      68,    70,    72,    74,    80,    85,    92,    97,   104,   112,
     114,   116,   118,   126,   136,   148,   160,   161,   163,   169,
     176,   180,   184,   188,   192,   196,   200,   204,   208,   212,
     216,   220,   224,   228,   232,   236,   240,   244,   248,   252,
     255,   258,   262,   266,   270,   274,   278,   282,   286,   290,
     291,   293,   297,   301,   307,   309,   311,   313,   317,   318,
     320,   324,   326,   329,   333,   337,   343,   345,   347,   351,
     357,   361,   365,   369,   373,   377,   381,   385,   389,   393,
     400,   409,   418,   427,   436,   445,   454,   461,   468,   477,
     489,   499,   509,   513,   520,   527,   537,   541,   543,   545,
     547,   549,   551,   556,   564,   572,   575,   579,   583,   588,
     593,   598,   604,   611,   614,   617,   621,   630,   634,   638,
     642,   646,   650,   654,   658,   662,   668,   672,   676,   680,
     684,   688,   690
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      71,     0,    -1,    -1,    72,    -1,    75,    -1,    72,    75,
      -1,    74,    -1,    73,    74,    -1,     4,    -1,     1,     4,
      -1,    81,    76,    -1,    81,    77,    -1,    74,    -1,    82,
      -1,    50,    -1,     4,    -1,     0,    -1,    51,    -1,    -1,
      17,    -1,     0,    -1,    84,    -1,    84,    76,    -1,    93,
      -1,    93,    76,    -1,    -1,     7,    79,    73,    80,    -1,
      80,     6,    73,    -1,    93,    -1,    92,    -1,    84,    -1,
      94,    -1,    33,    -1,     5,    79,    73,    80,     8,    -1,
      13,    93,    83,     8,    -1,    13,    93,    83,    15,    73,
       8,    -1,     9,    79,    73,     8,    -1,    10,    32,    35,
      91,    73,     8,    -1,    10,    32,    35,    91,    50,    73,
       8,    -1,    18,    -1,    11,    -1,    12,    -1,    16,    32,
      52,    85,    53,    73,    78,    -1,    16,    32,    35,    32,
      52,    85,    53,    73,    78,    -1,    16,    54,    89,    55,
      35,    32,    52,    85,    53,    73,    78,    -1,    16,    32,
      56,    57,    35,    32,    52,    85,    53,    73,    78,    -1,
      -1,     4,    -1,    83,    14,    93,     4,    73,    -1,    83,
      14,    56,    87,    57,    73,    -1,    93,    36,    93,    -1,
      90,    36,    93,    -1,    93,    36,    90,    -1,    93,    37,
      93,    -1,    90,    37,    93,    -1,    93,    37,    90,    -1,
      93,    23,    93,    -1,    90,    23,    93,    -1,    93,    23,
      90,    -1,    93,    24,    93,    -1,    90,    24,    93,    -1,
      93,    24,    90,    -1,    93,    26,    93,    -1,    90,    26,
      93,    -1,    93,    26,    90,    -1,    93,    25,    93,    -1,
      90,    25,    93,    -1,    93,    25,    90,    -1,    52,    84,
      53,    -1,    58,    84,    -1,    58,    93,    -1,    84,    27,
      84,    -1,    93,    27,    93,    -1,    84,    27,    93,    -1,
      93,    27,    84,    -1,    84,    28,    84,    -1,    93,    28,
      93,    -1,    84,    28,    93,    -1,    93,    28,    84,    -1,
      -1,    32,    -1,    32,    56,    57,    -1,    85,    50,    32,
      -1,    85,    50,    32,    56,    57,    -1,    91,    -1,    94,
      -1,    86,    -1,    87,    50,    86,    -1,    -1,    89,    -1,
      88,    51,    89,    -1,    91,    -1,    89,    91,    -1,    89,
      50,    91,    -1,    93,    38,    93,    -1,    93,    38,    93,
      38,    93,    -1,    93,    -1,    90,    -1,    32,    35,    91,
      -1,    54,    89,    55,    35,    91,    -1,    32,    35,    84,
      -1,    32,    59,    91,    -1,    32,    60,    91,    -1,    32,
      61,    91,    -1,    32,    62,    91,    -1,    32,    63,    91,
      -1,    32,    64,    91,    -1,    32,    65,    91,    -1,    32,
      66,    91,    -1,    32,    56,    93,    57,    35,    91,    -1,
      32,    52,    93,    67,    93,    53,    59,    91,    -1,    32,
      52,    93,    67,    93,    53,    60,    91,    -1,    32,    52,
      93,    67,    93,    53,    61,    91,    -1,    32,    52,    93,
      67,    93,    53,    62,    91,    -1,    32,    52,    93,    67,
      93,    53,    64,    91,    -1,    32,    52,    93,    67,    93,
      53,    65,    91,    -1,    32,    52,    87,    53,    35,    91,
      -1,    32,    52,    84,    53,    35,    91,    -1,    32,    52,
      93,    67,    93,    53,    35,    93,    -1,    32,    56,    93,
      57,    52,    93,    67,    93,    53,    35,    93,    -1,    32,
      56,    93,    57,    52,    93,    53,    35,    91,    -1,    32,
      56,    93,    57,    52,    91,    53,    35,    91,    -1,    32,
      35,    92,    -1,    32,    56,    93,    57,    35,    92,    -1,
      32,    52,    87,    53,    35,    92,    -1,    32,    56,    93,
      57,    52,    93,    53,    35,    92,    -1,    32,    35,    94,
      -1,    30,    -1,    31,    -1,    34,    -1,    94,    -1,    32,
      -1,    32,    56,    93,    57,    -1,    32,    56,    93,    57,
      52,    93,    53,    -1,    32,    56,    93,    57,    52,    91,
      53,    -1,    56,    57,    -1,    32,    56,    57,    -1,    32,
      52,    53,    -1,    32,    52,    87,    53,    -1,    29,    52,
      87,    53,    -1,    32,    52,    84,    53,    -1,    68,    32,
      52,    87,    53,    -1,    32,    52,    93,    67,    93,    53,
      -1,    39,    93,    -1,    40,    93,    -1,    52,    91,    53,
      -1,    19,    52,    32,    35,    91,    50,    93,    53,    -1,
      93,    40,    93,    -1,    93,    39,    93,    -1,    93,    44,
      93,    -1,    93,    45,    93,    -1,    93,    46,    93,    -1,
      93,    42,    93,    -1,    93,    41,    93,    -1,    93,    43,
      93,    -1,    93,    43,    93,    69,    93,    -1,    93,    20,
      93,    -1,    93,    21,    93,    -1,    93,    22,    93,    -1,
      54,    88,    55,    -1,    54,    89,    55,    -1,    29,    -1,
      56,    87,    57,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   115,   119,   121,   147,   154,   181,   183,
     188,   190,   194,   196,   200,   200,   200,   203,   206,   206,
     206,   209,   211,   213,   215,   220,   223,   230,   245,   247,
     249,   251,   253,   260,   274,   282,   291,   297,   305,   313,
     317,   319,   323,   330,   340,   349,   361,   362,   364,   374,
     386,   388,   390,   392,   394,   396,   398,   400,   402,   404,
     406,   408,   410,   412,   414,   416,   418,   420,   422,   428,
     433,   438,   440,   442,   444,   446,   448,   450,   452,   457,
     460,   466,   472,   478,   486,   488,   492,   497,   505,   508,
     513,   520,   525,   530,   537,   541,   548,   550,   554,   560,
     566,   572,   578,   584,   590,   596,   602,   608,   614,   620,
     627,   631,   635,   639,   643,   647,   651,   658,   665,   674,
     685,   693,   701,   707,   714,   721,   729,   738,   743,   748,
     753,   757,   763,   769,   776,   783,   787,   792,   797,   805,
     812,   821,   832,   840,   845,   851,   857,   865,   867,   869,
     871,   873,   875,   877,   879,   881,   889,   891,   893,   895,
     901,   907,   914
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of text\"", "error", "$undefined", "T_UNKNOWN",
  "\"end of line\"", "\"if\"", "\"else\"", "\"elseif\"", "\"end\"",
  "\"while\"", "\"for\"", "\"break\"", "\"continue\"", "\"switch\"",
  "\"case\"", "\"otherwise\"", "\"function\"", "\"endfunction\"",
  "\"return\"", "\"sigma\"", "\">>\"", "\"<<\"", "\"++\"", "\"==\"",
  "\"!=\"", "\"<=\"", "\">=\"", "\"&&\"", "\"||\"", "\"..\"", "\"number\"",
  "\"string\"", "\"identifier\"", "\"HookCommand\"", "T_ENDPOINT", "'='",
  "'<'", "'>'", "':'", "'-'", "'+'", "'$'", "'%'", "'@'", "'*'", "'/'",
  "'^'", "T_NEGATIVE", "T_POSITIVE", "T_LOGIC_NOT", "','", "';'", "'('",
  "')'", "'['", "']'", "'{'", "'}'", "'!'", "\"+=\"", "\"-=\"", "\"*=\"",
  "\"/=\"", "\"^=\"", "\"@=\"", "\"@@=\"", "\"++=\"", "'~'", "'#'", "'|'",
  "$accept", "input", "block_func", "block", "line", "line_func", "eol",
  "eol2", "func_end", "conditional", "elseif_list", "stmt", "funcdef",
  "case_list", "condition", "id_list", "arg", "arg_list", "matrix",
  "vector", "range", "exp_range", "assign", "exp", "initcell", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    61,    60,    62,    58,    45,
      43,    36,    37,    64,    42,    47,    94,   290,   291,   292,
      44,    59,    40,    41,    91,    93,   123,   125,    33,   293,
     294,   295,   296,   297,   298,   299,   300,   126,    35,   124
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    71,    72,    72,    73,    73,    74,    74,
      74,    74,    75,    75,    76,    76,    76,    77,    78,    78,
      78,    79,    79,    79,    79,    80,    80,    80,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    82,    82,    82,    82,    83,    83,    83,    83,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    85,
      85,    85,    85,    85,    86,    86,    87,    87,    88,    88,
      88,    89,    89,    89,    90,    90,    91,    91,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     2,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     2,     1,     2,     0,     4,     3,     1,     1,
       1,     1,     1,     5,     4,     6,     4,     6,     7,     1,
       1,     1,     7,     9,    11,    11,     0,     1,     5,     6,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     0,
       1,     3,     3,     5,     1,     1,     1,     3,     0,     1,
       3,     1,     2,     3,     3,     5,     1,     1,     3,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     6,
       8,     8,     8,     8,     8,     8,     6,     6,     8,    11,
       9,     9,     3,     6,     6,     9,     3,     1,     1,     1,
       1,     1,     4,     7,     7,     2,     3,     3,     4,     4,
       4,     5,     6,     2,     2,     3,     8,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     3,     3,     3,     3,
       3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     8,     0,     0,     0,    40,    41,     0,     0,
      39,     0,   161,   127,   128,   131,    32,   129,     0,     0,
       0,    88,     0,     0,     0,     0,     0,    12,     4,     0,
      13,    30,     0,    29,    28,   130,     9,   131,    88,     0,
      21,    23,   130,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,     0,    97,     0,    96,     0,    89,
      97,    91,    96,   135,    86,     0,    84,   130,    69,    70,
       0,     1,     5,    16,    15,    14,    17,    10,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     6,    22,    24,     0,     0,    47,     0,     0,    79,
       0,     0,     0,     0,   100,    98,   122,   130,   137,     0,
       0,    96,   136,     0,   101,   102,   103,   104,   105,   106,
     107,   108,    68,   145,     0,   159,     0,   160,    92,     0,
     162,     0,    71,    73,    75,    77,    57,    60,    66,    63,
      51,    54,   156,   157,   158,    58,    56,    61,    59,    67,
      65,    64,    62,    74,    72,    78,    76,    52,    50,    55,
      53,    94,   148,   147,   153,   152,   154,   149,   150,   151,
       0,     0,    96,     0,   160,     0,     7,     0,    36,     0,
      34,     0,     0,     0,    80,     0,     0,     0,     0,   139,
     140,   138,     0,   132,    90,    93,     0,    87,     0,     0,
       0,   140,   138,     0,   132,     0,     0,    33,     0,     0,
       0,     0,     0,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   141,    95,   155,     0,
       0,     0,     0,     0,    37,     0,     0,    35,     0,    81,
      82,     0,     0,     0,     0,   117,   116,   124,   142,   109,
     123,     0,     0,   142,     0,     0,    26,    38,     0,     0,
       0,     0,    20,    19,    42,    79,    79,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   133,     0,   134,   133,
       0,     0,    83,     0,     0,   146,   118,   110,   111,   112,
     113,   114,   115,     0,     0,     0,    43,     0,     0,   121,
     120,   125,     0,     0,     0,     0,    45,    44,   119
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,   120,   121,    28,    87,    88,   294,    39,
     207,    29,    30,   127,    31,   215,    74,    75,    68,    69,
      70,    76,    33,    72,    42
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -290
static const yytype_int16 yypact[] =
{
     732,    -3,  -290,  1571,  1571,    18,  -290,  -290,  1721,    -5,
    -290,   -43,   -17,  -290,  -290,  1146,  -290,  -290,  1721,  1721,
    1571,  1721,  1601,  1571,    38,    64,   792,  -290,  -290,     7,
    -290,   131,   108,  -290,  1866,    17,  -290,   -23,  1721,  1464,
      32,  1513,  -290,  1464,    46,  1721,   148,    27,  1721,    87,
    1721,  1631,   109,  1661,  1721,  1721,  1721,  1721,  1721,  1721,
    1721,  1721,  -290,  -290,   -13,   108,    72,  1866,    25,   438,
    -290,  -290,  1224,  -290,  -290,   -16,  -290,    16,  -290,  1947,
      90,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  -290,  1571,
    1571,  1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,  1721,
    1721,  1721,  1721,  1721,  1571,  1571,  1721,  1721,  1721,  1721,
    1721,  1721,  1721,  1721,  1721,  1721,  1721,   109,  1661,   533,
     917,  -290,  -290,  -290,  1161,  1721,  -290,    70,   114,   119,
     100,  1541,    94,    73,   131,  -290,  -290,    24,  -290,     3,
      77,  1802,  -290,   409,  -290,  -290,  -290,  -290,  -290,  -290,
    -290,  -290,  -290,  -290,  1721,  -290,  1721,   129,  -290,  1721,
    -290,  1721,  -290,  1920,   139,  1893,  1345,  1345,  1345,  1345,
    1345,  1345,    91,    91,   496,  -290,  1224,  -290,  1224,  -290,
    1224,  -290,  1224,  -290,  1920,   139,  1893,  -290,  1224,  -290,
    1224,  1285,   496,   496,    91,    91,     2,   126,   126,   126,
      10,    97,  1834,   667,  -290,  1571,  -290,    80,  -290,  1221,
    -290,  1751,  1464,   132,   141,   103,   147,   173,  1721,  -290,
     184,   185,  1721,   -10,  1691,  -290,  1721,  -290,   123,  1721,
    1721,  -290,  -290,  1721,   134,  1464,  1464,  -290,  1464,  1282,
    1601,   357,  1343,   119,   153,   189,  1464,   192,   193,   178,
    1721,  1781,   919,  1781,  1721,  -290,  -290,  1345,  1345,   980,
    1721,   917,  1100,  1404,  -290,    15,  1464,  -290,   130,  -290,
     181,   646,   179,   180,  1721,  -290,  -290,  -290,   188,  -290,
    -290,   190,   570,  -290,   191,   796,   228,  -290,   852,   978,
    1464,   194,  -290,  -290,  -290,   119,   119,  1041,  1721,  1721,
    1721,  1721,  1721,  1721,  1721,   210,   222,  1721,  -290,  -290,
    1039,   646,  -290,   146,   154,  -290,  1345,  -290,  -290,  -290,
    -290,  -290,  -290,  1721,  1781,  1102,  -290,  1464,  1464,  -290,
    -290,  -290,   223,   646,   646,  1721,  -290,  -290,  1345
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -290,  -290,  -290,   117,    61,   233,   176,  -290,  -289,     1,
       6,  -290,  -290,  -290,   151,  -241,   110,   -40,  -290,   -32,
     175,   475,   -38,     0,   315
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -163
static const yytype_int16 yytable[] =
{
      34,    36,   268,    41,    41,    43,   119,    83,    46,    49,
     133,    84,   140,   136,    89,    90,   131,   -31,    62,    63,
      67,   -31,   326,    79,  -126,   253,    34,    47,  -126,   117,
      89,    90,    83,   118,   159,    50,    84,    89,    90,    34,
     152,   160,   254,    34,   336,   337,   114,   115,   116,    48,
      44,    67,   141,   143,   313,   314,   220,    85,    86,    89,
      90,    27,   128,   231,    81,   159,   -85,   -31,   -31,   -85,
      80,   230,   288,   -85,  -126,  -126,   154,   201,   210,   129,
     155,   125,    85,   130,   211,   212,   236,    27,   237,   163,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     176,   178,   180,   182,   184,   186,   188,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   202,   203,   132,
      34,   228,   224,   159,    34,   153,   219,   159,    11,   218,
     221,    91,    92,    93,    94,   114,   115,   116,    12,    13,
      14,    37,   161,    17,    95,    96,   213,   159,    18,    19,
     232,   214,   126,   245,    40,    40,   246,   216,    89,    90,
     124,    20,   138,    38,   226,    22,    89,    23,    97,    98,
      99,    64,   116,   159,    78,    32,   256,    24,    32,    32,
     245,   206,   247,   290,   243,   206,   260,   109,   110,   111,
     112,   113,   114,   115,   116,    65,   245,   244,    32,   327,
     265,    32,   134,   139,   245,    41,   235,   328,   248,    34,
     269,   241,    34,   277,    32,   280,   122,   123,    32,   250,
     251,   270,   252,   298,   272,   273,    65,    65,   274,   257,
     258,   295,   296,   259,   236,    34,    34,   291,    34,    34,
     162,   164,    34,   305,   308,   323,    34,   299,   300,   301,
     302,   312,   303,   304,   282,   183,   185,   324,   335,    82,
     285,    34,    34,    34,    32,    32,    34,   286,   200,   227,
       0,    34,     0,     0,   297,   175,   177,   179,   181,    32,
      32,   187,   189,     0,     0,     0,   331,     0,    34,    34,
      34,     0,    65,     0,     0,    32,     0,     0,   316,    32,
     206,     0,     0,   206,     0,     0,     0,   325,     0,     0,
      34,    34,     0,     0,     0,    35,     0,     0,     0,     0,
       0,     0,   206,   206,   206,     0,   239,    34,    34,   242,
       0,     0,   206,    34,    34,   338,     0,    77,     0,     0,
       0,    35,     0,     0,     0,     0,     0,     0,     0,     0,
     206,     0,   261,   262,    35,   263,    40,     0,    35,     0,
       0,   266,     0,   271,     0,    77,   137,    77,     0,     0,
       0,   206,   206,     0,     0,     0,     0,    97,    98,    99,
      32,     0,     0,   289,    32,     0,     0,    32,     0,     0,
       0,     0,     0,     0,   206,   206,   109,   110,   111,   112,
     113,   114,   115,   116,     0,   310,     0,   311,     0,     0,
      32,    32,     0,    32,    32,     0,     0,    32,     0,     0,
       0,    32,     0,     0,     0,     0,     0,     0,     0,    97,
      98,    99,    77,     0,     0,    35,    32,    32,    32,    35,
       0,    32,     0,     0,   333,   334,    32,     0,   109,   110,
     111,   112,   113,   114,   115,   116,     0,    11,     0,     0,
       0,     0,     0,    32,    32,    32,   223,    12,    13,    14,
      37,     0,    17,     0,    77,     0,    77,    18,    19,     0,
       0,     0,     0,     0,     0,    32,    32,     0,   156,     0,
      45,     0,    38,   157,    22,    66,    71,     0,     0,     0,
       0,     0,    32,    32,     0,     0,    24,     0,    32,    32,
       0,     0,     0,    71,     0,     0,    97,    98,     0,     0,
      66,     0,     0,    71,    35,     0,   135,    35,     0,   144,
     145,   146,   147,   148,   149,   150,   151,   111,   112,   113,
     114,   115,   116,     0,   158,     0,     0,     0,     0,     0,
      35,    35,    11,    35,    35,    77,     0,    35,     0,     0,
       0,    35,    12,    13,    14,    37,     0,    17,     0,     0,
       0,     0,    18,    19,     0,     0,    35,    35,    35,     0,
       0,    35,     0,   156,     0,    45,    35,    38,   204,    22,
      97,    98,    99,     0,   158,     0,     0,     0,     0,     0,
     209,    24,     0,    35,    35,    35,   158,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,     0,     0,
       0,     0,     0,   306,     0,    35,    35,     0,     0,    71,
       0,   225,     0,     0,     0,     0,     0,   307,     0,     0,
       0,     0,    35,    35,     0,     0,   292,     1,    35,    35,
       2,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       0,     0,   -18,   293,    10,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    13,    14,    15,    16,
      17,     0,     0,     0,     0,    18,    19,    97,    98,    99,
       0,     0,     0,   249,     0,     0,     0,     0,    20,   158,
      21,   255,    22,     0,    23,     0,   109,   110,   111,   112,
     113,   114,   115,   116,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   234,   275,   276,     0,   279,   281,
       0,     0,    -2,     1,     0,   284,     2,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     0,     0,     9,     0,
      10,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    13,    14,    15,    16,    17,     0,     0,     0,
       0,    18,    19,     0,   317,   318,   319,   320,   321,   322,
       0,     0,     0,     0,    20,     0,    21,     0,    22,     0,
      23,     0,    -3,     1,     0,     0,     2,     3,   329,   330,
      24,     4,     5,     6,     7,     8,     0,     0,     9,     0,
      10,    11,     0,     0,     0,     0,    97,    98,    99,     0,
       0,    12,    13,    14,    15,    16,    17,     0,     0,     0,
       0,    18,    19,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,    20,     0,    21,     0,    22,   309,
      23,     0,     0,     1,     0,     0,     2,     3,     0,     0,
      24,     4,     5,     6,     7,     8,     0,     0,     0,     0,
      10,    11,  -162,  -162,  -162,     0,     0,     0,     0,     0,
       0,    12,    13,    14,    15,    16,    17,     0,     0,     0,
       0,    18,    19,  -162,  -162,  -162,  -162,  -162,  -162,     0,
       0,     0,     0,     0,    20,     0,    21,     0,    22,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     1,     0,
      24,     2,     3,   -25,   205,   -25,     4,     5,     6,     7,
       8,     0,     0,     0,     0,    10,    11,     0,     0,    97,
      98,    99,     0,     0,     0,     0,    12,    13,    14,    15,
      16,    17,     0,     0,     0,     0,    18,    19,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,    20,
       0,    21,   278,    22,     0,    23,     0,     0,     0,     1,
       0,     0,     2,     3,     0,    24,   -48,     4,     5,     6,
       7,     8,   -48,   -48,     0,     0,    10,    11,     0,     0,
      97,    98,    99,     0,     0,     0,     0,    12,    13,    14,
      15,    16,    17,     0,     0,     0,     0,    18,    19,   109,
     110,   111,   112,   113,   114,   115,   116,     0,     0,     0,
      20,     0,    21,   283,    22,     0,    23,     0,     0,     0,
       1,     0,     0,     2,     3,     0,    24,   -49,     4,     5,
       6,     7,     8,   -49,   -49,     0,     0,    10,    11,     0,
       0,    97,    98,    99,     0,     0,     0,     0,    12,    13,
      14,    15,    16,    17,     0,     0,     0,     0,    18,    19,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
       0,    20,     0,    21,   315,    22,     0,    23,     0,     0,
       0,     1,     0,     0,     2,     3,   -27,    24,   -27,     4,
       5,     6,     7,     8,     0,     0,     0,     0,    10,    11,
       0,     0,    97,    98,    99,     0,     0,     0,     0,    12,
      13,    14,    15,    16,    17,     0,     0,     0,     0,    18,
      19,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,     0,    20,     0,    21,   332,    22,     0,    23,     0,
       0,     0,     1,     0,     0,     2,     3,     0,    24,   208,
       4,     5,     6,     7,     8,     0,     0,     0,     0,    10,
      11,    51,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    13,    14,    15,    16,    17,     0,     0,    52,     0,
      18,    19,    53,     0,     0,    54,    55,    56,    57,    58,
      59,    60,    61,    20,     0,    21,     0,    22,     0,    23,
       0,     0,     1,     0,     0,     2,     3,     0,     0,    24,
       4,     5,     6,     7,     8,     0,     0,     0,     0,    10,
      11,     0,     0,     0,    97,    98,    99,     0,     0,     0,
      12,    13,    14,    15,    16,    17,     0,     0,     0,     0,
      18,    19,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   238,     0,    20,     0,    21,     0,    22,     0,    23,
       0,     0,     0,     1,     0,     0,     2,     3,     0,    24,
     264,     4,     5,     6,     7,     8,     0,     0,     0,     0,
      10,    11,     0,     0,     0,    97,    98,    99,     0,     0,
       0,    12,    13,    14,    15,    16,    17,     0,     0,     0,
       0,    18,    19,   229,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,    20,     0,    21,     0,    22,     0,
      23,     0,     0,     0,     1,     0,     0,     2,     3,     0,
      24,   267,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,    97,    98,    99,     0,     0,
       0,     0,    12,    13,    14,    15,    16,    17,     0,     0,
       0,     0,    18,    19,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,     0,    20,     0,    21,     0,    22,
       0,    23,     0,     0,     0,     1,     0,     0,     2,     3,
       0,    24,   287,     4,     5,     6,     7,     8,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,    13,    14,    15,    16,    17,     0,
       0,     0,     0,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,     0,    21,     0,
      22,     0,    23,     0,     0,     1,     0,     0,     2,     3,
       0,     0,    24,     4,     5,     6,     7,     8,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,    13,    14,    15,    16,    17,     0,
       0,     0,     0,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,    83,     0,     0,    20,    84,    21,     0,
      22,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      11,     0,     0,    85,     0,     0,     0,     0,     0,     0,
      12,    13,    14,    37,     0,    17,     0,     0,     0,     0,
      18,    19,     0,     0,     0,     0,     0,     0,     0,     0,
      11,   156,     0,    45,     0,    38,   217,    22,     0,     0,
      12,    13,    14,    37,     0,    17,     0,     0,     0,    24,
      18,    19,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,    20,     0,    38,     0,    22,     0,    23,
      12,    13,    14,    37,     0,    17,     0,     0,     0,    24,
      18,    19,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,    45,     0,    38,     0,    22,    73,     0,
      12,    13,    14,    15,     0,    17,     0,     0,     0,    24,
      18,    19,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,    20,     0,    21,     0,    22,     0,    23,
      12,    13,    14,    37,     0,    17,     0,     0,     0,    24,
      18,    19,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,    45,     0,    38,     0,    22,   142,     0,
      12,    13,    14,    37,     0,    17,     0,     0,     0,    24,
      18,    19,     0,     0,     0,     0,     0,     0,     0,     0,
      11,   156,     0,    45,     0,    38,     0,    22,     0,     0,
      12,    13,    14,    37,     0,    17,     0,     0,     0,    24,
      18,    19,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,    45,     0,    38,     0,    22,     0,     0,
      12,    13,    14,    37,     0,    17,     0,     0,     0,    24,
      18,    19,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,    45,     0,    38,     0,   240,     0,     0,
      12,    13,    14,    15,     0,    17,     0,     0,     0,    24,
      18,    19,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,    45,     0,    21,     0,    22,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    24,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,     0,     0,     0,   222,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,     0,
       0,   233,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   108,     0,     0,   111,   112,
     113,   114,   115,   116
};

static const yytype_int16 yycheck[] =
{
       0,     4,   243,     3,     4,     4,    38,     0,     8,    52,
      50,     4,    52,    51,    27,    28,    48,     0,    18,    19,
      20,     4,   311,    23,     0,    35,    26,    32,     4,    52,
      27,    28,     0,    56,    50,    52,     4,    27,    28,    39,
      53,    57,    52,    43,   333,   334,    44,    45,    46,    54,
      32,    51,    52,    53,   295,   296,    53,    50,    51,    27,
      28,     0,    35,    53,     0,    50,    50,    50,    51,    53,
      32,    69,    57,    57,    50,    51,    51,   117,     8,    52,
      55,    35,    50,    56,    14,    15,     6,    26,     8,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    32,
     120,   161,   154,    50,   124,    53,    53,    50,    19,    35,
      53,    23,    24,    25,    26,    44,    45,    46,    29,    30,
      31,    32,    52,    34,    36,    37,    32,    50,    39,    40,
      53,    32,     4,    50,     3,     4,    53,    57,    27,    28,
      43,    52,    53,    54,    35,    56,    27,    58,    20,    21,
      22,    20,    46,    50,    23,     0,    53,    68,     3,     4,
      50,   120,    35,    53,    52,   124,    52,    39,    40,    41,
      42,    43,    44,    45,    46,    20,    50,    56,    23,    53,
     240,    26,    51,    52,    50,   205,   205,    53,    35,   209,
      57,   211,   212,   251,    39,   253,    40,    41,    43,    35,
      35,    32,   222,    35,    32,    32,    51,    52,    50,   229,
     230,    52,    52,   233,     6,   235,   236,    56,   238,   239,
      89,    90,   242,    53,    53,    35,   246,    59,    60,    61,
      62,    57,    64,    65,   254,   104,   105,    35,    35,    26,
     260,   261,   262,   263,    89,    90,   266,   261,   117,   159,
      -1,   271,    -1,    -1,   274,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,    -1,    -1,   324,    -1,   288,   289,
     290,    -1,   117,    -1,    -1,   120,    -1,    -1,   298,   124,
     239,    -1,    -1,   242,    -1,    -1,    -1,   307,    -1,    -1,
     310,   311,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,
      -1,    -1,   261,   262,   263,    -1,   209,   327,   328,   212,
      -1,    -1,   271,   333,   334,   335,    -1,    22,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     289,    -1,   235,   236,    39,   238,   205,    -1,    43,    -1,
      -1,     4,    -1,   246,    -1,    50,    51,    52,    -1,    -1,
      -1,   310,   311,    -1,    -1,    -1,    -1,    20,    21,    22,
     205,    -1,    -1,   266,   209,    -1,    -1,   212,    -1,    -1,
      -1,    -1,    -1,    -1,   333,   334,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,   288,    -1,   290,    -1,    -1,
     235,   236,    -1,   238,   239,    -1,    -1,   242,    -1,    -1,
      -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,   117,    -1,    -1,   120,   261,   262,   263,   124,
      -1,   266,    -1,    -1,   327,   328,   271,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    19,    -1,    -1,
      -1,    -1,    -1,   288,   289,   290,    57,    29,    30,    31,
      32,    -1,    34,    -1,   159,    -1,   161,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,   310,   311,    -1,    50,    -1,
      52,    -1,    54,    55,    56,    20,    21,    -1,    -1,    -1,
      -1,    -1,   327,   328,    -1,    -1,    68,    -1,   333,   334,
      -1,    -1,    -1,    38,    -1,    -1,    20,    21,    -1,    -1,
      45,    -1,    -1,    48,   209,    -1,    51,   212,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    41,    42,    43,
      44,    45,    46,    -1,    69,    -1,    -1,    -1,    -1,    -1,
     235,   236,    19,   238,   239,   240,    -1,   242,    -1,    -1,
      -1,   246,    29,    30,    31,    32,    -1,    34,    -1,    -1,
      -1,    -1,    39,    40,    -1,    -1,   261,   262,   263,    -1,
      -1,   266,    -1,    50,    -1,    52,   271,    54,    55,    56,
      20,    21,    22,    -1,   119,    -1,    -1,    -1,    -1,    -1,
     125,    68,    -1,   288,   289,   290,   131,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,   310,   311,    -1,    -1,   154,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,   327,   328,    -1,    -1,     0,     1,   333,   334,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    12,    13,
      -1,    -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    39,    40,    20,    21,    22,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    52,   224,
      54,   226,    56,    -1,    58,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,   250,   251,    -1,   253,   254,
      -1,    -1,     0,     1,    -1,   260,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    12,    13,    -1,    -1,    16,    -1,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    39,    40,    -1,   299,   300,   301,   302,   303,   304,
      -1,    -1,    -1,    -1,    52,    -1,    54,    -1,    56,    -1,
      58,    -1,     0,     1,    -1,    -1,     4,     5,   323,   324,
      68,     9,    10,    11,    12,    13,    -1,    -1,    16,    -1,
      18,    19,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,
      -1,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    39,    40,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    52,    -1,    54,    -1,    56,    53,
      58,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,    -1,
      68,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    54,    -1,    56,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      68,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    20,
      21,    22,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    39,    40,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    52,
      -1,    54,    53,    56,    -1,    58,    -1,    -1,    -1,     1,
      -1,    -1,     4,     5,    -1,    68,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    18,    19,    -1,    -1,
      20,    21,    22,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      52,    -1,    54,    53,    56,    -1,    58,    -1,    -1,    -1,
       1,    -1,    -1,     4,     5,    -1,    68,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    -1,
      -1,    20,    21,    22,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    52,    -1,    54,    53,    56,    -1,    58,    -1,    -1,
      -1,     1,    -1,    -1,     4,     5,     6,    68,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    39,
      40,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    52,    -1,    54,    53,    56,    -1,    58,    -1,
      -1,    -1,     1,    -1,    -1,     4,     5,    -1,    68,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,
      19,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    -1,    -1,    52,    -1,
      39,    40,    56,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    52,    -1,    54,    -1,    56,    -1,    58,
      -1,    -1,     1,    -1,    -1,     4,     5,    -1,    -1,    68,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,
      19,    -1,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      39,    40,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    50,    -1,    52,    -1,    54,    -1,    56,    -1,    58,
      -1,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,    68,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    -1,    20,    21,    22,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    39,    40,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    52,    -1,    54,    -1,    56,    -1,
      58,    -1,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      68,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    20,    21,    22,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    39,    40,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    52,    -1,    54,    -1,    56,
      -1,    58,    -1,    -1,    -1,     1,    -1,    -1,     4,     5,
      -1,    68,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    -1,
      56,    -1,    58,    -1,    -1,     1,    -1,    -1,     4,     5,
      -1,    -1,    68,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,    -1,    -1,    52,     4,    54,    -1,
      56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      19,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,    -1,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    50,    -1,    52,    -1,    54,    55,    56,    -1,    -1,
      29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,    68,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    52,    -1,    54,    -1,    56,    -1,    58,
      29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,    68,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    52,    -1,    54,    -1,    56,    57,    -1,
      29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,    68,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    52,    -1,    54,    -1,    56,    -1,    58,
      29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,    68,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    52,    -1,    54,    -1,    56,    57,    -1,
      29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,    68,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    50,    -1,    52,    -1,    54,    -1,    56,    -1,    -1,
      29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,    68,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    52,    -1,    54,    -1,    56,    -1,    -1,
      29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,    68,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    52,    -1,    54,    -1,    56,    -1,    -1,
      29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,    68,
      39,    40,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    52,    -1,    54,    -1,    56,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    68,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    -1,    41,    42,
      43,    44,    45,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     9,    10,    11,    12,    13,    16,
      18,    19,    29,    30,    31,    32,    33,    34,    39,    40,
      52,    54,    56,    58,    68,    71,    72,    74,    75,    81,
      82,    84,    90,    92,    93,    94,     4,    32,    54,    79,
      84,    93,    94,    79,    32,    52,    93,    32,    54,    52,
      52,    35,    52,    56,    59,    60,    61,    62,    63,    64,
      65,    66,    93,    93,    84,    90,    91,    93,    88,    89,
      90,    91,    93,    57,    86,    87,    91,    94,    84,    93,
      32,     0,    75,     0,     4,    50,    51,    76,    77,    27,
      28,    23,    24,    25,    26,    36,    37,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    52,    56,    89,
      73,    74,    76,    76,    73,    35,     4,    83,    35,    52,
      56,    89,    32,    87,    84,    91,    92,    94,    53,    84,
      87,    93,    57,    93,    91,    91,    91,    91,    91,    91,
      91,    91,    53,    53,    51,    55,    50,    55,    91,    50,
      57,    52,    84,    93,    84,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    90,    93,    90,    93,    90,
      93,    90,    93,    84,    93,    84,    93,    90,    93,    90,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      84,    87,    93,    93,    55,     7,    74,    80,     8,    91,
       8,    14,    15,    32,    32,    85,    57,    55,    35,    53,
      53,    53,    67,    57,    89,    91,    35,    86,    87,    38,
      69,    53,    53,    67,    57,    79,     6,     8,    50,    73,
      56,    93,    73,    52,    56,    50,    53,    35,    35,    91,
      35,    35,    93,    35,    52,    91,    53,    93,    93,    93,
      52,    73,    73,    73,     8,    87,     4,     8,    85,    57,
      32,    73,    32,    32,    50,    91,    91,    92,    53,    91,
      92,    91,    93,    53,    91,    93,    80,     8,    57,    73,
      53,    56,     0,    17,    78,    52,    52,    93,    35,    59,
      60,    61,    62,    64,    65,    53,    53,    67,    53,    53,
      73,    73,    57,    85,    85,    53,    93,    91,    91,    91,
      91,    91,    91,    35,    35,    93,    78,    53,    53,    91,
      91,    92,    53,    73,    73,    35,    78,    78,    93
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (pproot, errmsg, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location, pproot, errmsg); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, AstNode **pproot, char **errmsg)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, pproot, errmsg)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    AstNode **pproot;
    char **errmsg;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (pproot);
  YYUSE (errmsg);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, AstNode **pproot, char **errmsg)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, pproot, errmsg)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    AstNode **pproot;
    char **errmsg;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, pproot, errmsg);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, AstNode **pproot, char **errmsg)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, pproot, errmsg)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    AstNode **pproot;
    char **errmsg;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , pproot, errmsg);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, pproot, errmsg); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, AstNode **pproot, char **errmsg)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, pproot, errmsg)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    AstNode **pproot;
    char **errmsg;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (pproot);
  YYUSE (errmsg);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 31: /* "\"string\"" */

/* Line 1000 of yacc.c  */
#line 94 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", (yyvaluep->str));
#endif
  free((yyvaluep->str));
};

/* Line 1000 of yacc.c  */
#line 1773 "psycon.tab.c"
	break;
      case 32: /* "\"identifier\"" */

/* Line 1000 of yacc.c  */
#line 94 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", (yyvaluep->str));
#endif
  free((yyvaluep->str));
};

/* Line 1000 of yacc.c  */
#line 1787 "psycon.tab.c"
	break;
      case 33: /* "\"HookCommand\"" */

/* Line 1000 of yacc.c  */
#line 94 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", (yyvaluep->str));
#endif
  free((yyvaluep->str));
};

/* Line 1000 of yacc.c  */
#line 1801 "psycon.tab.c"
	break;
      case 72: /* "block_func" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1815 "psycon.tab.c"
	break;
      case 73: /* "block" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1829 "psycon.tab.c"
	break;
      case 74: /* "line" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1843 "psycon.tab.c"
	break;
      case 75: /* "line_func" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1857 "psycon.tab.c"
	break;
      case 79: /* "conditional" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1871 "psycon.tab.c"
	break;
      case 80: /* "elseif_list" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1885 "psycon.tab.c"
	break;
      case 81: /* "stmt" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1899 "psycon.tab.c"
	break;
      case 82: /* "funcdef" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1913 "psycon.tab.c"
	break;
      case 83: /* "case_list" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1927 "psycon.tab.c"
	break;
      case 84: /* "condition" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1941 "psycon.tab.c"
	break;
      case 85: /* "id_list" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1955 "psycon.tab.c"
	break;
      case 86: /* "arg" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1969 "psycon.tab.c"
	break;
      case 87: /* "arg_list" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1983 "psycon.tab.c"
	break;
      case 88: /* "matrix" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1997 "psycon.tab.c"
	break;
      case 89: /* "vector" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2011 "psycon.tab.c"
	break;
      case 90: /* "range" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2025 "psycon.tab.c"
	break;
      case 91: /* "exp_range" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2039 "psycon.tab.c"
	break;
      case 92: /* "assign" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2053 "psycon.tab.c"
	break;
      case 93: /* "exp" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2067 "psycon.tab.c"
	break;
      case 94: /* "initcell" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2081 "psycon.tab.c"
	break;

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (AstNode **pproot, char **errmsg);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (AstNode **pproot, char **errmsg)
#else
int
yyparse (pproot, errmsg)
    AstNode **pproot;
    char **errmsg;
#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

/* User initialization code.  */

/* Line 1242 of yacc.c  */
#line 78 "psycon.y"
{
  if (ErrorMsg) {
	free(ErrorMsg);
	ErrorMsg = NULL;
  }
  *errmsg = NULL;
}

/* Line 1242 of yacc.c  */
#line 2242 "psycon.tab.c"

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 114 "psycon.y"
    { *pproot = NULL;;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 116 "psycon.y"
    { *pproot = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 120 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 122 "psycon.y"
    { //yyn=5
		if ((yyvsp[(2) - (2)].pnode)) {
			if ((yyvsp[(1) - (2)].pnode) == NULL)
				(yyval.pnode) = (yyvsp[(2) - (2)].pnode);
			else if ((yyvsp[(1) - (2)].pnode)->type == NODE_BLOCK) 
			{
//				$$ = $1;
				(yyvsp[(1) - (2)].pnode)->tail->next = (yyvsp[(2) - (2)].pnode);
				(yyvsp[(1) - (2)].pnode)->tail = (yyvsp[(2) - (2)].pnode);
			} 
			else 
			{ // a=1; b=2; ==> $1->type is '='. So first, a NODE_BLOCK tree should be made.
				(yyval.pnode) = newAstNode(NODE_BLOCK, (yyloc));
				(yyval.pnode)->next = (yyvsp[(1) - (2)].pnode);
				(yyvsp[(1) - (2)].pnode)->next = (yyval.pnode)->tail = (yyvsp[(2) - (2)].pnode);
#ifdef _DEBUG				
				(yyval.pnode)->str = (char*)malloc(32);
				strcpy_s ((yyval.pnode)->str, 32, "block_begins,yyn=5");
#endif
			}
		} else
			(yyval.pnode) = (yyvsp[(1) - (2)].pnode);
	;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 148 "psycon.y"
    {
		if ((yyvsp[(1) - (1)].pnode)) // if cond1, x=1, end ==> x=1 comes here.
			(yyval.pnode) = (yyvsp[(1) - (1)].pnode);
		else
			(yyval.pnode) = newAstNode(NODE_BLOCK, (yyloc));
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 155 "psycon.y"
    {
		if ((yyvsp[(2) - (2)].pnode)) {
			if ((yyvsp[(1) - (2)].pnode)->type == NODE_BLOCK) {
				if ((yyval.pnode)->next) {
//					$$ = $1;
					(yyvsp[(1) - (2)].pnode)->tail->next = (yyvsp[(2) - (2)].pnode);
					(yyvsp[(1) - (2)].pnode)->tail = (yyvsp[(2) - (2)].pnode);
				} else {
					(yyval.pnode) = (yyvsp[(2) - (2)].pnode);
					free((yyvsp[(1) - (2)].pnode));
				}
			} else { //if the second argument doesn't have NODE_BLOCK, make one
				(yyval.pnode) = newAstNode(NODE_BLOCK, (yyloc));
				(yyval.pnode)->next = (yyvsp[(1) - (2)].pnode);
				(yyvsp[(1) - (2)].pnode)->next = (yyval.pnode)->tail = (yyvsp[(2) - (2)].pnode);
#ifdef _DEBUG				
				(yyval.pnode)->str = (char*)malloc(32);
				strcpy_s ((yyval.pnode)->str, 32, "block_begins,yyn=7");
#endif				
			}
		}
		else // only "block" is given
			(yyval.pnode) = (yyvsp[(1) - (2)].pnode);
	;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 182 "psycon.y"
    { (yyval.pnode) = NULL;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 184 "psycon.y"
    { //yyn=9
		(yyval.pnode) = NULL;
		yyerrok;
	;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 189 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (2)].pnode);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 191 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (2)].pnode); (yyval.pnode)->suppress=1;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 195 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 197 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 210 "psycon.y"
    {	(yyval.pnode) = (yyvsp[(1) - (1)].pnode);	;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 212 "psycon.y"
    {	(yyval.pnode) = (yyvsp[(1) - (2)].pnode);	;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 214 "psycon.y"
    {	(yyval.pnode) = (yyvsp[(1) - (1)].pnode);	;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 216 "psycon.y"
    {	(yyval.pnode) = (yyvsp[(1) - (2)].pnode);	;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 220 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_IF, (yyloc));
	;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 224 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_IF, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode);
		(yyvsp[(2) - (4)].pnode)->alt = (yyvsp[(4) - (4)].pnode);
	;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 231 "psycon.y"
    {
		if ((yyvsp[(1) - (3)].pnode)->child==NULL) // in this case $1 is T_IF created as /*empty*/ 
		{  
			yydeleteAstNode((yyvsp[(1) - (3)].pnode), 1);
			(yyval.pnode) = (yyvsp[(3) - (3)].pnode);
		}
		else
		{
			(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
			(yyvsp[(1) - (3)].pnode)->alt = (yyvsp[(3) - (3)].pnode);
		}
	;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 246 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 248 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 250 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 252 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 254 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = malloc(strlen((yyvsp[(1) - (1)].str))+1);
 		strcpy((yyval.pnode)->str, (yyvsp[(1) - (1)].str));
 		free((yyvsp[(1) - (1)].str));
	;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 261 "psycon.y"
    { // This works, too, for "if cond, act; end" without else, because elseif_list can be empty
		(yyval.pnode) = newAstNode(T_IF, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (5)].pnode);
		(yyvsp[(2) - (5)].pnode)->next = (yyvsp[(3) - (5)].pnode);
		(yyvsp[(2) - (5)].pnode)->alt = (yyvsp[(4) - (5)].pnode);
		if ((yyvsp[(4) - (5)].pnode)->child==NULL && (yyvsp[(4) - (5)].pnode)->next==NULL) // When elseif_list is empty, T_IF is made, but no child and next
		{
			yydeleteAstNode((yyval.pnode)->alt, 1);
			(yyval.pnode)->alt=NULL;
		}
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 275 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (4)].pnode);
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode)->child;
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 283 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (6)].pnode);
		(yyvsp[(2) - (6)].pnode)->next = (yyvsp[(3) - (6)].pnode)->child;
		(yyvsp[(3) - (6)].pnode)->tail->next = (yyvsp[(5) - (6)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (6)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 292 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_WHILE, (yyloc));
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
	;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 298 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_FOR, (yyloc));
		(yyval.pnode)->child = newAstNode('=', (yylsp[(2) - (6)]));
		(yyval.pnode)->child->str = (yyvsp[(2) - (6)].str);
		(yyval.pnode)->child->child = (yyvsp[(4) - (6)].pnode);
		(yyval.pnode)->child->next = (yyvsp[(5) - (6)].pnode);
	;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 306 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_FOR, (yyloc));
		(yyval.pnode)->child = newAstNode('=', (yylsp[(2) - (7)]));
		(yyval.pnode)->child->str = (yyvsp[(2) - (7)].str);
		(yyval.pnode)->child->child = (yyvsp[(4) - (7)].pnode);
		(yyval.pnode)->child->next = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 314 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_RETURN, (yyloc));
	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 318 "psycon.y"
    { (yyval.pnode) = newAstNode(T_BREAK, (yyloc));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 320 "psycon.y"
    { (yyval.pnode) = newAstNode(T_CONTINUE, (yyloc));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 324 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(2) - (7)].str);
		(yyval.pnode)->child = (yyvsp[(4) - (7)].pnode);
		(yyvsp[(4) - (7)].pnode)->next = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 331 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(4) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (9)].pnode);
		(yyvsp[(6) - (9)].pnode)->next = (yyvsp[(8) - (9)].pnode);
		(yyval.pnode)->alt = newAstNode(NODE_VECTOR, (yylsp[(2) - (9)]));
		(yyval.pnode)->alt->child = (yyval.pnode)->alt->tail = newAstNode(T_ID, (yylsp[(3) - (9)]));
		(yyval.pnode)->alt->child->str = (yyval.pnode)->alt->tail->str = (yyvsp[(2) - (9)].str);
	;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 341 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(6) - (11)].str);
		(yyval.pnode)->child = (yyvsp[(8) - (11)].pnode);
		(yyvsp[(8) - (11)].pnode)->next = (yyvsp[(10) - (11)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (11)].pnode);

		;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 350 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(6) - (11)].str);
		(yyval.pnode)->child = (yyvsp[(8) - (11)].pnode);
		(yyvsp[(8) - (11)].pnode)->next = (yyvsp[(10) - (11)].pnode);
		(yyvsp[(10) - (11)].pnode)->next = newAstNode(NODE_INITCELL, (yylsp[(2) - (11)]));
		(yyvsp[(10) - (11)].pnode)->next->str = (yyvsp[(2) - (11)].str);
	;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 361 "psycon.y"
    { (yyval.pnode) = newAstNode(T_SWITCH, (yyloc));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 363 "psycon.y"
    { (yyval.pnode) = newAstNode(T_SWITCH, (yyloc));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 365 "psycon.y"
    {
		if ((yyvsp[(1) - (5)].pnode)->child)
			(yyvsp[(1) - (5)].pnode)->tail->next = (yyvsp[(3) - (5)].pnode);
		else
			(yyvsp[(1) - (5)].pnode)->child = (yyvsp[(3) - (5)].pnode);
		(yyvsp[(3) - (5)].pnode)->next = (yyvsp[(5) - (5)].pnode);
		(yyvsp[(1) - (5)].pnode)->tail = (yyvsp[(5) - (5)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (5)].pnode);
	;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 375 "psycon.y"
    {
		if ((yyvsp[(1) - (6)].pnode)->child)
			(yyvsp[(1) - (6)].pnode)->tail->next = (yyvsp[(4) - (6)].pnode);
		else
			(yyvsp[(1) - (6)].pnode)->child = (yyvsp[(4) - (6)].pnode);
		(yyvsp[(4) - (6)].pnode)->next = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(1) - (6)].pnode)->tail = (yyvsp[(6) - (6)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (6)].pnode);
	;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 387 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('<', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 389 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('<', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 391 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('<', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 393 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('>', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 395 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('>', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 397 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('>', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 399 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_EQ, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 401 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_EQ, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 403 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_EQ, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 405 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_NE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 407 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_NE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 409 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_NE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 411 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_GE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 413 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_GE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 415 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_GE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 417 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_LE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 419 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_LE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 421 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_LE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 423 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 429 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_LOGIC_NOT, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (2)].pnode);
	;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 434 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_LOGIC_NOT, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (2)].pnode);
	;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 439 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 441 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 443 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 445 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 447 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 449 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 451 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 453 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 457 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
	;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 461 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->tail = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->tail->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 467 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->tail = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->tail->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 473 "psycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->tail = (yyvsp[(1) - (3)].pnode)->tail->next = newAstNode(T_ID, (yylsp[(3) - (3)]));
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
		(yyval.pnode)->tail->str = (yyvsp[(3) - (3)].str);
	;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 479 "psycon.y"
    {
		(yyvsp[(1) - (5)].pnode)->tail = (yyvsp[(1) - (5)].pnode)->tail->next = newAstNode(NODE_INITCELL, (yylsp[(3) - (5)]));
		(yyval.pnode) = (yyvsp[(1) - (5)].pnode);
		(yyval.pnode)->tail->str = (yyvsp[(3) - (5)].str);
	;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 487 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 489 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 493 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_ARGS, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->tail = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 498 "psycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->tail = (yyvsp[(1) - (3)].pnode)->tail->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 505 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_MATRIX, (yyloc));
	;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 509 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_MATRIX, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->tail = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 514 "psycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->tail = (yyvsp[(1) - (3)].pnode)->tail->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 521 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_VECTOR, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->tail = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 526 "psycon.y"
    {
		(yyvsp[(1) - (2)].pnode)->tail = (yyvsp[(1) - (2)].pnode)->tail->next = (yyvsp[(2) - (2)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (2)].pnode);
	;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 531 "psycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->tail = (yyvsp[(1) - (3)].pnode)->tail->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 538 "psycon.y"
    {
		(yyval.pnode) = makeFunctionCall(":", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));
	;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 542 "psycon.y"
    {
		(yyval.pnode) = makeFunctionCall(":", (yyvsp[(1) - (5)].pnode), (yyvsp[(5) - (5)].pnode), (yyloc));
		(yyval.pnode)->tail = (yyvsp[(5) - (5)].pnode)->next = (yyvsp[(3) - (5)].pnode);
	;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 549 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 551 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 555 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 561 "psycon.y"
    { // Only to be used when RHS is a UDF. 5/18/2017 bjkwon
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->child = (yyvsp[(5) - (5)].pnode);
		(yyval.pnode)->alt = (yyvsp[(2) - (5)].pnode);
	;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 567 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 573 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('+', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 579 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('-', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 585 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('*', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 591 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('/', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 597 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNodeFunctionCall('^', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 603 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('@', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 609 "psycon.y"
    { 
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str); 
		(yyval.pnode)->child = makeCompoundLevelOpNode((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(1) - (3)]), (yylsp[(3) - (3)]));
	;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 615 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode(T_OP_CONCAT, (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 621 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 628 "psycon.y"
    {
		(yyval.pnode) = Restring("+=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 632 "psycon.y"
    {
		(yyval.pnode) = Restring("-=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 636 "psycon.y"
    {
		(yyval.pnode) = Restring("*=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 640 "psycon.y"
    {
		(yyval.pnode) = Restring("/=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 644 "psycon.y"
    {
		(yyval.pnode) = Restring("@=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 648 "psycon.y"
    {
		(yyval.pnode) = Restring("@@=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 652 "psycon.y"
    { /* x(45)=723 or x(id1:id2) = id1:id2  or x(array) = scalar */
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 659 "psycon.y"
    { /* x(x>0) = scalar */
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 666 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (8)].str);
		(yyval.pnode)->child = (yyvsp[(8) - (8)].pnode);
		(yyval.pnode)->alt = newAstNode(NODE_IDLIST, (yyloc));
		(yyval.pnode)->alt->child = (yyvsp[(5) - (8)].pnode);
		(yyval.pnode)->alt->alt = (yyvsp[(3) - (8)].pnode);
	;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 675 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (11)].str);
		(yyval.pnode)->child = (yyvsp[(11) - (11)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (11)].pnode);
		(yyvsp[(3) - (11)].pnode)->alt = newAstNode(NODE_IDLIST, (yyloc));
		(yyvsp[(3) - (11)].pnode)->alt->child = (yyvsp[(8) - (11)].pnode);
		(yyvsp[(3) - (11)].pnode)->alt->alt = (yyvsp[(6) - (11)].pnode);
	;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 686 "psycon.y"
    { // v{2}(4)=1 
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(9) - (9)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (9)].pnode);
		(yyvsp[(3) - (9)].pnode)->next = (yyvsp[(6) - (9)].pnode);
	;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 694 "psycon.y"
    { // v{2}(4:6)=1 
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(9) - (9)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (9)].pnode);
		(yyvsp[(3) - (9)].pnode)->next = (yyvsp[(6) - (9)].pnode);
	;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 702 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 708 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(6) - (6)].pnode)->alt = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 715 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(6) - (6)].pnode)->alt = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 722 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(9) - (9)].pnode);
		(yyvsp[(9) - (9)].pnode)->alt = (yyvsp[(6) - (9)].pnode);
		(yyvsp[(6) - (9)].pnode)->alt = (yyvsp[(3) - (9)].pnode);
	;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 730 "psycon.y"
    { // x={"bjk",noise(300), 4.5555}
		(yyval.pnode) = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 739 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_NUMBER, (yyloc));
		(yyval.pnode)->dval = (yyvsp[(1) - (1)].dval);
	;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 744 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_STRING, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 749 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ENDPOINT, (yyloc));
		(yyval.pnode)->str = NULL;
	;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 754 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 758 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (1)].str);
//		yyPrintf("T_ID", $$);
	;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 764 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (4)].pnode);
	;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 770 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (7)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (7)].pnode);
		(yyvsp[(3) - (7)].pnode)->alt = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 777 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (7)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (7)].pnode);
		(yyvsp[(3) - (7)].pnode)->alt = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 784 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
	;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 788 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 793 "psycon.y"
    { // I don't know what this is doing.... bjk 3/28/2017 
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 798 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->type = NODE_CALL;
 		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 806 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_REPLICA, (yyloc));
		(yyval.pnode)->child = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->child->type = NODE_CALL;
		// At this point, this makes NODE_CALL with NULL str. This is to be resolved in AstSig.cpp-----AstNode *tp = searchtree(p, NODE_CALL);
	;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 813 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->tail = (yyvsp[(3) - (4)].pnode); // leaving a mark for conditional indexing 3/28/2017 bjk
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 822 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(4) - (5)].pnode);
		(yyval.pnode)->type = NODE_CALL;
 		(yyval.pnode)->str = malloc(strlen((yyvsp[(2) - (5)].str))+2);
 		(yyval.pnode)->str[0] = '#';
 		strcpy((yyval.pnode)->str+1, (yyvsp[(2) - (5)].str));
 		free((yyvsp[(2) - (5)].str));
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 833 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_EXTRACT, (yyloc));
		(yyval.pnode)->child = newAstNode(T_ID, (yylsp[(1) - (6)]));
		(yyval.pnode)->child->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child->next = (yyvsp[(3) - (6)].pnode);
		(yyvsp[(3) - (6)].pnode)->next = (yyvsp[(5) - (6)].pnode);
	;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 841 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_NEGATIVE, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (2)].pnode);
	;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 846 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (2)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 852 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 858 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_SIGMA, (yyloc));
		(yyval.pnode)->child = newAstNode('=', (yylsp[(3) - (8)]));
		(yyval.pnode)->child->str = (yyvsp[(3) - (8)].str);
		(yyval.pnode)->child->child = (yyvsp[(5) - (8)].pnode);
		(yyval.pnode)->child->next = (yyvsp[(7) - (8)].pnode);
	;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 866 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('+', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 868 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('-', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 870 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('*', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 872 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('/', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 874 "psycon.y"
    { (yyval.pnode) = makeFunctionCall("^", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 876 "psycon.y"
    { (yyval.pnode) = makeFunctionCall("caret", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 878 "psycon.y"
    { (yyval.pnode) = makeFunctionCall("shift_spectrum", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 880 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('@', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 882 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INTERPOL, (yyloc));
		(yyval.pnode)->child = (yyvsp[(1) - (5)].pnode);
		(yyvsp[(1) - (5)].pnode)->next = (yyvsp[(3) - (5)].pnode);
		(yyvsp[(3) - (5)].pnode)->next = (yyvsp[(5) - (5)].pnode);
		(yyval.pnode)->tail = (yyvsp[(5) - (5)].pnode);
	;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 890 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_SHIFT, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 892 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_SHIFT2, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 894 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_CONCAT, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 896 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 902 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 908 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_REPLICA, (yyloc));
		(yyval.pnode)->str = NULL;
	;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 915 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->type = NODE_INITCELL;
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;



/* Line 1455 of yacc.c  */
#line 3957 "psycon.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (pproot, errmsg, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (pproot, errmsg, yymsg);
	  }
	else
	  {
	    yyerror (pproot, errmsg, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc, pproot, errmsg);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, pproot, errmsg);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (pproot, errmsg, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, pproot, errmsg);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, pproot, errmsg);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 923 "psycon.y"


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
