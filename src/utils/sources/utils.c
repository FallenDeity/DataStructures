#include "../headers/utils.h"

#include <stdio.h>
#include <stdlib.h>

char *getString() {
    int length = 1, index = 0;
    char ch;
    char *string = (char *) malloc(length * sizeof(char));
    while ((ch = (char) fgetc(stdin)) != '\n' && ch != EOF) {
        string[index++] = ch;
        if (index == length) {
            length *= 2;
            char *temp = (char *) realloc(string, length * sizeof(char));
            if (temp == NULL) {
                printf("Memory allocation failed\n");
                exit(1);
            }
            string = temp;
        }
    }
    string[index] = '\0';
    return string;
}

int getInteger() {
    char *end;
    int value = (int) strtol(getString(), &end, 10);
    if (*end != '\0') {
        printf("Invalid input\n");
        exit(1);
    }
    return value;
}