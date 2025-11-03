#ifdef HEADERS
#include "../src/asm.h"
#endif

#ifdef TESTS
TEST("Test inline asm add"){
    ASSERT(asm_add(1, 2), 3);
    ASSERT(asm_add(1, -2), -1);
    ASSERT(asm_add(0, 2), 2);
}


TEST("Test inline asm fib"){
    
    ASSERT(asm_fib(0), 0);
    ASSERT(asm_fib(1), 1);
    ASSERT(asm_fib(2), 3);
    ASSERT(asm_fib(3), 6);
    ASSERT(asm_fib(4), 10);
    ASSERT(asm_fib(5), 15);
    
    
    /*Python takes 2.84 sec on this one*/
    
    /*
    ASSERT(asm_fib(100), 4950);
    ASSERT(asm_fib(10000000), 49999995000000);
    ASSERT(asm_fib(99999999), 4999999850000001);
    */
}

#endif