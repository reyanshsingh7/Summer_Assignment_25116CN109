#include <stdio.h>

int main() {
    int rows;

    // Prompt the user for input
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    // Loop to print the pattern
    for (int i = 1; i <= rows; i++) {  
        for (int j = 1; j <= i; j++) {  
            printf("%d ", j); 
        }
        printf("\n");
    }
    return 0;
}