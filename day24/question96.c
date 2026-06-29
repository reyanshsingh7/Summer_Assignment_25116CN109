#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Removes duplicate characters from the string in place
void removeDuplicates(char *str) {
    int seen[26]  = {0};  // tracks seen alphabetic characters
    int seen2[256] = {0}; // tracks seen non-alphabetic characters
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (isalpha(ch)) {
            int idx = tolower(ch) - 'a';  // map character to index
            if (!seen[idx]) {             // check if character is seen
                seen[idx] = 1;            // mark character as seen
                str[j++]  = ch;           // write character to result
            }
        } else {
            if (!seen2[(unsigned char)ch]) {  // check if character is seen
                seen2[(unsigned char)ch] = 1; // mark character as seen
                str[j++] = ch;               // write character to result
            }
        }
    }

    str[j] = '\0';
}

int main() {
    char str[1000];

    // Input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline added by fgets
    str[strcspn(str, "\n")] = '\0';

    // Print original and result
    printf("Original : \"%s\"\n", str);
    removeDuplicates(str);
    printf("Result   : \"%s\"\n", str);

    return 0;
}