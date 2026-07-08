#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int seen[256] = {0}; // to avoid printing the same character twice

    // Input two strings
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    printf("Common characters: ");

    // For each character in str1, check if it exists in str2
    for (int i = 0; str1[i] != '\0'; i++) {
        char ch = str1[i];

        // Skip if already printed
        if (seen[(unsigned char)ch])
            continue;

        // Check if this character exists in str2
        if (strchr(str2, ch) != NULL) {
            printf("%c ", ch);
            seen[(unsigned char)ch] = 1;
        }
    }
    printf("\n");

    return 0;
}
