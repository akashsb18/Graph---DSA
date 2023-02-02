#include <bits/stdc++.h>
using namespace std;

vector<int> toposort(int V, vector<int> adj[])
{
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
    return ans;
}

int main()
{

    string dict[] = {"caa", "aaa", "aab"};
    int n = 3, k = 3;
    vector<int> adj[k];

    for (int i = 0; i < n - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.length(), s2.length());
        for (int j = 0; j < len; j++)
        {
            if (s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }
    vector<int> topo = toposort(k, adj);

    string ans;
    for (auto it : topo)
    {
        ans.push_back(char(it + 'a'));
    }

    cout << ans;

    // adjacencylist(adj, k);

    return 0;
}