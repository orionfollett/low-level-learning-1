#include "stack.h"
#include <stdio.h>


void hello_world(void) {
  printf("hello world\n");
}

static const int LEN_INDEX = 0;
static const int SIZE_INDEX = 1;

/* Creates a new stack initialized to size: size. */
Stack stack(Alloc alloc, int size){
  Stack s = (Stack) alloc(size + 2);
  s[LEN_INDEX] = 0;
  s[SIZE_INDEX] = (int) size;
  return s;
}

/* Pushes a new value onto the stack, returns the modified Stack. */
Stack push(Alloc alloc, int val);

/* Pops a value off the stack. Modifies stack in place. */
int pop(Stack s);

/* Returns the latest value off the stack without popping. */
int peek(Stack s);