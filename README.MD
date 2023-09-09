![C/C++ CI](https://github.com/filipewk/FCompiler/actions/workflows/c-cpp.yml/badge.svg)

# FCompiler

FCompiler is a simple C project made for compiling C projects and file into x86 32-bit machine code.
This compiler is made fully in C. It is 32-bit compatible.
<br />
At this stage the compiler performs lexical analysis and created a AST (Abstract Syntax Tree) for some types (still under developemnt).

## Usage
- To run th project locally, you need `gcc` and `make` installed. It works better on linux.
- Step 1: Clone the repository locally `git clone https://github.com/filipewk/FCompiler.git`.
- Step 2: Run `make` or `make clean` then `make` for clean build.
- Step 3: Run `./main` and the output should be `'Compiled OK'`.