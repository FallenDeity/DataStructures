#include "../headers/priority_queue.h"
#include "../../utils/headers/utils.h"

#include <stdio.h>
#include <stdlib.h>

static void growSize(PriorityQueue *queue) {
    int size = queue->array_size * 2;
    Element *temp = (Element *) realloc(queue->array, sizeof(Element) * size);
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    queue->array = temp;
    queue->array_size = size;
}

Element initializePriorityQueueElement() {
    int p, v;
    printf("Enter priority: ");
    p = getInteger();
    printf("Enter value: ");
    v = getInteger();
    Element e = {p, v};
    return e;
}

static void sort(PriorityQueue *queue) {
    for (int i = 0; i < queue->length; i++) {
        for (int j = i + 1; j < queue->length; j++) {
            if (queue->array[i].priority < queue->array[j].priority) {
                Element temp = queue->array[i];
                queue->array[i] = queue->array[j];
                queue->array[j] = temp;
            }
        }
    }
}

static void enqueue(PriorityQueue *queue, Element e) {
    if (queue->length == queue->array_size) {
        growSize(queue);
    }
    queue->array[queue->length] = e;
    queue->length++;
    sort(queue);
}

static void display(PriorityQueue queue) {
    for (int i = 0; i < queue.length; i++) {
        printf("%d ", queue.array[i].value);
    }
    printf("\n");
}

static Element dequeue(PriorityQueue *queue) {
    if (queue->length == 0) {
        printf("Queue is empty\n");
        Element e = {-1, -1};
        return e;
    }
    Element element = queue->array[0];
    queue->length--;
    for (int i = 0; i < queue->length; i++) {
        queue->array[i] = queue->array[i + 1];
    }
    return element;
}

PriorityQueue initializePriorityQueue(int size) {
    PriorityQueue queue;
    queue.array = (Element *) malloc(sizeof(Element) * size);
    queue.length = 0;
    queue.array_size = size;
    queue.enqueue = enqueue;
    queue.dequeue = dequeue;
    queue.display = display;
    return queue;
}

void priorityQueueMenu() {
    Element ele;
    int size;
    printf("Enter size of queue: ");
    size = getInteger();
    PriorityQueue queue = initializePriorityQueue(size);
    int choice;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        choice = getInteger();
        switch (choice) {
            case 1:
                ele = initializePriorityQueueElement();
                queue.enqueue(&queue, ele);
                printf("Element(value=%d, priority=%d) enqueued\n", ele.value, ele.priority);
                break;
            case 2:
                ele = queue.dequeue(&queue);
                if (ele.priority != -1) {
                    printf("Element(value=%d, priority=%d) dequeued\n", ele.value, ele.priority);
                }
                break;
            case 3:
                queue.display(queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
