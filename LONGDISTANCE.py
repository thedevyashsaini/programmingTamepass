for _ in range(int(input().strip())):
    n = int(input().strip())
    r = [int(x) for x in input().strip().split()]
    l, k = [int(x) - 1 for x in input().strip().split()]

    def isOdd(n):
        return False if n%2 == 0 else True
    def isEven(n):
        return True if n%2 == 0 else False

    count = 0

    for i in range(l,k+1):
        for j in range(l,k+1):
            if i != j:
                a = isOdd(r[i])
                b = isOdd(r[j])
                if a == b:
                    d = abs(j - i) - 1
                    if not isOdd(d):
                        count += 1
                else:
                    d = abs(j - i) - 1
                    if isOdd(d):
                        count += 1

    print(int(count/2))