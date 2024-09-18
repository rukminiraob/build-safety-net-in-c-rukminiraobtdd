#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
const char* getDelimiter(const char* numbers, const char** numbers_start);
int sumNumbers(const char* numbers, const char* delimiter);

// Add function implementation
int Add(const char *numbers) {
    if (numbers[0] == '\0') {
        return 0;  // Return 0 for an empty string
    }

    const char *numbers_start = numbers;
    const char *delimiter = getDelimiter(numbers, &numbers_start);

    return sumNumbers(numbers_start, delimiter);
}

// Function to get delimiter from the input string
const char* getDelimiter(const char* numbers, const char** numbers_start) {
    static char default_delimiter[] = ",\n";  // Support commas and newlines by default
    static char custom_delimiter[2] = {0};

    // Check for custom delimiter
    if (numbers[0] == '/' && numbers[1] == '/') {
        custom_delimiter[0] = numbers[2];  // Set the custom delimiter
        *numbers_start = strchr(numbers, '\n') + 1;  // Skip past the first line
        return custom_delimiter;
    }

    return default_delimiter;  // Use default delimiters if no custom delimiter is found
}

// Function to sum the numbers based on the delimiter
int sumNumbers(const char* numbers, const char* delimiter) {
    int sum = 0;
    char *numbers_copy = strdup(numbers);  // Make a mutable copy of the input string
    char *token = strtok(numbers_copy, delimiter);

    while (token != NULL) {
        sum += atoi(token);  // Convert string to int and add to sum
        token = strtok(NULL, delimiter);
    }

    free(numbers_copy);
    return sum;
}

