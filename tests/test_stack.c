#ifdef HEADERS
#include "../src/stack.h"
#include "utils.h"
#endif

#ifdef TESTS
TEST("Test stack operations") {
  Stack s = stack(0);
  s = push(s, 100);
  ASSERT(peek(s), 100);
  s = push(s, 200);
  ASSERT(peek(s), 200);
  s = push(s, 300);
  ASSERT(peek(s), 300);
  ASSERT(pop(s), 300);
  ASSERT(pop(s), 200);
  ASSERT(pop(s), 100);

  Stack s2 = stack(2);
  s2 = push(s2, 100);
  ASSERT(peek(s2), 100);
  s2 = push(s2, 200);
  ASSERT(peek(s2), 200);
  s2 = push(s2, 300);
  ASSERT(peek(s2), 300);
  ASSERT(pop(s2), 300);
  ASSERT(pop(s2), 200);
  ASSERT(pop(s2), 100);
}
#endif