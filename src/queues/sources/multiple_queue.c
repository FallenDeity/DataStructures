#include "../headers/multiple_queue.h"
#include "../../utils/headers/utils.h"

#include <stdio.h>
#include <stdlib.h>

static int isEmpty(MultipleQueue queue, int queue_number) {
    return queue.front[queue_number] == queue.rear[queue_number];
}

static int isFull(MultipleQueue queue, int queue_number) {
    return queue.rear[queue_number] == queue.queue_size * (queue_number + 1) - 1;
}

static void enqueue(MultipleQueue *queue, int queue_number, int value) {
    if (queue->isFull(*queue, queue_number)) {
        printf("Queue is full\n");
    } else {
        queue->rear[queue_number]++;
        queue->array[queue->rear[queue_number]] = value;
    }
}

static int dequeue(MultipleQueue *queue, int queue_number) {
    if (queue->isEmpty(*queue, queue_number)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        queue->front[queue_number]++;
        int value = queue->array[queue->front[queue_number]];
        return value;
    }
}

static void display(MultipleQueue queue, int queue_number) {
    if (queue.isEmpty(queue, queue_number)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue.front[queue_number] + 1; i <= queue.rear[queue_number]; i++) {
        printf("%d ", queue.array[i]);
    }
    printf("\n");
}

MultipleQueue initializeMultipleQueue(int total_queues, int queue_size) {
    MultipleQueue queue;
    queue.array = (int *) malloc(sizeof(int) * total_queues * queue_size);
    queue.front = (int *) malloc(sizeof(int) * total_queues);
    queue.rear = (int *) malloc(sizeof(int) * total_queues);
    queue.queue_size = queue_size;
    queue.total_queues = total_queues;
    for (int i = 0; i < total_queues; i++) {
        queue.front[i] = -1;
        queue.rear[i] = -1;
    }
    queue.isEmpty = isEmpty;
    queue.isFull = isFull;
    queue.enqueue = enqueue;
    queue.dequeue = dequeue;
    queue.display = display;
    return queue;
}

void multipleQueueMenu() {
    int total_queues, queue_size;
    printf("Enter total number of queues: ");
    total_queues = getInteger();
    printf("Enter size of each queue: ");
    queue_size = getInteger();
    MultipleQueue queue = initializeMultipleQueue(total_queues, queue_size);
    int choice, queue_number, value;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        choice = getInteger();
        printf("Enter queue number (%d-%d): ", 0, total_queues - 1);
        queue_number = getInteger();
        if (queue_number < 0 || queue_number >= total_queues) {
            printf("Invalid queue number\n");
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter value: ");
                value = getInteger();
                queue.enqueue(&queue, queue_number, value);
                break;
            case 2:
                value = queue.dequeue(&queue, queue_number);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                queue.display(queue, queue_number);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
