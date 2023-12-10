if __name__ == "__main__":
    stree = input()
    stre = [""]
    c = 0

    # Splitting the string into words
    for i in stree:
        if i == " ":
            c += 1
            stre += [""]
            continue
        stre[c] += i
    
    # Reversing each word
    for i in range(len(stre)):
        l = len(stre[i])
        w = ""
        for j in range(l-1, -1, -1):
            w += stre[i][j]
        stre[i] = w
        print(w, end = " ")

    print()