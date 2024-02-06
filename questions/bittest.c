#include <stdio.h>
#include <math.h>

int main() {
    int a = (int) pow(2,29);
    int b = (int) pow(2,31);
    printf("%d\n", b-3 << 1);

    return 0;
}