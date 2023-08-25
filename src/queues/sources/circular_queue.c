#include "../headers/circular_queue.h"
#include "../../utils/headers/utils.h"

#include <stdio.h>
#include <stdlib.h>

static int isEmpty(CircularQueue queue) {
    return queue.front == -1 && queue.rear == -1;
}

static int isFull(CircularQueue queue) {
    return (queue.rear + 1) % queue.size == queue.front;
}

static void enqueue(CircularQueue *queue, int value) {
    if (queue->isEmpty(*queue)) {
        queue->front = 0;
        queue->rear = 0;
        queue->array[queue->rear] = value;
    } else if (queue->isFull(*queue)) {
        printf("Queue is full\n");
    } else {
        queue->rear = (queue->rear + 1) % queue->size;
        queue->array[queue->rear] = value;
    }
}

static int dequeue(CircularQueue *queue) {
    if (queue->isEmpty(*queue)) {
        printf("Queue is empty\n");
        return -1;
    } else if (queue->front == queue->rear) {
        int value = queue->array[queue->front];
        queue->front = -1;
        queue->rear = -1;
        return value;
    } else {
        int value = queue->array[queue->front];
        queue->front = (queue->front + 1) % queue->size;
        return value;
    }
}

static void display(CircularQueue queue) {
    if (queue.isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    int i = queue.front;
    for (; i != queue.rear; i = (i + 1) % queue.size) {
        printf("%d ", queue.array[i]);
    }
    printf("%d\n", queue.array[i]);
}

CircularQueue initializeCircularQueue(int size) {
    CircularQueue queue;
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

void circularQueueMenu() {
    int size, choice;
    printf("Enter size of queue: ");
    size = getInteger();
    CircularQueue queue = initializeCircularQueue(size);
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
                    printf("Dequeued value: %d\n", value);
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
