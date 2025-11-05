%{
    
    #include "./cse.h"

    int yywrap();


    struct CSENode* CSEList = NULL;
    FILE* optimised = NULL;

%}

digit       [0-9]+
letter      [a-zA-Z]
identifier  {letter}({letter}|{digit}|_)*
op          [+\-/\*%]

%%
 
{identifier}" = "{identifier}([ ]{op}[ ]{identifier})?          {   findAndReplace(yytext); }
\n                                                              {   fprintf(optimised, "\n");   }
.                                                               {   fprintf(optimised, "%s", yytext);   }

%%

int yywrap() { return 1; }

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Error opening input file");
        return 1;
    }

    optimised = fopen("optimised_output.txt", "w");
    if (!optimised) {
        perror("Error opening output file");
        fclose(yyin);
        return 1;
    }

    yylex();

    fclose(yyin);
    fclose(optimised);

    return 0;
}