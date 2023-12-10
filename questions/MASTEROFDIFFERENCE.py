for _ in range(int(input().strip())):
    n = int(input().strip())
    m = int(input().strip())
    nums = [int(x) for x in input().strip().split()]
    nums = sorted(nums)
    x = n-1
    y = 0
    diff = 0
    while m > 0:
        d = nums[x] - nums[y]
        m -= 1
        diff = d
        a = nums[y+1] - nums[y]
        b = nums[x] - nums[x-1]
        if a <= b:
            x = x
            y = y + 1
        elif a > b:
            x = x - 1
            y = y
    print(diff)