#include <stdlib.h>
#include <stdio.h>

typedef struct Stack {
    void *ptr;
    int ptrType;
    struct Stack *next;
} Stack;

bool stack_push(Stack **head, void *ptr, int ptrType) {
    Stack *temp;
    temp = (Stack *)malloc(sizeof(Stack));
    temp->ptr = ptr;
    temp->ptrType = ptrType;
    temp->next = *head;
    
    *head = temp;
    
    return true;
}

Stack *stack_pop(Stack **head) {
	if( head != NULL ){
		Stack *temp;
		temp = *head;
		*head = temp->next;
		
		return temp;
	}else{
		return NULL;
	}
}