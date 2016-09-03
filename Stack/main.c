#include "stack.h"
#include <stdio.h>


int main(){
     int testData[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

     stack myStack = NULL;

    
     //array implementation test; 
	#ifdef _ARRAY_STACK_
     myStack = Array_Stack(myStack);
	#endif

     //linked list implementation test;
	#ifdef _LINKED_LIST_STACK_
     myStack = List_Stack(myStack); 
	#endif 

     //insert all the data stuff
     for (int i = 0; i < 11; i++)
     {
	    push(myStack, testData[i]); 
     }
     int *t = top(myStack); 
     printf("stack size: %d\n", getSize(myStack));
     printf("top: %d\n", *t);

     for (int i = 0; i <= 7; i++)
		pop(myStack);
     
     t = top(myStack); 
	printf("stack size: %d\n", getSize(myStack));

	if( t != NULL)
     	printf("top: %d\n", *t);

	//free the allocated mem;
	freeStack(myStack);

	return 0;
}