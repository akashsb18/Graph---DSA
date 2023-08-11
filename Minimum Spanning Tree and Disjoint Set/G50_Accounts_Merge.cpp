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

    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"John", "johnsmith@mail.com", "john00@mail.com"}, {"Mary", "mary@mail.com"}, {"John", "johnnybravo@mail.com"}};

    int n = accounts.size();
    unordered_map<string, int> mapMailnode;
    Disjoint_set ds(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            string mail = accounts[i][j];
            if (mapMailnode.find(mail) == mapMailnode.end())
            {
                mapMailnode[mail] = 1;
            }
            else
            {
                ds.union_by_size(i, mapMailnode[mail]);
            }
        }
    }

    vector<string> mergeMail[n];

    for (auto it : mapMailnode)
    {
        string mail = it.first;
        int node = ds.find_parent(it.second);
        mergeMail[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
        if (mergeMail[i].size() == 0)
        {
            continue;
        }
        vector<string> temp;
        sort(mergeMail[i].begin(), mergeMail[i].end());
        temp.push_back(accounts[i][0]);
        for (auto it : mergeMail[i])
        {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }

    return ans;

    return 0;
}
