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
     ENTRE = 297,
     RET = 298
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
#define RET 298




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
	StackConstantes *PilaConstantes; // Creamos la pila de constantes

	char *variable_type; // Tipo de la ultima variable conocida
    char *variable_name; // Nombre de la ultima variable conocida
    char *last_func; // Guarda el nombre de la ultima funcion utilizada
    char *tipo_func; // Guarda el tipo de retorno de la funcion declarada
	int contadorCuad = 0; // Guarda el contador de los cuadruplos
	int contadorK; // Guarda el contador de los parametros
	
	Cuadruplos *cuadruplo; // Crea el apuntador al primer pointer de los cuadruplos
    Node *dirProcsInit; // Crea el apuntador al primer pointer del dir procs
    SemanticCubeNode *semanticCube;; // Apuntador al primer nodo del cubo semantico
    
    // FUNCTION: alloc_virtual_address(char *returnType, char *scope)
	// RETURN: int
	//
	// Crea y regresa la direccion virtual para los diferentes tipos de variables
	//
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
	
	// FUNCTION: meterAPilaOperandos(Node *dirProcsInit, char* variable_name, char* last_func)
	// RETURN: void
	//
	// Funcion encargada de meter los ID's a la PilaOperandos
	//
	void meterAPilaOperandos(Node *dirProcsInit, char* variable_name, char* last_func){
		Node *tNode = dirProcsInit;
		Node *variableEncontrada = NULL;
		char *tipoVariable;
				
		variableEncontrada = findLocalVariableInProc(tNode, static_cast<char*>(PilaEjecucion->ptr),variable_name);
		
		tipoVariable = variableEncontrada->returnType;
		stack_push(&PilaOperandos, &variableEncontrada->virtual_address, 2);
		stack_push(&PiladeTipos, (findLocalVariableInProc(tNode, static_cast<char*>(PilaEjecucion->ptr),variable_name))->returnType, 1);
        
	}
	
	// FUNCTION: meterConstanteAPilaOperandos(char* tipo, char *constante)
	// RETURN: void
	//
	// Funcion encargada de meter las constantes a la PilaOperandos y PilaConstantes
	//
	void meterConstanteAPilaOperandos(char* tipo, char *constante){
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
			*direccion = alloc_virtual_address((char *)"texto",(char *) "constante");
			stack_push(&PilaOperandos, direccion, 2);
			stack_push(&PiladeTipos, (char *)"texto", 1);
			char *cons = (char *)malloc(sizeof(char *));
			cons = constante;
			stackC_push(&PilaConstantes, cons, *direccion, 1);
		}

		
	}
	
	// FUNCTION: meterFondoFalso()
	// RETURN: void
	//
	// Funcion encargada de meter el fondo falso a la pilaOperadores
	//
	void meterFondoFalso(){
		stack_push(&PilaOperadores, (char *) "-1", 1);
	}
	
	// FUNCTION: sacaFondoFalso()
	// RETURN: void
	//
	// Funcion encargada de sacar el fondo falso a la pilaOperadores
	//
	void sacaFondoFalso(){
		if(strcmp(static_cast<char*>(PilaOperadores->ptr), (char *) "-1") == 0){
			stack_pop(&PilaOperadores);
		}
	}
	
	// FUNCTION: funcionOperaciones(char* operador)
	// RETURN: void
	//
	// Funcion que se encarga de realizar la verificacion de la pilaOperadores para las expresiones y genera cuadruplos de expresiones
	//
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
	
	// FUNCTION: funcionAsignacion()
	// RETURN: void
	//
	// Funcion encargada de generar los cuadruplos para las asignaciones
	//
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
                printf("v: %i, %i\n",*static_cast<int*>(stack_pop(&PilaOperandos)->ptr),*static_cast<int*>(stack_pop(&PilaOperandos)->ptr));
				printf("Error Semantico: Tipos incopatibles %s,%s\n",tipo1,tipo2);
			} 
		}
	}
    
	// FUNCTION: funcionIfUno()
	// RETURN: void
	//
	// Funcion encargada de generar los cuadruplos para la expresion de la condicion del IF y el goToF
	//
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
	
	// FUNCTION: funcionIfDos()
	// RETURN: void
	//
	// Funcion encargada de generar el cuadruplos del goTo y rellenar el cuadruolo de goToF
	//
	void funcionIfDos(){
		Cuadruplos *falso;
		Cuadruplos *temp;
		
		temp = addCuad(&cuadruplo, 130, -1, -1, -1);
		contadorCuad++;
		falso = static_cast<Cuadruplos*>(stack_pop(&PiladeSaltosCuad)->ptr);
		falso->temporal = contadorCuad+1;
		stack_push(&PiladeSaltosCuad, temp, 2);
		
	}
	
	// FUNCTION: funcionIfTres()
	// RETURN: void
	//
	// Funcion encargada de generar el cuadruplo del goTo y rellenar el FIN 
	//
	void funcionIfTres(){
		Cuadruplos *temp;
		
		temp = static_cast<Cuadruplos*>(stack_pop(&PiladeSaltosCuad)->ptr);
		temp->temporal = contadorCuad+1;
	}
	
	// FUNCTION: funcionWhileUno()
	// RETURN: void
	//
	// Funcion encargada de meter el contador a la PiladeSaltos
	//
	void funcionWhileUno(){
		int *cont = (int *)malloc(sizeof(int));
		*cont = contadorCuad;
		stack_push(&PiladeSaltos, cont, 2);
	}
	
	// FUNCTION: funcionWhileDos()
	// RETURN: void
	//
	// Funcion encargada de generar los cuadruplos de goToF
	//
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
	
	// FUNCTION: funcionWhileTres()
	// RETURN: void
	//
	// Funcion encargada de generar el cuadruplo de goTo y rellenar el cuadruplo del goToF
	//
	void funcionWhileTres(){
		Cuadruplos *temp;
		int retorno;
		
		temp = static_cast<Cuadruplos*>(stack_pop(&PiladeSaltosCuad)->ptr);
		retorno = *static_cast<int*>(stack_pop(&PiladeSaltos)->ptr);
		addCuad(&cuadruplo, 130, -1, -1, retorno+1);
		contadorCuad++;
		temp->temporal = contadorCuad+1;
	}
	
	// FUNCTION: funcionParaUno()
	// RETURN: void
	//
	// 
	//
	void funcionParaUno() {
		int *cont = (int *)malloc(sizeof(int));
		*cont = contadorCuad;
		stack_push(&PiladeSaltos, cont, 2);
	}
	
	// FUNCTION: funcionParaDos()
	// RETURN: void
	//
	// 
	//
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
	
	// FUNCTION: funcionParaTres()
	// RETURN: void
	//
	// 
	//
	void funcionParaTres() {
		Cuadruplos *temp;
		Cuadruplos *temp2;

		temp = addCuad(&cuadruplo, 130, -1, -1, -1);
		contadorCuad++;
		temp2 = static_cast<Cuadruplos*>(stack_pop(&PiladeSaltosCuad)->ptr);
		temp2->temporal = contadorCuad+1;
		stack_push(&PiladeSaltosCuad, temp, 2);
	}
	
	// FUNCTION: funcionParaCuatro()
	// RETURN: void
	//
	// 
	//
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
    
	// FUNCTION: funcionLectura()
	// RETURN: void
	//
	// Funcion que se encarga de generar el cuadruplo para la funcion de Lectura
	//
    void funcionLectura() {
        addCuad(&cuadruplo, 200, -1, -1, *static_cast<int*>(stack_pop(&PilaOperandos)->ptr));
        contadorCuad++;
    }
	
	// FUNCTION: funcionEscritura()
	// RETURN: void
	//
	// Funcion que se encarga de generar el cuadruplo para la funcion de Escritura
	//
    void funcionEscritura() {
        addCuad(&cuadruplo, 190, -1, -1, *static_cast<int*>(stack_pop(&PilaOperandos)->ptr));
        contadorCuad++;
    }
    
	// FUNCTION: funcionEscrituraFin()
	// RETURN: void
	//
	// Funcion que se encarga de generar el cuadruplo para la escribir un println
	//
    void funcionEscrituraFin() {
        addCuad(&cuadruplo, 210, -1, -1, -1);
        contadorCuad++;
    }
    
    void funcReturnUno() {
        addCuad(&cuadruplo, 240, *static_cast<int*>(PilaOperandos->ptr), -1, -1);
        contadorCuad++;
    }
    
    void funcionFuncionesUno(char* funcion) {
		Node *tNode = findProc(dirProcsInit, funcion);
		
		if(tNode != NULL){
			tNode->virtual_address = alloc_virtual_address(tNode->returnType,(char *)"global");
        }
    }
	
	// FUNCTION: agregaParam(char* proc_name, char* tipoParam)
	// RETURN: void
	//
	// Funcion que se encarga de agregar un nuevo parametro en un procedimiento 
	//
	void agregaParam(char* proc_name, char* tipoParam){
		Node *tNode = findProc(dirProcsInit, proc_name);
		addParameter(&tNode->apunta, tipoParam);
		tNode->numeroCuadruplo = contadorCuad;
	}
	
	// FUNCTION: eliminaTabla(char* funcion)
	// RETURN: void
	//
	// Funcion que se encarga de eliminar la tabla de variables al momento de terminar la declaracion de la funcion y genera el cuadruplo de Retorno
	//
	void eliminaTabla(char* funcion){
		Node *tNode = findProc(dirProcsInit, funcion);
		
		if(tNode != NULL){
			addCuad(&cuadruplo, 180, -1, -1, -1);
			contadorCuad++;
		}
	}
	
	// FUNCTION: generaEra(char* proc_name)
	// RETURN: void
	//
	// Funcion que se encarga de generar el cuadruplo de Era al momento de mandar llamar a una funcion
	//
	void generaEra(char* proc_name){
		Node *tNode = findProc(dirProcsInit, proc_name);
		int cont;
        
		if(tNode != NULL){
			cont = findProcPos(dirProcsInit, proc_name);
			addCuad(&cuadruplo, 170, cont, -1, -1);
			contadorCuad++;
		}
        
	}
	
	// FUNCTION: generaParametro(char* proc_name)
	// RETURN: void
	//
	// Funcion que se encarga de generar el cuadruplo de los parametros mandados
	//
	void generaParametros(char* proc_name){
		int argumento;
		char* tipoArg;
		Node *tNode = findProc(dirProcsInit, proc_name);

        for(int i = 1; i <= contadorK; i++) {
            argumento = *static_cast<int*>(stack_pop(&PilaOperandos)->ptr);
            tipoArg = static_cast<char*>(stack_pop(&PiladeTipos)->ptr);

        // No checa si queda con el tipo que manda
		//if(strcmp(tipoArg, tNode->apunta->tipo) == 0){
            addCuad(&cuadruplo, 230, argumento, -1, i);
            contadorCuad++;
		//}
        }
            
        stack_push(&PilaOperandos, &(tNode->virtual_address), 2);
        stack_push(&PiladeTipos, tNode->returnType, 0);
	}
    
    // FUNCTION: generaCuadPrincipal()
    // RETURN: void
    //
    // Genera el cuadruplo de salto al main al inicio de la lista de cuadruplos
    // y la guarda en el stack
    //
    void generaCuadPrincipal() {
        Cuadruplos *temp;
        temp = addCuad(&cuadruplo, 130, -1, -1, -1);
        contadorCuad++;
        stack_push(&PiladeSaltosCuad, temp, 2);
    }
    
    void addSaltoAlPrincipal() {
        Cuadruplos *temp;
        
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
#line 598 "sintaxis.y"
{
    char *str;
}
/* Line 193 of yacc.c.  */
#line 774 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 787 "y.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  86
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNRULES -- Number of states.  */
#define YYNSTATES  203

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,     6,     7,    18,    21,    22,
      25,    26,    27,    34,    38,    39,    41,    43,    45,    47,
      49,    53,    56,    57,    59,    61,    63,    65,    67,    69,
      72,    73,    74,    81,    82,    92,    93,    97,    98,    99,
     106,   107,   111,   114,   115,   116,   123,   124,   125,   133,
     134,   135,   136,   148,   149,   150,   164,   165,   166,   172,
     173,   176,   177,   180,   181,   182,   189,   190,   191,   197,
     198,   202,   203,   206,   207,   208,   212,   215,   216,   217,
     220,   221,   224,   225,   228,   229,   232,   233,   237,   238,
     239,   244,   245,   246,   251,   252,   255,   256,   257,   262,
     263,   264,   269,   270,   271,   275,   276,   277,   282,   283,
     284,   289,   290,   291,   296,   299,   301,   303,   304,   306,
     308,   310,   312,   314,   316,   318,   320,   321,   325,   329
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      45,     0,    -1,    -1,    -1,    -1,    -1,    46,    51,     3,
      47,    27,    48,    33,    49,    50,    56,    -1,    52,    50,
      -1,    -1,    80,    51,    -1,    -1,    -1,     4,    55,    54,
      27,    53,    33,    -1,    36,    28,    37,    -1,    -1,     5,
      -1,     6,    -1,     8,    -1,     7,    -1,     9,    -1,    18,
      57,    19,    -1,    58,    57,    -1,    -1,    59,    -1,    62,
      -1,    66,    -1,    71,    -1,    73,    -1,    76,    -1,    90,
      33,    -1,    -1,    -1,    27,    60,    38,    61,    95,    33,
      -1,    -1,    14,    34,    95,    35,    63,    18,    57,    64,
      19,    -1,    -1,    15,    65,    57,    -1,    -1,    -1,    12,
      34,    68,    35,    67,    33,    -1,    -1,    95,    69,    70,
      -1,    32,    68,    -1,    -1,    -1,    13,    34,   127,    72,
      35,    33,    -1,    -1,    -1,    20,    74,    34,    95,    35,
      75,    56,    -1,    -1,    -1,    -1,    21,    34,    59,    77,
      95,    33,    78,    59,    79,    35,    56,    -1,    -1,    -1,
      22,    81,    55,    27,    82,    34,    83,    35,    87,    18,
      57,    88,    19,    -1,    -1,    -1,    55,    84,    27,    85,
      86,    -1,    -1,    32,    83,    -1,    -1,    52,    87,    -1,
      -1,    -1,    43,    34,   110,    89,    35,    33,    -1,    -1,
      -1,    27,    91,    34,    92,    35,    -1,    -1,   110,    93,
      94,    -1,    -1,    32,    92,    -1,    -1,    -1,   103,    96,
      97,    -1,    98,   103,    -1,    -1,    -1,    99,    24,    -1,
      -1,   100,    25,    -1,    -1,   101,    26,    -1,    -1,   102,
      23,    -1,    -1,   110,   104,   105,    -1,    -1,    -1,   106,
      16,   107,   103,    -1,    -1,    -1,   108,    17,   109,   103,
      -1,    -1,   116,   111,    -1,    -1,    -1,   112,    39,   113,
     110,    -1,    -1,    -1,   114,    40,   115,   110,    -1,    -1,
      -1,   123,   117,   118,    -1,    -1,    -1,   119,    41,   120,
     116,    -1,    -1,    -1,   121,    42,   122,   116,    -1,    -1,
      -1,    34,   124,    95,    35,    -1,   125,   126,    -1,    39,
      -1,    40,    -1,    -1,    28,    -1,    29,    -1,    30,    -1,
      31,    -1,    10,    -1,    11,    -1,   127,    -1,    90,    -1,
      -1,    27,   128,   129,    -1,    36,    95,    37,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   607,   607,   607,   607,   607,   607,   608,   609,   610,
     611,   613,   613,   614,   615,   617,   617,   617,   617,   617,
     619,   620,   621,   623,   623,   623,   623,   623,   623,   623,
     625,   625,   625,   627,   627,   628,   628,   629,   631,   631,
     632,   632,   633,   634,   636,   636,   638,   638,   638,   640,
     640,   640,   640,   642,   642,   642,   643,   643,   643,   644,
     645,   646,   647,   648,   649,   649,   650,   652,   652,   653,
     653,   654,   655,   656,   658,   658,   659,   660,   661,   661,
     662,   662,   663,   663,   664,   664,   666,   666,   667,   667,
     667,   668,   668,   668,   669,   671,   672,   672,   672,   673,
     673,   673,   674,   676,   676,   677,   677,   677,   678,   678,
     678,   679,   681,   681,   682,   683,   683,   684,   686,   686,
     686,   686,   686,   686,   687,   688,   690,   690,   691,   692
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
  "SIGUAL", "MAS", "MENOS", "POR", "ENTRE", "RET", "$accept", "program",
  "@1", "@2", "@3", "@4", "program1", "program2", "vars", "@5", "vars1",
  "tipo", "bloque", "bloque1", "estatuto", "asignacion", "@6", "@7",
  "condicion", "@8", "condicion1", "@9", "escritura", "@10", "escritura1",
  "@11", "escritura2", "lectura", "@12", "mientras", "@13", "@14", "para",
  "@15", "@16", "@17", "func", "@18", "@19", "func1", "@20", "@21",
  "func2", "varsfunc", "funcret", "@22", "llamada", "@23", "llamada2",
  "@24", "llamada3", "expresion", "@25", "expresion1", "expresion2", "@26",
  "@27", "@28", "@29", "cond", "@30", "cond1", "@31", "@32", "@33", "@34",
  "exp", "exp1", "@35", "@36", "@37", "@38", "termino", "@39", "termino1",
  "@40", "@41", "@42", "@43", "factor", "@44", "factor1", "varcte",
  "variable", "@45", "variable1", 0
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
     295,   296,   297,   298
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    46,    47,    48,    49,    45,    50,    50,    51,
      51,    53,    52,    54,    54,    55,    55,    55,    55,    55,
      56,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      60,    61,    59,    63,    62,    65,    64,    64,    67,    66,
      69,    68,    70,    70,    72,    71,    74,    75,    73,    77,
      78,    79,    76,    81,    82,    80,    84,    85,    83,    83,
      86,    86,    87,    87,    89,    88,    88,    91,    90,    93,
      92,    92,    94,    94,    96,    95,    97,    97,    99,    98,
     100,    98,   101,    98,   102,    98,   104,   103,   106,   107,
     105,   108,   109,   105,   105,   110,   112,   113,   111,   114,
     115,   111,   111,   117,   116,   119,   120,   118,   121,   122,
     118,   118,   124,   123,   123,   125,   125,   125,   126,   126,
     126,   126,   126,   126,   126,   126,   128,   127,   129,   129
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,    10,     2,     0,     2,
       0,     0,     6,     3,     0,     1,     1,     1,     1,     1,
       3,     2,     0,     1,     1,     1,     1,     1,     1,     2,
       0,     0,     6,     0,     9,     0,     3,     0,     0,     6,
       0,     3,     2,     0,     0,     6,     0,     0,     7,     0,
       0,     0,    11,     0,     0,    13,     0,     0,     5,     0,
       2,     0,     2,     0,     0,     6,     0,     0,     5,     0,
       3,     0,     2,     0,     0,     3,     2,     0,     0,     2,
       0,     2,     0,     2,     0,     2,     0,     3,     0,     0,
       4,     0,     0,     4,     0,     2,     0,     0,     4,     0,
       0,     4,     0,     0,     3,     0,     0,     4,     0,     0,
       4,     0,     0,     4,     2,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     3,     3,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    10,     1,    53,     0,    10,     0,     3,     9,
      15,    16,    18,    17,    19,     0,     0,    54,     4,     0,
       0,    59,     5,    56,     0,     8,     0,    63,     0,     0,
       8,    57,    63,     0,    14,    22,     6,     7,    61,    62,
      22,     0,     0,     0,     0,     0,    46,     0,    30,     0,
      22,    23,    24,    25,    26,    27,    28,     0,    59,    58,
      66,     0,    11,   117,     0,   117,     0,     0,     0,     0,
      20,    21,    29,    60,     0,     0,    13,     0,   112,   115,
     116,     0,    40,    74,    86,   102,   103,     0,   126,    44,
       0,   117,    30,    49,    31,   117,   117,    55,    12,   117,
      38,    43,    77,    94,    95,     0,     0,   111,   122,   123,
     126,   118,   119,   120,   121,   125,   114,   124,   129,     0,
      33,     0,   117,   117,     0,    69,    64,     0,     0,   117,
      41,    75,   117,     0,     0,     0,     0,    87,     0,     0,
      97,   100,   104,     0,     0,   117,   127,     0,     0,    47,
       0,     0,    68,    73,     0,   113,    39,    42,    76,    79,
      81,    83,    85,    89,    92,   117,   117,   106,   109,     0,
      45,    22,     0,    50,    32,   117,    70,     0,   117,   117,
      98,   101,   117,   117,   128,    37,    48,     0,    72,    65,
      90,    93,   107,   110,    35,     0,    51,    22,    34,     0,
      36,     0,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    16,    20,    25,    29,     5,    30,    77,
      42,    23,    36,    49,    50,    51,    68,   123,    52,   148,
     195,   197,    53,   128,    81,   101,   130,    54,   119,    55,
      66,   172,    56,   122,   187,   199,     6,     7,    19,    24,
      26,    38,    59,    33,    75,   154,    57,    69,   124,   153,
     176,    82,   102,   131,   132,   133,   134,   135,   136,    83,
     103,   137,   138,   178,   139,   179,    84,   104,   105,   165,
     106,   166,    85,   107,   142,   143,   182,   144,   183,    86,
      99,    87,   116,    89,   118,   146
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -167
static const yytype_int16 yypact[] =
{
    -167,    11,   -13,  -167,  -167,    15,   -13,    36,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,     0,    23,  -167,  -167,    24,
       1,    36,  -167,  -167,    28,    60,    38,    60,    36,    48,
      60,  -167,    60,    49,    32,    26,  -167,  -167,    37,  -167,
      26,    42,    44,    41,    43,    45,  -167,    46,    47,    53,
      26,  -167,  -167,  -167,  -167,  -167,  -167,    51,    36,  -167,
      33,    50,  -167,   -17,    58,   -17,    52,    61,    40,    55,
    -167,  -167,  -167,  -167,    56,    72,  -167,    59,  -167,  -167,
    -167,    62,  -167,  -167,  -167,   -32,  -167,     2,  -167,  -167,
      63,   -17,  -167,  -167,  -167,   -20,   -17,  -167,  -167,   -17,
    -167,    64,    31,     8,  -167,    54,    65,     7,  -167,  -167,
      47,  -167,  -167,  -167,  -167,  -167,  -167,  -167,    66,    68,
    -167,    69,   -17,   -17,    71,  -167,  -167,    73,    67,   -17,
    -167,  -167,   -17,    70,    74,    75,    84,  -167,    79,    92,
    -167,  -167,  -167,    76,    77,   -17,  -167,    78,    94,  -167,
      80,    81,  -167,    83,    85,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,   -17,   -17,  -167,  -167,    86,
    -167,    26,    48,  -167,  -167,   -20,  -167,    89,   -17,   -17,
    -167,  -167,   -17,   -17,  -167,    95,  -167,    61,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,    97,  -167,    26,  -167,    90,
    -167,    48,  -167
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,  -167,  -167,  -167,  -167,    88,   118,    -6,  -167,
    -167,     9,  -166,   -40,  -167,   -66,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,    -3,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,    82,
    -167,  -167,  -167,    96,  -167,  -167,    57,  -167,   -48,  -167,
    -167,   -63,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -127,
    -167,  -167,  -167,  -167,  -167,  -167,   -92,  -167,  -167,  -167,
    -167,  -167,  -121,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,    87,  -167,  -167
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -109
static const yytype_int16 yytable[] =
{
      60,    93,    90,   125,   126,   158,   186,   -96,   -99,     4,
      71,     3,   108,   109,    78,   -71,    15,    78,     8,    79,
      80,    32,    79,    80,   -88,   -91,    32,    17,   121,   110,
     111,   112,   113,   114,    22,   202,   127,    34,    43,    44,
      45,    10,    11,    12,    13,    14,    46,    47,  -105,  -108,
      18,   190,   191,    48,   -84,   -78,   -80,   -82,    21,   150,
     151,   192,   193,    27,    28,    31,    35,    40,    41,    58,
      61,    62,    70,   180,   181,    63,    74,    64,    94,    65,
      67,   -67,   169,   125,    72,    88,    91,    76,    92,    95,
      96,    97,    98,   140,   159,   163,   129,   100,   120,   160,
     156,   161,   145,   147,   149,   141,   152,   162,   155,   164,
     194,   170,   171,   173,   174,   175,   198,   167,    37,   168,
     177,   196,   189,   184,     9,   201,   157,   188,    39,     0,
       0,   185,     0,     0,     0,     0,     0,     0,     0,     0,
      73,     0,     0,     0,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117
};

static const yytype_int16 yycheck[] =
{
      40,    67,    65,    95,    96,   132,   172,    39,    40,    22,
      50,     0,    10,    11,    34,    35,     7,    34,     3,    39,
      40,    27,    39,    40,    16,    17,    32,    27,    91,    27,
      28,    29,    30,    31,    33,   201,    99,    28,    12,    13,
      14,     5,     6,     7,     8,     9,    20,    21,    41,    42,
      27,   178,   179,    27,    23,    24,    25,    26,    34,   122,
     123,   182,   183,    35,     4,    27,    18,    18,    36,    32,
      28,    27,    19,   165,   166,    34,    43,    34,    38,    34,
      34,    34,   145,   175,    33,    27,    34,    37,    27,    34,
      34,    19,    33,    39,    24,    16,    32,    35,    35,    25,
      33,    26,    36,    35,    35,    40,    35,    23,    35,    17,
      15,    33,    18,    33,    33,    32,    19,    41,    30,    42,
      35,   187,    33,    37,     6,    35,   129,   175,    32,    -1,
      -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,     0,    22,    51,    80,    81,     3,    51,
       5,     6,     7,     8,     9,    55,    47,    27,    27,    82,
      48,    34,    33,    55,    83,    49,    84,    35,     4,    50,
      52,    27,    52,    87,    55,    18,    56,    50,    85,    87,
      18,    36,    54,    12,    13,    14,    20,    21,    27,    57,
      58,    59,    62,    66,    71,    73,    76,    90,    32,    86,
      57,    28,    27,    34,    34,    34,    74,    34,    60,    91,
      19,    57,    33,    83,    43,    88,    37,    53,    34,    39,
      40,    68,    95,   103,   110,   116,   123,   125,    27,   127,
      95,    34,    27,    59,    38,    34,    34,    19,    33,   124,
      35,    69,    96,   104,   111,   112,   114,   117,    10,    11,
      27,    28,    29,    30,    31,    90,   126,   127,   128,    72,
      35,    95,    77,    61,    92,   110,   110,    95,    67,    32,
      70,    97,    98,    99,   100,   101,   102,   105,   106,   108,
      39,    40,   118,   119,   121,    36,   129,    35,    63,    35,
      95,    95,    35,    93,    89,    35,    33,    68,   103,    24,
      25,    26,    23,    16,    17,   113,   115,    41,    42,    95,
      33,    18,    75,    33,    33,    32,    94,    35,   107,   109,
     110,   110,   120,   122,    37,    57,    56,    78,    92,    33,
     103,   103,   116,   116,    15,    64,    59,    65,    19,    79,
      57,    35,    56
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
#line 607 "sintaxis.y"
    { generaCuadPrincipal(); }
    break;

  case 3:
#line 607 "sintaxis.y"
    {variable_type = (char *)"NP"; tipo_func = (char *)"global"; }
    break;

  case 4:
#line 607 "sintaxis.y"
    { variable_name = yylval.str; last_func = variable_name; stack_push(&PilaEjecucion, variable_name, 1);}
    break;

  case 5:
#line 607 "sintaxis.y"
    { addProc(&dirProcsInit,variable_name,variable_type); addSaltoAlPrincipal();}
    break;

  case 6:
#line 607 "sintaxis.y"
    {addCuad(&cuadruplo, 220, -1, -1, -1); contadorCuad++;}
    break;

  case 11:
#line 613 "sintaxis.y"
    { variable_name = yylval.str; }
    break;

  case 12:
#line 613 "sintaxis.y"
    {addLocalVariableToProc(&dirProcsInit,last_func,variable_name,variable_type,alloc_virtual_address(variable_type, tipo_func)); }
    break;

  case 15:
#line 617 "sintaxis.y"
    { variable_type = (char *)"numero"; }
    break;

  case 16:
#line 617 "sintaxis.y"
    { variable_type = (char *)"decimal"; }
    break;

  case 17:
#line 617 "sintaxis.y"
    { variable_type = (char *)"caracter"; }
    break;

  case 18:
#line 617 "sintaxis.y"
    { variable_type = (char *)"texto"; }
    break;

  case 19:
#line 617 "sintaxis.y"
    { variable_type = (char *)"booleano"; }
    break;

  case 30:
#line 625 "sintaxis.y"
    {meterAPilaOperandos(dirProcsInit, yylval.str, last_func); }
    break;

  case 31:
#line 625 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "120", 1);}
    break;

  case 32:
#line 625 "sintaxis.y"
    {funcionAsignacion();}
    break;

  case 33:
#line 627 "sintaxis.y"
    {funcionIfUno();}
    break;

  case 34:
#line 627 "sintaxis.y"
    {funcionIfTres();}
    break;

  case 35:
#line 628 "sintaxis.y"
    {funcionIfDos();}
    break;

  case 38:
#line 631 "sintaxis.y"
    { funcionEscrituraFin(); }
    break;

  case 40:
#line 632 "sintaxis.y"
    { funcionEscritura(); }
    break;

  case 44:
#line 636 "sintaxis.y"
    { funcionLectura(); }
    break;

  case 46:
#line 638 "sintaxis.y"
    {funcionWhileUno();}
    break;

  case 47:
#line 638 "sintaxis.y"
    {funcionWhileDos();}
    break;

  case 48:
#line 638 "sintaxis.y"
    {funcionWhileTres();}
    break;

  case 49:
#line 640 "sintaxis.y"
    { funcionParaUno(); }
    break;

  case 50:
#line 640 "sintaxis.y"
    { funcionParaDos(); }
    break;

  case 51:
#line 640 "sintaxis.y"
    { funcionParaTres(); }
    break;

  case 52:
#line 640 "sintaxis.y"
    { funcionParaCuatro(); }
    break;

  case 53:
#line 642 "sintaxis.y"
    {tipo_func = (char *)"local";}
    break;

  case 54:
#line 642 "sintaxis.y"
    {last_func = yylval.str; stack_push(&PilaEjecucion, last_func, 1); addProc(&dirProcsInit, last_func, variable_type);funcionFuncionesUno(last_func); }
    break;

  case 55:
#line 642 "sintaxis.y"
    {eliminaTabla(last_func);}
    break;

  case 56:
#line 643 "sintaxis.y"
    {agregaParam(static_cast<char*>(PilaEjecucion->ptr), variable_type);}
    break;

  case 57:
#line 643 "sintaxis.y"
    {variable_name = yylval.str; addLocalVariableToProc(&dirProcsInit, static_cast<char*>(PilaEjecucion->ptr), variable_name, variable_type, alloc_virtual_address(variable_type, (char *)"local"));}
    break;

  case 64:
#line 649 "sintaxis.y"
    { funcReturnUno(); }
    break;

  case 67:
#line 652 "sintaxis.y"
    { last_func = yylval.str; contadorK = 0; }
    break;

  case 68:
#line 652 "sintaxis.y"
    { generaEra(last_func); generaParametros(last_func); addCuad(&cuadruplo, 160, findProcPos(dirProcsInit, last_func), -1, -1); contadorCuad++; }
    break;

  case 69:
#line 653 "sintaxis.y"
    { contadorK++; }
    break;

  case 74:
#line 658 "sintaxis.y"
    {funcionOperaciones((char*)"80"); funcionOperaciones((char*)"90"); funcionOperaciones((char*)"100"); funcionOperaciones((char*)"110");}
    break;

  case 76:
#line 659 "sintaxis.y"
    {funcionOperaciones((char*)"80"); funcionOperaciones((char*)"90"); funcionOperaciones((char*)"100"); funcionOperaciones((char*)"110");}
    break;

  case 78:
#line 661 "sintaxis.y"
    {funcionOperaciones((char*)"80");}
    break;

  case 79:
#line 661 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "80", 1);}
    break;

  case 80:
#line 662 "sintaxis.y"
    {funcionOperaciones((char*)"90");}
    break;

  case 81:
#line 662 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "90", 1);}
    break;

  case 82:
#line 663 "sintaxis.y"
    {funcionOperaciones((char*)"100");}
    break;

  case 83:
#line 663 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "100", 1);}
    break;

  case 84:
#line 664 "sintaxis.y"
    {funcionOperaciones((char*)"110");}
    break;

  case 85:
#line 664 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "110", 1);}
    break;

  case 86:
#line 666 "sintaxis.y"
    {funcionOperaciones((char*)"60"); funcionOperaciones((char*)"70");}
    break;

  case 88:
#line 667 "sintaxis.y"
    {funcionOperaciones((char*)"60");}
    break;

  case 89:
#line 667 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "60", 1);}
    break;

  case 91:
#line 668 "sintaxis.y"
    {funcionOperaciones((char*)"70");}
    break;

  case 92:
#line 668 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "70", 1);}
    break;

  case 95:
#line 671 "sintaxis.y"
    {funcionOperaciones((char*)"10"); funcionOperaciones((char*)"20");}
    break;

  case 96:
#line 672 "sintaxis.y"
    {funcionOperaciones((char*)"10");}
    break;

  case 97:
#line 672 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "10", 1);}
    break;

  case 99:
#line 673 "sintaxis.y"
    {funcionOperaciones((char *)"20");}
    break;

  case 100:
#line 673 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "20", 1);}
    break;

  case 103:
#line 676 "sintaxis.y"
    {funcionOperaciones((char*)"30"); funcionOperaciones((char*)"40");}
    break;

  case 105:
#line 677 "sintaxis.y"
    {funcionOperaciones((char*)"30");}
    break;

  case 106:
#line 677 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "30", 1);}
    break;

  case 108:
#line 678 "sintaxis.y"
    {funcionOperaciones((char*)"40");}
    break;

  case 109:
#line 678 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "40", 1);}
    break;

  case 112:
#line 681 "sintaxis.y"
    {meterFondoFalso();}
    break;

  case 113:
#line 681 "sintaxis.y"
    {sacaFondoFalso();}
    break;

  case 115:
#line 683 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "10", 1);}
    break;

  case 116:
#line 683 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "20", 1);}
    break;

  case 118:
#line 686 "sintaxis.y"
    {meterConstanteAPilaOperandos((char *)"numero", yylval.str);}
    break;

  case 119:
#line 686 "sintaxis.y"
    {meterConstanteAPilaOperandos((char *)"decimal", yylval.str);}
    break;

  case 120:
#line 686 "sintaxis.y"
    {meterConstanteAPilaOperandos((char *)"texto", yylval.str);}
    break;

  case 121:
#line 686 "sintaxis.y"
    {meterConstanteAPilaOperandos((char *)"caracter", yylval.str);}
    break;

  case 126:
#line 690 "sintaxis.y"
    {meterAPilaOperandos(dirProcsInit, yylval.str, last_func);}
    break;


/* Line 1267 of yacc.c.  */
#line 2534 "y.tab.c"
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


#line 694 "sintaxis.y"


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
        
        //printf("#\n");
		//debugList(dirProcsInit);
		//printf("#\n");
		//imprimeListaConstantes(PilaConstantes);
		//printf("#\n");
		//imprimeCuad(cuadruplo);
		
		
        strcat(argv[1],(char *)".obj");
        /* WRITE OBJ FILE */
        FILE *file;
        file = fopen(argv[1],"w+"); /* apend file (add text to a file or create a file if it does not exist.*/
        imprimeConstantesToFile(&file, PilaConstantes);
        fprintf(file,"#\n");
        imprimeCuadruploToFile(&file, cuadruplo);
        fprintf(file,"#\n");
        imprimeDirProcsToFile(&file, dirProcsInit);
        fclose(file);
        
        deallocSemanticCube(&semanticCube);
        deallocProcDir(&dirProcsInit);

    } else {
        printf("Invalid parameter count: %s <filename>\n", argv[0]);
    }
}

