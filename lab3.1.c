#include <stdio.h> 

// C program to left shift and right shift a number by 2
int main() {
    // Declare required variables
    int num, l, r;

    // Take input from user
    printf("\nEnter you number: ");
    scanf("%d", &num);

    // Left shift
    l = num << 2;
    // Right shift
    r = num >> 2;

    // Display output
    printf("\nLeft shifted: %d\nRight shifted: %d\n\n", l, r);

    // Exit function
    return 0;
}