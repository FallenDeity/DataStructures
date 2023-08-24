#ifndef DATASTRUCTURES_MULTIPLE_STACK_H
#define DATASTRUCTURES_MULTIPLE_STACK_H

typedef struct MultipleStack {
    int *array;
    int *top;
    int stack_size;
    int total_stacks;
    int (*isFull)(struct MultipleStack, int);
    int (*isEmpty)(struct MultipleStack, int);
    void (*push)(struct MultipleStack *, int, int);
    int (*pop)(struct MultipleStack *, int);
    void (*display)(struct MultipleStack, int);
} MultipleStack;

MultipleStack initializeMultipleStack(int total_stacks, int stack_size);
void multipleStackMenu();

#endif//DATASTRUCTURES_MULTIPLE_STACK_H
