.global _asm_add


_asm_add:
    // x0 is return value
    // x0, x1, etc are args in order
    add x0, xo, x1
    ret