#ifndef ASM_H
#define ASM_H

int asm_add(int x, int y);
long asm_add_seq(int n);
long asm_fib(int n);
long asm_fnv_hash(const char* str, int len);

/* use long to not deal with mixing 32 bit and 64 bit numbers */
void asm_sort(long* lis, long len);

#endif