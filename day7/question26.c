#include <stdio.h>

int fibonacci(int n) {  // Function to calculate the nth Fibonacci number
    if (n == 0) return 0;  // Base case: F(0) = 0
    if (n == 1) return 1;  // Base case: F(1) = 1
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive case: F(n) = F(n-1) + F(n-2)
}

int main() {
    int n;

    // Prompt the user for input
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Check if the input is a positive integer
    if (n < 0) {
        printf("Fibonacci is not defined for negative numbers.\n");
        return 1;
    }

    // Print the Fibonacci sequence up to F(n)
    printf("Fibonacci sequence up to fib(%d): ", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", fibonacci(i));  
    }
    return 0;
}
