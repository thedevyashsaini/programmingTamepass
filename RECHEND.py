# cook your dish here
if __name__ == "__main__":
    for _ in range(int(input().strip())):
        n = int(input().strip())
        blocks = []
    
        for i in range(n):
            x = input().strip().split(" ")
            blocks += [(int(x[0])-1, int(x[1])-1)]
            
        blocks = sorted(blocks)
        flag = False

        i = 0
        while i < n:
            if blocks[i][1] == 0:
                flag = True
                i += 1
                break
            if i+1 < n:
                if blocks[i][1] - blocks[i+1][1] != 1:
                    i += 1
                    break
            i += 1
        
        if flag == False:
            j = n-1
            while j >= i:
                if blocks[j][1] == n-1:
                    flag = True
                    j -= 1
                    break
                if blocks[j][1] - blocks[j-1][1] != 1:
                    j -= 1
                    break
                j -= 1
            
        print("NO") if flag else print("YES")
