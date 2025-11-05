#ifndef ABSTREE_HEADER_FILE
#define ABSTREE_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include "../symboltable/symboltable.h"

typedef enum {
    TYPE_NONE,
    TYPE_ID,
    TYPE_INT,
    TYPE_CHAR,
    TYPE_BOOL,
} VarType;

typedef enum {
    NODE_CONN,
    NODE_LEAF,
    NODE_READ,
    NODE_WRITE,
    NODE_ASSGN,
    NODE_ADD,
    NODE_SUB,
    NODE_MUL,
    NODE_DIV,
    NODE_MOD,
    NODE_LT,
    NODE_GT,
    NODE_LE,
    NODE_GE,
    NODE_NE,
    NODE_EQ,
    NODE_IFELSE,
    NODE_WHILE,
    NODE_DOWHILE,
    NODE_REPEAT,
    NODE_ARRAY,
} NodeType;



typedef struct ASTNode{
    int value;                         // union of intval, strval, or varname
    VarType type;                           // type of the variable
    char* varName;                          // name of the variable
    NodeType nodetype;                      // node type information
    struct Gsymbol *GEntry;           // pointer to GST entry for global variables and functions
    struct ASTNode *left, *middle, *right;    // children nodes
} ASTNode;



/* Create a generic AST node */
ASTNode* TreeCreate(int val, VarType vtype, char* vname, NodeType ntype, ASTNode *l, ASTNode *m, ASTNode *r);

/* Make Leaf node (NUM constant or ID variable) */
ASTNode* makeLeafNode(int n, VarType vtype, char* vname);

/* Make arithmetic operator node (+, -, *, /) */
ASTNode* makeArithOPNode(NodeType ntype, ASTNode* l, ASTNode* r);

/* Make relational operator node (<, <=, >, >=, ==, !=) */
ASTNode* makeRelOPNode(NodeType ntype, ASTNode* l, ASTNode* r);

/* Make assignment statement node (ID = expr) */
ASTNode* makeAssgnNode(ASTNode* l, ASTNode* r);

/* Make READ statement node */
ASTNode* makeReadNode(ASTNode* l);

/* Make WRITE statement node */
ASTNode* makeWriteNode(ASTNode* l);

/* Make connector node (stmt1 ; stmt2) */
ASTNode* makeConnNode(ASTNode* l, ASTNode* r);

/* Make loop node (while, do-while, repeat-until) */
ASTNode* makeIterationNode(NodeType ntype, ASTNode *l, ASTNode* r);

/* Make IF-ELSE conditional node */
ASTNode* makeIfElseNode(ASTNode* l, ASTNode* m, ASTNode* r);

/* Make Int array node*/
ASTNode* makeArrayNode(char* arrName, VarType type, ASTNode* l);

#endif