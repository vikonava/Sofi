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
			tNode->virtual_address = NULL;
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
		contadorK = 1;
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
	void generaParametro(char* proc_name){
		int argumento;
		char* tipoArg;
		
		argumento = *static_cast<int*>(stack_pop(&PilaOperandos)->ptr);
		tipoArg = static_cast<char*>(PiladeTipos->ptr);
		
		Node *tNode = findProc(dirProcsInit, proc_name);
		if(strcmp(tipoArg, tNode->apunta->tipo) == 0){
			addCuad(&cuadruplo, 230, argumento, -1, contadorK);
		}
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
#line 558 "sintaxis.y"
{
    char *str;
}
/* Line 193 of yacc.c.  */
#line 732 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 745 "y.tab.c"

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
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNRULES -- Number of states.  */
#define YYNSTATES  199

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
       0,     0,     3,     4,     5,     6,     7,    18,    21,    22,
      25,    26,    27,    34,    38,    39,    41,    43,    45,    47,
      49,    53,    56,    57,    59,    61,    63,    65,    67,    69,
      71,    72,    73,    80,    81,    91,    92,    96,    97,    98,
     105,   106,   110,   113,   114,   115,   122,   123,   124,   132,
     133,   134,   135,   147,   148,   149,   160,   161,   162,   168,
     169,   172,   173,   175,   176,   177,   184,   185,   189,   190,
     191,   195,   196,   197,   201,   204,   205,   206,   209,   210,
     213,   214,   217,   218,   221,   222,   226,   227,   228,   233,
     234,   235,   240,   241,   244,   245,   246,   251,   252,   253,
     258,   259,   260,   264,   265,   266,   271,   272,   273,   278,
     279,   280,   285,   288,   290,   292,   293,   295,   297,   299,
     301,   303,   305,   307,   308,   312,   316,   320,   321,   324,
     327
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      44,     0,    -1,    -1,    -1,    -1,    -1,     3,    45,    27,
      46,    33,    47,    49,    55,    48,    50,    -1,    51,    49,
      -1,    -1,    79,    50,    -1,    -1,    -1,     4,    54,    53,
      27,    52,    33,    -1,    36,    28,    37,    -1,    -1,     5,
      -1,     6,    -1,     8,    -1,     7,    -1,     9,    -1,    18,
      56,    19,    -1,    57,    56,    -1,    -1,    58,    -1,    61,
      -1,    65,    -1,    70,    -1,    72,    -1,    75,    -1,    87,
      -1,    -1,    -1,    27,    59,    38,    60,    93,    33,    -1,
      -1,    14,    34,    93,    35,    62,    18,    56,    63,    19,
      -1,    -1,    15,    64,    56,    -1,    -1,    -1,    12,    34,
      67,    35,    66,    33,    -1,    -1,    93,    68,    69,    -1,
      32,    67,    -1,    -1,    -1,    13,    34,   125,    71,    35,
      33,    -1,    -1,    -1,    20,    73,    34,    93,    35,    74,
      55,    -1,    -1,    -1,    -1,    21,    34,    58,    76,    93,
      33,    77,    58,    78,    35,    55,    -1,    -1,    -1,    22,
      80,    54,    27,    81,    34,    82,    35,    86,    55,    -1,
      -1,    -1,    54,    83,    27,    84,    85,    -1,    -1,    32,
      82,    -1,    -1,    51,    -1,    -1,    -1,    27,    88,    34,
      89,    35,    33,    -1,    -1,   108,    90,    91,    -1,    -1,
      -1,    32,    92,    89,    -1,    -1,    -1,   101,    94,    95,
      -1,    96,   101,    -1,    -1,    -1,    97,    24,    -1,    -1,
      98,    25,    -1,    -1,    99,    26,    -1,    -1,   100,    23,
      -1,    -1,   108,   102,   103,    -1,    -1,    -1,   104,    16,
     105,   101,    -1,    -1,    -1,   106,    17,   107,   101,    -1,
      -1,   114,   109,    -1,    -1,    -1,   110,    39,   111,   108,
      -1,    -1,    -1,   112,    40,   113,   108,    -1,    -1,    -1,
     121,   115,   116,    -1,    -1,    -1,   117,    41,   118,   114,
      -1,    -1,    -1,   119,    42,   120,   114,    -1,    -1,    -1,
      34,   122,    93,    35,    -1,   123,   124,    -1,    39,    -1,
      40,    -1,    -1,    28,    -1,    29,    -1,    30,    -1,    31,
      -1,    10,    -1,    11,    -1,   125,    -1,    -1,    27,   126,
     127,    -1,    34,   128,    35,    -1,    36,    93,    37,    -1,
      -1,    93,   129,    -1,    32,   128,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   567,   567,   567,   567,   567,   567,   568,   569,   570,
     571,   573,   573,   574,   575,   577,   577,   577,   577,   577,
     579,   580,   581,   583,   583,   583,   583,   583,   583,   583,
     585,   585,   585,   587,   587,   588,   588,   589,   591,   591,
     592,   592,   593,   594,   596,   596,   598,   598,   598,   600,
     600,   600,   600,   602,   602,   602,   603,   603,   603,   604,
     605,   606,   607,   608,   610,   610,   611,   611,   612,   613,
     613,   614,   616,   616,   617,   618,   619,   619,   620,   620,
     621,   621,   622,   622,   624,   624,   625,   625,   625,   626,
     626,   626,   627,   629,   630,   630,   630,   631,   631,   631,
     632,   634,   634,   635,   635,   635,   636,   636,   636,   637,
     639,   639,   640,   641,   641,   642,   644,   644,   644,   644,
     644,   644,   645,   647,   647,   648,   649,   650,   651,   652,
     653
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
  "@2", "@3", "@4", "program1", "program2", "vars", "@5", "vars1", "tipo",
  "bloque", "bloque1", "estatuto", "asignacion", "@6", "@7", "condicion",
  "@8", "condicion1", "@9", "escritura", "@10", "escritura1", "@11",
  "escritura2", "lectura", "@12", "mientras", "@13", "@14", "para", "@15",
  "@16", "@17", "func", "@18", "@19", "func1", "@20", "@21", "func2",
  "varsfunc", "llamada", "@22", "llamada2", "@23", "llamada3", "@24",
  "expresion", "@25", "expresion1", "expresion2", "@26", "@27", "@28",
  "@29", "cond", "@30", "cond1", "@31", "@32", "@33", "@34", "exp", "exp1",
  "@35", "@36", "@37", "@38", "termino", "@39", "termino1", "@40", "@41",
  "@42", "@43", "factor", "@44", "factor1", "varcte", "variable", "@45",
  "variable1", "variable2", "variable3", 0
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
       0,    43,    45,    46,    47,    48,    44,    49,    49,    50,
      50,    52,    51,    53,    53,    54,    54,    54,    54,    54,
      55,    56,    56,    57,    57,    57,    57,    57,    57,    57,
      59,    60,    58,    62,    61,    64,    63,    63,    66,    65,
      68,    67,    69,    69,    71,    70,    73,    74,    72,    76,
      77,    78,    75,    80,    81,    79,    83,    84,    82,    82,
      85,    85,    86,    86,    88,    87,    90,    89,    89,    92,
      91,    91,    94,    93,    95,    95,    97,    96,    98,    96,
      99,    96,   100,    96,   102,   101,   104,   105,   103,   106,
     107,   103,   103,   108,   110,   111,   109,   112,   113,   109,
     109,   115,   114,   117,   118,   116,   119,   120,   116,   116,
     122,   121,   121,   123,   123,   123,   124,   124,   124,   124,
     124,   124,   124,   126,   125,   127,   127,   127,   128,   129,
     129
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,    10,     2,     0,     2,
       0,     0,     6,     3,     0,     1,     1,     1,     1,     1,
       3,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     6,     0,     9,     0,     3,     0,     0,     6,
       0,     3,     2,     0,     0,     6,     0,     0,     7,     0,
       0,     0,    11,     0,     0,    10,     0,     0,     5,     0,
       2,     0,     1,     0,     0,     6,     0,     3,     0,     0,
       3,     0,     0,     3,     2,     0,     0,     2,     0,     2,
       0,     2,     0,     2,     0,     3,     0,     0,     4,     0,
       0,     4,     0,     2,     0,     0,     4,     0,     0,     4,
       0,     0,     3,     0,     0,     4,     0,     0,     4,     0,
       0,     4,     2,     1,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     3,     3,     0,     2,     2,
       0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     3,     0,     4,     8,     0,
       0,     8,    15,    16,    18,    17,    19,    14,    22,     5,
       7,     0,     0,     0,     0,     0,    46,     0,    30,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    10,     0,
      11,   115,     0,   115,     0,     0,     0,     0,    20,    21,
      53,     6,    10,    13,     0,   110,   113,   114,     0,    40,
      72,    84,   100,   101,     0,   123,    44,     0,   115,    30,
      49,    31,   115,     0,     9,    12,   115,    38,    43,    75,
      92,    93,     0,     0,   109,   120,   121,   116,   117,   118,
     119,   112,   122,   127,     0,    33,     0,   115,   115,     0,
      66,     0,     0,     0,   115,    41,    73,   115,     0,     0,
       0,     0,    85,     0,     0,    95,    98,   102,     0,     0,
     115,   115,   124,     0,     0,    47,     0,     0,     0,    71,
      54,   111,    39,    42,    74,    77,    79,    81,    83,    87,
      90,   115,   115,   104,   107,   130,     0,     0,    45,    22,
       0,    50,    32,    65,    69,    67,     0,   115,   115,    96,
      99,   115,   115,   115,   128,   125,   126,    37,    48,     0,
     115,    59,    88,    91,   105,   108,   129,    35,     0,    51,
      70,    56,     0,    22,    34,     0,     0,    63,    36,     0,
      57,    62,     0,    52,    61,    55,    59,    58,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     8,    38,    10,    51,    11,    54,
      22,   181,    19,    29,    30,    31,    46,    98,    32,   124,
     178,   183,    33,   103,    58,    78,   105,    34,    94,    35,
      44,   150,    36,    97,   169,   185,    52,    73,   156,   182,
     186,   194,   197,   192,    37,    47,    99,   129,   155,   170,
      59,    79,   106,   107,   108,   109,   110,   111,    60,    80,
     112,   113,   157,   114,   158,    61,    81,    82,   141,    83,
     142,    62,    84,   117,   118,   161,   119,   162,    63,    76,
      64,    91,    66,    93,   122,   146,   164
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -146
static const yytype_int16 yypact[] =
{
      13,  -146,    33,   -10,  -146,  -146,    20,  -146,    50,    15,
      37,    50,  -146,  -146,  -146,  -146,  -146,    24,    25,  -146,
    -146,    34,    36,    27,    30,    31,  -146,    32,    35,    48,
      25,  -146,  -146,  -146,  -146,  -146,  -146,  -146,    49,    38,
    -146,   -21,    43,   -21,    40,    51,    39,    42,  -146,  -146,
    -146,  -146,    49,  -146,    52,  -146,  -146,  -146,    46,  -146,
    -146,  -146,   -33,  -146,     1,  -146,  -146,    47,   -21,  -146,
    -146,  -146,   -25,    15,  -146,  -146,   -21,  -146,    54,    17,
       9,  -146,    44,    53,     7,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,     0,    55,  -146,    56,   -21,   -21,    57,
    -146,    60,    59,    62,   -21,  -146,  -146,   -21,    64,    71,
      58,    66,  -146,    81,    82,  -146,  -146,  -146,    61,    63,
     -21,   -21,  -146,    65,    85,  -146,    67,    73,    74,    72,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,   -21,   -21,  -146,  -146,    76,    75,    77,  -146,    25,
      37,  -146,  -146,  -146,  -146,  -146,    78,   -21,   -21,  -146,
    -146,   -21,   -21,   -21,  -146,  -146,  -146,    94,  -146,    51,
     -25,    15,  -146,  -146,  -146,  -146,  -146,  -146,    92,  -146,
    -146,  -146,    80,    25,  -146,    83,    86,    50,  -146,    37,
    -146,  -146,    37,  -146,    84,  -146,    15,  -146,  -146
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,  -146,  -146,  -146,  -146,   106,    68,   -66,  -146,
    -146,    -5,  -145,   -30,  -146,   -44,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,    19,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,   -72,
    -146,  -146,  -146,  -146,  -146,  -146,   -43,  -146,  -146,  -146,
     -41,  -146,  -146,  -146,  -146,  -146,  -146,  -146,   -99,  -146,
    -146,  -146,  -146,  -146,  -146,   -69,  -146,  -146,  -146,  -146,
    -146,  -111,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,    69,  -146,  -146,   -37,  -146
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -107
static const yytype_int16 yytable[] =
{
      49,    70,    67,   100,    17,   168,   -94,   -97,   134,    55,
     -68,    85,    86,    55,    56,    57,     1,     5,    56,    57,
      12,    13,    14,    15,    16,   -86,   -89,    96,    65,    87,
      88,    89,    90,     4,   120,   102,   121,    23,    24,    25,
     -82,   -76,   -78,   -80,   193,    26,    27,   195,  -103,  -106,
     174,   175,    28,     7,     9,    18,   126,   127,   172,   173,
      21,    41,    39,    40,    42,    43,    45,    48,   101,   -64,
      65,    50,   159,   160,    68,    53,    72,    71,    69,   145,
     147,    77,    95,   115,   137,    75,   104,   130,   135,   138,
     123,   125,   128,   116,   131,   132,   136,   139,   148,   140,
     151,   100,   143,   149,   154,   144,   152,   153,   163,   177,
     165,   184,   171,   190,   166,   187,   196,    20,   189,   167,
      74,   191,   145,   133,   198,   179,   176,   180,     0,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   188
};

static const yytype_int16 yycheck[] =
{
      30,    45,    43,    72,     9,   150,    39,    40,   107,    34,
      35,    10,    11,    34,    39,    40,     3,    27,    39,    40,
       5,     6,     7,     8,     9,    16,    17,    68,    27,    28,
      29,    30,    31,     0,    34,    76,    36,    12,    13,    14,
      23,    24,    25,    26,   189,    20,    21,   192,    41,    42,
     161,   162,    27,    33,     4,    18,    97,    98,   157,   158,
      36,    34,    28,    27,    34,    34,    34,    19,    73,    34,
      27,    22,   141,   142,    34,    37,    34,    38,    27,   120,
     121,    35,    35,    39,    26,    33,    32,    27,    24,    23,
      35,    35,    35,    40,    35,    33,    25,    16,    33,    17,
      33,   170,    41,    18,    32,    42,    33,    33,    32,    15,
      35,    19,    34,    27,    37,    35,    32,    11,    35,   149,
      52,   187,   163,   104,   196,   169,   163,   170,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   183
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    44,    45,     0,    27,    46,    33,    47,     4,
      49,    51,     5,     6,     7,     8,     9,    54,    18,    55,
      49,    36,    53,    12,    13,    14,    20,    21,    27,    56,
      57,    58,    61,    65,    70,    72,    75,    87,    48,    28,
      27,    34,    34,    34,    73,    34,    59,    88,    19,    56,
      22,    50,    79,    37,    52,    34,    39,    40,    67,    93,
     101,   108,   114,   121,   123,    27,   125,    93,    34,    27,
      58,    38,    34,    80,    50,    33,   122,    35,    68,    94,
     102,   109,   110,   112,   115,    10,    11,    28,    29,    30,
      31,   124,   125,   126,    71,    35,    93,    76,    60,    89,
     108,    54,    93,    66,    32,    69,    95,    96,    97,    98,
      99,   100,   103,   104,   106,    39,    40,   116,   117,   119,
      34,    36,   127,    35,    62,    35,    93,    93,    35,    90,
      27,    35,    33,    67,   101,    24,    25,    26,    23,    16,
      17,   111,   113,    41,    42,    93,   128,    93,    33,    18,
      74,    33,    33,    33,    32,    91,    81,   105,   107,   108,
     108,   118,   120,    32,   129,    35,    37,    56,    55,    77,
      92,    34,   101,   101,   114,   114,   128,    15,    63,    58,
      89,    54,    82,    64,    19,    78,    83,    35,    56,    35,
      27,    51,    86,    55,    84,    55,    32,    85,    82
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
#line 567 "sintaxis.y"
    {variable_type = (char *)"NP"; tipo_func = (char *)"global"; }
    break;

  case 3:
#line 567 "sintaxis.y"
    { variable_name = yylval.str; last_func = variable_name; stack_push(&PilaEjecucion, variable_name, 1);}
    break;

  case 4:
#line 567 "sintaxis.y"
    { addProc(&dirProcsInit,variable_name,variable_type); }
    break;

  case 5:
#line 567 "sintaxis.y"
    {addCuad(&cuadruplo, 220, -1, -1, -1); contadorCuad++;}
    break;

  case 11:
#line 573 "sintaxis.y"
    { variable_name = yylval.str; }
    break;

  case 12:
#line 573 "sintaxis.y"
    {addLocalVariableToProc(&dirProcsInit,last_func,variable_name,variable_type,alloc_virtual_address(variable_type, tipo_func)); }
    break;

  case 15:
#line 577 "sintaxis.y"
    { variable_type = (char *)"numero"; }
    break;

  case 16:
#line 577 "sintaxis.y"
    { variable_type = (char *)"decimal"; }
    break;

  case 17:
#line 577 "sintaxis.y"
    { variable_type = (char *)"caracter"; }
    break;

  case 18:
#line 577 "sintaxis.y"
    { variable_type = (char *)"texto"; }
    break;

  case 19:
#line 577 "sintaxis.y"
    { variable_type = (char *)"booleano"; }
    break;

  case 30:
#line 585 "sintaxis.y"
    {meterAPilaOperandos(dirProcsInit, yylval.str, last_func);}
    break;

  case 31:
#line 585 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "120", 1);}
    break;

  case 32:
#line 585 "sintaxis.y"
    {funcionAsignacion();}
    break;

  case 33:
#line 587 "sintaxis.y"
    {funcionIfUno();}
    break;

  case 34:
#line 587 "sintaxis.y"
    {funcionIfTres();}
    break;

  case 35:
#line 588 "sintaxis.y"
    {funcionIfDos();}
    break;

  case 38:
#line 591 "sintaxis.y"
    { funcionEscrituraFin(); }
    break;

  case 40:
#line 592 "sintaxis.y"
    { funcionEscritura(); }
    break;

  case 44:
#line 596 "sintaxis.y"
    { funcionLectura(); }
    break;

  case 46:
#line 598 "sintaxis.y"
    {funcionWhileUno();}
    break;

  case 47:
#line 598 "sintaxis.y"
    {funcionWhileDos();}
    break;

  case 48:
#line 598 "sintaxis.y"
    {funcionWhileTres();}
    break;

  case 49:
#line 600 "sintaxis.y"
    { funcionParaUno(); }
    break;

  case 50:
#line 600 "sintaxis.y"
    { funcionParaDos(); }
    break;

  case 51:
#line 600 "sintaxis.y"
    { funcionParaTres(); }
    break;

  case 52:
#line 600 "sintaxis.y"
    { funcionParaCuatro(); }
    break;

  case 53:
#line 602 "sintaxis.y"
    {tipo_func = (char *)"local";}
    break;

  case 54:
#line 602 "sintaxis.y"
    {last_func = yylval.str; stack_push(&PilaEjecucion, last_func, 1); addProc(&dirProcsInit, last_func, variable_type);}
    break;

  case 55:
#line 602 "sintaxis.y"
    {eliminaTabla(last_func);}
    break;

  case 56:
#line 603 "sintaxis.y"
    {agregaParam(static_cast<char*>(PilaEjecucion->ptr), variable_type);}
    break;

  case 57:
#line 603 "sintaxis.y"
    {variable_name = yylval.str; addLocalVariableToProc(&dirProcsInit, static_cast<char*>(PilaEjecucion->ptr), variable_name, variable_type, alloc_virtual_address(variable_type, (char *)"local"));}
    break;

  case 64:
#line 610 "sintaxis.y"
    { last_func = yylval.str ;generaEra(last_func); }
    break;

  case 65:
#line 610 "sintaxis.y"
    { addCuad(&cuadruplo, 160, findProcPos(dirProcsInit, last_func), -1, -1); }
    break;

  case 66:
#line 611 "sintaxis.y"
    { generaParametro(last_func); }
    break;

  case 69:
#line 613 "sintaxis.y"
    { contadorK++; }
    break;

  case 72:
#line 616 "sintaxis.y"
    {funcionOperaciones((char*)"80"); funcionOperaciones((char*)"90"); funcionOperaciones((char*)"100"); funcionOperaciones((char*)"110");}
    break;

  case 74:
#line 617 "sintaxis.y"
    {funcionOperaciones((char*)"80"); funcionOperaciones((char*)"90"); funcionOperaciones((char*)"100"); funcionOperaciones((char*)"110");}
    break;

  case 76:
#line 619 "sintaxis.y"
    {funcionOperaciones((char*)"80");}
    break;

  case 77:
#line 619 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "80", 1);}
    break;

  case 78:
#line 620 "sintaxis.y"
    {funcionOperaciones((char*)"90");}
    break;

  case 79:
#line 620 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "90", 1);}
    break;

  case 80:
#line 621 "sintaxis.y"
    {funcionOperaciones((char*)"100");}
    break;

  case 81:
#line 621 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "100", 1);}
    break;

  case 82:
#line 622 "sintaxis.y"
    {funcionOperaciones((char*)"110");}
    break;

  case 83:
#line 622 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "110", 1);}
    break;

  case 84:
#line 624 "sintaxis.y"
    {funcionOperaciones((char*)"60"); funcionOperaciones((char*)"70");}
    break;

  case 86:
#line 625 "sintaxis.y"
    {funcionOperaciones((char*)"60");}
    break;

  case 87:
#line 625 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "60", 1);}
    break;

  case 89:
#line 626 "sintaxis.y"
    {funcionOperaciones((char*)"70");}
    break;

  case 90:
#line 626 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "70", 1);}
    break;

  case 93:
#line 629 "sintaxis.y"
    {funcionOperaciones((char*)"10"); funcionOperaciones((char*)"20");}
    break;

  case 94:
#line 630 "sintaxis.y"
    {funcionOperaciones((char*)"10");}
    break;

  case 95:
#line 630 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "10", 1);}
    break;

  case 97:
#line 631 "sintaxis.y"
    {funcionOperaciones((char *)"20");}
    break;

  case 98:
#line 631 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "20", 1);}
    break;

  case 101:
#line 634 "sintaxis.y"
    {funcionOperaciones((char*)"30"); funcionOperaciones((char*)"40");}
    break;

  case 103:
#line 635 "sintaxis.y"
    {funcionOperaciones((char*)"30");}
    break;

  case 104:
#line 635 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "30", 1);}
    break;

  case 106:
#line 636 "sintaxis.y"
    {funcionOperaciones((char*)"40");}
    break;

  case 107:
#line 636 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "40", 1);}
    break;

  case 110:
#line 639 "sintaxis.y"
    {meterFondoFalso();}
    break;

  case 111:
#line 639 "sintaxis.y"
    {sacaFondoFalso();}
    break;

  case 113:
#line 641 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "10", 1);}
    break;

  case 114:
#line 641 "sintaxis.y"
    {stack_push(&PilaOperadores, (char *) "20", 1);}
    break;

  case 116:
#line 644 "sintaxis.y"
    {meterConstanteAPilaOperandos((char *)"numero", yyval.str);}
    break;

  case 117:
#line 644 "sintaxis.y"
    {meterConstanteAPilaOperandos((char *)"decimal", yylval.str);}
    break;

  case 118:
#line 644 "sintaxis.y"
    {meterConstanteAPilaOperandos((char *)"texto", yyval.str);}
    break;

  case 119:
#line 644 "sintaxis.y"
    {meterConstanteAPilaOperandos((char *)"caracter", yyval.str);}
    break;

  case 123:
#line 647 "sintaxis.y"
    {meterAPilaOperandos(dirProcsInit, yylval.str, last_func);}
    break;


/* Line 1267 of yacc.c.  */
#line 2484 "y.tab.c"
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


#line 655 "sintaxis.y"


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
        
        printf("#\n");
		debugList(dirProcsInit);
		printf("#\n");
		imprimeListaConstantes(PilaConstantes);
		printf("#\n");
		imprimeCuad(cuadruplo);
		
		
        strcat(argv[1],(char *)".obj");
        /* WRITE OBJ FILE */
        FILE *file;
        file = fopen(argv[1],"w+"); /* apend file (add text to a file or create a file if it does not exist.*/
        imprimeConstantesToFile(&file, PilaConstantes);
        fprintf(file,"#\n");
        imprimeCuadruploToFile(&file, cuadruplo);
        fclose(file);
        
        deallocSemanticCube(&semanticCube);
        deallocProcDir(&dirProcsInit);

    } else {
        printf("Invalid parameter count: %s <filename>\n", argv[0]);
    }
}

