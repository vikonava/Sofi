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
PROGRAMA {return PROGRAMA;}
var {return VAR;}
VAR {return VAR;}
numero {return NUMERO;}
NUMERO {return NUMERO;}
decimal {return DECIMAL;}
DECIMAL {return DECIMAL;}
texto {return TEXTO;}
TEXTO {return TEXTO;}
caracter {return CARACTER;}
CARACTER {return CARACTER;}
booleano {return BOOLEANO;}
BOOLEANO {return BOOLEANO;}
imprime {return IMPRIME;}
IMPRIME {return IMPRIME;}
lee { return LEE;}
LEE { return LEE;}
si {return SI;}
SI {return SI;}
sino {return SINO;}
SINO {return SINO;}
y {return Y;}
Y {return Y;}
o {return O;}
O {return O;}
realiza {return REALIZA;}
REALIZA {return REALIZA;}
fin {return FIN;}
FIN {return FIN;}
mientras {return MIENTRAS;}
MIENTRAS {return MIENTRAS;}
para {return PARA;}
PARA {return PARA;}
func {return FUNC;}
FUNC {return FUNC;}
igual {return IGUAL;}
IGUAL {return IGUAL;}
mayor {return MAYOR;}
MAYOR {return MAYOR;}
menor {return MENOR;}
MENOR {return MENOR;}
diferente {return DIFERENTE;}
DIFERENTE {return DIFERENTE;}
verdadero {return TRUE;}
falso {return FALSE;}
VERDADERO {return TRUE;}
FALSO {return FALSE;}
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