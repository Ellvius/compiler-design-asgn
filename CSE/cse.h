#ifndef EXPR_LIST_H
#define EXPR_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ExprNode {
    char *result;       
    char *left;         
    char *op;           
    char *right;        
    struct ExprNode *next;
} ExprNode;

void insertExpression(ExprNode **head, char *result, char *left, char *op, char *right);

ExprNode *searchExpression(ExprNode *head, char *left, char *op, char *right);

void removeExpressionsWithOperand(ExprNode **head, char *var);

void clearExpressions(ExprNode **head);

void printExpressions(ExprNode *head);

#endif
