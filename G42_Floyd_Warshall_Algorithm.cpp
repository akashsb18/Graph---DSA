// In this , we were doing in place as given in question, or else we can do it in a different visited array
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> matrix = {{0, 1, 43},
                                  {1, 0, 6},
                                  {-1, -1, 0}};
    int n = matrix.size();

    vector<vector<int>> cost(n, vector<int>(n, INT_MAX));

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 1e8;
                }
                if (i == j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1e8)
                {
                    matrix[i][j] = -1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}