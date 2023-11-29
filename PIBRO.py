if __name__ == "__main__":
    for _ in range(int(input())):
        n, k = [int(x) for x in input().strip().split()]
        day = input().strip()
        lens = []
        l = len(day)
        for i in range(l):
            nday = day
            c = 0
            ctf = True
            ctb = True
            for j in range(n-i):
                if j < k:
                    nday = nday[:i+j] + "1" + nday[i+j+1:]
                if nday[i+j] == "1" and ctf:
                    c += 1
                    ctf = True
                else:
                    ctf = False
                if j != 0 and i-j >= 0:
                    if nday[i-j] == "1" and ctb:
                        c += 1
                        ctb = True
                    else:
                        ctb = False
                if ctf or ctb:
                    continue
                else:
                    break
            lens += [c]
        print(max(lens))