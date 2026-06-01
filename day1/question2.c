#include <stdio.h>

int main() {
    int n, rows; 


    // Prompt the user for input
    printf("Enter the number: ");
    scanf("%d", &n);

    // Prompt the user for the number of rows in the multiplication table
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Print the multiplication table header
    printf("\n Multiplication Table of %d \n\n", n);


    // Print the multiplication table using a loop
    for(int i =1; i <= rows; i++) {
        printf("%d x %d = %d\n", n, i, n*i);
    }

    return 0;
}