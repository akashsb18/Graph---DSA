#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid, int delRow[], int delCol[])
{
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < 4; i++)
    {
        int newRow = row + delRow[i];
        int newCol = col + delCol[i];
        if (newRow >= 0 and newRow < n and newCol >= 0 and newRow < m and vis[newRow][newCol] == 0 and grid[newRow][newCol] == 'o')
        {
            dfs(newRow, newCol, vis, grid, delRow, delCol);
        }
    }
}

int main()
{

    vector<vector<char>> mat = {{'x', 'o'},
                                {'o', 'x'}};
    int n = mat.size();
    int m = mat[0].size();
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, 1, 0, -1};
    vector<vector<int>> vis(n, vector<int>(m, 0));
    // traverse first row and last row
    for (int j = 0; j < m; j++)
    {
        // check for unvisited Os in the boundary rows
        // first row
        if (!vis[0][j] && mat[0][j] == 'O')
        {
            dfs(0, j, vis, mat, delrow, delcol);
        }

        // last row
        if (!vis[n - 1][j] && mat[n - 1][j] == 'O')
        {
            dfs(n - 1, j, vis, mat, delrow, delcol);
        }
    }

    for (int i = 0; i < n; i++)
    {
        // check for unvisited Os in the boundary columns
        // first column
        if (!vis[i][0] && mat[i][0] == 'O')
        {
            dfs(i, 0, vis, mat, delrow, delcol);
        }

        // last column
        if (!vis[i][m - 1] && mat[i][m - 1] == 'O')
        {
            dfs(i, m - 1, vis, mat, delrow, delcol);
        }
    }

    // if unvisited O then convert to X
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && mat[i][j] == 'O')
                mat[i][j] = 'X';
        }
    }
    return 0;
}