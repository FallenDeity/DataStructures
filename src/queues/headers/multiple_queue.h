#ifndef DATASTRUCTURES_MULTIPLE_QUEUE_H
#define DATASTRUCTURES_MULTIPLE_QUEUE_H

typedef struct MultipleQueue {
    int *array;
    int *front;
    int *rear;
    int queue_size;
    int total_queues;
    int (*isEmpty)(struct MultipleQueue, int);
    int (*isFull)(struct MultipleQueue, int);
    void (*enqueue)(struct MultipleQueue *, int, int);
    int (*dequeue)(struct MultipleQueue *, int);
    void (*display)(struct MultipleQueue, int);
} MultipleQueue;

MultipleQueue initializeMultipleQueue(int total_queues, int queue_size);
void multipleQueueMenu();

#endif//DATASTRUCTURES_MULTIPLE_QUEUE_H
