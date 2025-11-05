#include "codegen.h"
#include "../symboltable/symboltable.h"

static int tempNum = 0;
static int lnum = 0;

/*========== XSM CODE GENERATION IMPLEMENTATION ==========*/

RegIndex getTemp(void){
    return tempNum++;
}

int getLabel(void){
    return lnum++;
}

char *numToString(int num, int temp)
{
    char buffer[20];
    if(temp == 1){
        sprintf(buffer, "t%d", num); 
    }
    else {
        sprintf(buffer, "%d", num);
    }
    return strdup(buffer);      // duplicate into heap memory
}

char* codeGenOP(ASTNode *node, FILE *fp){
    char* t1 = codeGenNODE(node->left, fp);
    char* t2 = codeGenNODE(node->right, fp);

    int temp = getTemp();

    const char *op = NULL;
    switch (node->nodetype){
        case NODE_ADD: op = "+"; break;
        case NODE_SUB: op = "-"; break;
        case NODE_MUL: op = "*"; break;
        case NODE_DIV: op = "/"; break;
        case NODE_MOD: op = "%%"; break;
        case NODE_LT: op = "<"; break;
        case NODE_GT: op = ">"; break;
        case NODE_LE: op = "<="; break;
        case NODE_GE: op = ">="; break;
        case NODE_EQ: op = "=="; break;
        case NODE_NE: op = "!="; break;
    }

    if (op != NULL){
        fprintf(fp, "t%d = %s %s %s\n", temp, t1, op, t2);
    }

    return numToString(temp, 1);
}

char* codeGenNODE(ASTNode* node, FILE* fp){
    switch(node->nodetype){
        case NODE_LEAF: {
            if(node->varName == NULL){
                return numToString(node->value, 0);
            }
            else {
                return node->varName;
            }
        }

        case NODE_READ: {
            ASTNode *id = node->left;

            if (id->nodetype == NODE_ARRAY)
            {
                int t = getTemp();
                char* offsetRow = codeGenNODE(id->left, fp);
                fprintf(fp, "t%d = %s * 4\n", t, offsetRow);
                fprintf(fp, "read(%s[t%d])\n", id->varName, t);
            }
            else
            {
                fprintf(fp, "read(%s)\n", id->varName);
            }
            break;
        }

        case NODE_WRITE: {
            char* t = codeGenNODE(node->left, fp);
            fprintf(fp, "write(%s)\n", t);
            break;
        }

        case NODE_IFELSE: {
            int label_1 = getLabel(); // true
            int label_2 = getLabel(); // false
            int label_3 = getLabel();

            fprintf(fp, "\n");
            char* cond = codeGenNODE(node->left, fp); // code for if condition
            fprintf(fp, "if (%s) goto L%d\n",cond, label_1);
            fprintf(fp, "goto L%d\n", label_2);

            fprintf(fp, "L%d:\n", label_1); // true
            codeGenNODE(node->middle, fp);

            if (node->right)
            {
                fprintf(fp, "goto L%d\n", label_3);
            }

            fprintf(fp, "L%d:\n", label_2);
            if (node->right)
            {
                codeGenNODE(node->right, fp); // false
                fprintf(fp, "L%d:\n", label_3);
            }

            fprintf(fp, "\n");
            break;
        }

        case NODE_WHILE: {
            int L1 = getLabel(); // start
            int L2 = getLabel(); // body
            int L3 = getLabel(); // exit

            fprintf(fp, "\n");
            fprintf(fp, "L%d:\n", L1);
            char * cond = codeGenNODE(node->left, fp);
            fprintf(fp, "if (%s) goto L%d\n", cond, L2);

            fprintf(fp, "goto L%d\n", L3);

            fprintf(fp, "L%d:\n", L2);
            codeGenNODE(node->right, fp);

            fprintf(fp, "goto L%d\n", L1);
            fprintf(fp, "L%d:\n", L3);
            fprintf(fp, "\n");
            break;
        }

        case NODE_DOWHILE: {
            int L1 = getLabel(); // start of loop

            fprintf(fp, "\n");
            fprintf(fp, "L%d:\n", L1);
            codeGenNODE(node->right, fp); // body
            char *cond = codeGenNODE(node->left, fp);
            fprintf(fp, "if (%s) goto L%d\n", cond, L1);
            fprintf(fp, "\n");
            break;
        }

        case NODE_REPEAT: {
            int L1 = getLabel(); // start of loop

            fprintf(fp, "\n");
            fprintf(fp, "L%d:\n", L1);
            codeGenNODE(node->right, fp); // body
            char *cond = codeGenNODE(node->left, fp);
            fprintf(fp, "ifFalse (%s) goto L%d\n", cond, L1);
            fprintf(fp, "\n");
            break;
        }

        case NODE_ASSGN: {
            ASTNode *id = node->left;
            char* expr = codeGenNODE(node->right, fp);

            if (id->nodetype == NODE_ARRAY)
            {
                int t = getTemp();
                char* offsetRow = codeGenNODE(id->left, fp);
                fprintf(fp, "t%d = %s * 4\n", t, offsetRow);

                fprintf(fp, "%s[t%d] = %s\n", id->GEntry->name, t, expr);
            }
            else
            {
                fprintf(fp, "%s = %s\n", id->GEntry->name, expr);
            }
            break;
        }

        case NODE_ARRAY: {
            char* index = codeGenNODE(node->left, fp);
            int temp = getTemp();

            fprintf(fp, "t%d = %d * 4\n", temp, index);
            fprintf(fp, "t%d = %s[%s]\n", temp, node->GEntry->name, index); // free offsetRow
            return numToString(temp, 1);
        }

        case NODE_CONN: {
            codeGenNODE(node->left, fp);
            codeGenNODE(node->right, fp);
            return NULL;
        }

        case NODE_AND: {
            int t = getTemp();
            int L1 = getLabel();
            int L2 = getLabel();
            int L3 = getLabel();

            char *left = codeGenNODE(node->left, fp);
            fprintf(fp, "\tifFalse (%s) goto L%d\n", left, L1);
            
            char *right = codeGenNODE(node->right, fp);
            fprintf(fp, "\tifFalse (%s) goto L%d\n", right, L1);
            fprintf(fp, "\tt%d = 1\n", t);
            fprintf(fp, "\tgoto L%d\n", L2);
            fprintf(fp, "L%d:\n", L1);
            fprintf(fp, "\tt%d = 0\n", t);
            fprintf(fp, "L%d:\n", L2);

            fprintf(fp, "\n");
            return numToString(t, 1);
        }

        case NODE_OR: {
            int t = getTemp();
            int L1 = getLabel();
            int L2 = getLabel();
            int L3 = getLabel();

            char *left = codeGenNODE(node->left, fp);
            fprintf(fp, "\tif (%s) goto L%d\n", left, L1);
            
            char *right = codeGenNODE(node->right, fp);
            fprintf(fp, "\tif (%s) goto L%d\n", right, L1);
            fprintf(fp, "\tt%d = 0\n", t);
            fprintf(fp, "\tgoto L%d\n", L2);
            fprintf(fp, "L%d:\n", L1);
            fprintf(fp, "\tt%d = 1\n", t);
            fprintf(fp, "L%d:\n", L2);

            fprintf(fp, "\n");
            return numToString(t, 1);
        }

        case NODE_NOT: {
            int t = getTemp();
            int L1 = getLabel();
            int L2 = getLabel();

            char *operand = codeGenNODE(node->left, fp);

            fprintf(fp, "\tif (%s) goto L%d\n", operand, L1);
            fprintf(fp, "\tt%d = 1\n", t); // true if operand is false
            fprintf(fp, "\tgoto L%d\n", L2);
            fprintf(fp, "L%d:\n", L1);
            fprintf(fp, "\tt%d = 0\n", t); // false if operand is true
            fprintf(fp, "L%d:\n", L2);

            fprintf(fp, "\n");
            return numToString(t, 1);
        }

        default:
            return codeGenOP(node, fp);
    }
    return NULL;
}


int codeGen(ASTNode *node){
    FILE *fp = fopen("./output.txt", "w");     // output xsm file
    if(!fp){
        printf("Couldn't create output file\n");
        exit(1);
    }

    codeGenNODE(node, fp);
    
    fclose(fp);
    return 0;
}
