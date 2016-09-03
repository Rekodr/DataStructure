#include "stack.h"
#include <stdio.h>


int main(){
     int testData[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

     stack arrayStack = NULL;
     stack linkedStack = NULL;

     //array implementation test; 
     arrayStack = Array_Stack(arrayStack);
     //linked list implementation test;
     linkedStack = List_Stack(linkedStack); 

     //insert all the data stuff
     for (int i = 0; i < 11; i++)
     {
	    push(arrayStack, testData[i]); 
     }
     int *t = top(arrayStack); 
     printf("stack size: %d\n", getSize(arrayStack));
     printf("top: %d\n", *t);

     for (int i = 0; i <= 7; i++)
		pop(arrayStack);
     
     t = top(arrayStack); 
	printf("stack size: %d\n", getSize(arrayStack));

	if( t != NULL)
     	printf("top: %d\n", *t);
	


     return 0;
}