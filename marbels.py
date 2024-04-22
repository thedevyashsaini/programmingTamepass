for _ in range(int(input())):
    n, x = map(int, input().split())
    costs = list(map(int, input().split()))
    costs = sorted(costs)

    count = 0

    while True:
        a = x
        if x >= costs[0]:
            for i in range(n):
                if a >= costs[i]:
                    a -= costs[i]
                    costs[i] += 1
                    count += 1
                else:
                    break
            for i in range(i+1, n):
                costs[i] -= 1
        else:
            break
    
    print(count)