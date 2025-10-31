#include "stack.h"
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
    size = size * 2;
    s = (Stack)realloc(s, ((unsigned long)size + 2) * sizeof(int));
  }

  s[len + 2] = val;
  s[LEN_INDEX]++;
  return s;
}

/* Pops a value off the stack. Modifies stack in place. */
int pop(Stack s) {
  int len = s[LEN_INDEX];
  s[LEN_INDEX] = len - 1;
  return s[len];
}

/* Returns the latest value off the stack without popping. */
int peek(Stack s) {
  return s[s[LEN_INDEX]];
}

/* Deallocate memory associated with stack. */
void destroy_stack(Stack s) {
  free(s);
}