#ifndef CCOMPILER_H
#define CCOMPILER_H

#include <stdio.h>
#include <stdbool.h>

enum
{
  LEXICAL_ANALYSIS_ALL_OK,
  LEXICAL_ANALYSIS_INPUT_ERROR,
};

enum
{
  COMPILE_FAILED_WITH_ERRORS,
  COMPILER_FILE_COMPILED_OK
};

enum
{
  TOKEN_TYPE_IDENTIFIER,
  TOKEN_TYPE_KEYWORD,
  TOKEN_TYPE_SYMBOL,
  TOKEN_TYPE_NUMBER,
  TOKEN_TYPE_STRING,
  TOKEN_TYPE_COMMENT,
  TOKEN_TYPE_NEWLINE
};

struct pos
{
  int line;
  int col;
  const char *filename;
};

struct lex_process
{
  struct pos pos;
  struct vector *token_vec;
  struct compile_process *compiler;

  int current_expression_count;
  struct buffer *parentheses_buffer;
  struct lex_process_functions *function;
  void *private;
};

struct lex_process;
typedef char (*LEX_PROCESS_NEXT_CHAR)(struct lex_process *process);
typedef char (*LEX_PROCESS_PEEK_CHAR)(struct lex_process *process);
typedef void (*LEX_PROCESS_PUSH_CHAR)(struct lex_process *process, char c);

struct lex_process_functions
{
  LEX_PROCESS_NEXT_CHAR next_char;
  LEX_PROCESS_PEEK_CHAR peek_char;
  LEX_PROCESS_PUSH_CHAR push_char;
};

struct token
{
  int type;
  int flags;

  union
  {
    char cval;
    const char *sval;
    unsigned int inum;
    unsigned long lnum;
    unsigned long long llnum;
    void *any;
  };

  bool whitespace;
  const char *between_bracktes;
};

struct compile_process
{
  int flags;
  struct pos pos;
  struct compiler_process_input_file
  {
    FILE *fp;
    const char *abs_path;
  } cfile;

  FILE *ofile;
};

int compile_file(const char *filename, const char *out_filename, int flags);
struct compile_process *compile_process_create(const char *filename, const char *out_filename, int flags);

char compile_process_next_char(struct lex_process *lex_process);
char compile_process_peek_char(struct lex_process *lex_process);
void compile_process_push_char(struct lex_process *lex_process, char c);

struct lex_process *lex_process_create(struct compile_process *compiler, struct lex_process_functions *functions, void *private);
void lex_process_free(struct lex_process *process);
void *lex_process_private(struct lex_process *process);
struct vector *lex_process_tokens(struct lex_process *process);
int lex(struct lex_process *process);
#endif