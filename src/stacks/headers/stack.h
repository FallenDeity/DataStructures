#ifndef DATASTRUCTURES_STACKS_H
#define DATASTRUCTURES_STACKS_H

typedef struct Stack {
    int *array;
    int top;
    int size;
    int (*isFull)(struct Stack);
    int (*isEmpty)(struct Stack);
    void (*push)(struct Stack *, int);
    int (*pop)(struct Stack *);
    void (*display)(struct Stack);
} Stack;

Stack initializeStack(int size);
void stackMenu();

#endif//DATASTRUCTURES_STACKS_H
