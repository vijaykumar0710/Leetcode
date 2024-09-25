class Solution {
public:
void DFS(unordered_map<int,vector<int>>&adj,vector<bool>&visited,int u){
    visited[u]=true;
    
    for(auto &v:adj[u]){
        if(!visited[v]){
            DFS(adj,visited,v);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n=isConnected.size();
       vector<bool>visited(n,false);
       unordered_map<int,vector<int>>adj;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1){
               adj[i].push_back(j);
               adj[j].push_back(i); 
            }
        }
       }
       int Provinces=0;
       for(int i=0;i<n;i++){
        if(visited[i]==false){
            DFS(adj,visited,i);
            Provinces++;
          }
       } 
       return Provinces;
    }
};