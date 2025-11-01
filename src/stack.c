#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

static const int LEN_INDEX = 0;
static const int SIZE_INDEX = 1;

/* Creates a new stack initialized to size. */
Stack stack(int size) {
  Stack s = (Stack)malloc(((unsigned long)size + 2) * sizeof(int));
  s[LEN_INDEX] = 0;
  s[SIZE_INDEX] = (int)size;
  return s;
}

/* Pushes a new value onto the stack, returns the modified Stack. */
Stack push(Stack s, int val) {
  int size = s[SIZE_INDEX];
  int len = s[LEN_INDEX];

  if (len >= size) {
    size = (size + 1) * 2;
    s = (Stack)realloc(s, ((unsigned long)size + 2) * sizeof(int));
    s[SIZE_INDEX] = size;
  }

  s[len + 2] = val;
  s[LEN_INDEX] = s[LEN_INDEX] + 1;
  return s;
}

/* Pops a value off the stack. Modifies stack in place. */
int stack_pop(Stack s) {
  s[LEN_INDEX] = s[LEN_INDEX] - 1;
  return s[s[LEN_INDEX] + 2];
}

/* Returns the latest value off the stack without stack_popping. */
int stack_peek(Stack s) {
  return s[s[LEN_INDEX] + 2 - 1];
}

/* Deallocate memory associated with stack. */
void stack_destroy(Stack s) {
  free(s);
}