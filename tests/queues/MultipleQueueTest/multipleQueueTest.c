#include "multipleQueueTest.h"
#include "../../../src/queues//headers/multiple_queue.h"

#include <stdio.h>

static void TestInitializeMultipleQueue(CuTest *tc) {
    printf("\n---Multiple Queue Test Suite---\n");
    MultipleQueue multipleQueue = initializeMultipleQueue(3, 5);
    CuAssertIntEquals(tc, 5, multipleQueue.queue_size);
    CuAssertIntEquals(tc, 3, multipleQueue.total_queues);
    CuAssertPtrNotNull(tc, multipleQueue.array);
    CuAssertPtrNotNull(tc, multipleQueue.front);
    CuAssertPtrNotNull(tc, multipleQueue.rear);
}

static void TestIsEmpty(CuTest *tc) {
    MultipleQueue multipleQueue = initializeMultipleQueue(3, 5);
    CuAssertIntEquals(tc, 1, multipleQueue.isEmpty(multipleQueue, 0));
    multipleQueue.enqueue(&multipleQueue, 0, 1);
    CuAssertIntEquals(tc, 0, multipleQueue.isEmpty(multipleQueue, 0));
}

static void TestIsFull(CuTest *tc) {
    MultipleQueue multipleQueue = initializeMultipleQueue(3, 5);
    CuAssertIntEquals(tc, 0, multipleQueue.isFull(multipleQueue, 0));
    for (int i = 0; i < 5; ++i) {
        multipleQueue.enqueue(&multipleQueue, 0, i);
    }
    CuAssertIntEquals(tc, 1, multipleQueue.isFull(multipleQueue, 0));
}

static void TestEnqueue(CuTest *tc) {
    MultipleQueue multipleQueue = initializeMultipleQueue(3, 5);
    for (int i = 0; i < 5; ++i) {
        multipleQueue.enqueue(&multipleQueue, 0, i);
    }
    CuAssertIntEquals(tc, 1, multipleQueue.isFull(multipleQueue, 0));
    CuAssertIntEquals(tc, 0, multipleQueue.isEmpty(multipleQueue, 0));
    for (int i = 0; i < 5; ++i) {
        CuAssertIntEquals(tc, i, multipleQueue.array[i]);
    }
}

static void TestDequeue(CuTest *tc) {
    MultipleQueue multipleQueue = initializeMultipleQueue(3, 5);
    CuAssertIntEquals(tc, -1, multipleQueue.dequeue(&multipleQueue, 0));
    for (int i = 0; i < 5; ++i) {
        multipleQueue.enqueue(&multipleQueue, 0, i);
    }
    for (int i = 0; i < 5; ++i) {
        CuAssertIntEquals(tc, i, multipleQueue.dequeue(&multipleQueue, 0));
    }
    CuAssertIntEquals(tc, -1, multipleQueue.dequeue(&multipleQueue, 0));
}

static void TestDisplay(CuTest *tc) {
    MultipleQueue multipleQueue = initializeMultipleQueue(3, 5);
    multipleQueue.display(multipleQueue, 0);
    for (int i = 0; i < 5; ++i) {
        multipleQueue.enqueue(&multipleQueue, 0, i);
    }
    multipleQueue.display(multipleQueue, 0);
    CuAssertIntEquals(tc, 1, multipleQueue.isFull(multipleQueue, 0));
    printf("---Multiple Queue Test Suite Complete---\n");
}

CuSuite *MultipleQueueGetSuite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestInitializeMultipleQueue);
    SUITE_ADD_TEST(suite, TestIsEmpty);
    SUITE_ADD_TEST(suite, TestIsFull);
    SUITE_ADD_TEST(suite, TestEnqueue);
    SUITE_ADD_TEST(suite, TestDequeue);
    SUITE_ADD_TEST(suite, TestDisplay);
    return suite;
}
