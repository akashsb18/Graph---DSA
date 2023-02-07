#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    int n = 7;

    vector<pair<int, int>> adj[n];

    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, 1e9), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int adjWt = it.second;
            if (dis + adjWt < dist[adjNode])
            {
                dist[adjNode] = dis + adjWt;
                pq.push({dist[adjNode], adjNode});
                ways[adjNode] = ways[node];
            }
            else if (dis + adjWt == dist[adjNode])
            {
                ways[adjNode] = ways[node] + ways[adjNode];
            }
        }
    }

    // cout << ways[n - 1];
    for (auto it : ways)
    {
        cout << it << " ";
    }

    return 0;
}