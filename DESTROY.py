from collections import Counter
if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        k = int(input())
        a = dict(sorted(Counter(input().strip().split()).items(), key=lambda item: item[1], reverse=True))
        c = 0
        while k > 0:
            itr = iter(a)
            try: 
                key = next(itr)
            except StopIteration:
                break
            if len(a) > 1:
                nextKey = next(itr)
                a[key] -= 1
                a[nextKey] -= 1
                k -= 2
                c += 1
                if a[key] == 0:
                    del a[key]
                if a[nextKey] == 0:
                    del a[nextKey]
            else:
                k -= a[key]
                c += a[key]
        print(c)
