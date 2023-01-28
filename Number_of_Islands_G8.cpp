// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input: grid = {
//   {"1","1","1","1","0"},
//   {"1","1","0","1","0"},
//   {"1","1","0","0","0"},
//   {"0","0","0","0","0"}
// }
// Output: 1

// GFG Question Approach

#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> grid, vector<vector<int>> &vis, int row, int col)
{
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int delR = -1; delR <= 1; delR++)
        {
            for (int delC = -1; delC <= 1; delC++)
            {
                int nRow = r + delR;
                int nCol = c + delC;
                if (nRow >= 0 and nRow < n and nCol >= 0 and nCol < m and vis[nRow][nCol] == 0 and grid[nRow][nCol] == 1)
                {
                    vis[nRow][nCol] = 1;

                    q.push({nRow, nCol});
                }
            }
        }
    }
}

int main()
{

    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}};

    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int c = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (vis[row][col] == 0 and grid[row][col] == 1)
            {
                c++;
                BFS(grid, vis, row, col);
            }
        }
    }

    cout << c;

    return 0;
}
