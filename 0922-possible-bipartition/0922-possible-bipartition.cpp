class Solution {
public:
bool DFS(unordered_map<int,vector<int>>&adj,int u,vector<int>&color,int currColor){
   color[u]=currColor;
   for(auto &v:adj[u]){
    if(color[v]==color[u]) return false;
    if(color[v]==-1){
       int colorOfV=1-color[u];
        if(DFS(adj,v,color,colorOfV)==false)
        return false;
     }
   }
   return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>adj;
        for(auto &num:dislikes){
            int a=num[0];
            int b=num[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(DFS(adj,i,color,1)==false)
                return false;
            }
        }
        return true;
    }
};