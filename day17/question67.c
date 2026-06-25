#include <stdio.h>

//Function to find intersection of two arrays
int intersection(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int count = 0;
    int i;
    int j;

    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {

                int duplicate = 0;
                for (int k = 0; k < count; k++) {
                    if (result[k] == arr1[i]) {
                        duplicate = 1;
                        break;
                    }
                }
                if (!duplicate) {
                    result[count++] = arr1[i];
                }
                break;
            }
        }
    }
    return count;
}

int main() {
    int arr1[100], arr2[100], result[100];
    int n1, n2, i, j;

    //Input for Array 1
    printf("Enter the number of elements in Array 1: ");
    scanf("%d", &n1);
    printf("Enter %d elements of Array 1: ", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    //Input for Array 2
    printf("Enter the number of elements in Array 2: ");
    scanf("%d", &n2);
    printf("Enter %d elements of Array 2: ", n2);
    for (j = 0; j < n2; j++) {
        scanf("%d", &arr2[j]);
    }

    // Display arrays
    printf("\nArray 1: ");
    for (i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\nArray 2: ");
    for (j = 0; j < n2; j++) {
        printf("%d ", arr2[j]);
    }

    //Find and display intersection
    int count = intersection(arr1, n1, arr2, n2, result);

    printf("\nIntersection: ");
    if (count == 0)
        printf("No common elements found.");
    else
        for (i = 0; i < count; i++){
            printf("%d ", result[i]);
        }
    printf("\nTotal common elements: %d\n", count);

    return 0;
}