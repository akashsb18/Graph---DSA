#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    // //Adjacency Matrix
    // int adj[n + 1][m + 1];
    // for (int i = 0; i < m; i++)
    // {
    //     int x, y;
    //     cin >> x;
    //     cin >> y;
    //     adj[x][y] = 1;
    //     adj[y][x] = 1;
    // }

    // for (auto it : adj)
    // {
    //     cout << it[0] << " " << it[1] << endl;
    // }

    // Adjacency List
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}