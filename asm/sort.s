.global _asm_sort

start .req x0
len .req x1
last_byte .req x2
min_index .req x3
min .req x4
i .req x5
j .req x6
curr_i .req x7
curr_j .req x8
temp .req x9

_asm_sort:
    
    // convert len to bytes, multiply by 4
    lsl len, len, #2
    add last_byte, len, start
    
    mov i, start

    ldr curr_i, [i]    
    mov min_index, i
    mov min, curr_i
    
    outer:
        cmp last_byte, i
        ble exit

        ldr curr_i, [i]

        cmp curr_i, min
        bge skip 
            mov min_index, i
            mov min, curr_i
        skip:

        add i, i, #4
    b outer
    
    exit:
        str min, [start]
    ret