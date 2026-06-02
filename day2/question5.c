#include <stdio.h>

int sumofdigits(int n) {  // Function to calculate the sum of digits of a number
    int sum = 0;

    // Handle negative numbers by taking the absolute value
    if (n < 0)
    n = -n;

    // Special case for 0, which has a sum of digits equal to 0
    while (n > 0) {
        sum += n % 10; 
        n /= 10;
    }
    return sum;
}

int main() {
    int num;

    // Prompt the user for input
    printf("Enter a number: ");
    scanf("%d", &num);

    // Print the result
    printf("Sum of digits of %d = %d\n", num, sumofdigits(num));
    return 0;
}