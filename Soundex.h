#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int Add(const char *numbers) {
    if (numbers[0] == '\0') {
        return 0;  // Return 0 for an empty string
    }

    int sum = 0;
    const char *delimiter = ",";
    char *numbers_copy = strdup(numbers);  // Make a mutable copy of the input string

    // Check for custom delimiter
    if (numbers[0] == '/' && numbers[1] == '/') {
        delimiter = (char[]){numbers[2], '\0'};  // Set the delimiter as the third character
        numbers_copy = strchr(numbers, '\n') + 1;  // Skip past the first line
    }

    char *token = strtok(numbers_copy, delimiter);
    
    while (token != NULL) {
        sum += atoi(token);  // Convert string to int and add to sum
        token = strtok(NULL, delimiter);
    }

    free(numbers_copy);
    return sum;
}
