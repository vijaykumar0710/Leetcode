class Solution {
public:
int n;
    bool BFS(int u, int v, unordered_map<int, vector<int>> &adj){
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(u);
        visited[u]= true;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto &i: adj[node]){
                if(v==i)return true;
                if(!visited[i]){
                    q.push(i);
                    visited[i]= true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n= edges.size();
        unordered_map<int, vector<int>> adj;
        for(int i= 0; i< n; i++){
            int u= edges[i][0];
            int v= edges[i][1];
            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && BFS(u, v, adj)){
                return edges[i];
            }
            else{
                adj[v].push_back(u);
                adj[u].push_back(v);
            }
        }
        return edges[n-1];
    }
};