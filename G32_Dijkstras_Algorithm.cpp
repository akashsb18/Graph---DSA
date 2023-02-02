// Using Priority Queue

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

// vector<vector<int>> adj[] = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};

// int V = 3, S = 2;

//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     pq.push({0, S});
//     vector<int> dist(V, INT_MAX);
//     dist[S] = 0;

//     while (!pq.empty())
//     {
//         int dis = pq.top().first;
//         int node = pq.top().second;
//         pq.pop();
//         for (auto it : adj[node])
//         {
//             int adjWeight = it[1];
//             int adjNode = it[0];
//             if (dis + adjWeight < dist[adjNode])
//             {
//                 dist[adjNode] = dis + adjWeight;
//                 pq.push({dist[adjNode], adjNode});
//             }
//         }
//     }

//     for (auto it : dist)
//     {
//         cout << it << " ";
//     }

//     return 0;
// }

// Using Set DS

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> adj[] = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};

    int V = 3, S = 2;

    set<pair<int, int>> s;

    s.insert({0, S});

    vector<int> dis(V, INT_MAX);
    dis[S] = 0;

    while (!s.empty())
    {

        auto it = *s.begin();
        int node = it.second;
        int weight = it.first;
        s.erase(it);
        for (auto i : adj[node])
        {
            int adjNode = i[0];
            int adjWeight = i[1];
            if (weight + adjWeight < dis[adjNode])
            {
                // erase if it existed
                if (dis[adjNode] != INT_MAX)
                {
                    s.erase({dis[adjNode], adjNode});
                }
                dis[adjNode] = weight + adjWeight;
                s.insert({dis[adjNode], adjNode});
            }
        }
    }
    for (auto it : dis)
    {
        cout << it << " ";
    }

    return 0;
}