#!/bin/bash

set -euo pipefail  # safer: stop on errors, undefined vars, and failed pipes

# Config
PROJECT_ROOT="$(pwd)"

# To generate the output xsm code
pushd abstree >/dev/null
yacc -d abstree.y
lex abstree.l
popd >/dev/null

gcc -g abstree/lex.yy.c \
    abstree/y.tab.c \
    abstree/abstree.c \
    codegen/codegen.c \
    symboltable/symboltable.c \
    -o "$PROJECT_ROOT/expl"

"$PROJECT_ROOT/expl" "${1:-}"

cd ./CSE
./optimise.sh ../output.txt