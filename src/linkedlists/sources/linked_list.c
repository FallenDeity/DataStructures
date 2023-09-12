#include "../headers/linked_list.h"
#include "../../utils/headers/utils.h"

#include <stdio.h>
#include <stdlib.h>

static int isEmpty(LinkedList list) {
    return list.head == NULL;
}

static void insertAtHead(LinkedList *list, int value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
}

static void insertAtTail(LinkedList *list, int value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

static void insertAtPosition(LinkedList *list, int value, int position) {
    if (position == 0) {
        list->insertAtHead(list, value);
    } else {
        Node *new_node = (Node *) malloc(sizeof(Node));
        new_node->data = value;
        Node *temp = list->head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

static void deleteAtHead(LinkedList *list) {
    if (list->isEmpty(*list)) {
        printf("List is empty\n");
    } else {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
}

static void deleteAtTail(LinkedList *list) {
    if (list->isEmpty(*list)) {
        printf("List is empty\n");
    } else {
        Node *temp = list->head;
        while (temp->next != list->tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        free(list->tail);
        list->tail = temp;
    }
}

static void deleteAtPosition(LinkedList *list, int position) {
    if (list->isEmpty(*list)) {
        printf("List is empty\n");
    } else {
        if (position == 0) {
            list->deleteAtHead(list);
        } else {
            Node *temp = list->head;
            for (int i = 0; i < position - 1; i++) {
                temp = temp->next;
            }
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
        }
    }
}

static void display(LinkedList list) {
    if (list.isEmpty(list)) {
        printf("List is empty\n");
        return;
    }
    Node *temp = list.head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

LinkedList initializeLinkedList() {
    LinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.isEmpty = isEmpty;
    list.insertAtHead = insertAtHead;
    list.insertAtTail = insertAtTail;
    list.insertAtPosition = insertAtPosition;
    list.deleteAtHead = deleteAtHead;
    list.deleteAtTail = deleteAtTail;
    list.deleteAtPosition = deleteAtPosition;
    list.display = display;
    return list;
}

void linkedListMenu() {
    LinkedList list = initializeLinkedList();
    int choice;
    int value;
    int position;
    while (1) {
        printf("1. Insert at head\n2. Insert at tail\n3. Insert at position\n4. Delete at head\n5. Delete at tail\n6. Delete at position\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        choice = getInteger();
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                value = getInteger();
                list.insertAtHead(&list, value);
                break;
            case 2:
                printf("Enter value to insert: ");
                value = getInteger();
                list.insertAtTail(&list, value);
                break;
            case 3:
                printf("Enter value to insert: ");
                value = getInteger();
                printf("Enter position to insert: ");
                position = getInteger();
                list.insertAtPosition(&list, value, position);
                break;
            case 4:
                list.deleteAtHead(&list);
                break;
            case 5:
                list.deleteAtTail(&list);
                break;
            case 6:
                printf("Enter position to delete: ");
                position = getInteger();
                list.deleteAtPosition(&list, position);
                break;
            case 7:
                list.display(list);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}