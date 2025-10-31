#if defined HEADERS
#include <stdlib.h>
#include <string.h>
#include "../src/stack.h"
#elif defined TESTS
TEST("strlen returns length of string") {
  Stack s = stack(malloc, 3);

  ASSERT(strlen("") == 0);
  ASSERT(strlen("foo") == 3);
}

#endif