n = int(input())
combos = list(map(int, input().split()))
front = input().split()
back = input().split()
tattus = {}

for i in range(len(front)):
    y = front[i]
    w = back[i]

    if y in tattus:
        if combos[i] not in tattus[y]:
            tattus[y].append(combos[i])
    else:
        tattus[y] = [combos[i]]

    if w in tattus:
        if combos[i] not in tattus[w]:
            tattus[w].append(combos[i])
    else:
        tattus[w] = [combos[i]]

c = int(input())

costumers = input().split()

ans = ""

for i in costumers:
    if len(tattus[i]) > 0:
        mininum = min(tattus[i])
        while True:
            if mininum in combos:
                ans += str(mininum) + " "
                tattus[i].remove(mininum)
                combos.remove(mininum)
                break
            else:
                tattus[i].remove(mininum)
            if len(tattus[i]) > 0:
                mininum = min(tattus[i])
            else:
                ans += "-1 "
                break
    else:
        ans += "-1 "

print(ans)