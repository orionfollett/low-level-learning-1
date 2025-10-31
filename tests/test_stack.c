#if defined HEADERS
#include <stdlib.h>
#include <string.h>
#include "../src/stack.h"
#elif defined TESTS
TEST("strlen returns length of string") {
  Stack s = stack(malloc, 3);

  ASSERT(s[1] == 3);
}

#endif