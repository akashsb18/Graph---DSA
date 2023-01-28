//     bool check(vector<int>adj[],int colour[],int col,int node){
//         colour[node]=col;
//         for(auto it:adj[node]){
//             if(colour[it]==-1){
//                 if(check(adj,colour,!col,it)==false){
//                     return false;
//                 }
//             }
//             else if(colour[it]==colour[node]){
//                 return false;
//             }
//         }
//         return true;
//     }
// public:
// 	bool isBipartite(int V, vector<int>adj[]){
//         int colour[V];
//         for(int i=0;i<V;i++){
//             colour[i]=-1;
//         }

//         for(int i=0;i<V;i++){
//             if(colour[i]==-1){
//                 if(check(adj,colour,0,i)==false){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }