#include "../headers/linear_queue.h"
#include "../../utils/headers/utils.h"

#include <stdio.h>
#include <stdlib.h>

static int isEmpty(LinearQueue queue) {
    return queue.front == queue.rear;
}

static int isFull(LinearQueue queue) {
    return queue.rear == queue.size - 1;
}

static void enqueue(LinearQueue *queue, int value) {
    if (queue->isFull(*queue)) {
        printf("Queue is full\n");
    } else {
        queue->rear++;
        queue->array[queue->rear] = value;
    }
}

static int dequeue(LinearQueue *queue) {
    if (queue->isEmpty(*queue)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        queue->front++;
        int value = queue->array[queue->front];
        return value;
    }
}

static void display(LinearQueue queue) {
    if (queue.isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue.front + 1; i <= queue.rear; i++) {
        printf("%d ", queue.array[i]);
    }
    printf("\n");
}

LinearQueue initializeLinearQueue(int size) {
    LinearQueue queue;
    queue.array = (int *) malloc(sizeof(int) * size);
    queue.front = -1;
    queue.rear = -1;
    queue.size = size;
    queue.isEmpty = isEmpty;
    queue.isFull = isFull;
    queue.enqueue = enqueue;
    queue.dequeue = dequeue;
    queue.display = display;
    return queue;
}

void linearQueueMenu() {
    int size;
    printf("Enter size of queue: ");
    size = getInteger();
    LinearQueue queue = initializeLinearQueue(size);
    int choice;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        choice = getInteger();
        switch (choice) {
            case 1: {
                int value;
                printf("Enter value: ");
                value = getInteger();
                queue.enqueue(&queue, value);
                break;
            }
            case 2: {
                int value = queue.dequeue(&queue);
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;
            }
            case 3: {
                queue.display(queue);
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