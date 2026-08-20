#include <iostream>
using namespace std;

void MaxMin(int a[], int low, int high, int &max, int &min)
{
    // One element
    if (low == high)
    {
        max = min = a[low];
        return;
    }

    // Two elements
    if (low + 1 == high)
    {
        if (a[low] > a[high])
        {
            max = a[low];
            min = a[high];
        }
        else
        {
            max = a[high];
            min = a[low];
        }
        return;
    }

    // Divide
    int mid = (low + high) / 2;

    int max1, min1;
    int max2, min2;

    // Conquer
    MaxMin(a, low, mid, max1, min1);
    MaxMin(a, mid + 1, high, max2, min2);

    // Combine
    if (max1 > max2)
        max = max1;
    else
        max = max2;

    if (min1 < min2)
        min = min1;
    else
        min = min2;
}

int main()
{
    int a[] = {23, 11, 45, 7, 89, 34, 2, 67, 19, 56};
    int n = 10;

    int max, min;

    MaxMin(a, 0, n - 1, max, min);

    cout << "Maximum = " << max << endl;
    cout << "Minimum = " << min << endl;

    return 0;
}