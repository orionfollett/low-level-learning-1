#ifdef HEADERS
#include "../src/list.h"
#include "utils.h"
#endif

#ifdef TESTS
TEST("Test stack operations") {
  List l = list(0);
  ASSERT(list_len(l), 0);
  
  l = list_append(l, 100);
  ASSERT(list_len(l), 1);
  ASSERT(list_get(l, 0), 100);
  
  l = list_append(l, 200);
  ASSERT(list_len(l), 2);
  ASSERT(list_get(l, 1), 200);
}
#endif