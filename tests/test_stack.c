#if defined HEADERS
#include <string.h>
#include "../src/stack.h"
#elif defined TESTS
TEST("strlen returns length of string") {
  ASSERT(strlen("") == 0);
  ASSERT(strlen("foo") == 3);
  hello_world();
}

#endif