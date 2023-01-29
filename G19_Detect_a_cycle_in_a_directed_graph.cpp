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

    vector<vector<int>> v = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};
    int n = v.size();
    vector<int> adj[n];

        return 0;
}