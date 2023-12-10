from math import sqrt
for _ in range(int(input().strip())):
    n = int(input().strip())
    a = True

    if n > 0:
        m = sqrt(n)
        if m == int(m):
            print("Square")
            continue
        
        for i in range(2, n):
            if n/i > 1 and n%i == 0:
                print("Rectangle")
                a = False
                break

    if a:
        print("None")