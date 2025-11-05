#ifdef HEADERS
#include "../src/strings.h"
#include "utils.h"
#endif

#ifdef TESTS
TEST("Test strings") {
  s8 s = str("hello");
  s8 s2 = str("hello");
  ASSERT(s8cmp(s, s2), 1);
}
#endif