/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
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
/* Line 2053 of yacc.c  */
#line 38 "P1.y"

	struct pFrag* frag;
	char* str;


/* Line 2053 of yacc.c  */
#line 106 "P1.tab.h"
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
