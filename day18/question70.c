#include <stdio.h>

int main() {
    int arr[100];
    int n, i, j, temp, minindex;

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

    //Selection sort
    for (i = 0; i < n - 1; i++) {
        //Assume current position has the mininmum
        minindex = i;

        //Find the minimum element in the remaining array
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[minindex]) {
                minindex = j;
            }
        }
        
        //Swap minimum element with current position
        if (minindex != i) {
            temp = arr[i];
            arr[i] = arr[minindex];
            arr[minindex] = temp;
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