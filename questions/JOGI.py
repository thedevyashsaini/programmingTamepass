for _ in range(int(input().strip())):
    n, k = [int(x) for x in input().strip().split()]
    ani = [int(x) for x in input().strip().split()]
    bhupi = [int(x) for x in input().strip().split()]
    win = 0
    wins = []
    for i in range(n):
        if bhupi[2*i] > ani[i] or bhupi[(2*i)+1] > ani[i]:
            win += 1
            wins += [(ani[i], bhupi[2*i], bhupi[2*i+1])]

    if win < k:
        print("NO")
        continue
    elif win == k:
        print("YES")
        continue
    elif win > k:
        for i in wins:
            if i[2] < i[0] or i[1] < i[0]:
                win -= 1
                if win == k:
                    print("YES")
                    break
        if win > k:
            print("NO")
            continue