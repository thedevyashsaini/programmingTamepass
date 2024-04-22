for _ in range(int(input())):
    n = int(input())
    scores = list(map(int, input().split()))
    scores = sorted(scores, reverse=True)
    a = scores[0] + 1;
    first = False
    second = False
    for score in scores:
        if score < a:
            if not first:
                a = score
                first = True
                continue
            if not second:
                a = score
                second = True
                break

    print(a) if second else print(-1)
                