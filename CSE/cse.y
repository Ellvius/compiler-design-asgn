%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "cse.h"
    #include <regex.h>
    #include <ctype.h>
    #include <stdbool.h>

    int yylex(void);
    void yyerror(const char *s);
    extern FILE *yyin;
    extern int hasCondition;     
    ExprNode *exprList = NULL;    
    FILE* output = NULL;
%}

%union {
    char *str;
}

%token <str> ID TEMP NUM
%token <str> PLUS MINUS MUL DIV MOD LT GT LE GE EQ NE
%type <str> Operand Operator
%token READ WRITE
%token ASSIGN
%token LPAREN RPAREN
%token LBRACKET RBRACKET

%%

Program     : Program Line
            | Line
            ;

Line        : Assignment '\n'
            | IOStmt '\n'
            | '\n'
            ;

Assignment
    : ID ASSIGN Operand
        {
            removeExpressionsWithOperand(&exprList, $1);
            fprintf(output, "%s = %s\n", $1, $3);
            free($1); free($3);
        }

    | TEMP ASSIGN Operand
        {   fprintf(output, "%s = %s\n", $1, $3);   }

    | ID ASSIGN Operand Operator Operand
        {
            ExprNode *found = searchExpression(exprList, $3, $4, $5);
            if (found) {
                fprintf(output, "%s = %s\n", $1, found->result);
            } else {
                insertExpression(&exprList, $1, $3, $4, $5);
                fprintf(output, "%s = %s %s %s\n", $1, $3, $4, $5);
            }
            removeExpressionsWithOperand(&exprList, $1);
            free($1); free($3); free($4); free($5);
        }

    | TEMP ASSIGN Operand Operator Operand
        {
            ExprNode *found = searchExpression(exprList, $3, $4, $5);
            if (found) {
                fprintf(output, "%s = %s\n", $1, found->result);
            } else {
                insertExpression(&exprList, $1, $3, $4, $5);
                fprintf(output, "%s = %s %s %s\n", $1, $3, $4, $5);
            }
            free($1); free($3); free($4); free($5);
        }

    | ID LBRACKET TEMP RBRACKET ASSIGN Operand
        {
            char buffer[128];
            snprintf(buffer, sizeof(buffer), "%s[%s]", $1, $3);
            removeExpressionsWithOperand(&exprList, buffer);
            removeExpressionsWithOperand(&exprList, $1);
            fprintf(output, "%s[%s] = %s\n", $1, $3, $6);
            free($1); free($3); free($6);
        }

    | ID LBRACKET TEMP RBRACKET ASSIGN Operand Operator Operand
        {
            char buffer[128];
            snprintf(buffer, sizeof(buffer), "%s[%s]", $1, $3);

            ExprNode *found = searchExpression(exprList, $6, $7, $8);
            if (found) {
                fprintf(output, "%s[%s] = %s\n", $1, $3, found->result);
            } else {
                insertExpression(&exprList, buffer, $6, $7, $8);
                fprintf(output, "%s[%s] = %s %s %s\n", $1, $3, $6, $7, $8);
            }

            removeExpressionsWithOperand(&exprList, buffer);
            removeExpressionsWithOperand(&exprList, $1);
            free($1); free($3); free($6); free($7); free($8);
        }
    ;

Operand     : ID
            | TEMP
            | NUM
            ;

Operator    : PLUS      {   $$ = $1;    }
            | MINUS     {   $$ = $1;    }
            | MUL       {   $$ = $1;    }
            | DIV       {   $$ = $1;    }
            | MOD       {   $$ = $1;    }
            | LT        {   $$ = $1;    }
            | GT        {   $$ = $1;    }
            | LE        {   $$ = $1;    }
            | GE        {   $$ = $1;    }
            | EQ        {   $$ = $1;    }
            | NE        {   $$ = $1;    }
            ;

IOStmt
            : READ LPAREN ID RPAREN                         { fprintf(output, "read(%s)\n", $3);removeExpressionsWithOperand(&exprList, $3); free($3); }
            | READ LPAREN ID LBRACKET TEMP RBRACKET RPAREN  { fprintf(output, "read(%s[%s])\n", $3, $5);removeExpressionsWithOperand(&exprList, $3); free($3); free($5); }
            | WRITE LPAREN Operand RPAREN                   { fprintf(output, "write(%s)\n", $3);free($3); }
            ;

%%

void yyerror(const char *s){
    fprintf(stderr, "Error: %s\n", s);
}


bool hasLabel(char *filename) {
    FILE *fp = fopen(filename, "r");
    bool res = false;

    char line[1024];
    while(fgets(line, sizeof(line), fp)){
        int len = 0;
        if(line[len] != '\0' && line[len++] == 'L'){
            bool flag = false;
            while(line[len] != '\0' && isdigit(line[len])){
                len++;
                flag = true;
            }
            if(flag && line[len] == ':'){
                fclose(fp);
                return true;
            }
        }
    }

    fclose(fp);
    return false;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }

    yyin = fopen(argv[1], "r");
    output = fopen("optimised.txt", "w");

    if (hasLabel(argv[1])) {
        char buffer[1024];
        rewind(yyin);
        while (fgets(buffer, sizeof(buffer), yyin))
            fputs(buffer, output);
        printf("[INFO] Found label line — skipping optimization.\n");
    } else {
        printf("[INFO] No label line found — running optimizer.\n");
        yyparse();
    }

    fclose(yyin);
    fclose(output);
    clearExpressions(&exprList);
    return 0;
}


