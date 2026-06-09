#include <stdio.h>

int main() {
    int n;

    // Prompt the user for input
    printf("Enter number of rows: ");
    scanf("%d", &n);

    // Loop to print pattern
    for (int i = 1; i <= n; i++) {  
        for (int j = 1; j <= i; j++) {  
            printf("%c ",('A' + i - 1)); 
        }
        printf("\n");
    }
    return 0;
}