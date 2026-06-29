#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Counts and prints frequency of each character in the string
void charfrequency(const char *str) {
    int freq[26] = {0};  // array to store frequency of a-z

    // Count frequency of each character
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i]))                    // skip non-alphabetic characters
            freq[tolower(str[i]) - 'a']++;
    }

    // Print frequency of each character
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0)
            printf("'%c' : %d\n", 'a' + i, freq[i]);
    }
}

int main() {
    char str[1000];

    // Input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline added by fgets
    str[strcspn(str, "\n")] = '\0';

    // Print string and character frequency
    printf("String    : \"%s\"\n", str);
    printf("Frequency :\n");
    charfrequency(str);

    return 0;
}