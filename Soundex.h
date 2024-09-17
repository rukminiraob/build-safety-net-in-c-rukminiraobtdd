#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

// Add function implementation
int Add(const char *numbers) {
    if (numbers[0] == '\0') {
        return 0;  // Return 0 for an empty string
    }

    int sum = 0;
    const char *delimiter = ",";
    char *token = strtok((char *)numbers, delimiter);
    
    while (token != NULL) {
        sum += atoi(token);  // Convert string to int and add to sum
        token = strtok(NULL, delimiter);
    }
    
    return sum;
}
