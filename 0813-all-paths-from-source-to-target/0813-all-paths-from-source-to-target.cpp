class Solution {
public:
vector<vector<int>> result;
vector<int> path;
void dfs(vector<vector<int>>& graph,int u,vector<int> visited){
    path.push_back(u);
    if(u==graph.size()-1) result.push_back(path);
    visited[u]=1; //visited
  for(auto &v:graph[u]){
    if(visited[v]==0){
        dfs(graph,v,visited);  
    }
  }
  path.pop_back();
  visited[u]=0;
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(),0);
        dfs(graph,0,visited);
        return result;
    }
};