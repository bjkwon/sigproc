
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
#line 2 "cipsycon.y"

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
#line 88 "cipsycon.tab.c"

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
     T_NEGATIVE = 287,
     T_POSITIVE = 288,
     T_LOGIC_NOT = 289,
     T_USEC = 290,
     T_MSEC = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 23 "cipsycon.y"

	double dval;
	char *str;
	AstNode *pnode;



/* Line 214 of yacc.c  */
#line 169 "cipsycon.tab.c"
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
#line 103 "cipsycon.y"

AstNode *newAstNode(int type, YYLTYPE loc);
AstNode *makeFunctionCall(char *name, AstNode *first, AstNode *second, YYLTYPE loc);
AstNode *makeBinaryOpNode(int op, AstNode *first, AstNode *second, YYLTYPE loc);
void print_token_value(FILE *file, int type, YYSTYPE value);


/* Line 264 of yacc.c  */
#line 202 "cipsycon.tab.c"

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
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1399

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNRULES -- Number of states.  */
#define YYNSTATES  270

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    57,     2,    38,     2,     2,
      50,    51,    40,    37,    48,    36,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    49,
      33,    32,    34,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,    58,    53,    56,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    43,    44,    45,
      46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    16,    18,
      21,    24,    26,    28,    30,    32,    34,    36,    37,    39,
      41,    43,    46,    49,    51,    53,    55,    61,    69,    74,
      81,    86,    93,    95,    97,    99,   110,   123,   138,   155,
     163,   173,   185,   197,   198,   203,   204,   206,   212,   219,
     223,   227,   231,   235,   239,   243,   247,   250,   254,   258,
     259,   261,   265,   269,   275,   277,   279,   281,   285,   286,
     288,   292,   294,   297,   301,   305,   311,   313,   315,   319,
     326,   333,   343,   347,   354,   361,   371,   375,   384,   393,
     395,   397,   399,   404,   412,   416,   420,   425,   430,   436,
     443,   446,   449,   453,   462,   466,   470,   474,   478,   482,
     486,   490,   496,   500,   504,   508,   512,   516
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    -1,    61,    -1,    64,    -1,    61,    64,
      -1,    63,    -1,    62,    63,    -1,     4,    -1,     1,     4,
      -1,    68,    65,    -1,    63,    -1,    69,    -1,    48,    -1,
      49,    -1,     4,    -1,     0,    -1,    -1,    17,    -1,     0,
      -1,    81,    -1,    81,    47,    -1,    81,    46,    -1,    81,
      -1,    80,    -1,    72,    -1,     5,    72,    62,    70,     8,
      -1,     5,    72,    62,    70,     6,    62,     8,    -1,    13,
      81,    71,     8,    -1,    13,    81,    71,    15,    62,     8,
      -1,     9,    72,    62,     8,    -1,    10,    31,    32,    79,
      62,     8,    -1,    18,    -1,    11,    -1,    12,    -1,    50,
      81,    48,    81,    51,    67,    48,    81,    48,    81,    -1,
      50,    81,    48,    81,    51,    67,    48,    81,    48,    81,
      48,    67,    -1,    50,    81,    48,    81,    51,    67,    48,
      81,    48,    81,    48,    81,    48,    81,    -1,    50,    81,
      48,    81,    51,    67,    48,    81,    48,    81,    48,    81,
      48,    81,    48,    67,    -1,    16,    31,    50,    73,    51,
      62,    66,    -1,    16,    31,    32,    31,    50,    73,    51,
      62,    66,    -1,    16,    31,    52,    53,    32,    31,    50,
      73,    51,    62,    66,    -1,    16,    54,    77,    55,    32,
      31,    50,    73,    51,    62,    66,    -1,    -1,    70,     7,
      72,    62,    -1,    -1,     4,    -1,    71,    14,    81,     4,
      62,    -1,    71,    14,    52,    75,    53,    62,    -1,    81,
      33,    81,    -1,    81,    34,    81,    -1,    81,    23,    81,
      -1,    81,    24,    81,    -1,    81,    25,    81,    -1,    81,
      26,    81,    -1,    50,    72,    51,    -1,    56,    72,    -1,
      72,    27,    72,    -1,    72,    28,    72,    -1,    -1,    31,
      -1,    31,    52,    53,    -1,    73,    48,    31,    -1,    73,
      48,    31,    52,    53,    -1,    79,    -1,    82,    -1,    74,
      -1,    75,    48,    74,    -1,    -1,    77,    -1,    76,    49,
      77,    -1,    79,    -1,    77,    79,    -1,    77,    48,    79,
      -1,    81,    35,    81,    -1,    81,    35,    81,    35,    81,
      -1,    81,    -1,    78,    -1,    31,    32,    79,    -1,    31,
      52,    81,    53,    32,    79,    -1,    31,    50,    75,    51,
      32,    79,    -1,    31,    52,    81,    53,    50,    81,    51,
      32,    79,    -1,    31,    32,    80,    -1,    31,    52,    81,
      53,    32,    80,    -1,    31,    50,    75,    51,    32,    80,
      -1,    31,    52,    81,    53,    50,    81,    51,    32,    80,
      -1,    31,    32,    82,    -1,    31,    52,    53,    32,    31,
      50,    75,    51,    -1,    54,    77,    55,    32,    31,    50,
      75,    51,    -1,    29,    -1,    30,    -1,    31,    -1,    31,
      52,    81,    53,    -1,    31,    52,    81,    53,    50,    81,
      51,    -1,    31,    52,    53,    -1,    31,    50,    51,    -1,
      31,    50,    75,    51,    -1,    57,    31,    50,    51,    -1,
      57,    31,    50,    75,    51,    -1,    31,    50,    81,    56,
      81,    51,    -1,    36,    81,    -1,    37,    81,    -1,    50,
      79,    51,    -1,    19,    50,    31,    32,    79,    48,    81,
      51,    -1,    81,    37,    81,    -1,    81,    36,    81,    -1,
      81,    40,    81,    -1,    81,    41,    81,    -1,    81,    42,
      81,    -1,    81,    38,    81,    -1,    81,    39,    81,    -1,
      81,    39,    81,    58,    81,    -1,    81,    20,    81,    -1,
      81,    21,    81,    -1,    81,    22,    81,    -1,    54,    76,
      55,    -1,    54,    77,    55,    -1,    52,    75,    53,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   112,   112,   113,   117,   119,   137,   144,   165,   167,
     172,   176,   178,   182,   182,   182,   182,   185,   185,   185,
     188,   190,   195,   202,   204,   206,   208,   217,   230,   238,
     247,   253,   261,   265,   267,   269,   278,   288,   299,   313,
     320,   329,   338,   349,   350,   363,   364,   366,   376,   388,
     390,   392,   394,   396,   398,   400,   406,   411,   413,   418,
     421,   427,   433,   439,   447,   449,   453,   458,   466,   469,
     474,   481,   486,   491,   498,   502,   509,   511,   515,   521,
     528,   535,   543,   549,   556,   563,   571,   578,   586,   595,
     600,   605,   610,   616,   623,   628,   633,   641,   649,   660,
     668,   673,   679,   685,   693,   695,   697,   699,   701,   703,
     705,   707,   715,   717,   719,   721,   727,   735
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
  "\"string\"", "\"identifier\"", "'='", "'<'", "'>'", "':'", "'-'", "'+'",
  "'%'", "'@'", "'*'", "'/'", "'^'", "T_NEGATIVE", "T_POSITIVE",
  "T_LOGIC_NOT", "\"us\"", "\"ms\"", "','", "';'", "'('", "')'", "'{'",
  "'}'", "'['", "']'", "'~'", "'#'", "'|'", "$accept", "input",
  "block_func", "block", "line", "line_func", "eol", "func_end",
  "exp_time", "stmt", "funcdef", "elseif_list", "case_list", "condition",
  "id_list", "arg", "arg_list", "matrix", "vector", "range", "exp_range",
  "assign", "exp", "initcell", 0
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
     285,   286,    61,    60,    62,    58,    45,    43,    37,    64,
      42,    47,    94,   287,   288,   289,   290,   291,    44,    59,
      40,    41,   123,   125,    91,    93,   126,    35,   124
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      63,    64,    64,    65,    65,    65,    65,    66,    66,    66,
      67,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    69,    69,    70,    70,    71,    71,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    77,    78,    78,    79,    79,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       1,     2,     2,     1,     1,     1,     5,     7,     4,     6,
       4,     6,     1,     1,     1,    10,    12,    14,    16,     7,
       9,    11,    11,     0,     4,     0,     1,     5,     6,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     0,
       1,     3,     3,     5,     1,     1,     1,     3,     0,     1,
       3,     1,     2,     3,     3,     5,     1,     1,     3,     6,
       6,     9,     3,     6,     6,     9,     3,     8,     8,     1,
       1,     1,     4,     7,     3,     3,     4,     4,     5,     6,
       2,     2,     3,     8,     3,     3,     3,     3,     3,     3,
       3,     5,     3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     8,     0,     0,     0,    33,    34,     0,     0,
      32,     0,    89,    90,    91,     0,     0,     0,    68,     0,
       0,     0,     0,    11,     4,     0,    12,    25,    24,    23,
       9,    91,     0,    68,     0,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,   100,   101,     0,    77,
       0,    76,     0,    69,    71,    76,    56,     0,     1,     5,
      16,    15,    13,    14,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    69,     0,     6,     0,
       0,    46,     0,     0,    59,     0,     0,     0,     0,    78,
      82,    86,    95,    66,     0,    64,    76,    65,    94,     0,
      55,   102,     0,     0,     0,   115,     0,   116,    72,     0,
      57,    58,   112,   113,   114,    51,    52,    53,    54,    49,
      50,   105,   104,   109,   110,   106,   107,   108,     0,    94,
       0,   116,     7,     0,    30,     0,    28,     0,     0,     0,
      60,     0,     0,     0,     0,     0,     0,    96,     0,     0,
      92,    74,     0,    70,    73,     0,    97,     0,     0,    96,
      92,     0,     0,    26,     0,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,   117,    67,     0,     0,     0,
       0,     0,     0,     0,     0,    98,   111,     0,     0,     0,
      31,     0,     0,    29,     0,    61,    62,     0,     0,     0,
       0,    80,    84,    99,     0,    79,    83,     0,    75,     0,
      20,     0,     0,    27,     0,     0,     0,     0,     0,    19,
      18,    39,    59,    59,     0,     0,    93,     0,    22,    21,
       0,    93,     0,     0,    63,     0,     0,   103,    87,     0,
       0,    88,    40,     0,     0,    81,    85,     0,     0,     0,
      35,    41,    42,     0,    36,    20,     0,    37,     0,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    22,    87,    88,    24,    64,   231,   219,    25,
      26,   143,    92,    27,   151,   103,   104,    52,    53,    49,
     105,    28,    29,   107
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -175
static const yytype_int16 yypact[] =
{
     353,    13,  -175,   864,   864,     2,  -175,  -175,   982,   -10,
    -175,   -24,  -175,  -175,    -4,   982,   982,   864,   982,   864,
       3,    53,   411,  -175,  -175,     6,  -175,   120,  -175,  1319,
    -175,    56,   864,   982,   581,  1319,   581,    57,   982,   339,
      -1,   982,    61,   190,   760,   879,  -175,  -175,   -19,  -175,
      64,  1173,    41,   790,  -175,  1327,  -175,    93,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,   864,   864,   982,   982,   982,
     982,   982,   982,   982,   982,   982,   982,   982,   982,   982,
     982,   982,   982,   760,   894,  1296,   805,   445,  -175,   615,
     982,  -175,    86,   104,   106,    88,   820,   118,   909,  -175,
    -175,  -175,  -175,  -175,     9,  -175,  1020,  -175,   122,  1028,
    -175,  -175,   982,   982,   982,  -175,   982,   127,  -175,   835,
    -175,   125,   116,   116,   277,  1357,  1357,  1357,  1357,  1357,
    1357,   277,   277,   116,   -22,   124,   124,   124,    40,  -175,
    1051,  -175,  -175,   155,  -175,   751,  -175,   938,   751,   114,
     115,    70,   136,   138,   982,     8,   909,   139,   982,   143,
      -5,  1350,  1058,   967,  -175,   144,  -175,    75,   982,  -175,
     126,   751,   864,  -175,   649,   909,   397,   683,   106,   128,
     147,   751,   148,   149,   134,  -175,  -175,   997,  1081,   135,
     997,   982,   982,   982,   141,  -175,  1357,   982,   717,   581,
    -175,    54,   751,  -175,    76,  -175,   145,   295,   146,   150,
     982,  -175,  -175,  -175,   909,  -175,  -175,  1104,  1357,   156,
    1268,   909,  1127,  -175,   479,   751,   513,   751,   133,  -175,
    -175,  -175,   106,   106,  1150,    81,   161,   982,  -175,  -175,
      83,  -175,   547,   295,  -175,    85,    91,  -175,  -175,   997,
    1209,  -175,  -175,   751,   751,  -175,  -175,   982,   295,   295,
    1232,  -175,  -175,   982,  -175,  1196,   982,  1245,   982,  -175
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,  -175,  -175,    67,    25,   173,  -175,  -161,  -146,  -175,
    -175,  -175,  -175,    20,  -174,    42,   -76,  -175,   -30,  -175,
      87,   -41,    -3,   162
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -49
static const yytype_int16 yytable[] =
{
      35,    35,   100,    86,   204,    39,    60,   138,    65,    66,
      61,    96,    46,    47,    51,    55,    35,    30,    80,    81,
      82,    40,   155,    34,    36,    23,    42,   190,    43,    85,
      55,    93,   110,    37,    57,    55,   168,    48,    55,    56,
      55,   106,   109,   167,    41,   191,    44,    23,    45,    94,
      55,    95,    48,    58,    62,    63,   156,   156,   245,   246,
     157,   185,    35,    35,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     106,   140,   252,    55,   163,   120,   121,    55,   156,    90,
     114,   169,    97,    55,   146,    55,   115,   261,   262,   201,
     147,   148,   156,    89,    50,    54,    83,   225,    84,   161,
     162,    55,   142,    55,   142,   111,    55,   264,   180,    50,
      54,   181,   269,   156,   180,    50,   195,   227,    54,   156,
      99,   156,   248,   180,   251,   149,   253,   150,   235,   180,
     118,   152,   254,   119,   176,   240,   212,    65,    66,   216,
     154,    55,    65,    55,   159,   188,    80,    81,    82,   165,
      55,   171,   172,   173,   178,   196,    82,   179,   182,    35,
     183,   187,    55,   118,   189,   194,   197,   145,   206,   208,
     209,   205,   210,   118,    55,   214,   244,    55,   217,   218,
     220,   221,   199,   249,   222,    59,   232,   228,   186,   142,
     233,    54,   142,   164,   237,   101,     0,   234,   256,    11,
       0,    55,   174,     0,     0,   177,     0,     0,    55,    12,
      13,    14,     0,   142,     0,     0,    15,    16,     0,     0,
       0,     0,   142,     0,   250,     0,     0,     0,   198,     0,
      38,   184,    98,     0,    18,     0,    55,    20,   207,   142,
     118,   142,     0,     0,   260,     0,     0,     0,     0,     0,
     265,     0,     0,   267,     0,   220,   224,   142,   142,   226,
       0,     0,     0,     0,   211,     0,     0,   215,     0,     0,
       0,     0,     0,   142,   142,     0,     0,     0,     0,     0,
       0,     0,   242,     0,   243,   229,     1,    67,    68,     2,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     0,
       0,   -17,   230,    10,    11,    78,    79,    80,    81,    82,
     258,   259,     0,     0,    12,    13,    14,     0,     0,     0,
       0,    15,    16,     0,     0,     0,   255,     0,     0,     0,
       0,     0,     0,    91,     0,    17,     0,     0,     0,    18,
       0,    19,    20,    -2,     1,     0,     0,     2,     3,    67,
      68,    69,     4,     5,     6,     7,     8,     0,     0,     9,
       0,    10,    11,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    12,    13,    14,     0,     0,     0,     0,    15,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   202,     0,    17,     0,     0,     0,    18,     0,    19,
      20,    -3,     1,     0,     0,     2,     3,    67,    68,    69,
       4,     5,     6,     7,     8,     0,     0,     9,     0,    10,
      11,     0,     0,    76,    77,    78,    79,    80,    81,    82,
      12,    13,    14,     0,     0,     0,     1,    15,    16,     2,
       3,   -43,   -43,   -43,     4,     5,     6,     7,     8,     0,
       0,    17,     0,    10,    11,    18,     0,    19,    20,     0,
       0,     0,     0,     0,    12,    13,    14,     0,     0,     0,
       1,    15,    16,     2,     3,   -44,   -44,   -44,     4,     5,
       6,     7,     8,     0,     0,    17,     0,    10,    11,    18,
       0,    19,    20,     0,     0,     0,     0,     0,    12,    13,
      14,     0,     0,     0,     1,    15,    16,     2,     3,     0,
       0,   -47,     4,     5,     6,     7,     8,   -47,   -47,    17,
       0,    10,    11,    18,     0,    19,    20,     0,     0,     0,
       0,     0,    12,    13,    14,     0,     0,     0,     1,    15,
      16,     2,     3,     0,     0,   -48,     4,     5,     6,     7,
       8,   -48,   -48,    17,     0,    10,    11,    18,     0,    19,
      20,     0,     0,     0,     0,     0,    12,    13,    14,     0,
       0,     0,     1,    15,    16,     2,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     0,     0,    17,     0,    10,
      11,    18,     0,    19,    20,     0,     0,     0,    65,    66,
      12,    13,    14,     0,     0,     0,     1,    15,    16,     2,
       3,     0,     0,   144,     4,     5,     6,     7,     8,     0,
       0,    17,     0,    10,    11,    18,     0,    19,    20,     0,
       0,     0,     0,     0,    12,    13,    14,     0,     0,     0,
       1,    15,    16,     2,     3,     0,     0,   200,     4,     5,
       6,     7,     8,     0,     0,    17,     0,    10,    11,    18,
       0,    19,    20,     0,     0,     0,     0,     0,    12,    13,
      14,     0,     0,     0,     1,    15,    16,     2,     3,     0,
       0,   203,     4,     5,     6,     7,     8,     0,     0,    17,
       0,    10,    11,    18,     0,    19,    20,     0,     0,     0,
       0,     0,    12,    13,    14,     0,     0,     0,     1,    15,
      16,     2,     3,     0,     0,   223,     4,     5,     6,     7,
       8,     0,     0,    17,     0,    10,    11,    18,     0,    19,
      20,     0,     0,     0,     0,     0,    12,    13,    14,     0,
       0,     0,     1,    15,    16,     2,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     0,     0,    17,     0,    10,
      11,    18,     0,    19,    20,     0,     0,     0,     0,    11,
      12,    13,    14,     0,     0,     0,     0,    15,    16,    12,
      13,    31,     0,     0,     0,     0,    15,    16,     0,     0,
       0,    17,     0,     0,     0,    18,     0,    19,    20,    11,
      38,   102,    98,     0,    33,     0,     0,    20,     0,    12,
      13,    31,     0,     0,    11,     0,    15,    16,     0,     0,
       0,     0,     0,     0,    12,    13,    31,     0,   116,    11,
      38,    15,    16,     0,    33,   117,     0,    20,     0,    12,
      13,    31,     0,   116,    11,    38,    15,    16,     0,    33,
     141,     0,    20,     0,    12,    13,    31,     0,   116,     0,
      38,    15,    16,     0,    33,   153,     0,    20,     0,     0,
       0,     0,     0,    11,     0,    38,   166,    98,     0,    33,
       0,     0,    20,    12,    13,    31,     0,     0,    11,     0,
      15,    16,     0,     0,     0,     0,     0,     0,    12,    13,
      31,     0,     0,    11,    32,    15,    16,     0,    33,     0,
      19,    20,     0,    12,    13,    31,     0,     0,    11,    38,
      15,    16,   108,    33,     0,     0,    20,     0,    12,    13,
      31,     0,     0,     0,    38,    15,    16,   139,    33,     0,
       0,    20,     0,     0,     0,     0,     0,    11,     0,    38,
       0,    98,     0,    33,     0,     0,    20,    12,    13,    31,
       0,     0,     0,     0,    15,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,    38,     0,
     175,     0,    33,     0,     0,    20,    12,    13,    31,     0,
       0,    11,     0,    15,    16,     0,     0,     0,     0,     0,
       0,    12,    13,    31,     0,   116,    11,    38,    15,    16,
       0,    33,     0,     0,    20,     0,    12,    13,    14,     0,
       0,     0,    38,    15,    16,     0,    33,     0,     0,    20,
      67,    68,    69,     0,     0,     0,     0,    38,    67,    68,
      69,    18,     0,     0,    20,   112,    76,    77,    78,    79,
      80,    81,    82,     0,    76,    77,    78,    79,    80,    81,
      82,    67,    68,    69,     0,     0,   158,     0,    67,    68,
      69,   160,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    76,    77,    78,    79,    80,    81,
      82,    67,    68,    69,   170,     0,     0,     0,     0,   193,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    67,    68,    69,     0,     0,     0,
       0,     0,   213,     0,     0,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    67,    68,    69,
       0,     0,     0,     0,     0,   236,     0,     0,     0,     0,
       0,     0,     0,    76,    77,    78,    79,    80,    81,    82,
      67,    68,    69,     0,     0,     0,     0,     0,   241,     0,
       0,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    67,    68,    69,    70,    71,    72,    73,
       0,   247,     0,     0,     0,     0,    74,    75,   112,    76,
      77,    78,    79,    80,    81,    82,    67,    68,    69,     0,
       0,   113,     0,     0,     0,     0,     0,     0,     0,    67,
      68,    69,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,   238,   239,   266,    76,    77,    78,    79,    80,
      81,    82,    67,    68,    69,     0,     0,   257,     0,     0,
       0,     0,     0,     0,     0,    67,    68,    69,    76,    77,
      78,    79,    80,    81,    82,     0,     0,     0,     0,     0,
     263,    76,    77,    78,    79,    80,    81,    82,    67,    68,
      69,     0,     0,   268,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,    77,    78,    79,    80,    81,
      82,     0,     0,     0,   238,   239,    67,    68,    69,    70,
      71,    72,    73,     0,     0,     0,     0,     0,     0,    74,
      75,   112,    76,    77,    78,    79,    80,    81,    82,    67,
      68,    69,    70,    71,    72,    73,     0,    67,    68,    69,
       0,     0,    74,    75,     0,    76,    77,    78,    79,    80,
      81,    82,   112,    76,    77,    78,    79,    80,    81,    82,
      67,    68,    69,     0,     0,     0,     0,    67,    68,    69,
       0,     0,     0,     0,     0,   192,    76,    77,    78,    79,
      80,    81,    82,    76,    77,    78,    79,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
       3,     4,    43,    33,   178,     8,     0,    83,    27,    28,
       4,    41,    15,    16,    17,    18,    19,     4,    40,    41,
      42,    31,    98,     3,     4,     0,    50,    32,    32,    32,
      33,    32,    51,    31,    31,    38,    58,    17,    41,    19,
      43,    44,    45,   119,    54,    50,    50,    22,    52,    50,
      53,    52,    32,     0,    48,    49,    48,    48,   232,   233,
      51,    53,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,   243,    86,   114,    65,    66,    90,    48,    32,
      49,    51,    31,    96,     8,    98,    55,   258,   259,   175,
      14,    15,    48,    36,    17,    18,    50,    53,    52,   112,
     113,   114,    87,   116,    89,    51,   119,   263,    48,    32,
      33,    51,   268,    48,    48,    38,    51,    51,    41,    48,
      43,    48,    51,    48,    51,    31,    51,    31,   214,    48,
      53,    53,    51,    50,   147,   221,   187,    27,    28,   190,
      32,   154,    27,   156,    32,   158,    40,    41,    42,    32,
     163,     6,     7,     8,    50,   168,    42,    52,    32,   172,
      32,    32,   175,    86,    31,    31,    50,    90,    31,    31,
      31,    53,    48,    96,   187,    50,    53,   190,   191,   192,
     193,    50,   172,    32,   197,    22,    50,    52,   156,   174,
      50,   114,   177,   116,    48,    43,    -1,   210,   249,    19,
      -1,   214,   145,    -1,    -1,   148,    -1,    -1,   221,    29,
      30,    31,    -1,   198,    -1,    -1,    36,    37,    -1,    -1,
      -1,    -1,   207,    -1,   237,    -1,    -1,    -1,   171,    -1,
      50,   154,    52,    -1,    54,    -1,   249,    57,   181,   224,
     163,   226,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,
     263,    -1,    -1,   266,    -1,   268,   199,   242,   243,   202,
      -1,    -1,    -1,    -1,   187,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,   258,   259,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,    -1,   227,     0,     1,    20,    21,     4,
       5,    -1,    -1,    -1,     9,    10,    11,    12,    13,    -1,
      -1,    16,    17,    18,    19,    38,    39,    40,    41,    42,
     253,   254,    -1,    -1,    29,    30,    31,    -1,    -1,    -1,
      -1,    36,    37,    -1,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,    -1,     4,    -1,    50,    -1,    -1,    -1,    54,
      -1,    56,    57,     0,     1,    -1,    -1,     4,     5,    20,
      21,    22,     9,    10,    11,    12,    13,    -1,    -1,    16,
      -1,    18,    19,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    29,    30,    31,    -1,    -1,    -1,    -1,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,    -1,    50,    -1,    -1,    -1,    54,    -1,    56,
      57,     0,     1,    -1,    -1,     4,     5,    20,    21,    22,
       9,    10,    11,    12,    13,    -1,    -1,    16,    -1,    18,
      19,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      29,    30,    31,    -1,    -1,    -1,     1,    36,    37,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    50,    -1,    18,    19,    54,    -1,    56,    57,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    -1,
       1,    36,    37,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    50,    -1,    18,    19,    54,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    -1,    -1,    -1,     1,    36,    37,     4,     5,    -1,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    50,
      -1,    18,    19,    54,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    -1,    -1,     1,    36,
      37,     4,     5,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    50,    -1,    18,    19,    54,    -1,    56,
      57,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
      -1,    -1,     1,    36,    37,     4,     5,    -1,    -1,    -1,
       9,    10,    11,    12,    13,    -1,    -1,    50,    -1,    18,
      19,    54,    -1,    56,    57,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    -1,    -1,    -1,     1,    36,    37,     4,
       5,    -1,    -1,     8,     9,    10,    11,    12,    13,    -1,
      -1,    50,    -1,    18,    19,    54,    -1,    56,    57,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    -1,
       1,    36,    37,     4,     5,    -1,    -1,     8,     9,    10,
      11,    12,    13,    -1,    -1,    50,    -1,    18,    19,    54,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    -1,    -1,    -1,     1,    36,    37,     4,     5,    -1,
      -1,     8,     9,    10,    11,    12,    13,    -1,    -1,    50,
      -1,    18,    19,    54,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    -1,    -1,     1,    36,
      37,     4,     5,    -1,    -1,     8,     9,    10,    11,    12,
      13,    -1,    -1,    50,    -1,    18,    19,    54,    -1,    56,
      57,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
      -1,    -1,     1,    36,    37,     4,     5,    -1,    -1,    -1,
       9,    10,    11,    12,    13,    -1,    -1,    50,    -1,    18,
      19,    54,    -1,    56,    57,    -1,    -1,    -1,    -1,    19,
      29,    30,    31,    -1,    -1,    -1,    -1,    36,    37,    29,
      30,    31,    -1,    -1,    -1,    -1,    36,    37,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    54,    -1,    56,    57,    19,
      50,    51,    52,    -1,    54,    -1,    -1,    57,    -1,    29,
      30,    31,    -1,    -1,    19,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    48,    19,
      50,    36,    37,    -1,    54,    55,    -1,    57,    -1,    29,
      30,    31,    -1,    48,    19,    50,    36,    37,    -1,    54,
      55,    -1,    57,    -1,    29,    30,    31,    -1,    48,    -1,
      50,    36,    37,    -1,    54,    55,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    50,    51,    52,    -1,    54,
      -1,    -1,    57,    29,    30,    31,    -1,    -1,    19,    -1,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    -1,    -1,    19,    50,    36,    37,    -1,    54,    -1,
      56,    57,    -1,    29,    30,    31,    -1,    -1,    19,    50,
      36,    37,    53,    54,    -1,    -1,    57,    -1,    29,    30,
      31,    -1,    -1,    -1,    50,    36,    37,    53,    54,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    19,    -1,    50,
      -1,    52,    -1,    54,    -1,    -1,    57,    29,    30,    31,
      -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    50,    -1,
      52,    -1,    54,    -1,    -1,    57,    29,    30,    31,    -1,
      -1,    19,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    -1,    48,    19,    50,    36,    37,
      -1,    54,    -1,    -1,    57,    -1,    29,    30,    31,    -1,
      -1,    -1,    50,    36,    37,    -1,    54,    -1,    -1,    57,
      20,    21,    22,    -1,    -1,    -1,    -1,    50,    20,    21,
      22,    54,    -1,    -1,    57,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    36,    37,    38,    39,    40,    41,
      42,    20,    21,    22,    -1,    -1,    56,    -1,    20,    21,
      22,    53,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    36,    37,    38,    39,    40,    41,
      42,    20,    21,    22,    53,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    20,    21,    22,    23,    24,    25,    26,
      -1,    51,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    20,    21,    22,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    46,    47,    48,    36,    37,    38,    39,    40,
      41,    42,    20,    21,    22,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      48,    36,    37,    38,    39,    40,    41,    42,    20,    21,
      22,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    46,    47,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    20,
      21,    22,    23,    24,    25,    26,    -1,    20,    21,    22,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    35,    36,    37,    38,    39,    40,    41,    42,
      20,    21,    22,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    36,    37,    38,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     9,    10,    11,    12,    13,    16,
      18,    19,    29,    30,    31,    36,    37,    50,    54,    56,
      57,    60,    61,    63,    64,    68,    69,    72,    80,    81,
       4,    31,    50,    54,    72,    81,    72,    31,    50,    81,
      31,    54,    50,    32,    50,    52,    81,    81,    72,    78,
      79,    81,    76,    77,    79,    81,    72,    31,     0,    64,
       0,     4,    48,    49,    65,    27,    28,    20,    21,    22,
      23,    24,    25,    26,    33,    34,    36,    37,    38,    39,
      40,    41,    42,    50,    52,    81,    77,    62,    63,    62,
      32,     4,    71,    32,    50,    52,    77,    31,    52,    79,
      80,    82,    51,    74,    75,    79,    81,    82,    53,    81,
      51,    51,    35,    48,    49,    55,    48,    55,    79,    50,
      72,    72,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    75,    53,
      81,    55,    63,    70,     8,    79,     8,    14,    15,    31,
      31,    73,    53,    55,    32,    75,    48,    51,    56,    32,
      53,    81,    81,    77,    79,    32,    51,    75,    58,    51,
      53,     6,     7,     8,    62,    52,    81,    62,    50,    52,
      48,    51,    32,    32,    79,    53,    74,    32,    81,    31,
      32,    50,    35,    51,    31,    51,    81,    50,    62,    72,
       8,    75,     4,     8,    73,    53,    31,    62,    31,    31,
      48,    79,    80,    51,    50,    79,    80,    81,    81,    67,
      81,    50,    81,     8,    62,    53,    62,    51,    52,     0,
      17,    66,    50,    50,    81,    75,    51,    48,    46,    47,
      75,    51,    62,    62,    53,    73,    73,    51,    51,    32,
      81,    51,    66,    51,    51,    79,    80,    48,    62,    62,
      81,    66,    66,    48,    67,    81,    48,    81,    48,    67
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
#line 96 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", (yyvaluep->str));
#endif
  free((yyvaluep->str));
};

/* Line 1000 of yacc.c  */
#line 1586 "cipsycon.tab.c"
	break;
      case 31: /* "\"identifier\"" */

/* Line 1000 of yacc.c  */
#line 96 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", (yyvaluep->str));
#endif
  free((yyvaluep->str));
};

/* Line 1000 of yacc.c  */
#line 1600 "cipsycon.tab.c"
	break;
      case 61: /* "block_func" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1614 "cipsycon.tab.c"
	break;
      case 62: /* "block" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1628 "cipsycon.tab.c"
	break;
      case 63: /* "line" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1642 "cipsycon.tab.c"
	break;
      case 64: /* "line_func" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1656 "cipsycon.tab.c"
	break;
      case 67: /* "exp_time" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1670 "cipsycon.tab.c"
	break;
      case 68: /* "stmt" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1684 "cipsycon.tab.c"
	break;
      case 69: /* "funcdef" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1698 "cipsycon.tab.c"
	break;
      case 70: /* "elseif_list" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1712 "cipsycon.tab.c"
	break;
      case 71: /* "case_list" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1726 "cipsycon.tab.c"
	break;
      case 72: /* "condition" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1740 "cipsycon.tab.c"
	break;
      case 73: /* "id_list" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1754 "cipsycon.tab.c"
	break;
      case 74: /* "arg" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1768 "cipsycon.tab.c"
	break;
      case 75: /* "arg_list" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1782 "cipsycon.tab.c"
	break;
      case 76: /* "matrix" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1796 "cipsycon.tab.c"
	break;
      case 77: /* "vector" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1810 "cipsycon.tab.c"
	break;
      case 78: /* "range" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1824 "cipsycon.tab.c"
	break;
      case 79: /* "exp_range" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1838 "cipsycon.tab.c"
	break;
      case 80: /* "assign" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1852 "cipsycon.tab.c"
	break;
      case 81: /* "exp" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1866 "cipsycon.tab.c"
	break;
      case 82: /* "initcell" */

/* Line 1000 of yacc.c  */
#line 89 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1880 "cipsycon.tab.c"
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
#line 80 "cipsycon.y"
{
  if (ErrorMsg) {
	free(ErrorMsg);
	ErrorMsg = NULL;
  }
  *errmsg = NULL;
}

/* Line 1242 of yacc.c  */
#line 2041 "cipsycon.tab.c"

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
#line 112 "cipsycon.y"
    { *pproot = NULL;;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 114 "cipsycon.y"
    { *pproot = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 118 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 120 "cipsycon.y"
    {
		if ((yyvsp[(2) - (2)].pnode)) {
			if ((yyvsp[(1) - (2)].pnode) == NULL)
				(yyval.pnode) = (yyvsp[(2) - (2)].pnode);
			else if ((yyvsp[(1) - (2)].pnode)->type == NODE_BLOCK) {
				(yyvsp[(1) - (2)].pnode)->LastChild = (yyvsp[(1) - (2)].pnode)->LastChild->next = (yyvsp[(2) - (2)].pnode);
				(yyval.pnode) = (yyvsp[(1) - (2)].pnode);
			} else {
				(yyval.pnode) = newAstNode(NODE_BLOCK, (yyloc));
				(yyval.pnode)->child = (yyvsp[(1) - (2)].pnode);
				(yyval.pnode)->LastChild = (yyval.pnode)->child->next = (yyvsp[(2) - (2)].pnode);
			}
		} else
			(yyval.pnode) = (yyvsp[(1) - (2)].pnode);
	;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 138 "cipsycon.y"
    {
		if ((yyvsp[(1) - (1)].pnode))
			(yyval.pnode) = (yyvsp[(1) - (1)].pnode);
		else
			(yyval.pnode) = newAstNode(NODE_BLOCK, (yyloc));
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 145 "cipsycon.y"
    {
		if ((yyvsp[(2) - (2)].pnode)) {
			if ((yyvsp[(1) - (2)].pnode)->type == NODE_BLOCK) {
				if ((yyvsp[(1) - (2)].pnode)->LastChild) {
					(yyvsp[(1) - (2)].pnode)->LastChild = (yyvsp[(1) - (2)].pnode)->LastChild->next = (yyvsp[(2) - (2)].pnode);
					(yyval.pnode) = (yyvsp[(1) - (2)].pnode);
				} else {
					(yyval.pnode) = (yyvsp[(2) - (2)].pnode);
					free((yyvsp[(1) - (2)].pnode));
				}
			} else {
				(yyval.pnode) = newAstNode(NODE_BLOCK, (yyloc));
				(yyval.pnode)->child = (yyvsp[(1) - (2)].pnode);
				(yyval.pnode)->LastChild = (yyval.pnode)->child->next = (yyvsp[(2) - (2)].pnode);
			}
		} else
			(yyval.pnode) = (yyvsp[(1) - (2)].pnode);
	;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 166 "cipsycon.y"
    { (yyval.pnode) = NULL;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 168 "cipsycon.y"
    {
		(yyval.pnode) = NULL;
		yyerrok;
	;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 173 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (2)].pnode);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 177 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 179 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 189 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 191 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_MSEC, (yyloc));
		(yyval.pnode)->child = (yyvsp[(1) - (2)].pnode);
	;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 196 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_USEC, (yyloc));
		(yyval.pnode)->child = (yyvsp[(1) - (2)].pnode);
	;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 203 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 205 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 207 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 209 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(4) - (5)].pnode);
		(yyvsp[(2) - (5)].pnode)->next = (yyvsp[(3) - (5)].pnode);
		(yyvsp[(3) - (5)].pnode)->next = (yyvsp[(4) - (5)].pnode)->child;
		(yyval.pnode)->child = (yyvsp[(2) - (5)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 218 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(4) - (7)].pnode);
		(yyvsp[(2) - (7)].pnode)->next = (yyvsp[(3) - (7)].pnode);
		if ((yyvsp[(4) - (7)].pnode)->LastChild) {
			(yyvsp[(3) - (7)].pnode)->next = (yyvsp[(4) - (7)].pnode)->child;
			(yyvsp[(4) - (7)].pnode)->LastChild->next = (yyvsp[(6) - (7)].pnode);
		} else
			(yyvsp[(3) - (7)].pnode)->next = (yyvsp[(6) - (7)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (7)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 231 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (4)].pnode);
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode)->child;
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 239 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (6)].pnode);
		(yyvsp[(2) - (6)].pnode)->next = (yyvsp[(3) - (6)].pnode)->child;
		(yyvsp[(3) - (6)].pnode)->LastChild->next = (yyvsp[(5) - (6)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (6)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 248 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_WHILE, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode);
	;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 254 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_FOR, (yyloc));
		(yyval.pnode)->child = newAstNode('=', (yylsp[(2) - (6)]));
		(yyval.pnode)->child->str = (yyvsp[(2) - (6)].str);
		(yyval.pnode)->child->child = (yyvsp[(4) - (6)].pnode);
		(yyval.pnode)->child->next = (yyvsp[(5) - (6)].pnode);
	;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 262 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_RETURN, (yyloc));
	;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 266 "cipsycon.y"
    { (yyval.pnode) = newAstNode(T_BREAK, (yyloc));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 268 "cipsycon.y"
    { (yyval.pnode) = newAstNode(T_CONTINUE, (yyloc));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 270 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CIPULSE3, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (10)].pnode);
		(yyvsp[(2) - (10)].pnode)->next = (yyvsp[(4) - (10)].pnode);
		(yyvsp[(4) - (10)].pnode)->next = (yyvsp[(6) - (10)].pnode);
		(yyvsp[(6) - (10)].pnode)->next = (yyvsp[(8) - (10)].pnode);
		(yyvsp[(8) - (10)].pnode)->next = (yyvsp[(10) - (10)].pnode);
	;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 279 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CIPULSE4, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (12)].pnode);
		(yyvsp[(2) - (12)].pnode)->next = (yyvsp[(4) - (12)].pnode);
		(yyvsp[(4) - (12)].pnode)->next = (yyvsp[(6) - (12)].pnode);
		(yyvsp[(6) - (12)].pnode)->next = (yyvsp[(8) - (12)].pnode);
		(yyvsp[(8) - (12)].pnode)->next = (yyvsp[(10) - (12)].pnode);
		(yyvsp[(10) - (12)].pnode)->next = (yyvsp[(12) - (12)].pnode);
	;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 289 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CIPULSE5, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (14)].pnode);
		(yyvsp[(2) - (14)].pnode)->next = (yyvsp[(4) - (14)].pnode);
		(yyvsp[(4) - (14)].pnode)->next = (yyvsp[(6) - (14)].pnode);
		(yyvsp[(6) - (14)].pnode)->next = (yyvsp[(8) - (14)].pnode);
		(yyvsp[(8) - (14)].pnode)->next = (yyvsp[(10) - (14)].pnode);
		(yyvsp[(10) - (14)].pnode)->next = (yyvsp[(12) - (14)].pnode);
		(yyvsp[(12) - (14)].pnode)->next = (yyvsp[(14) - (14)].pnode);
	;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 300 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CIPULSE6, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (16)].pnode);
		(yyvsp[(2) - (16)].pnode)->next = (yyvsp[(4) - (16)].pnode);
		(yyvsp[(4) - (16)].pnode)->next = (yyvsp[(6) - (16)].pnode);
		(yyvsp[(6) - (16)].pnode)->next = (yyvsp[(8) - (16)].pnode);
		(yyvsp[(8) - (16)].pnode)->next = (yyvsp[(10) - (16)].pnode);
		(yyvsp[(10) - (16)].pnode)->next = (yyvsp[(12) - (16)].pnode);
		(yyvsp[(12) - (16)].pnode)->next = (yyvsp[(14) - (16)].pnode);
		(yyvsp[(14) - (16)].pnode)->next = (yyvsp[(16) - (16)].pnode);
	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 314 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(2) - (7)].str);
		(yyval.pnode)->child = (yyvsp[(4) - (7)].pnode);
		(yyvsp[(4) - (7)].pnode)->next = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 321 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(4) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (9)].pnode);
		(yyvsp[(6) - (9)].pnode)->next = (yyvsp[(8) - (9)].pnode);
		(yyvsp[(8) - (9)].pnode)->next = newAstNode(T_ID, (yylsp[(2) - (9)]));
		(yyvsp[(8) - (9)].pnode)->next->str = (yyvsp[(2) - (9)].str);
	;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 330 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(6) - (11)].str);
		(yyval.pnode)->child = (yyvsp[(8) - (11)].pnode);
		(yyvsp[(8) - (11)].pnode)->next = (yyvsp[(10) - (11)].pnode);
		(yyvsp[(10) - (11)].pnode)->next = newAstNode(NODE_INITCELL, (yylsp[(2) - (11)]));
		(yyvsp[(10) - (11)].pnode)->next->str = (yyvsp[(2) - (11)].str);
	;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 339 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(6) - (11)].str);
		(yyval.pnode)->child = (yyvsp[(8) - (11)].pnode);
		(yyvsp[(8) - (11)].pnode)->next = (yyvsp[(10) - (11)].pnode);
		(yyvsp[(10) - (11)].pnode)->next = (yyvsp[(3) - (11)].pnode);
	;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 349 "cipsycon.y"
    { (yyval.pnode) = newAstNode(T_IF, (yyloc));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 351 "cipsycon.y"
    {
		if ((yyvsp[(1) - (4)].pnode)->child)
			(yyvsp[(1) - (4)].pnode)->LastChild->next = (yyvsp[(3) - (4)].pnode);
		else
			(yyvsp[(1) - (4)].pnode)->child = (yyvsp[(3) - (4)].pnode);
		(yyvsp[(3) - (4)].pnode)->next = (yyvsp[(4) - (4)].pnode);
		(yyvsp[(1) - (4)].pnode)->LastChild = (yyvsp[(4) - (4)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (4)].pnode);
	;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 363 "cipsycon.y"
    { (yyval.pnode) = newAstNode(T_SWITCH, (yyloc));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 365 "cipsycon.y"
    { (yyval.pnode) = newAstNode(T_SWITCH, (yyloc));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 367 "cipsycon.y"
    {
		if ((yyvsp[(1) - (5)].pnode)->child)
			(yyvsp[(1) - (5)].pnode)->LastChild->next = (yyvsp[(3) - (5)].pnode);
		else
			(yyvsp[(1) - (5)].pnode)->child = (yyvsp[(3) - (5)].pnode);
		(yyvsp[(3) - (5)].pnode)->next = (yyvsp[(5) - (5)].pnode);
		(yyvsp[(1) - (5)].pnode)->LastChild = (yyvsp[(5) - (5)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (5)].pnode);
	;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 377 "cipsycon.y"
    {
		if ((yyvsp[(1) - (6)].pnode)->child)
			(yyvsp[(1) - (6)].pnode)->LastChild->next = (yyvsp[(4) - (6)].pnode);
		else
			(yyvsp[(1) - (6)].pnode)->child = (yyvsp[(4) - (6)].pnode);
		(yyvsp[(4) - (6)].pnode)->next = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(1) - (6)].pnode)->LastChild = (yyvsp[(6) - (6)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (6)].pnode);
	;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 389 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('<', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 391 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('>', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 393 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_EQ, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 395 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_NE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 397 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_LE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 399 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_GE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 401 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 407 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_LOGIC_NOT, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (2)].pnode);
	;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 412 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 414 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 418 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
	;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 422 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->LastChild = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->LastChild->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 428 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->LastChild = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->LastChild->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 434 "cipsycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->LastChild = (yyvsp[(1) - (3)].pnode)->LastChild->next = newAstNode(T_ID, (yylsp[(3) - (3)]));
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
		(yyval.pnode)->LastChild->str = (yyvsp[(3) - (3)].str);
	;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 440 "cipsycon.y"
    {
		(yyvsp[(1) - (5)].pnode)->LastChild = (yyvsp[(1) - (5)].pnode)->LastChild->next = newAstNode(NODE_INITCELL, (yylsp[(3) - (5)]));
		(yyval.pnode) = (yyvsp[(1) - (5)].pnode);
		(yyval.pnode)->LastChild->str = (yyvsp[(3) - (5)].str);
	;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 448 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 450 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 454 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_ARGS, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->LastChild = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 459 "cipsycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->LastChild = (yyvsp[(1) - (3)].pnode)->LastChild->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 466 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_MATRIX, (yyloc));
	;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 470 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_MATRIX, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->LastChild = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 475 "cipsycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->LastChild = (yyvsp[(1) - (3)].pnode)->LastChild->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 482 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_VECTOR, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->LastChild = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 487 "cipsycon.y"
    {
		(yyvsp[(1) - (2)].pnode)->LastChild = (yyvsp[(1) - (2)].pnode)->LastChild->next = (yyvsp[(2) - (2)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (2)].pnode);
	;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 492 "cipsycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->LastChild = (yyvsp[(1) - (3)].pnode)->LastChild->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 499 "cipsycon.y"
    {
		(yyval.pnode) = makeFunctionCall(":", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));
	;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 503 "cipsycon.y"
    {
		(yyval.pnode) = makeFunctionCall(":", (yyvsp[(1) - (5)].pnode), (yyvsp[(5) - (5)].pnode), (yyloc));
		(yyval.pnode)->LastChild = (yyvsp[(5) - (5)].pnode)->next = (yyvsp[(3) - (5)].pnode);
	;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 510 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 512 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 516 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 522 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(6) - (6)].pnode)->next = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 529 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(6) - (6)].pnode)->next = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 536 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(9) - (9)].pnode);
		(yyvsp[(9) - (9)].pnode)->next = (yyvsp[(6) - (9)].pnode);
		(yyvsp[(6) - (9)].pnode)->next = (yyvsp[(3) - (9)].pnode);
	;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 544 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 550 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(6) - (6)].pnode)->next = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 557 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(6) - (6)].pnode)->next = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 564 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(9) - (9)].pnode);
		(yyvsp[(9) - (9)].pnode)->next = (yyvsp[(6) - (9)].pnode);
		(yyvsp[(6) - (9)].pnode)->next = (yyvsp[(3) - (9)].pnode);
	;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 572 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 579 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(5) - (8)].str);
		(yyval.pnode)->child = (yyvsp[(7) - (8)].pnode);
		(yyvsp[(7) - (8)].pnode)->next = newAstNode(NODE_INITCELL, (yylsp[(1) - (8)]));
		(yyvsp[(7) - (8)].pnode)->next->str = (yyvsp[(1) - (8)].str);
	;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 587 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(5) - (8)].str);
		(yyval.pnode)->child = (yyvsp[(7) - (8)].pnode);
		(yyvsp[(7) - (8)].pnode)->next = (yyvsp[(2) - (8)].pnode);
	;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 596 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_NUMBER, (yyloc));
		(yyval.pnode)->dval = (yyvsp[(1) - (1)].dval);
	;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 601 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_STRING, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 606 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 611 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (4)].pnode);
	;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 617 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (7)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (7)].pnode);
		(yyvsp[(3) - (7)].pnode)->next = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 624 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 629 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 634 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->type = NODE_CALL;
 		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 642 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = malloc(strlen((yyvsp[(2) - (4)].str))+2);
 		(yyval.pnode)->str[0] = '#';
 		strcpy((yyval.pnode)->str+1, (yyvsp[(2) - (4)].str));
 		free((yyvsp[(2) - (4)].str));
	;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 650 "cipsycon.y"
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

  case 99:

/* Line 1455 of yacc.c  */
#line 661 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_EXTRACT, (yyloc));
		(yyval.pnode)->child = newAstNode(T_ID, (yylsp[(1) - (6)]));
		(yyval.pnode)->child->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child->next = (yyvsp[(3) - (6)].pnode);
		(yyvsp[(3) - (6)].pnode)->next = (yyvsp[(5) - (6)].pnode);
	;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 669 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_NEGATIVE, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (2)].pnode);
	;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 674 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (2)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 680 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 686 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_SIGMA, (yyloc));
		(yyval.pnode)->child = newAstNode('=', (yylsp[(3) - (8)]));
		(yyval.pnode)->child->str = (yyvsp[(3) - (8)].str);
		(yyval.pnode)->child->child = (yyvsp[(5) - (8)].pnode);
		(yyval.pnode)->child->next = (yyvsp[(7) - (8)].pnode);
	;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 694 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('+', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 696 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('-', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 698 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('*', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 700 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('/', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 702 "cipsycon.y"
    { (yyval.pnode) = makeFunctionCall("^", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 704 "cipsycon.y"
    { (yyval.pnode) = makeFunctionCall("caret", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 706 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('@', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 708 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INTERPOL, (yyloc));
		(yyval.pnode)->child = (yyvsp[(1) - (5)].pnode);
		(yyvsp[(1) - (5)].pnode)->next = (yyvsp[(3) - (5)].pnode);
		(yyvsp[(3) - (5)].pnode)->next = (yyvsp[(5) - (5)].pnode);
		(yyval.pnode)->LastChild = (yyvsp[(5) - (5)].pnode);
	;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 716 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_SHIFT, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 718 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_SHIFT2, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 720 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_CONCAT, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 722 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 728 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 736 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->type = NODE_INITCELL;
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;



/* Line 1455 of yacc.c  */
#line 3358 "cipsycon.tab.c"
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
#line 744 "cipsycon.y"


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

