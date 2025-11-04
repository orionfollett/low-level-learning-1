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

TEST("Test fib") {
  ASSERT(asm_fib(0), 1);
  ASSERT(asm_fib(1), 1);
  ASSERT(asm_fib(2), 2);
  ASSERT(asm_fib(3), 3);
  ASSERT(asm_fib(4), 5);
  ASSERT(asm_fib(5), 8);
  ASSERT(asm_fib(6), 13);
  ASSERT(asm_fib(7), 21);
  ASSERT(asm_fib(50), 20365011074);
}

TEST("Test asm fnc hash") {
  long r = asm_fnv_hash("hello", 5);
  long r2 = asm_fnv_hash("hello", 5);
  long r3 = asm_fnv_hash("goodbye", 7);

  ASSERT(r, r2);
  ASSERT(r3 != r2, 1);
}

TEST("Test asm sort function") {
  int lis[] = {2, 1, 4, 3};
  int expected[] = {1, 2, 3, 4};
  asm_sort(lis, 4);
  
  int i = 0;
  for(; i < 4; i++){
    ASSERT(lis[i], expected[i]);
  }

}

#endif