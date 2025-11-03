.global _asm_fib

_asm_fib:
    // x0 is return value
    // x0, x1, etc are args in order

    mov x1, #0

    loop:
        cmp x0, #0
        ble exit

        add x1, x1, x0
        sub x0, x0, #1
        
        cmp x0, #0
        bgt loop
    b exit
    exit:
        mov x0, x1
        ret
