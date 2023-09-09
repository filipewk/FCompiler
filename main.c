#include <stdio.h>
#include "helpers/vector.h"
#include "compiler.h"

void displayCompileStatus(int status)
{
  switch (status)
  {
  case COMPILER_FILE_COMPILED_OK:
    printf("Compiled OK\n");
    break;
  case COMPILE_FAILED_WITH_ERRORS:
    printf("Compile failed\n");
    break;
  default:
    printf("Unknown response for compile file\n");
    break;
  }
}

int main()
{
  int res = compile_file("./test.c", "./test", 0);
  displayCompileStatus(res);

  return 0;
}
