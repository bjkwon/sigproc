
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
     T_DUR = 287,
     T_LENGTH = 288,
     T_NEGATIVE = 289,
     T_POSITIVE = 290,
     T_LOGIC_NOT = 291,
     T_REPLICA = 292
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
#line 102 "psycon.y"

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
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2586

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNRULES -- Number of states.  */
#define YYNSTATES  367

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
       2,     2,     2,    58,     2,    67,    40,    41,     2,     2,
      52,    53,    43,    39,    50,    38,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    51,
      35,    34,    36,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,    68,    55,    66,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    46,
      47,    48,    49,    59,    60,    61,    62,    63,    64,    65
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    16,    18,
      21,    24,    26,    28,    30,    32,    34,    36,    37,    39,
      41,    43,    45,    47,    53,    60,    68,    77,    83,    90,
      98,   107,   112,   119,   124,   129,   135,   141,   148,   156,
     158,   160,   162,   170,   180,   192,   204,   205,   210,   211,
     213,   219,   226,   230,   234,   238,   242,   246,   250,   254,
     258,   262,   266,   270,   274,   278,   282,   286,   290,   294,
     298,   302,   305,   308,   312,   316,   320,   324,   325,   327,
     331,   335,   341,   343,   345,   347,   351,   352,   354,   358,
     360,   363,   367,   371,   377,   379,   381,   385,   389,   393,
     397,   401,   405,   409,   413,   417,   424,   433,   442,   451,
     460,   469,   478,   485,   492,   501,   513,   523,   533,   537,
     544,   551,   561,   565,   574,   583,   585,   587,   589,   591,
     593,   598,   606,   614,   618,   622,   627,   632,   637,   643,
     650,   653,   656,   660,   669,   673,   677,   681,   685,   689,
     693,   697,   701,   707,   711,   715,   719,   723,   727,   729
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      70,     0,    -1,    -1,    71,    -1,    74,    -1,    71,    74,
      -1,    73,    -1,    72,    73,    -1,     4,    -1,     1,     4,
      -1,    77,    75,    -1,    73,    -1,    78,    -1,    50,    -1,
      51,    -1,     4,    -1,     0,    -1,    -1,    17,    -1,     0,
      -1,    90,    -1,    89,    -1,    81,    -1,     5,    81,    72,
      79,     8,    -1,     5,    81,    50,    72,    79,     8,    -1,
       5,    81,    72,    79,     6,    72,     8,    -1,     5,    81,
      50,    72,    79,     6,    72,     8,    -1,     5,    90,    72,
      79,     8,    -1,     5,    90,    50,    72,    79,     8,    -1,
       5,    90,    72,    79,     6,    72,     8,    -1,     5,    90,
      50,    72,    79,     6,    72,     8,    -1,    13,    90,    80,
       8,    -1,    13,    90,    80,    15,    72,     8,    -1,     9,
      81,    72,     8,    -1,     9,    90,    72,     8,    -1,     9,
      81,    50,    72,     8,    -1,     9,    90,    50,    72,     8,
      -1,    10,    31,    34,    88,    72,     8,    -1,    10,    31,
      34,    88,    50,    72,     8,    -1,    18,    -1,    11,    -1,
      12,    -1,    16,    31,    52,    82,    53,    72,    76,    -1,
      16,    31,    34,    31,    52,    82,    53,    72,    76,    -1,
      16,    31,    54,    55,    34,    31,    52,    82,    53,    72,
      76,    -1,    16,    56,    86,    57,    34,    31,    52,    82,
      53,    72,    76,    -1,    -1,    79,     7,    81,    72,    -1,
      -1,     4,    -1,    80,    14,    90,     4,    72,    -1,    80,
      14,    54,    84,    55,    72,    -1,    90,    35,    90,    -1,
      87,    35,    90,    -1,    90,    35,    87,    -1,    90,    36,
      90,    -1,    87,    36,    90,    -1,    90,    36,    87,    -1,
      90,    23,    90,    -1,    87,    23,    90,    -1,    90,    23,
      87,    -1,    90,    24,    90,    -1,    87,    24,    90,    -1,
      90,    24,    87,    -1,    90,    26,    90,    -1,    87,    26,
      90,    -1,    90,    26,    87,    -1,    90,    25,    90,    -1,
      87,    25,    90,    -1,    90,    25,    87,    -1,    52,    81,
      53,    -1,    58,    81,    -1,    58,    90,    -1,    81,    27,
      81,    -1,    90,    27,    90,    -1,    81,    28,    81,    -1,
      90,    28,    90,    -1,    -1,    31,    -1,    31,    54,    55,
      -1,    82,    50,    31,    -1,    82,    50,    31,    54,    55,
      -1,    88,    -1,    91,    -1,    83,    -1,    84,    50,    83,
      -1,    -1,    86,    -1,    85,    51,    86,    -1,    88,    -1,
      86,    88,    -1,    86,    50,    88,    -1,    90,    37,    90,
      -1,    90,    37,    90,    37,    90,    -1,    90,    -1,    87,
      -1,    31,    34,    88,    -1,    31,    34,    81,    -1,    31,
      59,    88,    -1,    31,    60,    88,    -1,    31,    61,    88,
      -1,    31,    62,    88,    -1,    31,    63,    88,    -1,    31,
      64,    88,    -1,    31,    65,    88,    -1,    31,    54,    90,
      55,    34,    88,    -1,    31,    52,    90,    66,    90,    53,
      59,    88,    -1,    31,    52,    90,    66,    90,    53,    60,
      88,    -1,    31,    52,    90,    66,    90,    53,    61,    88,
      -1,    31,    52,    90,    66,    90,    53,    62,    88,    -1,
      31,    52,    90,    66,    90,    53,    64,    88,    -1,    31,
      52,    90,    66,    90,    53,    65,    88,    -1,    31,    52,
      84,    53,    34,    88,    -1,    31,    52,    81,    53,    34,
      88,    -1,    31,    52,    90,    66,    90,    53,    34,    90,
      -1,    31,    54,    90,    55,    52,    90,    66,    90,    53,
      34,    90,    -1,    31,    54,    90,    55,    52,    90,    53,
      34,    88,    -1,    31,    54,    90,    55,    52,    88,    53,
      34,    88,    -1,    31,    34,    89,    -1,    31,    54,    90,
      55,    34,    89,    -1,    31,    52,    84,    53,    34,    89,
      -1,    31,    54,    90,    55,    52,    90,    53,    34,    89,
      -1,    31,    34,    91,    -1,    31,    54,    55,    34,    31,
      52,    84,    53,    -1,    56,    86,    57,    34,    31,    52,
      84,    53,    -1,    29,    -1,    30,    -1,    32,    -1,    33,
      -1,    31,    -1,    31,    54,    90,    55,    -1,    31,    54,
      90,    55,    52,    90,    53,    -1,    31,    54,    90,    55,
      52,    88,    53,    -1,    31,    54,    55,    -1,    31,    52,
      53,    -1,    31,    52,    84,    53,    -1,    31,    52,    81,
      53,    -1,    67,    31,    52,    53,    -1,    67,    31,    52,
      84,    53,    -1,    31,    52,    90,    66,    90,    53,    -1,
      38,    90,    -1,    39,    90,    -1,    52,    88,    53,    -1,
      19,    52,    31,    34,    88,    50,    90,    53,    -1,    90,
      39,    90,    -1,    90,    38,    90,    -1,    90,    43,    90,
      -1,    90,    44,    90,    -1,    90,    45,    90,    -1,    90,
      41,    90,    -1,    90,    40,    90,    -1,    90,    42,    90,
      -1,    90,    42,    90,    68,    90,    -1,    90,    20,    90,
      -1,    90,    21,    90,    -1,    90,    22,    90,    -1,    56,
      85,    57,    -1,    56,    86,    57,    -1,    49,    -1,    54,
      84,    55,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   115,   115,   116,   120,   122,   140,   147,   168,   170,
     175,   179,   181,   185,   185,   185,   185,   188,   188,   188,
     191,   193,   195,   197,   206,   215,   228,   241,   250,   259,
     272,   285,   293,   302,   308,   314,   320,   326,   334,   342,
     346,   348,   352,   359,   368,   377,   388,   389,   402,   403,
     405,   415,   427,   429,   431,   433,   435,   437,   439,   441,
     443,   445,   447,   449,   451,   453,   455,   457,   459,   461,
     463,   469,   474,   479,   481,   483,   485,   490,   493,   499,
     505,   511,   519,   521,   525,   530,   538,   541,   546,   553,
     558,   563,   570,   574,   581,   583,   587,   593,   599,   605,
     611,   617,   623,   629,   635,   642,   649,   653,   657,   661,
     665,   669,   673,   680,   687,   696,   707,   715,   723,   729,
     736,   743,   751,   758,   766,   775,   780,   785,   790,   795,
     800,   806,   813,   821,   826,   831,   839,   848,   856,   867,
     875,   880,   886,   892,   900,   902,   904,   906,   908,   910,
     912,   914,   916,   924,   926,   928,   930,   936,   942,   949
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
  "\"string\"", "\"identifier\"", "\"fT\"", "\"fP\"", "'='", "'<'", "'>'",
  "':'", "'-'", "'+'", "'$'", "'%'", "'@'", "'*'", "'/'", "'^'",
  "T_NEGATIVE", "T_POSITIVE", "T_LOGIC_NOT", "\"..\"", "','", "';'", "'('",
  "')'", "'{'", "'}'", "'['", "']'", "'!'", "\"+=\"", "\"-=\"", "\"*=\"",
  "\"/=\"", "\"^=\"", "\"@=\"", "\"@@=\"", "'~'", "'#'", "'|'", "$accept",
  "input", "block_func", "block", "line", "line_func", "eol", "func_end",
  "stmt", "funcdef", "elseif_list", "case_list", "condition", "id_list",
  "arg", "arg_list", "matrix", "vector", "range", "exp_range", "assign",
  "exp", "initcell", 0
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
     285,   286,   287,   288,    61,    60,    62,    58,    45,    43,
      36,    37,    64,    42,    47,    94,   289,   290,   291,   292,
      44,    59,    40,    41,   123,   125,    91,    93,    33,   293,
     294,   295,   296,   297,   298,   299,   126,    35,   124
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      73,    74,    74,    75,    75,    75,    75,    76,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    78,    78,    78,    78,    79,    79,    80,    80,
      80,    80,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    82,    82,    82,
      82,    82,    83,    83,    84,    84,    85,    85,    85,    86,
      86,    86,    87,    87,    88,    88,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       1,     1,     1,     5,     6,     7,     8,     5,     6,     7,
       8,     4,     6,     4,     4,     5,     5,     6,     7,     1,
       1,     1,     7,     9,    11,    11,     0,     4,     0,     1,
       5,     6,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     3,     3,     0,     1,     3,
       3,     5,     1,     1,     1,     3,     0,     1,     3,     1,
       2,     3,     3,     5,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     6,     8,     8,     8,     8,
       8,     8,     6,     6,     8,    11,     9,     9,     3,     6,
       6,     9,     3,     8,     8,     1,     1,     1,     1,     1,
       4,     7,     7,     3,     3,     4,     4,     4,     5,     6,
       2,     2,     3,     8,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     3,     3,     3,     3,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     8,     0,     0,     0,    40,    41,     0,     0,
      39,     0,   125,   126,   129,   127,   128,     0,     0,   158,
       0,    86,     0,     0,     0,     0,    11,     4,     0,    12,
      22,     0,    21,    20,     9,   129,    86,     0,     0,     0,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,   141,     0,
      95,     0,    94,     0,    87,    95,    89,    94,    71,    72,
       0,     1,     5,    16,    15,    13,    14,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
       0,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,    77,     0,     0,     0,     0,    97,
      96,   118,   122,   134,     0,    84,     0,    82,    94,    83,
     133,     0,    98,    99,   100,   101,   102,   103,   104,    70,
     142,     0,   156,     0,   157,    90,     0,    73,     0,    75,
      59,    62,    68,    65,    53,    56,   153,   154,   155,    60,
      58,    63,    61,    69,    67,    66,    64,    74,    76,    54,
      52,    57,    55,    92,   145,   144,   150,   149,   151,   146,
     147,   148,     0,     0,    94,   133,     0,   157,     0,     7,
       0,   140,   141,     0,     0,     0,    33,     0,    34,     0,
      31,     0,     0,     0,    78,     0,     0,     0,     0,     0,
     136,     0,   135,     0,     0,   130,    88,    91,     0,   137,
       0,     0,     0,   136,   135,     0,   130,     0,     0,     0,
      23,     0,     0,    27,    35,    36,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,   159,     0,
      85,     0,     0,     0,     0,     0,     0,   138,    93,   152,
       0,     0,     0,    24,     0,     0,     0,    28,     0,     0,
      37,     0,     0,    32,     0,    79,    80,     0,     0,     0,
       0,   113,   112,   120,   139,     0,   105,   119,     0,     0,
       0,   139,     0,     0,     0,    25,     0,     0,    29,    38,
       0,     0,     0,     0,    19,    18,    42,    77,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,   131,
       0,     0,   132,   131,    26,    30,     0,     0,    81,     0,
       0,   143,   114,   106,   107,   108,   109,   110,   111,   123,
       0,     0,     0,   124,    43,     0,     0,   117,   116,   121,
       0,     0,     0,     0,    44,    45,   115
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,    25,   110,   111,    27,    77,   316,    28,    29,
     200,   122,    30,   215,   135,   136,    63,    64,    31,   137,
      32,    33,   139
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -327
static const yytype_int16 yypact[] =
{
     715,     9,  -327,  2181,  2181,   -11,  -327,  -327,  2368,   -14,
    -327,   -25,  -327,  -327,   192,  -327,  -327,  2368,  2368,  -327,
    2181,  2368,  2181,    16,    31,   765,  -327,  -327,    10,  -327,
      97,   245,  -327,  2515,  -327,    79,  2368,   915,   815,   965,
     865,    30,  2368,   448,    78,  2368,    35,   635,   107,  2212,
    2368,  2368,  2368,  2368,  2368,  2368,  2368,  -327,  -327,   -21,
     245,    25,  2515,    71,  2054,  -327,  -327,  1216,  -327,  2541,
     110,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  2181,  2181,
    2368,  2368,  2368,  2368,  2368,  2368,  2368,  2368,  2368,  2368,
    2368,  2368,  2368,  2368,  2368,  2368,  2368,  2368,  2368,  2368,
    2368,  2368,  2368,  2368,  2368,  2368,   107,  2243,  2086,  2023,
    1029,  -327,  2368,  2368,  2023,  1029,  2023,  1323,  2023,  1383,
    2368,  -327,   133,   118,   135,   109,  2118,   137,  2274,    97,
    -327,  -327,  -327,  -327,   -12,  -327,    24,  -327,  2436,  -327,
     142,   767,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,
    -327,  2368,  -327,  2368,   160,  -327,  2150,  -327,  2515,   168,
    1325,  1325,  1325,  1325,  1325,  1325,    99,    99,   440,  -327,
    1216,  -327,  1216,  -327,  1216,  -327,  1216,  1325,  1325,  -327,
    1216,  -327,  1216,  1266,   440,   440,    99,    99,    -5,   154,
     154,   154,     6,    70,  2468,  -327,   917,  -327,  1029,  -327,
     175,   362,   446,  1029,   222,  1443,  -327,  1503,  -327,  1553,
    -327,  2305,  2023,   162,   152,   105,   182,   183,  2368,   -26,
     186,  2274,   187,  2368,   194,    -8,  2336,  -327,   200,  -327,
     120,  2368,  2368,  -327,  -327,  2368,   171,   235,  2023,  2181,
    -327,   269,  2023,  -327,  -327,  -327,  2023,  1613,  2274,   718,
    1673,   135,   179,   204,  2023,   207,   208,   195,  -327,  2368,
    -327,  2399,   967,   196,  2399,  2368,   206,  -327,  1325,  1325,
    1031,  2368,  2023,  -327,  1733,  1263,  2023,  -327,  1793,  1853,
    -327,    12,  2023,  -327,   122,  -327,   205,   517,   209,   211,
    2368,  -327,  -327,  -327,    11,  2274,  -327,  -327,   214,   147,
    2274,  -327,   220,  2477,  1913,  -327,  1093,  1973,  -327,  -327,
    2023,  1153,  2023,   227,  -327,  -327,  -327,   135,   135,  1095,
    2368,  2368,  2368,  2368,  2368,  2368,  2368,   127,   230,   249,
    2368,   143,  -327,  -327,  -327,  -327,  1213,   517,  -327,   151,
     158,  -327,  1325,  -327,  -327,  -327,  -327,  -327,  -327,  -327,
    2368,  2399,  1155,  -327,  -327,  2023,  2023,  -327,  -327,  -327,
     250,   517,   517,  2368,  -327,  -327,  1325
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -327,  -327,  -327,   387,     0,   260,  -327,  -326,  -327,  -327,
     -87,  -327,   131,  -249,    65,   -98,  -327,   -33,   293,   386,
     -46,     1,   241
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -146
static const yytype_int16 yytable[] =
{
      26,   131,   284,   108,    38,    40,    78,    79,   193,    43,
      73,   354,   126,    34,    74,    78,    79,    44,    57,    58,
      41,    62,    67,    69,   221,    26,   264,    46,   204,   258,
     219,    71,   149,    78,    79,   364,   365,    67,   103,   104,
     105,   220,    45,    67,   265,   320,    67,    70,    62,   138,
     141,    67,    67,    67,    67,    67,    67,    67,   230,   233,
      75,    76,   221,   232,   120,    67,   127,   310,   339,   340,
     321,   322,   323,   324,   221,   325,   326,   222,   150,   158,
     158,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     170,   172,   174,   176,   177,   178,   180,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   194,   196,    67,
     199,   237,   123,   201,   202,   199,   241,   199,   226,   199,
     221,    67,   151,   234,    78,    79,    11,    67,   152,    67,
     124,   106,   125,   107,    37,    39,    12,    13,    35,    15,
      16,   210,   103,   104,   105,    17,    18,   211,   212,   213,
     281,    59,    67,    68,    67,   253,    19,    67,   254,    20,
     133,   128,   156,    36,   216,    22,   214,    86,    87,    88,
     221,   218,   253,   267,    23,   312,   224,   221,   129,   134,
     349,   238,   239,   240,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   221,   228,    78,   353,   327,   199,   105,
     329,   253,   331,   199,   355,   199,   252,   199,   253,   157,
     159,   356,   249,   330,   251,   293,   255,   256,   297,    67,
     259,   261,    67,   271,   262,   263,    47,    67,   242,   239,
     243,   266,   268,   269,   285,   286,   270,   192,   288,   289,
     158,   272,   239,   273,    48,   290,    49,   199,   295,    67,
     199,    50,    51,    52,    53,    54,    55,    56,   300,   313,
      67,   317,    67,   318,   350,    67,   299,   328,    80,    81,
      82,    83,   303,   332,   199,   276,   239,   277,   199,   199,
      84,    85,   338,   351,   363,    72,   260,   199,   132,     0,
       0,   319,     0,     0,     0,     0,    67,     0,     0,     0,
       0,    67,     0,     0,   199,   359,   199,   199,     0,     0,
       0,   199,     0,    60,    65,     0,     0,     0,     0,     0,
       0,   342,    67,    67,    67,    67,    67,    67,     0,    65,
       0,   352,     0,     0,     0,    65,   199,   199,    65,     0,
      60,    60,     0,    65,    65,    65,    65,    65,    65,    65,
       0,    67,    67,     0,     0,     0,     0,    65,     0,     0,
       0,   199,   199,  -145,   366,     0,     0,  -145,     0,     0,
     275,  -145,  -145,  -145,  -145,  -145,     0,     0,     0,     0,
    -145,  -145,   169,   171,   173,   175,     0,     0,   179,   181,
       0,  -145,  -145,  -145,  -145,  -145,     0,     0,     0,    60,
       0,    65,     0,     0,     0,     0,    61,    66,     0,     0,
       0,  -145,     0,    65,  -145,     0,     0,     0,  -145,    65,
    -145,    65,    66,     0,     0,   115,   117,   119,    61,  -145,
       0,    66,     0,   130,     0,     0,   142,   143,   144,   145,
     146,   147,   148,     0,    65,     0,    65,  -144,     0,    65,
     155,  -144,   121,     0,     0,  -144,  -144,  -144,  -144,  -144,
      86,    87,     0,     0,  -144,  -144,     0,     0,    86,    87,
      88,     0,     0,     0,     0,  -144,  -144,  -144,  -144,  -144,
     100,   101,   102,   103,   104,   105,    98,    99,   100,   101,
     102,   103,   104,   105,   155,  -144,   198,     0,  -144,     0,
       0,   203,  -144,   205,  -144,   207,   209,     0,     0,     0,
       0,    65,   155,  -144,    65,     0,     0,   314,     1,    65,
       0,     2,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     0,     0,   -17,   315,    10,    11,    66,     0,   227,
       0,    65,     0,     0,     0,     0,    12,    13,    14,    15,
      16,     0,    65,     0,    65,    17,    18,    65,    65,     0,
       0,     0,     0,     0,    65,     0,    19,     0,     0,    20,
       0,     0,     0,    21,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,    23,     0,     0,     0,    65,     0,
       0,     0,     0,    65,     0,     0,   247,     0,     0,   250,
       0,     0,     0,     0,   257,     0,     0,     0,     0,     0,
       0,     0,   155,     0,    65,    65,    65,    65,    65,    65,
       0,     0,     0,     0,     0,   274,     0,     0,     0,   278,
       0,     0,     0,   279,     0,     0,     0,     0,     0,     0,
       0,   287,     0,    65,    65,   291,     0,   292,     0,     0,
     296,   298,     0,     0,    11,     0,     0,   302,     0,   304,
       0,     0,   306,   307,    12,    13,    14,    15,    16,   311,
       0,     0,     0,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,    20,     0,   128,
       0,    21,     0,    22,     0,     0,     0,   336,     0,   337,
       0,     0,    23,     0,     0,     0,     0,   343,   344,   345,
     346,   347,   348,     0,     0,    -2,     1,     0,     0,     2,
       3,     0,   282,     0,     4,     5,     6,     7,     8,     0,
       0,     9,     0,    10,    11,     0,   357,   358,    86,    87,
      88,     0,   361,   362,    12,    13,    14,    15,    16,     0,
       0,     0,     0,    17,    18,     0,    98,    99,   100,   101,
     102,   103,   104,   105,    19,    -3,     1,    20,     0,     2,
       3,    21,     0,    22,     4,     5,     6,     7,     8,     0,
       0,     9,    23,    10,    11,     0,     0,    86,    87,    88,
       0,     0,     0,     0,    12,    13,    14,    15,    16,     0,
       0,     0,     0,    17,    18,    98,    99,   100,   101,   102,
     103,   104,   105,     0,    19,     0,     1,    20,     0,     2,
       3,    21,   225,    22,     4,     5,     6,     7,     8,     0,
       0,     0,    23,    10,    11,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    12,    13,    14,    15,    16,     0,
      95,    96,    97,   112,   113,   100,   101,   102,   103,   104,
     105,     0,     0,     0,    19,   114,     1,    20,     0,     2,
       3,    21,     0,    22,     4,     5,     6,     7,     8,     0,
       0,     0,    23,    10,    11,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    12,    13,    14,    15,    16,     0,
      95,    96,    97,   112,   113,   100,   101,   102,   103,   104,
     105,     0,     0,     0,    19,   118,     1,    20,     0,     2,
       3,    21,     0,    22,     4,     5,     6,     7,     8,     0,
       0,     0,    23,    10,    11,     0,     0,    86,    87,    88,
       0,     0,    78,    79,    12,    13,    14,    15,    16,     0,
       0,     0,     0,    17,    18,    98,    99,   100,   101,   102,
     103,   104,   105,     0,    19,   109,     1,    20,     0,     2,
       3,    21,   236,    22,     4,     5,     6,     7,     8,     0,
       0,     0,    23,    10,    11,     0,     0,    86,    87,    88,
       0,     0,    78,    79,    12,    13,    14,    15,    16,     0,
       0,     0,     0,    17,    18,    98,    99,   100,   101,   102,
     103,   104,   105,     0,    19,   116,     0,    20,     0,     0,
     294,    21,     0,    22,     0,     0,     0,     0,     0,     0,
       1,     0,    23,     2,     3,   -46,   -46,   -46,     4,     5,
       6,     7,     8,     0,     0,     0,     0,    10,    11,     0,
       0,    86,    87,    88,     0,     0,     0,     0,    12,    13,
      14,    15,    16,     0,     0,     0,     0,    17,    18,    98,
      99,   100,   101,   102,   103,   104,   105,     0,    19,     0,
       0,    20,     0,     0,   301,    21,     0,    22,     0,     0,
       0,     0,     0,     0,     1,     0,    23,     2,     3,   -47,
     -47,   -47,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,    86,    87,    88,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,    98,    99,   100,   101,   102,   103,   104,
     105,     0,    19,     0,     0,    20,     0,     0,   341,    21,
       0,    22,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   -50,     4,     5,     6,     7,     8,   -50,   -50,     0,
       0,    10,    11,     0,     0,    86,    87,    88,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,    98,    99,   100,   101,   102,   103,   104,
     105,     0,    19,     0,     0,    20,     0,     0,   360,    21,
       0,    22,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   -51,     4,     5,     6,     7,     8,   -51,   -51,     0,
       0,    10,    11,     0,     0,     0,    86,    87,    88,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    19,     0,     1,    20,     0,     2,     3,    21,
       0,    22,     4,     5,     6,     7,     8,     0,     0,     0,
      23,    10,    11,     0,     0,     0,    86,    87,    88,     0,
      78,    79,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,   231,    98,    99,   100,   101,   102,   103,
     104,   105,    19,     0,     0,    20,     0,     0,     0,    21,
       0,    22,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   206,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,    86,    87,    88,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,    98,    99,   100,   101,   102,   103,   104,
     105,     0,    19,     0,     0,    20,     0,     0,     0,    21,
       0,    22,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   208,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,    20,     0,     0,     0,    21,
       0,    22,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   244,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,    20,     0,     0,     0,    21,
       0,    22,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   245,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     1,    20,     0,     2,     3,    21,
       0,    22,     4,     5,     6,     7,     8,     0,     0,     0,
      23,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,   246,     0,    20,     0,     0,     0,    21,
       0,    22,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   280,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,    20,     0,     0,     0,    21,
       0,    22,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   283,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,    20,     0,     0,     0,    21,
       0,    22,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   305,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,    20,     0,     0,     0,    21,
       0,    22,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   308,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,    20,     0,     0,     0,    21,
       0,    22,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   309,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,    20,     0,     0,     0,    21,
       0,    22,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   334,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,    20,     0,     0,     0,    21,
       0,    22,     0,     0,     1,     0,     0,     2,     3,     0,
      23,   335,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     1,    20,     0,     2,     3,    21,
       0,    22,     4,     5,     6,     7,     8,     0,     0,     0,
      23,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    11,     0,    20,     0,     0,     0,    21,
       0,    22,     0,    12,    13,    35,    15,    16,     0,     0,
      23,     0,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,   153,    11,    42,     0,     0,     0,
      36,   154,     0,     0,     0,    12,    13,    35,    15,    16,
       0,    23,     0,     0,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,   153,    11,    42,     0,
       0,     0,    36,   197,     0,     0,     0,    12,    13,    35,
      15,    16,     0,    23,     0,     0,    17,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,   153,    11,
      42,     0,     0,     0,    36,   217,     0,     0,     0,    12,
      13,    35,    15,    16,     0,    23,     0,     0,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      11,     0,    42,   229,   128,     0,    36,     0,     0,     0,
      12,    13,    35,    15,    16,     0,     0,    23,     0,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    11,     0,    20,     0,     0,     0,    36,     0,    22,
       0,    12,    13,    35,    15,    16,     0,     0,    23,     0,
      17,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    11,     0,    42,     0,     0,   140,    36,     0,
       0,     0,    12,    13,    35,    15,    16,     0,     0,    23,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    11,     0,    42,     0,     0,   195,    36,
       0,     0,     0,    12,    13,    35,    15,    16,     0,     0,
      23,     0,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    11,     0,    42,     0,   128,     0,
      36,     0,     0,     0,    12,    13,    35,    15,    16,     0,
       0,    23,     0,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    11,     0,    42,     0,   248,
       0,    36,     0,     0,     0,    12,    13,    35,    15,    16,
       0,     0,    23,     0,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,   153,    11,    42,     0,
       0,     0,    36,     0,     0,     0,     0,    12,    13,    35,
      15,    16,     0,    23,     0,     0,    17,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    11,     0,
      42,     0,     0,     0,    36,     0,     0,     0,    12,    13,
      14,    15,    16,     0,     0,    23,     0,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
       0,    42,     0,     0,     0,    21,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    23,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    86,    87,    88,
       0,     0,   223,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,     0,     0,     0,     0,
     333,     0,     0,     0,   235,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     0,     0,     0,     0,     0,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,     0,
       0,   100,   101,   102,   103,   104,   105
};

static const yytype_int16 yycheck[] =
{
       0,    47,   251,    36,     3,     4,    27,    28,   106,     8,
       0,   337,    45,     4,     4,    27,    28,    31,    17,    18,
      31,    20,    21,    22,    50,    25,    34,    52,   115,    55,
     128,     0,    53,    27,    28,   361,   362,    36,    43,    44,
      45,    53,    56,    42,    52,    34,    45,    31,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,   156,    53,
      50,    51,    50,    68,    34,    64,    31,    55,   317,   318,
      59,    60,    61,    62,    50,    64,    65,    53,    53,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     110,   198,    34,   112,   113,   115,   203,   117,   151,   119,
      50,   120,    51,    53,    27,    28,    19,   126,    57,   128,
      52,    52,    54,    54,     3,     4,    29,    30,    31,    32,
      33,     8,    43,    44,    45,    38,    39,    14,    15,    31,
     248,    20,   151,    22,   153,    50,    49,   156,    53,    52,
      53,    54,    52,    56,    55,    58,    31,    20,    21,    22,
      50,    34,    50,    53,    67,    53,    34,    50,    47,    48,
      53,     6,     7,     8,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    50,    34,    27,    53,   295,   198,    45,
      53,    50,   300,   203,    53,   205,    54,   207,    50,    78,
      79,    53,   211,    66,    52,   261,    34,    34,   264,   218,
      34,    34,   221,    52,   223,    31,    34,   226,     6,     7,
       8,    31,   231,   232,    55,    31,   235,   106,    31,    31,
     239,     6,     7,     8,    52,    50,    54,   247,    52,   248,
     250,    59,    60,    61,    62,    63,    64,    65,    52,    54,
     259,    52,   261,    52,    34,   264,   265,    53,    23,    24,
      25,    26,   271,    53,   274,     6,     7,     8,   278,   279,
      35,    36,    55,    34,    34,    25,   221,   287,    47,    -1,
      -1,   290,    -1,    -1,    -1,    -1,   295,    -1,    -1,    -1,
      -1,   300,    -1,    -1,   304,   351,   306,   307,    -1,    -1,
      -1,   311,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,   320,   321,   322,   323,   324,   325,   326,    -1,    36,
      -1,   330,    -1,    -1,    -1,    42,   336,   337,    45,    -1,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      -1,   350,   351,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,   361,   362,     1,   363,    -1,    -1,     5,    -1,    -1,
     239,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      18,    19,    89,    90,    91,    92,    -1,    -1,    95,    96,
      -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,   106,
      -1,   108,    -1,    -1,    -1,    -1,    20,    21,    -1,    -1,
      -1,    49,    -1,   120,    52,    -1,    -1,    -1,    56,   126,
      58,   128,    36,    -1,    -1,    38,    39,    40,    42,    67,
      -1,    45,    -1,    47,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    -1,   151,    -1,   153,     1,    -1,   156,
      64,     5,     4,    -1,    -1,     9,    10,    11,    12,    13,
      20,    21,    -1,    -1,    18,    19,    -1,    -1,    20,    21,
      22,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      40,    41,    42,    43,    44,    45,    38,    39,    40,    41,
      42,    43,    44,    45,   108,    49,   109,    -1,    52,    -1,
      -1,   114,    56,   116,    58,   118,   120,    -1,    -1,    -1,
      -1,   218,   126,    67,   221,    -1,    -1,     0,     1,   226,
      -1,     4,     5,    -1,    -1,    -1,     9,    10,    11,    12,
      13,    -1,    -1,    16,    17,    18,    19,   151,    -1,   153,
      -1,   248,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    -1,   259,    -1,   261,    38,    39,   264,   265,    -1,
      -1,    -1,    -1,    -1,   271,    -1,    49,    -1,    -1,    52,
      -1,    -1,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,   295,    -1,
      -1,    -1,    -1,   300,    -1,    -1,   209,    -1,    -1,   212,
      -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   226,    -1,   321,   322,   323,   324,   325,   326,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,   242,
      -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,    -1,   350,   351,   259,    -1,   261,    -1,    -1,
     264,   265,    -1,    -1,    19,    -1,    -1,   271,    -1,   272,
      -1,    -1,   275,   276,    29,    30,    31,    32,    33,   282,
      -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    -1,    54,
      -1,    56,    -1,    58,    -1,    -1,    -1,   310,    -1,   312,
      -1,    -1,    67,    -1,    -1,    -1,    -1,   321,   322,   323,
     324,   325,   326,    -1,    -1,     0,     1,    -1,    -1,     4,
       5,    -1,     4,    -1,     9,    10,    11,    12,    13,    -1,
      -1,    16,    -1,    18,    19,    -1,   350,   351,    20,    21,
      22,    -1,   355,   356,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    39,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    49,     0,     1,    52,    -1,     4,
       5,    56,    -1,    58,     9,    10,    11,    12,    13,    -1,
      -1,    16,    67,    18,    19,    -1,    -1,    20,    21,    22,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    39,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    49,    -1,     1,    52,    -1,     4,
       5,    56,    55,    58,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    67,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    49,    50,     1,    52,    -1,     4,
       5,    56,    -1,    58,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    67,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    49,    50,     1,    52,    -1,     4,
       5,    56,    -1,    58,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    67,    18,    19,    -1,    -1,    20,    21,    22,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    39,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    49,    50,     1,    52,    -1,     4,
       5,    56,    55,    58,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    67,    18,    19,    -1,    -1,    20,    21,    22,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    39,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    49,    50,    -1,    52,    -1,    -1,
      53,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    67,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    18,    19,    -1,
      -1,    20,    21,    22,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    49,    -1,
      -1,    52,    -1,    -1,    53,    56,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    67,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    20,    21,    22,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    49,    -1,    -1,    52,    -1,    -1,    53,    56,
      -1,    58,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    18,    19,    -1,    -1,    20,    21,    22,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    49,    -1,    -1,    52,    -1,    -1,    53,    56,
      -1,    58,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    18,    19,    -1,    -1,    -1,    20,    21,    22,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    49,    -1,     1,    52,    -1,     4,     5,    56,
      -1,    58,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      67,    18,    19,    -1,    -1,    -1,    20,    21,    22,    -1,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    49,    -1,    -1,    52,    -1,    -1,    -1,    56,
      -1,    58,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    20,    21,    22,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    56,
      -1,    58,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    56,
      -1,    58,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    56,
      -1,    58,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,     1,    52,    -1,     4,     5,    56,
      -1,    58,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      67,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    52,    -1,    -1,    -1,    56,
      -1,    58,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    56,
      -1,    58,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    56,
      -1,    58,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    56,
      -1,    58,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    56,
      -1,    58,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    56,
      -1,    58,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    56,
      -1,    58,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      67,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,     1,    52,    -1,     4,     5,    56,
      -1,    58,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      67,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    19,    -1,    52,    -1,    -1,    -1,    56,
      -1,    58,    -1,    29,    30,    31,    32,    33,    -1,    -1,
      67,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    19,    52,    -1,    -1,    -1,
      56,    57,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      -1,    67,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    19,    52,    -1,
      -1,    -1,    56,    57,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    -1,    67,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    19,
      52,    -1,    -1,    -1,    56,    57,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    -1,    67,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      19,    -1,    52,    53,    54,    -1,    56,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    -1,    -1,    67,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    19,    -1,    52,    -1,    -1,    -1,    56,    -1,    58,
      -1,    29,    30,    31,    32,    33,    -1,    -1,    67,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    19,    -1,    52,    -1,    -1,    55,    56,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    67,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    19,    -1,    52,    -1,    -1,    55,    56,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,
      67,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    19,    -1,    52,    -1,    54,    -1,
      56,    -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,
      -1,    67,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    19,    -1,    52,    -1,    54,
      -1,    56,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      -1,    -1,    67,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    19,    52,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    -1,    67,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    19,    -1,
      52,    -1,    -1,    -1,    56,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    -1,    -1,    67,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    52,    -1,    -1,    -1,    56,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    67,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    20,    21,    22,
      -1,    -1,    66,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    66,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,
      -1,    40,    41,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     9,    10,    11,    12,    13,    16,
      18,    19,    29,    30,    31,    32,    33,    38,    39,    49,
      52,    56,    58,    67,    70,    71,    73,    74,    77,    78,
      81,    87,    89,    90,     4,    31,    56,    81,    90,    81,
      90,    31,    52,    90,    31,    56,    52,    34,    52,    54,
      59,    60,    61,    62,    63,    64,    65,    90,    90,    81,
      87,    88,    90,    85,    86,    87,    88,    90,    81,    90,
      31,     0,    74,     0,     4,    50,    51,    75,    27,    28,
      23,    24,    25,    26,    35,    36,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    52,    54,    86,    50,
      72,    73,    38,    39,    50,    72,    50,    72,    50,    72,
      34,     4,    80,    34,    52,    54,    86,    31,    54,    81,
      88,    89,    91,    53,    81,    83,    84,    88,    90,    91,
      55,    90,    88,    88,    88,    88,    88,    88,    88,    53,
      53,    51,    57,    50,    57,    88,    52,    81,    90,    81,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    87,
      90,    87,    90,    87,    90,    87,    90,    90,    90,    87,
      90,    87,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    81,    84,    90,    55,    90,    57,    72,    73,
      79,    90,    90,    72,    79,    72,     8,    72,     8,    88,
       8,    14,    15,    31,    31,    82,    55,    57,    34,    84,
      53,    50,    53,    66,    34,    55,    86,    88,    34,    53,
      84,    37,    68,    53,    53,    66,    55,    79,     6,     7,
       8,    79,     6,     8,     8,     8,    50,    72,    54,    90,
      72,    52,    54,    50,    53,    34,    34,    88,    55,    34,
      83,    34,    90,    31,    34,    52,    31,    53,    90,    90,
      90,    52,     6,     8,    72,    81,     6,     8,    72,    72,
       8,    84,     4,     8,    82,    55,    31,    72,    31,    31,
      50,    88,    88,    89,    53,    52,    88,    89,    88,    90,
      52,    53,    88,    90,    72,     8,    72,    72,     8,     8,
      55,    72,    53,    54,     0,    17,    76,    52,    52,    90,
      34,    59,    60,    61,    62,    64,    65,    84,    53,    53,
      66,    84,    53,    53,     8,     8,    72,    72,    55,    82,
      82,    53,    90,    88,    88,    88,    88,    88,    88,    53,
      34,    34,    90,    53,    76,    53,    53,    88,    88,    89,
      53,    72,    72,    34,    76,    76,    90
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
#line 95 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", (yyvaluep->str));
#endif
  free((yyvaluep->str));
};

/* Line 1000 of yacc.c  */
#line 1899 "psycon.tab.c"
	break;
      case 31: /* "\"identifier\"" */

/* Line 1000 of yacc.c  */
#line 95 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", (yyvaluep->str));
#endif
  free((yyvaluep->str));
};

/* Line 1000 of yacc.c  */
#line 1913 "psycon.tab.c"
	break;
      case 71: /* "block_func" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1927 "psycon.tab.c"
	break;
      case 72: /* "block" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1941 "psycon.tab.c"
	break;
      case 73: /* "line" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1955 "psycon.tab.c"
	break;
      case 74: /* "line_func" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1969 "psycon.tab.c"
	break;
      case 77: /* "stmt" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1983 "psycon.tab.c"
	break;
      case 78: /* "funcdef" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1997 "psycon.tab.c"
	break;
      case 79: /* "elseif_list" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2011 "psycon.tab.c"
	break;
      case 80: /* "case_list" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2025 "psycon.tab.c"
	break;
      case 81: /* "condition" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2039 "psycon.tab.c"
	break;
      case 82: /* "id_list" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2053 "psycon.tab.c"
	break;
      case 83: /* "arg" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2067 "psycon.tab.c"
	break;
      case 84: /* "arg_list" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2081 "psycon.tab.c"
	break;
      case 85: /* "matrix" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2095 "psycon.tab.c"
	break;
      case 86: /* "vector" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2109 "psycon.tab.c"
	break;
      case 87: /* "range" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2123 "psycon.tab.c"
	break;
      case 88: /* "exp_range" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2137 "psycon.tab.c"
	break;
      case 89: /* "assign" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2151 "psycon.tab.c"
	break;
      case 90: /* "exp" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2165 "psycon.tab.c"
	break;
      case 91: /* "initcell" */

/* Line 1000 of yacc.c  */
#line 88 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2179 "psycon.tab.c"
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
#line 79 "psycon.y"
{
  if (ErrorMsg) {
	free(ErrorMsg);
	ErrorMsg = NULL;
  }
  *errmsg = NULL;
}

/* Line 1242 of yacc.c  */
#line 2340 "psycon.tab.c"

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
#line 115 "psycon.y"
    { *pproot = NULL;;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 117 "psycon.y"
    { *pproot = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 121 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 123 "psycon.y"
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
#line 141 "psycon.y"
    {
		if ((yyvsp[(1) - (1)].pnode))
			(yyval.pnode) = (yyvsp[(1) - (1)].pnode);
		else
			(yyval.pnode) = newAstNode(NODE_BLOCK, (yyloc));
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 148 "psycon.y"
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
#line 169 "psycon.y"
    { (yyval.pnode) = NULL;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 171 "psycon.y"
    {
		(yyval.pnode) = NULL;
		yyerrok;
	;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 176 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (2)].pnode);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 180 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 182 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 192 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 194 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 196 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 198 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(4) - (5)].pnode);
		(yyvsp[(2) - (5)].pnode)->next = (yyvsp[(3) - (5)].pnode);
		(yyvsp[(3) - (5)].pnode)->next = (yyvsp[(4) - (5)].pnode)->child;
		(yyval.pnode)->child = (yyvsp[(2) - (5)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 207 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(5) - (6)].pnode);
		(yyvsp[(2) - (6)].pnode)->next = (yyvsp[(4) - (6)].pnode);
		(yyvsp[(4) - (6)].pnode)->next = (yyvsp[(5) - (6)].pnode)->child;
		(yyval.pnode)->child = (yyvsp[(2) - (6)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 216 "psycon.y"
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

  case 26:

/* Line 1455 of yacc.c  */
#line 229 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(5) - (8)].pnode);
		(yyvsp[(2) - (8)].pnode)->next = (yyvsp[(4) - (8)].pnode);
		if ((yyvsp[(5) - (8)].pnode)->LastChild) {
			(yyvsp[(4) - (8)].pnode)->next = (yyvsp[(5) - (8)].pnode)->child;
			(yyvsp[(5) - (8)].pnode)->LastChild->next = (yyvsp[(7) - (8)].pnode);
		} else
			(yyvsp[(4) - (8)].pnode)->next = (yyvsp[(7) - (8)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (8)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 242 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(4) - (5)].pnode);
		(yyvsp[(2) - (5)].pnode)->next = (yyvsp[(3) - (5)].pnode);
		(yyvsp[(3) - (5)].pnode)->next = (yyvsp[(4) - (5)].pnode)->child;
		(yyval.pnode)->child = (yyvsp[(2) - (5)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 251 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(5) - (6)].pnode);
		(yyvsp[(2) - (6)].pnode)->next = (yyvsp[(4) - (6)].pnode);
		(yyvsp[(4) - (6)].pnode)->next = (yyvsp[(5) - (6)].pnode)->child;
		(yyval.pnode)->child = (yyvsp[(2) - (6)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 260 "psycon.y"
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

  case 30:

/* Line 1455 of yacc.c  */
#line 273 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(5) - (8)].pnode);
		(yyvsp[(2) - (8)].pnode)->next = (yyvsp[(4) - (8)].pnode);
		if ((yyvsp[(5) - (8)].pnode)->LastChild) {
			(yyvsp[(4) - (8)].pnode)->next = (yyvsp[(5) - (8)].pnode)->child;
			(yyvsp[(5) - (8)].pnode)->LastChild->next = (yyvsp[(7) - (8)].pnode);
		} else
			(yyvsp[(4) - (8)].pnode)->next = (yyvsp[(7) - (8)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (8)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 286 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (4)].pnode);
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode)->child;
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 294 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (6)].pnode);
		(yyvsp[(2) - (6)].pnode)->next = (yyvsp[(3) - (6)].pnode)->child;
		(yyvsp[(3) - (6)].pnode)->LastChild->next = (yyvsp[(5) - (6)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (6)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 303 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_WHILE, (yyloc));
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
	;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 309 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_WHILE, (yyloc));
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
	;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 315 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_WHILE, (yyloc));
		(yyvsp[(2) - (5)].pnode)->next = (yyvsp[(4) - (5)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (5)].pnode);
	;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 321 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_WHILE, (yyloc));
		(yyvsp[(2) - (5)].pnode)->next = (yyvsp[(4) - (5)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (5)].pnode);
	;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 327 "psycon.y"
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
#line 335 "psycon.y"
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
#line 343 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_RETURN, (yyloc));
	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 347 "psycon.y"
    { (yyval.pnode) = newAstNode(T_BREAK, (yyloc));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 349 "psycon.y"
    { (yyval.pnode) = newAstNode(T_CONTINUE, (yyloc));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 353 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(2) - (7)].str);
		(yyval.pnode)->child = (yyvsp[(4) - (7)].pnode);
		(yyvsp[(4) - (7)].pnode)->next = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 360 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(4) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (9)].pnode);
		(yyvsp[(6) - (9)].pnode)->next = (yyvsp[(8) - (9)].pnode);
		(yyvsp[(8) - (9)].pnode)->next = newAstNode(T_ID, (yylsp[(2) - (9)]));
		(yyvsp[(8) - (9)].pnode)->next->str = (yyvsp[(2) - (9)].str);
	;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 369 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(6) - (11)].str);
		(yyval.pnode)->child = (yyvsp[(8) - (11)].pnode);
		(yyvsp[(8) - (11)].pnode)->next = (yyvsp[(10) - (11)].pnode);
		(yyvsp[(10) - (11)].pnode)->next = newAstNode(NODE_INITCELL, (yylsp[(2) - (11)]));
		(yyvsp[(10) - (11)].pnode)->next->str = (yyvsp[(2) - (11)].str);
	;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 378 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(6) - (11)].str);
		(yyval.pnode)->child = (yyvsp[(8) - (11)].pnode);
		(yyvsp[(8) - (11)].pnode)->next = (yyvsp[(10) - (11)].pnode);
		(yyvsp[(10) - (11)].pnode)->next = (yyvsp[(3) - (11)].pnode);
	;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 388 "psycon.y"
    { (yyval.pnode) = newAstNode(T_IF, (yyloc));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 390 "psycon.y"
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

  case 48:

/* Line 1455 of yacc.c  */
#line 402 "psycon.y"
    { (yyval.pnode) = newAstNode(T_SWITCH, (yyloc));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 404 "psycon.y"
    { (yyval.pnode) = newAstNode(T_SWITCH, (yyloc));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 406 "psycon.y"
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

  case 51:

/* Line 1455 of yacc.c  */
#line 416 "psycon.y"
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

  case 52:

/* Line 1455 of yacc.c  */
#line 428 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('<', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 430 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('<', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 432 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('<', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 434 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('>', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 436 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('>', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 438 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('>', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 440 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_EQ, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 442 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_EQ, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 444 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_EQ, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 446 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_NE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 448 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_NE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 450 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_NE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 452 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_GE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 454 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_GE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 456 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_GE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 458 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_LE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 460 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_LE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 462 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_LE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 464 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 470 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_LOGIC_NOT, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (2)].pnode);
	;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 475 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_LOGIC_NOT, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (2)].pnode);
	;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 480 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 482 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 484 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 486 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 490 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
	;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 494 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->LastChild = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->LastChild->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 500 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->LastChild = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->LastChild->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 506 "psycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->LastChild = (yyvsp[(1) - (3)].pnode)->LastChild->next = newAstNode(T_ID, (yylsp[(3) - (3)]));
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
		(yyval.pnode)->LastChild->str = (yyvsp[(3) - (3)].str);
	;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 512 "psycon.y"
    {
		(yyvsp[(1) - (5)].pnode)->LastChild = (yyvsp[(1) - (5)].pnode)->LastChild->next = newAstNode(NODE_INITCELL, (yylsp[(3) - (5)]));
		(yyval.pnode) = (yyvsp[(1) - (5)].pnode);
		(yyval.pnode)->LastChild->str = (yyvsp[(3) - (5)].str);
	;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 520 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 522 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 526 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_ARGS, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->LastChild = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 531 "psycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->LastChild = (yyvsp[(1) - (3)].pnode)->LastChild->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 538 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_MATRIX, (yyloc));
	;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 542 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_MATRIX, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->LastChild = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 547 "psycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->LastChild = (yyvsp[(1) - (3)].pnode)->LastChild->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 554 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_VECTOR, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->LastChild = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 559 "psycon.y"
    {
		(yyvsp[(1) - (2)].pnode)->LastChild = (yyvsp[(1) - (2)].pnode)->LastChild->next = (yyvsp[(2) - (2)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (2)].pnode);
	;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 564 "psycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->LastChild = (yyvsp[(1) - (3)].pnode)->LastChild->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 571 "psycon.y"
    {
		(yyval.pnode) = makeFunctionCall(":", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));
	;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 575 "psycon.y"
    {
		(yyval.pnode) = makeFunctionCall(":", (yyvsp[(1) - (5)].pnode), (yyvsp[(5) - (5)].pnode), (yyloc));
		(yyval.pnode)->LastChild = (yyvsp[(5) - (5)].pnode)->next = (yyvsp[(3) - (5)].pnode);
	;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 582 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 584 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 588 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 594 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 600 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('+', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 606 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('-', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 612 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('*', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 618 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('/', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 624 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNodeFunctionCall('^', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 630 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('@', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 636 "psycon.y"
    { /* Reverse engineered from the tree generated in x = x @ x @ (value) */
	  /* Should be decluttered up by someone else..... 7/20/2016 bjk*/
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str); 
		(yyval.pnode)->child = makeCompoundLevelOpNode((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(1) - (3)]), (yylsp[(3) - (3)]));
	;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 643 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyval.pnode)->childLHS = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 650 "psycon.y"
    {
		(yyval.pnode) = Restring("+=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 654 "psycon.y"
    {
		(yyval.pnode) = Restring("-=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 658 "psycon.y"
    {
		(yyval.pnode) = Restring("*=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 662 "psycon.y"
    {
		(yyval.pnode) = Restring("/=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 666 "psycon.y"
    {
		(yyval.pnode) = Restring("@=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 670 "psycon.y"
    {
		(yyval.pnode) = Restring("@@=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 674 "psycon.y"
    { /* x(45)=723 or x(id1:id2) = id1:id2  or x(array) = scalar */
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyval.pnode)->childLHS = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 681 "psycon.y"
    { /* x(x>0) = scalar */
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyval.pnode)->childLHS = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 688 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (8)].str);
		(yyval.pnode)->child = (yyvsp[(8) - (8)].pnode);
		(yyval.pnode)->childLHS = newAstNode(NODE_IDLIST, (yyloc));
		(yyval.pnode)->childLHS->child = (yyvsp[(5) - (8)].pnode);
		(yyval.pnode)->childLHS->LastChild = (yyvsp[(3) - (8)].pnode);
	;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 697 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (11)].str);
		(yyval.pnode)->child = (yyvsp[(11) - (11)].pnode);
		(yyval.pnode)->childLHS = (yyvsp[(3) - (11)].pnode);
		(yyvsp[(3) - (11)].pnode)->childLHS = newAstNode(NODE_IDLIST, (yyloc));
		(yyvsp[(3) - (11)].pnode)->childLHS->child = (yyvsp[(8) - (11)].pnode);
		(yyvsp[(3) - (11)].pnode)->childLHS->LastChild = (yyvsp[(6) - (11)].pnode);
	;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 708 "psycon.y"
    { // v{2}(4)=1 
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(9) - (9)].pnode);
		(yyval.pnode)->childLHS = (yyvsp[(3) - (9)].pnode);
		(yyvsp[(3) - (9)].pnode)->next = (yyvsp[(6) - (9)].pnode);
	;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 716 "psycon.y"
    { // v{2}(4:6)=1 
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(9) - (9)].pnode);
		(yyval.pnode)->childLHS = (yyvsp[(3) - (9)].pnode);
		(yyvsp[(3) - (9)].pnode)->next = (yyvsp[(6) - (9)].pnode);
	;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 724 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 730 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(6) - (6)].pnode)->childLHS = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 737 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(6) - (6)].pnode)->childLHS = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 744 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(9) - (9)].pnode);
		(yyvsp[(9) - (9)].pnode)->childLHS = (yyvsp[(6) - (9)].pnode);
		(yyvsp[(6) - (9)].pnode)->childLHS = (yyvsp[(3) - (9)].pnode);
	;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 752 "psycon.y"
    { // x={"bjk",noise(300), 4.5555}
		(yyval.pnode) = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 759 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(5) - (8)].str);
		(yyval.pnode)->child = (yyvsp[(7) - (8)].pnode);
		(yyvsp[(7) - (8)].pnode)->next = newAstNode(NODE_INITCELL, (yylsp[(1) - (8)]));
		(yyvsp[(7) - (8)].pnode)->next->str = (yyvsp[(1) - (8)].str);
	;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 767 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(5) - (8)].str);
		(yyval.pnode)->child = (yyvsp[(7) - (8)].pnode);
		(yyvsp[(7) - (8)].pnode)->next = (yyvsp[(2) - (8)].pnode);
	;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 776 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_NUMBER, (yyloc));
		(yyval.pnode)->dval = (yyvsp[(1) - (1)].dval);
	;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 781 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_STRING, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 786 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_DUR, (yyloc));
		(yyval.pnode)->str = NULL;
	;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 791 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_LENGTH, (yyloc));
		(yyval.pnode)->str = NULL;
	;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 796 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 801 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (4)].pnode);
	;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 807 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (7)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (7)].pnode);
		(yyvsp[(3) - (7)].pnode)->childLHS = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 814 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (7)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (7)].pnode);
		(yyvsp[(3) - (7)].pnode)->childLHS = (yyvsp[(6) - (7)].pnode);
		(yyval.pnode)->line = 232;
	;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 822 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 827 "psycon.y"
    { // I don't know what this is doing.... bjk 3/28/2017 
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 832 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->type = NODE_CALL;
 		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 840 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->LastChild = (yyvsp[(3) - (4)].pnode); // leaving a mark for conditional indexing 3/28/2017 bjk
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 849 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = malloc(strlen((yyvsp[(2) - (4)].str))+2);
 		(yyval.pnode)->str[0] = '#';
 		strcpy((yyval.pnode)->str+1, (yyvsp[(2) - (4)].str));
 		free((yyvsp[(2) - (4)].str));
	;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 857 "psycon.y"
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

  case 139:

/* Line 1455 of yacc.c  */
#line 868 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_EXTRACT, (yyloc));
		(yyval.pnode)->child = newAstNode(T_ID, (yylsp[(1) - (6)]));
		(yyval.pnode)->child->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child->next = (yyvsp[(3) - (6)].pnode);
		(yyvsp[(3) - (6)].pnode)->next = (yyvsp[(5) - (6)].pnode);
	;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 876 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_NEGATIVE, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (2)].pnode);
	;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 881 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (2)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 887 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 893 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_SIGMA, (yyloc));
		(yyval.pnode)->child = newAstNode('=', (yylsp[(3) - (8)]));
		(yyval.pnode)->child->str = (yyvsp[(3) - (8)].str);
		(yyval.pnode)->child->child = (yyvsp[(5) - (8)].pnode);
		(yyval.pnode)->child->next = (yyvsp[(7) - (8)].pnode);
	;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 901 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('+', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 903 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('-', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 905 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('*', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 907 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('/', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 909 "psycon.y"
    { (yyval.pnode) = makeFunctionCall("^", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 911 "psycon.y"
    { (yyval.pnode) = makeFunctionCall("caret", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 913 "psycon.y"
    { (yyval.pnode) = makeFunctionCall("shift_spectrum", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 915 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('@', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 917 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INTERPOL, (yyloc));
		(yyval.pnode)->child = (yyvsp[(1) - (5)].pnode);
		(yyvsp[(1) - (5)].pnode)->next = (yyvsp[(3) - (5)].pnode);
		(yyvsp[(3) - (5)].pnode)->next = (yyvsp[(5) - (5)].pnode);
		(yyval.pnode)->LastChild = (yyvsp[(5) - (5)].pnode);
	;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 925 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_SHIFT, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 927 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_SHIFT2, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 929 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_CONCAT, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 931 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 937 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 943 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_REPLICA, (yyloc));
		(yyval.pnode)->str = NULL;
	;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 950 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->type = NODE_INITCELL;
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;



/* Line 1455 of yacc.c  */
#line 4079 "psycon.tab.c"
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
#line 958 "psycon.y"


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

