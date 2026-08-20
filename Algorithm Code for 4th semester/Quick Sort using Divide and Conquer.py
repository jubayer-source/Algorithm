# Quick Sort using Divide and Conquer

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1

            # Swap
            arr[i], arr[j] = arr[j], arr[i]

    # Place pivot in correct position
    arr[i + 1], arr[high] = arr[high], arr[i + 1]

    return i + 1


def quick_sort(arr, low, high):
    if low < high:

        # Divide
        pivot_index = partition(arr, low, high)

        # Conquer
        quick_sort(arr, low, pivot_index - 1)
        quick_sort(arr, pivot_index + 1, high)


# Data set
arr = [45, 12, 78, 34, 23, 89, 11, 56, 7, 67]

print("Before sorting:", arr)

quick_sort(arr, 0, len(arr) - 1)

print("After sorting:", arr)