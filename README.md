# COMPILER DESIGN ASSIGNMENT - COMMON SUBEXPRESSION ELIMINATION

# How to Run the Project

## Requirements

Make sure to have the following installed:
  - gcc
  - lex
  - yacc
  - bash

If not install using

```bash
sudo apt install build-essential lex yacc
```

## Steps to Build and Run

1. Make the script executable (if not already):
```bash
chmod +x run.sh
```

2. Run the project using the provided script:
```bash
./run.sh <input_file_path>
```
Example:
```bash
./run.sh input.txt
```

- This command will:

  - Generate the parser and lexer files
  
  - Compile all source files into an executable named expl
  
  - Run the compiler on input.txt
  
  - Optimize the generated XSM code using CSE/optimise.sh

3. The generated output code will be available in:
```bash
output.txt
```

4. The optimized output code will be available in:
```bash
optimized.txt
```

## Manual Run (Optional)
To only compile and run without optimization:
```bash
gcc -g abstree/lex.yy.c \ 
    abstree/y.tab.c \ 
    abstree/abstree.c \
    codegen/codegen.c \
    symboltable/symboltable.c \
    -o expl
./expl input.txt
```

To optimize run:
```bash
cd ./CSE
```
```bash
./optimise.sh <relative_output_file_path>
```
Example:
```bash
./optimise.sh ../output.txt
```

# Team Members
- NIRANJAN V - B230466CS
- MUHAMMAD SWALIH K M - B231099CS
- LISHIN V S - B231045CS