#include <stdio.h>
#include <string.h>

//Function to check if a string is a palindrome
int palindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    //Compare characters from both ends
    while (left < right) {
        if (str[left] != str[right])
            return 0;
        left++;   //Move left pointer forward
        right--;   //Move right pointer backward
    }

    return 1;
}

int main() {
    char str[100];

    //Take string as input from user
    printf("Enter a string: ");
    scanf("%s", str);

    //Call palindrome function and display the result
    if (palindrome(str))
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);

    return 0;
}