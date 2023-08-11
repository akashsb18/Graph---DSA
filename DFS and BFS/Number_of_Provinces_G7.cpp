// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

// Example 1:

// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2

#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> adjList[], vector<int> &vis, int node)
{
    vis[node] = 1;
    for (auto it : adjList[node])
    {
        if (vis[it] == 0)
        {

            DFS(adjList, vis, it);
        }
    }
}

int main()
{

    vector<vector<int>> adjMat = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int v = adjMat.size();

    // Converting it into adjacency list

    vector<int> adjList[v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adjMat[i][j] == 1 and i != j)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    vector<int> vis(v, 0);
    int c = 0;
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
        {
            c++;
            DFS(adjList, vis, i);
        }
    }

    cout << c;

    return 0;
}