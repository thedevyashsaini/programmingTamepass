#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;
      
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}

int main() {
    int t;
    scanf("%d", &t);

    if (t > 0 && t < 100000) {
        int array[t];

        for (int i = 0; i < t; i++) {
            scanf("%d", &array[i]);
        }

        int ambiguous = 0;

        for (int i = 0; i < t; i++) {
            int p = binarySearch(array, i, 0, t - 1);
            if (array[p] == i) {
                ambiguous = 1;
                break;
            }
        }   

        if (ambiguous) {
            printf("ambiguous\n");
        } else {
            printf("not ambiguous\n");
        }
    } else {
        return 0;
    }

    return 0;
}