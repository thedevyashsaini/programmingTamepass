from math import sqrt
def isPrime(n):
    f= 0
    if(n > 1):
        for i in range(2, int(sqrt(n)) + 1):
            if (n % i == 0):
                f = 1
                break
        if (f == 0):
            return 1
        else:
            return 0
    else:
        return 0