#include <stdio.h>

//Returns the length of the string without using strlen()
int strlength(const char *str) {
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

int main() {
    char str[1000];

    //Input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    //Remove newline added by fgets
    str[strcspn(str, "\n")] = '\0';

    //Print string and its length
    printf("String :\"%s\"\n", str);
    printf("Length :%d\n", strlength(str));

    return 0;
}