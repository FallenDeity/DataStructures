#include "../headers/multiple_stack.h"
#include "../../utils/headers/utils.h"

#include <stdio.h>
#include <stdlib.h>

static int isEmpty(MultipleStack stack, int stack_number) {
    return stack.top[stack_number] == -1;
}

static int isFull(MultipleStack stack, int stack_number) {
    return stack.top[stack_number] == stack.stack_size * (stack_number + 1) - 1;
}

static void push(MultipleStack *stack, int stack_number, int value) {
    if (stack->isFull(*stack, stack_number)) {
        printf("Stack is full\n");
    } else {
        stack->top[stack_number]++;
        stack->array[stack->top[stack_number]] = value;
    }
}

static int pop(MultipleStack *stack, int stack_number) {
    if (stack->isEmpty(*stack, stack_number)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        int value = stack->array[stack->top[stack_number]];
        stack->top[stack_number]--;
        return value;
    }
}

static void display(MultipleStack stack, int stack_number) {
    if (stack.isEmpty(stack, stack_number)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= stack.top[stack_number]; i++) {
        printf("%d ", stack.array[i]);
    }
    printf("\n");
}

void multipleStackMenu() {
    int total_stacks, stack_size;
    printf("Enter total stacks: ");
    total_stacks = getInteger();
    printf("Enter stack size: ");
    stack_size = getInteger();
    MultipleStack stack = initializeMultipleStack(total_stacks, stack_size);
    int choice, stack_number, value;
    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        choice = getInteger();
        printf("Enter stack number (%d - %d): ", 0, total_stacks - 1);
        stack_number = getInteger();
        if (stack_number < 0 || stack_number >= total_stacks) {
            printf("Invalid stack number\n");
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter value: ");
                value = getInteger();
                stack.push(&stack, stack_number, value);
                break;
            case 2:
                value = stack.pop(&stack, stack_number);
                if (value != -1) {
                    printf("Popped value is %d\n", value);
                }
                break;
            case 3:
                stack.display(stack, stack_number);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

MultipleStack initializeMultipleStack(int total_stacks, int stack_size) {
    MultipleStack stack;
    stack.array = (int *) malloc(sizeof(int) * total_stacks * stack_size);
    stack.top = (int *) malloc(sizeof(int) * total_stacks);
    stack.stack_size = stack_size;
    stack.total_stacks = total_stacks;
    for (int i = 0; i < total_stacks; i++) {
        stack.top[i] = -1;
    }
    stack.isEmpty = isEmpty;
    stack.isFull = isFull;
    stack.push = push;
    stack.pop = pop;
    stack.display = display;
    return stack;
}