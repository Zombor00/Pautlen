%{
#include <stdio.h>
#include "tokens.h"

long yylin = 1;
long yycol = 1;

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

main {yycol += yyleng; return TOK_MAIN;}
int {yycol += yyleng; return TOK_INT;}
boolean {yycol += yyleng; return TOK_BOOLEAN;}
array {yycol += yyleng; return TOK_ARRAY;}
function {yycol += yyleng; return TOK_FUNCTION;}
if {yycol += yyleng; return TOK_IF;}
else {yycol += yyleng; return TOK_ELSE;}
while {yycol += yyleng; return TOK_WHILE;}
scanf {yycol += yyleng; return TOK_SCANF;}
printf {yycol += yyleng; return TOK_PRINTF;}
return {yycol += yyleng; return TOK_RETURN;}

";" {yycol += yyleng; return TOK_PUNTOYCOMA;}
"," {yycol += yyleng; return TOK_COMA;}
"(" {yycol += yyleng; return TOK_PARENTESISIZQUIERDO;}
")" {yycol += yyleng; return TOK_PARENTESISDERECHO;}
"[" {yycol += yyleng; return TOK_CORCHETEIZQUIERDO;}
"]" {yycol += yyleng; return TOK_CORCHETEDERECHO;}
"{" {yycol += yyleng; return TOK_LLAVEIZQUIERDA;}
"}" {yycol += yyleng; return TOK_LLAVEDERECHA;}

"=" {yycol += yyleng; return TOK_ASIGNACION;}
"+" {yycol += yyleng; return TOK_MAS;}
"-" {yycol += yyleng; return TOK_MENOS;}
"/" {yycol += yyleng; return TOK_DIVISION;}

"*" {yycol += yyleng; return TOK_ASTERISCO;}
"&&" {yycol += yyleng; return TOK_AND;}
"||" {yycol += yyleng; return TOK_OR;}
"!" {yycol += yyleng; return TOK_NOT;}
"==" {yycol += yyleng; return TOK_IGUAL;}
"!=" {yycol += yyleng; return TOK_DISTINTO;}
"<=" {yycol += yyleng; return TOK_MENORIGUAL;}
">=" {yycol += yyleng; return TOK_MAYORIGUAL;}
"<" {yycol += yyleng; return TOK_MENOR;}
">" {yycol += yyleng; return TOK_MAYOR;}

true {yycol += yyleng; return TOK_TRUE;}
false {yycol += yyleng; return TOK_FALSE;}
{CTE_ENTERA}  {yycol += yyleng; return TOK_CONSTANTE_ENTERA;}

{ID}		{yycol += yyleng; return TOK_IDENTIFICADOR;}

{ERROR_LONG}		{yycol += yyleng; return TOK_ERROR;}
{ERROR}		{yycol += yyleng; return TOK_ERROR;}
%%

/*
int main() {
         return yylex();
}*/
