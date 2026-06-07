#include <stdio.h>

long long factorial(int n) {  // Use long long to handle large factorials for big N
    
    // Factorial is not defined for negative numbers
    if (n == 0 || n == 1)
    return 1;  // Base case: factorial of 0 or 1 is 1
    return n * factorial(n-1);
}

int main() {
    int n;

    // Prompt the user for input
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Check if the input is a positive integer
    if (n<0) {
        printf("Factorial is not defined for negative numbers. \n");
        return 1;
    }
    
    // Calculate and print the factorial
    printf("Factorial of %d = %lld\n", n, factorial(n));
    
    return 0;
}