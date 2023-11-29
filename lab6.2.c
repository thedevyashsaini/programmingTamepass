#include <stdio.h>

// Function to reverse the array
void reverse(int *arr, int n) {
    // Swap the corresponding values in the array
    for (int i = 0; i < (n+1)/2; i++) {
        int t = *(arr + i);
        *(arr + i) = *(arr + n-i-1);
        *(arr + n-i-1) = t;
    }

    // Exit the function
    return;
}

// C program to reverse an array using pointers
int main() {
    int n;

    // printf("Enter a number: ");
    scanf("%d", &n);
    
    // Take input for the array
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }

    // Call the function to ger the revrse of array
    reverse(arr, n);

    // Print the reversed array
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }

    // Exit the function
    return 0;
}