#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> a = {{1, 2, 10}, {2, 0, 7}, {1, 3, 8}, {4, 0, 10}, {3, 4, 2}, {4, 2, 10}, {0, 3, 3}, {3, 1, 6}, {2, 4, 5}};

    int n = 5, src = 0, sink = 4, k = 1;

    vector<pair<int, int>> adj[n];

    for (auto it : a)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    queue<pair<int, pair<int, int>>> q;

    q.push({0, {src, 0}});

    while (!q.empty())
    {
        int stops = q.front().first;
        int node = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();
        if (stops > k)
        {
            continue;
        }
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int adjWeight = it.second;
            if (cost + adjWeight < dist[adjNode] and stops <= k)
            {
                dist[adjNode] = cost + adjWeight;
                q.push({stops + 1, {adjNode, dist[adjNode]}});
            }
        }
    }

    for (auto it : dist)
    {
        cout << it << " ";
    }

    return 0;
}