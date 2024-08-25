class Solution {
public:
void dfs(int u,unordered_map<int,vector<pair<int,int>>>&adj,vector<bool>&visited,int &result){
    visited[u]=true;
    for(auto &neigh:adj[u]){
        int v=neigh.first;
        int w=neigh.second;
        result=min(result,w);
        if(!visited[v]){
           dfs(v,adj,visited,result);
        }
    }
}
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;
       for(auto &road:roads){
        adj[road[0]].push_back({road[1],road[2]});
         adj[road[1]].push_back({road[0],road[2]});
       }
       vector<bool>visited(n,false);
       int result=INT_MAX;
       dfs(1,adj,visited,result);
       return result;
    }
};