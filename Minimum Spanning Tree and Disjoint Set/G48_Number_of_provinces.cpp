#include <bits/stdc++.h>
using namespace std;

class Disjoint_set
{
    vector<int> rank, parent, size;

public:
    // Constructor
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

    vector<vector<int>> graph = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    int n = graph.size();
    Disjoint_set ds(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                ds.union_by_size(i, j);
            }
        }
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.find_parent(i) == i)
        {
            c++;
        }
    }

    cout << c;

    return 0;
}
