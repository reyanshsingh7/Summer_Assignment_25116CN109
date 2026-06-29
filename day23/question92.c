#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Returns the maximum occurring character in the string
char maxOccurring(const char *str) {
    int freq[26] = {0};  // array to store frequency of a-z

    // Count frequency of each character
    for (int i = 0; str[i] != '\0'; i++)
        if (isalpha(str[i]))                // skip non-alphabetic characters
            freq[tolower(str[i]) - 'a']++;

    // Find maximum frequency
    int max = 0;
    char maxChar = '\0';

    for (int i = 0; i < 26; i++) {
        if (freq[i] > max) {
            max     = freq[i];
            maxChar = 'a' + i;
        }
    }

    return maxChar;
}

int main() {
    char str[1000];

    // Input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline added by fgets
    str[strcspn(str, "\n")] = '\0';

    // Print string and result
    printf("String  : \"%s\"\n", str);

    char result = maxOccurring(str);

    if (result != '\0')
        printf("Max Occurring : '%c'\n", result);
    else
        printf("No alphabetic character found\n");

    return 0;
}