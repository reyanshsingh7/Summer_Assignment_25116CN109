#include <stdio.h>

int gcd(int a, int b) {  // Function to calculate the GCD using the Euclidean algorithm

    // Handle negative numbers by taking the absolute value
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;

    // Prompt the user for input
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Calculate and print the value of LCM
    printf("LCM = %d\n", (a / gcd(a, b)) * b);
    return 0;
}