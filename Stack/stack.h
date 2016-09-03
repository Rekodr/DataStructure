#ifndef _STACK_H
#define _STACK_H

#include "which_Implementation.h"
typedef struct stack_ *stack ;


/* 
	Note: it is not really necessary to separate the implementation of
	Array_Stack and List_Stack. This is just my preference. You could just
	do the same as for the other functions. 

*/
stack Array_Stack(stack myStack);
stack List_Stack(stack myStack);
void freeStack(stack myStack);
int push(stack myStack, int data);
int pop(stack myStack);
int* top(stack myStack); 
int getSize(stack mystack);
int empty(stack mySact); 

#endif