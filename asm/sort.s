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
    lsl x1, x1, #2

    // x1 now stores the address for the last byte in the array
    add x1, x1, x0
    
    outer:
        cmp x0, x1
        bge exit

        // outer loop list value
        ldr x2, [x0]
        
        // inner loop
        inner: 


    
    exit:
    
    ret