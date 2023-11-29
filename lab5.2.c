#include <stdio.h>

// Recursive function to print n terms of fibonacci series
void fIbonacci(int x, int y, int c, int n) {
    if (c <= n) {
        if (c == 1) {
            printf("%d  ", 0);
            fIbonacci(x, y, ++c, n);
        } else if (c == 2) {
            y = 1;
            printf("%d  ", 1);
            fIbonacci(x, y, ++c, n);
        } else {
            int temp;
            temp = y;
            y = x + temp;
            x = temp;
            printf("%d  ", y);
            fIbonacci(x, y, ++c, n);
        }
    } else {
        return;
    }
}

// C progrm to print fibonacci series using revursion
int main() {
    // Declare required variables
    int n;

    // Take input from user
    printf("\nEnter number of terms to be printed: ");
    scanf("%d", &n);
    
    printf("\nFIbonacci Series:   ");
    fIbonacci(0, 0, 1, n);
    printf("\n\n");

    // Exit function
    return 0;   
}