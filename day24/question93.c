#include <stdio.h>
#include <string.h>

// Returns 1 if str2 is a rotation of str1, 0 otherwise
int rotation(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Lengths must be equal for rotation
    if (len1 != len2)
        return 0;

    // Concatenate str1 with itself
    char doubled[2000];
    doubled[0] = '\0';
    strcat(doubled, str1);         // append str1
    strcat(doubled, str1);         // append str1 again

    // Check if str2 is a substring of doubled
    if (strstr(doubled, str2))     // strstr returns NULL if not found
        return 1;

    return 0;
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

    if (rotation(str1, str2))
        printf("Result : \"%s\" is a rotation of \"%s\"\n", str2, str1);
    else
        printf("Result : \"%s\" is not a rotation of \"%s\"\n", str2, str1);

    return 0;
}