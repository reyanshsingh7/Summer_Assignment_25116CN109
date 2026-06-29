#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Finds and prints the longest word in the string
void longestWord(const char *str) {
    int  start    = 0; 
    int  maxStart = 0;
    int  maxLen   = 0;
    int  i        = 0;

    while (1) {
        // Skip spaces
        while (str[i] != '\0' && isspace(str[i]))
            i++;

        if (str[i] == '\0')  // end of string
            break;

        start = i;  // mark start of current word

        // Find end of current word
        while (str[i] != '\0' && !isspace(str[i]))
            i++;

        int wordLen = i - start;  // length of current word

        // Update longest word if current word is longer
        if (wordLen > maxLen) {
            maxLen   = wordLen;
            maxStart = start;
        }
    }

    // Print longest word
    if (maxLen == 0) {
        printf("No words found\n");
        return;
    }

    printf("Longest Word : \"");
    for (int i = maxStart; i < maxStart + maxLen; i++)
        printf("%c", str[i]);
    printf("\"\n");
    printf("Length       : %d\n", maxLen);
}

int main() {
    char str[1000];

    // Input
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline added by fgets
    str[strcspn(str, "\n")] = '\0';

    // Print sentence and longest word
    printf("Sentence : \"%s\"\n", str);
    longestWord(str);

    return 0;
}