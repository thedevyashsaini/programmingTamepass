def bubbleSort(arr):
    n = len(arr)

    for i in range(n):
        for j in range(0, n-i-1):
        
            if arr[j][0] > arr[j+1][0] :
                arr[j], arr[j+1] = arr[j+1], arr[j]

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

    # Storing the ASCII sum of each word as key and the index of the word as value
    myl = {}
    for i in range(len(stre)):
        sum = 0
        for j in stre[i]:
            sum += ord(j)
        myl[sum] = i
    
    # Sorting the dictionary
    myl = list(myl.items())
    bubbleSort(myl)
    myl = dict(myl)

    # Printing the words in the order of their ASCII sum
    for i in list(myl.values()):
        print(stre[i], end = " ")

    print()