#include "multipleStackTest.h"
#include "../../../src/stacks/headers/multiple_stack.h"

static void TestInitializeMultipleStack(CuTest *tc) {
    MultipleStack multipleStack = initializeMultipleStack(5, 3);
    CuAssertIntEquals(tc, 3, multipleStack.stack_size);
    CuAssertIntEquals(tc, 5, multipleStack.total_stacks);
    CuAssertPtrNotNull(tc, multipleStack.array);
}

static void TestIsEmpty(CuTest *tc) {
    MultipleStack multipleStack = initializeMultipleStack(5, 3);
    CuAssertIntEquals(tc, 1, multipleStack.isEmpty(multipleStack, 0));
    multipleStack.push(&multipleStack, 0, 1);
    CuAssertIntEquals(tc, 0, multipleStack.isEmpty(multipleStack, 0));
}

static void TestIsFull(CuTest *tc) {
    MultipleStack multipleStack = initializeMultipleStack(5, 3);
    for (int i = 0; i < 5; i++) {
        multipleStack.push(&multipleStack, 0, i);
    }
    CuAssertIntEquals(tc, 1, multipleStack.isFull(multipleStack, 0));
    multipleStack.pop(&multipleStack, 0);
    CuAssertIntEquals(tc, 0, multipleStack.isFull(multipleStack, 0));
}

static void TestPush(CuTest *tc) {
    MultipleStack multipleStack = initializeMultipleStack(5, 3);
    multipleStack.push(&multipleStack, 0, 1);
    CuAssertIntEquals(tc, 0, multipleStack.top[0]);
    CuAssertIntEquals(tc, 1, multipleStack.array[multipleStack.top[0]]);
    multipleStack.push(&multipleStack, 0, 2);
    CuAssertIntEquals(tc, 1, multipleStack.top[0]);
    CuAssertIntEquals(tc, 2, multipleStack.array[multipleStack.top[0]]);
}

static void TestPop(CuTest *tc) {
    MultipleStack multipleStack = initializeMultipleStack(5, 3);
    multipleStack.push(&multipleStack, 0, 1);
    multipleStack.push(&multipleStack, 0, 2);
    CuAssertIntEquals(tc, 2, multipleStack.pop(&multipleStack, 0));
    CuAssertIntEquals(tc, 1, multipleStack.pop(&multipleStack, 0));
    CuAssertIntEquals(tc, -1, multipleStack.pop(&multipleStack, 0));
}

static void TestDisplay(CuTest *tc) {
    MultipleStack multipleStack = initializeMultipleStack(5, 3);
    multipleStack.display(multipleStack, 0);
    multipleStack.push(&multipleStack, 0, 1);
    multipleStack.push(&multipleStack, 0, 2);
    multipleStack.display(multipleStack, 0);
    CuAssertIntEquals(tc, 1, multipleStack.top[0]);
}

CuSuite *MultipleStackGetSuite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestInitializeMultipleStack);
    SUITE_ADD_TEST(suite, TestIsEmpty);
    SUITE_ADD_TEST(suite, TestIsFull);
    SUITE_ADD_TEST(suite, TestPush);
    SUITE_ADD_TEST(suite, TestPop);
    SUITE_ADD_TEST(suite, TestDisplay);
    return suite;
}
