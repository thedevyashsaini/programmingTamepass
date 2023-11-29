def isPrime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True
    
def sumOfFactors(n):
    sum = 0
    d = 2

    while d <= n:
        if n % d == 0 and isPrime(d):
            sum += d
            n //= d
        else:
            d += 1

    return sum

def mean(a, b):
    return ((a + b) / 2)

for _ in range(int(input().strip())):
    n = int(input().strip())
    arr = input().strip().split()

    for i in range(n):
        arr[i] = sumOfFactors(int(arr[i]))

    arr = sorted(arr)

    if n % 2 == 0:
        a = n // 2
        b = a - 1
        diff = abs(arr[a] - arr[b])
        print(diff)
        continue
    else:
        mid = n // 2
        diff = abs(arr[mid] - mean(arr[mid+1], arr[mid-1]))
        for i in range(2,mid+1):
            d = abs(arr[mid] - mean(arr[mid+i], arr[mid-i]))
            if d == 0:
                diff = d
                break
            if d < diff:
                diff = d
        print(int(diff)) if diff.is_integer() else print(diff)
        continue