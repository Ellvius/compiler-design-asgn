#include "abstree.h"

ASTNode* TreeCreate(int val, VarType vtype, char* vname, NodeType ntype, ASTNode *l, ASTNode* m, ASTNode *r){
    ASTNode* temp = (ASTNode*)malloc(sizeof(ASTNode));
    Gsymbol* var = NULL;

    temp->value = val;
    temp->type = vtype;
    temp->varName = vname;
    temp->nodetype = ntype;
    temp->left = l;
    temp->middle = m;
    temp->right = r;

    if(temp->type == TYPE_ID){
        var = GLookup(vname);
        if(!var){
            fprintf(stderr, "Undefined variables: %s\n", vname);
            exit(1);
        }
        temp->type = var->type;
    }
    temp->GEntry = var;

    return temp;
}

ASTNode* makeLeafNode(int n, VarType vtype, char* vname){
    ASTNode* temp = TreeCreate(n, vtype, vname, NODE_LEAF, NULL, NULL, NULL);    
    return temp;
}

ASTNode* makeArithOPNode(NodeType ntype, ASTNode* l, ASTNode* r){
    if(l->type != TYPE_INT || r->type != TYPE_INT){
        fprintf(stderr, "type mismatch: arith\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(0, TYPE_INT, NULL, ntype, l, NULL, r);    
    return temp;
}

ASTNode* makeRelOPNode(NodeType ntype, ASTNode* l, ASTNode* r){
    if(l->type != r->type){
        fprintf(stderr, "type mismatch: relop\n");
        exit(1);
    }
    if(l->type != TYPE_INT){
        fprintf(stderr, "type mismatch: relop (not int)\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(0, TYPE_BOOL, NULL, ntype, l, NULL, r);    
    return temp;
}

ASTNode* makeAssgnNode(ASTNode* l, ASTNode* r){
    if((l->nodetype != NODE_LEAF && l->nodetype != NODE_ARRAY) || (l->varName == NULL)){
        fprintf(stderr, "type mismatch: assign (ID)\n");
        exit(1);
    }

    if(l->type != r->type){
        fprintf(stderr, "type mismatch: assign %d %d\n", l->type, r->type);
        exit(1);
    }

    ASTNode* temp = TreeCreate(0, TYPE_NONE, NULL, NODE_ASSGN, l, NULL, r);    
    return temp;
}

ASTNode* makeReadNode(ASTNode* l){
    if(l->type != TYPE_INT){
        fprintf(stderr, "type mismatch: read %d\n", l->type);
        exit(1);
    }

    ASTNode* temp = TreeCreate(0, TYPE_NONE, NULL, NODE_READ, l, NULL, NULL);
    return temp;
}

ASTNode* makeWriteNode(ASTNode* l){
    if(l->type != TYPE_INT && l->type != TYPE_BOOL){
        fprintf(stderr, "type mismatch: write %d\n", l->type);
        exit(1);
    }

    ASTNode* temp = TreeCreate(0, TYPE_NONE, NULL, NODE_WRITE, l, NULL, NULL);    
    return temp;
}

ASTNode* makeConnNode(ASTNode* l, ASTNode* r){
    ASTNode* temp = TreeCreate(0, TYPE_NONE, NULL, NODE_CONN, l, NULL, r);    
    return temp;
}

ASTNode* makeIterationNode(NodeType ntype, ASTNode *l, ASTNode* r){
    if(l->type != TYPE_BOOL){
        fprintf(stderr, "type mismatch: while\n");
        exit(1);
    }
    
    ASTNode* temp = TreeCreate(0, TYPE_NONE, NULL, ntype, l, NULL, r);
    return temp;
}

ASTNode* makeIfElseNode(ASTNode* l, ASTNode* m, ASTNode* r){
    if(l->type != TYPE_BOOL){
        fprintf(stderr, "type mismatch: ifelse\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(0, TYPE_NONE, NULL, NODE_IFELSE, l, m, r);
    return temp;
}


ASTNode* makeArrayNode(char* arrName, VarType type, ASTNode* l){
    Gsymbol* var = GLookup(arrName);

    if(var->size == 0){
        fprintf(stderr, "Not an array: %s\n", arrName);
        exit(1);
    }
    ASTNode* temp = TreeCreate(0, TYPE_ID, arrName, NODE_ARRAY, l, NULL, NULL);
    return temp;
}

ASTNode *makeLogicOPNode(NodeType ntype, ASTNode *l, ASTNode *r){
    if (l->type != TYPE_BOOL || r->type != TYPE_BOOL)
    {
        fprintf(stderr, "type mismatch: boolean operation\n");
        exit(1);
    }

    ASTNode *temp = TreeCreate(0, TYPE_BOOL, NULL, ntype, l, NULL, r);
    return temp;
}