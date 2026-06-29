#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Returns 1 if the string is a palindrome, 0 otherwise
int palindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (tolower(str[left]) != tolower(str[right]))  // compare characters
            return 0;

        left++;   // move left pointer forward
        right--;  // move right pointer backward
    }

    return 1;
}

int main() {
    char str[1000];

    // Input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline added by fgets
    str[strcspn(str, "\n")] = '\0';

    // Check and print result
    printf("String : \"%s\"\n", str);
    if (palindrome(str))
        printf("Result : \"%s\" is a Palindrome\n", str);
    else
        printf("Result : \"%s\" is not a Palindrome\n", str);

    return 0;
}