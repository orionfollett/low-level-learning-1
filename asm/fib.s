.global _asm_fib

_asm_fib:

    // fib numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34...
    // so each number is the sum of the last two numbers
    // all numbers 1 or below should return 1 (my rules)

    mov x1, #0 // last number
    mov x2, #1 // curr number
    
    cmp x0, #1
    ble exit

    loop:
        add x3, x1, x2
        mov x1, x2
        mov x2, x3
        
        sub x0, x0, 1
        
        cmp x0, #0
        bgt loop

    b exit
    exit:
        mov x0, x2
        ret
