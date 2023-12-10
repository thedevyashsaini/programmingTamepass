for _ in range(int(input().strip())):
    n, k = [int(x) for x in input().strip().split()]
    sum = 0
    for i in input().strip().split():
        sum += int(i)
    print("YES") if sum >= k else print("NO")