#include <stdio.h>

int main() {

    int n;
    
     // Prompt the user for input
    printf("Enter number of rows: ");
    scanf("%d", &n);
    
    //Loop to print pattern
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}