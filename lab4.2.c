#include <stdio.h>

// Function to print diamond
void printDIamond() {
    // Declare required variables
    int n;

    // Ask for diamond height
    printf("\nEnter height of diamond: ");
    scanf("%d", &n);
    printf("\n\n");

    // Make the height odd
    n = ((n / 2) * 2) + 1;

    // Print the diamond
    for (int i = 1; i <= n/2 + 1; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == n/2 + i || j == n/2 + 2 - i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = n/2 + 2; i <= n; i++) {
        int k = n - i + 1;
        for (int j = 1; j <= n; j++) {
            if (j == n/2 + k || j == n/2 + 2 - k) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n\n");

    // Exit function
    return;
}

// Function to print triangle
void printTriangle() {
    // Declare required variables
    int n;

    // Ask for triangle height
    printf("\nEnter height of triangle: ");
    scanf("%d", &n);
    printf("\n\n");

    // Print the triangle
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(i != n){    
                if(j == 1 || j == i) {
                    printf("*");
                } else {
                    printf(" ");
                }
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    printf("\n\n");

    // Exit function
    return;
}

// C program to print star pattern of hollow diamond, hollow right triangle
int main() {
    // Declare required variables
    char option;

    // Ask for pattern choice
    printf("\nWhich pattern do you want? (d/t): ");
    scanf("%c", &option);

    // Call respective functions
    if (option == 'd') {
        printDIamond();
    } else if (option == 't') {
        printTriangle();
    } else {
        printf("\nInvalid option!\n\n");
    }

    // Exit function
    return 0;
}