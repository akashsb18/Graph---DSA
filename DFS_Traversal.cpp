#include <bits/stdc++.h>
using namespace std;

void DFS(int grid[][6], vector<int> adjList[], int vis[], int node, vector<int> &dfs)
{
    vis[node] = 1;
    dfs.push_back(node);
    for (auto it : adjList[node])
    {
        if (vis[it] == 0)
        {
            DFS(grid, adjList, vis, it, dfs);
        }
    }
}

int main()
{

    int grid[][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0, 0},
        {0, 1, 1, 0, 1, 1},
        {0, 1, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}};

    int n = 6;

    vector<int> adjList[n];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (grid[i][j] == 1 and i != j)
            {
                adjList[i].push_back(j);
            }
        }
    }

    int vis[n] = {0};

    vector<int> dfs;

    DFS(grid, adjList, vis, 1, dfs);

    for (auto it : dfs)
    {
        cout << it << " ";
    }

    return 0;
}