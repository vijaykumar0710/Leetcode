class Solution {
public:
bool dfs(unordered_map<int,vector<int>>&adj, int source, int destination,unordered_set<int>& visited){
    if(source==destination){
        return true;
    }
    visited.insert(source);
for(auto &v:adj[source]){
if(visited.find(v)==visited.end()){
   if(dfs(adj,v,destination,visited)){
    return true;
       }
     }
   }
   return false; 
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>adj;
       
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       unordered_set<int> visited;
       return dfs(adj,source,destination,visited);  
    }
};