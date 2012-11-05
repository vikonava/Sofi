/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     PROGRAMA = 258,
     VAR = 259,
     NUMERO = 260,
     DECIMAL = 261,
     TEXTO = 262,
     CARACTER = 263,
     BOOLEANO = 264,
     TRUE = 265,
     FALSE = 266,
     IMPRIME = 267,
     LEE = 268,
     SI = 269,
     SINO = 270,
     Y = 271,
     O = 272,
     REALIZA = 273,
     FIN = 274,
     MIENTRAS = 275,
     PARA = 276,
     FUNC = 277,
     IGUAL = 278,
     MAYOR = 279,
     MENOR = 280,
     DIFERENTE = 281,
     ID = 282,
     CTENUM = 283,
     CTEDEC = 284,
     CTEX = 285,
     CCAR = 286,
     COMA = 287,
     PCOMA = 288,
     ABREPA = 289,
     CIERRAPA = 290,
     ABRECORCH = 291,
     CIERRACORCH = 292,
     SIGUAL = 293,
     MAS = 294,
     MENOS = 295,
     POR = 296,
     ENTRE = 297
   };
#endif
/* Tokens.  */
#define PROGRAMA 258
#define VAR 259
#define NUMERO 260
#define DECIMAL 261
#define TEXTO 262
#define CARACTER 263
#define BOOLEANO 264
#define TRUE 265
#define FALSE 266
#define IMPRIME 267
#define LEE 268
#define SI 269
#define SINO 270
#define Y 271
#define O 272
#define REALIZA 273
#define FIN 274
#define MIENTRAS 275
#define PARA 276
#define FUNC 277
#define IGUAL 278
#define MAYOR 279
#define MENOR 280
#define DIFERENTE 281
#define ID 282
#define CTENUM 283
#define CTEDEC 284
#define CTEX 285
#define CCAR 286
#define COMA 287
#define PCOMA 288
#define ABREPA 289
#define CIERRAPA 290
#define ABRECORCH 291
#define CIERRACORCH 292
#define SIGUAL 293
#define MAS 294
#define MENOS 295
#define POR 296
#define ENTRE 297




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 249 "sintaxis.y"
{
    char *str;
}
/* Line 1529 of yacc.c.  */
#line 137 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

