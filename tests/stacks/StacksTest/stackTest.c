#include "stackTest.h"
#include "../../../src/stacks/headers/stack.h"


static void TestInitializeStack(CuTest *tc) {
    Stack stack = initializeStack(5);
    CuAssertIntEquals(tc, 5, stack.size);
    CuAssertIntEquals(tc, -1, stack.top);
    CuAssertPtrNotNull(tc, stack.array);
}

static void TestIsEmpty(CuTest *tc) {
    Stack stack = initializeStack(5);
    CuAssertIntEquals(tc, 1, stack.isEmpty(stack));
    stack.push(&stack, 1);
    CuAssertIntEquals(tc, 0, stack.isEmpty(stack));
}

static void TestIsFull(CuTest *tc) {
    Stack stack = initializeStack(5);
    for (int i = 0; i < 5; i++) {
        stack.push(&stack, i);
    }
    CuAssertIntEquals(tc, 1, stack.isFull(stack));
    stack.pop(&stack);
    CuAssertIntEquals(tc, 0, stack.isFull(stack));
}

static void TestPush(CuTest *tc) {
    Stack stack = initializeStack(5);
    stack.push(&stack, 1);
    CuAssertIntEquals(tc, 0, stack.top);
    CuAssertIntEquals(tc, 1, stack.array[stack.top]);
    stack.push(&stack, 2);
    CuAssertIntEquals(tc, 1, stack.top);
    CuAssertIntEquals(tc, 2, stack.array[stack.top]);
}

static void TestPop(CuTest *tc) {
    Stack stack = initializeStack(5);
    stack.push(&stack, 1);
    stack.push(&stack, 2);
    CuAssertIntEquals(tc, 2, stack.pop(&stack));
    CuAssertIntEquals(tc, 1, stack.pop(&stack));
    CuAssertIntEquals(tc, -1, stack.pop(&stack));
}

static void TestDisplay(CuTest *tc) {
    Stack stack = initializeStack(5);
    stack.display(stack);
    stack.push(&stack, 1);
    stack.push(&stack, 2);
    stack.display(stack);
    CuAssertIntEquals(tc, 2, stack.pop(&stack));
}

CuSuite *StackGetSuite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestInitializeStack);
    SUITE_ADD_TEST(suite, TestIsEmpty);
    SUITE_ADD_TEST(suite, TestIsFull);
    SUITE_ADD_TEST(suite, TestPush);
    SUITE_ADD_TEST(suite, TestPop);
    SUITE_ADD_TEST(suite, TestDisplay);
    return suite;
}