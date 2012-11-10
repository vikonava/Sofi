/*
Silvia Fosado Garcia 1032432
Victor Nava 617610

Estructuras de datos utilizadas en el compilador
 
*/
#include <stdio.h>
#include <stdlib.h>

/****************** Cuadruplos *********************/
typedef struct _cuadruplos {
	int operador;
	int dirOperando1;
	int dirOperando2;
	int temporal;
	struct _cuadruplos *next;
} Cuadruplos;

// FUNCTION: addCuad(lista, operador, dirOperando1, dirOperando2, temporal);
// RETURN: void
//
// Inserta un Cuadruplo en una lista 
//
Cuadruplos* addCuad(Cuadruplos **list, int operador, int dirOp1, int dirOp2, int temporal) {
	Cuadruplos *cuad;
	cuad = *list;
	Cuadruplos *cuad_tmp = (struct _cuadruplos *)malloc(sizeof(struct _cuadruplos));
	
	cuad_tmp->operador = operador;
	cuad_tmp->dirOperando1 = dirOp1;
	cuad_tmp->dirOperando2 = dirOp2;
	cuad_tmp->temporal = temporal;
	cuad_tmp->next = NULL;
    
    if( cuad == NULL ){
        *list = cuad_tmp;
    }else{
	
        while(cuad->next != NULL) {
            cuad = cuad->next;
        }
        
        cuad->next = cuad_tmp;
    }
	return cuad_tmp;
}

void imprimeCuad(Cuadruplos *cuadruplo) {
	Cuadruplos *cuad;
	cuad = cuadruplo;
	int contador = 1;
	
	
	while(cuad != NULL) {
		printf("%d,%d,%d,%d\n", cuad->operador, cuad->dirOperando1, cuad->dirOperando2, cuad->temporal);
		contador++;
		cuad = cuad->next;
	}
	
}

Cuadruplos* buscarCuad(Cuadruplos *cuadruplo, int contador){
	Cuadruplos *temp = cuadruplo;
	
	for(int cont = 0; cont < contador && temp != NULL; cont++){
		temp = temp->next;	
	}
	return temp;
}

void imprimeCuadruploToFile(FILE **file, Cuadruplos *cuadruplo) {
    Cuadruplos *cuad;
	cuad = cuadruplo;
	
	while(cuad != NULL) {
		fprintf(*file, "%d,%d,%d,%d\n", cuad->operador, cuad->dirOperando1, cuad->dirOperando2, cuad->temporal);
		cuad = cuad->next;
	}
}