class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adj;
        
        // Build the adjacency list
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_set<int>visited;
        queue<int>qu;
        qu.push(source);
        visited.insert(source);

        while(!qu.empty()){
            int x=qu.front();
            qu.pop();

            if(x==destination) return true;

            for(auto &v:adj[x]){
             if(visited.find(v)==visited.end()){
                qu.push(v);
                visited.insert(v);
              }
            }
        }
        return false;
    }
};
