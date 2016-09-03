/*
 author: Recodeo Rekod
 desciption: linkedList implementation of a stack
*/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


#ifdef _LINKED_LIST_STACK_

struct node{
    struct node* next;
    int data; 
};

typedef struct node *node; 

struct stack_
{
     node top;
     int stack_size; 

};

stack List_Stack(stack myStack){
     myStack = malloc(sizeof(struct stack_));
	if(myStack == NULL){
	     fprintf(stderr,"allocation error.\n");
	     return NULL; 
	}

	myStack->stack_size = 0;
	myStack->top = NULL;
	return myStack;
}

void freeStack(stack myStack){
     empty(myStack);
     free(myStack); 
}

int push(stack myStack, int data){
     node newNode = malloc(sizeof(struct node));
     newNode->data = data;
     newNode->next = NULL;

     newNode->next = myStack->top;
     myStack->top = newNode;
     myStack->stack_size++;
     return 1;
}

int pop(stack myStack){
	if(myStack->stack_size <= 0){
	     fprintf(stderr, "The stack is empty");
	     return -1;
	}

	node temp = myStack->top->next; 
	if(myStack->top != NULL)
	     free(myStack->top);

	myStack->top = temp;

	myStack->stack_size--;
	return 1;
}

int* top(stack myStack){
	if(myStack->stack_size <= 0)
	     return NULL;
	return &myStack->top->data;
}

int getSize(stack myStack){
     return myStack->stack_size; 
}

int empty(stack myStack){
	if(myStack->stack_size <= 0){
	     return -1; 
	}
	while(myStack->top != NULL){
	     pop(myStack);
	}
	return 1;
}

#endif