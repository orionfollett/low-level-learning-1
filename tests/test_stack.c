#if defined HEADERS
#include <stdlib.h>
#include <string.h>
#include "../src/stack.h"
#elif defined TESTS
TEST("strlen returns length of string") {
  Stack s = stack(3);

  /*Test the size metadata is populated*/
  ASSERT(s[1] == 3);

  s = push(s, 100);
  s = push(s, 100);
  s = push(s, 100);
  s = push(s, 100);

  ASSERT(s[2] == 100);
  ASSERT(s[3] == 100);
  ASSERT(s[4] == 100);
  ASSERT(s[5] == 100);
}

#endif