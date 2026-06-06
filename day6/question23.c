#include <stdio.h>

int bits(int n) {  // Function to count the number of set bits in the binary representation of n
    int count = 0;

    while (n) {  // Loop until n becomes 0
        n = n & (n - 1);   // This operation removes the rightmost set bit from n
        count++;
    }

    return count;
}

int main() {
    int num;

    // Prompt the user for a number
    printf("Enter a number: ");
    scanf("%d", &num);

    
    // Print the number and the count of set bits
    printf("\n  Number   : %d\n", num);
    printf("             : %d\n", bits(num));

    return 0;
}