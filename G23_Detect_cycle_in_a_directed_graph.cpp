#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> adj = {{1}, {2}, {3}, {3}};

    int V = adj.size();
    int indegree[V] = {0};

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {

        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    for (auto it : indegree)
    {
        if (it != 0)
        {
            return 1;
        }
    }
    return 0;
    return 0;
}