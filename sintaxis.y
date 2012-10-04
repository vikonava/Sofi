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
    
    char *variable_type; // Tipo de la ultima variable conocida
    char *variable_name; // Nombre de la ultima variable conocida
    Node *dirProcsInit; // Crea el apuntador al primer pointer del dir procs
    SemanticCubeNode *semanticCube;; // Apuntador al primer nodo del cubo semantico
%}

%union {
    char *str;
}

%token PROGRAMA VAR NUMERO DECIMAL TEXTO CARACTER BOOLEANO TRUE FALSE IMPRIME LEE SI SINO Y O REALIZA FIN MIENTRAS PARA FUNC IGUAL MAYOR MENOR DIFERENTE ID CTENUM CTEDEC CTEX CCAR COMA PCOMA ABREPA CIERRAPA ABRECORCH CIERRACORCH SIGUAL MAS MENOS POR ENTRE
%start program

%%

program: PROGRAMA { variable_type = (char *)"NP"; } ID { variable_name = yylval.str; } PCOMA { addProc(&dirProcsInit,variable_name,variable_type); } program1 bloque program2;
program1: vars program1;
program1: ;
program2: func program2;
program2: ;

vars: VAR tipo vars1 ID { variable_name = yylval.str; } PCOMA { addProc(&dirProcsInit,variable_name,variable_type); } ;
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
        
        //debugSemanticCube(semanticCube);

        deallocSemanticCube(&semanticCube);
        deallocProcDir(&dirProcsInit);

    } else {
        printf("Invalid parameter count: %s <filename>\n", argv[0]);
    }
}
