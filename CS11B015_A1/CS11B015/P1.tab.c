/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "P1.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pNode{
    char* s;
    struct pNode* next;
};

struct pFrag{
    struct pNode* head;
    struct pNode* tail;
};

struct mNode{
	
	char* macro;
	int no_of_args;
	struct pFrag exp;
	char *args[5];
};

typedef struct mNode macroNode;
typedef struct pNode progNode;
typedef struct pFrag progFrag;
macroNode* macros;

int no_of_macros=0;
int i;
int j;
int k;

void AddMacro( macroNode*, macroNode*, int );


/* Line 268 of yacc.c  */
#line 108 "P1.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MACRO_DEF = 258,
     ID = 259,
     BRACE_OPEN = 260,
     BRACE_CLOSE = 261,
     PARA_OPEN = 262,
     PARA_CLOSE = 263,
     STATIC = 264,
     SQ_OPEN = 265,
     SQ_CLOSE = 266,
     INT = 267,
     TRUE = 268,
     FALSE = 269,
     THIS = 270,
     NEW = 271,
     INT_DECL = 272,
     DOT = 273,
     VOID = 274,
     NOT = 275,
     AND = 276,
     LT = 277,
     WHILE = 278,
     IF = 279,
     ELSE = 280,
     BOOL_DECL = 281,
     CLASS_DECL = 282,
     LEN = 283,
     MAIN = 284,
     EQ = 285,
     SEMICOLON = 286,
     EF = 287,
     COMMA = 288,
     EXT = 289,
     PUB = 290,
     RET = 291,
     MAIN_KEY = 292,
     ADD = 293,
     SUB = 294,
     MUL = 295,
     DIV = 296,
     MOD = 297,
     PRINT = 298,
     STRING_DECL = 299
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 37 "P1.y"

	struct pFrag* frag;
	char* str;



/* Line 293 of yacc.c  */
#line 195 "P1.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 207 "P1.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   205

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  177

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    26,    27,    30,    34,    35,    38,
      39,    43,    44,    49,    54,    55,    59,    60,    65,    66,
      69,    70,    84,    87,    88,    91,    92,    99,   108,   112,
     114,   116,   118,   120,   122,   126,   132,   137,   145,   147,
     153,   157,   160,   168,   176,   182,   184,   186,   190,   194,
     198,   202,   206,   210,   215,   219,   226,   231,   233,   235,
     239,   241,   243,   245,   251,   256,   259,   261,   263,   272,
     274,   277,   278
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    57,    47,    58,    -1,    27,     4,     5,
      29,     7,    44,    10,    11,     4,     8,     5,    43,     7,
      65,     8,    31,     6,     6,    -1,    -1,     4,    49,    -1,
      49,    33,     4,    -1,    -1,    65,    51,    -1,    -1,    51,
      33,    65,    -1,    -1,    52,    60,     4,    31,    -1,    52,
       4,     4,    31,    -1,    -1,    60,     4,    54,    -1,    -1,
      54,    33,    60,     4,    -1,    -1,    55,    56,    -1,    -1,
      35,    60,     4,     7,    53,     8,     5,    52,    70,    36,
      65,    31,     6,    -1,    68,    57,    -1,    -1,    58,    59,
      -1,    -1,    27,     4,     5,    52,    55,     6,    -1,    27,
       4,    34,     4,     5,    52,    55,     6,    -1,    17,    10,
      11,    -1,    26,    -1,    17,    -1,     4,    -1,    62,    -1,
      64,    -1,     5,    70,     6,    -1,    43,     7,    65,     8,
      31,    -1,     4,    30,    65,    31,    -1,     4,    10,    65,
      11,    30,    65,    31,    -1,    63,    -1,    23,     7,    65,
       8,    61,    -1,     4,    50,    31,    -1,    43,     7,    -1,
      24,     7,    65,     8,    62,    25,    62,    -1,    24,     7,
      65,     8,    62,    25,    64,    -1,    24,     7,    65,     8,
      61,    -1,    66,    -1,    67,    -1,    67,    38,    67,    -1,
      67,    39,    67,    -1,    67,    40,    67,    -1,    67,    41,
      67,    -1,    67,    21,    67,    -1,    67,    22,    67,    -1,
      67,    10,    67,    11,    -1,    67,    18,    28,    -1,    67,
      18,     4,     7,    50,     8,    -1,     4,     7,    50,     8,
      -1,    12,    -1,     4,    -1,     7,    65,     8,    -1,    13,
      -1,    14,    -1,    15,    -1,    16,    17,    10,    65,    11,
      -1,    16,     4,     7,     8,    -1,    20,    65,    -1,    71,
      -1,    69,    -1,     3,     4,     7,    48,     8,     5,    70,
       6,    -1,    61,    -1,    70,    61,    -1,    -1,     3,     4,
       7,    48,     8,     7,    65,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    82,   114,   123,   135,   147,   157,   165,
     175,   186,   196,   210,   227,   237,   250,   260,   275,   285,
     293,   303,   337,   350,   360,   368,   378,   398,   426,   441,
     449,   457,   466,   467,   469,   485,   503,   519,   542,   543,
     561,   562,   575,   600,   621,   639,   642,   646,   657,   668,
     679,   690,   701,   712,   726,   739,   758,   774,   782,   791,
     803,   812,   821,   830,   848,   866,   876,   877,   879,   902,
     903,   918,   927
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MACRO_DEF", "ID", "BRACE_OPEN",
  "BRACE_CLOSE", "PARA_OPEN", "PARA_CLOSE", "STATIC", "SQ_OPEN",
  "SQ_CLOSE", "INT", "TRUE", "FALSE", "THIS", "NEW", "INT_DECL", "DOT",
  "VOID", "NOT", "AND", "LT", "WHILE", "IF", "ELSE", "BOOL_DECL",
  "CLASS_DECL", "LEN", "MAIN", "EQ", "SEMICOLON", "EF", "COMMA", "EXT",
  "PUB", "RET", "MAIN_KEY", "ADD", "SUB", "MUL", "DIV", "MOD", "PRINT",
  "STRING_DECL", "$accept", "Goal", "mainClass", "args", "idList",
  "exprList", "exprList1", "declList", "funcArgs", "typeIDList",
  "methodDeclList", "methodDecl", "macroDefnList", "typeDeclList",
  "typeDecl", "Type", "Stmt", "Stmt1", "matchedIf", "unmatchedIf", "Expr",
  "Expression", "primaryExpr", "macroDefn", "macroDefStmt", "stmtList",
  "macroDefExpr", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    48,    48,    49,    49,    50,    50,
      51,    51,    52,    52,    52,    53,    53,    54,    54,    55,
      55,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    60,    61,    61,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    68,    68,    69,    70,
      70,    70,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,    18,     0,     2,     3,     0,     2,     0,
       3,     0,     4,     4,     0,     3,     0,     4,     0,     2,
       0,    13,     2,     0,     2,     0,     6,     8,     3,     1,
       1,     1,     1,     1,     3,     5,     4,     7,     1,     5,
       3,     2,     7,     7,     5,     1,     1,     3,     3,     3,
       3,     3,     3,     4,     3,     6,     4,     1,     1,     3,
       1,     1,     1,     5,     4,     2,     1,     1,     8,     1,
       2,     0,     8
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      23,     0,     0,     0,    23,    67,    66,     0,     1,     0,
      25,    22,     4,     0,     2,     7,     0,     0,     0,    24,
       5,     0,     0,     0,     0,    71,     0,     0,    14,     0,
       6,     9,    71,     0,     0,     0,    69,    32,    38,    33,
       0,    58,     0,    57,    60,    61,    62,     0,     0,     0,
      45,    46,     0,    20,     0,     0,     0,     0,    11,     0,
       0,     0,    41,    68,    70,     9,     0,     0,     0,    65,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,    29,     0,     0,    14,     0,     0,    40,     8,
      34,     0,     0,     0,     0,    59,     0,     0,    58,     0,
       0,    54,    51,    52,    47,    48,    49,    50,     0,     0,
       0,    26,     0,    19,     0,    20,     0,    36,     0,     0,
       0,     0,    56,    64,     0,    53,     9,     0,    13,    28,
      31,     0,    12,     0,     0,    10,    39,    44,    32,    35,
      63,     0,     0,     0,    27,     0,     0,    55,     0,    16,
      37,    42,    43,     0,     0,     0,     0,     0,    18,     0,
      14,    15,     0,    71,     0,     0,     9,     0,     0,     0,
      58,     0,    17,     3,     0,     0,    21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    16,    20,    57,    89,    53,   154,   161,
      83,   113,     3,    14,    19,    84,    36,    37,    38,    39,
      58,    50,    51,     4,     5,    40,     6
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -108
static const yytype_int16 yypact[] =
{
      20,    23,    46,    25,    20,  -108,  -108,    49,  -108,    54,
    -108,  -108,    57,    45,    26,  -108,    55,    35,    64,  -108,
      37,    13,    62,     3,    71,    50,   143,    39,  -108,    76,
    -108,   105,    50,    78,    84,    87,  -108,  -108,  -108,  -108,
       8,    88,   143,  -108,  -108,  -108,  -108,     7,   143,    89,
    -108,    66,    86,    73,    93,   143,   143,    69,  -108,    43,
     143,   143,   143,  -108,  -108,   143,    95,    94,   100,  -108,
    -108,   157,     5,   157,   157,   157,   157,   157,   157,   102,
     110,   106,  -108,     4,   118,  -108,   112,    96,  -108,    91,
    -108,   125,   133,   134,   135,  -108,   138,   143,  -108,   115,
     141,  -108,  -108,  -108,  -108,  -108,  -108,  -108,   145,   120,
     142,  -108,    85,  -108,   121,    73,   130,  -108,   143,    50,
      50,   131,  -108,  -108,   154,  -108,   143,   158,  -108,  -108,
    -108,   163,  -108,     9,   143,  -108,  -108,  -108,   149,  -108,
    -108,   160,   170,   169,  -108,   148,    50,  -108,   144,    85,
    -108,  -108,  -108,   179,   180,   185,   143,   186,  -108,   182,
    -108,   159,   162,     2,    85,   188,   124,    36,   191,   190,
      31,   143,  -108,  -108,   166,   192,  -108
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,  -108,  -108,  -108,   -61,  -108,   -82,  -108,  -108,
      90,  -108,   195,  -108,  -108,  -107,   -38,  -103,  -108,    56,
     -26,  -108,   107,  -108,  -108,   -31,  -108
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      49,    59,    64,   115,    94,   131,   166,    32,    28,   100,
     111,    67,    31,    32,    63,   144,    66,   138,    25,    81,
      26,    64,    69,     1,    68,    33,    34,     7,    82,    86,
      87,    33,    34,   101,    91,    92,    93,    29,    65,   112,
      31,    32,   155,   151,   112,    35,     8,    31,    32,    90,
      17,    35,     9,    18,    31,    32,    12,   168,    13,    33,
      34,    15,   128,    21,    22,   141,    33,    34,    23,    27,
      24,   124,   171,    33,    34,    30,    71,    80,   163,    35,
      54,   136,   137,    52,    72,    60,    35,    73,    74,   130,
      81,    61,   135,    35,    62,    65,    79,    70,    85,    82,
      88,    96,    81,    95,    75,    76,    77,    78,   145,    41,
      97,    82,    42,   108,   109,    55,   110,    43,    44,    45,
      46,    47,   114,   116,   118,    48,   125,   117,   170,    64,
     159,    42,   167,   119,    55,    56,    43,    44,    45,    46,
      47,   120,   121,   122,    48,   174,   123,    41,   126,   127,
      42,   128,   132,   129,    56,    43,    44,    45,    46,    47,
     134,    98,   139,    48,    42,   140,   142,   143,   147,    43,
      44,    45,    46,    47,   146,   148,   149,    48,    99,   150,
     102,   103,   104,   105,   106,   107,   156,   153,   157,   158,
     162,   160,   164,   165,   169,   172,   173,   175,   176,    11,
       0,     0,   152,     0,     0,   133
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-108))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      26,    32,    40,    85,    65,   112,     4,     5,     5,     4,
       6,     4,     4,     5,     6,     6,    42,   120,     5,    17,
       7,    59,    48,     3,    17,    23,    24,     4,    26,    55,
      56,    23,    24,    28,    60,    61,    62,    34,     7,    35,
       4,     5,   149,   146,    35,    43,     0,     4,     5,     6,
       5,    43,    27,    27,     4,     5,     7,   164,     4,    23,
      24,     4,    31,     8,    29,   126,    23,    24,     4,     7,
      33,    97,    36,    23,    24,     4,    10,     4,   160,    43,
       4,   119,   120,    44,    18,     7,    43,    21,    22,     4,
      17,     7,   118,    43,     7,     7,    10,     8,     5,    26,
      31,     7,    17,     8,    38,    39,    40,    41,   134,     4,
      10,    26,     7,    11,     4,    10,    10,    12,    13,    14,
      15,    16,     4,    11,    33,    20,    11,    31,     4,   167,
     156,     7,   163,     8,    10,    30,    12,    13,    14,    15,
      16,     8,     8,     8,    20,   171,     8,     4,     7,     4,
       7,    31,    31,    11,    30,    12,    13,    14,    15,    16,
      30,     4,    31,    20,     7,    11,     8,     4,     8,    12,
      13,    14,    15,    16,    25,     5,     7,    20,    71,    31,
      73,    74,    75,    76,    77,    78,     7,    43,     8,     4,
       8,     5,    33,    31,     6,     4,     6,    31,     6,     4,
      -1,    -1,   146,    -1,    -1,   115
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    46,    57,    68,    69,    71,     4,     0,    27,
      47,    57,     7,     4,    58,     4,    48,     5,    27,    59,
      49,     8,    29,     4,    33,     5,     7,     7,     5,    34,
       4,     4,     5,    23,    24,    43,    61,    62,    63,    64,
      70,     4,     7,    12,    13,    14,    15,    16,    20,    65,
      66,    67,    44,    52,     4,    10,    30,    50,    65,    70,
       7,     7,     7,     6,    61,     7,    65,     4,    17,    65,
       8,    10,    18,    21,    22,    38,    39,    40,    41,    10,
       4,    17,    26,    55,    60,     5,    65,    65,    31,    51,
       6,    65,    65,    65,    50,     8,     7,    10,     4,    67,
       4,    28,    67,    67,    67,    67,    67,    67,    11,     4,
      10,     6,    35,    56,     4,    52,    11,    31,    33,     8,
       8,     8,     8,     8,    65,    11,     7,     4,    31,    11,
       4,    60,    31,    55,    30,    65,    61,    61,    62,    31,
      11,    50,     8,     4,     6,    65,    25,     8,     5,     7,
      31,    62,    64,    43,    53,    60,     7,     8,     4,    65,
       5,    54,     8,    52,    33,    31,     4,    70,    60,     6,
       4,    36,     4,     6,    65,    31,     6
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
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
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

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
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

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
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 66 "P1.y"
    { 
			
			                                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (3)].frag)->head;
                                                                            (yyvsp[(1) - (3)].frag)->tail->next=(yyvsp[(2) - (3)].frag)->head;
                                                                            (yyvsp[(2) - (3)].frag)->tail->next=(yyvsp[(3) - (3)].frag)->head;
			                                                                (yyvsp[(3) - (3)].frag)->tail->next=NULL;
                                                                            frag->tail=(yyvsp[(3) - (3)].frag)->tail;
                                                                            (yyval.frag)=frag;
			                                                                progNode* tmp1=(yyval.frag)->head;
                                                                            printf("Expression:\n");
                                                                            while(tmp1!=NULL){
                                                                                printf("%s ", tmp1->s);
                                                                                tmp1=tmp1->next;
                                                                            }
                                            }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 82 "P1.y"
    {                                                                  
                                                                            progNode* tmp=(progNode*)malloc(17*sizeof(progNode));
						                                                    tmp[0].s=(yyvsp[(1) - (18)].str); 
                                                                            tmp[1].s=(yyvsp[(2) - (18)].str); 
                                                                            tmp[2].s=(yyvsp[(3) - (18)].str); 
                                                                            tmp[3].s=(yyvsp[(4) - (18)].str); 
                                                                            tmp[4].s=(yyvsp[(5) - (18)].str); 
                                                                            tmp[5].s=(yyvsp[(6) - (18)].str); 
                                                                            tmp[6].s=(yyvsp[(7) - (18)].str); 
                                                                            tmp[7].s=(yyvsp[(8) - (18)].str); 
                                                                            tmp[8].s=(yyvsp[(9) - (18)].str); 
                                                                            tmp[9].s=(yyvsp[(10) - (18)].str); 
                                                                            tmp[10].s=(yyvsp[(11) - (18)].str); 
                                                                            tmp[11].s=(yyvsp[(12) - (18)].str); 
                                                                            tmp[12].s=(yyvsp[(13) - (18)].str); 
                                                                            tmp[13].s=(yyvsp[(15) - (18)].str); 
                                                                            tmp[14].s=(yyvsp[(16) - (18)].str); 
                                                                            tmp[15].s=(yyvsp[(17) - (18)].str); 
                                                                            tmp[16].s=(yyvsp[(18) - (18)].str);
						                                                    i=0;
			                                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
						                                                    progNode* space=(progNode*)malloc(17*sizeof(progNode));
                                                    						frag->head=&tmp[0];
                                                    						for(i=0; i<16; i++)
                                                    							tmp[i].next=&tmp[i+1];
                                                    						tmp[12].next=(yyvsp[(14) - (18)].frag)->head;
                                                    						(yyvsp[(14) - (18)].frag)->tail->next=&tmp[13];
                                                    						tmp[16].next=NULL;
                                                    						frag->tail=&tmp[16];
                                                    						(yyval.frag)=frag; 
                                            }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 114 "P1.y"
    { 
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
	                                                                        progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                        	tmp_head->s="";
                                                                        	tmp_head->next=NULL;
                                                                        	tmp->head=tmp_head;
                                                                        	tmp->tail=tmp_head;
                                                                        	(yyval.frag)=tmp;
                                            }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 123 "P1.y"
    { 
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=(yyvsp[(1) - (2)].str);
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=tmp1;
                                                                            tmp1->next=(yyvsp[(2) - (2)].frag)->head;
                                                                            (yyvsp[(2) - (2)].frag)->tail->next=NULL;
                                                                            frag->tail=(yyvsp[(2) - (2)].frag)->tail;
                                                                            (yyval.frag)=frag;
 		                                    }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 135 "P1.y"
    {  
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=(yyvsp[(2) - (3)].str);
                                                                            tmp2->s=(yyvsp[(3) - (3)].str);
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (3)].frag)->head;
                                                                            (yyvsp[(1) - (3)].frag)->tail->next=tmp1;
                                                                            tmp1->next=tmp2;
                                                                            frag->tail= tmp2;
                                                                            (yyval.frag)=frag;
		                                    }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 147 "P1.y"
    {
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            (yyval.frag)=tmp;
                                            }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 157 "P1.y"
    {
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (2)].frag)->head;
                                                                            (yyvsp[(1) - (2)].frag)->tail->next=(yyvsp[(2) - (2)].frag)->head;
                                                                            (yyvsp[(2) - (2)].frag)->tail->next=NULL;
                                                                            frag->tail=(yyvsp[(2) - (2)].frag)->tail;
                                                                            (yyval.frag)=frag;
 		                                    }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 165 "P1.y"
    { 
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            (yyval.frag)=tmp;
                                            }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 175 "P1.y"
    {
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=(yyvsp[(2) - (3)].str);
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (3)].frag)->head;
                                                                            (yyvsp[(1) - (3)].frag)->tail->next=tmp1;
                                                                            tmp1->next=(yyvsp[(3) - (3)].frag)->head;
                                                                            frag->tail= (yyvsp[(3) - (3)].frag)->tail;
                            						                        (yyvsp[(3) - (3)].frag)->tail->next=NULL;
                                                                            (yyval.frag)=frag;
                                    		}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 186 "P1.y"
    {
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            (yyval.frag)=tmp;
                                            }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 196 "P1.y"
    {   
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=(yyvsp[(3) - (4)].str);
                                                                            tmp2->s=(yyvsp[(4) - (4)].str);
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (4)].frag)->head;
                                                                            (yyvsp[(1) - (4)].frag)->tail->next=(yyvsp[(2) - (4)].frag)->head;
                                                                            (yyvsp[(2) - (4)].frag)->tail->next=tmp1;
                                                                            tmp1->next=tmp2;
                                                                            frag->tail= tmp2;
                            						                        tmp2->next=NULL;
                                                                            (yyval.frag) = frag;
		                                    }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 210 "P1.y"
    {
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                                                            progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                            						                        tmp1->s=(yyvsp[(2) - (4)].str);
                                                                            tmp2->s=(yyvsp[(3) - (4)].str);
                            						                        tmp3->s=(yyvsp[(4) - (4)].str);
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (4)].frag)->head;
                                                                            (yyvsp[(1) - (4)].frag)->tail->next=tmp1;
                                                                            tmp1->next=tmp2;
                                                                            tmp2->next=tmp3;
                                                                            frag->tail= tmp3;
                                                                            tmp3->next=NULL;
                                                                            (yyval.frag) = frag;

                                            }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 227 "P1.y"
    { 
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            (yyval.frag)=tmp;
                                            }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 238 "P1.y"
    {
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=(yyvsp[(2) - (3)].str);
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (3)].frag)->head;
                                                                            (yyvsp[(1) - (3)].frag)->tail->next=tmp1;
                                                                            tmp1->next=(yyvsp[(3) - (3)].frag)->head;
                                                                            frag->tail= (yyvsp[(3) - (3)].frag)->tail;
                                                                            (yyvsp[(3) - (3)].frag)->tail->next=NULL;
                                                                            (yyval.frag)=frag;

                                             }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 250 "P1.y"
    {
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            (yyval.frag)=tmp;
                                            }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 261 "P1.y"
    {
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                            						                        progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=(yyvsp[(2) - (4)].str);
                            						                        tmp2->s=(yyvsp[(4) - (4)].str);
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (4)].frag)->head;
                                                                            (yyvsp[(1) - (4)].frag)->tail->next=tmp1;
                                                                            tmp1->next=(yyvsp[(3) - (4)].frag)->head;
                            						                        (yyvsp[(3) - (4)].frag)->tail->next=tmp2;
                                                                            frag->tail= tmp2;
                                                                            tmp2->next=NULL;
                                                                            (yyval.frag)=frag;
                                            }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 275 "P1.y"
    {
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            (yyval.frag)=tmp;
                                            }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 285 "P1.y"
    {   
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (2)].frag)->head;
                                                                            (yyvsp[(1) - (2)].frag)->tail->next=(yyvsp[(2) - (2)].frag)->head;
                                                                            (yyvsp[(2) - (2)].frag)->tail->next=NULL;
                                                                            frag->tail=(yyvsp[(2) - (2)].frag)->tail;
                                                                            (yyval.frag)=frag;
                                            }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 293 "P1.y"
    {
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            (yyval.frag)=tmp;
                                            }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 304 "P1.y"
    {
                                                                        	progNode* tmp= (progNode*)malloc(8*sizeof(progNode));
                                                                        	tmp[0].s=(yyvsp[(1) - (13)].str);
                                                                        	tmp[1].s=(yyvsp[(3) - (13)].str);
                                                                        	tmp[2].s=(yyvsp[(4) - (13)].str);
                                                                        	tmp[3].s=(yyvsp[(6) - (13)].str);
                                                                        	tmp[4].s=(yyvsp[(7) - (13)].str);
                                                                        	tmp[5].s=(yyvsp[(10) - (13)].str);
                                                                        	tmp[6].s=(yyvsp[(12) - (13)].str);
                                                                        	tmp[7].s=(yyvsp[(13) - (13)].str);
                                                                        	progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                        	frag->head=&tmp[0];
                                                                        	tmp[0].next=(yyvsp[(2) - (13)].frag)->head;
                                                                        	printf("#@#@#@$ %d \n",(int) (yyvsp[(2) - (13)].frag)->tail);
                                                                        	(yyvsp[(2) - (13)].frag)->tail->next=&tmp[1];
                                                                        	tmp[1].next=&tmp[2];
                                                                        	tmp[2].next=(yyvsp[(5) - (13)].frag)->head;
                                                                        	(yyvsp[(5) - (13)].frag)->tail->next=&tmp[3];
                                                                        	tmp[3].next=&tmp[4];
                                                                        	tmp[4].next=(yyvsp[(8) - (13)].frag)->head;
                                                                        	(yyvsp[(8) - (13)].frag)->tail->next=(yyvsp[(9) - (13)].frag)->head;
                                                                        	if((yyvsp[(9) - (13)].frag)->tail!=NULL)
                                                                        	(yyvsp[(9) - (13)].frag)->tail->next=&tmp[5];
                                                                        	else
                                                                        	(yyvsp[(8) - (13)].frag)->tail->next=&tmp[5];
                                                                        	tmp[5].next=(yyvsp[(11) - (13)].frag)->head;
                                                                        	(yyvsp[(11) - (13)].frag)->tail->next=&tmp[6];
                                                                        	tmp[6].next=&tmp[7];
                                                                        	tmp[7].next=NULL;
                                                                        	frag->tail=&tmp[7];
                                                                        	(yyval.frag) = frag;
                                            }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 337 "P1.y"
    { 
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                			if((yyvsp[(1) - (2)].frag)!=NULL){
                                                                                frag->head=(yyvsp[(1) - (2)].frag)->head;
                                                                                (yyvsp[(1) - (2)].frag)->tail->next=(yyvsp[(2) - (2)].frag)->head;
                                                                            }
                                                                			else{
                                                                			    frag->head=(yyvsp[(2) - (2)].frag)->head;
                                                                			}
                                                                                (yyvsp[(2) - (2)].frag)->tail->next=NULL;
                                                                                frag->tail=(yyvsp[(2) - (2)].frag)->tail;
                                                                                (yyval.frag)=frag;
                                            }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 350 "P1.y"
    {
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            (yyval.frag)=tmp;
                                            }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 360 "P1.y"
    {  
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (2)].frag)->head;
                                                                            (yyvsp[(1) - (2)].frag)->tail->next=(yyvsp[(2) - (2)].frag)->head;
                                                                            (yyvsp[(2) - (2)].frag)->tail->next=NULL;
                                                                            frag->tail=(yyvsp[(2) - (2)].frag)->tail;
                                                                            (yyval.frag)=frag;
                                            }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 368 "P1.y"
    {
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=tmp_head;
                                                                            (yyval.frag)=tmp;
                                            }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 378 "P1.y"
    {
			 progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp4= (progNode*)malloc(sizeof(progNode));
				tmp1->s=(yyvsp[(1) - (6)].str);
				tmp2->s=(yyvsp[(2) - (6)].str);
				tmp3->s=(yyvsp[(3) - (6)].str);
				tmp4->s=(yyvsp[(6) - (6)].str);
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
				frag->head=tmp1;
				tmp1->next=tmp2;
				tmp2->next=tmp3;
				tmp3->next= (yyvsp[(4) - (6)].frag)->head;
				(yyvsp[(4) - (6)].frag)->tail->next=(yyvsp[(5) - (6)].frag)->head;
				(yyvsp[(5) - (6)].frag)->tail->next=tmp4;
				tmp4->next=NULL;
				frag->tail=tmp4;
				(yyval.frag)=frag;
}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 398 "P1.y"
    {
			progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp4= (progNode*)malloc(sizeof(progNode));
                                progNode* tmp5= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp6= (progNode*)malloc(sizeof(progNode));
				tmp1->s=(yyvsp[(1) - (8)].str);
                                tmp2->s=(yyvsp[(2) - (8)].str);
                                tmp3->s=(yyvsp[(3) - (8)].str);
                                tmp4->s=(yyvsp[(4) - (8)].str);
				tmp5->s=(yyvsp[(5) - (8)].str);
				tmp6->s=(yyvsp[(8) - (8)].str);
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                frag->head=tmp1;
                                tmp1->next=tmp2;
                                tmp2->next=tmp3;
				tmp3->next=tmp4;
				tmp4->next=tmp5;
                                tmp5->next= (yyvsp[(6) - (8)].frag)->head;
                                (yyvsp[(6) - (8)].frag)->tail->next=(yyvsp[(7) - (8)].frag)->head;
                                (yyvsp[(7) - (8)].frag)->tail->next=tmp6;
                                tmp6->next=NULL;
                                frag->tail=tmp6;
                                (yyval.frag)=frag;
				
}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 426 "P1.y"
    { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
				 progNode* tmp2= (progNode*)malloc(sizeof(progNode)); 
				 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
				tmp1->s=(yyvsp[(1) - (3)].str);
				tmp2->s=(yyvsp[(2) - (3)].str);
				tmp3->s=(yyvsp[(3) - (3)].str);
				progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
				frag->head=tmp1;
				tmp1->next=tmp2;
				tmp2->next=tmp3;
				tmp3->next=NULL;
				frag->tail=tmp3;
				(yyval.frag)=frag;

 }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 441 "P1.y"
    { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
			tmp1->s=(yyvsp[(1) - (1)].str);
			tmp1->next=NULL;
			progFrag* frag=(progFrag*)malloc(sizeof(progNode));
			frag->head=tmp1;
			frag->tail=tmp1;
			(yyval.frag)=frag;
 }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 449 "P1.y"
    { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                        tmp1->s=(yyvsp[(1) - (1)].str);
                        tmp1->next=NULL;
                        progFrag* frag=(progFrag*)malloc(sizeof(progNode));
                        frag->head=tmp1;
                        frag->tail=tmp1;
                        (yyval.frag)=frag;
 }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 457 "P1.y"
    { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                        tmp1->s=(yyvsp[(1) - (1)].str);
                        tmp1->next=NULL;
                        progFrag* frag=(progFrag*)malloc(sizeof(progNode));
                        frag->head=tmp1;
                        frag->tail=tmp1;
                        (yyval.frag)=frag;
}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 466 "P1.y"
    { (yyval.frag)=(yyvsp[(1) - (1)].frag); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 467 "P1.y"
    {(yyval.frag)=(yyvsp[(1) - (1)].frag);}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 469 "P1.y"
    { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
				tmp1->s=(yyvsp[(1) - (3)].str);
				tmp2->s=(yyvsp[(3) - (3)].str);
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
				frag->head=tmp1;
				tmp1->next=(yyvsp[(2) - (3)].frag)->head;
				if((yyvsp[(2) - (3)].frag)->tail!=NULL)
				(yyvsp[(2) - (3)].frag)->tail->next=tmp2;
				else
				tmp1->next=tmp2;
				tmp2->next=NULL;
				frag->tail=tmp2;
				(yyval.frag)=frag;

 }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 485 "P1.y"
    { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp4= (progNode*)malloc(sizeof(progNode));
                                tmp1->s=(yyvsp[(1) - (5)].str);
                                tmp2->s=(yyvsp[(2) - (5)].str);
				tmp3->s=(yyvsp[(4) - (5)].str);
				tmp4->s=(yyvsp[(5) - (5)].str);
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                frag->head=tmp1;
				tmp1->next=tmp2;
                                tmp2->next=(yyvsp[(3) - (5)].frag)->head;
                                (yyvsp[(3) - (5)].frag)->tail->next=tmp3;
				tmp3->next=tmp4;
                                tmp4->next=NULL;
                                frag->tail=tmp2;
                                (yyval.frag)=frag;
 }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 503 "P1.y"
    { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                tmp1->s=(yyvsp[(1) - (4)].str);
                                tmp2->s=(yyvsp[(2) - (4)].str);
				tmp3->s=(yyvsp[(4) - (4)].str);
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                frag->head=tmp1;
				tmp1->next=tmp2;
                                tmp2->next=(yyvsp[(3) - (4)].frag)->head;
                                (yyvsp[(3) - (4)].frag)->tail->next=tmp3;
                                tmp3->next=NULL;
                                frag->tail=tmp3;
                                (yyval.frag)=frag;

 }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 519 "P1.y"
    {progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
				 progNode* tmp4= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp5= (progNode*)malloc(sizeof(progNode));
                                tmp1->s=(yyvsp[(1) - (7)].str);
                                tmp2->s=(yyvsp[(2) - (7)].str);
                                tmp3->s=(yyvsp[(4) - (7)].str);
				tmp4->s=(yyvsp[(5) - (7)].str);
				tmp5->s=(yyvsp[(7) - (7)].str);
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                frag->head=tmp1;
                                tmp1->next=tmp2;
                                tmp2->next=(yyvsp[(3) - (7)].frag)->head;
                                (yyvsp[(3) - (7)].frag)->tail->next=tmp3;
				tmp3->next=tmp4;
                                tmp4->next=(yyvsp[(6) - (7)].frag)->head;
                                (yyvsp[(6) - (7)].frag)->tail->next=tmp5;
				tmp5->next=NULL;
                                frag->tail=tmp5;
                                (yyval.frag)=frag;

 }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 542 "P1.y"
    { (yyval.frag)=(yyvsp[(1) - (1)].frag); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 543 "P1.y"
    {progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                tmp1->s=(yyvsp[(1) - (5)].str);
                                tmp2->s=(yyvsp[(2) - (5)].str);
                                tmp3->s=(yyvsp[(4) - (5)].str);
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                frag->head=tmp1;
                                tmp1->next=tmp2;
                                tmp2->next=(yyvsp[(3) - (5)].frag)->head;
                                (yyvsp[(3) - (5)].frag)->tail->next=tmp3;
                                tmp3->next=(yyvsp[(5) - (5)].frag)->head;
                                (yyvsp[(5) - (5)].frag)->tail->next=NULL;
                                frag->tail=(yyvsp[(5) - (5)].frag)->tail;
                                (yyval.frag)=frag;
				

 }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 561 "P1.y"
    {}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 562 "P1.y"
    { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
				tmp1->s=(yyvsp[(1) - (2)].str);	
				tmp2->s=(yyvsp[(2) - (2)].str);
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
				frag->head=tmp1;
				tmp1->next=tmp2;
				tmp2->next=NULL;
				frag->tail=tmp2;
				(yyval.frag)= frag;
				
 }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 575 "P1.y"
    { progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp4= (progNode*)malloc(sizeof(progNode));
                                tmp1->s=(yyvsp[(1) - (7)].str);
                                tmp2->s=(yyvsp[(2) - (7)].str);
                                tmp3->s=(yyvsp[(4) - (7)].str);
                                tmp4->s=(yyvsp[(6) - (7)].str);
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                frag->head=tmp1;
                                tmp1->next=tmp2;
                                tmp2->next=(yyvsp[(3) - (7)].frag)->head;
                                (yyvsp[(3) - (7)].frag)->tail->next=tmp3;
                                tmp3->next=(yyvsp[(5) - (7)].frag)->head;
				if((yyvsp[(5) - (7)].frag)->tail!=NULL)
				(yyvsp[(5) - (7)].frag)->tail->next=tmp4;
				else
				tmp3->next=tmp4;
                                tmp4->next=(yyvsp[(7) - (7)].frag)->head;
				(yyvsp[(7) - (7)].frag)->tail=NULL;
				frag->tail=(yyvsp[(7) - (7)].frag)->tail;
                                (yyval.frag)=frag;

 }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 600 "P1.y"
    {progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp4= (progNode*)malloc(sizeof(progNode));
                                tmp1->s=(yyvsp[(1) - (7)].str);
                                tmp2->s=(yyvsp[(2) - (7)].str);
                                tmp3->s=(yyvsp[(4) - (7)].str);
                                tmp4->s=(yyvsp[(6) - (7)].str);
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                frag->head=tmp1;
                                tmp1->next=tmp2;
                                tmp2->next=(yyvsp[(3) - (7)].frag)->head;
                                (yyvsp[(3) - (7)].frag)->tail->next=tmp3;
                                tmp3->next=(yyvsp[(5) - (7)].frag)->head;
                                (yyvsp[(5) - (7)].frag)->tail->next=tmp4;
                                tmp4->next=(yyvsp[(7) - (7)].frag)->head;
                                (yyvsp[(7) - (7)].frag)->tail=NULL;
                                frag->tail=(yyvsp[(7) - (7)].frag)->tail;
                                (yyval.frag)=frag;

 }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 621 "P1.y"
    {progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                tmp1->s=(yyvsp[(1) - (5)].str);
                                tmp2->s=(yyvsp[(2) - (5)].str);
                                tmp3->s=(yyvsp[(4) - (5)].str);
                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                frag->head=tmp1;
                                tmp1->next=tmp2;
                                tmp2->next=(yyvsp[(3) - (5)].frag)->head;
                                (yyvsp[(3) - (5)].frag)->tail->next=tmp3;
                                tmp3->next=(yyvsp[(5) - (5)].frag)->head;
				(yyvsp[(5) - (5)].frag)->tail->next=NULL;
                                frag->tail=(yyvsp[(5) - (5)].frag)->tail;
                                (yyval.frag)=frag;

 }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 639 "P1.y"
    {
			(yyval.frag)= (yyvsp[(1) - (1)].frag);
		}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 642 "P1.y"
    { 
			(yyval.frag)= (yyvsp[(1) - (1)].frag);
			}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 646 "P1.y"
    { 	progNode* tmp= (progNode*)malloc(sizeof(progNode));
						tmp->s=(yyvsp[(2) - (3)].str);
						progFrag* frag=(progFrag*)malloc(sizeof(progFrag));

						frag->head=(yyvsp[(1) - (3)].frag)->head;
						(yyvsp[(1) - (3)].frag)->tail->next=tmp;
						tmp->next=(yyvsp[(3) - (3)].frag)->head;
						frag->tail= (yyvsp[(3) - (3)].frag)->tail;
						(yyval.frag)=frag;

						}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 657 "P1.y"
    {         progNode* tmp= (progNode*)malloc(sizeof(progNode));
                                                tmp->s=(yyvsp[(2) - (3)].str);
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=(yyvsp[(1) - (3)].frag)->head;
                                                (yyvsp[(1) - (3)].frag)->tail->next=tmp;
                                                tmp->next=(yyvsp[(3) - (3)].frag)->head;
                                                frag->tail= (yyvsp[(3) - (3)].frag)->tail;
						(yyval.frag)=frag;

                                                }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 668 "P1.y"
    {       progNode* tmp= (progNode*)malloc(sizeof(progNode));
                                                tmp->s=(yyvsp[(2) - (3)].str);
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=(yyvsp[(1) - (3)].frag)->head;
                                                (yyvsp[(1) - (3)].frag)->tail->next=tmp;
                                                tmp->next=(yyvsp[(3) - (3)].frag)->head;
                                                frag->tail= (yyvsp[(3) - (3)].frag)->tail;
						(yyval.frag)=frag;
		                                
                }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 679 "P1.y"
    {       progNode* tmp= (progNode*)malloc(sizeof(progNode));
                                                tmp->s=(yyvsp[(2) - (3)].str);
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=(yyvsp[(1) - (3)].frag)->head;
                                                (yyvsp[(1) - (3)].frag)->tail->next=tmp;
                                                tmp->next=(yyvsp[(3) - (3)].frag)->head;
                                                frag->tail= (yyvsp[(3) - (3)].frag)->tail;
						(yyval.frag)=frag;
        
			                }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 690 "P1.y"
    {       progNode* tmp= (progNode*)malloc(sizeof(progNode));
                                                tmp->s=(yyvsp[(2) - (3)].str);
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=(yyvsp[(1) - (3)].frag)->head;
                                                (yyvsp[(1) - (3)].frag)->tail->next=tmp;
                                                tmp->next=(yyvsp[(3) - (3)].frag)->head;
                                                frag->tail= (yyvsp[(3) - (3)].frag)->tail;
						(yyval.frag)=frag;
	        
	                                }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 701 "P1.y"
    {       progNode* tmp= (progNode*)malloc(sizeof(progNode));
                                                tmp->s=(yyvsp[(2) - (3)].str);
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=(yyvsp[(1) - (3)].frag)->head;
                                                (yyvsp[(1) - (3)].frag)->tail->next=tmp;
                                                tmp->next=(yyvsp[(3) - (3)].frag)->head;
                                                frag->tail= (yyvsp[(3) - (3)].frag)->tail;
						(yyval.frag)=frag;
                
	                        }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 712 "P1.y"
    {      progNode* tmp1= (progNode*)malloc(sizeof(progNode));
						 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                                tmp1->s=(yyvsp[(2) - (4)].str);
						tmp2->s=(yyvsp[(4) - (4)].str);
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=(yyvsp[(1) - (4)].frag)->head;
                                                (yyvsp[(1) - (4)].frag)->tail->next=tmp1;
                                                tmp1->next=(yyvsp[(3) - (4)].frag)->head;
						(yyvsp[(3) - (4)].frag)->tail=tmp2;
                                                frag->tail= tmp2;
						(yyval.frag)=frag;

                                                }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 726 "P1.y"
    {			progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                        	progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                                tmp1->s=(yyvsp[(2) - (3)].str);
						tmp2->s=(yyvsp[(3) - (3)].str);
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=(yyvsp[(1) - (3)].frag)->head;
                                                (yyvsp[(1) - (3)].frag)->tail->next=tmp1;
                                                tmp1->next=tmp2;
                                                frag->tail= tmp2;
						(yyval.frag)=frag;

                                               }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 739 "P1.y"
    {      progNode* tmp1= (progNode*)malloc(sizeof(progNode));
						 progNode* tmp2= (progNode*)malloc(sizeof(progNode));
						 progNode* tmp3= (progNode*)malloc(sizeof(progNode));
						 progNode* tmp4= (progNode*)malloc(sizeof(progNode));
                                                tmp1->s=(yyvsp[(2) - (6)].str);
						tmp2->s=(yyvsp[(3) - (6)].str);
						tmp3->s=(yyvsp[(4) - (6)].str);
						tmp4->s=(yyvsp[(6) - (6)].str);
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=(yyvsp[(1) - (6)].frag)->head;
                                                (yyvsp[(1) - (6)].frag)->tail->next=tmp1;
                                                tmp1->next=tmp2;
						tmp2->next=tmp3;
						tmp3->next=(yyvsp[(5) - (6)].frag)->head;
						(yyvsp[(5) - (6)].frag)->tail->next=tmp4;
                                                frag->tail= tmp4;
						(yyval.frag) = frag;
                                                }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 758 "P1.y"
    {    progNode* tmp1= (progNode*)malloc(sizeof(progNode));
						progNode* tmp2= (progNode*)malloc(sizeof(progNode));
						progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                                                tmp1->s=(yyvsp[(1) - (4)].str);
						tmp2->s=(yyvsp[(2) - (4)].str);	
						tmp3->s=(yyvsp[(4) - (4)].str);
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=tmp1;
                                                tmp1->next=tmp2;
                                                tmp2->next=(yyvsp[(3) - (4)].frag)->head;
						(yyvsp[(3) - (4)].frag)->tail->next=tmp3;
                                                frag->tail= tmp3;
						(yyval.frag) = frag;
					    }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 774 "P1.y"
    {	progNode* tmp1= (progNode*)malloc(sizeof(progNode));
			tmp1->s=(yyvsp[(1) - (1)].str);
			progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
			frag->head=tmp1;
			frag->tail=tmp1;
			tmp1->next=NULL;
			(yyval.frag)=frag;
			}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 782 "P1.y"
    {      progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                        tmp1->s=(yyvsp[(1) - (1)].str);
                        progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                        frag->head=tmp1;
                        frag->tail=tmp1;
                        tmp1->next=NULL;
                        (yyval.frag)=frag;
                      }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 791 "P1.y"
    {  progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                                                tmp1->s=(yyvsp[(1) - (3)].str);
                                                tmp2->s=(yyvsp[(3) - (3)].str);
                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                frag->head=tmp1;
                                                tmp1->next=(yyvsp[(2) - (3)].frag)->head;
                                                (yyvsp[(2) - (3)].frag)->tail->next=tmp2;
                                                frag->tail= tmp2;
                                                (yyval.frag) = frag;

		}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 803 "P1.y"
    {     progNode* tmp1= (progNode*)malloc(sizeof(progNode));
   
                        progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                        frag->head=tmp1;
                        frag->tail=tmp1;
                        tmp1->next=NULL;
                        (yyval.frag)=frag;
                       }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 812 "P1.y"
    {     progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                        tmp1->s=(yyvsp[(1) - (1)].str);
                        progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                        frag->head=tmp1;
                        frag->tail=tmp1;
                        tmp1->next=NULL;
                        (yyval.frag)=frag;
                      }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 821 "P1.y"
    {      progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                        tmp1->s=(yyvsp[(1) - (1)].str);
                        progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                        frag->head=tmp1;
                        frag->tail=tmp1;
                        tmp1->next=NULL;
                        (yyval.frag)=frag;
                      }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 830 "P1.y"
    {  progNode* tmp1= (progNode*)malloc(sizeof(progNode));
			progNode* tmp2= (progNode*)malloc(sizeof(progNode));
			progNode* tmp3= (progNode*)malloc(sizeof(progNode));
			progNode* tmp4= (progNode*)malloc(sizeof(progNode));
                        tmp1->s=(yyvsp[(1) - (5)].str);
			tmp2->s=(yyvsp[(2) - (5)].str);
			tmp3->s=(yyvsp[(3) - (5)].str);
			tmp4->s=(yyvsp[(5) - (5)].str);
                        progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                        frag->head=tmp1;
			tmp1->next=tmp2;
			tmp2->next=tmp3;
			tmp3->next=(yyvsp[(4) - (5)].frag)->head;
			(yyvsp[(4) - (5)].frag)->tail->next=tmp4;
                        frag->tail=tmp4;
                        tmp4->next=NULL;
                        (yyval.frag)=frag;
	}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 848 "P1.y"
    {  progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                        progNode* tmp2= (progNode*)malloc(sizeof(progNode));
                        progNode* tmp3= (progNode*)malloc(sizeof(progNode));
                        progNode* tmp4= (progNode*)malloc(sizeof(progNode));
                        tmp1->s=(yyvsp[(1) - (4)].str);
                        tmp2->s=(yyvsp[(2) - (4)].str);
                        tmp3->s=(yyvsp[(3) - (4)].str);
                        tmp4->s=(yyvsp[(4) - (4)].str);
                        progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                        frag->head=tmp1;
                        tmp1->next=tmp2;
                        tmp2->next=tmp3;
                        tmp3->next=tmp4;
                        frag->tail=tmp4;
                        tmp4->next=NULL;
                        (yyval.frag)=frag;

	}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 866 "P1.y"
    {  progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                        tmp1->s=(yyvsp[(1) - (2)].str);
                        progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                        frag->head=tmp1;
                        tmp1->next=(yyvsp[(2) - (2)].frag)->head;
                        (yyvsp[(2) - (2)].frag)->tail->next=NULL;
			frag->tail=(yyvsp[(2) - (2)].frag)->tail;
                        (yyval.frag)=frag;
	}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 876 "P1.y"
    { (yyval.frag)=(yyvsp[(1) - (1)].frag);}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 877 "P1.y"
    { (yyval.frag)=(yyvsp[(1) - (1)].frag);}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 879 "P1.y"
    { 
	no_of_macros++;
    int no_args=0;
	char* body=(yyvsp[(7) - (8)].frag);
	macroNode *m=(macroNode*) malloc(sizeof(macroNode));
	m->macro=(yyvsp[(2) - (8)].str);
	char* args=(yyvsp[(4) - (8)].frag);
	for(i=0; i<strlen(args);i++)
       		 if(args[i]==',')
               		no_args++;
	m->no_of_args=no_args+1;
    j=0;
    k=0;
	 for(i=0; i<strlen(args); i++){
                        m->args[j][k]=args[i];
                        if(args[i]==','){
                                j++;
                                k=0;
                        }
	}
    AddMacro(m, macros, no_of_macros);
}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 902 "P1.y"
    {(yyval.frag)=(yyvsp[(1) - (1)].frag);}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 903 "P1.y"
    {  progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                        frag->head=(yyvsp[(1) - (2)].frag)->head;
			if((yyvsp[(1) - (2)].frag)->tail==NULL)
			(yyvsp[(1) - (2)].frag)->tail=(progNode*)malloc(sizeof(progNode));
                        (yyvsp[(1) - (2)].frag)->tail->next=(yyvsp[(2) - (2)].frag)->head;
			if((yyvsp[(2) - (2)].frag)->tail!=NULL){
                        (yyvsp[(2) - (2)].frag)->tail->next=NULL;
			frag->tail=(yyvsp[(2) - (2)].frag)->tail;
			}
			else{
			(yyvsp[(1) - (2)].frag)->tail->next=NULL;
                        frag->tail=(yyvsp[(1) - (2)].frag)->tail;
			}
                        (yyval.frag)=frag;
 }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 918 "P1.y"
    { progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
         progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
        tmp_head->s="";
        tmp_head->next=NULL;
        tmp->head=tmp_head;
        tmp->tail=tmp_head;
        (yyval.frag)=tmp;
}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 927 "P1.y"
    {
  	no_of_macros++;
 	char* body=(yyvsp[(7) - (8)].frag);
    int no_args;
        macroNode *m=(macroNode*) malloc(sizeof(macroNode));
        m->macro=(yyvsp[(2) - (8)].str);
        char* args=(yyvsp[(4) - (8)].frag);
        for(i=0; i<strlen(args);i++)
                 if(args[i]==',')
                        no_args++;
        m->no_of_args=no_args+1;
         for(i=0; i<strlen(args); i++){
                        m->args[j][k]=args[i];
                        if(args[i]==','){
                                j++;
                                k=0;
                        }
        }
        AddMacro(m, macros, no_of_macros);
 
}
    break;



/* Line 1806 of yacc.c  */
#line 2852 "P1.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
		      yytoken, &yylval);
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
      if (!yypact_value_is_default (yyn))
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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



/* Line 2067 of yacc.c  */
#line 949 "P1.y"


int main( int argc, char** argv){
//extern int yydebug;
//yydebug=1;
	yyparse();
	//int count= countMacros();
	//macroNode* macros=(macroNode*)malloc(count*sizeof(macroNode));	
	//initMacros(macros);
}

yyerror(char *s){
	fprintf(stderr, "Parse error...: %s\n", s);
}

void AddMacro(macroNode* m, macroNode* macroList, int i){
	macroList[i]=*m;
}


