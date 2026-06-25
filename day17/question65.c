#include <stdio.h>

//Function to merge two arrays into result[]
void mergearrays(int a[], int n, int b[], int m, int result[]) {
    int k = 0;

    //Copy all elements of a[]
    for (int i = 0; i < n; i++){
        result[k++] = a[i];
    }

    //Append all elements of b[]
    for (int j = 0; j < m; j++) {
        result[k++] = b[j];
    }
}

//Function to print an array
void array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, m;

    //Input size and elements of Array A
    printf("Enter size of Array A: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    //Input size and elements of Array B
    printf("Enter size of Array B: ");
    scanf("%d", &m);

    int b[m];

    printf("Enter %d elements: ", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    //Declare result array of combined size
    int result[n + m];

    //Merge both arrays
    mergearrays(a, n, b, m, result);

    //Display all arrays
    printf("Array A: ");
    array(a, n);
    printf("Array B: ");
    array(b, m);
    printf("Merged: ");
    array(result, n + m);

    return 0;
}
