class Solution {
public:
bool isValid(unordered_map<int,vector<int>>&adj,int colr,int node,vector<int>&color){
      for(auto &v:adj[node]){
          if(color[v]==colr) return false;
      }
      return true;
  }
  bool solve(unordered_map<int,vector<int>>&adj,int node,int m,int n,vector<int>&color){
      if(node==n) return true;
      for(int colr=1;colr<=m;colr++){
          if(isValid(adj,colr,node,color)){
              color[node]=colr;
              if(solve(adj,node+1,m,n,color)) return true;
              color[node]=0;
          }
      }
      return false;
  }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
         unordered_map<int,vector<int>>adj;
        for(auto &vec:paths){
            int u=vec[0]-1,v=vec[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(n,0);
        solve(adj,0,4,n,color);
        return color;
    }
};