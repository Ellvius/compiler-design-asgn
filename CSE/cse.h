#ifndef CSE_H
#define CSE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum ops {
    NODE_ADD = 1,
    NODE_SUB = 2,
    NODE_MUL = 3,
    NODE_DIV = 4,
    NODE_MOD = 5
};

struct CSENode {
    int op;
    char* operand1;
    char* operand2;
    char* result;
    struct CSENode* next;
};

extern struct CSENode* CSEList;
extern FILE* optimised;

struct CSENode* searchCSE(int op, char* operand1, char* operand2);
void insertCSENode(int op, char* operand1, char* operand2, char* result);
void removeExpr(const char* operand);


void findAndReplace(char* expr);

#endif