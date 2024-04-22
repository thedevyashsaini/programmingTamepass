import math

for _ in range(int(input())):
    n = int(input())
    points = []
    for _ in range(n):
        x, y = map(int, input().split())
        points.append((x, y))
    
    hy = -math.inf
    hx = -math.inf
    ans = -math.inf

    for i in points:
        if i[1] >= hy:
            hy = i[1]
            hx = i[0]

    change = 0

    for i in points:
        if i[y] > 0:
            change -= i[y]
            