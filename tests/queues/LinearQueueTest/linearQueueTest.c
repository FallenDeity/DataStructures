#include "linearQueueTest.h"
#include "../../../src/queues//headers/linear_queue.h"

#include <stdio.h>

static void TestInitializeLinearQueue(CuTest *tc) {
    printf("\n---Linear Queue Test Suite---\n");
    LinearQueue linearQueue = initializeLinearQueue(5);
    CuAssertIntEquals(tc, 5, linearQueue.size);
    CuAssertIntEquals(tc, -1, linearQueue.front);
    CuAssertIntEquals(tc, -1, linearQueue.rear);
    CuAssertPtrNotNull(tc, linearQueue.array);
}

static void TestIsEmpty(CuTest *tc) {
    LinearQueue linearQueue = initializeLinearQueue(5);
    CuAssertIntEquals(tc, 1, linearQueue.isEmpty(linearQueue));
    linearQueue.enqueue(&linearQueue, 1);
    CuAssertIntEquals(tc, 0, linearQueue.isEmpty(linearQueue));
}

static void TestIsFull(CuTest *tc) {
    LinearQueue linearQueue = initializeLinearQueue(5);
    CuAssertIntEquals(tc, 0, linearQueue.isFull(linearQueue));
    for (int i = 0; i < 5; ++i) {
        linearQueue.enqueue(&linearQueue, i);
    }
    CuAssertIntEquals(tc, 1, linearQueue.isFull(linearQueue));
}

static void TestEnqueue(CuTest *tc) {
    LinearQueue linearQueue = initializeLinearQueue(5);
    for (int i = 0; i < 5; ++i) {
        linearQueue.enqueue(&linearQueue, i);
    }
    CuAssertIntEquals(tc, 1, linearQueue.isFull(linearQueue));
    CuAssertIntEquals(tc, 0, linearQueue.isEmpty(linearQueue));
    for (int i = 0; i < 5; ++i) {
        CuAssertIntEquals(tc, i, linearQueue.array[i]);
    }
}

static void TestDequeue(CuTest *tc) {
    LinearQueue linearQueue = initializeLinearQueue(5);
    CuAssertIntEquals(tc, -1, linearQueue.dequeue(&linearQueue));
    for (int i = 0; i < 5; ++i) {
        linearQueue.enqueue(&linearQueue, i);
    }
    for (int i = 0; i < 5; ++i) {
        CuAssertIntEquals(tc, i, linearQueue.dequeue(&linearQueue));
    }
    CuAssertIntEquals(tc, -1, linearQueue.dequeue(&linearQueue));
}

static void TestDisplay(CuTest *tc) {
    LinearQueue linearQueue = initializeLinearQueue(5);
    linearQueue.display(linearQueue);
    for (int i = 0; i < 5; ++i) {
        linearQueue.enqueue(&linearQueue, i);
    }
    linearQueue.display(linearQueue);
    CuAssertIntEquals(tc, 1, linearQueue.isFull(linearQueue));
    printf("---Linear Queue Test Suite Complete---\n");
}

CuSuite *LinearQueueGetSuite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestInitializeLinearQueue);
    SUITE_ADD_TEST(suite, TestIsEmpty);
    SUITE_ADD_TEST(suite, TestIsFull);
    SUITE_ADD_TEST(suite, TestEnqueue);
    SUITE_ADD_TEST(suite, TestDequeue);
    SUITE_ADD_TEST(suite, TestDisplay);
    return suite;
}
