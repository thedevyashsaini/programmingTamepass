#include <stdio.h>

// Function to get max, min and av of array using pointer
void maxminavr(int *arr, int *max, int *min, int *av, int n) {
    // Set mac and min to first value initially
    *max = *min = *arr;

    // Iterate over the array
    for (int i = 0; i < n; i++) {
        // Set the new values fro max and min
        if (*(arr + i) > *max) {
            *max = *(arr + i);
        }
        if (*(arr + i) < *min) {
            *min = *(arr + i);
        }
        
        // Store the sum of array in average variable
        *av += *(arr + i);
    }

    // Divide the sum by number of terms
    *av /= n;

    // Exit the function
    return;
}

// C program to find max, min, average of an array using pointers 
int main() {
    int n;

    // printf("Enter a number: ");
    scanf("%d", &n);

    // Take input for array
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }

    // Call function to get max, min and average of array
    int max, min, av = 0;
    maxminavr(arr, &max, &min, &av, n);
    
    // Print the result
    printf("%d %d %d", max, min, av);
    
    // Exit the function
    return 0;
