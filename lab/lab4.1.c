#include <stdio.h>

// Define function to calculate factorial of a numbers
long fact(long a) {
    if (a <= 1) {
        return 1;
    } else {
        return a * fact(a-1);
    }
}

// Define function to calculate the terms using nCr
long term(long n, long r) {
    return fact(n) / (fact(r) * (fact(n-r)));
}

// C Program to prlong Pascal's triangle up to n rows
long main() {
    // Declare required variables
    long n;

    // Take input from uuser for number of rows
    printf("\nEnter number of rows: ");
    scanf("%ld", &n);
    printf("\n\n");

    long len = ((2 * n) - 1);

    // Run loop for n rows
    for (long i = 1; i <= n; i++) {
        long count = 0;
        long tp = 1;

        // Run loop for n columns
        for (long j = 1; j <= len; j++) {
            // Prlong space if it is not in the centre part
            if (j <= (len - ((2*i)-1)) / 2 || j > ((len - ((2*i)-1)) / 2) + ((2*i)-1)) {
                printf("     ");
            }
            else {
                // Else alternatively prlong term and spaces
                if(tp == 1) {
                    // Calculate terms using term function
                    printf("%05ld", term(i-1, count));
                    count++;
                    // printf("*");
                    tp = 0;
                } else {
                    printf("     ");
                    tp = 1;
                }
            }
        }
        // Goto nect line
        printf("\n\n");
    }

    printf("\n\n");

    // Exit function
    return 0;
}