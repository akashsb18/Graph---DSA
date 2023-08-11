
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

    int grid[][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0, 0},
        {0, 1, 1, 0, 1, 1},
        {0, 1, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}};

    int n = 6;

    vector<int> adjList[n];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (grid[i][j] == 1 and i != j)
            {
                adjList[i].push_back(j);
            }
        }
    }

    adjacencylist(adjList, n);

    int vis[n] = {0};
    vector<int> bfs;

    queue<int> q;

    q.push(1);
    vis[1] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adjList[node])
        {
            if (vis[it] == 0)
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    for (auto it : bfs)
    {
        cout << it << " ";
    }

    return 0;
}
