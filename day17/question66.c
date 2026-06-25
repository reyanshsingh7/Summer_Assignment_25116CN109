#include <stdio.h>

int unionarr(int a[], int n, int b[], int m, int result[]) {
    int k = 0;

    // Copy all elements of a[] into result
    for (int i = 0; i < n; i++) {
            result[k++] = a[i];
    }

    //Add elements of b[] that are not in a[]
    for (int i = 0; i < m; i++) {
         int found = 0;
         for (int j = 0; j < n; j++){
              if (b[i] == a[j]) {
                found = 1;
                break;
              }
         }
          if (!found)
                  result[k++] = b[i];
    }

    return k;
}

int main() {
    int a[100], b[100], result[200];
    int n, m;

    //Input Array A
    printf("Enter size of array A: ");
    scanf("%d", &n);
    printf("Enter elements of A: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    //Input Array B
    printf("Enter size of array B: ");
    scanf("%d", &m);
    printf("Enter elements of B: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    //Compute union
    int size = unionarr(a, n, b, m, result);

    //Print result
    printf("Union: ");
    for (int i = 0; i < size; i++) {
         printf("%d ", result[i]);
    }
    printf("\nSize: %d\n", size);

    return 0;
}