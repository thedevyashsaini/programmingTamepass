#include <stdio.h>

// Function to add numbers using pointers
void add(int *a, int *b, int *sum) {
    *sum = *a + *b;
    return;
}

// C program to add two numbers using pointer
int main() {
    // Declare required variables and take input from user
    int a, b, sum;
    scanf("%d %d", &a, &b);

    // Add the numbers and print sum
    add(&a, &b, &sum);
    printf("%d", sum);

    // Exit the function
    return 0;
}