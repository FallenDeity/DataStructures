#ifndef DATASTRUCTURES_PRIORITY_QUEUE_H
#define DATASTRUCTURES_PRIORITY_QUEUE_H

typedef struct {
    int priority;
    int value;
} Element;

typedef struct PriorityQueue {
    Element *array;
    int length;
    int array_size;
    void (*enqueue)(struct PriorityQueue *, Element);
    void (*display)(struct PriorityQueue);
    Element (*dequeue)(struct PriorityQueue *);
} PriorityQueue;

PriorityQueue initializePriorityQueue(int size);
void priorityQueueMenu();
Element initializePriorityQueueElement();

#endif//DATASTRUCTURES_PRIORITY_QUEUE_H
