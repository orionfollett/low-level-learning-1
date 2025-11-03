.global _asm_fnv_hash

_asm_fnv_hash:
    // args
    // x0 is pointer to string
    // x1 is len of string

    // we return a number

    /*
    algorithm fnv-1 is
    hash := 14695981039346656037

    for each byte_of_data to be hashed do
        hash := hash × 1099511628211
        hash := hash XOR byte_of_data

    return hash 
    */

    // addr of last byte to load
    add x1, x1, x0
    mov x4, #97
    mov x3, #113
    loop:

        // load first byte
        ldrb w2, [x0]

        // increment address
        add x0, x0, #1

        mul x3, x3, x4
        // extend to wider register
        uxtb x2, w2
        eor x3, x3, x2
        
        
        // check loop end
        cmp x0, x1
        blt loop
    
    mov x0, x3
    ret


    // x0 is the addr to the next char to read
    // x1 is max byte addr to read
    // x2 holds loaded bytes
    // x3 holds result

