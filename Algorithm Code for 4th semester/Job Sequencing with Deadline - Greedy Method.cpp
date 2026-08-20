#include <iostream>
using namespace std;

int main()
{
    int n = 6;

    char job[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int deadline[] = {2, 1, 2, 1, 3, 3};
    int profit[] = {100, 19, 27, 25, 15, 30};

    // Sort jobs according to decreasing profit
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (profit[i] < profit[j])
            {
                swap(profit[i], profit[j]);
                swap(deadline[i], deadline[j]);
                swap(job[i], job[j]);
            }
        }
    }

    // Maximum deadline = 3
    char slot[3] = {'-', '-', '-'};

    int totalProfit = 0;

    // Greedy job selection
    for (int i = 0; i < n; i++)
    {
        for (int j = deadline[i] - 1; j >= 0; j--)
        {
            if (slot[j] == '-')
            {
                slot[j] = job[i];
                totalProfit += profit[i];
                break;
            }
        }
    }

    cout << "Job Sequence: ";

    for (int i = 0; i < 3; i++)
    {
        cout << slot[i] << " ";
    }

    cout << "\nMaximum Profit = " << totalProfit;

    return 0;
}