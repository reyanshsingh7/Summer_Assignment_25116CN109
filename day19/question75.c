#include <stdio.h>

int main() {
    int rows, cols;
    int A[10][10], transpose[10][10];

    //Get Matrix size
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    //Input Matrix 
    printf("\nEnter elements of Matrix :\n");
    for (int i = 0; i < rows; i ++) {
        for (int j = 0; j < cols; j++) {
            printf(" Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    //Find transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = A[i][j];
        }
    }

    //Print original matrix
    printf("\nOriginal Matrix :\n");
    for ( int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    
    //Print Transpose matrix
    printf("\nTranspose Matrix:\n");
    for ( int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}