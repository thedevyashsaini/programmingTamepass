for _ in range(int(input().strip())):
    s = input().strip()
    i = 0
    l = len(s)
    while i < l:
        if i + 2 < l:
            t = s[i:i+3]
            s = s[:i] + t[::-1] + s[i+3:]
        else:
            t = s[i:]
            s = s[:i] + t[::-1]
        i += 3
    for i in range(l):
        s = s[:i] + chr(25 - (ord(s[i]) - 97) + 97) + s[i+1:]
    count = 0
    for i in range(l-1):
        for j in range(i+1,l):
            if ord(s[i]) > ord(s[j]):
                count += 1
    print(count)