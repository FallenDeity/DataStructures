#include "../headers/utils.h"

#include <stdio.h>
#include <stdlib.h>

int getInteger() {
    int value;
    char *end;
    char input[100];
    fgets(input, 100, stdin);
    value = strtol(input, &end, 10);
    if (end == input || *end != '\n') {
        printf("Invalid input\n");
        exit(1);
    }
    return value;
}