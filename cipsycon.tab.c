
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
     T_REPLICA = 284,
     T_NUMBER = 285,
     T_STRING = 286,
     T_ID = 287,
     T_HOOKCMD = 288,
     T_ENDPOINT = 289,
     T_NEGATIVE = 290,
     T_POSITIVE = 291,
     T_LOGIC_NOT = 292,
     T_USEC = 293,
     T_MSEC = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 22 "cipsycon.y"

	double dval;
	char *str;
	AstNode *pnode;



/* Line 214 of yacc.c  */
#line 172 "cipsycon.tab.c"
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
#line 106 "cipsycon.y"

AstNode *newAstNode(int type, YYLTYPE loc);
AstNode *makeFunctionCall(char *name, AstNode *first, AstNode *second, YYLTYPE loc);
AstNode *makeBinaryOpNode(int op, AstNode *first, AstNode *second, YYLTYPE loc);
AstNode *makeCompoundLevelOpNode(char *first, AstNode *second, YYLTYPE loc1, YYLTYPE loc2);
AstNode *makeCompoundOpNode(int op, char *first, AstNode *second, YYLTYPE loc1, YYLTYPE loc2);
AstNode *makeCompoundOpNodeFunctionCall(int op, char *first, AstNode *second, YYLTYPE loc1, YYLTYPE loc2);
AstNode *Restring(char *oper, char* dummy1, AstNode *dumm2, AstNode *dummy3, AstNode *dummy4, YYLTYPE loc);
void print_token_value(FILE *file, int type, YYSTYPE value);


/* Line 264 of yacc.c  */
#line 209 "cipsycon.tab.c"

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
#define YYFINAL  82
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  168
/* YYNRULES -- Number of states.  */
#define YYNSTATES  358

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,    70,    41,    42,     2,     2,
      54,    55,    44,    40,    52,    39,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    53,
      36,    35,    37,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    71,    59,    69,     2,     2,     2,
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
      47,    48,    49,    50,    51,    61,    62,    63,    64,    65,
      66,    67,    68
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    16,    18,
      21,    24,    26,    28,    30,    32,    34,    36,    37,    39,
      41,    43,    46,    49,    51,    54,    56,    59,    60,    65,
      69,    71,    73,    75,    77,    79,    85,    90,    97,   102,
     109,   117,   119,   121,   123,   134,   147,   162,   179,   187,
     197,   209,   221,   222,   224,   230,   237,   241,   245,   249,
     253,   257,   261,   265,   269,   273,   277,   281,   285,   289,
     293,   297,   301,   305,   309,   313,   316,   319,   323,   327,
     331,   335,   339,   343,   347,   351,   352,   354,   358,   362,
     368,   370,   372,   374,   378,   379,   381,   385,   387,   390,
     394,   398,   404,   406,   408,   412,   418,   422,   426,   430,
     434,   438,   442,   446,   450,   454,   461,   470,   479,   488,
     497,   506,   515,   522,   529,   538,   550,   560,   570,   574,
     581,   588,   598,   602,   604,   606,   608,   610,   612,   617,
     625,   633,   636,   640,   644,   649,   654,   659,   665,   672,
     675,   678,   682,   691,   695,   699,   703,   707,   711,   715,
     719,   723,   729,   733,   737,   741,   745,   749,   751
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      73,     0,    -1,    -1,    74,    -1,    77,    -1,    74,    77,
      -1,    76,    -1,    75,    76,    -1,     4,    -1,     1,     4,
      -1,    83,    78,    -1,    76,    -1,    84,    -1,    52,    -1,
      53,    -1,     4,    -1,     0,    -1,    -1,    17,    -1,     0,
      -1,    95,    -1,    95,    51,    -1,    95,    50,    -1,    86,
      -1,    86,    78,    -1,    95,    -1,    95,    78,    -1,    -1,
       7,    81,    75,    82,    -1,    82,     6,    75,    -1,    95,
      -1,    94,    -1,    86,    -1,    96,    -1,    33,    -1,     5,
      81,    75,    82,     8,    -1,    13,    95,    85,     8,    -1,
      13,    95,    85,    15,    75,     8,    -1,     9,    81,    75,
       8,    -1,    10,    32,    35,    93,    75,     8,    -1,    10,
      32,    35,    93,    52,    75,     8,    -1,    18,    -1,    11,
      -1,    12,    -1,    54,    95,    52,    95,    55,    80,    52,
      95,    52,    95,    -1,    54,    95,    52,    95,    55,    80,
      52,    95,    52,    95,    52,    80,    -1,    54,    95,    52,
      95,    55,    80,    52,    95,    52,    95,    52,    95,    52,
      95,    -1,    54,    95,    52,    95,    55,    80,    52,    95,
      52,    95,    52,    95,    52,    95,    52,    80,    -1,    16,
      32,    54,    87,    55,    75,    79,    -1,    16,    32,    35,
      32,    54,    87,    55,    75,    79,    -1,    16,    56,    91,
      57,    35,    32,    54,    87,    55,    75,    79,    -1,    16,
      32,    58,    59,    35,    32,    54,    87,    55,    75,    79,
      -1,    -1,     4,    -1,    85,    14,    95,     4,    75,    -1,
      85,    14,    58,    89,    59,    75,    -1,    95,    36,    95,
      -1,    92,    36,    95,    -1,    95,    36,    92,    -1,    95,
      37,    95,    -1,    92,    37,    95,    -1,    95,    37,    92,
      -1,    95,    23,    95,    -1,    92,    23,    95,    -1,    95,
      23,    92,    -1,    95,    24,    95,    -1,    92,    24,    95,
      -1,    95,    24,    92,    -1,    95,    26,    95,    -1,    92,
      26,    95,    -1,    95,    26,    92,    -1,    95,    25,    95,
      -1,    92,    25,    95,    -1,    95,    25,    92,    -1,    54,
      86,    55,    -1,    60,    86,    -1,    60,    95,    -1,    86,
      27,    86,    -1,    95,    27,    95,    -1,    86,    27,    95,
      -1,    95,    27,    86,    -1,    86,    28,    86,    -1,    95,
      28,    95,    -1,    86,    28,    95,    -1,    95,    28,    86,
      -1,    -1,    32,    -1,    32,    58,    59,    -1,    87,    52,
      32,    -1,    87,    52,    32,    58,    59,    -1,    93,    -1,
      96,    -1,    88,    -1,    89,    52,    88,    -1,    -1,    91,
      -1,    90,    53,    91,    -1,    93,    -1,    91,    93,    -1,
      91,    52,    93,    -1,    95,    38,    95,    -1,    95,    38,
      95,    38,    95,    -1,    95,    -1,    92,    -1,    32,    35,
      93,    -1,    56,    91,    57,    35,    93,    -1,    32,    35,
      86,    -1,    32,    61,    93,    -1,    32,    62,    93,    -1,
      32,    63,    93,    -1,    32,    64,    93,    -1,    32,    65,
      93,    -1,    32,    66,    93,    -1,    32,    67,    93,    -1,
      32,    68,    93,    -1,    32,    58,    95,    59,    35,    93,
      -1,    32,    54,    95,    69,    95,    55,    61,    93,    -1,
      32,    54,    95,    69,    95,    55,    62,    93,    -1,    32,
      54,    95,    69,    95,    55,    63,    93,    -1,    32,    54,
      95,    69,    95,    55,    64,    93,    -1,    32,    54,    95,
      69,    95,    55,    66,    93,    -1,    32,    54,    95,    69,
      95,    55,    67,    93,    -1,    32,    54,    89,    55,    35,
      93,    -1,    32,    54,    86,    55,    35,    93,    -1,    32,
      54,    95,    69,    95,    55,    35,    95,    -1,    32,    58,
      95,    59,    54,    95,    69,    95,    55,    35,    95,    -1,
      32,    58,    95,    59,    54,    95,    55,    35,    93,    -1,
      32,    58,    95,    59,    54,    93,    55,    35,    93,    -1,
      32,    35,    94,    -1,    32,    58,    95,    59,    35,    94,
      -1,    32,    54,    89,    55,    35,    94,    -1,    32,    58,
      95,    59,    54,    95,    55,    35,    94,    -1,    32,    35,
      96,    -1,    30,    -1,    31,    -1,    34,    -1,    96,    -1,
      32,    -1,    32,    58,    95,    59,    -1,    32,    58,    95,
      59,    54,    95,    55,    -1,    32,    58,    95,    59,    54,
      93,    55,    -1,    58,    59,    -1,    32,    58,    59,    -1,
      32,    54,    55,    -1,    32,    54,    89,    55,    -1,    29,
      54,    89,    55,    -1,    32,    54,    86,    55,    -1,    70,
      32,    54,    89,    55,    -1,    32,    54,    95,    69,    95,
      55,    -1,    39,    95,    -1,    40,    95,    -1,    54,    93,
      55,    -1,    19,    54,    32,    35,    93,    52,    95,    55,
      -1,    95,    40,    95,    -1,    95,    39,    95,    -1,    95,
      44,    95,    -1,    95,    45,    95,    -1,    95,    46,    95,
      -1,    95,    42,    95,    -1,    95,    41,    95,    -1,    95,
      43,    95,    -1,    95,    43,    95,    71,    95,    -1,    95,
      20,    95,    -1,    95,    21,    95,    -1,    95,    22,    95,
      -1,    56,    90,    57,    -1,    56,    91,    57,    -1,    29,
      -1,    58,    89,    59,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   120,   124,   126,   152,   159,   186,   188,
     193,   197,   199,   203,   203,   203,   203,   206,   206,   206,
     210,   212,   217,   224,   226,   228,   230,   235,   238,   245,
     260,   262,   264,   266,   268,   275,   289,   297,   306,   312,
     320,   328,   332,   334,   336,   345,   355,   366,   380,   387,
     397,   406,   418,   419,   421,   431,   443,   445,   447,   449,
     451,   453,   455,   457,   459,   461,   463,   465,   467,   469,
     471,   473,   475,   477,   479,   485,   490,   495,   497,   499,
     501,   503,   505,   507,   509,   514,   517,   523,   529,   535,
     543,   545,   549,   554,   562,   565,   570,   577,   582,   587,
     594,   598,   605,   607,   611,   617,   623,   629,   635,   641,
     647,   653,   659,   665,   671,   677,   684,   688,   692,   696,
     700,   704,   708,   715,   722,   731,   742,   750,   758,   764,
     771,   778,   786,   795,   800,   805,   810,   814,   820,   826,
     833,   840,   844,   849,   854,   862,   869,   878,   889,   897,
     902,   908,   914,   922,   924,   926,   928,   930,   932,   934,
     936,   938,   946,   948,   950,   952,   958,   964,   971
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
  "'^'", "T_NEGATIVE", "T_POSITIVE", "T_LOGIC_NOT", "\"us\"", "\"ms\"",
  "','", "';'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'!'", "\"+=\"",
  "\"-=\"", "\"*=\"", "\"/=\"", "\"^=\"", "\"@=\"", "\"@@=\"", "\"++=\"",
  "'~'", "'#'", "'|'", "$accept", "input", "block_func", "block", "line",
  "line_func", "eol", "func_end", "exp_time", "conditional", "elseif_list",
  "stmt", "funcdef", "case_list", "condition", "id_list", "arg",
  "arg_list", "matrix", "vector", "range", "exp_range", "assign", "exp",
  "initcell", 0
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
     293,   294,    44,    59,    40,    41,    91,    93,   123,   125,
      33,   295,   296,   297,   298,   299,   300,   301,   302,   126,
      35,   124
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    78,    78,    78,    78,    79,    79,    79,
      80,    80,    80,    81,    81,    81,    81,    82,    82,    82,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    84,    84,
      84,    84,    85,    85,    85,    85,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    87,    87,    87,    87,    87,
      88,    88,    89,    89,    90,    90,    90,    91,    91,    91,
      92,    92,    93,    93,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    96
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       1,     2,     2,     1,     2,     1,     2,     0,     4,     3,
       1,     1,     1,     1,     1,     5,     4,     6,     4,     6,
       7,     1,     1,     1,    10,    12,    14,    16,     7,     9,
      11,    11,     0,     1,     5,     6,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     0,     1,     3,     3,     5,
       1,     1,     1,     3,     0,     1,     3,     1,     2,     3,
       3,     5,     1,     1,     3,     5,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     6,     8,     8,     8,     8,
       8,     8,     6,     6,     8,    11,     9,     9,     3,     6,
       6,     9,     3,     1,     1,     1,     1,     1,     4,     7,
       7,     2,     3,     3,     4,     4,     4,     5,     6,     2,
       2,     3,     8,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     3,     3,     3,     3,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     8,     0,     0,     0,    42,    43,     0,     0,
      41,     0,   167,   133,   134,   137,    34,   135,     0,     0,
       0,    94,     0,     0,     0,     0,     0,    11,     4,     0,
      12,    32,     0,    31,    30,   136,     9,   137,     0,    94,
       0,    23,    25,   136,     0,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   149,   150,     0,   103,     0,   102,     0,
      95,   103,    97,   102,   141,    92,     0,    90,   136,    75,
      76,     0,     1,     5,    16,    15,    13,    14,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
      95,     0,     6,    24,    26,     0,     0,    53,     0,     0,
      85,     0,     0,     0,     0,   106,   104,   128,   136,   143,
       0,     0,   102,   142,     0,   107,   108,   109,   110,   111,
     112,   113,   114,    74,   151,     0,     0,   165,     0,   166,
      98,     0,   168,     0,    77,    79,    81,    83,    63,    66,
      72,    69,    57,    60,   162,   163,   164,    64,    62,    67,
      65,    73,    71,    70,    68,    80,    78,    84,    82,    58,
      56,    61,    59,   100,   154,   153,   159,   158,   160,   155,
     156,   157,     0,     0,   102,     0,   166,     0,     7,     0,
      38,     0,    36,     0,     0,     0,    86,     0,     0,     0,
       0,   145,   146,   144,     0,   138,     0,    96,    99,     0,
      93,     0,     0,     0,   146,   144,     0,   138,     0,     0,
      35,     0,     0,     0,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     147,   101,   161,     0,     0,     0,     0,     0,    39,     0,
       0,    37,     0,    87,    88,     0,     0,     0,     0,   123,
     122,   130,   148,   115,   129,     0,     0,     0,    20,   148,
       0,     0,    28,    40,     0,     0,     0,     0,    19,    18,
      48,    85,    85,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   139,     0,     0,    22,    21,   140,   139,     0,
       0,    89,     0,     0,   152,   124,   116,   117,   118,   119,
     120,   121,     0,     0,     0,     0,    49,     0,     0,   127,
     126,   131,     0,     0,     0,     0,     0,    44,    51,    50,
     125,     0,    45,    20,     0,    46,     0,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,   121,   122,    28,    88,   300,   287,    40,
     209,    29,    30,   128,    31,   217,    75,    76,    69,    70,
      71,    77,    33,    73,    43
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -316
static const yytype_int16 yypact[] =
{
     692,     9,  -316,  1584,  1584,     5,  -316,  -316,  1744,   -21,
    -316,   -30,    -9,  -316,  -316,   304,  -316,  -316,  1744,  1744,
    1584,  1744,  1616,  1584,    52,   139,   789,  -316,  -316,    10,
    -316,    96,   164,  -316,  1999,    12,  -316,    -7,  1584,  1744,
    1488,    28,   126,  -316,  1488,   122,  1744,   694,    -8,  1744,
     142,  1744,  1648,   451,  1680,  1744,  1744,  1744,  1744,  1744,
    1744,  1744,  1744,  -316,  -316,    -6,   164,   128,  1899,    29,
     376,  -316,  -316,  2089,  -316,  -316,    68,  -316,    24,  -316,
    2080,   137,  -316,  -316,  -316,  -316,  -316,  -316,  -316,  1584,
    1584,  1744,  1744,  1744,  1744,  1744,  1744,  1744,  1744,  1744,
    1744,  1744,  1744,  1744,  1584,  1584,  1744,  1744,  1744,  1744,
    1744,  1744,  1744,  1744,  1744,  1744,  1744,   451,  1680,  1999,
    1520,   923,  -316,  -316,  -316,  1175,  1744,  -316,   120,   143,
     160,   135,  1552,   161,   -13,    96,  -316,  -316,    25,  -316,
       6,    33,  1831,  -316,   733,  -316,  -316,  -316,  -316,  -316,
    -316,  -316,  -316,  -316,  -316,  1744,  1744,  -316,  1744,   163,
    -316,  1744,  -316,  1744,  -316,  2053,   176,  2026,  2124,  2124,
    2124,  2124,  2124,  2124,   171,   171,   209,  -316,  2089,  -316,
    2089,  -316,  2089,  -316,  2089,  -316,  2053,   176,  2026,  -316,
    2089,  -316,  2089,  2116,   209,   209,   171,   171,    87,   166,
     166,   166,    32,    85,  1865,   925,  -316,  1584,  -316,    60,
    -316,  1237,  -316,  1776,  1488,   152,   167,    86,   183,   192,
    1744,  -316,   193,   196,  1744,    13,  1114,  1712,  -316,  1744,
    -316,    90,  1744,  1744,  -316,  -316,  1744,   186,  1488,  1488,
    -316,  1488,  1300,  1616,   988,  1363,   160,   178,   211,  1488,
     212,   216,   204,  1744,  1808,  1177,  1808,  1744,  1744,  -316,
    -316,  2124,  2124,  1239,  1744,   923,  1112,  1426,  -316,    77,
    1488,  -316,   104,  -316,   201,   606,   206,   214,  1744,  -316,
    -316,  -316,     8,  -316,  -316,   208,   493,   217,  1967,  -316,
     218,  1053,   270,  -316,   856,   986,  1488,   220,  -316,  -316,
    -316,   160,   160,  1302,  1744,  1744,  1744,  1744,  1744,  1744,
    1744,   242,   245,  1744,  1744,  -316,  -316,  -316,  -316,  1049,
     606,  -316,   121,   129,  -316,  2124,  -316,  -316,  -316,  -316,
    -316,  -316,  1744,  1808,  1365,  1429,  -316,  1488,  1488,  -316,
    -316,  -316,   246,  1744,   606,   606,  1744,  1491,  -316,  -316,
    2124,  1744,  -316,  1926,  1744,  1940,  1744,  -316
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -316,  -316,  -316,   149,   197,   264,   102,  -314,  -315,    -3,
      26,  -316,  -316,  -316,   157,  -244,   131,   -44,  -316,   -34,
     182,   531,   -35,     0,   333
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -169
static const yytype_int16 yytable[] =
{
      34,    44,   272,    42,    42,   120,   336,   134,    47,   141,
      84,    48,   -33,    36,    85,   132,   -33,   137,    63,    64,
      68,    89,    90,    80,    50,  -132,    34,   129,    84,  -132,
     348,   349,    85,    89,    90,    49,   352,    45,   119,   161,
      34,   357,   221,   304,    34,    51,   130,   117,   256,   153,
     131,   118,   119,   142,   144,    89,    90,   322,   323,    89,
      90,   222,    86,    87,   -33,   -33,   239,   257,   240,   305,
     306,   307,   308,   203,   309,   310,   -91,  -132,  -132,   -91,
      86,    87,   156,   -91,    81,   161,   157,   234,   223,   165,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     178,   180,   182,   184,   186,   188,   190,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   204,   205,   231,
     161,    34,   227,    89,    90,    34,    84,   162,   212,   161,
      85,   114,   115,   116,   213,   214,   294,   161,   248,    82,
     235,   249,   161,   123,   124,   260,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   226,   248,   126,   233,   296,
      41,    41,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   248,   133,   215,   337,    65,    86,    87,
      79,   248,    32,   154,   338,    32,    32,    91,    92,    93,
      94,   163,   216,   125,   218,    65,   220,    27,   229,   269,
      95,    96,    66,    89,   238,    32,   246,    42,    32,   135,
     140,    34,   116,   244,    34,   114,   115,   116,   250,   281,
      66,   284,    32,    27,   255,   247,    32,   251,   253,    97,
      98,   254,   261,   262,    66,    66,   263,   273,    34,    34,
     264,    34,    34,   274,   276,    34,   164,   166,   277,    34,
     111,   112,   113,   114,   115,   116,   278,   286,   288,   297,
     301,   185,   187,   311,   291,    34,    34,    34,   302,   314,
      34,    32,    32,   317,   202,    34,   239,   332,   303,   321,
     333,   346,   177,   179,   181,   183,    32,    32,   189,   191,
      83,   292,   230,     0,    34,    34,    34,     0,   341,    66,
       0,     0,     0,    32,   325,     0,     0,    32,     0,     0,
       0,     0,     0,   334,   335,     0,     0,     0,   208,    34,
      34,     0,   208,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,    34,    34,    52,
       0,     0,     0,   347,    34,    34,   350,     0,     0,     0,
       0,   353,     0,     0,   355,    78,   288,     0,    53,    35,
     242,     0,    54,   245,    41,    55,    56,    57,    58,    59,
      60,    61,    62,    35,     0,     0,     0,    35,     0,     0,
       0,     0,     0,     0,    78,   138,    78,   265,   266,    32,
     267,     0,     0,    32,     0,    11,    32,     0,   275,     0,
       0,     0,     0,     0,     0,    12,    13,    14,    37,     0,
      17,     0,     0,     0,     0,    18,    19,     0,     0,   295,
      32,    32,     0,    32,    32,     0,     0,    32,   158,     0,
      46,    32,    39,   159,    22,     0,     0,     0,     0,   208,
       0,     0,   208,   319,     0,   320,    24,    32,    32,    32,
      78,     0,    32,     0,    35,     0,     0,    32,    35,     0,
       0,     0,   208,   208,   208,     0,     0,     0,     0,     0,
      11,     0,   208,     0,     0,     0,    32,    32,    32,     0,
      12,    13,    14,    37,     0,    17,   344,   345,     0,     0,
      18,    19,   208,     0,    78,     0,    78,     0,     0,     0,
       0,    32,    32,     0,     0,    38,   139,    39,     0,    22,
       0,    23,     0,    97,    98,    99,   208,   208,     0,    32,
      32,    24,     0,     0,     0,     0,    32,    32,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   208,   208,     0,    35,     0,     0,    35,   312,     0,
       0,    67,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   313,     0,     0,     0,     0,     0,     0,    67,
      72,    35,    35,     0,    35,    35,    78,    67,    35,     0,
      72,     0,    35,   136,     0,     0,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,     0,     0,    35,    35,
      35,   160,     0,    35,     0,     0,   298,     1,    35,     0,
       2,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       0,     0,   -17,   299,    10,    11,     0,    35,    35,    35,
       0,     0,     0,     0,     0,    12,    13,    14,    15,    16,
      17,     0,     0,     0,     0,    18,    19,     0,     0,     0,
       0,   160,    35,    35,     0,     0,     0,   211,     0,     0,
      20,     0,    21,   160,    22,     0,    23,     0,     0,     0,
      35,    35,     0,     0,     0,     0,    24,    35,    35,     0,
       0,     0,     0,     0,     0,     0,     0,    72,     0,   228,
       0,     0,    -2,     1,     0,     0,     2,     3,   127,     0,
       0,     4,     5,     6,     7,     8,     0,     0,     9,     0,
      10,    11,     0,     0,    97,    98,    99,     0,     0,     0,
       0,    12,    13,    14,    15,    16,    17,     0,     0,     0,
       0,    18,    19,   109,   110,   111,   112,   113,   114,   115,
     116,     0,     0,     0,     0,     0,    20,     0,    21,     0,
      22,   252,    23,    97,    98,    99,     0,     0,   160,     0,
     259,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,   279,   280,     0,   283,   285,    -3,
       1,     0,   225,     2,     3,   290,     0,     0,     4,     5,
       6,     7,     8,     0,     0,     9,     0,    10,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    13,
      14,    15,    16,    17,     0,     0,     0,     0,    18,    19,
       0,     0,     0,     0,     0,     0,   326,   327,   328,   329,
     330,   331,     0,    20,     0,    21,     0,    22,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     1,     0,    24,
       2,     3,     0,   339,   340,     4,     5,     6,     7,     8,
       0,     0,     0,     0,    10,    11,  -168,  -168,  -168,     0,
       0,     0,     0,     0,     0,    12,    13,    14,    15,    16,
      17,     0,     0,     0,     0,    18,    19,  -168,  -168,  -168,
    -168,  -168,  -168,     0,     0,     0,     0,     0,     0,     0,
      20,     0,    21,     0,    22,     0,    23,     0,     0,     0,
       0,     0,     0,     0,     1,     0,    24,     2,     3,   -27,
     207,   -27,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,    97,    98,    99,     0,     0,
       0,     0,    12,    13,    14,    15,    16,    17,     0,     0,
       0,     0,    18,    19,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,     0,     0,     0,    20,     0,    21,
       0,    22,     0,    23,   237,     0,     0,     1,     0,     0,
       2,     3,   270,    24,   -54,     4,     5,     6,     7,     8,
     -54,   -54,     0,     0,    10,    11,     0,     0,    97,    98,
      99,     0,     0,     0,     0,    12,    13,    14,    15,    16,
      17,     0,     0,     0,     0,    18,    19,   109,   110,   111,
     112,   113,   114,   115,   116,     0,     0,     0,     0,     0,
      20,     0,    21,     0,    22,     0,    23,     0,     0,     0,
       1,     0,     0,     2,     3,     0,    24,   -55,     4,     5,
       6,     7,     8,   -55,   -55,     0,     0,    10,    11,     0,
       0,     0,     0,    97,    98,    99,     0,     0,    12,    13,
      14,    15,    16,    17,     0,     0,     0,     0,    18,    19,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,    20,     0,    21,     0,    22,   318,    23,
       0,     0,     0,     1,     0,     0,     2,     3,   -29,    24,
     -29,     4,     5,     6,     7,     8,     0,     0,     0,     0,
      10,    11,     0,     0,    97,    98,    99,     0,     0,     0,
       0,    12,    13,    14,    15,    16,    17,     0,     0,     0,
       0,    18,    19,   109,   110,   111,   112,   113,   114,   115,
     116,     0,     0,     0,     0,     0,    20,     0,    21,   258,
      22,     0,    23,     0,     0,     0,     1,     0,     0,     2,
       3,     0,    24,   210,     4,     5,     6,     7,     8,     0,
       0,     0,     0,    10,    11,     0,     0,    97,    98,    99,
       0,     0,     0,     0,    12,    13,    14,    15,    16,    17,
       0,     0,     0,     0,    18,    19,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,    20,
       0,    21,   282,    22,     0,    23,     0,     0,     1,     0,
       0,     2,     3,     0,     0,    24,     4,     5,     6,     7,
       8,     0,     0,     0,     0,    10,    11,     0,     0,    97,
      98,    99,     0,     0,     0,     0,    12,    13,    14,    15,
      16,    17,     0,     0,     0,     0,    18,    19,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,   241,
       0,    20,     0,    21,   289,    22,     0,    23,     0,     0,
       0,     1,     0,     0,     2,     3,     0,    24,   268,     4,
       5,     6,     7,     8,     0,     0,     0,     0,    10,    11,
       0,     0,    97,    98,    99,     0,     0,     0,     0,    12,
      13,    14,    15,    16,    17,     0,     0,     0,     0,    18,
      19,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,     0,     0,     0,    20,     0,    21,   324,    22,     0,
      23,     0,     0,     0,     1,     0,     0,     2,     3,     0,
      24,   271,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,    97,    98,    99,     0,     0,
       0,     0,    12,    13,    14,    15,    16,    17,     0,     0,
       0,     0,    18,    19,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,     0,     0,     0,    20,     0,    21,
     342,    22,     0,    23,     0,     0,     0,     1,     0,     0,
       2,     3,     0,    24,   293,     4,     5,     6,     7,     8,
       0,     0,     0,     0,    10,    11,     0,     0,     0,    97,
      98,    99,     0,     0,     0,    12,    13,    14,    15,    16,
      17,     0,     0,     0,     0,    18,    19,     0,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
      20,   343,    21,     0,    22,     0,    23,     0,     0,     1,
       0,     0,     2,     3,     0,     0,    24,     4,     5,     6,
       7,     8,     0,     0,     0,     0,    10,    11,     0,     0,
       0,    97,    98,    99,     0,     0,     0,    12,    13,    14,
      15,    16,    17,     0,     0,     0,     0,    18,    19,     0,
     109,   110,   111,   112,   113,   114,   115,   116,     0,    11,
       0,     0,    20,   351,    21,     0,    22,     0,    23,    12,
      13,    14,    37,     0,    17,     0,     0,     0,    24,    18,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,   158,     0,    46,     0,    39,   206,    22,     0,
       0,    12,    13,    14,    37,     0,    17,     0,     0,     0,
      24,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,   158,     0,    46,     0,    39,   219,
      22,     0,     0,    12,    13,    14,    37,     0,    17,     0,
       0,     0,    24,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,    38,     0,
      39,     0,    22,     0,    23,    12,    13,    14,    37,     0,
      17,     0,     0,     0,    24,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
      46,     0,    39,     0,    22,    74,     0,    12,    13,    14,
      15,     0,    17,     0,     0,     0,    24,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,    38,     0,    21,     0,    22,     0,    23,    12,
      13,    14,    37,     0,    17,     0,     0,     0,    24,    18,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,    46,     0,    39,     0,    22,   143,
       0,    12,    13,    14,    37,     0,    17,     0,     0,     0,
      24,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,   158,     0,    46,     0,    39,     0,
      22,     0,     0,    12,    13,    14,    37,     0,    17,     0,
       0,     0,    24,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,    46,     0,
      39,     0,    22,     0,     0,    12,    13,    14,    37,     0,
      17,     0,     0,     0,    24,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
      46,     0,    39,     0,   243,     0,     0,    12,    13,    14,
      15,     0,    17,     0,     0,     0,    24,    18,    19,     0,
       0,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,     0,    46,     0,    21,     0,    22,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    24,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,     0,     0,     0,     0,     0,
     224,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
       0,     0,     0,     0,   236,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    97,    98,    99,     0,
       0,   155,     0,     0,     0,     0,     0,     0,     0,     0,
      97,    98,    99,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,     0,     0,     0,   315,   316,   354,   109,
     110,   111,   112,   113,   114,   115,   116,    97,    98,    99,
       0,     0,   356,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,   315,   316,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      97,    98,    99,   100,   101,   102,   103,     0,     0,    97,
      98,    99,     0,     0,     0,     0,   106,   107,   108,     0,
       0,   111,   112,   113,   114,   115,   116,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    97,    98,    99,     0,
       0,     0,     0,     0,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,   232,   109,   110,   111,   112,   113,
     114,   115,   116,   109,   110,   111,   112,   113,   114,   115,
     116
};

static const yytype_int16 yycheck[] =
{
       0,     4,   246,     3,     4,    39,   320,    51,     8,    53,
       0,    32,     0,     4,     4,    49,     4,    52,    18,    19,
      20,    27,    28,    23,    54,     0,    26,    35,     0,     4,
     344,   345,     4,    27,    28,    56,   351,    32,    38,    52,
      40,   356,    55,    35,    44,    54,    54,    54,    35,    55,
      58,    58,    52,    53,    54,    27,    28,   301,   302,    27,
      28,    55,    52,    53,    52,    53,     6,    54,     8,    61,
      62,    63,    64,   117,    66,    67,    52,    52,    53,    55,
      52,    53,    53,    59,    32,    52,    57,    55,    55,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   163,
      52,   121,   156,    27,    28,   125,     0,    59,     8,    52,
       4,    44,    45,    46,    14,    15,    59,    52,    52,     0,
      55,    55,    52,    41,    42,    55,    20,    21,    22,    23,
      24,    25,    26,    27,    28,   155,    52,    35,    71,    55,
       3,     4,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    52,    32,    32,    55,    20,    52,    53,
      23,    52,     0,    55,    55,     3,     4,    23,    24,    25,
      26,    54,    32,    44,    59,    38,    35,     0,    35,   243,
      36,    37,    20,    27,   207,    23,    54,   207,    26,    52,
      53,   211,    46,   213,   214,    44,    45,    46,    35,   254,
      38,   256,    40,    26,   224,    58,    44,    35,    35,    20,
      21,    35,   232,   233,    52,    53,   236,    59,   238,   239,
      54,   241,   242,    32,    32,   245,    89,    90,    32,   249,
      41,    42,    43,    44,    45,    46,    52,   257,   258,    58,
      54,   104,   105,    55,   264,   265,   266,   267,    54,    52,
     270,    89,    90,    55,   117,   275,     6,    35,   278,    59,
      35,    35,   100,   101,   102,   103,   104,   105,   106,   107,
      26,   265,   161,    -1,   294,   295,   296,    -1,   333,   117,
      -1,    -1,    -1,   121,   304,    -1,    -1,   125,    -1,    -1,
      -1,    -1,    -1,   313,   314,    -1,    -1,    -1,   121,   319,
     320,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,    -1,    -1,    -1,   337,   338,    35,
      -1,    -1,    -1,   343,   344,   345,   346,    -1,    -1,    -1,
      -1,   351,    -1,    -1,   354,    22,   356,    -1,    54,    26,
     211,    -1,    58,   214,   207,    61,    62,    63,    64,    65,
      66,    67,    68,    40,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,   238,   239,   207,
     241,    -1,    -1,   211,    -1,    19,   214,    -1,   249,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,
      34,    -1,    -1,    -1,    -1,    39,    40,    -1,    -1,   270,
     238,   239,    -1,   241,   242,    -1,    -1,   245,    52,    -1,
      54,   249,    56,    57,    58,    -1,    -1,    -1,    -1,   242,
      -1,    -1,   245,   294,    -1,   296,    70,   265,   266,   267,
     117,    -1,   270,    -1,   121,    -1,    -1,   275,   125,    -1,
      -1,    -1,   265,   266,   267,    -1,    -1,    -1,    -1,    -1,
      19,    -1,   275,    -1,    -1,    -1,   294,   295,   296,    -1,
      29,    30,    31,    32,    -1,    34,   337,   338,    -1,    -1,
      39,    40,   295,    -1,   161,    -1,   163,    -1,    -1,    -1,
      -1,   319,   320,    -1,    -1,    54,    55,    56,    -1,    58,
      -1,    60,    -1,    20,    21,    22,   319,   320,    -1,   337,
     338,    70,    -1,    -1,    -1,    -1,   344,   345,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,   344,   345,    -1,   211,    -1,    -1,   214,    55,    -1,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,   238,   239,    -1,   241,   242,   243,    46,   245,    -1,
      49,    -1,   249,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,   265,   266,
     267,    70,    -1,   270,    -1,    -1,     0,     1,   275,    -1,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    12,    13,
      -1,    -1,    16,    17,    18,    19,    -1,   294,   295,   296,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,
      -1,   120,   319,   320,    -1,    -1,    -1,   126,    -1,    -1,
      54,    -1,    56,   132,    58,    -1,    60,    -1,    -1,    -1,
     337,   338,    -1,    -1,    -1,    -1,    70,   344,   345,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,   158,
      -1,    -1,     0,     1,    -1,    -1,     4,     5,     4,    -1,
      -1,     9,    10,    11,    12,    13,    -1,    -1,    16,    -1,
      18,    19,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    39,    40,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    54,    -1,    56,    -1,
      58,   220,    60,    20,    21,    22,    -1,    -1,   227,    -1,
     229,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,   253,   254,    -1,   256,   257,     0,
       1,    -1,    59,     4,     5,   264,    -1,    -1,     9,    10,
      11,    12,    13,    -1,    -1,    16,    -1,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,   305,   306,   307,   308,
     309,   310,    -1,    54,    -1,    56,    -1,    58,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    70,
       4,     5,    -1,   332,   333,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    56,    -1,    58,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    70,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    20,    21,    22,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    39,    40,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    54,    -1,    56,
      -1,    58,    -1,    60,    59,    -1,    -1,     1,    -1,    -1,
       4,     5,     4,    70,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    18,    19,    -1,    -1,    20,    21,
      22,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    39,    40,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    56,    -1,    58,    -1,    60,    -1,    -1,    -1,
       1,    -1,    -1,     4,     5,    -1,    70,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    -1,
      -1,    -1,    -1,    20,    21,    22,    -1,    -1,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    54,    -1,    56,    -1,    58,    55,    60,
      -1,    -1,    -1,     1,    -1,    -1,     4,     5,     6,    70,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    39,    40,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    54,    -1,    56,    55,
      58,    -1,    60,    -1,    -1,    -1,     1,    -1,    -1,     4,
       5,    -1,    70,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    18,    19,    -1,    -1,    20,    21,    22,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    39,    40,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    56,    55,    58,    -1,    60,    -1,    -1,     1,    -1,
      -1,     4,     5,    -1,    -1,    70,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    20,
      21,    22,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    39,    40,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    52,
      -1,    54,    -1,    56,    55,    58,    -1,    60,    -1,    -1,
      -1,     1,    -1,    -1,     4,     5,    -1,    70,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    39,
      40,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    56,    55,    58,    -1,
      60,    -1,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      70,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    20,    21,    22,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    39,    40,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    54,    -1,    56,
      55,    58,    -1,    60,    -1,    -1,    -1,     1,    -1,    -1,
       4,     5,    -1,    70,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    20,
      21,    22,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    39,    40,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      54,    52,    56,    -1,    58,    -1,    60,    -1,    -1,     1,
      -1,    -1,     4,     5,    -1,    -1,    70,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      -1,    20,    21,    22,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    19,
      -1,    -1,    54,    52,    56,    -1,    58,    -1,    60,    29,
      30,    31,    32,    -1,    34,    -1,    -1,    -1,    70,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    52,    -1,    54,    -1,    56,    57,    58,    -1,
      -1,    29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,
      70,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    52,    -1,    54,    -1,    56,    57,
      58,    -1,    -1,    29,    30,    31,    32,    -1,    34,    -1,
      -1,    -1,    70,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    54,    -1,
      56,    -1,    58,    -1,    60,    29,    30,    31,    32,    -1,
      34,    -1,    -1,    -1,    70,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,
      54,    -1,    56,    -1,    58,    59,    -1,    29,    30,    31,
      32,    -1,    34,    -1,    -1,    -1,    70,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    54,    -1,    56,    -1,    58,    -1,    60,    29,
      30,    31,    32,    -1,    34,    -1,    -1,    -1,    70,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
      -1,    29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,
      70,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    52,    -1,    54,    -1,    56,    -1,
      58,    -1,    -1,    29,    30,    31,    32,    -1,    34,    -1,
      -1,    -1,    70,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    54,    -1,
      56,    -1,    58,    -1,    -1,    29,    30,    31,    32,    -1,
      34,    -1,    -1,    -1,    70,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,
      54,    -1,    56,    -1,    58,    -1,    -1,    29,    30,    31,
      32,    -1,    34,    -1,    -1,    -1,    70,    39,    40,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    54,    -1,    56,    -1,    58,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    20,    21,    22,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    50,    51,    52,    39,
      40,    41,    42,    43,    44,    45,    46,    20,    21,    22,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    50,    51,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    20,
      21,    22,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,
      -1,    41,    42,    43,    44,    45,    46,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    39,    40,    41,    42,    43,    44,    45,
      46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     9,    10,    11,    12,    13,    16,
      18,    19,    29,    30,    31,    32,    33,    34,    39,    40,
      54,    56,    58,    60,    70,    73,    74,    76,    77,    83,
      84,    86,    92,    94,    95,    96,     4,    32,    54,    56,
      81,    86,    95,    96,    81,    32,    54,    95,    32,    56,
      54,    54,    35,    54,    58,    61,    62,    63,    64,    65,
      66,    67,    68,    95,    95,    86,    92,    93,    95,    90,
      91,    92,    93,    95,    59,    88,    89,    93,    96,    86,
      95,    32,     0,    77,     0,     4,    52,    53,    78,    27,
      28,    23,    24,    25,    26,    36,    37,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    54,    58,    95,
      91,    75,    76,    78,    78,    75,    35,     4,    85,    35,
      54,    58,    91,    32,    89,    86,    93,    94,    96,    55,
      86,    89,    95,    59,    95,    93,    93,    93,    93,    93,
      93,    93,    93,    55,    55,    52,    53,    57,    52,    57,
      93,    52,    59,    54,    86,    95,    86,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    92,    95,    92,
      95,    92,    95,    92,    95,    86,    95,    86,    95,    92,
      95,    92,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    86,    89,    95,    95,    57,     7,    76,    82,
       8,    93,     8,    14,    15,    32,    32,    87,    59,    57,
      35,    55,    55,    55,    69,    59,    95,    91,    93,    35,
      88,    89,    38,    71,    55,    55,    69,    59,    81,     6,
       8,    52,    75,    58,    95,    75,    54,    58,    52,    55,
      35,    35,    93,    35,    35,    95,    35,    54,    55,    93,
      55,    95,    95,    95,    54,    75,    75,    75,     8,    89,
       4,     8,    87,    59,    32,    75,    32,    32,    52,    93,
      93,    94,    55,    93,    94,    93,    95,    80,    95,    55,
      93,    95,    82,     8,    59,    75,    55,    58,     0,    17,
      79,    54,    54,    95,    35,    61,    62,    63,    64,    66,
      67,    55,    55,    69,    52,    50,    51,    55,    55,    75,
      75,    59,    87,    87,    55,    95,    93,    93,    93,    93,
      93,    93,    35,    35,    95,    95,    79,    55,    55,    93,
      93,    94,    55,    52,    75,    75,    35,    95,    79,    79,
      95,    52,    80,    95,    52,    95,    52,    80
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
#line 99 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", (yyvaluep->str));
#endif
  free((yyvaluep->str));
};

/* Line 1000 of yacc.c  */
#line 1825 "cipsycon.tab.c"
	break;
      case 32: /* "\"identifier\"" */

/* Line 1000 of yacc.c  */
#line 99 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", (yyvaluep->str));
#endif
  free((yyvaluep->str));
};

/* Line 1000 of yacc.c  */
#line 1839 "cipsycon.tab.c"
	break;
      case 33: /* "\"HookCommand\"" */

/* Line 1000 of yacc.c  */
#line 99 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", (yyvaluep->str));
#endif
  free((yyvaluep->str));
};

/* Line 1000 of yacc.c  */
#line 1853 "cipsycon.tab.c"
	break;
      case 74: /* "block_func" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1867 "cipsycon.tab.c"
	break;
      case 75: /* "block" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1881 "cipsycon.tab.c"
	break;
      case 76: /* "line" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1895 "cipsycon.tab.c"
	break;
      case 77: /* "line_func" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1909 "cipsycon.tab.c"
	break;
      case 80: /* "exp_time" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1923 "cipsycon.tab.c"
	break;
      case 81: /* "conditional" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1937 "cipsycon.tab.c"
	break;
      case 82: /* "elseif_list" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1951 "cipsycon.tab.c"
	break;
      case 83: /* "stmt" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1965 "cipsycon.tab.c"
	break;
      case 84: /* "funcdef" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1979 "cipsycon.tab.c"
	break;
      case 85: /* "case_list" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1993 "cipsycon.tab.c"
	break;
      case 86: /* "condition" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2007 "cipsycon.tab.c"
	break;
      case 87: /* "id_list" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2021 "cipsycon.tab.c"
	break;
      case 88: /* "arg" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2035 "cipsycon.tab.c"
	break;
      case 89: /* "arg_list" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2049 "cipsycon.tab.c"
	break;
      case 90: /* "matrix" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2063 "cipsycon.tab.c"
	break;
      case 91: /* "vector" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2077 "cipsycon.tab.c"
	break;
      case 92: /* "range" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2091 "cipsycon.tab.c"
	break;
      case 93: /* "exp_range" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2105 "cipsycon.tab.c"
	break;
      case 94: /* "assign" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2119 "cipsycon.tab.c"
	break;
      case 95: /* "exp" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2133 "cipsycon.tab.c"
	break;
      case 96: /* "initcell" */

/* Line 1000 of yacc.c  */
#line 92 "cipsycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2147 "cipsycon.tab.c"
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
#line 83 "cipsycon.y"
{
  if (ErrorMsg) {
	free(ErrorMsg);
	ErrorMsg = NULL;
  }
  *errmsg = NULL;
}

/* Line 1242 of yacc.c  */
#line 2308 "cipsycon.tab.c"

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
#line 119 "cipsycon.y"
    { *pproot = NULL;;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 121 "cipsycon.y"
    { *pproot = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 125 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 127 "cipsycon.y"
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
#line 153 "cipsycon.y"
    {
		if ((yyvsp[(1) - (1)].pnode)) // if cond1, x=1, end ==> x=1 comes here.
			(yyval.pnode) = (yyvsp[(1) - (1)].pnode);
		else
			(yyval.pnode) = newAstNode(NODE_BLOCK, (yyloc));
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 160 "cipsycon.y"
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
#line 187 "cipsycon.y"
    { (yyval.pnode) = NULL;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 189 "cipsycon.y"
    { //yyn=9
		(yyval.pnode) = NULL;
		yyerrok;
	;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 194 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (2)].pnode);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 198 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 200 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 211 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 213 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_MSEC, (yyloc));
		(yyval.pnode)->child = (yyvsp[(1) - (2)].pnode);
	;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 218 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_USEC, (yyloc));
		(yyval.pnode)->child = (yyvsp[(1) - (2)].pnode);
	;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 225 "cipsycon.y"
    {	(yyval.pnode) = (yyvsp[(1) - (1)].pnode);	;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 227 "cipsycon.y"
    {	(yyval.pnode) = (yyvsp[(1) - (2)].pnode);	;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 229 "cipsycon.y"
    {	(yyval.pnode) = (yyvsp[(1) - (1)].pnode);	;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 231 "cipsycon.y"
    {	(yyval.pnode) = (yyvsp[(1) - (2)].pnode);	;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 235 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_IF, (yyloc));
	;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 239 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_IF, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode);
		(yyvsp[(2) - (4)].pnode)->alt = (yyvsp[(4) - (4)].pnode);
	;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 246 "cipsycon.y"
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

  case 30:

/* Line 1455 of yacc.c  */
#line 261 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 263 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 265 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 267 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 269 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = malloc(strlen((yyvsp[(1) - (1)].str))+1);
 		strcpy((yyval.pnode)->str, (yyvsp[(1) - (1)].str));
 		free((yyvsp[(1) - (1)].str));
	;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 276 "cipsycon.y"
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

  case 36:

/* Line 1455 of yacc.c  */
#line 290 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (4)].pnode);
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode)->child;
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 298 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (6)].pnode);
		(yyvsp[(2) - (6)].pnode)->next = (yyvsp[(3) - (6)].pnode)->child;
		(yyvsp[(3) - (6)].pnode)->tail->next = (yyvsp[(5) - (6)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (6)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 307 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_WHILE, (yyloc));
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 313 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_FOR, (yyloc));
		(yyval.pnode)->child = newAstNode('=', (yylsp[(2) - (6)]));
		(yyval.pnode)->child->str = (yyvsp[(2) - (6)].str);
		(yyval.pnode)->child->child = (yyvsp[(4) - (6)].pnode);
		(yyval.pnode)->child->next = (yyvsp[(5) - (6)].pnode);
	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 321 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_FOR, (yyloc));
		(yyval.pnode)->child = newAstNode('=', (yylsp[(2) - (7)]));
		(yyval.pnode)->child->str = (yyvsp[(2) - (7)].str);
		(yyval.pnode)->child->child = (yyvsp[(4) - (7)].pnode);
		(yyval.pnode)->child->next = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 329 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_RETURN, (yyloc));
	;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 333 "cipsycon.y"
    { (yyval.pnode) = newAstNode(T_BREAK, (yyloc));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 335 "cipsycon.y"
    { (yyval.pnode) = newAstNode(T_CONTINUE, (yyloc));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 337 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CIPULSE3, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (10)].pnode);
		(yyvsp[(2) - (10)].pnode)->next = (yyvsp[(4) - (10)].pnode);
		(yyvsp[(4) - (10)].pnode)->next = (yyvsp[(6) - (10)].pnode);
		(yyvsp[(6) - (10)].pnode)->next = (yyvsp[(8) - (10)].pnode);
		(yyvsp[(8) - (10)].pnode)->next = (yyvsp[(10) - (10)].pnode);
	;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 346 "cipsycon.y"
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

  case 46:

/* Line 1455 of yacc.c  */
#line 356 "cipsycon.y"
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

  case 47:

/* Line 1455 of yacc.c  */
#line 367 "cipsycon.y"
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

  case 48:

/* Line 1455 of yacc.c  */
#line 381 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(2) - (7)].str);
		(yyval.pnode)->child = (yyvsp[(4) - (7)].pnode);
		(yyvsp[(4) - (7)].pnode)->next = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 388 "cipsycon.y"
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

  case 50:

/* Line 1455 of yacc.c  */
#line 398 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(6) - (11)].str);
		(yyval.pnode)->child = (yyvsp[(8) - (11)].pnode);
		(yyvsp[(8) - (11)].pnode)->next = (yyvsp[(10) - (11)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (11)].pnode);

		;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 407 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(6) - (11)].str);
		(yyval.pnode)->child = (yyvsp[(8) - (11)].pnode);
		(yyvsp[(8) - (11)].pnode)->next = (yyvsp[(10) - (11)].pnode);
		(yyvsp[(10) - (11)].pnode)->next = newAstNode(NODE_INITCELL, (yylsp[(2) - (11)]));
		(yyvsp[(10) - (11)].pnode)->next->str = (yyvsp[(2) - (11)].str);
	;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 418 "cipsycon.y"
    { (yyval.pnode) = newAstNode(T_SWITCH, (yyloc));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 420 "cipsycon.y"
    { (yyval.pnode) = newAstNode(T_SWITCH, (yyloc));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 422 "cipsycon.y"
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

  case 55:

/* Line 1455 of yacc.c  */
#line 432 "cipsycon.y"
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

  case 56:

/* Line 1455 of yacc.c  */
#line 444 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('<', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 446 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('<', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 448 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('<', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 450 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('>', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 452 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('>', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 454 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('>', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 456 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_EQ, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 458 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_EQ, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 460 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_EQ, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 462 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_NE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 464 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_NE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 466 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_NE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 468 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_GE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 470 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_GE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 472 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_GE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 474 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_LE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 476 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_LE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 478 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_LE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 480 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 486 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_LOGIC_NOT, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (2)].pnode);
	;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 491 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_LOGIC_NOT, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (2)].pnode);
	;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 496 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 498 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 500 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 502 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 504 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 506 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 508 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 510 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 514 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
	;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 518 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->tail = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->tail->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 524 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->tail = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->tail->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 530 "cipsycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->tail = (yyvsp[(1) - (3)].pnode)->tail->next = newAstNode(T_ID, (yylsp[(3) - (3)]));
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
		(yyval.pnode)->tail->str = (yyvsp[(3) - (3)].str);
	;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 536 "cipsycon.y"
    {
		(yyvsp[(1) - (5)].pnode)->tail = (yyvsp[(1) - (5)].pnode)->tail->next = newAstNode(NODE_INITCELL, (yylsp[(3) - (5)]));
		(yyval.pnode) = (yyvsp[(1) - (5)].pnode);
		(yyval.pnode)->tail->str = (yyvsp[(3) - (5)].str);
	;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 544 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 546 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 550 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_ARGS, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->tail = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 555 "cipsycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->tail = (yyvsp[(1) - (3)].pnode)->tail->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 562 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_MATRIX, (yyloc));
	;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 566 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_MATRIX, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->tail = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 571 "cipsycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->tail = (yyvsp[(1) - (3)].pnode)->tail->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 578 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_VECTOR, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->tail = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 583 "cipsycon.y"
    {
		(yyvsp[(1) - (2)].pnode)->tail = (yyvsp[(1) - (2)].pnode)->tail->next = (yyvsp[(2) - (2)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (2)].pnode);
	;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 588 "cipsycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->tail = (yyvsp[(1) - (3)].pnode)->tail->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 595 "cipsycon.y"
    {
		(yyval.pnode) = makeFunctionCall(":", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));
	;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 599 "cipsycon.y"
    {
		(yyval.pnode) = makeFunctionCall(":", (yyvsp[(1) - (5)].pnode), (yyvsp[(5) - (5)].pnode), (yyloc));
		(yyval.pnode)->tail = (yyvsp[(5) - (5)].pnode)->next = (yyvsp[(3) - (5)].pnode);
	;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 606 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 608 "cipsycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 612 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 618 "cipsycon.y"
    { // Only to be used when RHS is a UDF. 5/18/2017 bjkwon
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->child = (yyvsp[(5) - (5)].pnode);
		(yyval.pnode)->alt = (yyvsp[(2) - (5)].pnode);
	;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 624 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 630 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('+', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 636 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('-', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 642 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('*', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 648 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('/', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 654 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNodeFunctionCall('^', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 660 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('@', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 666 "cipsycon.y"
    { 
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str); 
		(yyval.pnode)->child = makeCompoundLevelOpNode((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(1) - (3)]), (yylsp[(3) - (3)]));
	;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 672 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode(T_OP_CONCAT, (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 678 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 685 "cipsycon.y"
    {
		(yyval.pnode) = Restring("+=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 689 "cipsycon.y"
    {
		(yyval.pnode) = Restring("-=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 693 "cipsycon.y"
    {
		(yyval.pnode) = Restring("*=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 697 "cipsycon.y"
    {
		(yyval.pnode) = Restring("/=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 701 "cipsycon.y"
    {
		(yyval.pnode) = Restring("@=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 705 "cipsycon.y"
    {
		(yyval.pnode) = Restring("@@=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 709 "cipsycon.y"
    { /* x(45)=723 or x(id1:id2) = id1:id2  or x(array) = scalar */
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 716 "cipsycon.y"
    { /* x(x>0) = scalar */
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 723 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (8)].str);
		(yyval.pnode)->child = (yyvsp[(8) - (8)].pnode);
		(yyval.pnode)->alt = newAstNode(NODE_IDLIST, (yyloc));
		(yyval.pnode)->alt->child = (yyvsp[(5) - (8)].pnode);
		(yyval.pnode)->alt->alt = (yyvsp[(3) - (8)].pnode);
	;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 732 "cipsycon.y"
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

  case 126:

/* Line 1455 of yacc.c  */
#line 743 "cipsycon.y"
    { // v{2}(4)=1 
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(9) - (9)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (9)].pnode);
		(yyvsp[(3) - (9)].pnode)->next = (yyvsp[(6) - (9)].pnode);
	;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 751 "cipsycon.y"
    { // v{2}(4:6)=1 
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(9) - (9)].pnode);
		(yyval.pnode)->alt = (yyvsp[(3) - (9)].pnode);
		(yyvsp[(3) - (9)].pnode)->next = (yyvsp[(6) - (9)].pnode);
	;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 759 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 765 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(6) - (6)].pnode)->alt = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 772 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(6) - (6)].pnode)->alt = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 779 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(9) - (9)].pnode);
		(yyvsp[(9) - (9)].pnode)->alt = (yyvsp[(6) - (9)].pnode);
		(yyvsp[(6) - (9)].pnode)->alt = (yyvsp[(3) - (9)].pnode);
	;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 787 "cipsycon.y"
    { // x={"bjk",noise(300), 4.5555}
		(yyval.pnode) = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 796 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_NUMBER, (yyloc));
		(yyval.pnode)->dval = (yyvsp[(1) - (1)].dval);
	;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 801 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_STRING, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 806 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_ENDPOINT, (yyloc));
		(yyval.pnode)->str = NULL;
	;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 811 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 815 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (1)].str);
//		yyPrintf("T_ID", $$);
	;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 821 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (4)].pnode);
	;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 827 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (7)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (7)].pnode);
		(yyvsp[(3) - (7)].pnode)->alt = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 834 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (7)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (7)].pnode);
		(yyvsp[(3) - (7)].pnode)->alt = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 841 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
	;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 845 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 850 "cipsycon.y"
    { // I don't know what this is doing.... bjk 3/28/2017 
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 855 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->type = NODE_CALL;
 		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 863 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_REPLICA, (yyloc));
		(yyval.pnode)->child = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->child->type = NODE_CALL;
		// At this point, this makes NODE_CALL with NULL str. This is to be resolved in AstSig.cpp-----AstNode *tp = searchtree(p, NODE_CALL);
	;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 870 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->tail = (yyvsp[(3) - (4)].pnode); // leaving a mark for conditional indexing 3/28/2017 bjk
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 879 "cipsycon.y"
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

  case 148:

/* Line 1455 of yacc.c  */
#line 890 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_EXTRACT, (yyloc));
		(yyval.pnode)->child = newAstNode(T_ID, (yylsp[(1) - (6)]));
		(yyval.pnode)->child->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child->next = (yyvsp[(3) - (6)].pnode);
		(yyvsp[(3) - (6)].pnode)->next = (yyvsp[(5) - (6)].pnode);
	;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 898 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_NEGATIVE, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (2)].pnode);
	;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 903 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (2)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 909 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 915 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_SIGMA, (yyloc));
		(yyval.pnode)->child = newAstNode('=', (yylsp[(3) - (8)]));
		(yyval.pnode)->child->str = (yyvsp[(3) - (8)].str);
		(yyval.pnode)->child->child = (yyvsp[(5) - (8)].pnode);
		(yyval.pnode)->child->next = (yyvsp[(7) - (8)].pnode);
	;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 923 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('+', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 925 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('-', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 927 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('*', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 929 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('/', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 931 "cipsycon.y"
    { (yyval.pnode) = makeFunctionCall("^", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 933 "cipsycon.y"
    { (yyval.pnode) = makeFunctionCall("caret", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 935 "cipsycon.y"
    { (yyval.pnode) = makeFunctionCall("shift_spectrum", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 937 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode('@', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 939 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INTERPOL, (yyloc));
		(yyval.pnode)->child = (yyvsp[(1) - (5)].pnode);
		(yyvsp[(1) - (5)].pnode)->next = (yyvsp[(3) - (5)].pnode);
		(yyvsp[(3) - (5)].pnode)->next = (yyvsp[(5) - (5)].pnode);
		(yyval.pnode)->tail = (yyvsp[(5) - (5)].pnode);
	;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 947 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_SHIFT, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 949 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_SHIFT2, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 951 "cipsycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_CONCAT, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 953 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 959 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 965 "cipsycon.y"
    {
		(yyval.pnode) = newAstNode(T_REPLICA, (yyloc));
		(yyval.pnode)->str = NULL;
	;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 972 "cipsycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->type = NODE_INITCELL;
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->col = (yyloc).first_column;
	;}
    break;



/* Line 1455 of yacc.c  */
#line 4105 "cipsycon.tab.c"
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
#line 980 "cipsycon.y"


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
