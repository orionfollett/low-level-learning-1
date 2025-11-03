.global _asm_add

asm_add:
    // x0 is return value
    // x0, x1, etc are args in order
    add x0, x0, x1
    ret