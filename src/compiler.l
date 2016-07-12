
%{
#include "compiler.tab.h"
extern int line_cnt;
//[0-9]*.[0-9]+          {yylval.f_num = atof(yytext); return f_number;}
#define true 1
#define false 0

%}
%%
"int"                  {return INT;}
"float"                {return FLOAT;}
"bool"                 {return BOOL;}
"char"                 {return CHAR;}

"const"                {return CONST;}
"for"				   {return FOR;}
"while"				   {return WHILE;}
"switch"			   {return SWITCH;}
"case"				   {return CASE;}
"do"				   {return DO;}
"if"				   {return IF;}
"default"			   {return DEFAULT;}
"break"				   {return BREAK;}
"continue"             {return CONTINUE;}
"goto"				   {return GOTO;}
"else"                 {return ELSE;}

"true"                 {yylval.bool_val = true; return TRUE;}
"false"                {yylval.bool_val = false; return FALSE;}

"main"                 {return MAIN;}

"=="                   {return EQ_OP;}
">>"                   {return RIGHT_OP;}
"<<"                   {return LEFT_OP;}
">="                   {return GE_OP;}
"<="                   {return LE_OP;}
"&&"                   {return AND_OP;}
"||"                   {return OR_OP;}
"^"                    {return XOR_OP;}


\'[^\'\"]\'            {yylval.char_val = yytext[1]; return CHAR_VAL;}
[_A-Za-z][_A-Za-z0-9]* {yylval.str = alloc_str(yytext); return identifier;} /* return variable name*/
[0-9]*[.][0-9]+        {yylval.f_num = atof(yytext);return f_number;}
[0-9]+                 {yylval.num = atoi(yytext); return number;}
[ \t]                  ;
[-+=;)(/*{}:><!]       {return yytext[0];}
[\n]                   {line_cnt +=1;}
.                      {ECHO; yyerror ("unexpected character");}

%%
int yywrap (void) {return 1;}

