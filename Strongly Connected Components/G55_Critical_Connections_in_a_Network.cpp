#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(vector<int> adj[], int tin[], int low[], vector<int> vis, int node, vector<vector<int>> bridges, int parent)
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (vis[it] == 0)
        {
            dfs(adj, tin, low, vis, it, bridges, node);
            low[node] = min(low[node], low[it]);
            if (low[it] > tin[node])
            {
                bridges.push_back({node, it});
            }
        }
        else
        {
            low[node] = min(low[node], low[it]);
        }
    }
}

int main()
{

    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};

    int n = 4;

    vector<int> adj[n];
    for (auto it : connections)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n, 0);

    int tin[n];
    int low[n];

    vector<vector<int>> bridges;

    dfs(adj, tin, low, vis, 0, bridges, -1);

    return bridges;

    return 0;
}
