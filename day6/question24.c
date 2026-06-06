#include <stdio.h>

double power(double x, int n) {  // Function to calculate x raised to the power of n
    double result = 1.0;
    int absolute = n < 0 ? -n : n;

    for (int i = 0; i < absolute; i++) {  // Loop to multiply x by itself absolute times
        result *= x; 
    }
    return n < 0 ? 1 / result : result;   // If n is negative, return the reciprocal of the result

}

int main() {
    double x;
    int n;

    // Prompt the user for base and exponent
    printf("Enter base: ");
    scanf("%lf", &x);
    printf("Enter exponent: ");
    scanf("%d", &n);

    // Calculate and print the result
    printf("%.2f ^ %d = %.2f\n", x, n, power(x, n));
    return 0;
}