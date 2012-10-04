void addProc(Node **list, char* name, char *returnType);
Node* findProc(Node *list, char* name);
Node* findLocalVariableInProc(Node *list, char* proc_name, char* var_name);
void addLocalVariableToProc(Node **list, char* proc_name, char* var_name, char* returnType);
void dealloc(Node **list);
void debugList(Node *list);