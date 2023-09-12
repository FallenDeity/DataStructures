#ifndef DATASTRUCTURES_LINKED_LIST_H
#define DATASTRUCTURES_LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int (*isEmpty)(struct LinkedList);
    void (*insertAtHead)(struct LinkedList *, int);
    void (*insertAtTail)(struct LinkedList *, int);
    void (*insertAtPosition)(struct LinkedList *, int, int);
    void (*deleteAtHead)(struct LinkedList *);
    void (*deleteAtTail)(struct LinkedList *);
    void (*deleteAtPosition)(struct LinkedList *, int);
    void (*display)(struct LinkedList);
} LinkedList;

LinkedList initializeLinkedList();
void linkedListMenu();

#endif//DATASTRUCTURES_LINKED_LIST_H
