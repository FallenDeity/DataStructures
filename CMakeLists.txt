cmake_minimum_required(VERSION 3.26)
project(DataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(DataStructures main.c
        src/stacks/sources/stack.c
        src/stacks/headers/stack.h
        src/utils/sources/utils.c
        src/utils/headers/utils.h
        src/stacks/sources/multiple_stack.c
        src/stacks/headers/multiple_stack.h
        tests/CuTest/CuTest.h
        tests/CuTest/CuTest.c
        tests/stacks/StackTest/stackTest.c
        tests/stacks/StackTest/stackTest.h
        tests/stacks/MultipleStackTest/multipleStackTest.c
        tests/stacks/MultipleStackTest/multipleStackTest.h
        src/queues/sources/linear_queue.c
        src/queues/headers/linear_queue.h
        src/queues/headers/priority_queue.h
        src/queues/sources/priority_queue.c
        src/queues/headers/circular_queue.h
        src/queues/sources/circular_queue.c
        src/queues/headers/counter_queue.h
        src/queues/sources/counter_queue.c
        src/queues/headers/multiple_queue.h
        src/queues/sources/multiple_queue.c
        tests/queues/CircularQueueTest/circularQueueTest.c
        tests/queues/CircularQueueTest/circularQueueTest.h
        tests/queues/CounterQueueTest/counterQueueTest.c
        tests/queues/CounterQueueTest/counterQueueTest.h
        tests/queues/LinearQueueTest/linearQueueTest.c
        tests/queues/LinearQueueTest/linearQueueTest.h
        tests/queues/MultipleQueueTest/multipleQueueTest.c
        tests/queues/MultipleQueueTest/multipleQueueTest.h)
