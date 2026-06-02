#include <stdio.h>

int productofdigits(int n) {  // Function to calculate the product of digits of a number
    int product = 1;
    
    // Handle negative numbers by taking the absolute value
    if (n < 0) 
    n = -n;

    // Special case for 0, which has a product of digits equal to 0
    if (n == 0)
    return 0;

    // Calculate the product of digits
    while (n > 0) {
        product *= n % 10;
        n /= 10;
    }
    return product;
}

int main() {
    int num;

    // Prompt the user for input
    printf("Enter a number: ");
    scanf("%d", &num);

    // Print the result
    printf("Product of digits of %d = %d\n", num, productofdigits(num));
    return 0;
}