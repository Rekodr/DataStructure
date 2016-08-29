/*
Author: Recodeo Rekod
Description: generic programing demo in c
*/

#include <stdio.h>
#include <string.h>
#include "list.h"

int compareInt(int* t, int* d);
void printInt(int* data);

int compareStr(char* str1, char* str2);
void printString(char* data);

int main(){

	int data = 5;
   	int data2 = 6;
   	int data3 = 28;
   	int data4 = 15;
   	int data5 = 10;
    	char* strings[] =  {"monday", "tuesday","wednesday","thursday","friday","saturday","sunday"};

    	linkedList list = NULL ;

	//test with integers 
    	list = LinkedList(list, sizeof(int), &compareInt, &printInt,0);
	insert(list, &data); 
	insert(list,&data2);
	printf("size: %d\n", getSize(list));
	printf("found data position %d\n", contains(list, &data2)); 
	delete(list, &data);
	printf("found data position %d\n", contains(list, &data2));
	printf("size: %d\n", getSize(list));
	insert(list, &data3);
	insert(list, &data4);  
	insert(list, &data5);  
	toString(list);
	deAllocate(list);

     // test with string, here we assume that the longest string had 20 characters.
	list = LinkedList(list, 20,  &compareStr, &printString,1);

	for(int i = 0 ; i < 7; i++){
		insert(list, strings[i]); 
	}
	toString(list);
	delete(list, "monday");
	printf("size: %d\n", getSize(list));
	delete(list,"friday");  //to bad  jajaja
	printf("found data position %d\n", contains(list, "tuesday")); 
	printf("\n\n");
	toString(list);
	deAllocate(list);
	return 0;
}


int compareInt(int* t, int* d){
    if(*t > *d)
        return 1;
    else if (*t < *d)
        return -1;
   return 0 ;         
}

void printInt(int* data){
    printf("%d\n", *data);
}


int compareStr(char* str1, char* str2){
    if(strlen(str1) != strlen(str2))
        return -1;
    return strncmp(str1, str2, strlen(str1));
}
void printString(char* data){
    printf("%s\n", data);
}

