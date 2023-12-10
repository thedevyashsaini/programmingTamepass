from collections import Counter

x = int(input())
for _ in range(x):
    n = int(input())
    l = input().split(" ")
    man_after_each_swip = []

    def manin(i):
        man_in = 0
        c = Counter(l[0:i])
        for p in c.values():
            if p % 2 == 0:
                continue
            else: 
                man_in += 1
        return man_in
    for i in range(n):
        man_after_each_swip.append(manin(i+1))
    
    print(max(man_after_each_swip))