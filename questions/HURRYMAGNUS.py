if __name__ == "__main__":
    for _ in range(int(input().strip())):
        x = input().strip().split(" ")
        n = int(x[0])
        t = int(x[1])
        c = 0
        count = 0
        vids = [int(y) for y in input().strip().split(" ")]
        for i in range(n):
            if c + vids[i] <= t:
                c += vids[i] + 1
                count += 1
            else: 
                break
        print(count)