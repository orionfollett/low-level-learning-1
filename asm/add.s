.global asm_add
.type asm_add, %function

asm_add:
    // x0 is return value
    // x0, x1, etc are args in order
    add x0, x0, x1
    ret