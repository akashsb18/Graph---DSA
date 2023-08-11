#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> adj = {{1, 4}, {2}, {3}, {}, {5}, {3}};
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
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            ans.push_back(i);
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
                ans.push_back(it);
                q.push(it);
            }
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}