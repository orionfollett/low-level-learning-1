#ifdef HEADERS
#include "../src/asm.h"
#endif

#ifdef TESTS
TEST("Test inline asm add"){
    ASSERT(asm_add(1, 2), 3);
    ASSERT(asm_add(1, -2), -1);
    ASSERT(asm_add(0, 2), 2);
}
#endif