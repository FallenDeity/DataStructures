#include "linkedListTest.h"
#include "../../../src/linkedlists/headers/linked_list.h"

#include <stdio.h>

static void TestInitializeLinkedList(CuTest *tc) {
    printf("\n---Linked List Test Suite---\n");
    LinkedList list = initializeLinkedList();
    CuAssertPtrEquals(tc, NULL, list.head);
    CuAssertPtrEquals(tc, NULL, list.tail);
}

static void TestIsEmpty(CuTest *tc) {
    LinkedList list = initializeLinkedList();
    CuAssertIntEquals(tc, 1, list.isEmpty(list));
    list.insertAtHead(&list, 1);
    CuAssertIntEquals(tc, 0, list.isEmpty(list));
}

static void TestInsertAtHead(CuTest *tc) {
    LinkedList list = initializeLinkedList();
    list.insertAtHead(&list, 1);
    CuAssertIntEquals(tc, 1, list.head->data);
    CuAssertIntEquals(tc, 1, list.tail->data);
    list.insertAtHead(&list, 2);
    CuAssertIntEquals(tc, 2, list.head->data);
    CuAssertIntEquals(tc, 1, list.tail->data);
}

static void TestInsertAtTail(CuTest *tc) {
    LinkedList list = initializeLinkedList();
    list.insertAtTail(&list, 1);
    CuAssertIntEquals(tc, 1, list.head->data);
    CuAssertIntEquals(tc, 1, list.tail->data);
    list.insertAtTail(&list, 2);
    CuAssertIntEquals(tc, 1, list.head->data);
    CuAssertIntEquals(tc, 2, list.tail->data);
}

static void TestInsertAtPosition(CuTest *tc) {
    LinkedList list = initializeLinkedList();
    list.insertAtPosition(&list, 1, 0);
    CuAssertIntEquals(tc, 1, list.head->data);
    CuAssertIntEquals(tc, 1, list.tail->data);
    list.insertAtPosition(&list, 2, 0);
    CuAssertIntEquals(tc, 2, list.head->data);
    CuAssertIntEquals(tc, 1, list.tail->data);
    list.insertAtPosition(&list, 3, 1);
    CuAssertIntEquals(tc, 2, list.head->data);
    CuAssertIntEquals(tc, 1, list.tail->data);
    list.insertAtPosition(&list, 4, 2);
    CuAssertIntEquals(tc, 2, list.head->data);
    CuAssertIntEquals(tc, 1, list.tail->data);
}

static void TestDeleteAtHead(CuTest *tc) {
    LinkedList list = initializeLinkedList();
    list.deleteAtHead(&list);
    CuAssertIntEquals(tc, 1, list.isEmpty(list));
    list.insertAtHead(&list, 1);
    list.insertAtHead(&list, 2);
    list.deleteAtHead(&list);
    CuAssertIntEquals(tc, 1, list.head->data);
    CuAssertIntEquals(tc, 1, list.tail->data);
}

static void TestDeleteAtTail(CuTest *tc) {
    LinkedList list = initializeLinkedList();
    list.deleteAtTail(&list);
    CuAssertIntEquals(tc, 1, list.isEmpty(list));
    list.insertAtHead(&list, 1);
    list.insertAtHead(&list, 2);
    list.deleteAtTail(&list);
    CuAssertIntEquals(tc, 2, list.head->data);
    CuAssertIntEquals(tc, 2, list.tail->data);
}

static void TestDeleteAtPosition(CuTest *tc) {
    LinkedList list = initializeLinkedList();
    list.deleteAtPosition(&list, 0);
    CuAssertIntEquals(tc, 1, list.isEmpty(list));
    list.insertAtHead(&list, 1);
    list.insertAtHead(&list, 2);
    list.deleteAtPosition(&list, 0);
    CuAssertIntEquals(tc, 1, list.head->data);
    CuAssertIntEquals(tc, 1, list.tail->data);
    list.insertAtHead(&list, 2);
    list.insertAtHead(&list, 3);
    list.deleteAtPosition(&list, 1);
    CuAssertIntEquals(tc, 3, list.head->data);
    CuAssertIntEquals(tc, 1, list.tail->data);
}

static void TestDisplay(CuTest *tc) {
    LinkedList list = initializeLinkedList();
    list.display(list);
    list.insertAtHead(&list, 1);
    list.insertAtHead(&list, 2);
    list.insertAtHead(&list, 3);
    list.display(list);
    CuAssertIntEquals(tc, 3, list.head->data);
    printf("\n---End Linked List Test Suite---\n");
}

CuSuite *LinkedListGetSuite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestInitializeLinkedList);
    SUITE_ADD_TEST(suite, TestIsEmpty);
    SUITE_ADD_TEST(suite, TestInsertAtHead);
    SUITE_ADD_TEST(suite, TestInsertAtTail);
    SUITE_ADD_TEST(suite, TestInsertAtPosition);
    SUITE_ADD_TEST(suite, TestDeleteAtHead);
    SUITE_ADD_TEST(suite, TestDeleteAtTail);
    SUITE_ADD_TEST(suite, TestDeleteAtPosition);
    SUITE_ADD_TEST(suite, TestDisplay);
    return suite;
}