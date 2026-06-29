#include <stdio.h>
#include <ctype.h>

// Returns the number of words in the string
int countwords(const char *str) {
    int words = 0;
    int inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {  // non-space character
            if (!inWord) {       // entering a new word
                words++;
                inWord = 1;
            }
        } else {
            inWord = 0;          // exiting a word
        }
    }

    return words;
}

int main() {
    char str[1000];

    // Input
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline added by fgets
    str[strcspn(str, "\n")] = '\0';

    // Print sentence and word count
    printf("Sentence   : \"%s\"\n", str);
    printf("Word Count : %d\n", countwords(str));

    return 0;
}