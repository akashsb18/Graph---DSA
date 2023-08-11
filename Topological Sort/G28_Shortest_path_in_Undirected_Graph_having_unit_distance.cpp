#include <bits/stdc++.h>
using namespace std;

void adjacencylist(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << "->";
        for (int &x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{

    vector<vector<int>> edges = {{0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};
    int n = 9, m = 10, src = 0;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    // 0->1 3
    // 1->0 2
    // 2->1 6
    // 3->0 4
    // 4->3 5
    // 5->4 6
    // 6->5 2 7 8
    // 7->6 8
    // 8->7 6
    queue<pair<int, int>> q;
    q.push({src, 0});

    while (!q.empty())
    {
        int node = q.front().first;
        q.pop();
        for (auto it : adj[node])
        {
            int x = dist[node] + 1;
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = 1 + dist[node];
                q.push({it, x});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
        {
            dist[i] = -1;
        }
    }
    for (auto it : dist)
    {
        cout << it << " ";
    }

    return 0;
}