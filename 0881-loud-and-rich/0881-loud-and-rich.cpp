class Solution {
public:
int t[501];
int dfs(unordered_map<int,vector<int>>&adj,int x,vector<int>& quiet){
    if(t[x]!=-1) return t[x];
    int ans=x;
       for(auto v:adj[x]){
         int candidate=dfs(adj,v,quiet);
         if(quiet[ans]>quiet[candidate]){
         ans=candidate;
        }
    }
    return t[x]=ans;
}
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    int n=quiet.size();
    unordered_map<int,vector<int>>adj;
    for(auto &vec:richer){
        int u=vec[0];
        int v=vec[1];
        adj[v].push_back(u);
       }
       vector<int>res(n);
        memset(t,-1,sizeof(t));
      for(int i=0;i<n;i++){
       res[i]=dfs(adj,i,quiet);
       }
       return res;
    }
};