#ifndef _STACK_H
#define _STACK_H

typedef struct stack_ *stack ;

stack Stack(stack myStack);
void freeStack(stack myStack); 
int push(stack myStack, int data);
int pop(stack myStack);
int* top(stack myStack); 
int getSize(stack mystack);
int empty(stack mySact); 

#endif