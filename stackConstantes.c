#include <stdlib.h>
#include <stdio.h>

typedef struct StackConstantes {
    void *ptr;
    int direccionMemoria;
	int ptrType;
    struct StackConstantes *next;
} StackConstantes;

bool stackC_push(StackConstantes **head, void *ptr, int direccionMemoria, int ptrType) {
    StackConstantes *temp;
    temp = (StackConstantes *)malloc(sizeof(StackConstantes));
    temp->ptr = ptr;
	temp->direccionMemoria = direccionMemoria;
    temp->ptrType = ptrType;
    temp->next = *head;
    
    *head = temp;
    
    return true;
}

StackConstantes *stackC_pop(StackConstantes **head) {
	if( head != NULL ){
		StackConstantes *temp;
		temp = *head;
		*head = temp->next;
		
		return temp;
	}else{
		return NULL;
	}
}

void imprimeListaConstantes(StackConstantes *head){
	StackConstantes *temp;
	temp = head;
	
	while (temp != NULL) {
		if(temp->ptrType == 2){
		printf("%i,%i\n", temp->direccionMemoria,*static_cast<int*>(temp->ptr));
		}
		temp = temp->next;
	}
}

void imprimeConstantesToFile(FILE **file, StackConstantes *head) {
StackConstantes *temp;
	temp = head;
	
	while (temp != NULL) {
		if(temp->ptrType == 2){
		fprintf(*file, "%i,%i\n", temp->direccionMemoria,*static_cast<int*>(temp->ptr));
		}
		temp = temp->next;
	}
}