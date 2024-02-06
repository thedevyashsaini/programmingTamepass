#include <stdio.h>

// Declare function for factorial
int factorialOf(int);

// C program to get factorial of a number using recusive function
int main() {
    // Declare required variables
    int num, fact;

    // Take input from user
    printf("\nEnter your number: ");
    scanf("%d", &num);

    // Get factorial
    fact = factorialOf(num);

    // Display output
    printf("\nFactorial of %d is %d.\n\n", num, fact);

    // Exit function
    return 0;
}

// Define the function
int factorialOf(int num) {

    // return 1 at end
    if (num == 1) {
        return 1;
    }

    // Return n * n-1 up to 1
    return num * factorialOf(num-1);
 }