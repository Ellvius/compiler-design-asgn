%{
#include "y.tab.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

%}

%%
[ \t\r]+                    ;
\n                          { return '\n'; }

"read"                      { return READ; }
"write"                     { return WRITE; }

"t"[0-9]+                   {
                                yylval.str = strdup(yytext);
                                return TEMP;
                            }

[a-zA-Z_][a-zA-Z0-9_]*      {
                                yylval.str = strdup(yytext);
                                return ID;
                            }

[0-9]+                      {
                                yylval.str = strdup(yytext);
                                return NUM;
                            }

"=="                        { yylval.str = strdup("=="); return EQ; }
"!="                        { yylval.str = strdup("!="); return NE; }
"<="                        { yylval.str = strdup("<="); return LE; }
">="                        { yylval.str = strdup(">="); return GE; }
"<"                         { yylval.str = strdup("<");  return LT; }
">"                         { yylval.str = strdup(">");  return GT; }

"+"                         { yylval.str = strdup("+");  return PLUS; }
"-"                         { yylval.str = strdup("-");  return MINUS; }
"*"                         { yylval.str = strdup("*");  return MUL; }
"/"                         { yylval.str = strdup("/");  return DIV; }
"%"                         { yylval.str = strdup("%"); return MOD; }

"="                         { return ASSIGN; }
"("                         { return LPAREN; }
")"                         { return RPAREN; }
"["                         { return LBRACKET; }
"]"                         { return RBRACKET; }

.       
%%

int yywrap(void){ return 1; }
