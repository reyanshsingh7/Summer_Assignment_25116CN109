#include <stdio.h>

int main() {
    int n;

    // Prompt the user for input
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("The factors of %d are: ", n);

    // Loop to find and print the factors of n
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}