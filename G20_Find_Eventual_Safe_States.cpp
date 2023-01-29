#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &graph, vector<int> &vis, vector<int> &pvis, int node)
{
    vis[node] = 1;
    pvis[node] = 1;
    for (auto it : graph[node])
    {
        if (vis[it] == 0)
        {
            if (dfs(graph, vis, pvis, it) == true)
            {
                return true;
            }
        }
        if (pvis[it] != 0)
        {
            return true;
        }
    }
    pvis[node] = 0;
    return false;
}

int main()
{

    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    int v = graph.size();

    vector<int> vis(v, 0);

    vector<int> pathvis(v, 0);

    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
        {
            dfs(graph, vis, pathvis, i);
        }
    }

    vector<int> ans;

    for (int i = 0; i < v; i++)
    {
        if (pathvis[i] == 0)
        {
            ans.push_back(i);
        }
    }

    return 0;
}
