#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> grid, vector<int> col, int i)
{
    queue<int> q;
    q.push(i);
    col[i] = 0;
    while (!q.empty())
    {
        vector<int> temp = grid[q.front()];
        // {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}}
        int n = temp.size();
        int val = q.front();
        q.pop();
        for (auto it : temp)
        {
            if (col[it] == -1)
            {
                col[it] = !col[val];
                q.push(it);
            }
            else if (col[it] == col[val])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{

    vector<vector<int>> grid = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    int node = grid.size();
    vector<int> col(node, -1);
    for (int i = 0; i < node; i++)
    {
        if (col[i] == -1)
        {
            if (check(grid, col, i) == false)
            {
                cout << 0;
            }
        }
    }
    cout << 1;
    return 0;
}

//  bool check(vector<int>adj[],int col[],int i){
//         queue<int> q;
//         q.push(i);
//         col[i]=0;
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             for(auto it:adj[node]){
//                 if(col[it]==-1){
//                     col[it]=!col[node];
//                     q.push(it);
//                 }
//                 else if(col[it]==col[node]){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// 	bool isBipartite(int V, vector<int>adj[]){
//         int colour[V];
//         for(int i=0;i<V;i++){
//             colour[i]=-1;
//         }

//         for(int i=0;i<V;i++){
//             if(colour[i]==-1){
//                 if(check(adj,colour,i)==false){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }