#include "counterQueueTest.h"
#include "../../../src/queues//headers/counter_queue.h"

#include <stdio.h>

static void TestInitializeCounterQueue(CuTest *tc) {
    printf("\n---Counter Queue Test Suite---\n");
    CounterQueue counterQueue = initializeCounterQueue(5);
    CuAssertIntEquals(tc, 5, counterQueue.size);
    CuAssertIntEquals(tc, 0, counterQueue.front);
    CuAssertIntEquals(tc, 0, counterQueue.rear);
    CuAssertIntEquals(tc, 0, counterQueue.counter);
    CuAssertPtrNotNull(tc, counterQueue.array);
}

static void TestIsEmpty(CuTest *tc) {
    CounterQueue counterQueue = initializeCounterQueue(5);
    CuAssertIntEquals(tc, 1, counterQueue.isEmpty(counterQueue));
    CuAssertIntEquals(tc, 0, counterQueue.counter);
    counterQueue.enqueue(&counterQueue, 1);
    CuAssertIntEquals(tc, 1, counterQueue.counter);
    CuAssertIntEquals(tc, 0, counterQueue.isEmpty(counterQueue));
}

static void TestIsFull(CuTest *tc) {
    CounterQueue counterQueue = initializeCounterQueue(5);
    CuAssertIntEquals(tc, 0, counterQueue.isFull(counterQueue));
    for (int i = 0; i < 5; ++i) {
        counterQueue.enqueue(&counterQueue, i);
    }
    CuAssertIntEquals(tc, 5, counterQueue.counter);
    CuAssertIntEquals(tc, 1, counterQueue.isFull(counterQueue));
}

static void TestEnqueue(CuTest *tc) {
    CounterQueue counterQueue = initializeCounterQueue(5);
    for (int i = 0; i < 5; ++i) {
        counterQueue.enqueue(&counterQueue, i);
    }
    CuAssertIntEquals(tc, 1, counterQueue.isFull(counterQueue));
    CuAssertIntEquals(tc, 0, counterQueue.isEmpty(counterQueue));
    for (int i = 0; i < 5; ++i) {
        CuAssertIntEquals(tc, i, counterQueue.array[i]);
    }
}

static void TestDequeue(CuTest *tc) {
    CounterQueue counterQueue = initializeCounterQueue(5);
    CuAssertIntEquals(tc, -1, counterQueue.dequeue(&counterQueue));
    for (int i = 0; i < 5; ++i) {
        counterQueue.enqueue(&counterQueue, i);
    }
    for (int i = 0; i < 5; ++i) {
        CuAssertIntEquals(tc, i, counterQueue.dequeue(&counterQueue));
    }
    CuAssertIntEquals(tc, -1, counterQueue.dequeue(&counterQueue));
}

static void TestDisplay(CuTest *tc) {
    CounterQueue counterQueue = initializeCounterQueue(5);
    counterQueue.display(counterQueue);
    for (int i = 0; i < 5; ++i) {
        counterQueue.enqueue(&counterQueue, i);
    }
    counterQueue.display(counterQueue);
    CuAssertIntEquals(tc, 1, counterQueue.isFull(counterQueue));
    printf("---Counter Queue Test Suite Complete---\n");
}

CuSuite *CounterQueueGetSuite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestInitializeCounterQueue);
    SUITE_ADD_TEST(suite, TestIsEmpty);
    SUITE_ADD_TEST(suite, TestIsFull);
    SUITE_ADD_TEST(suite, TestEnqueue);
    SUITE_ADD_TEST(suite, TestDequeue);
    SUITE_ADD_TEST(suite, TestDisplay);
    return suite;
}
