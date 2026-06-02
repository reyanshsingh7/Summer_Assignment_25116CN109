#include <stdio.h>

int reversenumber(int n) {  // Function to reverse the digits of a number
    int rev = 0;

    // Handle negative numbers by taking the absolute value
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

int palindrome(int n) {   // Function to check if a number is a palindrome
    if (n < 0)
    return 0;
    return n == reversenumber(n);   // A number is a palindrome if it is equal to its reverse
}

int main(){
    int num;

    // Prompt the user for input
    printf("Enter a number: ");
    scanf("%d", &num);

    // Print the result
    if (palindrome(num))
        printf("%d is a Palindrome\n", num);
    else
        printf("%d is not a Palindrome\n", num);
    return 0;
}