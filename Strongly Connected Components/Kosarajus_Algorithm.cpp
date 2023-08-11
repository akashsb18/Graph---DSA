class Solution
{
public:
    void DFS(vector<vector<int>> &adj, vector<int> &vis, stack<int> &s, int node)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                DFS(adj, vis, s, it);
            }
        }
        s.push(node);
    }
    void DFS3(vector<vector<int>> &adjT, vector<int> &vis, int node)
    {
        vis[node] = 1;
        for (auto it : adjT[node])
        {
            if (vis[it] == 0)
            {
                DFS3(adjT, vis, it);
            }
        }
    }
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        vector<int> vis(V, 0);
        stack<int> s;

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                DFS(adj, vis, s, i);
            }
        }

        vector<vector<int>> adjT(V);

        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }

        int c = 0;
        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            if (vis[node] == 0)
            {
                c++;
                DFS3(adjT, vis, node);
            }
        }
        return c;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(vector<vector<int>> &adj, vector<int> &vis, stack<int> &s, int node)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                DFS(adj, vis, s, it);
            }
        }
        s.push(node);
    }
    void DFS3(vector<vector<int>> &adjT, vector<int> &vis, int node)
    {
        vis[node] = 1;
        for (auto it : adjT[node])
        {
            if (vis[it] == 0)
            {
                DFS3(adjT, vis, it);
            }
        }
    }
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        vector<int> vis(V, 0);
        stack<int> s;

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                DFS(adj, vis, s, i);
            }
        }
        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }

        int c = 0;
        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            if (vis[node] == 0)
            {
                c++;
                DFS3(adjT, vis, node);
            }
        }
        return c;
    }
};

int main()
{

    return 0;
}