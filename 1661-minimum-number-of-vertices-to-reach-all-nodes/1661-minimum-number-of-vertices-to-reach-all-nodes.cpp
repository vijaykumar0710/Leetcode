class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    unordered_map<int,vector<int>>adj;
    //adjacency list
    for(auto &edge:edges){
       int u=edge[0];
       int v=edge[1];
       adj[u].push_back(v);
       }
       // calculating indegree 
       vector<int>indegree(n,0);
       for(int u=0;u<n;u++){
        for(auto &v:adj[u]){
            indegree[v]++;
          }
       }
       // push vertices in queue with indegree 0
     //  queue<int>que;
       vector<int>result;
       for(int i=0;i<n;i++){
        if(indegree[i]==0) result.push_back(i);
       }
       // BFS
    //    vector<int>result;
    //    while(!que.empty()){
    //      int u=que.front();
    //      result.push_back(u);
    //      que.pop();

    //      for(auto &v:adj[u]){
    //         indegree[v]--;
    
    //      if(indegree[v]==0){
    //         que.push(v);
    //       }
    //    }
    // }
       return result;
    }
};