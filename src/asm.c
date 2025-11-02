#include "asm.h"
#include <stdio.h>

int asm_add(int x, int y) {
  int sum;

  asm volatile("add %w0, %w1, %w2\n\t" : "=r"(sum) : "r"(x), "r"(y));
  return sum;
}

int asm_fib(int n);
void asm_sort(int* lis, int len);
