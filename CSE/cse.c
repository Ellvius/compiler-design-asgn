#include "./cse.h"

static int tempNum = 0;

int findOP(char c){
    switch(c){
        case '+': return NODE_ADD;
        case '-': return NODE_SUB;
        case '*': return NODE_MUL;
        case '/': return NODE_DIV;
        case '%': return NODE_MOD;
    }
    return 0;
}

struct CSENode* newCSENode(int op, char* operand1, char* operand2, char* result){
    struct CSENode* node = malloc(sizeof(struct CSENode));

    node->op = op;
    node->operand1 = strdup(operand1);
    node->operand2 = strdup(operand2);
    node->result = strdup(result);
    node->next = NULL;
    
    return node;
}

struct CSENode* searchCSE(int op, char* operand1, char* operand2){

    struct CSENode* temp = CSEList;
    while(temp){
        if(temp->op == op && strcmp(temp->operand1, operand1) == 0 && strcmp(temp->operand2, operand2) == 0){
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

void insertCSENode(int op, char* operand1, char* operand2, char* result){


    if (op == NODE_ADD || op == NODE_MUL) {
        if (strcmp(operand1, operand2) > 0) {
            char* temp = operand1;
            operand1 = operand2;
            operand2 = temp;
        }
    }

    struct CSENode* node = newCSENode(op, operand1, operand2,result);

    if(!CSEList){
        CSEList = node;
        return;
    }
    
    struct CSENode* temp = CSEList;
    while(temp->next){
        temp = temp->next;
    }

    temp->next = node;
}

void removeExpr(const char* result) {
    struct CSENode* curr = CSEList;
    struct CSENode* prev = NULL;

    while (curr) {
        if (strcmp(curr->result, result) == 0) {
            struct CSENode* toDelete = curr;
            if (prev == NULL) {
                CSEList = curr->next;
                curr = CSEList;
            } else {
                prev->next = curr->next;
                curr = curr->next;
            }
            free(toDelete->operand1);
            free(toDelete->operand2);
            free(toDelete->result);
            free(toDelete);
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

void findAndReplace(char *expr) {
    
    char *lhs = strtok(expr, " ");     
    char *eq  = strtok(NULL, " ");     
    char *operand1 = strtok(NULL, " ");     
    char *op  = strtok(NULL, " ");      
    char *operand2 = strtok(NULL, " "); 


    if(op == NULL || operand2 == NULL){
        removeExpr(lhs);
        fprintf(optimised, "%s %s %s", lhs, eq, operand1);
        return;
    }
    
    int opCode = findOP(op[0]);

    if (opCode == NODE_ADD || opCode == NODE_MUL) {
        if (strcmp(operand1, operand2) > 0) {
            char* temp = operand1;
            operand1 = operand2;
            operand2 = temp;
        }
    }

    struct CSENode* node = searchCSE(opCode, operand1, operand2);
    

    if(node == NULL){
        fprintf(optimised, "%s = %s %s %s", lhs, operand1, op, operand2);
        insertCSENode(opCode, operand1, operand2, lhs);
    }else{
        fprintf(optimised, "%s = %s", lhs, node->result);
        removeExpr(lhs);
    }
}

