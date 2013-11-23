/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2068 of yacc.c  */
#line 37 "P1.y"

	struct pFrag* frag;
	char* str;



/* Line 2068 of yacc.c  */
#line 101 "P1.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


