#ifndef DATASTRUCTURES_LINEAR_QUEUE_H
#define DATASTRUCTURES_LINEAR_QUEUE_H

typedef struct LinearQueue {
    int *array;
    int front;
    int rear;
    int size;
    int (*isEmpty)(struct LinearQueue);
    int (*isFull)(struct LinearQueue);
    void (*enqueue)(struct LinearQueue *, int);
    int (*dequeue)(struct LinearQueue *);
    void (*display)(struct LinearQueue);
} LinearQueue;

LinearQueue initializeLinearQueue(int size);
void linearQueueMenu();

#endif//DATASTRUCTURES_LINEAR_QUEUE_H
