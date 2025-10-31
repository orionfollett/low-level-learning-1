#ifndef STACK_H
#define STACK_H

typedef int* Stack;

/* Creates a new stack initialized to size: size. */
Stack stack(int size);

/* Pushes a new value onto the stack, returns the modified Stack. */
Stack push(Stack s, int val);

/* Pops a value off the stack. Modifies stack in place. */
int pop(Stack s);

/* Returns the latest value off the stack without popping. */
int peek(Stack s);

/* Release stacls underlying memory. */
void destroy_stack(Stack s);

#endif