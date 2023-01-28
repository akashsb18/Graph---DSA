// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Example 1:
// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

#include <bits/stdc++.h>
using namespace std;

void BFS()
{
}

int main()
{

    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    // {{x,y},z}
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
        }
    }
    int ct = 0;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        ct = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newR = r + delRow[i];
            int newC = c + delCol[i];
            if (newR >= 0 and newR < n and newC >= 0 and newC < m and vis[newR][newC] != 2 and grid[newR][newC] == 1)
            {
                q.push({{newR, newC}, ct + 1});
                vis[newR][newC] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] != 2 and grid[i][j] == 1)
            {
                return -1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }

    cout << ct;

    return 0;
}