/*
Silvia Fosado Garcia 1032432
Victor Nava 617610

Lexico del Lenguaje
 
*/

%{
	#include <stdio.h>
	#include "sintaxis.tab.h"
    using namespace std;
    #define YY_DECL extern "C" int yylex()
%}
%option yylineno

%%

programa {return PROGRAMA;}
var {return VAR;}
numero {return NUMERO;}
decimal {return DECIMAL;}
texto {return TEXTO;}
caracter {return CARACTER;}
booleano {return BOOLEANO;}
imprime {return IMPRIME;}
lee { return LEE; }
si {return SI;}
sino {return SINO;}
y {return Y;}
o {return O;}
realiza {return REALIZA;}
fin {return FIN;}
mientras {return MIENTRAS;}
para {return PARA;}
func {return FUNC;}
igual {return IGUAL;}
mayor {return MAYOR;}
menor {return MENOR;}
diferente {return DIFERENTE;}
verdadero {return TRUE;}
falso {return FALSE;}
[a-zA-Z][a-zA-Z]* { yylval.str = strdup(yytext); return ID;}
[0-9][0-9]* {yylval.str = strdup(yytext); return CTENUM;}
[0-9][0-9]*\.[0-9][0-9]* {yylval.str = strdup(yytext); return CTEDEC;}
\"[^\"]*\" {yylval.str = strdup(yytext); return CTEX;}
\'[a-zA-Z]\' {yylval.str = strdup(yytext); return CCAR;}
"," {return COMA;}
";" {return PCOMA;}
"(" {return ABREPA;}
")" {return CIERRAPA;}
"[" {return ABRECORCH;}
"]" {return CIERRACORCH;}
"+" {return MAS;}
"-" {return MENOS;}
"*" {return POR;}
"/" {return ENTRE;}
"=" {return SIGUAL;}
\n
\t
\b
\r
.
%%