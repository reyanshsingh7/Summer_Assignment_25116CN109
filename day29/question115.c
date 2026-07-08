#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 200

char str1[MAX], str2[MAX];

void inputString() {
    printf("Enter a string: ");
    scanf(" %[^\n]", str1);
    printf("String stored!\n");
}

void findLength() {
    printf("Length of string: %lu\n", strlen(str1));
}

void reverseString() {
    int len = strlen(str1);
    char reversed[MAX];

    for (int i = 0; i < len; i++) {
        reversed[i] = str1[len - 1 - i];
    }
    reversed[len] = '\0';

    printf("Reversed string: %s\n", reversed);
}

void toUpperCase() {
    char result[MAX];
    int i;
    for (i = 0; str1[i] != '\0'; i++) {
        result[i] = toupper(str1[i]);
    }
    result[i] = '\0';
    printf("Uppercase: %s\n", result);
}

void toLowerCase() {
    char result[MAX];
    int i;
    for (i = 0; str1[i] != '\0'; i++) {
        result[i] = tolower(str1[i]);
    }
    result[i] = '\0';
    printf("Lowercase: %s\n", result);
}

void checkPalindrome() {
    int len = strlen(str1);
    int isPalindrome = 1;

    for (int i = 0; i < len / 2; i++) {
        if (str1[i] != str1[len - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
}

void countVowelsConsonants() {
    int vowels = 0, consonants = 0;

    for (int i = 0; str1[i] != '\0'; i++) {
        char ch = tolower(str1[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        } else if (ch >= 'a' && ch <= 'z') {
            consonants++;
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
}

void concatenateStrings() {
    printf("Enter second string: ");
    scanf(" %[^\n]", str2);

    char result[MAX * 2];
    strcpy(result, str1);
    strcat(result, str2);

    printf("Concatenated string: %s\n", result);
}

void compareStrings() {
    printf("Enter second string: ");
    scanf(" %[^\n]", str2);

    int result = strcmp(str1, str2);

    if (result == 0) {
        printf("Strings are equal.\n");
    } else if (result < 0) {
        printf("First string is less than second string.\n");
    } else {
        printf("First string is greater than second string.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n--- String Operations Menu ---\n");
        printf("1. Enter/Update String\n");
        printf("2. Find Length\n");
        printf("3. Reverse String\n");
        printf("4. Convert to Uppercase\n");
        printf("5. Convert to Lowercase\n");
        printf("6. Check Palindrome\n");
        printf("7. Count Vowels and Consonants\n");
        printf("8. Concatenate with Another String\n");
        printf("9. Compare with Another String\n");
        printf("10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice >= 2 && choice <= 9 && strlen(str1) == 0) {
            printf("Please enter a string first (option 1).\n");
            continue;
        }

        switch (choice) {
            case 1: inputString(); break;
            case 2: findLength(); break;
            case 3: reverseString(); break;
            case 4: toUpperCase(); break;
            case 5: toLowerCase(); break;
            case 6: checkPalindrome(); break;
            case 7: countVowelsConsonants(); break;
            case 8: concatenateStrings(); break;
            case 9: compareStrings(); break;
            case 10: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 10);

    return 0;
}