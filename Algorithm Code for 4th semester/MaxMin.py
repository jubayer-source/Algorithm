def maxmin(a, i, j, minimum, maximum):

    if i == j:
        minimum = maximum = a[i]

    elif i == j - 1:

        if a[i] < a[j]:
            minimum = a[i]
            maximum = a[j]
        else:
            minimum = a[j]
            maximum = a[i]

    else:
        mid = (i + j) // 2

        min1, max1 = maxmin(a, i, mid, minimum, maximum)
        min2, max2 = maxmin(a, mid + 1, j, minimum, maximum)

        # Compare minimums
        if min1 < min2:
            minimum = min1
        else:
            minimum = min2

        # Compare maximums
        if max1 > max2:
            maximum = max1
        else:
            maximum = max2

    return minimum, maximum


# Driver code
a = [12, 45, 7, 89, 23, 1, 56]

minimum, maximum = maxmin(a, 0, len(a)-1, 0, 0)

print("Minimum =", minimum)
print("Maximum =", maximum)