class Solution {
public:
bool isCycle(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,vector<bool>&inRecursion){
visited[u]=true;
inRecursion[u]=true;
for(int &v:adj[u]){
    if(!visited[v] && isCycle(adj,v,visited,inRecursion)){
        return true;
    }else if(visited[v] && inRecursion[v]){
        return true;
    }
  }
  inRecursion[u]=false;
  return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(auto &Node:graph[i])
          adj[i].push_back(Node);
        }
        vector<bool>visited(n,false);
        vector<bool>inRecursion(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                isCycle(adj,i,visited,inRecursion);
            }
        }
        vector<int>safeNode;
        for(int i=0;i<n;i++){
            if(!inRecursion[i]){
                safeNode.push_back(i);
            }
        }
        return safeNode;
    }
};