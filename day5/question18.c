#include <stdio.h>

int factorial(int n) {  // Function to calculate the factorial of a number
    int fact = 1;

    // Loop to calculate factorial
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int strong(int n) {  // Function to check if a number is a Strong Number
    int temp = n, sum = 0;

    // Loop to calculate the sum of the factorial of digits
    while (temp > 0) {
        sum += factorial(temp % 10);
        temp /= 10;
    }
    return sum == n;
}

int main() {
    int n;

    // Prompt the user for input
    printf("Enter a number: ");
    scanf("%d", &n);

    // Check if the number is a Strong Number and print the result
    if (strong(n))
        printf("%d is a Strong Number\n", n);
    else      
        printf("%d is not a Strong Number\n", n);
    
    return 0;
}