int spanningTree(int V, vector<vector<int>> adj[])
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Weight and node
    pq.push({0, 0});
    int sum = 0;
    vector<int> vis(V, 0);

    while (!pq.empty())
    {
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int adjWt = it[1];
            if (vis[adjNode] == 0)
            {
                pq.push({adjWt, adjNode});
            }
        }
    }
    return sum;
}