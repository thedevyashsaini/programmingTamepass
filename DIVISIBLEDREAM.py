if __name__ == "__main__": 
    for _ in range(int(input())):
        x = input().split(" ")
        k = int(x[1])
        count = 0
        arr = [int(y) for y in input().strip().split(" ")]
        for i in arr:
            r = i % k
            if r != 0:
                count += (k-r)
        print(count)