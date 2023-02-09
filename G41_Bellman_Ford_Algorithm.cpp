#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> edges{{0, 1, 5}, {1, 0, 3}, {1, 2, -1}, {2, 0, 1}};

    int V = 3, S = 2;
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 and wt + dist[u] < dist[v])
            {
                dist[v] = wt + dist[u];
            }
        }
    }
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 and wt + dist[u] < dist[v])
            {
                return {-1};
            }
        }
    }
    for (auto it : dist)
    {
        cout << it << " ";
    }

    // return dist;

    return 0;
}