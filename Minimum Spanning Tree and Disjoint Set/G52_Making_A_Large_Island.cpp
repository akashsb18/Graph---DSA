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

    vector<vector<int>> grid = {{1, 0, 1}, {0, 0, 0}, {1, 1, 1}};

    int n = grid.size();
    Disjoint_set ds(n * n);

    // Connecting Components
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 0)
                continue;
            for (int i = 0; i < 4; i++)
            {
                int adjRow = row + dr[i];
                int adjCol = col + dc[i];
                if (adjRow >= 0 and adjRow < n and adjCol >= 0 and adjCol < n and grid[adjRow][adjCol] == 1)
                {
                    int nodeNo = row * n + col;
                    int adjNodeNo = adjRow * n + col;
                    ds.union_by_size(nodeNo, adjNodeNo);
                }
            }
        }
    }
    // step 2
    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (grid[i][j] == 1)
                continue;

            set<int> set;

            for (int idx = 0; idx < 4; idx++)
            {
                int adjRow = i + dr[idx];
                int adjCol = j + dc[idx];

                if (adjRow >= 0 and adjRow < n and adjCol >= 0 and adjCol < n and grid[adjRow][adjCol] == 1)
                {
                    set.insert(ds.find_parent(adjRow * n + adjCol));
                }
            }

            int totalsize = 0;

            for (auto it : set)
            {
                totalsize += ds.size[it];
            }
            mx = max(mx, totalsize + 1);
        }
    }
    mx = max(mx, ds.size[ds.find_parent(n * n - 1)]);

    cout << mx << endl;
    return 0;
}
