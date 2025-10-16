#include "Stack.h"
#include <iostream>
#include <stdio.h>
using namespace std;

void stackInit(Stack* s, int size){
    s -> capacity = size;                       // change capacity 
    s -> size = 0;                              // set size with 0
    s -> s = (int*)malloc(sizeof(int)*size);    // allocate dynamic table
}

void printState(Stack* s){
    printf("size=%d, capacity=%d\n",s->size, s->capacity); // print size and capacity
}

void stackPush(Stack* s, int par){
    if(s -> size >= s -> capacity) {  //check if we have enough space
        s -> capacity = (s -> capacity)*2; // if dont double it
        s -> s = (int*)realloc(s -> s, (s -> capacity)*sizeof(int));
    }
    int size = s -> size;
    s -> s[size] = par; // add new value
    s -> size =  s -> size + 1; // incriment size
}

int stackPop(Stack* s){
    if(s -> size == 0 || s -> capacity == 0){ //check if we have something to pop
        printf("there is nothing to pop\n");
        return 0;
    }
    int size = s -> size;
    int var = s -> s[size-1]; // safe the last value
    s -> s[size-1] = 0;
    s -> size =  s -> size - 1;
    return var; // and return it
}

bool stackEmpty(Stack *s){
    return (s -> size == 0) || (s -> capacity == 0);  // check if table has any value in the dynamic table
}

void stackDestroy(Stack* s){
    free(s -> s);       // free dynamic table
    s -> size = 0;      // set size with 0
    s -> capacity = 0;  // set capacity with 0
}
