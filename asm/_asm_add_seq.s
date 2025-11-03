.global _asm_add_seq

_asm_add_seq:
    // x0 is return value
    // x0, x1, etc are args in order

    // Note there is a formula to compute this in constant time
    // but this was good practice writing a simple loop

    mov x1, #0

    cmp x0, #0
        ble exit

    loop:
        add x1, x1, x0
        sub x0, x0, #1
        
        cmp x0, #0
        bgt loop

    b exit
    
    exit:
        mov x0, x1
        ret
