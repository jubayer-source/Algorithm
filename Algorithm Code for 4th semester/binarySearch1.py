def binarySearch(arr, left, right, target):
    if left == right:
        if target == arr[left]:
            return left
        else:
            return -1
    else:
        mid = (left+right)//2
        if target == arr[mid]:
            return mid
        elif target < arr[mid]:
            return binarySearch(arr, left, mid-1, target)
        else:
            return binarySearch(arr, mid+1, right, target)

data = [1,2,3,4,5,6,7,8,9,10]
target= int(input("Enter a number to search in array: "))

Result = binarySearch(data, 0, len(data)-1, target)

if target != -1:
    print(f"found the value at index: {Result}")
else:
    print("Target not found.")
