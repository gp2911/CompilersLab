%{
#include "P1.tab.h"
#include <string.h>
int comment_caller;
%}

%x multi_line_comment foo
%x single_line_comment bar


%%

"#define" 			{	yylval.str = strdup ( yytext );
					return MACRO_DEF;
					}
"length" 			{ 	yylval.str = strdup ( yytext );
					return LEN;
					}
"int"    			{	yylval.str = strdup ( yytext );
					return INT_DECL;
					}
"String"  			{	yylval.str = strdup ( yytext );
					return STRING_DECL;	
					}
"class"	  			{	yylval.str = strdup ( yytext );
					return CLASS_DECL;
					}
"public static void main" 	{	yylval.str = strdup (yytext);
					return MAIN;
					}
"boolean"			{	yylval.str = strdup (yytext);
					return BOOL_DECL;
					}
"while"				{       yylval.str = strdup (yytext);
                                        return WHILE;
					}
"if" 				{       yylval.str = strdup (yytext);
                                        return IF;
					}
"else" 				{       yylval.str = strdup (yytext);
                                        return ELSE;
					}
"extends"			{       yylval.str = strdup (yytext);
                                        return EXT;
					}
"new"				{       yylval.str = strdup (yytext);
                                        return NEW;
					}
"public" 			{       yylval.str = strdup (yytext);
                                        return PUB;
					}
"static"			{	yylval.str = strdup (yytext);
					return STATIC;
					}
"void"				{	yylval.str = strdup (yytext);
					return VOID;
					}
"main"				{	yylval.str = strdup (yytext);
					return MAIN_KEY;
					}
"return" 			{       yylval.str = strdup (yytext);
                                        return RET;
					}
"this"				{       yylval.str = strdup (yytext);
                                        return THIS;
					}
"true" 				{       yylval.str = strdup (yytext);
                                        return TRUE;
					}
"false" 			{       yylval.str = strdup (yytext);
                                        return FALSE;
					}

[a-zA-Z"_"][a-zA-Z0-9"_"]* 	{       yylval.str = strdup (yytext);
                                        return ID;
					}
[1-9][0-9]*			{	yylval.str = strdup ( yytext );
					return INT;
					}
0				{       yylval.str = strdup (yytext);
                                        return INT;
					}

"+" 				{       yylval.str = strdup (yytext);
                                        return ADD;
					}
"-" 				{       yylval.str = strdup (yytext);
                                        return SUB;
					}
"*" 				{       yylval.str = strdup (yytext);
                                        return MUL;
					}
"/" 				{       yylval.str = strdup (yytext);
                                        return DIV;
					}

"="				{       yylval.str = strdup (yytext);
                                        return EQ;
					}

"!" 				{       yylval.str = strdup (yytext);
                                        return NOT;	
					}
"&" 				{       yylval.str = strdup (yytext);
                                        return AND;
					}
"<"				{       yylval.str = strdup (yytext);
                                        return LT;
					}

"{" 				{       yylval.str = strdup (yytext);
                                        return BRACE_OPEN;
					}
"}" 				{       yylval.str = strdup (yytext);
                                        return BRACE_CLOSE;
					}
"(" 				{       yylval.str = strdup (yytext);
                                        return PARA_OPEN;
					}
")" 				{       yylval.str = strdup (yytext);
                                        return PARA_CLOSE;
					}
"[" 				{       yylval.str = strdup (yytext);
                                        return SQ_OPEN;
					}
"]" 				{       yylval.str = strdup (yytext);
                                        return SQ_CLOSE;
					}

";" 				{       yylval.str = strdup (yytext);
                                        return SEMICOLON;
					}	
"," 				{       yylval.str = strdup (yytext);
                                        return COMMA;
					}
"." 				{       yylval.str = strdup (yytext);
                                        return DOT;
					}

"System.out.println" 		{       yylval.str = strdup (yytext);
                                        return PRINT;
					}
 
"<<EOF>>" 			{       yylval.str = strdup (yytext);
                                        return EF;	
					}


[\t\n" "]+ /*eat up whitespaces*/

"//" {
	comment_caller=INITIAL;
	BEGIN(single_line_comment);
	}

<bar>"//" {
	comment_caller=bar;
	BEGIN(single_line_comment);
	}

"/*" {
	comment_caller = INITIAL;
	BEGIN(multi_line_comment);
	}

<foo>"/*" {
	 comment_caller=foo;
	 BEGIN(multi_line_comment);
	}

<multi_line_comment>[^*]*
<multi_line_comment>"*"+[^*]*
<multi_line_comment>["*"]+"/" BEGIN(comment_caller);

<single_line_comment>[^"\n"]*
<single_line_comment>["\n"]+ BEGIN(comment_caller);


. 				{	yylval.str = strdup(yytext);
					printf("Unknown character! %s \n", yytext);
					}

%%

