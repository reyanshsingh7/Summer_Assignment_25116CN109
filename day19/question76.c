#include <stdio.h>

int main() {
    int n;
    int A[10][10];
    int sum = 0;

    //Get Matrix size
    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    //Input Matrix 
    printf("\nEnter elements of Matrix :\n");
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            printf(" Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    //Find sum of diagonal
    for (int i = 0; i < n; i++) {
        sum += A[i][i];
        }

    //Print original matrix
    printf("\nMatrix :\n");
    for ( int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    
    //Print sum
    printf("\nSum of diagonal elements = %d\n", sum);
    
    return 0;
}