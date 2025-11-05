#ifndef OARM_H
#define OARM_H

/* OARM is Orion's ARM, which is a tiny subset of ARM I am implementing */

/*
commands:
<name> .req <register_name>
#<numerical constant>
<label_name>:

lsl <result register>, <op1>, <op2>
add <result register>, <op1>, <op2>
mov <result register>, <op1>
cmp <op1>, <op2>
ldr <op1>, [<addr>]
str <op1>, [<addr>]
ret
bgt <label_name>
bge <label_name>
*/

int oarm(const char* code, int memory[1024]);

#endif