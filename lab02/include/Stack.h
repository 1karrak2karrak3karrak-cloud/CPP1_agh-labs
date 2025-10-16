#ifndef STACK_H
#define STACK_H
#include <stdio.h>

struct Stack {
    int* s = nullptr;    // the dynamic table
    int size;            // size which is taken
    int capacity;        // allowed size of s table
};

void stackInit(Stack* s, int size); // initialize s table with capacity
void printState(Stack* s);          // print the size and capacity
void stackPush(Stack* s, int par);  // adding new value to table
int stackPop(Stack* s);             // delete last value from the table
bool stackEmpty(Stack *s);          // check if table is empty
void stackDestroy(Stack* s);        // free dynamic table

#endif // STACK_H
