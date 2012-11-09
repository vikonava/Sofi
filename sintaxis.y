/*
Silvia Fosado Garcia 1032432
Victor Nava 617610

Programa BISON para el Manejo de Sintaxis
 
*/
%{
	#include <stdio.h>
    #include <iostream>
    #include "estructura.c"
	#include "cuadruplos.c"
	#include "stack.c"
	
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
	
	void meterConstanteAPilaOperandos(char* tipo){
		int *direccion = (int *)malloc(sizeof(int));
		
		if(strcmp(tipo, (char *) "numero") == 0){
			*direccion = alloc_virtual_address((char *) "numero", (char *) "constante");
			stack_push(&PilaOperandos, direccion, 2);
			stack_push(&PiladeTipos, (char *) "numero", 1);
		}
		if(strcmp(tipo, (char *) "decimal") == 0){
			*direccion = alloc_virtual_address((char *) "decimal", (char *) "constante");
			stack_push(&PilaOperandos, direccion, 2);
			stack_push(&PiladeTipos, (char *) "decimal", 1);
		}
		if(strcmp(tipo, (char *) "caracter") == 0){
			*direccion = alloc_virtual_address((char *) "caracter", (char *) "constante");
			stack_push(&PilaOperandos, direccion, 2);
			stack_push(&PiladeTipos, (char *) "caracter", 1);
		}
		if(strcmp(tipo, (char *) "texto") == 0){
			*direccion = alloc_virtual_address((char *) "texto", (char *) "constante");
			stack_push(&PilaOperandos, direccion, 2);
			stack_push(&PiladeTipos, (char *) "texto ", 1);
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

	
%}



%union {
    char *str;
}

%token PROGRAMA VAR NUMERO DECIMAL TEXTO CARACTER BOOLEANO TRUE FALSE IMPRIME LEE SI SINO Y O REALIZA FIN MIENTRAS PARA FUNC IGUAL MAYOR MENOR DIFERENTE ID CTENUM CTEDEC CTEX CCAR COMA PCOMA ABREPA CIERRAPA ABRECORCH CIERRACORCH SIGUAL MAS MENOS POR ENTRE
%start program

%%

program: PROGRAMA {variable_type = (char *)"NP"; tipo_func = (char *)"global"; } ID { variable_name = yylval.str; last_func = variable_name; stack_push(&PilaEjecucion, variable_name, 1);} PCOMA { addProc(&dirProcsInit,variable_name,variable_type); } program1 bloque program2;
program1: vars program1;
program1: ;
program2: func program2;
program2: ;

vars: VAR tipo vars1 ID { variable_name = yylval.str; } PCOMA {addLocalVariableToProc(&dirProcsInit,last_func,variable_name,variable_type,alloc_virtual_address(variable_type, tipo_func)); } ;
vars1: ABRECORCH CTENUM CIERRACORCH;
vars1: ;

tipo: NUMERO { variable_type = (char *)"numero"; } | DECIMAL { variable_type = (char *)"decimal"; } | CARACTER { variable_type = (char *)"caracter"; } | TEXTO { variable_type = (char *)"texto"; } | BOOLEANO { variable_type = (char *)"booleano"; };

bloque: REALIZA bloque1 FIN;
bloque1: estatuto bloque1;
bloque1: ;

estatuto: asignacion | condicion | escritura | lectura | mientras | para;

asignacion: ID {meterAPilaOperandos(dirProcsInit, yylval.str, last_func);} SIGUAL {stack_push(&PilaOperadores, (char *) "120", 1);} expresion PCOMA {funcionAsignacion();};

condicion: SI ABREPA expresion CIERRAPA {funcionIfUno();} REALIZA bloque1 condicion1 FIN {funcionIfTres();};
condicion1: SINO {funcionIfDos();} bloque1;
condicion1: ;

escritura: IMPRIME ABREPA escritura1 CIERRAPA PCOMA;
escritura1: expresion escritura2;
escritura2: COMA escritura1;
escritura2: ;

lectura: LEE ABREPA variable CIERRAPA PCOMA;

mientras: MIENTRAS {funcionWhileUno();} ABREPA expresion CIERRAPA {funcionWhileDos();} bloque {funcionWhileTres();};

para: PARA ABREPA asignacion { funcionParaUno(); } expresion PCOMA { funcionParaDos(); } asignacion { funcionParaTres(); } CIERRAPA bloque { funcionParaCuatro(); } ;

func: FUNC tipo ID ABREPA params CIERRAPA func1 bloque;
func1: vars func1;
func1: ;

params: tipo params1 ID params2;
params1: ABRECORCH expresion CIERRACORCH;
params1: ;
params2: COMA params;
params2: ;

expresion: cond {funcionOperaciones((char*)"80"); funcionOperaciones((char*)"90"); funcionOperaciones((char*)"100"); funcionOperaciones((char*)"110");} expresion1 ;
expresion1: expresion2 cond {funcionOperaciones((char*)"80"); funcionOperaciones((char*)"90"); funcionOperaciones((char*)"100"); funcionOperaciones((char*)"110");};
expresion1: ;
expresion2: {funcionOperaciones((char*)"80");} MAYOR {stack_push(&PilaOperadores, (char *) "80", 1);} 
	| {funcionOperaciones((char*)"90");} MENOR {stack_push(&PilaOperadores, (char *) "90", 1);}
	| {funcionOperaciones((char*)"100");} DIFERENTE {stack_push(&PilaOperadores, (char *) "100", 1);}
	| {funcionOperaciones((char*)"110");} IGUAL {stack_push(&PilaOperadores, (char *) "110", 1);};

cond: exp {funcionOperaciones((char*)"60"); funcionOperaciones((char*)"70");} cond1;
cond1: {funcionOperaciones((char*)"60");} Y {stack_push(&PilaOperadores, (char *) "60", 1);} cond;
cond1: {funcionOperaciones((char*)"70");} O {stack_push(&PilaOperadores, (char *) "70", 1);} cond;
cond1: ;

exp: termino exp1 {funcionOperaciones((char*)"10"); funcionOperaciones((char*)"20");};
exp1: {funcionOperaciones((char*)"10");} MAS {stack_push(&PilaOperadores, (char *) "10", 1);} exp;
exp1: {funcionOperaciones((char *)"20");} MENOS {stack_push(&PilaOperadores, (char *) "20", 1);} exp;
exp1: ;

termino: factor {funcionOperaciones((char*)"30"); funcionOperaciones((char*)"40");} termino1;
termino1: {funcionOperaciones((char*)"30");} POR {stack_push(&PilaOperadores, (char *) "30", 1);} termino;
termino1: {funcionOperaciones((char*)"40");} ENTRE {stack_push(&PilaOperadores, (char *) "40", 1);} termino;
termino1: ;

factor: ABREPA {meterFondoFalso();} expresion CIERRAPA {sacaFondoFalso();};
factor: factor1 varcte;
factor1: MAS {stack_push(&PilaOperadores, (char *) "10", 1);} | MENOS {stack_push(&PilaOperadores, (char *) "20", 1);};
factor1: ;

varcte: CTENUM {meterConstanteAPilaOperandos((char *)"numero");} | CTEDEC {meterConstanteAPilaOperandos((char *)"decimal");} | CTEX {meterConstanteAPilaOperandos((char *)"texto");} | CCAR {meterConstanteAPilaOperandos((char *)"caracter");} | TRUE | FALSE;
varcte: variable ;

variable: ID {meterAPilaOperandos(dirProcsInit, yylval.str, last_func);} variable1;
variable1: ABREPA variable2 CIERRAPA;
variable1: ABRECORCH expresion CIERRACORCH;
variable1: ;
variable2: expresion variable3;
variable3: COMA variable2;
variable3: ;

%%

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
		imprimeCuad(cuadruplo);
		
        deallocSemanticCube(&semanticCube);
        deallocProcDir(&dirProcsInit);

    } else {
        printf("Invalid parameter count: %s <filename>\n", argv[0]);
    }
}
