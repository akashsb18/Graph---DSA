
// Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected)

#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> grid, vector<vector<int>> &vis, vector<pair<int, int>> &v, int row0, int col0)
{
    vis[row][col] = 1;
    int n = grid.size(), m = grid[0].size();
    v.push_back({row - row0, col - col0});
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int newRow = row + delrow[i];
        int newCol = col + delcol[i];
        if (newRow >= 0 and newRow < n and newCol >= 0 and newCol < m and vis[newRow][newCol] == 0 and grid[newRow][newCol] == 1)
        {
            dfs(newRow, newCol, grid, vis, v, row0, col0);
        }
    }
}

int main()
{

    vector<vector<int>> grid = {{1, 1, 0, 1, 1},
                                {1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1},
                                {1, 1, 0, 1, 1}};
    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 and grid[i][j] == 1)
            {
                vector<pair<int, int>> v;
                dfs(i, j, grid, vis, v, i, j);
                s.insert(v);
            }
        }
    }

    cout << s.size();

    return 0;
}