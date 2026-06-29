#include <stdio.h>

int main() {
    int rows, cols;
    int A[10][10], B[10][10], result[10][10];

    //Get Matrix size
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    //Input Matrix A
    printf("\nEnter elements of Matrix A:\n");
    for (int i = 0; i < rows; i ++) {
        for (int j = 0; j < cols; j++) {
            printf(" Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    //Input Matrix B
    printf("\nEnter elements of Matrix B:\n");
    for (int i = 0; i < rows; i ++) {
        for (int j = 0; j < cols; j++) {
            printf(" Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }

    //Add Matrices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    //Print Matrix A
    printf("\nMatrix A:\n");
    for ( int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    //Print Matrix B
    printf("\nMatrix B:\n");
    for ( int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    
    //Print Result
    printf("\nMatrix (A + B):\n");
    for ( int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}