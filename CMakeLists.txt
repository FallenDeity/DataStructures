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
        tests/stacks/StacksTest/stackTest.c
        tests/stacks/StacksTest/stackTest.h
        tests/stacks/MultipleStacksTest/multipleStackTest.c
        tests/stacks/MultipleStacksTest/multipleStackTest.h)
