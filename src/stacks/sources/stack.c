#include "../headers/stack.h"
#include "../../utils/headers/utils.h"

#include <stdio.h>
#include <stdlib.h>

static int isEmpty(Stack stack) {
    return stack.top == -1;
}

static int isFull(Stack stack) {
    return stack.top == stack.size - 1;
}

static void push(Stack *stack, int value) {
    if (stack->isFull(*stack)) {
        printf("Stack is full\n");
    } else {
        stack->top++;
        stack->array[stack->top] = value;
    }
}

static int pop(Stack *stack) {
    if (stack->isEmpty(*stack)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        int value = stack->array[stack->top];
        stack->top--;
        return value;
    }
}

static void display(Stack stack) {
    if (stack.isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= stack.top; i++) {
        printf("%d ", stack.array[i]);
    }
    printf("\n");
}

void stackMenu() {
    int size;
    printf("Enter size of stack: ");
    size = getInteger();
    Stack stack = initializeStack(size);
    int choice;
    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        choice = getInteger();
        switch (choice) {
            case 1: {
                int value;
                printf("Enter value: ");
                value = getInteger();
                stack.push(&stack, value);
                break;
            }
            case 2: {
                int value = stack.pop(&stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            }
            case 3: {
                stack.display(stack);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }
}

Stack initializeStack(int size) {
    Stack stack;
    stack.array = (int *) malloc(sizeof(int) * size);
    stack.top = -1;
    stack.size = size;
    stack.isFull = isFull;
    stack.isEmpty = isEmpty;
    stack.push = push;
    stack.pop = pop;
    stack.display = display;
    return stack;
}