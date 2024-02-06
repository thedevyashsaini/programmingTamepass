#include <stdio.h>
#include <string.h>

// Recursive function to reverse the string
void reverseStr(char *num, char *rev, int c, int l) {
    if (c == l) {
        // Terminate the string and return 
        rev[c] = '\0';
        return;
    }
    // Place current values
    rev[l-c-1] = num[c];

    // COntinue reversing
    reverseStr(num, rev, ++c, l);
}

// C program to reverse a given integer string using recursion
int main() {
    // Declare required variables
    char num[100];
    char rev[100];

    // Take input from user
    printf("\nEnter your number: ");
    scanf("%s", num);

    // Get length of the string
    int l = strlen(num);

    // Reverse the number
    reverseStr(num, rev, 0, l);

    // Print the reversed number
    printf("%s -> %s\n\n",num, rev);

    // Exit the function
    return 0;
}