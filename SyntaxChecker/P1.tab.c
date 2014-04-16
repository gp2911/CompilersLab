/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "P1.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Code corresponding to one token in input
struct pNode{
    char* s;
    struct pNode* next;
};

//A code fragment
struct pFrag{
    struct pNode* head;
    struct pNode* tail;
};

//Macro node



//typedef struct mNode macroNode;
typedef struct pNode progNode;
typedef struct pFrag progFrag;
//macroNode* macros;
//macroNode currNode;

int no_of_macros=-1;

int i;
int j;
int k;

//void AddMacro( macroNode*, macroNode*, int );
//void parseArgs(progFrag*, macroNode*);

/* Line 371 of yacc.c  */
#line 105 "P1.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "P1.tab.h".  */
#ifndef YY_YY_P1_TAB_H_INCLUDED
# define YY_YY_P1_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     BRACE_OPEN = 259,
     BRACE_CLOSE = 260,
     PARA_OPEN = 261,
     PARA_CLOSE = 262,
     STATIC = 263,
     SQ_OPEN = 264,
     SQ_CLOSE = 265,
     INT = 266,
     TRUE = 267,
     FALSE = 268,
     THIS = 269,
     NEW = 270,
     INT_DECL = 271,
     DOT = 272,
     VOID = 273,
     NOT = 274,
     AND = 275,
     LT = 276,
     WHILE = 277,
     IF = 278,
     ELSE = 279,
     BOOL_DECL = 280,
     CLASS_DECL = 281,
     LEN = 282,
     MAIN = 283,
     EQ = 284,
     SEMICOLON = 285,
     EF = 286,
     COMMA = 287,
     EXT = 288,
     PUB = 289,
     RET = 290,
     MAIN_KEY = 291,
     ADD = 292,
     SUB = 293,
     MUL = 294,
     DIV = 295,
     MOD = 296,
     PRINT = 297,
     STRING_DECL = 298
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 38 "P1.y"

	struct pFrag* frag;
	char* str;


/* Line 387 of yacc.c  */
#line 197 "P1.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_P1_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 225 "P1.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
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
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNRULES -- Number of states.  */
#define YYNSTATES  154

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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,    25,    28,    29,    33,    34,    39,
      44,    45,    49,    50,    55,    56,    59,    60,    74,    77,
      78,    85,    94,    98,   100,   102,   104,   106,   108,   112,
     118,   123,   131,   133,   139,   147,   155,   161,   163,   165,
     169,   173,   177,   181,   185,   189,   194,   198,   205,   210,
     212,   214,   218,   220,   222,   224,   230,   235,   238,   240,
     243
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    46,    54,    -1,    26,     3,     4,    28,
       6,    43,     9,    10,     3,     7,     4,    42,     6,    61,
       7,    30,     5,     5,    -1,    61,    48,    -1,    -1,    48,
      32,    61,    -1,    -1,    49,    56,     3,    30,    -1,    49,
       3,     3,    30,    -1,    -1,    56,     3,    51,    -1,    -1,
      51,    32,    56,     3,    -1,    -1,    52,    53,    -1,    -1,
      34,    56,     3,     6,    50,     7,     4,    49,    64,    35,
      61,    30,     5,    -1,    54,    55,    -1,    -1,    26,     3,
       4,    49,    52,     5,    -1,    26,     3,    33,     3,     4,
      49,    52,     5,    -1,    16,     9,    10,    -1,    25,    -1,
      16,    -1,     3,    -1,    58,    -1,    60,    -1,     4,    64,
       5,    -1,    42,     6,    61,     7,    30,    -1,     3,    29,
      61,    30,    -1,     3,     9,    61,    10,    29,    61,    30,
      -1,    59,    -1,    22,     6,    61,     7,    57,    -1,    23,
       6,    61,     7,    58,    24,    58,    -1,    23,     6,    61,
       7,    58,    24,    60,    -1,    23,     6,    61,     7,    57,
      -1,    62,    -1,    63,    -1,    63,    37,    63,    -1,    63,
      38,    63,    -1,    63,    39,    63,    -1,    63,    40,    63,
      -1,    63,    20,    63,    -1,    63,    21,    63,    -1,    63,
       9,    63,    10,    -1,    63,    17,    27,    -1,    63,    17,
       3,     6,    47,     7,    -1,     3,     6,    47,     7,    -1,
      11,    -1,     3,    -1,     6,    61,     7,    -1,    12,    -1,
      13,    -1,    14,    -1,    15,    16,     9,    61,    10,    -1,
      15,     3,     6,     7,    -1,    19,    61,    -1,    57,    -1,
      64,    57,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    69,    69,    85,   116,   124,   134,   145,   155,   169,
     186,   196,   209,   219,   234,   244,   252,   262,   296,   304,
     314,   334,   362,   378,   387,   396,   406,   409,   413,   430,
     449,   465,   488,   491,   509,   541,   563,   583,   587,   592,
     603,   615,   627,   639,   651,   663,   678,   691,   711,   728,
     738,   748,   760,   769,   779,   789,   808,   826,   838,   841,
     857
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "BRACE_OPEN", "BRACE_CLOSE",
  "PARA_OPEN", "PARA_CLOSE", "STATIC", "SQ_OPEN", "SQ_CLOSE", "INT",
  "TRUE", "FALSE", "THIS", "NEW", "INT_DECL", "DOT", "VOID", "NOT", "AND",
  "LT", "WHILE", "IF", "ELSE", "BOOL_DECL", "CLASS_DECL", "LEN", "MAIN",
  "EQ", "SEMICOLON", "EF", "COMMA", "EXT", "PUB", "RET", "MAIN_KEY", "ADD",
  "SUB", "MUL", "DIV", "MOD", "PRINT", "STRING_DECL", "$accept", "Goal",
  "mainClass", "exprList", "exprList1", "declList", "funcArgs",
  "typeIDList", "methodDeclList", "methodDecl", "typeDeclList", "typeDecl",
  "Type", "Stmt", "Stmt1", "matchedIf", "unmatchedIf", "Expr",
  "Expression", "primaryExpr", "stmtList", YY_NULL
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
     295,   296,   297,   298
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    47,    47,    48,    48,    49,    49,
      49,    50,    50,    51,    51,    52,    52,    53,    54,    54,
      55,    55,    56,    56,    56,    56,    57,    57,    58,    58,
      58,    58,    58,    58,    59,    60,    60,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,    18,     2,     0,     3,     0,     4,     4,
       0,     3,     0,     4,     0,     2,     0,    13,     2,     0,
       6,     8,     3,     1,     1,     1,     1,     1,     3,     5,
       4,     7,     1,     5,     7,     7,     5,     1,     1,     3,
       3,     3,     3,     3,     3,     4,     3,     6,     4,     1,
       1,     3,     1,     1,     1,     5,     4,     2,     1,     2,
       0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    19,     0,     1,     2,     0,     0,    18,
       0,     0,     0,    10,     0,     0,    16,     0,     0,     0,
      24,    23,     0,     0,    10,     0,     0,     0,    20,     0,
      15,     0,    16,     0,     9,    22,    25,     0,     8,     0,
       0,     0,    21,     0,    12,     0,     0,     0,     0,     0,
      14,    50,     0,    49,    52,    53,    54,     0,     0,     0,
      37,    38,    10,    11,     5,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,     0,
       0,     7,    51,     0,     0,     0,    50,     0,     0,    46,
      43,    44,    39,    40,    41,    42,     0,    60,     0,     0,
       0,    58,    26,    32,    27,     0,     0,    48,     4,    56,
       0,     0,    45,     5,     0,     0,     0,     0,     0,     0,
       0,     0,    59,    13,     0,    55,     3,     0,     0,     0,
      28,     0,     0,     0,     0,     6,    47,     0,    30,     0,
       0,     0,     0,     0,    33,    36,    26,    29,    17,     0,
       0,    31,    34,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    80,   108,    16,    46,    63,    22,    30,
       6,     9,    23,   101,   102,   103,   104,    81,    60,    61,
     105
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -86
static const yytype_int16 yypact[] =
{
     -12,    26,    34,   -86,    31,   -86,    11,    46,    55,   -86,
      57,    13,    39,   -86,    80,    75,    37,    81,    76,    84,
      83,   -86,    14,    86,   -86,    90,    64,    91,   -86,    65,
     -86,    73,    37,   100,   -86,   -86,   -86,   103,   -86,    18,
     104,   109,   -86,    67,    65,   110,   118,   123,    85,   124,
     -86,   121,    85,   -86,   -86,   -86,   -86,    53,    85,   122,
     -86,    40,   -86,    98,    85,   125,   127,   126,   -86,   101,
      99,    15,    99,    99,    99,    99,    99,    99,    -1,    65,
     129,   -86,   -86,   130,    85,   133,   -86,   131,   128,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,    30,     5,   134,   136,
     137,   -86,   -86,   -86,   -86,     3,   141,   -86,   107,   -86,
     135,   142,   -86,    85,    85,    85,    35,     8,    85,    85,
      85,    85,   -86,   -86,    85,   -86,   -86,   139,   138,   119,
     -86,   143,   144,   145,   132,   -86,   -86,   140,   -86,     5,
       5,   146,   148,    85,   -86,   -86,   147,   -86,   -86,   149,
       5,   -86,   -86,   -86
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -86,   -86,   -86,    41,   -86,   -19,   -86,   -86,   150,   -86,
     -86,   -86,   -28,   -85,   -75,   -86,     6,   -48,   -86,    47,
      58
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      59,    37,    96,    97,    65,    32,   116,    97,   116,    97,
      68,   116,    97,   130,     1,    20,    47,    13,    88,    28,
     122,    98,    99,    42,    21,    98,    99,    98,    99,     4,
      98,    99,   122,    26,     5,     7,   110,     8,   121,   114,
      19,   100,    89,    78,   114,   100,    14,   100,    29,    70,
     100,   106,    29,    20,   144,   145,    66,    71,    11,   115,
      72,    73,    21,    12,   115,   146,   128,   129,    36,    67,
     131,   132,   133,   134,    10,   152,   135,    74,    75,    76,
      77,    20,    15,    17,    18,    24,    25,    26,    51,    31,
      21,    52,    27,    33,    34,   149,    53,    54,    55,    56,
      57,    35,    86,    38,    58,    52,    41,    40,    43,    45,
      53,    54,    55,    56,    57,    44,    48,    87,    58,    90,
      91,    92,    93,    94,    95,    49,    50,    64,    62,    69,
      79,    85,    82,    83,   113,    84,   107,   109,   111,   124,
     118,   112,   119,   120,   123,   125,   136,   126,   137,   138,
     139,   140,   141,   148,   127,   117,   153,     0,     0,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,   143,
       0,   150,     0,     0,     0,     0,   147,     0,     0,   151,
       0,     0,    39
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-86)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      48,    29,     3,     4,    52,    24,     3,     4,     3,     4,
      58,     3,     4,     5,    26,    16,    44,     4,     3,     5,
     105,    22,    23,     5,    25,    22,    23,    22,    23,     3,
      22,    23,   117,     3,     0,     4,    84,    26,    35,     9,
       3,    42,    27,    62,     9,    42,    33,    42,    34,     9,
      42,    79,    34,    16,   139,   140,     3,    17,     3,    29,
      20,    21,    25,     6,    29,   140,   114,   115,     3,    16,
     118,   119,   120,   121,    28,   150,   124,    37,    38,    39,
      40,    16,    43,     3,     9,     4,    10,     3,     3,     3,
      25,     6,     9,     3,    30,   143,    11,    12,    13,    14,
      15,    10,     3,    30,    19,     6,     3,     7,     4,    42,
      11,    12,    13,    14,    15,     6,     6,    70,    19,    72,
      73,    74,    75,    76,    77,     7,     3,     6,     4,     7,
      32,    30,     7,     6,     6,     9,     7,     7,     5,    32,
       6,    10,     6,     6,     3,    10,     7,     5,    10,    30,
       7,     7,     7,     5,   113,    97,   150,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    24,    -1,    -1,    -1,    -1,    30,    -1,    -1,    30,
      -1,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    45,    46,     3,     0,    54,     4,    26,    55,
      28,     3,     6,     4,    33,    43,    49,     3,     9,     3,
      16,    25,    52,    56,     4,    10,     3,     9,     5,    34,
      53,     3,    49,     3,    30,    10,     3,    56,    30,    52,
       7,     3,     5,     4,     6,    42,    50,    56,     6,     7,
       3,     3,     6,    11,    12,    13,    14,    15,    19,    61,
      62,    63,     4,    51,     6,    61,     3,    16,    61,     7,
       9,    17,    20,    21,    37,    38,    39,    40,    49,    32,
      47,    61,     7,     6,     9,    30,     3,    63,     3,    27,
      63,    63,    63,    63,    63,    63,     3,     4,    22,    23,
      42,    57,    58,    59,    60,    64,    56,     7,    48,     7,
      61,     5,    10,     6,     9,    29,     3,    64,     6,     6,
       6,    35,    57,     3,    32,    10,     5,    47,    61,    61,
       5,    61,    61,    61,    61,    61,     7,    10,    30,     7,
       7,     7,    30,    29,    57,    57,    58,    30,     5,    61,
      24,    30,    58,    60
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

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
/* Line 1787 of yacc.c  */
#line 69 "P1.y"
    { 
			
			                                                                progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (2)].frag)->head;
                                                                            (yyvsp[(1) - (2)].frag)->tail->next=(yyvsp[(2) - (2)].frag)->head;
                                                                            (yyvsp[(2) - (2)].frag)->tail->next=NULL;
			                                                                //$3->tail->next=NULL;
                                                                            frag->tail=(yyvsp[(2) - (2)].frag)->tail;
                                                                            (yyval.frag)=frag;
			                                                                progNode* tmp1=(yyval.frag)->head;
                                                                            //printf("Expression:\n");
                                                                            while(tmp1!=NULL){
                                                                                printf("%s ", tmp1->s);
                                                                                tmp1=tmp1->next;
                                                                            }
                                            }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 85 "P1.y"
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
/* Line 1787 of yacc.c  */
#line 116 "P1.y"
    {
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (2)].frag)->head;
                                                                            (yyvsp[(1) - (2)].frag)->tail->next=(yyvsp[(2) - (2)].frag)->head;
                                                                            (yyvsp[(2) - (2)].frag)->tail->next=NULL;
                                                                            frag->tail=(yyvsp[(2) - (2)].frag)->tail;
                                                                            (yyval.frag)=frag;
 		                                    }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 124 "P1.y"
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

  case 6:
/* Line 1787 of yacc.c  */
#line 134 "P1.y"
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

  case 7:
/* Line 1787 of yacc.c  */
#line 145 "P1.y"
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
/* Line 1787 of yacc.c  */
#line 155 "P1.y"
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

  case 9:
/* Line 1787 of yacc.c  */
#line 169 "P1.y"
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

  case 10:
/* Line 1787 of yacc.c  */
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

  case 11:
/* Line 1787 of yacc.c  */
#line 197 "P1.y"
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

  case 12:
/* Line 1787 of yacc.c  */
#line 209 "P1.y"
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

  case 13:
/* Line 1787 of yacc.c  */
#line 220 "P1.y"
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

  case 14:
/* Line 1787 of yacc.c  */
#line 234 "P1.y"
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
/* Line 1787 of yacc.c  */
#line 244 "P1.y"
    {   
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (2)].frag)->head;
                                                                            (yyvsp[(1) - (2)].frag)->tail->next=(yyvsp[(2) - (2)].frag)->head;
                                                                            (yyvsp[(2) - (2)].frag)->tail->next=NULL;
                                                                            frag->tail=(yyvsp[(2) - (2)].frag)->tail;
                                                                            (yyval.frag)=frag;
                                            }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 252 "P1.y"
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
/* Line 1787 of yacc.c  */
#line 263 "P1.y"
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
                                                                        	////printf("#@#@#@$ %d \n",(int) $2->tail);
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

  case 18:
/* Line 1787 of yacc.c  */
#line 296 "P1.y"
    {  
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (2)].frag)->head;
                                                                            (yyvsp[(1) - (2)].frag)->tail->next=(yyvsp[(2) - (2)].frag)->head;
                                                                            (yyvsp[(2) - (2)].frag)->tail->next=NULL;
                                                                            frag->tail=(yyvsp[(2) - (2)].frag)->tail;
                                                                            (yyval.frag)=frag;
                                            }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 304 "P1.y"
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

  case 20:
/* Line 1787 of yacc.c  */
#line 314 "P1.y"
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

  case 21:
/* Line 1787 of yacc.c  */
#line 334 "P1.y"
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

  case 22:
/* Line 1787 of yacc.c  */
#line 362 "P1.y"
    { 
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
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

  case 23:
/* Line 1787 of yacc.c  */
#line 378 "P1.y"
    { 
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                			tmp1->s=(yyvsp[(1) - (1)].str);
                                                                			tmp1->next=NULL;
                                                                			progFrag* frag=(progFrag*)malloc(sizeof(progNode));
                                                                			frag->head=tmp1;
                                                                			frag->tail=tmp1;
                                                                			(yyval.frag)=frag;
                                            }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 387 "P1.y"
    { 
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=(yyvsp[(1) - (1)].str);
                                                                            tmp1->next=NULL;
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progNode));
                                                                            frag->head=tmp1;
                                                                            frag->tail=tmp1;
                                                                            (yyval.frag)=frag;
                                            }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 396 "P1.y"
    { 
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=(yyvsp[(1) - (1)].str);
                                                                            tmp1->next=NULL;
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progNode));
                                                                            frag->head=tmp1;
                                                                            frag->tail=tmp1;
                                                                            (yyval.frag)=frag;
                                            }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 406 "P1.y"
    { 
                                                                            (yyval.frag)=(yyvsp[(1) - (1)].frag);
                                            }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 409 "P1.y"
    {
                                                                            (yyval.frag)=(yyvsp[(1) - (1)].frag);
                                            }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 413 "P1.y"
    { 
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
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

  case 29:
/* Line 1787 of yacc.c  */
#line 430 "P1.y"
    { 
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
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
                                                                            frag->tail=tmp4;
                                                                            (yyval.frag)=frag;
                                            }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 449 "P1.y"
    { 
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
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

  case 31:
/* Line 1787 of yacc.c  */
#line 465 "P1.y"
    {
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
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

  case 32:
/* Line 1787 of yacc.c  */
#line 488 "P1.y"
    {
                                                                            (yyval.frag)=(yyvsp[(1) - (1)].frag); 
                                            }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 491 "P1.y"
    {
                                                                            ////printf("here in expr\n");
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
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

  case 34:
/* Line 1787 of yacc.c  */
#line 509 "P1.y"
    { 
                                                                            printf("in matched if\n");
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
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
                                                                            progNode * tmp = frag->head;
                                                                            while(tmp != NULL){
                                                                                printf("%s", tmp->s);
                                                                                tmp = tmp->next;
                                                                            }

                                            }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 541 "P1.y"
    {
                                                                            printf("in unmatched if\n");
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
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

  case 36:
/* Line 1787 of yacc.c  */
#line 563 "P1.y"
    {
                                                                            printf("in unmatched if\n");    
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
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

  case 37:
/* Line 1787 of yacc.c  */
#line 583 "P1.y"
    {
                                                                			//printf("in expr\n");
                                                                            (yyval.frag)= (yyvsp[(1) - (1)].frag);
                                    		}
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 587 "P1.y"
    { 
                                                                			//printf("in expr, to primExp\n");
                                                                            (yyval.frag)= (yyvsp[(1) - (1)].frag);
                                			}
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 592 "P1.y"
    { 	
                                                                            //printf("so far so good\n");
                                                                            progNode* tmp= (progNode*)malloc(sizeof(progNode));
                                                    						tmp->s=(yyvsp[(2) - (3)].str);
                                                    						progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                    						frag->head=(yyvsp[(1) - (3)].frag)->head;
                                                    						(yyvsp[(1) - (3)].frag)->tail->next=tmp;
                                                    						tmp->next=(yyvsp[(3) - (3)].frag)->head;
                                                    						frag->tail= (yyvsp[(3) - (3)].frag)->tail;
                                                    						(yyval.frag)=frag;
                    						}
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 603 "P1.y"
    {         
                                                                            progNode* tmp= (progNode*)malloc(sizeof(progNode));
                                                                            tmp->s=(yyvsp[(2) - (3)].str);
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (3)].frag)->head;
                                                                            (yyvsp[(1) - (3)].frag)->tail->next=tmp;
                                                                            tmp->next=(yyvsp[(3) - (3)].frag)->head;
                                                                            frag->tail= (yyvsp[(3) - (3)].frag)->tail;
                                                    						(yyval.frag)=frag;

                                            }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 615 "P1.y"
    {      
                                                                            progNode* tmp= (progNode*)malloc(sizeof(progNode));
                                                                            tmp->s=(yyvsp[(2) - (3)].str);
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (3)].frag)->head;
                                                                            (yyvsp[(1) - (3)].frag)->tail->next=tmp;
                                                                            tmp->next=(yyvsp[(3) - (3)].frag)->head;
                                                                            frag->tail= (yyvsp[(3) - (3)].frag)->tail;
                                                    						(yyval.frag)=frag;
		                                
                                            }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 627 "P1.y"
    {      
                                                                            progNode* tmp= (progNode*)malloc(sizeof(progNode));
                                                                            tmp->s=(yyvsp[(2) - (3)].str);
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (3)].frag)->head;
                                                                            (yyvsp[(1) - (3)].frag)->tail->next=tmp;
                                                                            tmp->next=(yyvsp[(3) - (3)].frag)->head;
                                                                            frag->tail= (yyvsp[(3) - (3)].frag)->tail;
                                                    						(yyval.frag)=frag;
                                    
                			                }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 639 "P1.y"
    {     
                                                                            progNode* tmp= (progNode*)malloc(sizeof(progNode));
                                                                            tmp->s=(yyvsp[(2) - (3)].str);
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (3)].frag)->head;
                                                                            (yyvsp[(1) - (3)].frag)->tail->next=tmp;
                                                                            tmp->next=(yyvsp[(3) - (3)].frag)->head;
                                                                            frag->tail= (yyvsp[(3) - (3)].frag)->tail;
                                                    						(yyval.frag)=frag;
                        	        
        	                                }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 651 "P1.y"
    {      
                                                                            progNode* tmp= (progNode*)malloc(sizeof(progNode));
                                                                            tmp->s=(yyvsp[(2) - (3)].str);
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=(yyvsp[(1) - (3)].frag)->head;
                                                                            (yyvsp[(1) - (3)].frag)->tail->next=tmp;
                                                                            tmp->next=(yyvsp[(3) - (3)].frag)->head;
                                                                            frag->tail= (yyvsp[(3) - (3)].frag)->tail;
                                                    						(yyval.frag)=frag;
                
                	                        }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 663 "P1.y"
    {      
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
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

  case 46:
/* Line 1787 of yacc.c  */
#line 678 "P1.y"
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

  case 47:
/* Line 1787 of yacc.c  */
#line 691 "P1.y"
    {     
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
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

  case 48:
/* Line 1787 of yacc.c  */
#line 711 "P1.y"
    {    
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
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

  case 49:
/* Line 1787 of yacc.c  */
#line 728 "P1.y"
    {
                                                                            //printf("should be coming here...");
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                			tmp1->s=(yyvsp[(1) - (1)].str);
                                                                			progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                			frag->head=tmp1;
                                                                			frag->tail=tmp1;
                                                                			tmp1->next=NULL;
                                                                			(yyval.frag)=frag;
                                    			}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 738 "P1.y"
    {     
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=(yyvsp[(1) - (1)].str);
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=tmp1;
                                                                            frag->tail=tmp1;
                                                                            tmp1->next=NULL;
                                                                            (yyval.frag)=frag;
                                                }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 748 "P1.y"
    {  
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
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

  case 52:
/* Line 1787 of yacc.c  */
#line 760 "P1.y"
    {     
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(   progNode));
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=tmp1;
                                                                            frag->tail=tmp1;
                                                                            tmp1->next=NULL;
                                                                            (yyval.frag)=frag;
                                               }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 769 "P1.y"
    {  
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=(yyvsp[(1) - (1)].str);
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=tmp1;
                                                                            frag->tail=tmp1;
                                                                            tmp1->next=NULL;
                                                                            (yyval.frag)=frag;
                                                }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 779 "P1.y"
    {     
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
                                                                            tmp1->s=(yyvsp[(1) - (1)].str);
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
                                                                            frag->head=tmp1;
                                                                            frag->tail=tmp1;
                                                                            tmp1->next=NULL;
                                                                            (yyval.frag)=frag;
                                                }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 789 "P1.y"
    { 
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
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

  case 56:
/* Line 1787 of yacc.c  */
#line 808 "P1.y"
    {  
                                                                            progNode* tmp1= (progNode*)malloc(sizeof(progNode));
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

  case 57:
/* Line 1787 of yacc.c  */
#line 826 "P1.y"
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

  case 58:
/* Line 1787 of yacc.c  */
#line 838 "P1.y"
    {
                                                                            (yyval.frag)=(yyvsp[(1) - (1)].frag);
                                                }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 841 "P1.y"
    {  
                                                                            progFrag* frag=(progFrag*)malloc(sizeof(progFrag));
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

  case 60:
/* Line 1787 of yacc.c  */
#line 857 "P1.y"
    {
                                                                            progFrag* tmp=(progFrag*)malloc(sizeof(progNode));
                                                                            progNode* tmp_head=(progNode*) malloc(sizeof(progNode));
                                                                            tmp_head->s="";
                                                                            tmp_head->next=NULL;
                                                                            tmp->head=tmp_head;
                                                                            tmp->tail=NULL;
                                                                            (yyval.frag)=tmp;
                                                }
    break;


/* Line 1787 of yacc.c  */
#line 2608 "P1.tab.c"
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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


/* Line 2050 of yacc.c  */
#line 867 "P1.y"


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

/*void AddMacro(macroNode* m, macroNode* macroList, int i){
	macroList[i]=*m;
}

void parseArgs(progFrag* args, macroNode *m){
    if(args==NULL)
        m->no_of_args=0;
    else{
        int argNum = 0;
        progNode *tmp = args->head;
        while(tmp){
            if(strcmp(tmp->s, ",")!=0  && strcmp(tmp->s," ")!=0){
                strcpy(m->args[argNum], tmp->s);
                argNum++;
            }
            tmp = tmp->next;
        }
        m->no_of_args = argNum;
    }
}
*/
