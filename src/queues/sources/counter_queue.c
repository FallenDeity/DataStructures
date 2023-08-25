#include "../headers/counter_queue.h"
#include "../../utils/headers/utils.h"

#include <stdio.h>
#include <stdlib.h>

static int isEmpty(CounterQueue queue) {
    return queue.counter == 0;
}

static int isFull(CounterQueue queue) {
    return queue.counter == queue.size;
}

static void enqueue(CounterQueue *queue, int value) {
    if (queue->isFull(*queue)) {
        printf("Queue is full\n");
    } else {
        queue->array[queue->rear] = value;
        queue->rear = (queue->rear + 1) % queue->size;
        queue->counter++;
    }
}

static int dequeue(CounterQueue *queue) {
    if (queue->isEmpty(*queue)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int value = queue->array[queue->front];
        queue->front = (queue->front + 1) % queue->size;
        queue->counter--;
        return value;
    }
}

static void display(CounterQueue queue) {
    if (queue.isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    int temp = queue.counter;
    int i = queue.front;
    while (temp > 0) {
        printf("%d ", queue.array[i]);
        i = (i + 1) % queue.size;
        temp--;
    }
    printf("\n");
}

CounterQueue initializeCounterQueue(int size) {
    CounterQueue queue;
    queue.array = (int *) malloc(sizeof(int) * size);
    queue.front = 0;
    queue.rear = 0;
    queue.size = size;
    queue.counter = 0;
    queue.isEmpty = isEmpty;
    queue.isFull = isFull;
    queue.enqueue = enqueue;
    queue.dequeue = dequeue;
    queue.display = display;
    return queue;
}

void counterQueueMenu() {
    int size;
    printf("Enter size of queue: ");
    size = getInteger();
    CounterQueue queue = initializeCounterQueue(size);
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
                    printf("Dequeued %d\n", value);
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
