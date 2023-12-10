#include <stdio.h>

// Recursive function to reverse the number
int reverse(int n, int rev) {
    if (n == 0) return rev;
    rev = rev*10 + n%10;
    n /= 10;
    return reverse(n, rev);
}

// C Program to reverse a number using recursive function
int main() {
    // Declare required variables
    int num, rev;

    // Take input from user
    printf("\nEnter your number: ");
    scanf("%d", &num);

    // Call recursive function to reverse the number
    rev = reverse(num, 0);

    // Print output
    printf("%d -> %d\n\n", num, rev);

    // Exit function
    return 0;
}