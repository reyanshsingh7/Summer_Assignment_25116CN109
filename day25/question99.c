#include <stdio.h>
#include <string.h>

int main() {
    int n;

    // Input number of names
    printf("Enter number of names: ");
    scanf("%d", &n);
    getchar(); // consume leftover newline from scanf

    char names[n][50];

    // Input names
    for (int i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0'; // remove newline
    }

    // Sort names alphabetically using bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // strcmp returns > 0 if names[j] comes after names[j+1] alphabetically
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap the names
                char temp[50];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    // Print sorted names
    printf("\nNames in alphabetical order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}