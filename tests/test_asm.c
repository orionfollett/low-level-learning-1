#ifdef HEADERS
#include "../src/asm.h"
#endif

#ifdef TESTS
TEST("Test asm add") {
  ASSERT(asm_add(1, 2), 3);
  ASSERT(asm_add(1, -2), -1);
  ASSERT(asm_add(0, 2), 2);
}

TEST("Test add seq") {
  ASSERT(asm_add_seq(0), 0);
  ASSERT(asm_add_seq(1), 1);
  ASSERT(asm_add_seq(2), 3);
  ASSERT(asm_add_seq(3), 6);
  ASSERT(asm_add_seq(4), 10);
  ASSERT(asm_add_seq(5), 15);

  ASSERT(asm_add_seq(100), 5050);

  /*Python takes 2.84 sec on this one*/

  ASSERT(asm_add_seq(10000000), 50000005000000);
  ASSERT(asm_add_seq(99999999), 4999999950000000);
}

#endif