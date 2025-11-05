#include "symboltable.h"

Gsymbol *Ghead = NULL, *Gtail = NULL;

Gsymbol* GLookup(char * name){
    Gsymbol *temp = Ghead;

    while(temp != NULL && (strcmp(temp->name, name) != 0)){
        temp = temp->next;
    }

    return temp;
}

void GInstall(char *name, int type, int size){
    Gsymbol *newEntry = GLookup(name);
    
    if(newEntry != NULL){
        fprintf(stdout, "Variable re-initialized \"%s\"\n", name);
        exit(1);
    }

    newEntry = (Gsymbol*)malloc(sizeof(Gsymbol));
    newEntry->name = strdup(name);
    newEntry->type = type;
    newEntry->size = size;
    newEntry->next = NULL;

    if(Ghead != NULL){
        Gtail->next = newEntry;
        Gtail = newEntry;
    }
    else {
        Ghead = newEntry;
        Gtail = newEntry;
    }
}


char* tokenToString(int type){
    switch(type){
        case TYPE_NONE: return "NONE";
        case TYPE_ID: return "ID";
        case TYPE_INT:  return "INT";
        case TYPE_CHAR: return "CHAR";
        case TYPE_BOOL: return "BOOL";
        default: return "UNDEFINED";
    }
}

void printSymbolTable(void){
    Gsymbol* temp = Ghead;

    while(temp != NULL){
        fprintf(stdout, "%s----%s----%d\n", temp->name, tokenToString(temp->type), temp->size);
        temp = temp->next;
    }
}