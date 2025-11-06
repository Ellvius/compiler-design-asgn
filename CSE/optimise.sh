#!/bin/bash
yacc -d cse.y
lex cse.l
gcc lex.yy.c y.tab.c cse.c -o optimizer
./optimizer "$1"
