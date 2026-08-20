#include <iostream>
using namespace std;

int main()
{
    int n = 6;

    int weight[] = {10, 20, 30, 40, 50, 60};
    int profit[] = {60, 100, 120, 160, 150, 180};

    int capacity = 100;
    float ratio[6];

    // Calculate profit/weight ratio
    for (int i = 0; i < n; i++)
    {
        ratio[i] = (float)profit[i] / weight[i];
    }

    // Sort according to ratio
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                swap(ratio[i], ratio[j]);
                swap(weight[i], weight[j]);
                swap(profit[i], profit[j]);
            }
        }
    }

    float totalProfit = 0;

    // Select items
    for (int i = 0; i < n; i++)
    {
        if (weight[i] <= capacity)
        {
            capacity = capacity - weight[i];
            totalProfit = totalProfit + profit[i];
        }
        else
        {
            totalProfit = totalProfit + ratio[i] * capacity;
            break;
        }
    }

    cout << "Maximum Profit = " << totalProfit;

    return 0;
}