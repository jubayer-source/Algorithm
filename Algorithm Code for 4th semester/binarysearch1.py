def binarySearch(arr, left, right, target):
    if left > right:
        return -1
    
    mid = (left+right)//2

    if arr[mid] == target:
        return mid
    
    elif target < arr[mid]:
        return binarySearch(arr, left, mid-1, target)
    
    else:
        return binarySearch(arr, mid+1, right,target)
    
data = [2,4,5,6,7,8,9,10]
target = int(input("Enter the targer number: "))

result = binarySearch(data, 0, len(data)-1, target)

if result !=-1:
    print(f"Element found at index(result)")
else:
    print(f"Element Not found.")
