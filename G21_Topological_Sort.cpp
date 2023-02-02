// public:
// void dfs(vector<int> adj[], int node, int vis[], stack<int> &st)
// {
//     vis[node] = 1;
//     for (auto it : adj[node])
//     {
//         if (vis[it] == 0)
//         {
//             dfs(adj, it, vis, st);
//         }
//     }
//     st.push(node);
// }
// // Function to return list containing vertices in Topological order.
// vector<int> topoSort(int V, vector<int> adj[])
// {
// stack<int> st;
// vector<int> ans;
// int vis[V] = {0};
// for (int i = 0; i < V; i++)
// {
//     if (vis[i] == 0)
//     {
//         dfs(adj, i, vis, st);
//     }
// }
// while (!st.empty())
// {
//     ans.push_back(st.top());
//     st.pop();
// }
//     return ans;
// }