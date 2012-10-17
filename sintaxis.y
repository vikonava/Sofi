/*
Silvia Fosado Garcia 1032432
Victor Nava 617610

Programa BISON para el Manejo de Sintaxis
 
*/
%{
	#include <stdio.h>
    #include <iostream>
    #include "estructura.c"
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
    char *variable_type; // Tipo de la ultima variable conocida
    char *variable_name; // Nombre de la ultima variable conocida
    char *last_func; //
    char *tipo_func;
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
        } else if (strcmp(scope,(char *)"temporal") == 0) {
        } else if (strcmp(scope,(char *)"constante") == 0) {
        } else return -1;
    }
%}

%union {
    char *str;
}

%token PROGRAMA VAR NUMERO DECIMAL TEXTO CARACTER BOOLEANO TRUE FALSE IMPRIME LEE SI SINO Y O REALIZA FIN MIENTRAS PARA FUNC IGUAL MAYOR MENOR DIFERENTE ID CTENUM CTEDEC CTEX CCAR COMA PCOMA ABREPA CIERRAPA ABRECORCH CIERRACORCH SIGUAL MAS MENOS POR ENTRE
%start program

%%

program: PROGRAMA { variable_type = (char *)"NP"; tipo_func = (char *)"global" } ID { variable_name = yylval.str; last_func = variable_name; } PCOMA { addProc(&dirProcsInit,variable_name,variable_type); } program1 bloque program2;
program1: vars program1;
program1: ;
program2: func program2;
program2: ;

vars: VAR tipo vars1 ID { variable_name = yylval.str; } PCOMA { addLocalVariableToProc(&dirProcsInit,last_func,variable_name,variable_type,alloc_virtual_address(variable_type, tipo_func)); } ;
vars1: ABRECORCH CTENUM CIERRACORCH;
vars1: ;

tipo: NUMERO { variable_type = (char *)"numero"; } | DECIMAL { variable_type = (char *)"decimal"; } | CARACTER { variable_type = (char *)"caracter"; } | TEXTO { variable_type = (char *)"texto"; } | BOOLEANO { variable_type = (char *)"booleano"; };

/*exparr: ABREPA exparr1 CIERRAPA;
exparr1: expresion exparr2;
exparr2: COMA exparr1;
exparr2: ;*/

bloque: REALIZA bloque1 FIN;
bloque1: estatuto bloque1;
bloque1: ;

estatuto: asignacion | condicion | escritura | lectura | mientras | para;

asignacion: ID SIGUAL expresion PCOMA;

condicion: SI ABREPA expresion CIERRAPA bloque condicion1;
condicion1: SINO bloque;
condicion1: ;

escritura: IMPRIME ABREPA escritura1 CIERRAPA PCOMA;
escritura1: expresion escritura2;
escritura2: COMA escritura1;
escritura2: ;

lectura: LEE ABREPA variable CIERRAPA PCOMA;

mientras: MIENTRAS ABREPA expresion CIERRAPA bloque;

para: PARA ABREPA asignacion expresion PCOMA asignacion CIERRAPA bloque;

func: FUNC tipo ID ABREPA params CIERRAPA bloque;

params: tipo params1 ID params2;
params1: ABRECORCH expresion CIERRACORCH;
params1: ;
params2: COMA params;
params2: ;

expresion: cond expresion1;
expresion1: expresion2 cond;
expresion1: ;
expresion2: MAYOR | MENOR | DIFERENTE | IGUAL;

cond: exp cond1;
cond1: Y cond;
cond1: O cond;
cond1: ;

exp: termino exp1;
exp1: MAS exp;
exp1: MENOS exp;
exp1: ;

termino: factor termino1;
termino1: POR termino;
termino1: ENTRE termino;
termino1: ;

factor: ABREPA expresion CIERRAPA;
factor: factor1 varcte;
factor1: MAS | MENOS;
factor1: ;

varcte: CTENUM | CTEDEC | CTEX | CCAR | TRUE | FALSE;
varcte: variable;

variable: ID variable1;
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
        
        debugList(dirProcsInit);

        deallocSemanticCube(&semanticCube);
        deallocProcDir(&dirProcsInit);

    } else {
        printf("Invalid parameter count: %s <filename>\n", argv[0]);
    }
}
