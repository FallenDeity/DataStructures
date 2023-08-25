#ifndef DATASTRUCTURES_CIRCULAR_QUEUE_H
#define DATASTRUCTURES_CIRCULAR_QUEUE_H

typedef struct CircularQueue {
    int *array;
    int front;
    int rear;
    int size;
    int (*isEmpty)(struct CircularQueue);
    int (*isFull)(struct CircularQueue);
    void (*enqueue)(struct CircularQueue *, int);
    int (*dequeue)(struct CircularQueue *);
    void (*display)(struct CircularQueue);
} CircularQueue;

CircularQueue initializeCircularQueue(int size);
void circularQueueMenu();

#endif//DATASTRUCTURES_CIRCULAR_QUEUE_H
