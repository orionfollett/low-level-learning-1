#if defined HEADERS
#include <stdlib.h>
#include <string.h>
#include "../src/stack.h"
#elif defined TESTS
TEST("strlen returns length of string") {
  Stack s = stack(0);

  s = push(s, 100);
  ASSERT(peek(s) == 100);
  s = push(s, 200);
  ASSERT(peek(s) == 200);
  s = push(s, 300);
  ASSERT(peek(s) == 300);

  ASSERT(pop(s) == 300);
  ASSERT(pop(s) == 200);
  ASSERT(pop(s) == 100);
}

#endif