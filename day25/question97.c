#include <stdio.h>

int main() {
    int arr1[100], arr2[100], arr3[200];
    int n1, n2, i, j, k;

    // Input first array
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter %d sorted elements: ", n1);
    for (i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);

    // Input second array
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter %d sorted elements: ", n2);
    for (i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    // Merge the two sorted arrays
    i = 0; j = 0; k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    while (i < n1)
        arr3[k++] = arr1[i++];

    while (j < n2)
        arr3[k++] = arr2[j++];

    // Print merged array
    printf("Merged array: ");
    for (int x = 0; x < k; x++)
        printf("%d ", arr3[x]);

    return 0;
}