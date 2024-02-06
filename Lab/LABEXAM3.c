// Palin-Primes up to 10^5
#include <stdio.h>

int isPrime(int n) {
    if (n == 1)
        return 0;
    if (n <= 3)
        return 1;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int isPalindrome(int n) {
    int rev = 0;
    int c = n;
    while (n) {
        rev *= 10;
        rev += n % 10;
        n /= 10;
    }
    if (rev == c)
        return 1;
    else
        return 0;
}

int main() {
    int count = 0;
    printf("\n");
    for (int i = 1; i <= 100000; i++) {
        if (i % 10 == 0) {
            continue;
        }
        if (isPrime(i) && isPalindrome(i)) {
            count += 1;
            printf("%d\t", i);
        }
    }

    printf("\n\nTotal Number of Prime Palindromes: %d\n\n", count);
    return 0;
}


// 
// int main(){
// for(int i=0;i<10;i++)
// {
//     for(int j=0;j<10;j++)
//     {
//         print(j)
//         if(i>0 && j>0 && i%j==0)
//         return
//     }
// }}