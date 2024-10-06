class Solution {
public:
int dfs(unordered_map<int,vector<int>>&adj,vector<bool>&visited,vector<bool>hasApple,int u){
    visited[u]=true;
    int mintime=0;
    for(auto &v:adj[u]){
        if(!visited[v]){
            int dist=dfs(adj,visited,hasApple,v);
            if(dist>0 || hasApple[v]==true){
                mintime+=dist+2;
            }
        }
    }
    return mintime;
}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
       return dfs(adj,visited,hasApple,0);
    }
};