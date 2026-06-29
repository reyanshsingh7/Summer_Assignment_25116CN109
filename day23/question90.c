#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Returns the first repeating character, or '\0' if none found
char firstrepeating(const char *str) {
    int freq[26] = {0};  // array to store frequency of a-z

    // Find first character that has been seen before
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {                        // skip non-alphabetic characters
            int idx = tolower(str[i]) - 'a';
            freq[idx]++;
            if (freq[idx] == 2)
                return str[i];                        // return first repeating character
        }
    }

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

    char result = firstrepeating(str);

    if (result != '\0')
        printf("First Repeating : '%c'\n", result);
    else
        printf("No repeating character found\n");

    return 0;
}