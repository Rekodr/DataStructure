/*
 author: Recodeo Rekod
 desciption: array implementation of a stack
*/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 50

struct stack_
{
     int *data;
     int stack_size;
     int* top;
     int max_size;  

};

stack Stack(stack myStack)
{
     myStack = malloc(sizeof(struct stack_)); 
	if(myStack == NULL){
	     fprintf(stderr, "allocation failled.\n");
	     return NULL; 
	}
	myStack->data = malloc(sizeof(int) * ARRAY_SIZE);
	if(myStack->data == NULL){
		fprintf(stderr, "allocation failled.\n");
	     return NULL; 
	}
	myStack->stack_size = 0;
	myStack->top = NULL;
	myStack->max_size = ARRAY_SIZE; 
	return myStack;
}

void freeStack(stack myStack){
	if(myStack == NULL)
	     return;
	if(myStack->data != NULL)
	     free(myStack->data);

	free(myStack); 
}

int push(stack myStack, int data){

	if(myStack->stack_size >= myStack->max_size){
	     myStack->max_size += ARRAY_SIZE;
	     myStack->data = realloc(myStack, sizeof(int) * myStack->max_size); 
		if(myStack->data == NULL){
			fprintf(stderr, "allocation failled. push %d\n", data);
	     	return -1; 
		}
	}

	myStack->data[myStack->stack_size] = data;
	myStack->top = &myStack->data[myStack->stack_size];
	myStack->stack_size++; 
	return 1;
}


int pop(stack myStack){
	if(myStack->stack_size == 0){
	     fprintf(stderr, "The stack is empty.\n");
	     return -1; 
	}
	myStack->stack_size--;
	myStack->top = &myStack->data[myStack->stack_size];
	return 1;
}

int* top(stack myStack){
	if(myStack->stack_size <= 0)
	     return NULL;
	return myStack->top;
}

int getSize(stack myStack){
     return myStack->stack_size; 
}

int empty(stack myStack){
     myStack->stack_size = 0;
     return 1; 
}