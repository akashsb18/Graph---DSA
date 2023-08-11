#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    int n = 5, m = 6;
    vector<pair<int, int>> adj[n + 1];

    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});

    vector<int> dist(n + 1, 1e8);
    dist[1] = 0;

    vector<int> parent(n + 1);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    while (!pq.empty())
    {

        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int adjWt = it.second;
            if (wt + adjWt < dist[adjNode])
            {
                dist[adjNode] = wt + adjWt;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }
    if (dist[n] == 1e8)
    {
        return {-1};
    }
    vector<int> ans;

    int node = n;
    while (parent[node] != node)
    {
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());

    return 0;
}