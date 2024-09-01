#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    // Array to store Soundex codes for 'A' to 'Z'
    static const char soundexTable[26] = {
        // A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };

    c = toupper(c);

    // Check if the character is a letter
    if (c >= 'A' && c <= 'Z') {
        return soundexTable[c - 'A'];
    } else {
        return '0'; // Non-alphabetical characters
    }
}

void generateSoundex(const char *name, char *soundex) {
    // Handle the case where the name is empty
    if (name[0] == '\0') {
        soundex[0] = '\0';
        return;
    }

    // Initialize the soundex code
    soundex[0] = toupper(name[0]);
    soundex[1] = soundex[2] = soundex[3] = '0';
    soundex[4] = '\0'; // Null-terminate the string

    char lastCode = '0'; // Keep track of the last non-zero code
    int sIndex = 1;

    // Process each character in the name, starting from the second character
    for (int i = 1; name[i] != '\0' && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != lastCode) {
            soundex[sIndex++] = code;
            lastCode = code;
        }
    }
}


#endif // SOUNDEX_H
