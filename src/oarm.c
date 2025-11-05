#include "oarm.h"
#include <stdio.h>
/*
commands:
<name> .req <register_name>
#<numerical constant>
<label_name>:

lsl <result register>, <op1>, <op2>
add <result register>, <op1>, <op2>
mov <result register>, <op1>
cmp <op1>, <op2>
ldr <op1>, [<addr>]
str <op1>, [<addr>]
ret
bgt <label_name>
bge <label_name>
*/

typedef enum {
  ADD,
  MOV,
  CMP,
  LDR,
  STR,
  RET,
  BGT,
  BGE,
  LABEL,
  REG_ALIAS
} StmtTypeT;

int oarm(const char* code, int memory[1024]) {
  int registers[10] = {0};
  /*int cmp_bit = 0;*/
  printf("%s", code);
  printf("%i", memory[0]);
  return registers[0];

  /*
    Things Ill probably need:
    - string struct
        - string compare
    - string map (that uses the aforementioned string class)


  Interpreter Stages:
  - clean up whitespace, make all lower case
  - go line by line, parse statements into tagged union and add to list
      - store map of label name to index in list
  - execute item by item in list, modifying register state, memory, and cmp
  state with each cmd execution
  - return with value in register[0] (x0)
  */
}
