#include <stdio.h>
#include <string.h>

//Reverses the string in place using two pointers
void revstring(char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {

        //Swap characters at left and right
        char temp   = str[left];
        str[left]   = str[right];
        str[right]  = temp;

        left++;   //move left pointer forward
        right--;  //move right pointer backward
    }
}

int main() {
    char str[1000];

    //Input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    //Remove newline added by fgets
    str[strcspn(str, "\n")] = '\0';

    //Print original and reversed string
    printf("Original : \"%s\"\n", str);
    revstring(str);
    printf("Reversed : \"%s\"\n", str);

    return 0;
}