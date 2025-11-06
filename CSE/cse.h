#ifndef EXPR_LIST_H
#define EXPR_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
   Structure to represent a single expression:
   e.g. t1 = a + b  →  op = "+", left = "a", right = "b", result = "t1"
*/
typedef struct ExprNode {
    char *result;       // result variable (e.g. t1)
    char *left;         // left operand (e.g. a)
    char *op;           // operator (e.g. +)
    char *right;        // right operand (e.g. b)
    struct ExprNode *next;
} ExprNode;

/* Insert a new expression if not already present */
void insertExpression(ExprNode **head, const char *result,
                      const char *left, const char *op, const char *right);

/* Search for an existing expression by operator and operands */
ExprNode *searchExpression(ExprNode *head, const char *left,
                           const char *op, const char *right);

/* Remove all expressions where given variable appears as operand */
void removeExpressionsWithOperand(ExprNode **head, const char *var);

/* Delete the entire expression list */
void clearExpressions(ExprNode **head);

/* Debug helper to print all expressions */
void printExpressions(const ExprNode *head);

#endif
