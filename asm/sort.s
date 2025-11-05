.global _asm_sort

_asm_sort:
    // sort the list in place
    // algorithm:
    //def test_sort(lis):
    //min = lis[0]
    
    //for i in range(0, len(lis)):
    //    min_index = i
    //    min = lis[min_index]
    //    for j in range(i, len(lis)):
    //        if lis[j] < min:
    //            min = lis[j]
    //            min_index = j
    //    
    //    lis[min_index] = lis[i]
    //    lis[i] = min
    //    
    //return lis
    

    // x0 has memory address of first element in list
    // list of ints so Ill assume 4 bytes each
    // x1 has list length

    // multiply length by 4 since we care about it in bytes
    // say len is 3, that's actually 3 ints, which are each 4 bytes, so need
    // to multiply by 4
    lsl x1, x1, #2

    // x1 now stores the address for the last byte in the array
    add x1, x1, x0
    
    outer:
        cmp x0, x1
        bge exit

        // outer loop list value
        ldr x2, [x0]
        
        // x3 is min_value
        mov x3, x2
        
        // x4 is min index
        mov x4, x0

        // inner loop
        inner:
            cmp 
            
        inner_exit:

        // increment outer loop counter
        add x0, x0, #4
    
    exit:
    
    ret