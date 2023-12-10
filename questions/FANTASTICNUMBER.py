def isPrime(n):
    if n == 1:
        return False

    for i in range(2, int((n**0.5)) + 1):
        if n % i == 0:
            return False
    
    return True

def isFantastic(n):
    new = bin(n)[2:]
    one = 0

    for i in str(new):
        if i == "1":
            one += 1

    if one % 2 != 0:
        return False
    
    r = n >> one

    if r < 4: 
        return False
    
    for i in range(3,int(r//2)+1):
        if r-i == 2:
            continue
        if isPrime(i) and isPrime(r-i):
            return True

    return False


for _ in range(int(input().strip())):
    n = int(input().strip())
    nums = [int(x) for x in input().strip().split()]
    f = []
    isf = False
    for i in nums:
        if isFantastic(i):
            f += [i]
            isf = True
    f = sorted(f)
    print(' '.join(map(str, f))) if isf else print(-1)