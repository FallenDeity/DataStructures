#include "tests/CuTest/CuTest.h"
#include "tests/stacks/MultipleStacksTest/multipleStackTest.h"
#include "tests/stacks/StacksTest/stackTest.h"

#include <stdio.h>

void runAllTests() {
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite, StackGetSuite());
    CuSuiteAddSuite(suite, MultipleStackGetSuite());

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
