// // //GFG
// // #include <bits/stdc++.h>
// // using namespace std;

// // int main()
// // {

// //     vector<vector<int>> grid = {{1, 1, 1, 1, 1},
// //                                 {1, 1, 1, 1, 1},
// //                                 {1, 1, 1, 1, 0},
// //                                 {1, 0, 1, 0, 1}};
// //     pair<int, int> source = {0, 0};
// //     pair<int, int> dest = {3, 4};
// //     int n = grid.size(), m = grid[0].size();
// //     vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
// //     dist[source.first][source.second] = 0;
// //     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

// //     pq.push({0, source});
// //     int row[] = {-1, 0, 1, 0};
// //     int col[] = {0, 1, 0, -1};
// //     while (!pq.empty())
// //     {
// //         int curRow = pq.top().second.first;
// //         int curCol = pq.top().second.second;
// //         int dis = pq.top().first;
// //         pq.pop();
// //         for (int i = 0; i < 4; i++)
// //         {
// //             int newRow = row[i] + curRow;
// //             int newCol = col[i] + curCol;
// //             if (newRow >= 0 and newRow < n and newCol >= 0 and newCol < m and grid[newRow][newCol] != 0 and dis + 1 < dist[newRow][newCol])
// //             {
// //                 dist[newRow][newCol] = dis + 1;
// //                 pq.push({dis + 1, {newRow, newCol}});
// //             }
// //         }
// //     }

// //     int ans = dist[dest.first][dest.second];
// //     if (ans == INT_MAX)
// //     {
// //         cout << -1 << endl;
// //     }
// //     else
// //     {
// //         cout << ans << endl;
// //     }

// //     // for (int i = 0; i < n; i++)
// //     // {
// //     //     for (int j = 0; j < m; j++)
// //     //     {
// //     //         cout << dist[i][j] << " ";
// //     //     }
// //     //     cout << endl;
// //     // }

// //     return 0;
// // }

// // // Leetcode
// // #include <bits/stdc++.h>
// // using namespace std;

// // int main()
// // {

// //     vector<vector<int>> grid = {
// //         {1, 0, 0},
// //         {1, 1, 0},
// //         {1, 1, 0},
// //     };

// //     int n = grid.size();
// //     pair<int, int> source = {0, 0};
// //     pair<int, int> dest = {n - 1, n - 1};
// //     vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
// //     dist[source.first][source.second] = 0;
// //     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

// //     pq.push({0, source});
// //     int row[] = {-1, 0, 1, 0, -1, 1, 1, -1};
// //     int col[] = {0, 1, 0, -1, 1, 1, -1, -1};
// //     while (!pq.empty())
// //     {
// //         int curRow = pq.top().second.first;
// //         int curCol = pq.top().second.second;
// //         int dis = pq.top().first;
// //         pq.pop();
// //         for (int i = 0; i < 8; i++)
// //         {
// //             int newRow = row[i] + curRow;
// //             int newCol = col[i] + curCol;
// //             if (newRow >= 0 and newRow < n and newCol >= 0 and newCol < n and grid[newRow][newCol] != 1 and dis + 1 < dist[newRow][newCol])
// //             {
// //                 dist[newRow][newCol] = dis + 1;
// //                 pq.push({dis + 1, {newRow, newCol}});
// //             }
// //         }
// //     }

// //     // int ans = dist[dest.first][dest.second];
// //     // if (ans == INT_MAX)
// //     // {
// //     //     cout << -1 << endl;
// //     // }
// //     // else
// //     // {
// //     //     cout << ans << endl;
// //     // }

// //     // for (int i = 0; i < n; i++)
// //     // {
// //     //     for (int j = 0; j < n; j++)
// //     //     {
// //     //         cout << dist[i][j] << " ";
// //     //     }
// //     //     cout << endl;
// //     // }

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<vector<int>> grid = {
//         {1, 0, 0},
//         {1, 1, 0},
//         {1, 1, 0},
//     };

//     int n = grid.size();
//     pair<int, int> source = {0, 0};
//     pair<int, int> dest = {n - 1, n - 1};
//     vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
//     dist[source.first][source.second] = 0;
//     // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
//     set<pair<int, pair<int, int>>> pq;
//     pq.insert({0, source});

//     pq.insert({0, source});
//     int row[] = {-1, 0, 1, 0, -1, 1, 1, -1};
//     int col[] = {0, 1, 0, -1, 1, 1, -1, -1};
//     while (!pq.empty())
//     {
//         auto it = *pq.begin();
//         int curRow = it.second.first;
//         int curCol = it.second.second;
//         int dis = it.first;
//         pq.erase(it);
//         for (int i = 0; i < 8; i++)
//         {
//             int newRow = row[i] + curRow;
//             int newCol = col[i] + curCol;
//             if (newRow >= 0 and newRow < n and newCol >= 0 and newCol < n and grid[newRow][newCol] != 1 and dis + 1 < dist[newRow][newCol])
//             {
//                 dist[newRow][newCol] = dis + 1;
//                 pq.insert({dis + 1, {newRow, newCol}});
//             }
//         }
//     }

//     // int ans = dist[dest.first][dest.second];
//     // if (ans == INT_MAX)
//     // {
//     //     cout << -1 << endl;
//     // }
//     // else
//     // {
//     //     cout << ans << endl;
//     // }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << dist[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
