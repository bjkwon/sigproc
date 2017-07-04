
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
     T_NUMBER = 284,
     T_STRING = 285,
     T_ID = 286,
     T_ENDPOINT = 287,
     T_NEGATIVE = 288,
     T_POSITIVE = 289,
     T_LOGIC_NOT = 290,
     T_REPLICA = 291
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
#line 169 "psycon.tab.c"
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
#line 206 "psycon.tab.c"

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
#define YYFINAL  80
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2403

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  163
/* YYNRULES -- Number of states.  */
#define YYNSTATES  348

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    67,    39,    40,     2,     2,
      51,    52,    42,    38,    49,    37,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    50,
      34,    33,    35,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,    68,    56,    66,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    45,    46,
      47,    48,    58,    59,    60,    61,    62,    63,    64,    65
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    16,    18,
      21,    24,    26,    28,    30,    32,    34,    36,    37,    39,
      41,    43,    46,    48,    51,    52,    57,    61,    63,    65,
      67,    69,    75,    80,    87,    92,    97,   103,   109,   116,
     124,   126,   128,   130,   138,   148,   160,   172,   173,   175,
     181,   188,   192,   196,   200,   204,   208,   212,   216,   220,
     224,   228,   232,   236,   240,   244,   248,   252,   256,   260,
     264,   267,   270,   274,   278,   282,   286,   290,   294,   298,
     302,   303,   305,   309,   313,   319,   321,   323,   325,   329,
     330,   332,   336,   338,   341,   345,   349,   355,   357,   359,
     363,   369,   373,   377,   381,   385,   389,   393,   397,   401,
     405,   412,   421,   430,   439,   448,   457,   466,   473,   480,
     489,   501,   511,   521,   525,   532,   539,   549,   553,   555,
     557,   559,   561,   563,   568,   576,   584,   587,   591,   595,
     600,   605,   610,   616,   623,   626,   629,   633,   642,   646,
     650,   654,   658,   662,   666,   670,   674,   680,   684,   688,
     692,   696,   700,   702
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      70,     0,    -1,    -1,    71,    -1,    74,    -1,    71,    74,
      -1,    73,    -1,    72,    73,    -1,     4,    -1,     1,     4,
      -1,    79,    75,    -1,    73,    -1,    80,    -1,    49,    -1,
      50,    -1,     4,    -1,     0,    -1,    -1,    17,    -1,     0,
      -1,    82,    -1,    82,    75,    -1,    91,    -1,    91,    75,
      -1,    -1,     7,    77,    72,    78,    -1,    78,     6,    72,
      -1,    91,    -1,    90,    -1,    82,    -1,    92,    -1,     5,
      77,    72,    78,     8,    -1,    13,    91,    81,     8,    -1,
      13,    91,    81,    15,    72,     8,    -1,     9,    82,    72,
       8,    -1,     9,    91,    72,     8,    -1,     9,    82,    49,
      72,     8,    -1,     9,    91,    49,    72,     8,    -1,    10,
      31,    33,    89,    72,     8,    -1,    10,    31,    33,    89,
      49,    72,     8,    -1,    18,    -1,    11,    -1,    12,    -1,
      16,    31,    51,    83,    52,    72,    76,    -1,    16,    31,
      33,    31,    51,    83,    52,    72,    76,    -1,    16,    53,
      87,    54,    33,    31,    51,    83,    52,    72,    76,    -1,
      16,    31,    55,    56,    33,    31,    51,    83,    52,    72,
      76,    -1,    -1,     4,    -1,    81,    14,    91,     4,    72,
      -1,    81,    14,    55,    85,    56,    72,    -1,    91,    34,
      91,    -1,    88,    34,    91,    -1,    91,    34,    88,    -1,
      91,    35,    91,    -1,    88,    35,    91,    -1,    91,    35,
      88,    -1,    91,    23,    91,    -1,    88,    23,    91,    -1,
      91,    23,    88,    -1,    91,    24,    91,    -1,    88,    24,
      91,    -1,    91,    24,    88,    -1,    91,    26,    91,    -1,
      88,    26,    91,    -1,    91,    26,    88,    -1,    91,    25,
      91,    -1,    88,    25,    91,    -1,    91,    25,    88,    -1,
      51,    82,    52,    -1,    57,    82,    -1,    57,    91,    -1,
      82,    27,    82,    -1,    91,    27,    91,    -1,    82,    27,
      91,    -1,    91,    27,    82,    -1,    82,    28,    82,    -1,
      91,    28,    91,    -1,    82,    28,    91,    -1,    91,    28,
      82,    -1,    -1,    31,    -1,    31,    55,    56,    -1,    83,
      49,    31,    -1,    83,    49,    31,    55,    56,    -1,    89,
      -1,    92,    -1,    84,    -1,    85,    49,    84,    -1,    -1,
      87,    -1,    86,    50,    87,    -1,    89,    -1,    87,    89,
      -1,    87,    49,    89,    -1,    91,    36,    91,    -1,    91,
      36,    91,    36,    91,    -1,    91,    -1,    88,    -1,    31,
      33,    89,    -1,    53,    87,    54,    33,    89,    -1,    31,
      33,    82,    -1,    31,    58,    89,    -1,    31,    59,    89,
      -1,    31,    60,    89,    -1,    31,    61,    89,    -1,    31,
      62,    89,    -1,    31,    63,    89,    -1,    31,    64,    89,
      -1,    31,    65,    89,    -1,    31,    55,    91,    56,    33,
      89,    -1,    31,    51,    91,    66,    91,    52,    58,    89,
      -1,    31,    51,    91,    66,    91,    52,    59,    89,    -1,
      31,    51,    91,    66,    91,    52,    60,    89,    -1,    31,
      51,    91,    66,    91,    52,    61,    89,    -1,    31,    51,
      91,    66,    91,    52,    63,    89,    -1,    31,    51,    91,
      66,    91,    52,    64,    89,    -1,    31,    51,    85,    52,
      33,    89,    -1,    31,    51,    82,    52,    33,    89,    -1,
      31,    51,    91,    66,    91,    52,    33,    91,    -1,    31,
      55,    91,    56,    51,    91,    66,    91,    52,    33,    91,
      -1,    31,    55,    91,    56,    51,    91,    52,    33,    89,
      -1,    31,    55,    91,    56,    51,    89,    52,    33,    89,
      -1,    31,    33,    90,    -1,    31,    55,    91,    56,    33,
      90,    -1,    31,    51,    85,    52,    33,    90,    -1,    31,
      55,    91,    56,    51,    91,    52,    33,    90,    -1,    31,
      33,    92,    -1,    29,    -1,    30,    -1,    32,    -1,    92,
      -1,    31,    -1,    31,    55,    91,    56,    -1,    31,    55,
      91,    56,    51,    91,    52,    -1,    31,    55,    91,    56,
      51,    89,    52,    -1,    55,    56,    -1,    31,    55,    56,
      -1,    31,    51,    52,    -1,    31,    51,    85,    52,    -1,
      31,    51,    82,    52,    -1,    67,    31,    51,    52,    -1,
      67,    31,    51,    85,    52,    -1,    31,    51,    91,    66,
      91,    52,    -1,    37,    91,    -1,    38,    91,    -1,    51,
      89,    52,    -1,    19,    51,    31,    33,    89,    49,    91,
      52,    -1,    91,    38,    91,    -1,    91,    37,    91,    -1,
      91,    42,    91,    -1,    91,    43,    91,    -1,    91,    44,
      91,    -1,    91,    40,    91,    -1,    91,    39,    91,    -1,
      91,    41,    91,    -1,    91,    41,    91,    68,    91,    -1,
      91,    20,    91,    -1,    91,    21,    91,    -1,    91,    22,
      91,    -1,    53,    86,    54,    -1,    53,    87,    54,    -1,
      48,    -1,    55,    85,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   115,   119,   121,   147,   154,   181,   183,
     188,   192,   194,   198,   198,   198,   198,   201,   201,   201,
     204,   206,   208,   210,   215,   218,   225,   240,   242,   244,
     246,   248,   262,   270,   279,   285,   291,   297,   303,   311,
     319,   323,   325,   329,   336,   346,   355,   367,   368,   370,
     380,   392,   394,   396,   398,   400,   402,   404,   406,   408,
     410,   412,   414,   416,   418,   420,   422,   424,   426,   428,
     434,   439,   444,   446,   448,   450,   452,   454,   456,   458,
     463,   466,   472,   478,   484,   492,   494,   498,   503,   511,
     514,   519,   526,   531,   536,   543,   547,   554,   556,   560,
     566,   572,   578,   584,   590,   596,   602,   608,   614,   620,
     626,   633,   637,   641,   645,   649,   653,   657,   664,   671,
     680,   691,   699,   707,   713,   720,   727,   735,   744,   749,
     754,   759,   763,   768,   774,   781,   788,   792,   797,   802,
     810,   819,   827,   838,   846,   851,   857,   863,   871,   873,
     875,   877,   879,   881,   883,   885,   887,   895,   897,   899,
     901,   907,   913,   920
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
  "\"!=\"", "\"<=\"", "\">=\"", "\"&&\"", "\"||\"", "\"number\"",
  "\"string\"", "\"identifier\"", "T_ENDPOINT", "'='", "'<'", "'>'", "':'",
  "'-'", "'+'", "'$'", "'%'", "'@'", "'*'", "'/'", "'^'", "T_NEGATIVE",
  "T_POSITIVE", "T_LOGIC_NOT", "\"..\"", "','", "';'", "'('", "')'", "'['",
  "']'", "'{'", "'}'", "'!'", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"",
  "\"^=\"", "\"@=\"", "\"@@=\"", "\"++=\"", "'~'", "'#'", "'|'", "$accept",
  "input", "block_func", "block", "line", "line_func", "eol", "func_end",
  "conditional", "elseif_list", "stmt", "funcdef", "case_list",
  "condition", "id_list", "arg", "arg_list", "matrix", "vector", "range",
  "exp_range", "assign", "exp", "initcell", 0
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
     285,   286,   287,    61,    60,    62,    58,    45,    43,    36,
      37,    64,    42,    47,    94,   288,   289,   290,   291,    44,
      59,    40,    41,    91,    93,   123,   125,    33,   292,   293,
     294,   295,   296,   297,   298,   299,   126,    35,   124
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      73,    74,    74,    75,    75,    75,    75,    76,    76,    76,
      77,    77,    77,    77,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    80,    80,    80,    80,    81,    81,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    83,    83,    83,    83,    84,    84,    85,    85,    86,
      86,    86,    87,    87,    87,    88,    88,    89,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       1,     2,     1,     2,     0,     4,     3,     1,     1,     1,
       1,     5,     4,     6,     4,     4,     5,     5,     6,     7,
       1,     1,     1,     7,     9,    11,    11,     0,     1,     5,
       6,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       0,     1,     3,     3,     5,     1,     1,     1,     3,     0,
       1,     3,     1,     2,     3,     3,     5,     1,     1,     3,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       6,     8,     8,     8,     8,     8,     8,     6,     6,     8,
      11,     9,     9,     3,     6,     6,     9,     3,     1,     1,
       1,     1,     1,     4,     7,     7,     2,     3,     3,     4,
       4,     4,     5,     6,     2,     2,     3,     8,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     3,     3,     3,
       3,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     8,     0,     0,     0,    41,    42,     0,     0,
      40,     0,   128,   129,   132,   130,     0,     0,   162,     0,
      89,     0,     0,     0,     0,     0,    11,     4,     0,    12,
      29,     0,    28,    27,   131,     9,   132,    89,     0,    20,
      22,   131,     0,     0,     0,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   144,   145,     0,    98,     0,    97,     0,    90,    98,
      92,    97,   136,    87,     0,    85,   131,    70,    71,     0,
       1,     5,    16,    15,    13,    14,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,     0,     6,
      21,    23,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,    80,     0,     0,     0,   101,    99,   123,   131,
     138,     0,     0,    97,   137,     0,   102,   103,   104,   105,
     106,   107,   108,   109,    69,   146,     0,   160,     0,   161,
      93,     0,   163,     0,    72,    74,    76,    78,    58,    61,
      67,    64,    52,    55,   157,   158,   159,    59,    57,    62,
      60,    68,    66,    65,    63,    75,    73,    79,    77,    53,
      51,    56,    54,    95,   149,   148,   154,   153,   155,   150,
     151,   152,     0,     0,    97,     0,   161,     0,     7,     0,
       0,    34,   144,   145,     0,    35,     0,    32,     0,     0,
       0,    81,     0,     0,     0,     0,   140,   139,     0,   133,
      91,    94,     0,    88,   141,     0,     0,     0,   140,   139,
       0,   133,     0,     0,    31,    36,    37,     0,     0,     0,
       0,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   142,    96,   156,     0,     0,
       0,     0,     0,    38,     0,     0,    33,     0,    82,    83,
       0,     0,     0,     0,   118,   117,   125,   143,   110,   124,
       0,     0,   143,     0,     0,    25,    39,     0,     0,     0,
       0,    19,    18,    43,    80,    80,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   134,     0,   135,   134,     0,
       0,    84,     0,     0,   147,   119,   111,   112,   113,   114,
     115,   116,     0,     0,     0,    44,     0,     0,   122,   121,
     126,     0,     0,     0,     0,    46,    45,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,    25,   118,   119,    27,    86,   303,    38,   209,
      28,    29,   130,    30,   222,    73,    74,    67,    68,    31,
      75,    32,    71,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -277
static const yytype_int16 yypact[] =
{
     793,    37,  -277,  1942,  1942,    16,  -277,  -277,  2114,    15,
    -277,    14,  -277,  -277,    86,  -277,  2114,  2114,  -277,  1942,
    2114,  1973,  1942,   102,   143,   852,  -277,  -277,    33,  -277,
     181,   166,  -277,  2284,   135,  -277,   -25,  2114,  1811,   130,
      36,  -277,  1029,   911,   142,  2114,   291,   121,  2114,   133,
    2001,  1857,  2032,  2114,  2114,  2114,  2114,  2114,  2114,  2114,
    2114,  -277,  -277,   -21,   166,   163,  2284,    -1,   389,  -277,
    -277,  1336,  -277,  -277,   -38,  -277,    80,  -277,  2359,   132,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  1942,  1942,  2114,
    2114,  2114,  2114,  2114,  2114,  2114,  2114,  2114,  2114,  2114,
    2114,  2114,  1942,  1942,  2114,  2114,  2114,  2114,  2114,  2114,
    2114,  2114,  2114,  2114,  2114,  1857,  2032,  1888,  1093,  -277,
    -277,  -277,  1811,  1333,  2114,  2114,  1811,  1393,  2114,  -277,
      20,   182,   186,   165,  1915,   190,   181,  -277,  -277,   138,
    -277,    -7,   -20,  2204,  -277,   854,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  2114,  -277,  2114,   196,
    -277,  2114,  -277,  2060,  -277,  2334,   211,  2309,   486,   486,
     486,   486,   486,   486,   162,   162,   191,  -277,  1336,  -277,
    1336,  -277,  1336,  -277,  1336,  -277,  2334,   211,  2309,  -277,
    1336,  -277,  1336,  1396,   191,   191,   162,   162,   -29,   195,
     195,   195,    -4,    32,  2237,  1031,  -277,  1942,  -277,   147,
    1453,  -277,   704,  1826,  1513,  -277,  1572,  -277,  2141,  1811,
     193,   197,   110,   208,   212,  2114,   217,   223,  2114,   -24,
    2087,  -277,  2114,  -277,  -277,   111,  2114,  2114,  -277,  -277,
    2114,   209,  1811,  1811,  -277,  -277,  -277,  1811,  1632,  1973,
     631,  1692,   186,   203,   233,  1811,   234,   235,   218,  2114,
    2168,  1095,  2168,  2114,  -277,  -277,   486,   486,  1155,  2114,
    1093,  1273,  1752,  -277,    72,  1811,  -277,   145,  -277,   213,
     610,   222,   227,  2114,  -277,  -277,  -277,   107,  -277,  -277,
     229,   318,  -277,   230,  2246,   268,  -277,   970,  1153,  1811,
     231,  -277,  -277,  -277,   186,   186,  1215,  2114,  2114,  2114,
    2114,  2114,  2114,  2114,   252,   253,  2114,  -277,  -277,  1213,
     610,  -277,   146,   150,  -277,   486,  -277,  -277,  -277,  -277,
    -277,  -277,  2114,  2168,  1275,  -277,  1811,  1811,  -277,  -277,
    -277,   257,   610,   610,  2114,  -277,  -277,   486
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -277,  -277,  -277,   267,   161,   266,   187,  -276,    89,    30,
    -277,  -277,  -277,   174,  -250,   140,   -46,  -277,   -36,   434,
     526,   -40,     0,   131
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -164
static const yytype_int16 yytable[] =
{
      33,   117,   277,    40,    43,   142,    87,    88,    46,   262,
     138,   161,   134,   112,   113,   114,    61,    62,   162,    66,
      87,    88,    78,    87,    88,    33,   115,   263,   217,   161,
     116,   154,   227,    82,   218,   219,    82,    83,    33,   237,
      83,    35,    33,    33,   335,   226,    47,    44,   238,   156,
      66,   143,   145,   157,   322,   323,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    49,   345,   346,    48,   203,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   161,    84,    85,   239,    84,    85,   165,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   178,   180,
     182,   184,   186,   188,   190,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   204,   205,   235,    33,    50,
     230,   161,    33,    33,   212,   213,    33,    33,   297,   -86,
      82,    34,   -86,    79,    83,   -30,   -86,    51,  -127,   -30,
     307,    52,  -127,    80,    53,    54,    55,    56,    57,    58,
      59,    60,    76,   243,   131,   244,    34,    87,    88,   254,
     161,    26,   255,   265,   135,   308,   309,   310,   311,    34,
     312,   313,   132,    34,    34,   128,   133,    39,    42,    84,
      85,   139,    76,   163,   -30,   -30,    26,  -127,  -127,    89,
      90,    91,    92,    63,   254,   254,    77,   299,   336,   254,
      93,    94,   337,   274,   112,   113,   114,    40,    87,    88,
      33,    95,    96,   220,    33,   155,    33,   221,   250,    33,
     286,   223,   289,   225,   136,   141,   120,   121,   261,   232,
     109,   110,   111,   112,   113,   114,   266,   267,    87,   114,
     268,   256,    33,    33,   252,   257,    76,    33,    33,    34,
     259,    33,   253,    34,    34,    33,   260,    34,    34,   278,
     269,   164,   166,   291,   279,   281,   282,   283,   300,   294,
      33,    33,    33,   304,   243,    33,   185,   187,   305,   208,
      33,   314,   317,   306,   208,   332,   333,   321,   208,   202,
     344,    81,    76,   340,    76,   129,   242,    33,    33,    33,
     295,   233,     0,     0,     0,     0,     0,   325,     0,   123,
     127,    95,    96,    97,     0,     0,   334,     0,     0,    33,
      33,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,   114,    33,    33,    95,    96,
      97,    34,    33,    33,   347,    34,     0,    34,     0,     0,
      34,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
     315,   208,     0,    34,    34,   208,     0,     0,    34,    34,
      76,    39,    34,     0,   316,     0,    34,     0,     0,   210,
       0,     0,     0,   214,     0,     0,     0,     0,     0,     0,
       0,    34,    34,    34,     0,     0,    34,     0,    11,   208,
       0,    34,   208,     0,     0,     0,     0,     0,    12,    13,
      36,    15,     0,     0,     0,     0,    16,    17,    34,    34,
      34,   208,   208,   208,     0,     0,     0,    18,   158,     0,
      45,   208,    37,   159,    21,     0,     0,     0,     0,     0,
      34,    34,     0,    64,    69,    69,    23,     0,     0,   208,
       0,     0,     0,     0,     0,     0,     0,    34,    34,     0,
       0,    69,     0,    34,    34,     0,     0,     0,     0,    69,
     208,   208,    69,   248,    64,    64,   251,    69,    69,    69,
      69,    69,    69,    69,    69,     0,     0,     0,     0,     0,
       0,     0,    69,   208,   208,     0,    95,    96,    97,   270,
     271,     0,     0,     0,   272,     0,     0,     0,     0,     0,
       0,     0,   280,   107,   108,   109,   110,   111,   112,   113,
     114,     0,   177,   179,   181,   183,     0,     0,   189,   191,
       0,     0,   298,     0,     0,    65,    70,     0,     0,    64,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,    70,   319,     0,   320,     0,    69,     0,
       0,    65,     0,     0,    70,     0,   137,     0,     0,   146,
     147,   148,   149,   150,   151,   152,   153,     0,     0,     0,
      69,     0,    69,     0,   160,    69,     0,    69,     0,     0,
       0,     0,     0,   342,   343,     0,     0,     0,     0,     0,
     301,     1,     0,     0,     2,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     0,     0,   -17,   302,    10,    11,
       0,     0,     0,     0,     0,   275,     0,     0,     0,    12,
      13,    14,    15,   160,     0,     0,     0,    16,    17,     0,
       0,    95,    96,    97,   216,     0,     0,     0,    18,    69,
     160,    19,     0,    20,    69,    21,    69,    22,   107,   108,
     109,   110,   111,   112,   113,   114,     0,    23,     0,     0,
       0,     0,    70,    69,   231,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    69,     0,    69,    69,     0,     0,
       0,     0,     0,    69,     0,  -149,     0,     0,     0,  -149,
       0,     0,     0,  -149,  -149,  -149,  -149,  -149,     0,     0,
       0,     0,  -149,  -149,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -149,  -149,  -149,  -149,     0,     0,     0,
       0,     0,    69,    69,    69,    69,    69,    69,     0,     0,
       0,   258,  -149,     0,     0,  -149,   160,  -149,   264,  -149,
       0,  -149,     0,     0,     0,     0,    69,    69,     0,     0,
       0,  -149,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,   285,     0,   288,   290,
       0,     0,     0,    -2,     1,   293,     0,     2,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     0,     0,     9,
       0,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,     0,     0,     0,     0,
      16,    17,     0,     0,   326,   327,   328,   329,   330,   331,
       0,    18,     0,     0,    19,     0,    20,     0,    21,     0,
      22,     0,    -3,     1,     0,     0,     2,     3,   338,   339,
      23,     4,     5,     6,     7,     8,     0,     0,     9,     0,
      10,    11,     0,     0,    95,    96,    97,     0,     0,     0,
       0,    12,    13,    14,    15,     0,     0,     0,     0,    16,
      17,   107,   108,   109,   110,   111,   112,   113,   114,     0,
      18,     0,     0,    19,     0,    20,     0,    21,     0,    22,
     229,     0,     1,     0,     0,     2,     3,     0,     0,    23,
       4,     5,     6,     7,     8,     0,     0,     0,     0,    10,
      11,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      12,    13,    14,    15,     0,   104,   105,   106,   124,   125,
     109,   110,   111,   112,   113,   114,     0,     0,     0,    18,
     126,     0,    19,     0,    20,     0,    21,     0,    22,     0,
       0,     1,     0,     0,     2,     3,     0,     0,    23,     4,
       5,     6,     7,     8,     0,     0,     0,     0,    10,    11,
    -163,  -163,  -163,     0,     0,     0,     0,     0,     0,    12,
      13,    14,    15,     0,     0,     0,     0,    16,    17,  -163,
    -163,  -163,  -163,  -163,  -163,     0,     0,     0,    18,     0,
       0,    19,     0,    20,     0,    21,     0,    22,     0,     0,
       1,     0,     0,     2,     3,     0,     0,    23,     4,     5,
       6,     7,     8,     0,     0,     0,     0,    10,    11,     0,
       0,    95,    96,    97,     0,     0,    87,    88,    12,    13,
      14,    15,     0,     0,     0,     0,    16,    17,   107,   108,
     109,   110,   111,   112,   113,   114,     0,    18,   122,     0,
      19,     0,    20,     0,    21,     0,    22,   241,     0,     0,
       0,     0,     0,     0,     1,     0,    23,     2,     3,   -24,
     207,   -24,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,    95,    96,    97,     0,     0,
       0,     0,    12,    13,    14,    15,     0,     0,     0,     0,
      16,    17,   107,   108,   109,   110,   111,   112,   113,   114,
       0,    18,     0,     0,    19,     0,    20,   287,    21,     0,
      22,     0,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   -49,     4,     5,     6,     7,     8,   -49,   -49,     0,
       0,    10,    11,     0,     0,    95,    96,    97,     0,     0,
       0,     0,    12,    13,    14,    15,     0,     0,     0,     0,
      16,    17,   107,   108,   109,   110,   111,   112,   113,   114,
       0,    18,     0,     0,    19,     0,    20,   292,    21,     0,
      22,     0,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   -50,     4,     5,     6,     7,     8,   -50,   -50,     0,
       0,    10,    11,     0,     0,    95,    96,    97,     0,     0,
       0,     0,    12,    13,    14,    15,     0,     0,     0,     0,
      16,    17,   107,   108,   109,   110,   111,   112,   113,   114,
       0,    18,     0,     0,    19,     0,    20,   324,    21,     0,
      22,     0,     0,     0,     1,     0,     0,     2,     3,   -26,
      23,   -26,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,    95,    96,    97,     0,     0,
       0,     0,    12,    13,    14,    15,     0,     0,     0,     0,
      16,    17,   107,   108,   109,   110,   111,   112,   113,   114,
       0,    18,     0,     0,    19,     0,    20,   341,    21,     0,
      22,     0,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   211,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,     0,    95,    96,    97,     0,
       0,     0,    12,    13,    14,    15,     0,     0,     0,     0,
      16,    17,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    18,     0,     0,    19,     0,    20,     0,    21,     0,
      22,     0,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   215,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,     0,    95,    96,    97,     0,
       0,     0,    12,    13,    14,    15,     0,     0,     0,     0,
      16,    17,   236,   107,   108,   109,   110,   111,   112,   113,
     114,    18,     0,     0,    19,     0,    20,     0,    21,     0,
      22,     0,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   245,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,     0,     0,     0,     0,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,    19,     0,    20,     0,    21,     0,
      22,     0,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   246,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,     0,     0,     0,     0,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,    19,     0,    20,     0,    21,     0,
      22,     0,     0,     1,     0,     0,     2,     3,     0,     0,
      23,     4,     5,     6,     7,     8,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    13,    14,    15,     0,     0,     0,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,   247,     0,    19,     0,    20,     0,    21,     0,    22,
       0,     0,     0,     1,     0,     0,     2,     3,     0,    23,
     273,     4,     5,     6,     7,     8,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    13,    14,    15,     0,     0,     0,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,    19,     0,    20,     0,    21,     0,    22,
       0,     0,     0,     1,     0,     0,     2,     3,     0,    23,
     276,     4,     5,     6,     7,     8,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    13,    14,    15,     0,     0,     0,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,    19,     0,    20,     0,    21,     0,    22,
       0,     0,     0,     1,     0,     0,     2,     3,     0,    23,
     296,     4,     5,     6,     7,     8,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    13,    14,    15,     0,     0,     0,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,    19,     0,    20,     0,    21,     0,    22,
       0,     0,     1,     0,     0,     2,     3,     0,     0,    23,
       4,     5,     6,     7,     8,     0,     0,  -148,     0,    10,
      11,  -148,     0,     0,     0,  -148,  -148,  -148,  -148,  -148,
      12,    13,    14,    15,  -148,  -148,     0,     0,    16,    17,
       0,     0,     0,     0,     0,  -148,  -148,  -148,  -148,    18,
       0,     0,    19,     0,    20,     0,    21,     0,    22,     0,
       0,     0,     0,     0,  -148,     0,    11,  -148,    23,  -148,
       0,  -148,     0,  -148,     0,     0,    12,    13,    36,    15,
       0,     0,     0,  -148,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,    11,    19,   140,
      37,     0,    21,     0,    22,     0,     0,    12,    13,    36,
      15,     0,     0,     0,    23,    16,    17,     0,     0,     0,
       0,     0,     0,     0,    11,     0,    18,   158,     0,    45,
       0,    37,   206,    21,    12,    13,    36,    15,     0,     0,
       0,     0,    16,    17,     0,    23,     0,     0,     0,     0,
       0,    11,     0,    18,   158,     0,    45,     0,    37,   224,
      21,    12,    13,    36,    15,     0,     0,     0,     0,    16,
      17,     0,    23,     0,     0,     0,     0,     0,     0,     0,
      18,     0,    11,    19,     0,    37,     0,    21,     0,    22,
       0,     0,    12,    13,    36,    15,     0,     0,     0,    23,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    18,     0,     0,    45,     0,    37,     0,    21,    72,
      12,    13,    14,    15,     0,     0,     0,     0,    16,    17,
      23,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,    11,    19,     0,    20,     0,    21,     0,    22,     0,
       0,    12,    13,    36,    15,     0,     0,     0,    23,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      18,     0,     0,    45,     0,    37,     0,    21,   144,    12,
      13,    36,    15,     0,     0,     0,     0,    16,    17,    23,
       0,     0,     0,     0,     0,     0,    11,     0,    18,     0,
       0,    45,   234,    37,     0,    21,    12,    13,    36,    15,
       0,     0,     0,     0,    16,    17,     0,    23,     0,     0,
       0,     0,     0,    11,     0,    18,   158,     0,    45,     0,
      37,     0,    21,    12,    13,    36,    15,     0,     0,     0,
       0,    16,    17,     0,    23,     0,     0,     0,     0,     0,
      11,     0,    18,     0,     0,    45,     0,    37,     0,    21,
      12,    13,    36,    15,     0,     0,     0,     0,    16,    17,
       0,    23,     0,     0,     0,     0,     0,    11,     0,    18,
       0,     0,    45,     0,    37,     0,   249,    12,    13,    14,
      15,     0,     0,     0,     0,    16,    17,     0,    23,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,    45,
       0,    20,     0,    21,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,     0,    23,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    95,    96,    97,     0,
     228,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,   318,     0,
       0,     0,     0,   240,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    95,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    95,    96,    97,    98,    99,   100,
     101,     0,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    95,
      96,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,     0,   109,   110,
     111,   112,   113,   114
};

static const yytype_int16 yycheck[] =
{
       0,    37,   252,     3,     4,    51,    27,    28,     8,    33,
      50,    49,    48,    42,    43,    44,    16,    17,    56,    19,
      27,    28,    22,    27,    28,    25,    51,    51,     8,    49,
      55,    52,    52,     0,    14,    15,     0,     4,    38,    68,
       4,     4,    42,    43,   320,    52,    31,    31,    52,    50,
      50,    51,    52,    54,   304,   305,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    51,   342,   343,    53,   115,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    49,    49,    50,    52,    49,    50,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   163,   118,    33,
     156,    49,   122,   123,   124,   125,   126,   127,    56,    49,
       0,     0,    52,    31,     4,     0,    56,    51,     0,     4,
      33,    55,     4,     0,    58,    59,    60,    61,    62,    63,
      64,    65,    21,     6,    33,     8,    25,    27,    28,    49,
      49,     0,    52,    52,    31,    58,    59,    60,    61,    38,
      63,    64,    51,    42,    43,    33,    55,     3,     4,    49,
      50,    50,    51,    51,    49,    50,    25,    49,    50,    23,
      24,    25,    26,    19,    49,    49,    22,    52,    52,    49,
      34,    35,    52,   249,    42,    43,    44,   207,    27,    28,
     210,    20,    21,    31,   214,    52,   216,    31,   218,   219,
     260,    56,   262,    33,    50,    51,    39,    40,   228,    33,
      39,    40,    41,    42,    43,    44,   236,   237,    27,    44,
     240,    33,   242,   243,    51,    33,   115,   247,   248,   118,
      33,   251,    55,   122,   123,   255,    33,   126,   127,    56,
      51,    87,    88,   263,    31,    31,    31,    49,    55,   269,
     270,   271,   272,    51,     6,   275,   102,   103,    51,   118,
     280,    52,    52,   283,   123,    33,    33,    56,   127,   115,
      33,    25,   161,   333,   163,     4,   207,   297,   298,   299,
     270,   161,    -1,    -1,    -1,    -1,    -1,   307,    -1,    42,
      43,    20,    21,    22,    -1,    -1,   316,    -1,    -1,   319,
     320,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,   336,   337,    20,    21,
      22,   210,   342,   343,   344,   214,    -1,   216,    -1,    -1,
     219,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,   210,    -1,   242,   243,   214,    -1,    -1,   247,   248,
     249,   207,   251,    -1,    66,    -1,   255,    -1,    -1,   122,
      -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   270,   271,   272,    -1,    -1,   275,    -1,    19,   248,
      -1,   280,   251,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    37,    38,   297,   298,
     299,   270,   271,   272,    -1,    -1,    -1,    48,    49,    -1,
      51,   280,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
     319,   320,    -1,    19,    20,    21,    67,    -1,    -1,   298,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   336,   337,    -1,
      -1,    37,    -1,   342,   343,    -1,    -1,    -1,    -1,    45,
     319,   320,    48,   216,    50,    51,   219,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,   342,   343,    -1,    20,    21,    22,   242,
     243,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   255,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,   275,    -1,    -1,    19,    20,    -1,    -1,   115,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    37,   297,    -1,   299,    -1,   134,    -1,
      -1,    45,    -1,    -1,    48,    -1,    50,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    -1,    -1,
     156,    -1,   158,    -1,    68,   161,    -1,   163,    -1,    -1,
      -1,    -1,    -1,   336,   337,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,    -1,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    12,    13,    -1,    -1,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,    29,
      30,    31,    32,   117,    -1,    -1,    -1,    37,    38,    -1,
      -1,    20,    21,    22,   128,    -1,    -1,    -1,    48,   225,
     134,    51,    -1,    53,   230,    55,   232,    57,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    67,    -1,    -1,
      -1,    -1,   156,   249,   158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   259,   260,    -1,   262,   263,    -1,    -1,
      -1,    -1,    -1,   269,    -1,     1,    -1,    -1,    -1,     5,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,   308,   309,   310,   311,   312,   313,    -1,    -1,
      -1,   225,    48,    -1,    -1,    51,   230,    53,   232,    55,
      -1,    57,    -1,    -1,    -1,    -1,   332,   333,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   259,   260,    -1,   262,   263,
      -1,    -1,    -1,     0,     1,   269,    -1,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    12,    13,    -1,    -1,    16,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,   308,   309,   310,   311,   312,   313,
      -1,    48,    -1,    -1,    51,    -1,    53,    -1,    55,    -1,
      57,    -1,     0,     1,    -1,    -1,     4,     5,   332,   333,
      67,     9,    10,    11,    12,    13,    -1,    -1,    16,    -1,
      18,    19,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      38,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      48,    -1,    -1,    51,    -1,    53,    -1,    55,    -1,    57,
      56,    -1,     1,    -1,    -1,     4,     5,    -1,    -1,    67,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      49,    -1,    51,    -1,    53,    -1,    55,    -1,    57,    -1,
      -1,     1,    -1,    -1,     4,     5,    -1,    -1,    67,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    -1,    53,    -1,    55,    -1,    57,    -1,    -1,
       1,    -1,    -1,     4,     5,    -1,    -1,    67,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    18,    19,    -1,
      -1,    20,    21,    22,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    37,    38,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    48,    49,    -1,
      51,    -1,    53,    -1,    55,    -1,    57,    56,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    67,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    20,    21,    22,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    38,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    48,    -1,    -1,    51,    -1,    53,    52,    55,    -1,
      57,    -1,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    18,    19,    -1,    -1,    20,    21,    22,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    38,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    48,    -1,    -1,    51,    -1,    53,    52,    55,    -1,
      57,    -1,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    18,    19,    -1,    -1,    20,    21,    22,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    38,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    48,    -1,    -1,    51,    -1,    53,    52,    55,    -1,
      57,    -1,    -1,    -1,     1,    -1,    -1,     4,     5,     6,
      67,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    20,    21,    22,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    38,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    48,    -1,    -1,    51,    -1,    53,    52,    55,    -1,
      57,    -1,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    20,    21,    22,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    38,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    48,    -1,    -1,    51,    -1,    53,    -1,    55,    -1,
      57,    -1,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    20,    21,    22,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    38,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    48,    -1,    -1,    51,    -1,    53,    -1,    55,    -1,
      57,    -1,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    53,    -1,    55,    -1,
      57,    -1,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    53,    -1,    55,    -1,
      57,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,    -1,
      67,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    -1,    51,    -1,    53,    -1,    55,    -1,    57,
      -1,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,    67,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    53,    -1,    55,    -1,    57,
      -1,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,    67,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    53,    -1,    55,    -1,    57,
      -1,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,    67,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    53,    -1,    55,    -1,    57,
      -1,    -1,     1,    -1,    -1,     4,     5,    -1,    -1,    67,
       9,    10,    11,    12,    13,    -1,    -1,     1,    -1,    18,
      19,     5,    -1,    -1,    -1,     9,    10,    11,    12,    13,
      29,    30,    31,    32,    18,    19,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    48,
      -1,    -1,    51,    -1,    53,    -1,    55,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    19,    51,    67,    53,
      -1,    55,    -1,    57,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    67,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    19,    51,    52,
      53,    -1,    55,    -1,    57,    -1,    -1,    29,    30,    31,
      32,    -1,    -1,    -1,    67,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    48,    49,    -1,    51,
      -1,    53,    54,    55,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    37,    38,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    48,    49,    -1,    51,    -1,    53,    54,
      55,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      38,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    19,    51,    -1,    53,    -1,    55,    -1,    57,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    67,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    48,    -1,    -1,    51,    -1,    53,    -1,    55,    56,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,    38,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    19,    51,    -1,    53,    -1,    55,    -1,    57,    -1,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    67,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      48,    -1,    -1,    51,    -1,    53,    -1,    55,    56,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    37,    38,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    48,    -1,
      -1,    51,    52,    53,    -1,    55,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    38,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    48,    49,    -1,    51,    -1,
      53,    -1,    55,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    37,    38,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    48,    -1,    -1,    51,    -1,    53,    -1,    55,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,    38,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    19,    -1,    48,
      -1,    -1,    51,    -1,    53,    -1,    55,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    37,    38,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    53,    -1,    55,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    67,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    20,    21,    22,    -1,
      66,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    66,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    -1,    -1,    39,    40,
      41,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     9,    10,    11,    12,    13,    16,
      18,    19,    29,    30,    31,    32,    37,    38,    48,    51,
      53,    55,    57,    67,    70,    71,    73,    74,    79,    80,
      82,    88,    90,    91,    92,     4,    31,    53,    77,    82,
      91,    92,    82,    91,    31,    51,    91,    31,    53,    51,
      33,    51,    55,    58,    59,    60,    61,    62,    63,    64,
      65,    91,    91,    82,    88,    89,    91,    86,    87,    88,
      89,    91,    56,    84,    85,    89,    92,    82,    91,    31,
       0,    74,     0,     4,    49,    50,    75,    27,    28,    23,
      24,    25,    26,    34,    35,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    51,    55,    87,    72,    73,
      75,    75,    49,    72,    37,    38,    49,    72,    33,     4,
      81,    33,    51,    55,    87,    31,    82,    89,    90,    92,
      52,    82,    85,    91,    56,    91,    89,    89,    89,    89,
      89,    89,    89,    89,    52,    52,    50,    54,    49,    54,
      89,    49,    56,    51,    82,    91,    82,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    88,    91,    88,
      91,    88,    91,    88,    91,    82,    91,    82,    91,    88,
      91,    88,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    82,    85,    91,    91,    54,     7,    73,    78,
      72,     8,    91,    91,    72,     8,    89,     8,    14,    15,
      31,    31,    83,    56,    54,    33,    52,    52,    66,    56,
      87,    89,    33,    84,    52,    85,    36,    68,    52,    52,
      66,    56,    77,     6,     8,     8,     8,    49,    72,    55,
      91,    72,    51,    55,    49,    52,    33,    33,    89,    33,
      33,    91,    33,    51,    89,    52,    91,    91,    91,    51,
      72,    72,    72,     8,    85,     4,     8,    83,    56,    31,
      72,    31,    31,    49,    89,    89,    90,    52,    89,    90,
      89,    91,    52,    89,    91,    78,     8,    56,    72,    52,
      55,     0,    17,    76,    51,    51,    91,    33,    58,    59,
      60,    61,    63,    64,    52,    52,    66,    52,    52,    72,
      72,    56,    83,    83,    52,    91,    89,    89,    89,    89,
      89,    89,    33,    33,    91,    76,    52,    52,    89,    89,
      90,    52,    72,    72,    33,    76,    76,    91
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
      case 30: /* "\"string\"" */

/* Line 1000 of yacc.c  */
#line 94 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", (yyvaluep->str));
#endif
  free((yyvaluep->str));
};

/* Line 1000 of yacc.c  */
#line 1857 "psycon.tab.c"
	break;
      case 31: /* "\"identifier\"" */

/* Line 1000 of yacc.c  */
#line 94 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", (yyvaluep->str));
#endif
  free((yyvaluep->str));
};

/* Line 1000 of yacc.c  */
#line 1871 "psycon.tab.c"
	break;
      case 71: /* "block_func" */

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
      case 72: /* "block" */

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
      case 73: /* "line" */

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
      case 74: /* "line_func" */

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
      case 77: /* "conditional" */

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
      case 78: /* "elseif_list" */

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
      case 79: /* "stmt" */

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
      case 80: /* "funcdef" */

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
      case 81: /* "case_list" */

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
      case 82: /* "condition" */

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
      case 83: /* "id_list" */

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
      case 84: /* "arg" */

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
      case 85: /* "arg_list" */

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
      case 86: /* "matrix" */

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
      case 87: /* "vector" */

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
      case 88: /* "range" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2095 "psycon.tab.c"
	break;
      case 89: /* "exp_range" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2109 "psycon.tab.c"
	break;
      case 90: /* "assign" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2123 "psycon.tab.c"
	break;
      case 91: /* "exp" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2137 "psycon.tab.c"
	break;
      case 92: /* "initcell" */

/* Line 1000 of yacc.c  */
#line 87 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2151 "psycon.tab.c"
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
#line 2312 "psycon.tab.c"

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
#line 193 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 195 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 205 "psycon.y"
    {	(yyval.pnode) = (yyvsp[(1) - (1)].pnode);	;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 207 "psycon.y"
    {	(yyval.pnode) = (yyvsp[(1) - (2)].pnode);	;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 209 "psycon.y"
    {	(yyval.pnode) = (yyvsp[(1) - (1)].pnode);	;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 211 "psycon.y"
    {	(yyval.pnode) = (yyvsp[(1) - (2)].pnode);	;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 215 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_IF, (yyloc));
	;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 219 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_IF, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode);
		(yyvsp[(2) - (4)].pnode)->alt = (yyvsp[(4) - (4)].pnode);
	;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 226 "psycon.y"
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

  case 27:

/* Line 1455 of yacc.c  */
#line 241 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 243 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 245 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 247 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 249 "psycon.y"
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
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 263 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (4)].pnode);
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode)->child;
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 271 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (6)].pnode);
		(yyvsp[(2) - (6)].pnode)->next = (yyvsp[(3) - (6)].pnode)->child;
		(yyvsp[(3) - (6)].pnode)->tail->next = (yyvsp[(5) - (6)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (6)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 280 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_WHILE, (yyloc));
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
	;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 286 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_WHILE, (yyloc));
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
	;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 292 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_WHILE, (yyloc));
		(yyvsp[(2) - (5)].pnode)->next = (yyvsp[(4) - (5)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (5)].pnode);
	;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 298 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_WHILE, (yyloc));
		(yyvsp[(2) - (5)].pnode)->next = (yyvsp[(4) - (5)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (5)].pnode);
	;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 304 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_FOR, (yyloc));
		(yyval.pnode)->child = newAstNode('=', (yylsp[(2) - (6)]));
		(yyval.pnode)->child->str = (yyvsp[(2) - (6)].str);
		(yyval.pnode)->child->child = (yyvsp[(4) - (6)].pnode);
		(yyval.pnode)->child->next = (yyvsp[(5) - (6)].pnode);
	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 312 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_FOR, (yyloc));
		(yyval.pnode)->child = newAstNode('=', (yylsp[(2) - (7)]));
		(yyval.pnode)->child->str = (yyvsp[(2) - (7)].str);
		(yyval.pnode)->child->child = (yyvsp[(4) - (7)].pnode);
		(yyval.pnode)->child->next = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 320 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_RETURN, (yyloc));
	;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 324 "psycon.y"
    { (yyval.pnode) = newAstNode(T_BREAK, (yyloc));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 326 "psycon.y"
    { (yyval.pnode) = newAstNode(T_CONTINUE, (yyloc));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 330 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(2) - (7)].str);
		(yyval.pnode)->child = (yyvsp[(4) - (7)].pnode);
		(yyvsp[(4) - (7)].pnode)->next = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 337 "psycon.y"
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

  case 45:

/* Line 1455 of yacc.c  */
#line 347 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(6) - (11)].str);
		(yyval.pnode)->child = (yyvsp[(8) - (11)].pnode);
		(yyvsp[(8) - (11)].pnode)->next = (yyvsp[(10) - (11)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (11)].pnode);

		;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 356 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(6) - (11)].str);
		(yyval.pnode)->child = (yyvsp[(8) - (11)].pnode);
		(yyvsp[(8) - (11)].pnode)->next = (yyvsp[(10) - (11)].pnode);
		(yyvsp[(10) - (11)].pnode)->next = newAstNode(NODE_INITCELL, (yylsp[(2) - (11)]));
		(yyvsp[(10) - (11)].pnode)->next->str = (yyvsp[(2) - (11)].str);
	;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 367 "psycon.y"
    { (yyval.pnode) = newAstNode(T_SWITCH, (yyloc));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 369 "psycon.y"
    { (yyval.pnode) = newAstNode(T_SWITCH, (yyloc));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 371 "psycon.y"
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

  case 50:

/* Line 1455 of yacc.c  */
#line 381 "psycon.y"
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

  case 51:

/* Line 1455 of yacc.c  */
#line 393 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('<', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 395 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('<', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 397 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('<', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 399 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('>', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 401 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('>', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 403 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('>', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 405 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_EQ, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 407 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_EQ, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 409 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_EQ, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 411 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_NE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 413 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_NE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 415 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_NE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 417 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_GE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 419 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_GE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 421 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_GE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 423 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_LE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 425 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_LE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 427 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_LE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 429 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 435 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_LOGIC_NOT, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (2)].pnode);
	;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 440 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_LOGIC_NOT, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (2)].pnode);
	;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 445 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 447 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 449 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 451 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 453 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 455 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 457 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 459 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 463 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
	;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 467 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->tail = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->tail->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 473 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->tail = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->tail->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 479 "psycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->tail = (yyvsp[(1) - (3)].pnode)->tail->next = newAstNode(T_ID, (yylsp[(3) - (3)]));
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
		(yyval.pnode)->tail->str = (yyvsp[(3) - (3)].str);
	;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 485 "psycon.y"
    {
		(yyvsp[(1) - (5)].pnode)->tail = (yyvsp[(1) - (5)].pnode)->tail->next = newAstNode(NODE_INITCELL, (yylsp[(3) - (5)]));
		(yyval.pnode) = (yyvsp[(1) - (5)].pnode);
		(yyval.pnode)->tail->str = (yyvsp[(3) - (5)].str);
	;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 493 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 495 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 499 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_ARGS, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->tail = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 504 "psycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->tail = (yyvsp[(1) - (3)].pnode)->tail->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 511 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_MATRIX, (yyloc));
	;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 515 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_MATRIX, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->tail = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 520 "psycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->tail = (yyvsp[(1) - (3)].pnode)->tail->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 527 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_VECTOR, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->tail = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 532 "psycon.y"
    {
		(yyvsp[(1) - (2)].pnode)->tail = (yyvsp[(1) - (2)].pnode)->tail->next = (yyvsp[(2) - (2)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (2)].pnode);
	;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 537 "psycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->tail = (yyvsp[(1) - (3)].pnode)->tail->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 544 "psycon.y"
    {
		(yyval.pnode) = makeFunctionCall(":", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));
	;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 548 "psycon.y"
    {
		(yyval.pnode) = makeFunctionCall(":", (yyvsp[(1) - (5)].pnode), (yyvsp[(5) - (5)].pnode), (yyloc));
		(yyval.pnode)->tail = (yyvsp[(5) - (5)].pnode)->next = (yyvsp[(3) - (5)].pnode);
	;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 555 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 557 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 561 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 567 "psycon.y"
    { // Only to be used when RHS is a UDF. 5/18/2017 bjkwon
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->child = (yyvsp[(5) - (5)].pnode);
		(yyval.pnode)->alt = (yyvsp[(2) - (5)].pnode);
	;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 573 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 579 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('+', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 585 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('-', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 591 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('*', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 597 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('/', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 603 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNodeFunctionCall('^', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 609 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('@', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 615 "psycon.y"
    { 
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str); 
		(yyval.pnode)->child = makeCompoundLevelOpNode((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(1) - (3)]), (yylsp[(3) - (3)]));
	;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 621 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode(T_OP_CONCAT, (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 627 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 634 "psycon.y"
    {
		(yyval.pnode) = Restring("+=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 638 "psycon.y"
    {
		(yyval.pnode) = Restring("-=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 642 "psycon.y"
    {
		(yyval.pnode) = Restring("*=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 646 "psycon.y"
    {
		(yyval.pnode) = Restring("/=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 650 "psycon.y"
    {
		(yyval.pnode) = Restring("@=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 654 "psycon.y"
    {
		(yyval.pnode) = Restring("@@=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 658 "psycon.y"
    { /* x(45)=723 or x(id1:id2) = id1:id2  or x(array) = scalar */
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 665 "psycon.y"
    { /* x(x>0) = scalar */
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 672 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (8)].str);
		(yyval.pnode)->child = (yyvsp[(8) - (8)].pnode);
		(yyval.pnode)->alt = newAstNode(NODE_IDLIST, (yyloc));
		(yyval.pnode)->alt->child = (yyvsp[(5) - (8)].pnode);
		(yyval.pnode)->alt->tail = (yyvsp[(3) - (8)].pnode);
	;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 681 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (11)].str);
		(yyval.pnode)->child = (yyvsp[(11) - (11)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (11)].pnode);
		(yyvsp[(3) - (11)].pnode)->alt = newAstNode(NODE_IDLIST, (yyloc));
		(yyvsp[(3) - (11)].pnode)->alt->child = (yyvsp[(8) - (11)].pnode);
		(yyvsp[(3) - (11)].pnode)->alt->tail = (yyvsp[(6) - (11)].pnode);
	;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 692 "psycon.y"
    { // v{2}(4)=1 
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(9) - (9)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (9)].pnode);
		(yyvsp[(3) - (9)].pnode)->next = (yyvsp[(6) - (9)].pnode);
	;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 700 "psycon.y"
    { // v{2}(4:6)=1 
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(9) - (9)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (9)].pnode);
		(yyvsp[(3) - (9)].pnode)->next = (yyvsp[(6) - (9)].pnode);
	;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 708 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 714 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(6) - (6)].pnode)->alt = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 721 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(6) - (6)].pnode)->alt = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 728 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(9) - (9)].pnode);
		(yyvsp[(9) - (9)].pnode)->alt = (yyvsp[(6) - (9)].pnode);
		(yyvsp[(6) - (9)].pnode)->alt = (yyvsp[(3) - (9)].pnode);
	;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 736 "psycon.y"
    { // x={"bjk",noise(300), 4.5555}
		(yyval.pnode) = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 745 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_NUMBER, (yyloc));
		(yyval.pnode)->dval = (yyvsp[(1) - (1)].dval);
	;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 750 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_STRING, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 755 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ENDPOINT, (yyloc));
		(yyval.pnode)->str = NULL;
	;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 760 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 764 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 769 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (4)].pnode);
	;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 775 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (7)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (7)].pnode);
		(yyvsp[(3) - (7)].pnode)->alt = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 782 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (7)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (7)].pnode);
		(yyvsp[(3) - (7)].pnode)->alt = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 789 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
	;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 793 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 798 "psycon.y"
    { // I don't know what this is doing.... bjk 3/28/2017 
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 803 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->type = NODE_CALL;
 		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 811 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->tail = (yyvsp[(3) - (4)].pnode); // leaving a mark for conditional indexing 3/28/2017 bjk
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 820 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = malloc(strlen((yyvsp[(2) - (4)].str))+2);
 		(yyval.pnode)->str[0] = '#';
 		strcpy((yyval.pnode)->str+1, (yyvsp[(2) - (4)].str));
 		free((yyvsp[(2) - (4)].str));
	;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 828 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(4) - (5)].pnode);
		(yyval.pnode)->type = NODE_CALL;
 		(yyval.pnode)->str = malloc(strlen((yyvsp[(2) - (5)].str))+2);
 		(yyval.pnode)->str[0] = '#';
 		strcpy((yyval.pnode)->str+1, (yyvsp[(2) - (5)].str));
 		free((yyvsp[(2) - (5)].str));
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 839 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_EXTRACT, (yyloc));
		(yyval.pnode)->child = newAstNode(T_ID, (yylsp[(1) - (6)]));
		(yyval.pnode)->child->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child->next = (yyvsp[(3) - (6)].pnode);
		(yyvsp[(3) - (6)].pnode)->next = (yyvsp[(5) - (6)].pnode);
	;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 847 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_NEGATIVE, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (2)].pnode);
	;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 852 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (2)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 858 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 864 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_SIGMA, (yyloc));
		(yyval.pnode)->child = newAstNode('=', (yylsp[(3) - (8)]));
		(yyval.pnode)->child->str = (yyvsp[(3) - (8)].str);
		(yyval.pnode)->child->child = (yyvsp[(5) - (8)].pnode);
		(yyval.pnode)->child->next = (yyvsp[(7) - (8)].pnode);
	;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 872 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('+', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 874 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('-', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 876 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('*', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 878 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('/', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 880 "psycon.y"
    { (yyval.pnode) = makeFunctionCall("^", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 882 "psycon.y"
    { (yyval.pnode) = makeFunctionCall("caret", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 884 "psycon.y"
    { (yyval.pnode) = makeFunctionCall("shift_spectrum", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 886 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('@', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 888 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INTERPOL, (yyloc));
		(yyval.pnode)->child = (yyvsp[(1) - (5)].pnode);
		(yyvsp[(1) - (5)].pnode)->next = (yyvsp[(3) - (5)].pnode);
		(yyvsp[(3) - (5)].pnode)->next = (yyvsp[(5) - (5)].pnode);
		(yyval.pnode)->tail = (yyvsp[(5) - (5)].pnode);
	;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 896 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_SHIFT, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 898 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_SHIFT2, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 900 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_CONCAT, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 902 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 908 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 914 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_REPLICA, (yyloc));
		(yyval.pnode)->str = NULL;
	;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 921 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->type = NODE_INITCELL;
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;



/* Line 1455 of yacc.c  */
#line 4041 "psycon.tab.c"
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
#line 929 "psycon.y"


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

