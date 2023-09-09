#ifndef CCOMPILER_H
#define CCOMPILER_H

#include <stdio.h>

enum
{
  COMPILE_FAILED_WITH_ERRORS,
  COMPILER_FILE_COMPILED_OK
};

struct compile_process
{
  int flags;

  struct compiler_process_input_file
  {
    FILE *fp;
    const char *abs_path;
  } cfile;

  FILE *ofile;
};

int compile_file(const char *filename, const char *out_filename, int flags);
struct compile_process *compile_process_create(const char *filename, const char *out_filename, int flags);

#endif