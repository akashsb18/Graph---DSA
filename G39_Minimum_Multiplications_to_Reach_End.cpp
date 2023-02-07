#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> A = {3, 4, 65};
    int n = A.size();
    int start = 7, end = 66175;

    queue<pair<int, int>> q;
    q.push({0, start});

    vector<int> dist(100000, INT_MAX);
    dist[start] = 0;

    while (!q.empty())
    {
        int node = q.front().second;
        int steps = q.front().first;
        q.pop();

        if (node == end)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            int newNode = (node * A[i]) % 100000;
            if (steps + 1 < dist[newNode])
            {
                dist[newNode] = steps + 1;
                q.push({steps + 1, newNode});
            }
        }
    }

    cout << dist[end];
    // cout << -1 << endl;

    return 0;
}