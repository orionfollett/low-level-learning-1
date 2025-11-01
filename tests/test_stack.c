#ifdef HEADERS
#include "../src/stack.h"
#include "utils.h"
#endif

#ifdef TESTS
TEST("Test stack operations") {
  Stack s = stack(0);
  s = push(s, 100);
  ASSERT(stack_peek(s), 100);
  s = push(s, 200);
  ASSERT(stack_peek(s), 200);
  s = push(s, 300);
  ASSERT(stack_peek(s), 300);
  ASSERT(stack_pop(s), 300);
  ASSERT(stack_pop(s), 200);
  ASSERT(stack_pop(s), 100);

  Stack s2 = stack(2);
  s2 = push(s2, 100);
  ASSERT(stack_peek(s2), 100);
  s2 = push(s2, 200);
  ASSERT(stack_peek(s2), 200);
  s2 = push(s2, 300);
  ASSERT(stack_peek(s2), 300);
  ASSERT(stack_pop(s2), 300);
  ASSERT(stack_pop(s2), 200);
  ASSERT(stack_pop(s2), 100);
}
#endif