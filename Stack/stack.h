#ifndef _STACK_H
#define _STACK_H

#include "which_Implementation.h"
typedef struct stack_ *stack ;

stack Array_Stack(stack myStack);
stack List_Stack(stack myStack);
void freeStack(stack myStack);
int push(stack myStack, int data);
int pop(stack myStack);
int* top(stack myStack); 
int getSize(stack mystack);
int empty(stack mySact); 

#endif