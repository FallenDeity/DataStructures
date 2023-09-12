#include "tests/CuTest/CuTest.h"
#include "tests/linkedlists/LinkedListTest/linkedListTest.h"
#include "tests/queues/CircularQueueTest/circularQueueTest.h"
#include "tests/queues/CounterQueueTest/counterQueueTest.h"
#include "tests/queues/LinearQueueTest/linearQueueTest.h"
#include "tests/queues/MultipleQueueTest/multipleQueueTest.h"
#include "tests/stacks/MultipleStackTest/multipleStackTest.h"
#include "tests/stacks/StackTest/stackTest.h"

#include <stdio.h>

void runAllTests() {
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite, StackGetSuite());
    CuSuiteAddSuite(suite, MultipleStackGetSuite());
    CuSuiteAddSuite(suite, CircularQueueGetSuite());
    CuSuiteAddSuite(suite, CounterQueueGetSuite());
    CuSuiteAddSuite(suite, LinearQueueGetSuite());
    CuSuiteAddSuite(suite, MultipleQueueGetSuite());
    CuSuiteAddSuite(suite, LinkedListGetSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);

    CuStringDelete(output);
    CuSuiteDelete(suite);
}

int main() {
    runAllTests();
    return 0;
}
