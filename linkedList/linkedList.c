/*
Author: Recodeo Rekod
Description: The purpose of this project is to demo how to use
            basic generic programing in c.
            To do so , let implement a basic linkedList
*/

#include <stdlib.h>
#include <string.h>
#include "list.h"  


// function declaration
// note: when declaring you actually don"t arguments' name"
void dataCpy(void*, void*, int, int);


 struct node{
    void* data;  // the data will be stored in this void pointer
    struct node *next; // this will point to the next node
 };
typedef struct node *node;  

// This is the linkedList structure. 
// Note that could add all the list function whithing this structure
// it is not acutally hard to do it, see how the comparator and toSring are done.
// set the check_NULL to 1 if using data ending with a '\0' character such strings for ex.
struct linkedList{
    node head; 
    node tail;
    node current; 
    int _size; 
    size_t dataSize;
    
    // here is a function pointer. void pointers are used as argument so that
    // we can used the generic data. No worry I will wirte a tuto for that. 
    int (*comparator)(void* data1, void* data2); 
    void (*toString)(void* data);
    int check_NULL;  
}; 


//constructor/
linkedList LinkedList(linkedList list, size_t dataSize, void* comparator, void* toString, int checkNULL){
    list = malloc(sizeof(struct linkedList));
    if(list == NULL){
        fprintf(stderr, "ERROR");
    }
    list->_size = 0;
    list->dataSize = dataSize; 
    list->comparator = comparator; 
    list->toString = toString;
    list->check_NULL = checkNULL; 
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// destructor; 
// In case you don't know a destructor is in charge off freeing memorry.
// destructors are critial in c/c++ since this language do not HAVE a 
// GARBAGE collector
int deAllocate(linkedList list){
    while(list->head->next != list->tail){
        delete(list, list->head->next->data);
    }
   
    if(list->tail != NULL)
        free(list->tail);
    if(list->head != NULL){
        list->head->next = NULL; 
        free(list->head);
    }
      
    free(list);
    return 1; 
}

//data insertion
int insert(linkedList list, void* data){
    // intinial insertion; when to list size is 0
    if(list->_size == 0){
        list->head = malloc(sizeof(struct node )); 
        // the head in this implementation is a dumb node
        node store = list->head->next = malloc(sizeof(struct node));
        if(list->head == NULL || list->head->next == NULL)
            return -1;
       store->data  = malloc(sizeof(list->dataSize));
       dataCpy(store->data, data, list->dataSize, list->check_NULL); 
       list->tail = store; 
    }
    else{
        if(list->tail == NULL)
            return -1;
        node store = list->tail; 
        store->data = malloc(sizeof(list->dataSize));
        if(list->tail == NULL)
            return -1;
        dataCpy(store->data, data, list->dataSize, list->check_NULL);
    }
    
    list->tail->next = malloc(sizeof(struct node)); 
    list->tail = list->tail->next;
   
    list->_size++;
    return list->_size; 
}

// this function copy the data into a node data
// this pretty much the same way as memcpy work
// add a check for '\0' when checkNull is set
void dataCpy(void* dest, void* src, int size, int checkNUll){
    char c;
    int i;
    for(i = 0; i < size; i++){
        c = *((char*)(dest + i)) = *((char*)(src + i));

        if(c == '\0' && checkNUll == 1){
            break;
        }   
    }
}

int getSize(linkedList list){
  return list->_size;
}

int contains(linkedList list, void* data){
    if(list->_size == 0)
        return -1;
    int position = 0; 
    for( node tmp = list->head->next ; tmp != list->tail; tmp = tmp->next, position++){
      if((list->comparator)(tmp->data, data) == 0)
        return position; 
    }
    return -1;
}

int delete(linkedList list, void* data){
    if(list->_size == 0)
        return -1;
    int p; 
    if((p = contains(list, data)) > -1){
        node tmp = list->head ; 
        for( int i = 0; i <= p; i++){
            list->current = tmp; 
            tmp = tmp->next; 
        }
       list->current->next = tmp->next;
       free(tmp->data);
       free(tmp);
       list->_size--;  
       return SUCCESS;
    }    
    return -1;
}

void toString(linkedList list){
    for(node tmp = list->head->next; tmp != list->tail; tmp = tmp->next){
        (list->toString)(tmp->data);
    }
}



