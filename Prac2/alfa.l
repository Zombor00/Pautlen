%{
#include <stdio.h>
#include "tokens.h"
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
{ESPACIO} {}
{SALTOLINEA}	{}
{COMENTARIOS}	{}

main {return TOK_MAIN;}
int {return TOK_INT;}
boolean {return TOK_BOOLEAN;}
array {return TOK_ARRAY;}
function {return TOK_FUNCTION;}
if {return TOK_IF;}
else {return TOK_ELSE;}
while {return TOK_WHILE;}
scanf {return TOK_SCANF;}
printf {return TOK_PRINTF;}
return {return TOK_RETURN;}

";" {return TOK_PUNTOYCOMA;}
"," {return TOK_COMA;}
"(" {return TOK_PARENTESISIZQUIERDO;}
")" {return TOK_PARENTESISDERECHO;}
"[" {return TOK_CORCHETEIZQUIERDO;}
"]" {return TOK_CORCHETEDERECHO;}
"{" {return TOK_LLAVEIZQUIERDA;}
"}" {return TOK_LLAVEDERECHA;}

"=" {return TOK_ASIGNACION;}
"+" {return TOK_MAS;}
"-" {return TOK_MENOS;}
"/" {return TOK_DIVISION;}

"*" {return TOK_ASTERISCO;}
"&&" {return TOK_AND;}
"||" {return TOK_OR;}
"!" {return TOK_NOT;}
"==" {return TOK_IGUAL;}
"!=" {return TOK_DISTINTO;}
"<=" {return TOK_MENORIGUAL;}
">=" {return TOK_MAYORIGUAL;}
"<" {return TOK_MENOR;}
">" {return TOK_MAYOR;}

true {return TOK_TRUE;}
false {return TOK_FALSE;}
{CTE_ENTERA}  {return TOK_CONSTANTE_ENTERA;}

{ID}		{return TOK_IDENTIFICADOR;}

{ERROR_LONG}		{return TOK_ERROR;}
{ERROR}		{return TOK_ERROR;}
%%

/*
int main() {
         return yylex();
}*/
