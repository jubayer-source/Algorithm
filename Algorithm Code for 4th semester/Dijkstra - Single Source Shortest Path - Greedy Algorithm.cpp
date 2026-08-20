#include <iostream>
using namespace std;

const int INF = 9999;

int main()
{
    int n = 5;

    int graph[5][5] =
    {
        {0, 4, 1, INF, INF},
        {4, 0, 2, 2, INF},
        {1, 2, 0, 3, INF},
        {INF, 2, 3, 0, 2},
        {INF, INF, INF, 2, 0}
    };

    int dist[5];
    int visited[5] = {0};

    int source = 0;

    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
    }

    dist[source] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
            {
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] &&
                graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest Distance from " << source << ":\n";

    for (int i = 0; i < n; i++)
    {
        cout << source << " -> " << i
             << " = " << dist[i] << endl;
    }

    return 0;
}