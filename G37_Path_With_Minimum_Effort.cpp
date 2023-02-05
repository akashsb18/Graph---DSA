#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> height = {{1, 2, 2},
                                  {3, 8, 4},
                                  {5, 3, 5}};

    int n = height.size();
    int m = height[0].size();

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    dist[0][0] = 0;
    pq.push({0, {0, 0}});

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if (row == n - 1 and col == m - 1)
        {
            return diff;
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {

            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m)
            {
                int check_diff = abs(height[nrow][ncol] - height[row][col]);
                int neweffort = max(check_diff, diff);

                if (neweffort < dist[nrow][ncol])
                {

                    dist[nrow][ncol] = neweffort;
                    pq.push({neweffort, {nrow, ncol}});
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
