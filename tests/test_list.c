#ifdef HEADERS
#include "../src/list.h"
#include "utils.h"
#endif

#ifdef TESTS
TEST("Test list append.") {
  List l = list(0);
  ASSERT(list_len(l), 0);

  l = list_append(l, 100);
  ASSERT(list_len(l), 1);
  ASSERT(list_get(l, 0), 100);

  l = list_append(l, 200);
  ASSERT(list_len(l), 2);
  ASSERT(list_get(l, 1), 200);
}

TEST("Test list insert.") {
  List l = list(0);
  ASSERT(list_len(l), 0);

  l = list_append(l, 100);
  l = list_append(l, 200);
  l = list_append(l, 300);

  l = list_insert(l, 0, 99);
  ASSERT(list_get(l, 0), 99);
  ASSERT(list_get(l, 1), 100);
  ASSERT(list_get(l, 2), 200);
  ASSERT(list_get(l, 3), 300);

  l = list_insert(l, 2, 999);

  ASSERT(list_get(l, 0), 99);
  ASSERT(list_get(l, 1), 100);
  ASSERT(list_get(l, 2), 999);
  ASSERT(list_get(l, 3), 200);
  ASSERT(list_get(l, 4), 300);
}
#endif