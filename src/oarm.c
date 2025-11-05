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

int execute_oarm(const char* code, int memory[1024]);
