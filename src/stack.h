#ifndef STACK_H
#define STACK_H

typedef int* Stack;
typedef int*(*Alloc)(int);

void hello_world(void);

/* Creates a new stack initialized to size: size. */
Stack stack(Alloc alloc, int size);

/* Pushes a new value onto the stack, returns the modified Stack. */
Stack push(Alloc alloc, int val);

/* Pops a value off the stack. Modifies stack in place. */
int pop(Stack s);

/* Returns the latest value off the stack without popping. */
int peek(Stack s);

#endif