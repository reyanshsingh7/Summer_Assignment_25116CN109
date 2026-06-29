#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Counts and prints the number of vowels and consonants in the string
void count(const char *str) {
    int vowels = 0, consonants = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);

        if (isalpha(ch)) {    //skip non-alphabetic characters
            if (strchr("aeiou", ch))   //check if char is a vowel
                vowels++;
            else
                consonants++;
        }
    }

    printf("Vowels : %d\n", vowels);
    printf("Consonants : %d\n", consonants);
}

int main() {
    char str[1000];

    //Input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    //Remove newline added by fgets
    str[strcspn(str, "\n")] = '\0';

     //Print original string and counts
    printf("String : \"%s\"\n", str);
    count(str);

    return 0;
}