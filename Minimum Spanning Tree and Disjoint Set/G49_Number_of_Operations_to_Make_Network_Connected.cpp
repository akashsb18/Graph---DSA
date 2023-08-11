#include <bits/stdc++.h>
using namespace std;

class Disjoint_set
{

public:
    // Constructor
    vector<int> rank, parent, size;
    Disjoint_set(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_parent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        // Path Compression
        return parent[node] = find_parent(parent[node]);
    }

    void union_by_rank(int u, int v)
    {

        int ulp_u = find_parent(u);
        int ulp_v = find_parent(v);

        if (ulp_u == ulp_v)
        {
            return;
        }
        if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void union_by_size(int u, int v)
    {

        int ulp_u = find_parent(u);
        int ulp_v = find_parent(v);

        if (ulp_u == ulp_v)
        {
            return;
        }
        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

int main()
{

    vector<vector<int>> connections = {{0, 1}, {0, 2}, {3, 4}, {2, 3}};

    int n = 5;
    Disjoint_set ds(n);
    int V = connections.size(), E = connections[0].size();
    int c = 0;
    for (auto it : connections)
    {
        int u = it[0];
        int v = it[1];
        if (ds.find_parent(u) == ds.find_parent(v))
        {
            c++;
        }
        else
        {
            ds.union_by_size(u, v);
        }
    }
    int diff = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.parent[i] == i)
        {
            diff++;
        }
    }
    int ans = diff - 1;

    if (ans <= c)
    {
        return ans;
    }
    return -1;

    return 0;
}