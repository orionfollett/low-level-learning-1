#include "asm.h"
#include <stdio.h>

int asm_add(int x, int y) {
  int sum;
  asm volatile("add %w0, %w1, %w2" : "=r"(sum) : "r"(x), "r"(y));
  return sum;
}

// TODO inline asm wont work because gcc doesnt let you use labels which i need for loops and stuff
// instead ill need to write in separate file and compile into it
// thats fine because my emulator will need to do that anyways
long asm_fib(int n) {
    /*generate the nth fibonacci number.*/
    long result;
    
    asm volatile(
        "loop:\n\t"
        "cmp %w0, #0\n\t"
        "ble exit\n\t"
        "add %w1, %w1, %w0\n\t"
        "sub %w0, %w0, %w1\n\t"
        "b loop\n\t"
        "exit:\n\t"
        : "=r"(result) : "r"(n)
    );
    printf("RESULT %i\n", (int)result);
    return result;
}

void asm_sort(int* lis, int len);
