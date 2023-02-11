#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};

    int n = 4;
    int distanceThreshold = 4;
    vector<vector<int>> adjMat(n, vector<int>(n, 1e8));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adjMat[i][j] = 0;
            }
        }
    }

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adjMat[u][v] = wt;
        adjMat[v][u] = wt;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
            }
        }
    }
    int city = -1, currMin = 1e8, ctr = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMat[i][j] > 0 and adjMat[i][j] <= distanceThreshold)
            {
                ctr++;
            }
        }
        if (currMin >= ctr)
        {
            currMin = ctr;
            city = i;
        }
        ctr = 0;
    }

    cout << city;

    return 0;
}