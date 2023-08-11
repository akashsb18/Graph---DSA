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

    vector<vector<int>> operators = {{1, 1}, {0, 1}, {3, 3}, {3, 4}};

    int n = 4, m = 5;
    Disjoint_set ds(n * m);
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    vector<int> ans;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    for (auto it : operators)
    {
        int row = it[0];
        int col = it[1];
        if (vis[row][col] == 1)
        {
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int adjRow = row + dr[i];
            int adjCol = col + dr[i];
            if (adjRow >= 0 and adjRow < n and adjCol >= 0 and adjCol < m and vis[adjRow][adjCol] == 1)
            {
                int nodeNo = m * row + col;
                int adjNodeNo = m * adjRow + adjCol;
                if (ds.find_parent(nodeNo) != ds.find_parent(adjNodeNo))
                {
                    cnt--;
                    ds.union_by_size(nodeNo, adjNodeNo);
                }
            }
        }
        ans.push_back(cnt);
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}