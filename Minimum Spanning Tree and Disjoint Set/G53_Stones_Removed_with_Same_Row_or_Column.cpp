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

    vector<vector<int>> stones = {{0, 0}, {1, 2}, {2, 0}, {2, 3}, {3, 0}, {3, 1}};

    int n = stones.size(), m = 2;
    int maxRow = 0, maxCol = 0;

    for (auto it : stones)
    {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    Disjoint_set ds(maxRow + maxCol + 1);
    unordered_map<int, int> stoneNodes;
    for (auto it : stones)
    {
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;
        ds.union_by_size(nodeRow, nodeCol);
        stoneNodes[nodeRow] = 1;
        stoneNodes[nodeCol] = 1;
    }
    int ans = 0;
    for (auto it : stoneNodes)
    {
        if (ds.find_parent(it.first) == it.first)
        {
            ans++;
        }
    }

    cout << n - ans;
    return 0;
}