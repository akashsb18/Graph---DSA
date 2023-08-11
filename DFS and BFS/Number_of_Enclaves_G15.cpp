#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> mat, vector<vector<int>> &vis, int row, int col, int delRow[], int delCol[])
{
    vis[row][col] = 1;
    int n = mat.size(), m = mat[0].size();
    for (int i = 0; i < 4; i++)
    {
        int newRow = row + delRow[i];
        int newCol = col + delCol[i];
        if (newRow >= 0 and newRow < n and newCol >= 0 and newCol < m and mat[newRow][newCol] == 1 and vis[newRow][newCol] == 0)
        {
            vis[newRow][newCol] = 1;
            dfs(mat, vis, newRow, newCol, delRow, delCol);
        }
    }
}

int main()
{

    vector<vector<int>> mat = {{0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
                               {1, 1, 0, 0, 0, 1, 0, 1, 1, 1},
                               {0, 0, 0, 1, 1, 1, 0, 0, 0, 0}};
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    // int vis[n][m] = {0};
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, 1, 0, -1};

    for (int j = 0; j < m; j++)
    {

        if (!vis[0][j] && mat[0][j] == 1)
        {
            dfs(mat, vis, 0, j, delrow, delcol);
        }

        if (!vis[n - 1][j] && mat[n - 1][j] == 1)
        {
            dfs(mat, vis, n - 1, j, delrow, delcol);
        }
    }

    for (int i = 0; i < n; i++)
    {

        if (!vis[i][0] && mat[i][0] == 1)
        {
            dfs(mat, vis, i, 0, delrow, delcol);
        }

        if (!vis[i][m - 1] && mat[i][m - 1] == 1)
        {
            dfs(mat, vis, i, m - 1, delrow, delcol);
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
    int cv = 0, cg = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (vis[i][j] == 1)
    //         {
    //             cv++;
    //         }
    //         if (mat[i][j] == 1)
    //         {
    //             cg++;
    //         }
    //     }
    // }
    int cantMoves = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] && !vis[i][j])
            {
                cantMoves++;
            }
        }
    }
    // int ans = cg - cv;
    // cout << ans;

    cout << cantMoves;

    return 0;
}