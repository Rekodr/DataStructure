#ifndef _LIST_
#define _LIST_

#include <stdio.h>

#define SUCCESS 100
#define FAILURE 500

typedef struct linkedList *linkedList;


 

linkedList LinkedList(linkedList, size_t dataSize, void*, void*, int); 
int insert(linkedList list, void* data);
int delete(linkedList list, void* data);
int getSize(linkedList list);  
int contains(linkedList list, void* data);
void toString();
int deAllocate(linkedList list);

#endif