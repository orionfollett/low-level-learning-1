#include "asm.h"
#include <stdio.h>

int asm_add(int x, int y) {
  int sum;
  asm volatile("add %w0, %w1, %w2" : "=r"(sum) : "r"(x), "r"(y));
  return sum;
}

int asm_fib(int n) {
    /*generate the nth fibonacci number.*/
    int result;
    asm volatile("add %w0, %w1, 1" : "=r"(result) : "r"(n));
    return result;
}

void asm_sort(int* lis, int len);
