#ifdef HEADERS
#include "../src/map.h"
#include "utils.h"
#endif

#ifdef TESTS
TEST("Test map operations") {
  Map m = map(3);
  m = map_set(m, 0, 100);
  m = map_set(m, 1, 200);
  m = map_set(m, 2, 300);
  m = map_set(m, 3, 400);

  ResultInt r0 = map_get(m, 0);
  ASSERT(r0.tag, OK);
  ASSERT(r0.ok, 100);

  ResultInt r1 = map_get(m, 1);
  ASSERT(r1.tag, OK);
  ASSERT(r1.ok, 200);

  ResultInt r2 = map_get(m, 2);
  ASSERT(r2.tag, OK);
  ASSERT(r2.ok, 300);

  ResultInt r3 = map_get(m, 3);
  ASSERT(r3.tag, OK);
  ASSERT(r3.ok, 400);

  ResultInt r4 = map_get(m, 4);
  ASSERT(r4.tag, ERR);
}
#endif