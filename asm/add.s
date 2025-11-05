.global _asm_add

temp .req x0

_asm_add:
    // x0 is return value
    // x0, x1, etc are args in order
    add temp, temp, x1
    ret