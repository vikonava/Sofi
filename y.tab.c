/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 8 "sintaxis.y"

	#include <stdio.h>
    #include <iostream>
    #include "estructura.c"
	#include "cuadruplos.c"
	#include "stack.c"
	#include "stackConstantes.c"
	
    using namespace std;
    
    #define YYERROR_VERBOSE 1
    
    extern "C" int yylex();
    extern "C" int yyparse();
    extern "C" FILE *yyin;
    extern int yylineno;
    
    extern void insert_to_dirprocs(char *name, char *returnType);
    
    void yyerror(const char *s);
    
    typedef struct {
        char *name;
        char *returnType;
        int local_variables_address;
        int next;
    } dir_procs;
    
    // Base de Direcciones de Memoria Virtuales
    int GCAR = 0, GTEXTO = 1000, GINT = 2000, GFLOAT = 3000, GBOOL = 4000, LCAR = 5000, LTEXTO = 6000, LINT = 7000, LFLOAT = 8000, LBOOL = 9000, TCAR = 10000, TTEXTO = 11000, TINT = 12000, TFLOAT = 13000, TBOOL = 14000, CTCAR = 15000, CTTEXTO = 16000, CTINT = 17000, CTFLOAT = 18000, CTBOOL = 19000;
    
    // Offsets de Direcciones de Memoria
    int global_car_offset = 0, global_text_offset = 0, global_int_offset = 0, global_float_offset = 0, global_bool_offset = 0, local_car_offset = 0, local_text_offset = 0, local_int_offset = 0, local_float_offset = 0, local_bool_offset = 0, temp_car_offset = 0, temp_text_offset = 0, temp_int_offset = 0, temp_float_offset = 0, temp_bool_offset = 0, const_car_offset = 0, const_text_offset = 0, const_int_offset = 0, const_float_offset = 0, const_bool_offset = 0;

    // Declaracion Variables
	Stack *PilaOperandos; // Creamos la pila de Operandos
	Stack *PilaOperadores; // Creamos la pila de Operadores
	Stack *PiladeSaltos; // Creamos la pila Saltos ints de linea de cuadruplos
    Stack *PiladeSaltosCuad; // Creamos la pila de Saltos que almacena cuadruplos
	Stack *PiladeTipos; //Creamos la pila de los tipos para checar la semantica
    Stack *PilaEjecucion; // Se guarda los procedimientos en los que estamos
	StackConstantes *PilaConstantes;
	
	bool exitoso;
	char *variable_type; // Tipo de la ultima variable conocida
    char *variable_name; // Nombre de la ultima variable conocida
    char *last_func; //
    char *tipo_func;
	int contadorCuad = 0;
	
	Cuadruplos *cuadruplo;
    Node *dirProcsInit; // Crea el apuntador al primer pointer del dir procs
    SemanticCubeNode *semanticCube;; // Apuntador al primer nodo del cubo semantico
    
    int alloc_virtual_address(char *returnType, char *scope) {
        if (strcmp(scope,(char *)"global") == 0) {
            if (strcmp(returnType,(char *)"caracter") == 0) {
                global_car_offset++;
                return GCAR+global_car_offset-1;
            } else if (strcmp(returnType,(char *)"texto") == 0) {
                global_text_offset++;
                return GTEXTO+global_text_offset-1;
            } else if (strcmp(returnType,(char *)"numero") == 0) {
                global_int_offset++;
                return GINT+global_int_offset-1;
            } else if (strcmp(returnType,(char *)"decimal") == 0) {
                global_float_offset++;
                return GFLOAT+global_float_offset-1;
            } else if (strcmp(returnType,(char *)"booleano") == 0) {
                global_bool_offset++;
                return GBOOL+global_bool_offset-1;
            } else return -1;
        } else if (strcmp(scope,(char *)"local") == 0) {
			if (strcmp(returnType,(char *)"caracter") == 0) {
                local_car_offset++;
                return LCAR+local_car_offset-1;
            } else if (strcmp(returnType,(char *)"texto") == 0) {
                local_text_offset++;
                return LTEXTO+local_text_offset-1;
            } else if (strcmp(returnType,(char *)"numero") == 0) {
                local_int_offset++;
                return LINT+local_int_offset-1;
            } else if (strcmp(returnType,(char *)"decimal") == 0) {
                local_float_offset++;
                return LFLOAT+local_float_offset-1;
            } else if (strcmp(returnType,(char *)"booleano") == 0) {
                local_bool_offset++;
                return LBOOL+local_bool_offset-1;
            } else return -1;
        } else if (strcmp(scope,(char *)"temporal") == 0) {
			if (strcmp(returnType,(char *)"caracter") == 0) {
                temp_car_offset++;
                return TCAR+temp_car_offset-1;
            } else if (strcmp(returnType,(char *)"texto") == 0) {
                temp_text_offset++;
                return TTEXTO+temp_text_offset-1;
            } else if (strcmp(returnType,(char *)"numero") == 0) {
                temp_int_offset++;
                return TINT+temp_int_offset-1;
            } else if (strcmp(returnType,(char *)"decimal") == 0) {
                temp_float_offset++;
                return TFLOAT+temp_float_offset-1;
            } else if (strcmp(returnType,(char *)"booleano") == 0) {
                temp_bool_offset++;
                return TBOOL+temp_bool_offset-1;
            } else return -1;
        } else if (strcmp(scope,(char *)"constante") == 0) {
			if (strcmp(returnType,(char *)"caracter") == 0) {
                const_car_offset++;
                return CTCAR+const_car_offset-1;
            } else if (strcmp(returnType,(char *)"texto") == 0) {
                const_text_offset++;
                return CTTEXTO+const_text_offset-1;
            } else if (strcmp(returnType,(char *)"numero") == 0) {
                const_int_offset++;
                return CTINT+const_int_offset-1;
            } else if (strcmp(returnType,(char *)"decimal") == 0) {
                const_float_offset++;
                return CTFLOAT+const_float_offset-1;
            } else if (strcmp(returnType,(char *)"booleano") == 0) {
                const_bool_offset++;
                return CTBOOL+const_bool_offset-1;
            } else return -1;
        } else return -1;
    }
	
	void meterAPilaOperandos(Node *dirProcsInit, char* variable_name, char* last_func){
		Node *tNode = dirProcsInit;
		Node *variableEncontrada = NULL;
		char *tipoVariable;
				
		variableEncontrada = findLocalVariableInProc(tNode, static_cast<char*>(PilaEjecucion->ptr),variable_name);
		
		tipoVariable = variableEncontrada->returnType;
		stack_push(&PilaOperandos, &variableEncontrada->virtual_address, 2);
		stack_push(&PiladeTipos, (findLocalVariableInProc(tNode, static_cast<char*>(PilaEjecucion->ptr),variable_name))->returnType, 1);
        
	}
	
	void meterConstanteAPilaOperandos(char* tipo, char* constante){
		int *direccion = (int *)malloc(sizeof(int));
		
		if(strcmp(tipo, (char *) "numero") == 0){
			*direccion = alloc_virtual_address((char *) "numero", (char *) "constante");
			stack_push(&PilaOperandos, direccion, 2);
			stack_push(&PiladeTipos, (char *) "numero", 1);
			int *cons = (int *)malloc(sizeof(int));
			*cons = atoi(constante);
			stackC_push(&PilaConstantes, cons, *direccion, 2);
		}
		if(strcmp(tipo, (char *) "decimal") == 0){
			*direccion = alloc_virtual_address((char *) "decimal", (char *) "constante");
			stack_push(&PilaOperandos, direccion, 2);
			stack_push(&PiladeTipos, (char *) "decimal", 1);
			float *cons = (float *)malloc(sizeof(float));
			*cons = atof(constante);
			stackC_push(&PilaConstantes, cons, *direccion, 3);
		}
		if(strcmp(tipo, (char *) "caracter") == 0){
			*direccion = alloc_virtual_address((char *) "caracter", (char *) "constante");
			stack_push(&PilaOperandos, direccion, 2);
			stack_push(&PiladeTipos, (char *) "caracter", 0);
			char *cons = (char *)malloc(sizeof(char));
			cons = constante;
			stackC_push(&PilaConstantes, cons, *direccion, 0);
		}
		if(strcmp(tipo, (char *) "texto") == 0){
			*direccion = alloc_virtual_address((char *) "texto", (char *) "constante");
			stack_push(&PilaOperandos, direccion, 2);
			stack_push(&PiladeTipos, (char *) "texto ", 1);
			char *cons = (char *)malloc(sizeof(char));
			cons = constante;
			stackC_push(&PilaConstantes, cons, *direccion, 3);
		}

		
	}
	
	void meterFondoFalso(){
		stack_push(&PilaOperadores, (char *) "-1", 1);
	}
	
	void sacaFondoFalso(){
		if(strcmp(static_cast<char*>(PilaOperadores->ptr), (char *) "-1") == 0){
			stack_pop(&PilaOperadores);
		}
	}
	
	void funcionOperaciones(char* operador){
		char* tipo1;
		char* tipo2;
		char* tipoRetorno;
		int operando1;
		int operando2;
		int *direccionTemporal = (int *)malloc(sizeof(int));
		int operadorInt;
		
		operadorInt = atoi(operador);

		tipo1 = static_cast<char*>(PiladeTipos->ptr);
        
        if (PiladeTipos->next != NULL) {
            tipo2 = static_cast<char*>(PiladeTipos->next->ptr);
        
            tipoRetorno = findSemanticCubeReturnType(semanticCube, tipo1, tipo2, operador);
		
		
            if (PilaOperadores != NULL){
                if (strcmp(operador, static_cast<char*>(PilaOperadores->ptr)) == 0){
                    if( strcmp(tipoRetorno,"error") != 0) {
                        stack_pop(&PiladeTipos);
                        stack_pop(&PiladeTipos);
                        operando2 = *static_cast<int*>(stack_pop(&PilaOperandos)->ptr);
                        operando1 = *static_cast<int*>(stack_pop(&PilaOperandos)->ptr);
                        stack_pop(&PilaOperadores);
                        *direccionTemporal = alloc_virtual_address(tipoRetorno, (char *) "temporal");
                        addCuad(&cuadruplo, operadorInt, operando1, operando2, *direccionTemporal);
						contadorCuad++;
                        stack_push(&PilaOperandos, direccionTemporal, 2);
                        stack_push(&PiladeTipos, (void *)findSemanticCubeReturnType(semanticCube, tipo1, tipo2, operador), 1);
                    } else{
                        printf("Error Semantico: Tipos incopatibles %s,%s\n",tipo1,tipo2);
                    }
                }
            }
        }
	}
	
	void funcionAsignacion(){
		int operando11;
		int operando12;
		char* tipo1;
		char* tipo2;
				
		if (strcmp((char *) "120", static_cast<char*>(PilaOperadores->ptr)) == 0) {
			stack_pop(&PilaOperadores);
			tipo1 = static_cast<char*>(PiladeTipos->ptr);
			tipo2 = static_cast<char*>(PiladeTipos->next->ptr);
			
			if (strcmp(tipo2,tipo1) == 0){
				stack_pop(&PiladeTipos);
				stack_pop(&PiladeTipos);
				operando12 = *static_cast<int*>(stack_pop(&PilaOperandos)->ptr);
				operando11 = *static_cast<int*>(stack_pop(&PilaOperandos)->ptr);
				addCuad(&cuadruplo, 120, operando12, -1, operando11);
				contadorCuad++;
			} else{
				printf("Error Semantico: Tipos incopatibles %s,%s\n",tipo1,tipo2);
			} 
		}
	}

	void funcionIfUno(){
		Cuadruplos *temp;
		char* aux;
		int resultado;
		
		aux = static_cast<char*>(PiladeTipos->ptr);
		if(strcmp(aux, (char *) "booleano") == 0){
			resultado = *static_cast<int*>(stack_pop(&PilaOperandos)->ptr);
			temp = addCuad(&cuadruplo, 140, resultado, -1, -1);
			contadorCuad++;
			stack_push(&PiladeSaltosCuad, temp, 2);
		}
	}
	
	void funcionIfDos(){
		Cuadruplos *falso;
		Cuadruplos *temp;
		
		temp = addCuad(&cuadruplo, 130, -1, -1, -1);
		contadorCuad++;
		falso = static_cast<Cuadruplos*>(stack_pop(&PiladeSaltosCuad)->ptr);
		falso->temporal = contadorCuad+1;
		stack_push(&PiladeSaltosCuad, temp, 2);
		
	}
	
	void funcionIfTres(){
		Cuadruplos *temp;
		
		temp = static_cast<Cuadruplos*>(stack_pop(&PiladeSaltosCuad)->ptr);
		temp->temporal = contadorCuad+1;
	}
	
	void funcionWhileUno(){
		int *cont = (int *)malloc(sizeof(int));
		*cont = contadorCuad;
		stack_push(&PiladeSaltos, cont, 2);
	}
	
	void funcionWhileDos(){
		Cuadruplos *temp;
		char* aux;
		int resultado;
		
		aux = static_cast<char*>(PiladeTipos->ptr);
		if(strcmp(aux, (char *) "booleano") == 0){
			resultado = *static_cast<int*>(stack_pop(&PilaOperandos)->ptr);
			temp = addCuad(&cuadruplo, 140, resultado, -1, -1);
			contadorCuad++;
			stack_push(&PiladeSaltosCuad, temp, 2);
		}
	}
	
	void funcionWhileTres(){
		Cuadruplos *temp;
		int retorno;
		
		temp = static_cast<Cuadruplos*>(stack_pop(&PiladeSaltosCuad)->ptr);
		retorno = *static_cast<int*>(stack_pop(&PiladeSaltos)->ptr);
		addCuad(&cuadruplo, 130, -1, -1, retorno+1);
		contadorCuad++;
		temp->temporal = contadorCuad+1;
	}

	void funcionParaUno() {
		int *cont = (int *)malloc(sizeof(int));
		*cont = contadorCuad;
		stack_push(&PiladeSaltos, cont, 2);
	}

	void funcionParaDos() {
		Cuadruplos *temp;
		char* aux;
		int resultado;
		
		aux = static_cast<char*>(PiladeTipos->ptr);
		if(strcmp(aux, (char *) "booleano") == 0){
			resultado = *static_cast<int*>(stack_pop(&PilaOperandos)->ptr);
			temp = addCuad(&cuadruplo, 140, resultado, -1, -1);
			contadorCuad++;
			stack_push(&PiladeSaltosCuad, temp, 2);

			temp = addCuad(&cuadruplo, 130, -1, -1, -1);
			contadorCuad++;
			stack_push(&PiladeSaltosCuad, temp, 2);

			
			int *cont = (int *)malloc(sizeof(int));
			*cont = contadorCuad;
			stack_push(&PiladeSaltos, cont, 2);
		}
	}

	void funcionParaTres() {
		Cuadruplos *temp;
		Cuadruplos *temp2;

		temp = addCuad(&cuadruplo, 130, -1, -1, -1);
		contadorCuad++;
		temp2 = static_cast<Cuadruplos*>(stack_pop(&PiladeSaltosCuad)->ptr);
		temp2->temporal = contadorCuad+1;
		stack_push(&PiladeSaltosCuad, temp, 2);
	}

	void funcionParaCuatro() {
		int retorno;
		Cuadruplos *temp;

		retorno = *static_cast<int*>(stack_pop(&PiladeSaltos)->ptr);
		addCuad(&cuadruplo, 130, -1, -1, retorno+1);
		contadorCuad++;
		temp = static_cast<Cuadruplos*>(stack_pop(&PiladeSaltosCuad)->ptr);
		retorno = *static_cast<int*>(stack_pop(&PiladeSaltos)->ptr);
		temp->temporal = retorno+1;
		temp = static_cast<Cuadruplos*>(stack_pop(&PiladeSaltosCuad)->ptr);
		temp->temporal = contadorCuad+1;
	}
	


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 382 "sintaxis.y"
{
    char *str;
}
/* Line 193 of yacc.c.  */
#line 556 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 569 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNRULES -- Number of states.  */
#define YYNSTATES  183

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,     6,    16,    19,    20,    23,
      24,    25,    32,    36,    37,    39,    41,    43,    45,    47,
      51,    54,    55,    57,    59,    61,    63,    65,    67,    68,
      69,    76,    77,    87,    88,    92,    93,    99,   102,   105,
     106,   112,   113,   114,   122,   123,   124,   125,   137,   146,
     149,   150,   155,   159,   160,   163,   164,   165,   169,   172,
     173,   174,   177,   178,   181,   182,   185,   186,   189,   190,
     194,   195,   196,   201,   202,   203,   208,   209,   212,   213,
     214,   219,   220,   221,   226,   227,   228,   232,   233,   234,
     239,   240,   241,   246,   247,   248,   253,   256,   258,   260,
     261,   263,   265,   267,   269,   271,   273,   275,   276,   280,
     284,   288,   289,   292,   295
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    -1,    -1,    -1,     3,    45,    27,    46,
      33,    47,    48,    54,    49,    -1,    50,    48,    -1,    -1,
      75,    49,    -1,    -1,    -1,     4,    53,    52,    27,    51,
      33,    -1,    36,    28,    37,    -1,    -1,     5,    -1,     6,
      -1,     8,    -1,     7,    -1,     9,    -1,    18,    55,    19,
      -1,    56,    55,    -1,    -1,    57,    -1,    60,    -1,    64,
      -1,    67,    -1,    68,    -1,    71,    -1,    -1,    -1,    27,
      58,    38,    59,    80,    33,    -1,    -1,    14,    34,    80,
      35,    61,    18,    55,    62,    19,    -1,    -1,    15,    63,
      55,    -1,    -1,    12,    34,    65,    35,    33,    -1,    80,
      66,    -1,    32,    65,    -1,    -1,    13,    34,   112,    35,
      33,    -1,    -1,    -1,    20,    69,    34,    80,    35,    70,
      54,    -1,    -1,    -1,    -1,    21,    34,    57,    72,    80,
      33,    73,    57,    74,    35,    54,    -1,    22,    53,    27,
      34,    77,    35,    76,    54,    -1,    50,    76,    -1,    -1,
      53,    78,    27,    79,    -1,    36,    80,    37,    -1,    -1,
      32,    77,    -1,    -1,    -1,    88,    81,    82,    -1,    83,
      88,    -1,    -1,    -1,    84,    24,    -1,    -1,    85,    25,
      -1,    -1,    86,    26,    -1,    -1,    87,    23,    -1,    -1,
      95,    89,    90,    -1,    -1,    -1,    91,    16,    92,    88,
      -1,    -1,    -1,    93,    17,    94,    88,    -1,    -1,   101,
      96,    -1,    -1,    -1,    97,    39,    98,    95,    -1,    -1,
      -1,    99,    40,   100,    95,    -1,    -1,    -1,   108,   102,
     103,    -1,    -1,    -1,   104,    41,   105,   101,    -1,    -1,
      -1,   106,    42,   107,   101,    -1,    -1,    -1,    34,   109,
      80,    35,    -1,   110,   111,    -1,    39,    -1,    40,    -1,
      -1,    28,    -1,    29,    -1,    30,    -1,    31,    -1,    10,
      -1,    11,    -1,   112,    -1,    -1,    27,   113,   114,    -1,
      34,   115,    35,    -1,    36,    80,    37,    -1,    -1,    80,
     116,    -1,    32,   115,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   391,   391,   391,   391,   391,   392,   393,   394,   395,
     397,   397,   398,   399,   401,   401,   401,   401,   401,   403,
     404,   405,   407,   407,   407,   407,   407,   407,   409,   409,
     409,   411,   411,   412,   412,   413,   415,   416,   417,   418,
     420,   422,   422,   422,   424,   424,   424,   424,   426,   427,
     428,   430,   431,   432,   433,   434,   436,   436,   437,   438,
     439,   439,   440,   440,   441,   441,   442,   442,   444,   444,
     445,   445,   445,   446,   446,   446,   447,   449,   450,   450,
     450,   451,   451,   451,   452,   454,   454,   455,   455,   455,
     456,   456,   456,   457,   459,   459,   460,   461,   461,   462,
     464,   464,   464,   464,   464,   464,   465,   467,   467,   468,
     469,   470,   471,   472,   473
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAMA", "VAR", "NUMERO", "DECIMAL",
  "TEXTO", "CARACTER", "BOOLEANO", "TRUE", "FALSE", "IMPRIME", "LEE", "SI",
  "SINO", "Y", "O", "REALIZA", "FIN", "MIENTRAS", "PARA", "FUNC", "IGUAL",
  "MAYOR", "MENOR", "DIFERENTE", "ID", "CTENUM", "CTEDEC", "CTEX", "CCAR",
  "COMA", "PCOMA", "ABREPA", "CIERRAPA", "ABRECORCH", "CIERRACORCH",
  "SIGUAL", "MAS", "MENOS", "POR", "ENTRE", "$accept", "program", "@1",
  "@2", "@3", "program1", "program2", "vars", "@4", "vars1", "tipo",
  "bloque", "bloque1", "estatuto", "asignacion", "@5", "@6", "condicion",
  "@7", "condicion1", "@8", "escritura", "escritura1", "escritura2",
  "lectura", "mientras", "@9", "@10", "para", "@11", "@12", "@13", "func",
  "func1", "params", "params1", "params2", "expresion", "@14",
  "expresion1", "expresion2", "@15", "@16", "@17", "@18", "cond", "@19",
  "cond1", "@20", "@21", "@22", "@23", "exp", "exp1", "@24", "@25", "@26",
  "@27", "termino", "@28", "termino1", "@29", "@30", "@31", "@32",
  "factor", "@33", "factor1", "varcte", "variable", "@34", "variable1",
  "variable2", "variable3", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    45,    46,    47,    44,    48,    48,    49,    49,
      51,    50,    52,    52,    53,    53,    53,    53,    53,    54,
      55,    55,    56,    56,    56,    56,    56,    56,    58,    59,
      57,    61,    60,    63,    62,    62,    64,    65,    66,    66,
      67,    69,    70,    68,    72,    73,    74,    71,    75,    76,
      76,    77,    78,    78,    79,    79,    81,    80,    82,    82,
      84,    83,    85,    83,    86,    83,    87,    83,    89,    88,
      91,    92,    90,    93,    94,    90,    90,    95,    97,    98,
      96,    99,   100,    96,    96,   102,   101,   104,   105,   103,
     106,   107,   103,   103,   109,   108,   108,   110,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   113,   112,   114,
     114,   114,   115,   116,   116
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     9,     2,     0,     2,     0,
       0,     6,     3,     0,     1,     1,     1,     1,     1,     3,
       2,     0,     1,     1,     1,     1,     1,     1,     0,     0,
       6,     0,     9,     0,     3,     0,     5,     2,     2,     0,
       5,     0,     0,     7,     0,     0,     0,    11,     8,     2,
       0,     4,     3,     0,     2,     0,     0,     3,     2,     0,
       0,     2,     0,     2,     0,     2,     0,     2,     0,     3,
       0,     0,     4,     0,     0,     4,     0,     2,     0,     0,
       4,     0,     0,     4,     0,     0,     3,     0,     0,     4,
       0,     0,     4,     0,     0,     4,     2,     1,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     3,
       3,     0,     2,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     3,     0,     4,     7,     0,
       0,     7,    14,    15,    17,    16,    18,    13,    21,     9,
       6,     0,     0,     0,     0,     0,    41,     0,    28,     0,
      21,    22,    23,    24,    25,    26,    27,     0,     5,     9,
       0,    10,    99,     0,    99,     0,     0,     0,    19,    20,
       0,     8,    12,     0,    94,    97,    98,     0,    39,    56,
      68,    84,    85,     0,   107,     0,     0,    99,    44,    29,
       0,    11,    99,     0,    99,    37,    59,    76,    77,     0,
       0,    93,   104,   105,   100,   101,   102,   103,    96,   106,
     111,     0,    31,     0,    99,    99,     0,     0,    36,    38,
      57,    99,     0,     0,     0,     0,    69,     0,     0,    79,
      82,    86,     0,     0,    99,    99,   108,    40,     0,    42,
       0,     0,    53,     0,    95,    58,    61,    63,    65,    67,
      71,    74,    99,    99,    88,    91,   114,     0,     0,    21,
       0,    45,    30,    99,     0,    50,    99,    99,    80,    83,
      99,    99,    99,   112,   109,   110,    35,    43,     0,     0,
      55,    50,     0,    72,    75,    89,    92,   113,    33,     0,
      46,    52,     0,    51,    49,    48,    21,    32,     0,    54,
      34,     0,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     8,    10,    38,    11,    53,    22,
     122,    19,    29,    30,    31,    47,    95,    32,   118,   169,
     176,    33,    57,    75,    34,    35,    45,   140,    36,    94,
     158,   178,    39,   162,   123,   144,   173,    58,    76,   100,
     101,   102,   103,   104,   105,    59,    77,   106,   107,   146,
     108,   147,    60,    78,    79,   132,    80,   133,    61,    81,
     111,   112,   150,   113,   151,    62,    72,    63,    88,    65,
      90,   116,   137,   153
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -140
static const yytype_int16 yypact[] =
{
       5,  -140,    11,    -8,  -140,  -140,    25,  -140,    40,    34,
      41,    40,  -140,  -140,  -140,  -140,  -140,    24,     0,    39,
    -140,    35,    37,    28,    32,    33,  -140,    36,  -140,    46,
       0,  -140,  -140,  -140,  -140,  -140,  -140,    34,  -140,    39,
      38,  -140,   -24,    42,   -24,    43,    44,    30,  -140,  -140,
      47,  -140,  -140,    45,  -140,  -140,  -140,    48,    49,  -140,
    -140,   -16,  -140,     7,  -140,    50,    51,   -24,  -140,  -140,
      53,  -140,   -24,    55,   -24,  -140,    31,    12,  -140,    52,
      54,   -10,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
     -27,    56,  -140,    57,   -24,   -24,    34,    58,  -140,  -140,
    -140,   -24,    60,    65,    69,    59,  -140,    63,    79,  -140,
    -140,  -140,    61,    62,   -24,   -24,  -140,  -140,    80,  -140,
      64,    66,    67,    70,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,   -24,   -24,  -140,  -140,    68,    71,    74,     0,
      41,  -140,  -140,   -24,    81,    40,   -24,   -24,  -140,  -140,
     -24,   -24,   -24,  -140,  -140,  -140,    92,  -140,    44,    75,
      82,    40,    41,  -140,  -140,  -140,  -140,  -140,  -140,    96,
    -140,  -140,    34,  -140,  -140,  -140,     0,  -140,    83,  -140,
    -140,    41,  -140
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,  -140,  -140,  -140,   105,    78,  -139,  -140,  -140,
      -4,  -136,   -30,  -140,   -45,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,     2,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,   -81,   -53,  -140,  -140,   -42,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,   -98,  -140,  -140,  -140,  -140,
    -140,  -140,   -86,  -140,  -140,  -140,  -140,  -140,  -100,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,    72,
    -140,  -140,   -32,  -140
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -91
static const yytype_int16 yytable[] =
{
      49,    68,    66,   125,   157,    17,   161,   114,     1,   115,
      54,     4,    23,    24,    25,    55,    56,    82,    83,     5,
      26,    27,   161,   -78,   -81,    93,   175,    28,   -70,   -73,
      97,   -87,   -90,    50,    64,    84,    85,    86,    87,    12,
      13,    14,    15,    16,     9,   182,   148,   149,   163,   164,
     165,   166,   120,   121,   -66,   -60,   -62,   -64,     7,    18,
      21,    37,    42,    40,    41,    48,    43,    44,    69,    64,
      46,    28,   136,   138,    70,    52,    99,    67,    71,   130,
     174,    74,   129,    73,   126,    91,    92,    96,    98,   117,
     127,   109,   119,   124,   110,   128,   131,   141,   139,   142,
     152,   159,   134,   143,   135,   145,   154,   168,   160,   156,
     136,   155,   171,   170,   172,   177,    20,    51,   181,   179,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180
};

static const yytype_int16 yycheck[] =
{
      30,    46,    44,   101,   140,     9,   145,    34,     3,    36,
      34,     0,    12,    13,    14,    39,    40,    10,    11,    27,
      20,    21,   161,    39,    40,    67,   162,    27,    16,    17,
      72,    41,    42,    37,    27,    28,    29,    30,    31,     5,
       6,     7,     8,     9,     4,   181,   132,   133,   146,   147,
     150,   151,    94,    95,    23,    24,    25,    26,    33,    18,
      36,    22,    34,    28,    27,    19,    34,    34,    38,    27,
      34,    27,   114,   115,    27,    37,    74,    34,    33,    16,
     161,    32,    23,    35,    24,    35,    35,    34,    33,    33,
      25,    39,    35,    35,    40,    26,    17,    33,    18,    33,
      32,   143,    41,    36,    42,    35,    35,    15,    27,   139,
     152,    37,    37,   158,    32,    19,    11,    39,    35,   172,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   176
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    44,    45,     0,    27,    46,    33,    47,     4,
      48,    50,     5,     6,     7,     8,     9,    53,    18,    54,
      48,    36,    52,    12,    13,    14,    20,    21,    27,    55,
      56,    57,    60,    64,    67,    68,    71,    22,    49,    75,
      28,    27,    34,    34,    34,    69,    34,    58,    19,    55,
      53,    49,    37,    51,    34,    39,    40,    65,    80,    88,
      95,   101,   108,   110,    27,   112,    80,    34,    57,    38,
      27,    33,   109,    35,    32,    66,    81,    89,    96,    97,
      99,   102,    10,    11,    28,    29,    30,    31,   111,   112,
     113,    35,    35,    80,    72,    59,    34,    80,    33,    65,
      82,    83,    84,    85,    86,    87,    90,    91,    93,    39,
      40,   103,   104,   106,    34,    36,   114,    33,    61,    35,
      80,    80,    53,    77,    35,    88,    24,    25,    26,    23,
      16,    17,    98,   100,    41,    42,    80,   115,    80,    18,
      70,    33,    33,    36,    78,    35,    92,    94,    95,    95,
     105,   107,    32,   116,    35,    37,    55,    54,    73,    80,
      27,    50,    76,    88,    88,   101,   101,   115,    15,    62,
      57,    37,    32,    79,    76,    54,    63,    19,    74,    77,
      55,    35,    54
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 391 "sintaxis.y"
    {variable_type = (char *)"NP"; tipo_func = (char *)"global"; }
    break;

  case 3:
#line 391 "sintaxis.y"
    { variable_name = yylval.str; last_func = variable_name; stack_push(&PilaEjecucion, variable_name, 1);}
    break;

  case 4:
#line 391 "sintaxis.y"
    { addProc(&dirProcsInit,variable_name,variable_type); }
    break;

  case 10:
#line 397 "sintaxis.y"
    { variable_name = yylval.str; }
    break;

  case 11:
#line 397 "sintaxis.y"
    {addLocalVariableToProc(&dirProcsInit,last_func,variable_name,variable_type,alloc_virtual_address(variable_type, tipo_func)); }
    break;

  case 14:
#line 401 "sintaxis.y"
    { variable_type = (char *)"numero"; }
    break;

  case 15:
#line 401 "sintaxis.y"
    { variable_type = (char *)"decimal"; }
    break;

  case 16:
#line 401 "sintaxis.y"
    { variable_type = (char *)"caracter"; }
    break;

  case 17:
#line 401 "sintaxis.y"
    { variable_type = (char *)"texto"; }
    break;

  case 18:
#line 401 "sintaxis.y"
    { variable_type = (char *)"booleano"; }
    break;

  case 28:
#line 409 "sintaxis.y"
    {meterAPilaOperandos(dirProcsInit, yylval.str, last_func);}
    break;

  case 29:
#line 409 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "120", 1);}
    break;

  case 30:
#line 409 "sintaxis.y"
    {funcionAsignacion();}
    break;

  case 31:
#line 411 "sintaxis.y"
    {funcionIfUno();}
    break;

  case 32:
#line 411 "sintaxis.y"
    {funcionIfTres();}
    break;

  case 33:
#line 412 "sintaxis.y"
    {funcionIfDos();}
    break;

  case 41:
#line 422 "sintaxis.y"
    {funcionWhileUno();}
    break;

  case 42:
#line 422 "sintaxis.y"
    {funcionWhileDos();}
    break;

  case 43:
#line 422 "sintaxis.y"
    {funcionWhileTres();}
    break;

  case 44:
#line 424 "sintaxis.y"
    { funcionParaUno(); }
    break;

  case 45:
#line 424 "sintaxis.y"
    { funcionParaDos(); }
    break;

  case 46:
#line 424 "sintaxis.y"
    { funcionParaTres(); }
    break;

  case 47:
#line 424 "sintaxis.y"
    { funcionParaCuatro(); }
    break;

  case 56:
#line 436 "sintaxis.y"
    {funcionOperaciones((char*)"80"); funcionOperaciones((char*)"90"); funcionOperaciones((char*)"100"); funcionOperaciones((char*)"110");}
    break;

  case 58:
#line 437 "sintaxis.y"
    {funcionOperaciones((char*)"80"); funcionOperaciones((char*)"90"); funcionOperaciones((char*)"100"); funcionOperaciones((char*)"110");}
    break;

  case 60:
#line 439 "sintaxis.y"
    {funcionOperaciones((char*)"80");}
    break;

  case 61:
#line 439 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "80", 1);}
    break;

  case 62:
#line 440 "sintaxis.y"
    {funcionOperaciones((char*)"90");}
    break;

  case 63:
#line 440 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "90", 1);}
    break;

  case 64:
#line 441 "sintaxis.y"
    {funcionOperaciones((char*)"100");}
    break;

  case 65:
#line 441 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "100", 1);}
    break;

  case 66:
#line 442 "sintaxis.y"
    {funcionOperaciones((char*)"110");}
    break;

  case 67:
#line 442 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "110", 1);}
    break;

  case 68:
#line 444 "sintaxis.y"
    {funcionOperaciones((char*)"60"); funcionOperaciones((char*)"70");}
    break;

  case 70:
#line 445 "sintaxis.y"
    {funcionOperaciones((char*)"60");}
    break;

  case 71:
#line 445 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "60", 1);}
    break;

  case 73:
#line 446 "sintaxis.y"
    {funcionOperaciones((char*)"70");}
    break;

  case 74:
#line 446 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "70", 1);}
    break;

  case 77:
#line 449 "sintaxis.y"
    {funcionOperaciones((char*)"10"); funcionOperaciones((char*)"20");}
    break;

  case 78:
#line 450 "sintaxis.y"
    {funcionOperaciones((char*)"10");}
    break;

  case 79:
#line 450 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "10", 1);}
    break;

  case 81:
#line 451 "sintaxis.y"
    {funcionOperaciones((char *)"20");}
    break;

  case 82:
#line 451 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "20", 1);}
    break;

  case 85:
#line 454 "sintaxis.y"
    {funcionOperaciones((char*)"30"); funcionOperaciones((char*)"40");}
    break;

  case 87:
#line 455 "sintaxis.y"
    {funcionOperaciones((char*)"30");}
    break;

  case 88:
#line 455 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "30", 1);}
    break;

  case 90:
#line 456 "sintaxis.y"
    {funcionOperaciones((char*)"40");}
    break;

  case 91:
#line 456 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "40", 1);}
    break;

  case 94:
#line 459 "sintaxis.y"
    {meterFondoFalso();}
    break;

  case 95:
#line 459 "sintaxis.y"
    {sacaFondoFalso();}
    break;

  case 97:
#line 461 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "10", 1);}
    break;

  case 98:
#line 461 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "20", 1);}
    break;

  case 100:
#line 464 "sintaxis.y"
    {meterConstanteAPilaOperandos((char *)"numero", yyval.str);}
    break;

  case 101:
#line 464 "sintaxis.y"
    {meterConstanteAPilaOperandos((char *)"decimal", yylval.str);}
    break;

  case 102:
#line 464 "sintaxis.y"
    {meterConstanteAPilaOperandos((char *)"texto", yyval.str);}
    break;

  case 103:
#line 464 "sintaxis.y"
    {meterConstanteAPilaOperandos((char *)"caracter", yyval.str);}
    break;

  case 107:
#line 467 "sintaxis.y"
    {meterAPilaOperandos(dirProcsInit, yylval.str, last_func);}
    break;


/* Line 1267 of yacc.c.  */
#line 2224 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 475 "sintaxis.y"


void yyerror(const char *s)  /* Llamada por yyparse ante un error */
{ 
  printf ("Error on line #%i: %s\n", yylineno, s);
  exit(-1);
}

main(int argc, char* argv[]) {
    if (argc == 2) {
        FILE *myfile = fopen(argv[1], "r");
        if (!myfile) {
            printf("Cant open file %s!\n", argv[1]);
            return -1;
        }
    
        yyin = myfile;
        initSemanticCube(&semanticCube);
    
        do {
            yyparse();
        } while (!feof(yyin));
        
        //debugList(dirProcsInit);
		imprimeListaConstantes(PilaConstantes);
		printf("#\n");
		imprimeCuad(cuadruplo);
		
        deallocSemanticCube(&semanticCube);
        deallocProcDir(&dirProcsInit);

    } else {
        printf("Invalid parameter count: %s <filename>\n", argv[0]);
    }
}

