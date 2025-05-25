class Solution {
public:
    long long M=1e9+7;
    int dfs(int node, int parent, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    int max_depth = 0;
    for (int child : adj[node]) {
        if (!visited[child]) {
            max_depth = max(max_depth, dfs(child, node, adj, visited));
        }
    }
    return max_depth + 1;
}

    long long modPower(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1){
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int m=edges.size();
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(2*m+1,false);
        int depth=dfs(1,-1,adj,visited)-1;
        cout<<depth;
        long long ans = modPower(2, depth - 1, M);
        return ans;
    }
};