#include "cse.h"

static ExprNode *createNode(const char *result, const char *left,
                            const char *op, const char *right) {
    ExprNode *node = (ExprNode *)malloc(sizeof(ExprNode));
    node->result = strdup(result);
    node->left = strdup(left);
    node->op = strdup(op);
    node->right = strdup(right);
    node->next = NULL;
    return node;
}

static int isSameExpression(const ExprNode *node, const char *left,
                            const char *op, const char *right) {
    return (strcmp(node->op, op) == 0 &&
            strcmp(node->left, left) == 0 &&
            strcmp(node->right, right) == 0);
}

void insertExpression(ExprNode **head, const char *result,
                      const char *left, const char *op, const char *right) {
    if (!head) return;

    if (searchExpression(*head, left, op, right) != NULL)
        return;

    ExprNode *newNode = createNode(result, left, op, right);
    newNode->next = *head;
    *head = newNode;
}

ExprNode *searchExpression(ExprNode *head, const char *left,
                           const char *op, const char *right) {
    for (ExprNode *cur = head; cur != NULL; cur = cur->next) {
        if (isSameExpression(cur, left, op, right))
            return cur;
    }
    return NULL;
}

void removeExpressionsWithOperand(ExprNode **head, const char *var) {
    if (!head || !*head) return;

    ExprNode *cur = *head;
    ExprNode *prev = NULL;

    while (cur) {
        int match = (strcmp(cur->left, var) == 0 || strcmp(cur->right, var) == 0);
        if (match) {
            ExprNode *toDelete = cur;
            if (prev)
                prev->next = cur->next;
            else
                *head = cur->next;

            cur = cur->next;
            free(toDelete->result);
            free(toDelete->left);
            free(toDelete->op);
            free(toDelete->right);
            free(toDelete);
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}

void clearExpressions(ExprNode **head) {
    if (!head) return;
    ExprNode *cur = *head;
    while (cur) {
        ExprNode *tmp = cur;
        cur = cur->next;
        free(tmp->result);
        free(tmp->left);
        free(tmp->op);
        free(tmp->right);
        free(tmp);
    }
    *head = NULL;
}

void printExpressions(const ExprNode *head) {
    for (const ExprNode *cur = head; cur; cur = cur->next) {
        printf("%s = %s %s %s\n", cur->result, cur->left, cur->op, cur->right);
    }
}
