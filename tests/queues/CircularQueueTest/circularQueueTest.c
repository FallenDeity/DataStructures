#include "circularQueueTest.h"
#include "../../../src/queues//headers/circular_queue.h"

#include <stdio.h>

static void TestInitializeCircularQueue(CuTest *tc) {
    printf("\n---Circular Queue Test Suite---\n");
    CircularQueue circularQueue = initializeCircularQueue(5);
    CuAssertIntEquals(tc, 5, circularQueue.size);
    CuAssertIntEquals(tc, -1, circularQueue.front);
    CuAssertIntEquals(tc, -1, circularQueue.rear);
    CuAssertPtrNotNull(tc, circularQueue.array);
}

static void TestIsEmpty(CuTest *tc) {
    CircularQueue circularQueue = initializeCircularQueue(5);
    CuAssertIntEquals(tc, 1, circularQueue.isEmpty(circularQueue));
    circularQueue.enqueue(&circularQueue, 1);
    CuAssertIntEquals(tc, 0, circularQueue.isEmpty(circularQueue));
}

static void TestIsFull(CuTest *tc) {
    CircularQueue circularQueue = initializeCircularQueue(5);
    CuAssertIntEquals(tc, 0, circularQueue.isFull(circularQueue));
    for (int i = 0; i < 5; ++i) {
        circularQueue.enqueue(&circularQueue, i);
    }
    CuAssertIntEquals(tc, 1, circularQueue.isFull(circularQueue));
}

static void TestEnqueue(CuTest *tc) {
    CircularQueue circularQueue = initializeCircularQueue(5);
    for (int i = 0; i < 5; ++i) {
        circularQueue.enqueue(&circularQueue, i);
    }
    CuAssertIntEquals(tc, 1, circularQueue.isFull(circularQueue));
    CuAssertIntEquals(tc, 0, circularQueue.isEmpty(circularQueue));
    for (int i = 0; i < 5; ++i) {
        CuAssertIntEquals(tc, i, circularQueue.array[i]);
    }
}

static void TestDequeue(CuTest *tc) {
    CircularQueue circularQueue = initializeCircularQueue(5);
    CuAssertIntEquals(tc, -1, circularQueue.dequeue(&circularQueue));
    for (int i = 0; i < 5; ++i) {
        circularQueue.enqueue(&circularQueue, i);
    }
    for (int i = 0; i < 5; ++i) {
        CuAssertIntEquals(tc, i, circularQueue.dequeue(&circularQueue));
    }
    CuAssertIntEquals(tc, -1, circularQueue.dequeue(&circularQueue));
}

static void TestDisplay(CuTest *tc) {
    CircularQueue circularQueue = initializeCircularQueue(5);
    circularQueue.display(circularQueue);
    for (int i = 0; i < 5; ++i) {
        circularQueue.enqueue(&circularQueue, i);
    }
    circularQueue.display(circularQueue);
    CuAssertIntEquals(tc, 1, circularQueue.isFull(circularQueue));
    printf("---Circular Queue Test Suite Complete---\n");
}

CuSuite *CircularQueueGetSuite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestInitializeCircularQueue);
    SUITE_ADD_TEST(suite, TestIsEmpty);
    SUITE_ADD_TEST(suite, TestIsFull);
    SUITE_ADD_TEST(suite, TestEnqueue);
    SUITE_ADD_TEST(suite, TestDequeue);
    SUITE_ADD_TEST(suite, TestDisplay);
    return suite;
}
