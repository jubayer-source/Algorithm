def find_max_min(a, n, max_val, min_val):

    max_val = a[0]
    min_val = a[0]

    for i in range(n):

        if a[i] > max_val:
            max_val = a[i]

        if a[i] < min_val:
            min_val = a[i]

    print("Maximum =", max_val)
    print("Minimum =", min_val)


# Driver code
a = [10, 5, 80, 2, 45]
n = len(a)
max_val = 0
min_val = 0

find_max_min(a, n, max_val, min_val)