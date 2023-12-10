#include <stdio.h>

// C program to display fibonacci series up to 100
int main() {
    // Declare required variables
    int current = 0;
    int next = 1;
    int sum;
    printf("\nFibonacci series up to 100:\t");

    // Continuously print series untill 100
    while (current < 100) {
        printf("%d  ", current);
        sum = current + next;
        current = next;
        next = sum;
    }
    printf("\n\n");

    // Exit function
    return 0;
}