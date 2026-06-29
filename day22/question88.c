#include <stdio.h>
#include <string.h>

// Removes all spaces from the string in place
void removeSpaces(char *str) {
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ') {   // copy only non-space characters
            str[j] = str[i];   // write non-space character
            j++;
        }
        i++;
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
    removeSpaces(str);
    printf("Result   : \"%s\"\n", str);

    return 0;
}