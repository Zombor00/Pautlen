%{
#include <stdio.h>
#include "y.tab.h"

extern FILE * yyout;
long yylin = 1;
long yycol = 1;
int yy_morph_error = 0;
%}

%option noyywrap
ESPACIO 		[ \t]+
SALTOLINEA	\n|\n\r|\r
COMENTARIOS "//".*\n
ID		[a-zA-Z]([a-zA-Z0-9]){0,99}
CTE_ENTERA  [0-9]+
ERROR_LONG  [a-zA-Z]([a-zA-Z0-9]){100,}
ERROR		.

%%
{ESPACIO} {yycol += yyleng;}
{SALTOLINEA}	{yycol = 1; yylin += 1;}
{COMENTARIOS}	{yycol = 1; yylin += 1;}

main {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_MAIN;}
int {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_INT;}
boolean {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_BOOLEAN;}
array {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_ARRAY;}
function {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_FUNCTION;}
if {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_IF;}
else {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_ELSE;}
while {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_WHILE;}
scanf {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_SCANF;}
printf {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_PRINTF;}
return {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_RETURN;}

";" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_PUNTOYCOMA;}
"," {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_COMA;}
"(" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_PARENTESISIZQUIERDO;}
")" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_PARENTESISDERECHO;}
"[" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_CORCHETEIZQUIERDO;}
"]" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_CORCHETEDERECHO;}
"{" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_LLAVEIZQUIERDA;}
"}" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_LLAVEDERECHA;}

"=" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_ASIGNACION;}
"+" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_MAS;}
"-" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_MENOS;}
"/" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_DIVISION;}

"*" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_ASTERISCO;}
"&&" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_AND;}
"||" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_OR;}
"!" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_NOT;}
"==" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_IGUAL;}
"!=" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_DISTINTO;}
"<=" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_MENORIGUAL;}
">=" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_MAYORIGUAL;}
"<" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_MENOR;}
">" {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_MAYOR;}

true {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_TRUE;}
false {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_FALSE;}
{CTE_ENTERA}  {yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_CONSTANTE_ENTERA;}

{ID}		{yycol += yyleng; fprintf(yyout,";D:\t%s\n", yytext); return TOK_IDENTIFICADOR;}

{ERROR_LONG}		{fprintf(stderr,"****Error morfologico en [lin %ld, col %ld]\n", yylin, yycol); yy_morph_error = 1; return TOK_ERROR;}
{ERROR}		{fprintf(stderr,"****Error morfologico en [lin %ld, col %ld]\n", yylin, yycol); yy_morph_error = 1; return TOK_ERROR;}
%%

/*
int main() {
         return yylex();
}*/
