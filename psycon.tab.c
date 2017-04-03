
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
     T_LOGIC_NOT = 291
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
#line 98 "psycon.y"

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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2426

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNRULES -- Number of states.  */
#define YYNSTATES  350

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    66,    40,    41,     2,     2,
      51,    52,    43,    39,    49,    38,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    50,
      35,    34,    36,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,    67,    54,    65,     2,     2,     2,
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
      47,    48,    58,    59,    60,    61,    62,    63,    64
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
     298,   302,   305,   309,   313,   317,   321,   322,   324,   328,
     332,   338,   340,   342,   344,   348,   349,   351,   355,   357,
     360,   364,   368,   374,   376,   378,   382,   386,   390,   394,
     398,   402,   406,   410,   414,   421,   430,   439,   448,   457,
     466,   475,   484,   491,   501,   505,   512,   519,   529,   533,
     542,   551,   553,   555,   557,   559,   561,   566,   574,   578,
     582,   587,   592,   597,   603,   610,   613,   616,   620,   629,
     633,   637,   641,   645,   649,   653,   657,   661,   667,   671,
     675,   679,   683,   687
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      69,     0,    -1,    -1,    70,    -1,    73,    -1,    70,    73,
      -1,    72,    -1,    71,    72,    -1,     4,    -1,     1,     4,
      -1,    76,    74,    -1,    72,    -1,    77,    -1,    49,    -1,
      50,    -1,     4,    -1,     0,    -1,    -1,    17,    -1,     0,
      -1,    89,    -1,    88,    -1,    80,    -1,     5,    80,    71,
      78,     8,    -1,     5,    80,    49,    71,    78,     8,    -1,
       5,    80,    71,    78,     6,    71,     8,    -1,     5,    80,
      49,    71,    78,     6,    71,     8,    -1,     5,    89,    71,
      78,     8,    -1,     5,    89,    49,    71,    78,     8,    -1,
       5,    89,    71,    78,     6,    71,     8,    -1,     5,    89,
      49,    71,    78,     6,    71,     8,    -1,    13,    89,    79,
       8,    -1,    13,    89,    79,    15,    71,     8,    -1,     9,
      80,    71,     8,    -1,     9,    89,    71,     8,    -1,     9,
      80,    49,    71,     8,    -1,     9,    89,    49,    71,     8,
      -1,    10,    31,    34,    87,    71,     8,    -1,    10,    31,
      34,    87,    49,    71,     8,    -1,    18,    -1,    11,    -1,
      12,    -1,    16,    31,    51,    81,    52,    71,    75,    -1,
      16,    31,    34,    31,    51,    81,    52,    71,    75,    -1,
      16,    31,    53,    54,    34,    31,    51,    81,    52,    71,
      75,    -1,    16,    55,    85,    56,    34,    31,    51,    81,
      52,    71,    75,    -1,    -1,    78,     7,    80,    71,    -1,
      -1,     4,    -1,    79,    14,    89,     4,    71,    -1,    79,
      14,    53,    83,    54,    71,    -1,    89,    35,    89,    -1,
      86,    35,    89,    -1,    89,    35,    86,    -1,    89,    36,
      89,    -1,    86,    36,    89,    -1,    89,    36,    86,    -1,
      89,    23,    89,    -1,    86,    23,    89,    -1,    89,    23,
      86,    -1,    89,    24,    89,    -1,    86,    24,    89,    -1,
      89,    24,    86,    -1,    89,    26,    89,    -1,    86,    26,
      89,    -1,    89,    26,    86,    -1,    89,    25,    89,    -1,
      86,    25,    89,    -1,    89,    25,    86,    -1,    51,    80,
      52,    -1,    57,    80,    -1,    80,    27,    80,    -1,    89,
      27,    89,    -1,    80,    28,    80,    -1,    89,    28,    89,
      -1,    -1,    31,    -1,    31,    53,    54,    -1,    81,    49,
      31,    -1,    81,    49,    31,    53,    54,    -1,    87,    -1,
      90,    -1,    82,    -1,    83,    49,    82,    -1,    -1,    85,
      -1,    84,    50,    85,    -1,    87,    -1,    85,    87,    -1,
      85,    49,    87,    -1,    89,    37,    89,    -1,    89,    37,
      89,    37,    89,    -1,    89,    -1,    86,    -1,    31,    34,
      87,    -1,    31,    34,    80,    -1,    31,    58,    87,    -1,
      31,    59,    87,    -1,    31,    60,    87,    -1,    31,    61,
      87,    -1,    31,    62,    87,    -1,    31,    63,    87,    -1,
      31,    64,    87,    -1,    31,    53,    89,    54,    34,    87,
      -1,    31,    51,    89,    65,    89,    52,    34,    89,    -1,
      31,    51,    89,    65,    89,    52,    58,    87,    -1,    31,
      51,    89,    65,    89,    52,    59,    87,    -1,    31,    51,
      89,    65,    89,    52,    60,    87,    -1,    31,    51,    89,
      65,    89,    52,    61,    87,    -1,    31,    51,    89,    65,
      89,    52,    63,    87,    -1,    31,    51,    89,    65,    89,
      52,    64,    87,    -1,    31,    51,    83,    52,    34,    87,
      -1,    31,    53,    89,    54,    51,    89,    52,    34,    87,
      -1,    31,    34,    88,    -1,    31,    53,    89,    54,    34,
      88,    -1,    31,    51,    83,    52,    34,    88,    -1,    31,
      53,    89,    54,    51,    89,    52,    34,    88,    -1,    31,
      34,    90,    -1,    31,    53,    54,    34,    31,    51,    83,
      52,    -1,    55,    85,    56,    34,    31,    51,    83,    52,
      -1,    29,    -1,    30,    -1,    32,    -1,    33,    -1,    31,
      -1,    31,    53,    89,    54,    -1,    31,    53,    89,    54,
      51,    89,    52,    -1,    31,    53,    54,    -1,    31,    51,
      52,    -1,    31,    51,    83,    52,    -1,    31,    51,    80,
      52,    -1,    66,    31,    51,    52,    -1,    66,    31,    51,
      83,    52,    -1,    31,    51,    89,    65,    89,    52,    -1,
      38,    89,    -1,    39,    89,    -1,    51,    87,    52,    -1,
      19,    51,    31,    34,    87,    49,    89,    52,    -1,    89,
      39,    89,    -1,    89,    38,    89,    -1,    89,    43,    89,
      -1,    89,    44,    89,    -1,    89,    45,    89,    -1,    89,
      41,    89,    -1,    89,    40,    89,    -1,    89,    42,    89,
      -1,    89,    42,    89,    67,    89,    -1,    89,    20,    89,
      -1,    89,    21,    89,    -1,    89,    22,    89,    -1,    55,
      84,    56,    -1,    55,    85,    56,    -1,    53,    83,    54,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   111,   111,   112,   116,   118,   136,   143,   164,   166,
     171,   175,   177,   181,   181,   181,   181,   184,   184,   184,
     187,   189,   191,   193,   202,   211,   224,   237,   246,   255,
     268,   281,   289,   298,   304,   310,   316,   322,   330,   338,
     342,   344,   348,   355,   364,   373,   384,   385,   398,   399,
     401,   411,   423,   425,   427,   429,   431,   433,   435,   437,
     439,   441,   443,   445,   447,   449,   451,   453,   455,   457,
     459,   465,   470,   472,   474,   476,   481,   484,   490,   496,
     502,   510,   512,   516,   521,   529,   532,   537,   544,   549,
     554,   561,   565,   572,   574,   578,   584,   590,   596,   602,
     608,   614,   620,   626,   633,   640,   648,   652,   656,   660,
     664,   668,   672,   679,   687,   693,   700,   707,   715,   722,
     730,   739,   744,   749,   754,   759,   764,   770,   777,   782,
     787,   795,   804,   812,   823,   831,   836,   842,   848,   856,
     858,   860,   862,   864,   866,   868,   870,   872,   880,   882,
     884,   886,   892,   900
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
  "T_NEGATIVE", "T_POSITIVE", "T_LOGIC_NOT", "','", "';'", "'('", "')'",
  "'{'", "'}'", "'['", "']'", "'!'", "\"+=\"", "\"-=\"", "\"*=\"",
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
      36,    37,    64,    42,    47,    94,   289,   290,   291,    44,
      59,    40,    41,   123,   125,    91,    93,    33,   292,   293,
     294,   295,   296,   297,   298,   126,    35,   124
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      72,    73,    73,    74,    74,    74,    74,    75,    75,    75,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    77,    77,    77,    77,    78,    78,    79,    79,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    81,    81,    81,    81,
      81,    82,    82,    83,    83,    84,    84,    84,    85,    85,
      85,    86,    86,    87,    87,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    90
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
       3,     2,     3,     3,     3,     3,     0,     1,     3,     3,
       5,     1,     1,     1,     3,     0,     1,     3,     1,     2,
       3,     3,     5,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     6,     8,     8,     8,     8,     8,
       8,     8,     6,     9,     3,     6,     6,     9,     3,     8,
       8,     1,     1,     1,     1,     1,     4,     7,     3,     3,
       4,     4,     4,     5,     6,     2,     2,     3,     8,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     3,     3,
       3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     8,     0,     0,     0,    40,    41,     0,     0,
      39,     0,   121,   122,   125,   123,   124,     0,     0,     0,
      85,     0,     0,     0,     0,    11,     4,     0,    12,    22,
       0,    21,    20,     9,   125,    85,     0,     0,     0,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,   136,     0,    94,
       0,    93,     0,    86,    94,    88,    93,    71,     0,     0,
       1,     5,    16,    15,    13,    14,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,     0,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,    76,     0,     0,     0,     0,    96,    95,
     114,   118,   129,     0,    83,     0,    81,    93,    82,   128,
       0,    97,    98,    99,   100,   101,   102,   103,    70,   137,
       0,   151,     0,   152,    89,     0,    72,    74,    59,    62,
      68,    65,    53,    56,   148,   149,   150,    60,    58,    63,
      61,    69,    67,    66,    64,    73,    75,    54,    52,    57,
      55,    91,   140,   139,   145,   144,   146,   141,   142,   143,
       0,    93,   128,     0,   152,     0,     7,     0,   135,   136,
       0,     0,     0,    33,     0,    34,     0,    31,     0,     0,
       0,    77,     0,     0,     0,     0,     0,   131,     0,   130,
       0,     0,   126,    87,    90,     0,   132,     0,     0,     0,
     130,     0,   126,     0,     0,     0,    23,     0,     0,    27,
      35,    36,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,     0,     0,   153,    84,     0,     0,     0,     0,
       0,     0,   133,    92,   147,     0,     0,     0,    24,     0,
       0,     0,    28,     0,     0,    37,     0,     0,    32,     0,
      78,    79,     0,     0,     0,     0,   112,   116,   134,     0,
     104,   115,     0,     0,   134,     0,     0,    25,     0,     0,
      29,    38,     0,     0,     0,     0,    19,    18,    42,    76,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,     0,   127,    26,    30,     0,     0,    80,     0,     0,
     138,   105,   106,   107,   108,   109,   110,   111,   119,     0,
     120,    43,     0,     0,   113,   117,     0,     0,    44,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,   109,   110,    26,    76,   308,    27,    28,
     197,   121,    29,   212,   134,   135,    62,    63,    30,   136,
      31,    32,   138
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -245
static const yytype_int16 yypact[] =
{
     717,     3,  -245,  2138,  2138,    -8,  -245,  -245,   148,   -21,
    -245,    -7,  -245,  -245,     9,  -245,  -245,   148,   148,  2138,
     148,  2138,    43,   111,   766,  -245,  -245,     8,  -245,     5,
     202,  -245,  2381,  -245,    24,   148,   913,   815,   962,   864,
      83,   148,   719,   120,   148,    88,   513,   106,   246,   148,
     148,   148,   148,   148,   148,   148,  -245,  -245,   -11,   202,
      77,  2381,   -10,   595,  -245,  -245,  1313,  -245,  2381,    79,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  2138,  2138,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   106,  2167,  2042,  1939,   459,
    -245,   148,   148,  1939,   459,  1939,  1251,  1939,  1310,   148,
    -245,   119,   109,   129,   110,  2080,   132,  2196,     5,  -245,
    -245,  -245,  -245,    96,  -245,   -38,  -245,  2319,  -245,   134,
     915,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
     148,  -245,   148,   142,  -245,  2109,  -245,   156,  1430,  1430,
    1430,  1430,  1430,  1430,   204,   204,   149,  -245,  1313,  -245,
    1313,  -245,  1313,  -245,  1313,  1430,  1430,  -245,  1313,  -245,
    1313,  1372,   149,   149,   204,   204,    -6,   139,   139,   139,
     113,  2350,  -245,   964,  -245,   459,  -245,   244,  1988,  2037,
     459,   247,  1369,  -245,  1428,  -245,  1477,  -245,  2225,  1939,
     137,   143,   133,   164,   179,   148,    92,  -245,  2196,   184,
     148,   191,    25,  2254,  -245,   209,  -245,   158,   148,   148,
    -245,   148,   172,   256,  1939,  2138,  -245,   264,  1939,  -245,
    -245,  -245,  1939,  1536,  2196,   769,  1595,   129,   181,   225,
    1939,   227,   228,   217,  -245,  -245,  2283,  1027,   229,  2283,
     148,   230,  -245,  1430,  1430,  1086,   148,  1939,  -245,  1654,
    1192,  1939,  -245,  1713,  1772,  -245,   101,  1939,  -245,   159,
    -245,   215,   654,   232,   236,   148,  -245,  -245,   -33,  2196,
    -245,  -245,  1147,  2196,  -245,  1194,  1831,  -245,  1025,  1890,
    -245,  -245,  1939,  1084,  1939,   234,  -245,  -245,  -245,   129,
     129,  1253,   148,   148,   148,   148,   148,   148,   148,   168,
     255,   182,  -245,  -245,  -245,  1143,   654,  -245,   190,   192,
    -245,  1430,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  2283,
    -245,  -245,  1939,  1939,  -245,  -245,   654,   654,  -245,  -245
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -245,  -245,  -245,   270,     0,   267,  -245,  -204,  -245,  -245,
     -85,  -245,   128,  -244,    74,   -92,  -245,   -29,   304,   386,
     -44,     1,   258
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -141
static const yytype_int16 yytable[] =
{
      25,   312,   130,   279,    37,    39,   107,    33,    72,    42,
      43,   218,    73,   190,   219,   125,    77,    78,    56,    57,
      61,    66,    68,    40,    25,   313,   314,   315,   316,   201,
     317,   318,    77,    78,    44,   216,    66,   102,   103,   104,
     150,   148,    66,    46,    45,    66,   151,    61,   137,   140,
      66,    66,    66,    66,    66,    66,    66,    74,    75,   259,
      47,   229,    48,   227,    66,   328,   329,    49,    50,    51,
      52,    53,    54,    55,    69,   105,   260,   106,    68,    68,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   168,
     170,   172,   174,   175,   176,   178,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   191,   193,    66,   196,
     233,    70,   198,   199,   196,   237,   196,   119,   196,   126,
      66,   223,   341,    77,    78,    11,    66,   207,    66,   149,
     155,    36,    38,   208,   209,    12,    13,    34,    15,    16,
     210,   218,   348,   349,    17,    18,   254,    58,   217,    67,
     218,    66,   276,    66,   122,   302,    66,    19,   132,   127,
     211,    35,   218,    21,   213,   230,   215,    11,   221,    85,
      86,   123,    22,   124,   128,   133,   225,    12,    13,    34,
      15,    16,   249,    77,   104,   250,    17,    18,   247,    99,
     100,   101,   102,   103,   104,   196,   248,   319,   251,    41,
     196,   321,   196,    35,   196,   156,   157,   218,   249,   245,
     262,   304,   287,   252,    22,   291,    66,   218,   256,    66,
     338,   257,   258,   266,    66,    79,    80,    81,    82,   263,
     264,   218,   265,   133,   340,   280,    68,    83,    84,   249,
     261,   249,   342,   196,   343,    66,   196,   102,   103,   104,
     234,   235,   236,   238,   235,   239,   281,    66,   283,   284,
      66,   292,   267,   235,   268,    11,   285,   295,   305,   196,
     271,   235,   272,   196,   196,    12,    13,    34,    15,    16,
     289,   293,   196,   309,    17,    18,   311,   310,   327,   339,
      66,    71,   255,     0,    66,   345,   196,    41,   196,   196,
     139,    35,     0,   196,   131,     0,     0,   114,   116,   118,
       0,     0,    22,   331,    66,    66,    66,    66,    66,    66,
       0,     0,     0,    59,    64,   196,   196,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      66,     0,     0,     0,     0,    64,   196,   196,    64,     0,
      59,    59,     0,    64,    64,    64,    64,    64,    64,    64,
       0,     0,     0,   270,     0,     0,     0,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   195,     0,
       0,     0,     0,   200,     0,   202,     0,   204,     0,     0,
       0,     0,   167,   169,   171,   173,     0,     0,   177,   179,
       0,     0,     0,     0,     0,    60,    65,     0,     0,    59,
       0,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,    64,     0,     0,     0,    60,     0,    64,
      65,    64,   129,     0,     0,   141,   142,   143,   144,   145,
     146,   147,     0,     0,     0,     0,     0,     0,     0,   154,
       0,     0,     0,     0,    64,     0,    64,     0,     0,    64,
       1,     0,     0,     2,     3,   -46,   -46,   -46,     4,     5,
       6,     7,     8,     0,     0,     0,   243,    10,    11,   246,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    13,
      14,    15,    16,   154,     0,     0,     0,    17,    18,     0,
       0,     0,     0,     0,   269,   206,     0,     0,   273,     0,
      19,   154,   274,     0,    20,     0,    21,     0,     0,    64,
     282,     0,    64,     0,     0,    22,     0,    64,     0,     0,
       0,     0,    11,     0,     0,     0,    65,   296,   224,     0,
     298,   299,    12,    13,    14,    15,    16,   303,    64,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
      64,     0,     0,    64,    19,     0,   127,     0,    20,     0,
      21,     0,   325,     0,   326,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,     0,     0,     0,    64,     0,     0,
       0,   253,     0,     0,     0,     0,     0,     0,     0,   154,
       0,     0,   346,   347,    11,     0,     0,    64,    64,    64,
      64,    64,    64,     0,    12,    13,    34,    15,    16,     0,
       0,     0,     0,    17,    18,     0,     0,     0,     0,     0,
       0,     0,   286,    64,   152,   290,    41,     0,     0,     0,
      35,   153,     0,     0,   306,     1,     0,     0,     2,     3,
       0,    22,     0,     4,     5,     6,     7,     8,     0,     0,
     -17,   307,    10,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,    13,    14,    15,    16,     0,     0,
       0,     0,    17,    18,     0,     0,     0,     0,     0,   332,
     333,   334,   335,   336,   337,    19,     0,     0,     0,    20,
       0,    21,     0,     0,     0,     0,     0,    -2,     1,     0,
      22,     2,     3,   120,     0,   344,     4,     5,     6,     7,
       8,     0,     0,     9,     0,    10,    11,     0,     0,    85,
      86,    87,     0,     0,     0,     0,    12,    13,    14,    15,
      16,     0,     0,     0,     0,    17,    18,    97,    98,    99,
     100,   101,   102,   103,   104,     0,    -3,     1,    19,     0,
       2,     3,    20,   277,    21,     4,     5,     6,     7,     8,
       0,     0,     9,    22,    10,    11,     0,     0,     0,    85,
      86,    87,     0,     0,     0,    12,    13,    14,    15,    16,
       0,     0,     0,     0,    17,    18,     0,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     1,    19,     0,     2,
       3,    20,     0,    21,     4,     5,     6,     7,     8,     0,
       0,     0,    22,    10,    11,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    12,    13,    14,    15,    16,     0,
      94,    95,    96,   111,   112,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   113,     1,    19,     0,     2,     3,
      20,     0,    21,     4,     5,     6,     7,     8,     0,     0,
       0,    22,    10,    11,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    12,    13,    14,    15,    16,     0,    94,
      95,    96,   111,   112,    99,   100,   101,   102,   103,   104,
       0,     0,     0,   117,     1,    19,     0,     2,     3,    20,
       0,    21,     4,     5,     6,     7,     8,     0,     0,     0,
      22,    10,    11,     0,     0,    85,    86,    87,     0,     0,
      77,    78,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,    97,    98,    99,   100,   101,   102,   103,
     104,     0,   108,     1,    19,     0,     2,     3,    20,   222,
      21,     4,     5,     6,     7,     8,     0,     0,     0,    22,
      10,    11,     0,     0,    85,    86,    87,     0,     0,    77,
      78,    12,    13,    14,    15,    16,     0,     0,     0,     0,
      17,    18,    97,    98,    99,   100,   101,   102,   103,   104,
       0,   115,     0,    19,     0,     0,     0,    20,   232,    21,
       0,     0,     0,     0,     0,     0,     1,     0,    22,     2,
       3,   -47,   -47,   -47,     4,     5,     6,     7,     8,     0,
       0,     0,     0,    10,    11,     0,     0,    85,    86,    87,
       0,     0,     0,     0,    12,    13,    14,    15,    16,     0,
       0,     0,     0,    17,    18,    97,    98,    99,   100,   101,
     102,   103,   104,     0,     0,     0,    19,     0,     0,   288,
      20,     0,    21,     0,     0,     1,     0,     0,     2,     3,
       0,    22,   -50,     4,     5,     6,     7,     8,   -50,   -50,
       0,     0,    10,    11,     0,     0,    85,    86,    87,     0,
       0,     0,     0,    12,    13,    14,    15,    16,     0,     0,
       0,     0,    17,    18,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,     0,    19,     0,     0,   294,    20,
       0,    21,     0,     0,     1,     0,     0,     2,     3,     0,
      22,   -51,     4,     5,     6,     7,     8,   -51,   -51,     0,
       0,    10,    11,     0,     0,     0,     0,    85,    86,    87,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,     1,    19,     0,     2,     3,    20,   320,
      21,     4,     5,     6,     7,     8,     0,     0,     0,    22,
      10,    11,     0,     0,    85,    86,    87,     0,     0,    77,
      78,    12,    13,    14,    15,    16,     0,     0,     0,     0,
      17,    18,    97,    98,    99,   100,   101,   102,   103,   104,
       0,     0,     0,    19,     0,     0,   322,    20,     0,    21,
       0,     0,     1,     0,     0,     2,     3,     0,    22,   203,
       4,     5,     6,     7,     8,     0,     0,     0,     0,    10,
      11,     0,     0,    85,    86,    87,     0,     0,     0,     0,
      12,    13,    14,    15,    16,     0,     0,     0,     0,    17,
      18,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,     0,    19,     0,     0,   330,    20,     0,    21,     0,
       0,     1,     0,     0,     2,     3,     0,    22,   205,     4,
       5,     6,     7,     8,     0,     0,     0,     0,    10,    11,
       0,     0,     0,    85,    86,    87,     0,     0,     0,    12,
      13,    14,    15,    16,     0,     0,     0,     0,    17,    18,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,    19,     0,     0,     0,    20,     0,    21,     0,     0,
       1,     0,     0,     2,     3,     0,    22,   240,     4,     5,
       6,     7,     8,     0,     0,     0,     0,    10,    11,     0,
       0,     0,    85,    86,    87,     0,     0,     0,    12,    13,
      14,    15,    16,     0,     0,     0,     0,    17,    18,   228,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     0,
      19,     0,     0,     0,    20,     0,    21,     0,     0,     1,
       0,     0,     2,     3,     0,    22,   241,     4,     5,     6,
       7,     8,     0,     0,     0,     0,    10,    11,     0,     0,
      85,    86,    87,     0,     0,     0,     0,    12,    13,    14,
      15,    16,     0,     0,     0,     0,    17,    18,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,     1,    19,
       0,     2,     3,    20,     0,    21,     4,     5,     6,     7,
       8,     0,     0,     0,    22,    10,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    13,    14,    15,
      16,     0,     0,     0,     0,    17,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   242,     0,    19,     0,
       0,     0,    20,     0,    21,     0,     0,     1,     0,     0,
       2,     3,     0,    22,   275,     4,     5,     6,     7,     8,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    13,    14,    15,    16,
       0,     0,     0,     0,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,    20,     0,    21,     0,     0,     1,     0,     0,     2,
       3,     0,    22,   278,     4,     5,     6,     7,     8,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    13,    14,    15,    16,     0,
       0,     0,     0,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,     0,     0,     0,
      20,     0,    21,     0,     0,     1,     0,     0,     2,     3,
       0,    22,   297,     4,     5,     6,     7,     8,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,    13,    14,    15,    16,     0,     0,
       0,     0,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,     0,     0,     0,    20,
       0,    21,     0,     0,     1,     0,     0,     2,     3,     0,
      22,   300,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,    20,     0,
      21,     0,     0,     1,     0,     0,     2,     3,     0,    22,
     301,     4,     5,     6,     7,     8,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    13,    14,    15,    16,     0,     0,     0,     0,
      17,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,    20,     0,    21,
       0,     0,     1,     0,     0,     2,     3,     0,    22,   323,
       4,     5,     6,     7,     8,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    13,    14,    15,    16,     0,     0,     0,     0,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,     0,    20,     0,    21,     0,
       0,     1,     0,     0,     2,     3,     0,    22,   324,     4,
       5,     6,     7,     8,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
      13,    14,    15,    16,     0,     0,     0,     0,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,    19,     0,     2,     3,    20,     0,    21,     4,     5,
       6,     7,     8,     0,     0,     0,    22,    10,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    13,
      14,    15,    16,     0,     0,     0,     0,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -140,
      19,     0,     0,  -140,    20,     0,    21,  -140,  -140,  -140,
    -140,  -140,     0,     0,     0,    22,  -140,  -140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -140,  -140,  -140,
    -140,  -140,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -139,  -140,
       0,     0,  -139,  -140,     0,  -140,  -139,  -139,  -139,  -139,
    -139,     0,     0,     0,  -140,  -139,  -139,     0,     0,     0,
       0,    11,     0,     0,     0,     0,  -139,  -139,  -139,  -139,
    -139,    12,    13,    34,    15,    16,     0,     0,     0,     0,
      17,    18,     0,     0,     0,     0,     0,     0,  -139,     0,
       0,   152,  -139,    41,  -139,     0,     0,    35,   194,    11,
       0,     0,     0,  -139,     0,     0,     0,     0,    22,    12,
      13,    34,    15,    16,     0,     0,     0,     0,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,    11,   152,
       0,    41,     0,     0,     0,    35,   214,     0,    12,    13,
      34,    15,    16,     0,     0,     0,    22,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
      41,   226,   127,     0,    35,     0,     0,    12,    13,    34,
      15,    16,     0,     0,     0,    22,    17,    18,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,     0,    19,
       0,     0,     0,    35,     0,    21,    12,    13,    34,    15,
      16,     0,     0,     0,    22,    17,    18,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,    41,     0,
       0,   192,    35,     0,     0,    12,    13,    34,    15,    16,
       0,     0,     0,    22,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,    41,     0,   127,
       0,    35,     0,     0,    12,    13,    34,    15,    16,     0,
       0,     0,    22,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,    41,     0,   244,     0,
      35,     0,     0,    12,    13,    34,    15,    16,     0,     0,
       0,    22,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,    11,   152,     0,    41,     0,     0,     0,    35,
       0,     0,    12,    13,    14,    15,    16,     0,     0,     0,
      22,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,    20,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,    22,
       0,     0,     0,     0,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,    93,     0,
       0,     0,     0,     0,   220,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,     0,     0,
       0,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,     0,     0,     0,     0,   231,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104
};

static const yytype_int16 yycheck[] =
{
       0,    34,    46,   247,     3,     4,    35,     4,     0,     8,
      31,    49,     4,   105,    52,    44,    27,    28,    17,    18,
      19,    20,    21,    31,    24,    58,    59,    60,    61,   114,
      63,    64,    27,    28,    55,   127,    35,    43,    44,    45,
      50,    52,    41,    34,    51,    44,    56,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    49,    50,    34,
      51,    67,    53,   155,    63,   309,   310,    58,    59,    60,
      61,    62,    63,    64,    31,    51,    51,    53,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   109,
     195,     0,   111,   112,   114,   200,   116,    34,   118,    31,
     119,   150,   326,    27,    28,    19,   125,     8,   127,    52,
      51,     3,     4,    14,    15,    29,    30,    31,    32,    33,
      31,    49,   346,   347,    38,    39,    54,    19,    52,    21,
      49,   150,   244,   152,    34,    54,   155,    51,    52,    53,
      31,    55,    49,    57,    54,    52,    34,    19,    34,    20,
      21,    51,    66,    53,    46,    47,    34,    29,    30,    31,
      32,    33,    49,    27,    45,    52,    38,    39,    51,    40,
      41,    42,    43,    44,    45,   195,    53,   289,    34,    51,
     200,   293,   202,    55,   204,    77,    78,    49,    49,   208,
      52,    52,   256,    34,    66,   259,   215,    49,    34,   218,
      52,   220,    31,    51,   223,    23,    24,    25,    26,   228,
     229,    49,   231,   105,    52,    54,   235,    35,    36,    49,
      31,    49,    52,   243,    52,   244,   246,    43,    44,    45,
       6,     7,     8,     6,     7,     8,    31,   256,    31,    31,
     259,   260,     6,     7,     8,    19,    49,   266,    53,   269,
       6,     7,     8,   273,   274,    29,    30,    31,    32,    33,
      51,    51,   282,    51,    38,    39,   285,    51,    54,    34,
     289,    24,   218,    -1,   293,   339,   296,    51,   298,   299,
      54,    55,    -1,   303,    46,    -1,    -1,    37,    38,    39,
      -1,    -1,    66,   312,   313,   314,   315,   316,   317,   318,
      -1,    -1,    -1,    19,    20,   325,   326,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
     339,    -1,    -1,    -1,    -1,    41,   346,   347,    44,    -1,
      46,    47,    -1,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,
      -1,    -1,    -1,   113,    -1,   115,    -1,   117,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    19,    20,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,   119,    -1,    -1,    -1,    41,    -1,   125,
      44,   127,    46,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,   150,    -1,   152,    -1,    -1,   155,
       1,    -1,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,   206,    18,    19,   209,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,   107,    -1,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,   234,   119,    -1,    -1,   238,    -1,
      51,   125,   242,    -1,    55,    -1,    57,    -1,    -1,   215,
     250,    -1,   218,    -1,    -1,    66,    -1,   223,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    -1,   150,   267,   152,    -1,
     270,   271,    29,    30,    31,    32,    33,   277,   244,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,    -1,    -1,   259,    51,    -1,    53,    -1,    55,    -1,
      57,    -1,   302,    -1,   304,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   289,    -1,    -1,    -1,   293,    -1,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,
      -1,    -1,   342,   343,    19,    -1,    -1,   313,   314,   315,
     316,   317,   318,    -1,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   256,   339,    49,   259,    51,    -1,    -1,    -1,
      55,    56,    -1,    -1,     0,     1,    -1,    -1,     4,     5,
      -1,    66,    -1,     9,    10,    11,    12,    13,    -1,    -1,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,   313,
     314,   315,   316,   317,   318,    51,    -1,    -1,    -1,    55,
      -1,    57,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,
      66,     4,     5,     4,    -1,   339,     9,    10,    11,    12,
      13,    -1,    -1,    16,    -1,    18,    19,    -1,    -1,    20,
      21,    22,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    39,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,     0,     1,    51,    -1,
       4,     5,    55,     4,    57,     9,    10,    11,    12,    13,
      -1,    -1,    16,    66,    18,    19,    -1,    -1,    -1,    20,
      21,    22,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    39,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,     1,    51,    -1,     4,
       5,    55,    -1,    57,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    66,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    49,     1,    51,    -1,     4,     5,
      55,    -1,    57,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    66,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    49,     1,    51,    -1,     4,     5,    55,
      -1,    57,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      66,    18,    19,    -1,    -1,    20,    21,    22,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    49,     1,    51,    -1,     4,     5,    55,    54,
      57,     9,    10,    11,    12,    13,    -1,    -1,    -1,    66,
      18,    19,    -1,    -1,    20,    21,    22,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    39,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    49,    -1,    51,    -1,    -1,    -1,    55,    54,    57,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    66,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    18,    19,    -1,    -1,    20,    21,    22,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    39,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    51,    -1,    -1,    52,
      55,    -1,    57,    -1,    -1,     1,    -1,    -1,     4,     5,
      -1,    66,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    18,    19,    -1,    -1,    20,    21,    22,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    39,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    51,    -1,    -1,    52,    55,
      -1,    57,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      66,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,     1,    51,    -1,     4,     5,    55,    52,
      57,     9,    10,    11,    12,    13,    -1,    -1,    -1,    66,
      18,    19,    -1,    -1,    20,    21,    22,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    39,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    51,    -1,    -1,    52,    55,    -1,    57,
      -1,    -1,     1,    -1,    -1,     4,     5,    -1,    66,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,
      19,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,
      39,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    51,    -1,    -1,    52,    55,    -1,    57,    -1,
      -1,     1,    -1,    -1,     4,     5,    -1,    66,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    51,    -1,    -1,    -1,    55,    -1,    57,    -1,    -1,
       1,    -1,    -1,     4,     5,    -1,    66,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    18,    19,    -1,
      -1,    -1,    20,    21,    22,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      51,    -1,    -1,    -1,    55,    -1,    57,    -1,    -1,     1,
      -1,    -1,     4,     5,    -1,    66,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      20,    21,    22,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    39,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,     1,    51,
      -1,     4,     5,    55,    -1,    57,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    66,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,
      -1,    -1,    55,    -1,    57,    -1,    -1,     1,    -1,    -1,
       4,     5,    -1,    66,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    55,    -1,    57,    -1,    -1,     1,    -1,    -1,     4,
       5,    -1,    66,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      55,    -1,    57,    -1,    -1,     1,    -1,    -1,     4,     5,
      -1,    66,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    57,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
      66,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    55,    -1,
      57,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,    66,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    55,    -1,    57,
      -1,    -1,     1,    -1,    -1,     4,     5,    -1,    66,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    55,    -1,    57,    -1,
      -1,     1,    -1,    -1,     4,     5,    -1,    66,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    51,    -1,     4,     5,    55,    -1,    57,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    66,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      51,    -1,    -1,     5,    55,    -1,    57,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    66,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    51,
      -1,    -1,     5,    55,    -1,    57,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    66,    18,    19,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    49,    55,    51,    57,    -1,    -1,    55,    56,    19,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    66,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    49,
      -1,    51,    -1,    -1,    -1,    55,    56,    -1,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    66,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,
      51,    52,    53,    -1,    55,    -1,    -1,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    66,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    51,
      -1,    -1,    -1,    55,    -1,    57,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    66,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    51,    -1,
      -1,    54,    55,    -1,    -1,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    66,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    51,    -1,    53,
      -1,    55,    -1,    -1,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    66,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    51,    -1,    53,    -1,
      55,    -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    66,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    49,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      66,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    55,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    66,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    65,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    65,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     9,    10,    11,    12,    13,    16,
      18,    19,    29,    30,    31,    32,    33,    38,    39,    51,
      55,    57,    66,    69,    70,    72,    73,    76,    77,    80,
      86,    88,    89,     4,    31,    55,    80,    89,    80,    89,
      31,    51,    89,    31,    55,    51,    34,    51,    53,    58,
      59,    60,    61,    62,    63,    64,    89,    89,    80,    86,
      87,    89,    84,    85,    86,    87,    89,    80,    89,    31,
       0,    73,     0,     4,    49,    50,    74,    27,    28,    23,
      24,    25,    26,    35,    36,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    51,    53,    85,    49,    71,
      72,    38,    39,    49,    71,    49,    71,    49,    71,    34,
       4,    79,    34,    51,    53,    85,    31,    53,    80,    87,
      88,    90,    52,    80,    82,    83,    87,    89,    90,    54,
      89,    87,    87,    87,    87,    87,    87,    87,    52,    52,
      50,    56,    49,    56,    87,    51,    80,    80,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    86,    89,    86,
      89,    86,    89,    86,    89,    89,    89,    86,    89,    86,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      83,    89,    54,    89,    56,    71,    72,    78,    89,    89,
      71,    78,    71,     8,    71,     8,    87,     8,    14,    15,
      31,    31,    81,    54,    56,    34,    83,    52,    49,    52,
      65,    34,    54,    85,    87,    34,    52,    83,    37,    67,
      52,    65,    54,    78,     6,     7,     8,    78,     6,     8,
       8,     8,    49,    71,    53,    89,    71,    51,    53,    49,
      52,    34,    34,    87,    54,    82,    34,    89,    31,    34,
      51,    31,    52,    89,    89,    89,    51,     6,     8,    71,
      80,     6,     8,    71,    71,     8,    83,     4,     8,    81,
      54,    31,    71,    31,    31,    49,    87,    88,    52,    51,
      87,    88,    89,    51,    52,    89,    71,     8,    71,    71,
       8,     8,    54,    71,    52,    53,     0,    17,    75,    51,
      51,    89,    34,    58,    59,    60,    61,    63,    64,    83,
      52,    83,    52,     8,     8,    71,    71,    54,    81,    81,
      52,    89,    87,    87,    87,    87,    87,    87,    52,    34,
      52,    75,    52,    52,    87,    88,    71,    71,    75,    75
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
#line 91 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", (yyvaluep->str));
#endif
  free((yyvaluep->str));
};

/* Line 1000 of yacc.c  */
#line 1856 "psycon.tab.c"
	break;
      case 31: /* "\"identifier\"" */

/* Line 1000 of yacc.c  */
#line 91 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", (yyvaluep->str));
#endif
  free((yyvaluep->str));
};

/* Line 1000 of yacc.c  */
#line 1870 "psycon.tab.c"
	break;
      case 32: /* "\"fT\"" */

/* Line 1000 of yacc.c  */
#line 91 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", (yyvaluep->str));
#endif
  free((yyvaluep->str));
};

/* Line 1000 of yacc.c  */
#line 1884 "psycon.tab.c"
	break;
      case 33: /* "\"fP\"" */

/* Line 1000 of yacc.c  */
#line 91 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding string \"%s\"\n", (yyvaluep->str));
#endif
  free((yyvaluep->str));
};

/* Line 1000 of yacc.c  */
#line 1898 "psycon.tab.c"
	break;
      case 70: /* "block_func" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1912 "psycon.tab.c"
	break;
      case 71: /* "block" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1926 "psycon.tab.c"
	break;
      case 72: /* "line" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1940 "psycon.tab.c"
	break;
      case 73: /* "line_func" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1954 "psycon.tab.c"
	break;
      case 76: /* "stmt" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1968 "psycon.tab.c"
	break;
      case 77: /* "funcdef" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1982 "psycon.tab.c"
	break;
      case 78: /* "elseif_list" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 1996 "psycon.tab.c"
	break;
      case 79: /* "case_list" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2010 "psycon.tab.c"
	break;
      case 80: /* "condition" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2024 "psycon.tab.c"
	break;
      case 81: /* "id_list" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2038 "psycon.tab.c"
	break;
      case 82: /* "arg" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2052 "psycon.tab.c"
	break;
      case 83: /* "arg_list" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2066 "psycon.tab.c"
	break;
      case 84: /* "matrix" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2080 "psycon.tab.c"
	break;
      case 85: /* "vector" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2094 "psycon.tab.c"
	break;
      case 86: /* "range" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2108 "psycon.tab.c"
	break;
      case 87: /* "exp_range" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2122 "psycon.tab.c"
	break;
      case 88: /* "assign" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2136 "psycon.tab.c"
	break;
      case 89: /* "exp" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2150 "psycon.tab.c"
	break;
      case 90: /* "initcell" */

/* Line 1000 of yacc.c  */
#line 84 "psycon.y"
	{
#ifdef DEBUG
    printf("discarding node %s\n", getAstNodeName((yyvaluep->pnode)));
#endif
  yydeleteAstNode((yyvaluep->pnode), 0);
};

/* Line 1000 of yacc.c  */
#line 2164 "psycon.tab.c"
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
#line 75 "psycon.y"
{
  if (ErrorMsg) {
	free(ErrorMsg);
	ErrorMsg = NULL;
  }
  *errmsg = NULL;
}

/* Line 1242 of yacc.c  */
#line 2325 "psycon.tab.c"

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
#line 111 "psycon.y"
    { *pproot = NULL;;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 113 "psycon.y"
    { *pproot = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 117 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 119 "psycon.y"
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
#line 137 "psycon.y"
    {
		if ((yyvsp[(1) - (1)].pnode))
			(yyval.pnode) = (yyvsp[(1) - (1)].pnode);
		else
			(yyval.pnode) = newAstNode(NODE_BLOCK, (yyloc));
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 144 "psycon.y"
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
#line 165 "psycon.y"
    { (yyval.pnode) = NULL;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 167 "psycon.y"
    {
		(yyval.pnode) = NULL;
		yyerrok;
	;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 172 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (2)].pnode);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 176 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 178 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 188 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 190 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 192 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 194 "psycon.y"
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
#line 203 "psycon.y"
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
#line 212 "psycon.y"
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
#line 225 "psycon.y"
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
#line 238 "psycon.y"
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
#line 247 "psycon.y"
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
#line 256 "psycon.y"
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
#line 269 "psycon.y"
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
#line 282 "psycon.y"
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
#line 290 "psycon.y"
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
#line 299 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_WHILE, (yyloc));
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
	;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 305 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_WHILE, (yyloc));
		(yyvsp[(2) - (4)].pnode)->next = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (4)].pnode);
	;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 311 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_WHILE, (yyloc));
		(yyvsp[(2) - (5)].pnode)->next = (yyvsp[(4) - (5)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (5)].pnode);
	;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 317 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_WHILE, (yyloc));
		(yyvsp[(2) - (5)].pnode)->next = (yyvsp[(4) - (5)].pnode);
		(yyval.pnode)->child = (yyvsp[(2) - (5)].pnode);
	;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 323 "psycon.y"
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
#line 331 "psycon.y"
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
#line 339 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_RETURN, (yyloc));
	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 343 "psycon.y"
    { (yyval.pnode) = newAstNode(T_BREAK, (yyloc));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 345 "psycon.y"
    { (yyval.pnode) = newAstNode(T_CONTINUE, (yyloc));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 349 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_FUNCTION, (yyloc));
		(yyval.pnode)->str = (yyvsp[(2) - (7)].str);
		(yyval.pnode)->child = (yyvsp[(4) - (7)].pnode);
		(yyvsp[(4) - (7)].pnode)->next = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 356 "psycon.y"
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
#line 365 "psycon.y"
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
#line 374 "psycon.y"
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
#line 384 "psycon.y"
    { (yyval.pnode) = newAstNode(T_IF, (yyloc));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 386 "psycon.y"
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
#line 398 "psycon.y"
    { (yyval.pnode) = newAstNode(T_SWITCH, (yyloc));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 400 "psycon.y"
    { (yyval.pnode) = newAstNode(T_SWITCH, (yyloc));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 402 "psycon.y"
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
#line 412 "psycon.y"
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
#line 424 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('<', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 426 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('<', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 428 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('<', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 430 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('>', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 432 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('>', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 434 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('>', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 436 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_EQ, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 438 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_EQ, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 440 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_EQ, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 442 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_NE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 444 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_NE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 446 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_NE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 448 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_GE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 450 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_GE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 452 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_GE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 454 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_LE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 456 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_LE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 458 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_COMP_LE, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 460 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 466 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_LOGIC_NOT, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (2)].pnode);
	;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 471 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 473 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_AND, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 475 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 477 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_LOGIC_OR, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 481 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
	;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 485 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->LastChild = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->LastChild->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 491 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IDLIST, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->LastChild = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->LastChild->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 497 "psycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->LastChild = (yyvsp[(1) - (3)].pnode)->LastChild->next = newAstNode(T_ID, (yylsp[(3) - (3)]));
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
		(yyval.pnode)->LastChild->str = (yyvsp[(3) - (3)].str);
	;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 503 "psycon.y"
    {
		(yyvsp[(1) - (5)].pnode)->LastChild = (yyvsp[(1) - (5)].pnode)->LastChild->next = newAstNode(NODE_INITCELL, (yylsp[(3) - (5)]));
		(yyval.pnode) = (yyvsp[(1) - (5)].pnode);
		(yyval.pnode)->LastChild->str = (yyvsp[(3) - (5)].str);
	;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 511 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 513 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 517 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_ARGS, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->LastChild = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 522 "psycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->LastChild = (yyvsp[(1) - (3)].pnode)->LastChild->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 529 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_MATRIX, (yyloc));
	;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 533 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_MATRIX, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->LastChild = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 538 "psycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->LastChild = (yyvsp[(1) - (3)].pnode)->LastChild->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 545 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_VECTOR, (yyloc));
		(yyval.pnode)->child = (yyval.pnode)->LastChild = (yyvsp[(1) - (1)].pnode);
	;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 550 "psycon.y"
    {
		(yyvsp[(1) - (2)].pnode)->LastChild = (yyvsp[(1) - (2)].pnode)->LastChild->next = (yyvsp[(2) - (2)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (2)].pnode);
	;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 555 "psycon.y"
    {
		(yyvsp[(1) - (3)].pnode)->LastChild = (yyvsp[(1) - (3)].pnode)->LastChild->next = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode) = (yyvsp[(1) - (3)].pnode);
	;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 562 "psycon.y"
    {
		(yyval.pnode) = makeFunctionCall(":", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));
	;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 566 "psycon.y"
    {
		(yyval.pnode) = makeFunctionCall(":", (yyvsp[(1) - (5)].pnode), (yyvsp[(5) - (5)].pnode), (yyloc));
		(yyval.pnode)->LastChild = (yyvsp[(5) - (5)].pnode)->next = (yyvsp[(3) - (5)].pnode);
	;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 573 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 575 "psycon.y"
    { (yyval.pnode) = (yyvsp[(1) - (1)].pnode);;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 579 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 585 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 591 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('+', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 597 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('-', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 603 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('*', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 609 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('/', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 615 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNodeFunctionCall('^', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 621 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = makeCompoundOpNode('@', (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(3) - (3)]), (yylsp[(1) - (3)]));
	;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 627 "psycon.y"
    { /* Reverse engineered from the tree generated in x = x @ x @ (value) */
	  /* Should be decluttered up by someone else..... 7/20/2016 bjk*/
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str); 
		(yyval.pnode)->child = makeCompoundLevelOpNode((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].pnode), (yylsp[(1) - (3)]), (yylsp[(3) - (3)]));
	;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 634 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(6) - (6)].pnode)->next = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 641 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (8)].str);
		(yyval.pnode)->child = (yyvsp[(8) - (8)].pnode);
		(yyvsp[(8) - (8)].pnode)->next = (yyvsp[(3) - (8)].pnode);
		(yyvsp[(3) - (8)].pnode)->next = (yyvsp[(5) - (8)].pnode);
	;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 649 "psycon.y"
    {
		(yyval.pnode) = Restring("+=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 653 "psycon.y"
    {
		(yyval.pnode) = Restring("-=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 657 "psycon.y"
    {
		(yyval.pnode) = Restring("*=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 661 "psycon.y"
    {
		(yyval.pnode) = Restring("/=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 665 "psycon.y"
    {
		(yyval.pnode) = Restring("@=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 669 "psycon.y"
    {
		(yyval.pnode) = Restring("@@=", (yyvsp[(1) - (8)].str), (yyvsp[(3) - (8)].pnode), (yyvsp[(5) - (8)].pnode), (yyvsp[(8) - (8)].pnode), (yyloc));
	;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 673 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(6) - (6)].pnode)->next = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 680 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(9) - (9)].pnode);
		(yyvsp[(9) - (9)].pnode)->next = (yyvsp[(6) - (9)].pnode);
		(yyvsp[(6) - (9)].pnode)->next = (yyvsp[(3) - (9)].pnode);
	;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 688 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (3)].pnode);
	;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 694 "psycon.y"
    {
		(yyval.pnode) = newAstNode('=', (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(6) - (6)].pnode)->next = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 701 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child = (yyvsp[(6) - (6)].pnode);
		(yyvsp[(6) - (6)].pnode)->next = (yyvsp[(3) - (6)].pnode);
	;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 708 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_IXASSIGN, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (9)].str);
		(yyval.pnode)->child = (yyvsp[(9) - (9)].pnode);
		(yyvsp[(9) - (9)].pnode)->next = (yyvsp[(6) - (9)].pnode);
		(yyvsp[(6) - (9)].pnode)->next = (yyvsp[(3) - (9)].pnode);
	;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 716 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (3)].pnode);
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 723 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(5) - (8)].str);
		(yyval.pnode)->child = (yyvsp[(7) - (8)].pnode);
		(yyvsp[(7) - (8)].pnode)->next = newAstNode(NODE_INITCELL, (yylsp[(1) - (8)]));
		(yyvsp[(7) - (8)].pnode)->next->str = (yyvsp[(1) - (8)].str);
	;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 731 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(5) - (8)].str);
		(yyval.pnode)->child = (yyvsp[(7) - (8)].pnode);
		(yyvsp[(7) - (8)].pnode)->next = (yyvsp[(2) - (8)].pnode);
	;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 740 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_NUMBER, (yyloc));
		(yyval.pnode)->dval = (yyvsp[(1) - (1)].dval);
	;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 745 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_STRING, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 750 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_DUR, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 755 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_LENGTH, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 760 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 765 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (4)].pnode);
	;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 771 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_ID, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (7)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (7)].pnode);
		(yyvsp[(3) - (7)].pnode)->next = (yyvsp[(6) - (7)].pnode);
	;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 778 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INITCELL, (yyloc));
		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 783 "psycon.y"
    { // I don't know what this is doing.... bjk 3/28/2017 
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = (yyvsp[(1) - (3)].str);
	;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 788 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->type = NODE_CALL;
 		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 796 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = (yyvsp[(1) - (4)].str);
		(yyval.pnode)->child = (yyvsp[(3) - (4)].pnode);
		(yyval.pnode)->LastChild = (yyvsp[(3) - (4)].pnode); // leaving a mark for conditional indexing 3/28/2017 bjk
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 805 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_CALL, (yyloc));
 		(yyval.pnode)->str = malloc(strlen((yyvsp[(2) - (4)].str))+2);
 		(yyval.pnode)->str[0] = '#';
 		strcpy((yyval.pnode)->str+1, (yyvsp[(2) - (4)].str));
 		free((yyvsp[(2) - (4)].str));
	;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 813 "psycon.y"
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

  case 134:

/* Line 1455 of yacc.c  */
#line 824 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_EXTRACT, (yyloc));
		(yyval.pnode)->child = newAstNode(T_ID, (yylsp[(1) - (6)]));
		(yyval.pnode)->child->str = (yyvsp[(1) - (6)].str);
		(yyval.pnode)->child->next = (yyvsp[(3) - (6)].pnode);
		(yyvsp[(3) - (6)].pnode)->next = (yyvsp[(5) - (6)].pnode);
	;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 832 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_NEGATIVE, (yyloc));
		(yyval.pnode)->child = (yyvsp[(2) - (2)].pnode);
	;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 837 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (2)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 843 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 849 "psycon.y"
    {
		(yyval.pnode) = newAstNode(T_SIGMA, (yyloc));
		(yyval.pnode)->child = newAstNode('=', (yylsp[(3) - (8)]));
		(yyval.pnode)->child->str = (yyvsp[(3) - (8)].str);
		(yyval.pnode)->child->child = (yyvsp[(5) - (8)].pnode);
		(yyval.pnode)->child->next = (yyvsp[(7) - (8)].pnode);
	;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 857 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('+', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 859 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('-', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 861 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('*', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 863 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('/', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 865 "psycon.y"
    { (yyval.pnode) = makeFunctionCall("^", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 867 "psycon.y"
    { (yyval.pnode) = makeFunctionCall("caret", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 869 "psycon.y"
    { (yyval.pnode) = makeFunctionCall("shift_spectrum", (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 871 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode('@', (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 873 "psycon.y"
    {
		(yyval.pnode) = newAstNode(NODE_INTERPOL, (yyloc));
		(yyval.pnode)->child = (yyvsp[(1) - (5)].pnode);
		(yyvsp[(1) - (5)].pnode)->next = (yyvsp[(3) - (5)].pnode);
		(yyvsp[(3) - (5)].pnode)->next = (yyvsp[(5) - (5)].pnode);
		(yyval.pnode)->LastChild = (yyvsp[(5) - (5)].pnode);
	;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 881 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_SHIFT, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 883 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_SHIFT2, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 885 "psycon.y"
    { (yyval.pnode) = makeBinaryOpNode(T_OP_CONCAT, (yyvsp[(1) - (3)].pnode), (yyvsp[(3) - (3)].pnode), (yyloc));;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 887 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 893 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 901 "psycon.y"
    {
		(yyval.pnode) = (yyvsp[(2) - (3)].pnode);
		(yyval.pnode)->type = NODE_INITCELL;
		(yyval.pnode)->line = (yyloc).first_line;
		(yyval.pnode)->column = (yyloc).first_column;
	;}
    break;



/* Line 1455 of yacc.c  */
#line 3990 "psycon.tab.c"
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
#line 909 "psycon.y"


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

