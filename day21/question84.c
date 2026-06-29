#include <stdio.h>
#include <ctype.h>

//Converts all lowercase letters in the string to uppercase
void uppercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = toupper(str[i]);
}

int main() {
    char str[1000];

    //Input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    //Remove newline added by fgets
    str[strcspn(str, "\n")] = '\0';

    //Print original string
    printf("Original :\"%s\"\n", str);

    uppercase(str);

    //Print result
    printf("Uppercase :\"%s\"\n", str);

    return 0;
}