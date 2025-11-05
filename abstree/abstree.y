%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "../abstree/abstree.h"
    #include "../codegen/codegen.h"
    #include "../symboltable/symboltable.h"

    extern FILE *yyin;

    int yylex(void);
    int yyerror(const char *s);

%}

%union{
    struct ASTNode *node;
    char* idName;
    int intVal;
}

%token START_BLOCK END_BLOCK DECL ENDDECL READ WRITE 
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE REPEAT UNTIL
%token PLUS MINUS MUL DIV MOD
%token LT GT LE GE NE EQ
%token ASSGN EOS COMMA 
%token INT 
%token <intVal> NUM
%token <idName> ID
%type <node> Expr Program Slist Stmt Code
%type <node> InputStmt OutputStmt AsgStmt IfStmt IterativeStmt
%type <node>  Identifier

%right ASSGN
%nonassoc NE EQ
%nonassoc LT LE GT GE
%left PLUS MINUS
%left MUL DIV MOD

%%

Program     :   Declarations Code                   {
                                                        $$ = $2;
                                                        printSymbolTable();
                                                        // codeGen($2);
                                                        exit(0);
                                                    }

Code        :   START_BLOCK Slist END_BLOCK         {
                                                        $$ = $2;
                                                    }
            |   START_BLOCK END_BLOCK               {
                                                        fprintf(stdout, "Empty program\n");
                                                        exit(0);
                                                    }  
            ;

Slist       :   Slist Stmt              {$$ = makeConnNode($1, $2);}
            |   Stmt                    {$$ = $1;}
            |   Declarations            {}
            ;

Stmt        :   IfStmt                  {$$ = $1;}
            |   IterativeStmt           {$$ = $1;}
            |   InputStmt               {$$ = $1;}
            |   OutputStmt              {$$ = $1;}
            |   AsgStmt                 {$$ = $1;}
            ;

Declarations:   DECL DeclList ENDDECL   {}
            |   DECL ENDDECL            {}
            ;

DeclList    :   DeclList Decl           {}
            |   Decl                    {}
            ;

Decl        :   INT VarList EOS        {}
            ;

VarList     :   VarList COMMA ID '['NUM']'              {GInstall($3, TYPE_INT, $5);} 
            |   VarList COMMA ID                        {GInstall($3, TYPE_INT, 1);}
            |   ID '['NUM']'                            {GInstall($1, TYPE_INT, $3);}
            |   ID                                      {GInstall($1, TYPE_INT, 1);}
            ;

IfStmt      :   IF '(' Expr ')' THEN Slist ELSE Slist ENDIF EOS     {$$ = makeIfElseNode($3, $6, $8);}
            |   IF '(' Expr ')' THEN Slist ENDIF EOS                {$$ = makeIfElseNode($3, $6, NULL);}
            ;

IterativeStmt   :   WHILE '(' Expr ')' DO Slist ENDWHILE EOS        {$$ = makeIterationNode(NODE_WHILE, $3, $6);}
                |   DO Slist WHILE '(' Expr ')' EOS                 {$$ = makeIterationNode(NODE_DOWHILE, $5, $2);}
                |   REPEAT Slist UNTIL '(' Expr ')' EOS             {$$ = makeIterationNode(NODE_REPEAT, $5, $2);}
                ;

InputStmt   :   READ '(' Identifier ')' EOS         {$$ = makeReadNode($3);}
            ;

OutputStmt  :   WRITE '(' Expr ')' EOS              {$$ = makeWriteNode($3);}
            ;

AsgStmt     :   Identifier ASSGN Expr EOS           {$$ = makeAssgnNode($1, $3);}
            ;


Identifier  :   ID '['Expr']'               {$$ = makeArrayNode($1, TYPE_ID, $3);}
            |   ID                          {$$ = makeLeafNode(0, TYPE_ID, $1);}
            ;

Expr        :   Expr PLUS Expr          {$$ = makeArithOPNode(NODE_ADD, $1, $3);}
            |   Expr MINUS Expr         {$$ = makeArithOPNode(NODE_SUB, $1, $3);}
            |   Expr MUL Expr           {$$ = makeArithOPNode(NODE_MUL, $1, $3);}
            |   Expr DIV Expr           {$$ = makeArithOPNode(NODE_DIV, $1, $3);}
            |   Expr MOD Expr           {$$ = makeArithOPNode(NODE_MOD, $1, $3);}
            |   '(' Expr ')'            {$$ = $2;}
            |   Expr LT Expr            {$$ = makeRelOPNode(NODE_LT, $1, $3);}
            |   Expr GT Expr            {$$ = makeRelOPNode(NODE_GT, $1, $3);}
            |   Expr LE Expr            {$$ = makeRelOPNode(NODE_LE, $1, $3);}
            |   Expr GE Expr            {$$ = makeRelOPNode(NODE_GE, $1, $3);}
            |   Expr NE Expr            {$$ = makeRelOPNode(NODE_NE, $1, $3);}
            |   Expr EQ Expr            {$$ = makeRelOPNode(NODE_EQ, $1, $3);}
            |   Identifier              {$$ = $1;}
            |   NUM                     {$$ = makeLeafNode($1, TYPE_INT, NULL);}
            ;

%%

int yyerror(const char *s){
    printf("yyerror %s\n",s);
    exit(1);
}


int main(int argc, char* argv[]){
    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(!yyin){
            printf("Couldn't find the input file!\n");
            return 1;
        }
    }
    else {
        yyin = stdin;
    }
    
    yyparse();

    if(yyin != stdin) fclose(yyin);
    return 0;
}