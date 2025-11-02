#ifdef HEADERS
#include "../src/map.h"
#include "utils.h"
#endif

#ifdef TESTS
TEST("Test map get and set.") {
  Map m = map(3);
  int i = 0;
  for(; i< 10; i++){
    m = map_set(m, i, 100*i);
  }

  ResultInt r;
  for(; i< 10; i++){
    r = map_get(m, i);
    ASSERT(r.tag, OK);
    ASSERT(r.ok, i*100);
  }

  ResultInt err = map_get(m, 99);
  ASSERT(err.tag, ERR);
}

TEST("Test map pop.") {
  Map m = map(3);
  int i = 0;
  for(; i< 10; i++){
    m = map_set(m, i, 100*i);
  }

  

}
#endif