#include <bits/stdc++.h>
using namespace std;

void dfs(vector<pair<int, int>> adj[], int node, vector<bool> vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        int v = it.first;
        if (vis[v] == 0)
        {
            dfs(adj, v, vis, st);
        }
    }
    st.push(node);
}

int main()
{

    vector<vector<int>> edges = {{0, 1, 2}, {2, 1, 2}, {2, 4, 2}, {1, 4, 8}, {1, 3, 6}};

    int n = 5, m = 5;

    vector<pair<int, int>> adj[n];

    for (int i = 0; i < m; i++)

    {

        int u = edges[i][0];

        int v = edges[i][1];

        int wt = edges[i][2];

        adj[u].push_back({v, wt});
    }

    stack<int> st;

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)

    {

        if (visited[i] == false)

        {

            dfs(adj, i, visited, st);
        }
    }

    vector<int> dis(n, 1e9);

    dis[0] = 0;

    while (!st.empty())

    {

        int node = st.top();

        st.pop();

        for (auto x : adj[node])

        {

            int v = x.first;

            int d = x.second;

            if (dis[v] > dis[node] + d)

            {

                dis[v] = dis[node] + d;
            }
        }
    }

    for (int i = 0; i < n; i++)

    {
        if (dis[i] == 1e9)
        {
            dis[i] = -1;
        }
    }

    for (auto it : dis)
    {
        cout << it << " ";
    }

    return 0;
}