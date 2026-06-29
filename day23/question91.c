#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Returns 1 if two strings are anagrams, 0 otherwise
int isAnagram(const char *str1, const char *str2) {
    int freq[26] = {0};  // array to store frequency of a-z

    // Increment frequency for str1
    for (int i = 0; str1[i] != '\0'; i++)
        if (isalpha(str1[i]))                 // skip non-alphabetic characters
            freq[tolower(str1[i]) - 'a']++;

    // Decrement frequency for str2
    for (int i = 0; str2[i] != '\0'; i++)
        if (isalpha(str2[i]))                 // skip non-alphabetic characters
            freq[tolower(str2[i]) - 'a']--;

    // Check if all frequencies are 0
    for (int i = 0; i < 26; i++)
        if (freq[i] != 0)
            return 0;

    return 1;
}

int main() {
    char str1[1000];
    char str2[1000];

    // Input
    printf("Enter first string  : ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string : ");
    fgets(str2, sizeof(str2), stdin);

    // Remove newline added by fgets
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Print strings and result
    printf("First String  : \"%s\"\n", str1);
    printf("Second String : \"%s\"\n", str2);

    if (isAnagram(str1, str2))
        printf("Result : \"%s\" and \"%s\" are Anagrams\n", str1, str2);
    else
        printf("Result : \"%s\" and \"%s\" are not Anagrams\n", str1, str2);

    return 0;
}