
/*
Tests...

just need macro to print file and line on failure but no need to abort

main function

*/
#include <stdio.h>
#include "test_stack.c"

int main(void) {
  printf("Stack operations\n");
  test_stack_ops();
}