#include <stdio.h>
#include <string.h>

// Compresses the string using run-length encoding
void compressString(const char *str, char *result) {
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        char ch    = str[i];  // current character
        int  count = 0;       // frequency of current character

        // Count consecutive occurrences of current character
        while (str[i] == ch) {
            count++;
            i++;
        }

        // Write character to result
        result[j++] = ch;

        // Write count only if greater than 1
        if (count > 1) {
            // Convert count to string and write to result
            if (count >= 10) {
                result[j++] = '0' + (count / 10);
                result[j++] = '0' + (count % 10);
            } else {
                result[j++] = '0' + count;
            }
        }
    }

    result[j] = '\0';
}

int main() {
    char str[1000];
    char result[2000];

    // Input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline added by fgets
    str[strcspn(str, "\n")] = '\0';

    // Compress string
    compressString(str, result);

    // Print original and compressed string
    printf("Original   : \"%s\"\n", str);
    printf("Compressed : \"%s\"\n", result);

    return 0;
}