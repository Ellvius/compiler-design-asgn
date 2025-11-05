%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "y.tab.h"
    #include "abstree.h"
    int yyerror(const char *s);

    int val;
%}

digit           [0-9]
letter          [a-zA-Z]
identifier      {letter}({letter}|{digit})*

%%

"begin"     { return START_BLOCK; }
"end"       { return END_BLOCK; }
"decl"      { return DECL; }
"enddecl"   { return ENDDECL; }

"read"      { return READ; }
"write"     { return WRITE; }

"if"        { return IF; }
"then"      { return THEN; }
"else"      { return ELSE;}    
"endif"     { return ENDIF; }

"while"     { return WHILE; }
"do"        { return DO; }
"endwhile"  { return ENDWHILE; }
"repeat"    { return REPEAT; }
"until"     { return UNTIL; }

"int"       { return INT; }

"<="        { return LE; }
">="        { return GE; }
"!="        { return NE; }
"=="        { return EQ; }
"<"         { return LT; }
">"         { return GT; }

{digit}+            {yylval.intVal = atoi(yytext); return NUM;}

{identifier}        {yylval.idName = strdup(yytext); return ID;}

"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MUL; }
"/"         { return DIV; }
"%"         { return MOD; }
"="         { return ASSGN; }
";"         { return EOS; }
","         { return COMMA; }

[ \t\n]     { }
[()\[\]]        { return *yytext; }
.           { 
                fprintf(stderr, "Unknown character: %c\n", *yytext);
                exit(1);
            }

%%

int yywrap(void) {
    return 1;
}