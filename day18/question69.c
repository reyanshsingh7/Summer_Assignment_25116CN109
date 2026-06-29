#include <stdio.h>

int main() {
    int arr[100];
    int n, i, j, temp;

    //Input
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Display original array
    printf("\nArray before sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    //Bubble sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    //Display sorted array
    printf("\nArray after sorting: ");
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}