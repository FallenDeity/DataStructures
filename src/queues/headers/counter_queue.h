#ifndef DATASTRUCTURES_COUNTER_QUEUE_H
#define DATASTRUCTURES_COUNTER_QUEUE_H

typedef struct CounterQueue {
    int *array;
    int front;
    int rear;
    int size;
    int counter;
    int (*isEmpty)(struct CounterQueue);
    int (*isFull)(struct CounterQueue);
    void (*enqueue)(struct CounterQueue *, int);
    int (*dequeue)(struct CounterQueue *);
    void (*display)(struct CounterQueue);
} CounterQueue;

CounterQueue initializeCounterQueue(int size);
void counterQueueMenu();

#endif//DATASTRUCTURES_COUNTER_QUEUE_H
