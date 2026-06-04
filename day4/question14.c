#include <stdio.h>

long long fibonacci(int n) {  // Function to calculate the nth Fibonacci number

    // Handle negative input
    if (n == 0)
        return 0; 

    // Base case for n = 1
    else if (n == 1)
        return 1;
        
    // Iteratively calculate Fibonacci numbers for n > 1    
    else {
        long long a = 0, b = 1, fib;
        for (int i = 2; i <= n; i++) {
            fib = a + b; 
            a = b; 
            b = fib; 
        }
        return b; 
    }
}
int main() {
    int n;

    // Prompt the user for input
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Validate the input to ensure it's a non-negative integer
    if (n < 0) {
        printf("Error: n must be a non - negative integer.\n");
        return 1;
    }
    
    // Print the nth Fibonacci number
    printf("Fibonacci term at position %d is: %lld\n", n, fibonacci(n));
    return 0;
}