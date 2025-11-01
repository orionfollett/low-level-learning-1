#ifndef TEST_H
#define TEST_H

#include <stdio.h>

#define ASSERT(x, y)         \
    do {                     \
        if(x!=y){            \
            printf("Failure at %s:%i\n", __FILE__, __LINE__); \
        }                   \
    } while (0)

#endif