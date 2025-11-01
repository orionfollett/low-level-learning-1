#ifndef TEST_H
#define TEST_H

#include <stdio.h>

#define TEST(name) test=name;

#define ASSERT(x, y)         \
    do {                     \
        if(x!=y){            \
            putchar('!'); \
            printf("%s failed  at %s:%i\n", test, __FILE__, __LINE__); \
        }                   \
        else { \
            putchar('.'); \
        } \
    } while (0)

#endif