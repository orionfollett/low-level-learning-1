#ifdef HEADERS
#include "../src/map.h"
#include "utils.h"
#endif

#ifdef TESTS
TEST("Test map get and set.") {
  Map m = map(3);
  int i = 0;
  for (; i < 10; i++) {
    m = map_set(m, i, 100 * i);
  }

  ResultInt r;
  for (; i < 10; i++) {
    r = map_get(m, i);
    ASSERT(r.tag, OK);
    ASSERT(r.ok, i * 100);
  }

  ResultInt err = map_get(m, 99);
  ASSERT(err.tag, ERR);
}

TEST("Test map pop.") {
  Map m = map(3);
  int i = 0;
  for (; i < 20; i++) {
    m = map_set(m, i, 100 * i);
  }

  /*middle of linked list*/
  ResultInt r6 = map_get(m, 6);
  ASSERT(r6.tag, OK);
  ASSERT(r6.ok, 600);

  ResultInt pop6 = map_pop(m, 6);
  ASSERT(pop6.tag, OK);
  ASSERT(pop6.ok, 600);

  r6 = map_get(m, 6);
  ASSERT(r6.tag, ERR);

  /*first item of linked list*/
  ResultInt r0 = map_get(m, 0);
  ASSERT(r0.tag, OK);
  ASSERT(r0.ok, 0);

  ResultInt pop0 = map_pop(m, 0);
  ASSERT(pop0.tag, OK);
  ASSERT(pop0.ok, 0);

  r0 = map_get(m, 0);
  ASSERT(r0.tag, ERR);
}
#endif