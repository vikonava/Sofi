/*
Silvia Fosado Garcia 1032432
Victor Nava 617610

Estructuras de datos utilizadas en el compilador
 
*/
#include <stdio.h>
#include <stdlib.h>

/*************************** Tabla Parametros **************************/ 
typedef struct Parametros {
	int numero;
	char* tipo;
	struct Parametros *next;
} Parametros;

// FUNCTION: addParameter(parametro, tipoParametro)
// RETURN: void
//
// Inserta un nodo nuevo de un parametro a la lista que contiene todos los parametros de la funcion
//
void addParameter(Parametros **parametro, char* tipo){
	Parametros *param;
	param = *parametro;
	Parametros *param_temp = (struct Parametros *)malloc(sizeof(struct Parametros));
	
	param_temp->numero = param_temp->numero++;
	param_temp->tipo = tipo;
	param_temp->next = NULL;
	
	if (param == NULL) {
		*parametro = param_temp;
	} else {
		while(param->next != NULL){
			param = param->next;
		}
		
		param->next = param_temp;
	}
}

// FUNCTION: cuentaParametros(parametro)
// RETURN: int
//
// Regresa la cantidad de parametros que hay en la lista de parametros
//
int cuentaParametros(Parametros *head){
	Parametros *param = head;
	int cont = 0;
	
	while (param != NULL) {
		cont++;
		param = param -> next;
	}
	return cont;
}

/*void imprime(Parametros *head){
	Parametros *param = head;
	
	while (param != NULL) {
		printf("%s \n", param->tipo);
		param = param -> next;
	}
}*/

/****************** Cubo Semantico *********************/

typedef struct _fopernode {
    char* data;
    _fopernode *contents;
    _fopernode *next;
} SemanticCubeNode;

// FUNCTION: addOperNode(lista, operador)
// RETURN: void
//
// Inserta un nudo nuevo de un operador en una lista
//
void addOperNode(SemanticCubeNode **list, char* operador) {
    SemanticCubeNode *sNode;
    sNode = (struct _fopernode *)malloc(sizeof(struct _fopernode));
    
    sNode->data = operador;
    sNode->contents = NULL;
    sNode->next = *list;
    
    *list = sNode;
}

// FUNCTION: addSecondOperNode(lista, operador1, operador2)
// RETURN: void
//
// Inserta el segundo operador a la lista de un primer operador
//
void addSecondOperNode(SemanticCubeNode **list, char* op1, char* op2) {
    SemanticCubeNode *sNode = *list;
    
    while (sNode != NULL) {
        if (sNode->data == op1) {
            SemanticCubeNode *stNode = (struct _fopernode *)malloc(sizeof(struct _fopernode));
            
            stNode->data = op2;
            stNode->contents = NULL;
            stNode->next = sNode->contents;
            
            sNode->contents = stNode;
            
            break;
        }
        sNode = sNode->next;
    }
}

// FUNCTION: addOperationNode(list, op1, op2, operation, returnType)
// Return: void
//
// Inserta la operacion en conjunto con su respuesta a la lista de nodos
//
void addOperationNode(SemanticCubeNode **list, char* op1, char *op2, char* operation, char* returnType) {
    SemanticCubeNode *sNode = *list;
    SemanticCubeNode *stNode;
    
    while (sNode != NULL) {
        if (sNode->data == op1) {
            stNode = sNode->contents;
            while (stNode != NULL) {
                if (stNode->data == op2) {
                    SemanticCubeNode *otNode = (struct _fopernode *)malloc(sizeof(struct _fopernode));
                    SemanticCubeNode *rtNode = (struct _fopernode *)malloc(sizeof(struct _fopernode));
            
                    // Nodo con info del return type
                    rtNode->data = returnType;
                    rtNode->contents = NULL;
                    rtNode->next = NULL;
                    
                    // Nodo con info de la operacion
                    otNode->data = operation;
                    otNode->contents = rtNode;
                    otNode->next = stNode->contents;
            
                    stNode->contents = otNode;
                    break;
                }
                stNode = stNode->next;
            }
            break;
        }
        sNode = sNode->next;
    }
}

// FUNCTION: findSemanticCubeReturnType(lista, op1, op2, operation)
// RETURN: char*
//
// Devuelve el tipo de retorno que generaria la operacion "operation" entre los operadores op1 y op2
// en caso de no encontrarlo devuelve (char *)"error"
//
char* findSemanticCubeReturnType(SemanticCubeNode *list, char* op1, char* op2, char* operation) {
    SemanticCubeNode *sNode = list;
    
    while (sNode != NULL) {
        if (strcmp(sNode->data,op1) == 0) {
            sNode = sNode->contents;
            while (sNode != NULL) {
                if (strcmp(sNode->data,op2) == 0) {
                    sNode = sNode->contents;
                    while (sNode != NULL) {
                        if (sNode->data == operation) return sNode->contents->data;
                        sNode = sNode->next;
                    }
                    break;
                }
                sNode = sNode->next;
            }
            break;
        }
        sNode = sNode->next;
    }
    
    return (char *)"error";
}


// FUNCTION: debugSemanticCube(lista)
// Return: void
//
// Imprime el cubo semantico para fines de debugging
//
void debugSemanticCube(SemanticCubeNode *list) {
    SemanticCubeNode *sNode = list;
    SemanticCubeNode *stNode;
    SemanticCubeNode *otNode;
    
    while (sNode != NULL) {
        stNode = sNode->contents;
        while (stNode != NULL) {
            otNode = stNode->contents;
            while (otNode != NULL) {
                printf("OP1:%s, OP2:%s, OPER:%s, RETURN:%s\n", sNode->data, stNode->data, otNode->data, otNode->contents->data);
                otNode = otNode->next;
            }
            stNode = stNode->next;
        }
        sNode = sNode->next;
        printf("\n");
    }
    
    printf("FIN\n");
}

// FUNCTION: deallocSemanticCube(lista)
// Return: void
//
// Libera memoria del cubo semantico
//
void deallocSemanticCube(SemanticCubeNode **list) {
    SemanticCubeNode *sNode = *list;
    SemanticCubeNode *stNode;
    SemanticCubeNode *otNode;
    SemanticCubeNode *fNode;
    
    while (sNode != NULL) {
        stNode = sNode->contents;
        while (stNode != NULL) {
            otNode = stNode->contents;
            while (otNode != NULL) {
                free(otNode->contents);
                fNode = otNode;
                otNode = otNode->next;
                free(fNode);
            }
            fNode = stNode;
            stNode = stNode->next;
            free(fNode);
        }
        fNode = sNode;
        sNode = sNode->next;
        free(fNode);
    }
}

/************** Init Semantic Cube *******************/

void initSemanticCube(SemanticCubeNode **list) {
    addOperNode(list,(char *)"numero");
    addSecondOperNode(list, (char *)"numero", (char *)"numero");
    addOperationNode(list, (char *)"numero", (char *)"numero", (char *)"10", (char *)"numero");
    addOperationNode(list, (char *)"numero", (char *)"numero", (char *)"20", (char *)"numero");
    addOperationNode(list, (char *)"numero", (char *)"numero", (char *)"30", (char *)"numero");
    addOperationNode(list, (char *)"numero", (char *)"numero", (char *)"40", (char *)"decimal");
    addOperationNode(list, (char *)"numero", (char *)"numero", (char *)"50", (char *)"numero");
    addOperationNode(list, (char *)"numero", (char *)"numero", (char *)"80", (char *)"booleano");
    addOperationNode(list, (char *)"numero", (char *)"numero", (char *)"90", (char *)"booleano");
    addOperationNode(list, (char *)"numero", (char *)"numero", (char *)"110", (char *)"booleano");
    addOperationNode(list, (char *)"numero", (char *)"numero", (char *)"100", (char *)"booleano");
    addSecondOperNode(list, (char *)"numero", (char *)"decimal");
    addOperationNode(list, (char *)"numero", (char *)"decimal", (char *)"10", (char *)"decimal");
    addOperationNode(list, (char *)"numero", (char *)"decimal", (char *)"20", (char *)"decimal");
    addOperationNode(list, (char *)"numero", (char *)"decimal", (char *)"30", (char *)"decimal");
    addOperationNode(list, (char *)"numero", (char *)"decimal", (char *)"40", (char *)"decimal");
    addOperationNode(list, (char *)"numero", (char *)"decimal", (char *)"50", (char *)"numero");
    addOperationNode(list, (char *)"numero", (char *)"decimal", (char *)"80", (char *)"booleano");
    addOperationNode(list, (char *)"numero", (char *)"decimal", (char *)"90", (char *)"booleano");
    
    addOperNode(list,(char *)"decimal");
    addSecondOperNode(list, (char *)"decimal", (char *)"numero");
    addOperationNode(list, (char *)"decimal", (char *)"numero", (char *)"10", (char *)"decimal");
    addOperationNode(list, (char *)"decimal", (char *)"numero", (char *)"20", (char *)"decimal");
    addOperationNode(list, (char *)"decimal", (char *)"numero", (char *)"30", (char *)"decimal");
    addOperationNode(list, (char *)"decimal", (char *)"numero", (char *)"40", (char *)"decimal");
    addOperationNode(list, (char *)"decimal", (char *)"numero", (char *)"50", (char *)"numero");
    addOperationNode(list, (char *)"decimal", (char *)"numero", (char *)"80", (char *)"booleano");
    addOperationNode(list, (char *)"decimal", (char *)"numero", (char *)"90", (char *)"booleano");
    addSecondOperNode(list, (char *)"decimal", (char *)"decimal");
    addOperationNode(list, (char *)"decimal", (char *)"decimal", (char *)"10", (char *)"decimal");
    addOperationNode(list, (char *)"decimal", (char *)"decimal", (char *)"20", (char *)"decimal");
    addOperationNode(list, (char *)"decimal", (char *)"decimal", (char *)"30", (char *)"decimal");
    addOperationNode(list, (char *)"decimal", (char *)"decimal", (char *)"40", (char *)"decimal");
    addOperationNode(list, (char *)"decimal", (char *)"decimal", (char *)"50", (char *)"numero");
    addOperationNode(list, (char *)"decimal", (char *)"decimal", (char *)"80", (char *)"booleano");
    addOperationNode(list, (char *)"decimal", (char *)"decimal", (char *)"90", (char *)"booleano");
    addOperationNode(list, (char *)"decimal", (char *)"decimal", (char *)"110", (char *)"booleano");
    addOperationNode(list, (char *)"decimal", (char *)"decimal", (char *)"100", (char *)"booleano");
    
    addOperNode(list,(char *)"texto");
    addSecondOperNode(list, (char *)"texto", (char *)"texto");
    addOperationNode(list, (char *)"texto", (char *)"texto", (char *)"110", (char *)"booleano");
    addOperationNode(list, (char *)"texto", (char *)"texto", (char *)"100", (char *)"booleano");
    
    addOperNode(list,(char *)"caracter");
    addSecondOperNode(list, (char *)"caracter", (char *)"caracter");
    addOperationNode(list, (char *)"caracter", (char *)"caracter", (char *)"110", (char *)"booleano");
    addOperationNode(list, (char *)"caracter", (char *)"caracter", (char *)"100", (char *)"booleano");
    
    addOperNode(list,(char *)"booleano");
    addSecondOperNode(list, (char *)"booleano", (char *)"booleano");
    addOperationNode(list, (char *)"booleano", (char *)"booleano", (char *)"110", (char *)"booleano");
    addOperationNode(list, (char *)"booleano", (char *)"booleano", (char *)"100", (char *)"booleano");
    addOperationNode(list, (char *)"booleano", (char *)"booleano", (char *)"60", (char *)"booleano");
    addOperationNode(list, (char *)"booleano", (char *)"booleano", (char *)"70", (char *)"booleano");
}

/****************** Dir Procs **********************/

typedef struct _node {
    char* name;
    char* returnType;
    int virtual_address;
	int numeroCuadruplo;
	Parametros *apunta;
    _node *local_variables;
    _node *next;
} Node;

// FUNCTION: addProc(lista, name, returnType);
// RETURN: void
//
// Inserta un Proc en una lista junto con su nombre, tipo de retorno y
// variable local.
//
void addProc(Node **list, char* name, char *returnType) {
    Node *tNode, *temp;
    temp = *list;
    tNode = (struct _node *)malloc(sizeof(struct _node));
    
    tNode->name = name;
    tNode->returnType = returnType;
	tNode->apunta = NULL;
    tNode->local_variables = NULL;

    if (temp == NULL) {
        *list = tNode;
    } else {
        while (temp->next != NULL) temp = temp->next;
        temp->next = tNode;
    }
}

// FUNCTION: findProc(lista, name)
// RETURN: Node
//
// Busca un Proc en una lista y lo devuelve. Devuelve nulo en caso
// de no existir.
//
Node* findProc(Node *list, char* name) {
    Node *tNode = list;
    
    while (tNode != NULL) {
        if (strcmp(tNode->name,name) == 0) return tNode;
        tNode = tNode->next;
    }
    
    return NULL;
}

// FUNCTION: findProcPos(directorioProcedimientos, nombreProceso)
// RETURN: int
//
// Regresa la cantidad total de parametros que tiene una funcion
//
int findProcPos(Node *list, char* name) {
    Node *tNode = list;
    int contador = 0;
	
    while (tNode != NULL) {
        if (strcmp(tNode->name,name) == 0) return contador;
        tNode = tNode->next;
	contador++;    }
    
    return -1;
}

// FUNCTION: findLocalVariableInProc(list, proc_name, var_name);
// RETURN: Node
//
// Busca una variable en un proc
//
Node* findLocalVariableInProc(Node *list, char* proc_name, char* var_name) {
    // Busca en las variables del Proc
    Node *tNode = findProc(list, proc_name);
    tNode = tNode->local_variables;
    
    while (tNode != NULL) {
        if (strcmp(tNode->name,var_name) == 0) return tNode;
        tNode = tNode->next;
    }
    
    return NULL;
}

// FUNCTION: addLocalVariableToProc(list, proc_name, var_name, returnType);
// RETURN: void
//
// Agrega una variable local a un Proc especifico en una lista
//
void addLocalVariableToProc(Node **list, char* proc_name, char* var_name, char* returnType, int virtual_address) {
    Node *procNode = findProc(*list, proc_name);
    Node *tNode = (struct _node *)malloc(sizeof(struct _node));
    
    tNode->name = var_name;
    tNode->returnType = returnType;
    tNode->local_variables = NULL;
    tNode->virtual_address = virtual_address;
    tNode->next = procNode->local_variables;
    
    procNode->local_variables = tNode;
}

// FUNCTION: dealloc(list)
// RETURN: void
//
// Libera la memoria de la lista automaticamente
//
void deallocProcDir(Node **list) {
    Node *tNode = *list;
    Node *sNode;
    
    while (tNode != NULL) {
        sNode = tNode;
        tNode = tNode->next;
        free(sNode);
    }
    
    *list = NULL;
}


// FUNCTION: debugList(lista)
// RETURN: void
//
// Imprime la informacion disponible de la lista de procs. Esto
// simplemente para uso de debugging.
//
void debugList(Node *list) {
    Node *tNode = list;
    Node *local_variables;
	int numParams = 0;
	
    while (tNode != NULL) {
        numParams = cuentaParametros(tNode->apunta);
		printf("%s, %s, %d, %d\n", tNode->name, tNode->returnType, numParams, tNode->numeroCuadruplo);
		
		/*printf("%s\n", tNode->name);
		imprime(tNode->apunta);*/
		tNode = tNode->next;
	}
}

// FUNCTION: imprimeCuadToFile(FILE **file, Cuadruplos *cuadruplo)
// RETURN: void
//
// Imprime los cuadruplos en el formato requerido en un archivo especifico mandado como parametro
//
void imprimeDirProcsToFile(FILE **file, Node *list) {
    Node *tNode = list;
	int numParams = 0;
	
	while(tNode != NULL) {
        numParams = cuentaParametros(tNode->apunta);
		fprintf(*file, "%s,%s,%d,%d,%d\n", tNode->name, tNode->returnType, numParams, tNode->numeroCuadruplo, tNode->virtual_address);
		tNode = tNode->next;
	}
}
