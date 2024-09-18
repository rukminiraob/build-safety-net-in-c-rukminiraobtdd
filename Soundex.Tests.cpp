//#include "Soundex.h"
//#include <gtest/gtest.h>

/* TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
    char soundex[5];

    generateSoundex("AX", soundex);
    ASSERT_STREQ(soundex, "A200");

    generateSoundex("Robert", soundex);
    ASSERT_STREQ(soundex, "R163");

    generateSoundex("Rupert", soundex);
    ASSERT_STREQ(soundex, "R163");

    generateSoundex("Rubin", soundex);
    ASSERT_STREQ(soundex, "R150");

    generateSoundex("Ashcraft", soundex);
    ASSERT_STREQ(soundex, "A261");

    generateSoundex("Ashcroft", soundex);
    ASSERT_STREQ(soundex, "A261");
}

TEST(SoudexTestsuite, NonAlphabetCharacter) {
    char soundex[5];

    generateSoundex("A#hcroft", soundex);
    ASSERT_STREQ(soundex, "A261");
} */

#include <gtest/gtest.h>
#include "Soundex.h"
#include <stdio.h>
#include <assert.h>

// Function prototype for Add
int Add(const char *numbers);

// Main test function

int main() {
    // Test for an empty string input
    assert(Add("") == 0);
    
    // Test for a single number
    assert(Add("1") == 1);
    
    // Test for two numbers separated by a comma
    assert(Add("1,2") == 3);

    // Test for a custom delimiter
    assert(Add("//;\n1;2") == 3);

    // Test for a custom delimiter '|'
    assert(Add("//|\n1|2|3") == 6);

    // Test for a custom delimiter with newline
    assert(Add("//|\n1|2\n3") == 6);

    printf("All tests passed.\n");
    return 0;
}
