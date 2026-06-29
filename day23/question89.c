#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Returns the first non-repeating character, or '\0' if none found
char nonRepeating(const char *str) {
    int freq[26] = {0};  // array to store frequency of a-z

    // Count frequency of each character
    for (int i = 0; str[i] != '\0'; i++)
        if (isalpha(str[i]))                  // skip non-alphabetic characters
            freq[tolower(str[i]) - 'a']++;

    // Find first character with frequency 1
    for (int i = 0; str[i] != '\0'; i++)
        if (isalpha(str[i]))                  // skip non-alphabetic characters
            if (freq[tolower(str[i]) - 'a'] == 1)
                return str[i];

    return '\0';
}

int main() {
    char str[1000];

    // Input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline added by fgets
    str[strcspn(str, "\n")] = '\0';

    // Print string and result
    printf("String : \"%s\"\n", str);

    char result = nonRepeating(str);

    if (result != '\0')
        printf("First Non-Repeating : '%c'\n", result);
    else
        printf("No non-repeating character found\n");

    return 0;
}