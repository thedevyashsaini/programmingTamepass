st = input().strip().lower()
vovels = {
    "a": 0,
    "e": 0,
    "i": 0,
    "o": 0,
    "u": 0
}

for i in st:
    if i in vovels:
        vovels[i] += 1

for i, j in vovels.items():
    print(f"{i}: {j}")