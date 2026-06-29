#include <stdio.h>

int main() {
    int n;
    int A[10][10];
    int symmetric = 1;

    // Input matrix size
    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    // Input matrix
    printf("\nEnter elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    // Check if the matrix is symmetric
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != A[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if (symmetric == 0)
            break;
    }

    // Print matrix
    printf("\nMatrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // Display result
    if (symmetric)
        printf("\nThe matrix is symmetric.\n");
    else
        printf("\nThe matrix is not symmetric.\n");

    return 0;
}