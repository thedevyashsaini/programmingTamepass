arr = [1,2,3,4,5,6,7,8,9]
def search(arr, x, high, low):
    mid = low + (high - low) // 2
    if x == arr[mid]:
        return mid
    else:
        if x > arr[mid]:
            return search(arr, x, high, mid+1)
        else:
            return search(arr, x, mid-1, low)

print(search(arr, 8, len(arr)-1, 0))