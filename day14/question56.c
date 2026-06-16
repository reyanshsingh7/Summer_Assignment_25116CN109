#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int i, j;
    int found;

    //Take number of elements as input from the user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    //Take array elements as input from the user
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    } 

    //Find and display duplicate elements
    printf("\nDuplicate elements: ");
    found = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] ==arr[j]) {
                printf("%d ", arr[i]);
                found = 1;
                break;
            }
        }
    }

    if (found == 0) {
        printf("No duplicate found");
    }

    printf("\n");
    
    return 0;
}