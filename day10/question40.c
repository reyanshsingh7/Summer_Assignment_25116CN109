#include <stdio.h>

int main() {
    int n, i, j;

    // Prompt the user for input
    printf("Enter number of rows: ");
    scanf("%d", &n);

    //Loop to print pattern
    for (i = 1; i <= n; i++) {

        for (j = 1; j <= n - i; j++){
            printf(" ");
        }
        for (j = 0; j < i; j++) {
            printf("%c", 'A' + j);
        }
        for(j = i - 2; j >= 0; j--) {
            printf("%c", 'A' + j);
        }   
        printf("\n");
    }
    return 0;
}
