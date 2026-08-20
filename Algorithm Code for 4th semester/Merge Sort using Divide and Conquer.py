# Merge Sort using Divide and Conquer

def merge(arr, left, mid, right):
    left_part = arr[left:mid + 1]
    right_part = arr[mid + 1:right + 1]

    i = 0
    j = 0
    k = left

    # Merge the two sorted parts
    while i < len(left_part) and j < len(right_part):

        if left_part[i] <= right_part[j]:
            arr[k] = left_part[i]
            i += 1
        else:
            arr[k] = right_part[j]
            j += 1

        k += 1

    # Copy remaining elements of left part
    while i < len(left_part):
        arr[k] = left_part[i]
        i += 1
        k += 1

    # Copy remaining elements of right part
    while j < len(right_part):
        arr[k] = right_part[j]
        j += 1
        k += 1


def merge_sort(arr, left, right):

    if left < right:

        # Divide
        mid = (left + right) // 2

        # Conquer
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)

        # Combine
        merge(arr, left, mid, right)


# Data set
arr = [38, 27, 43, 3, 9, 82, 10, 55, 21, 67]

print("Before sorting:", arr)

merge_sort(arr, 0, len(arr) - 1)

print("After sorting:", arr)