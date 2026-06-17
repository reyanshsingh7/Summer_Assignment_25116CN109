#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int i;
    int k;
    int temp;

    //Take number of elements as input from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    //Take array elements as input from user
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Take number of Rotations as input from user
    printf("Enter number of left rotation: ");
    scanf("%d", &k);

    k = k % n;    //Reduce k to avoid redundant rotations

    //Display original array
    printf("\nOriginal array: ");
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    //Rotate the array left by k positions
    for (int r = 0; r < k; r++) {
        temp = arr[0];
        for (i = 0; i < n - 1; i++) {
             arr[i] = arr[i + 1];
        }
        arr[n - 1] = temp;
    }

    //Display rotated array
    printf("\nRotated array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}