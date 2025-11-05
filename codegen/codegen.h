#ifndef CODE_GEN_HEADER_FILE
#define CODE_GEN_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include "../abstree/abstree.h"

#define RegIndex int

RegIndex getTemp(void);
int getLabel(void);

char* codeGenOP(ASTNode *node, FILE* fp);
char* codeGenNODE(ASTNode* node, FILE* fp);
int codeGen(ASTNode *node);

#endif