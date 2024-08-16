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

        // Use a queue for BFS
        queue<int> q;
        unordered_set<int> visited;
        
        // Start BFS from the source
        q.push(source);
        visited.insert(source);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            // If we reach the destination, return true
            if (node == destination) {
                return true;
            }
            
            // Explore all adjacent nodes
            for (auto &neighbor : adj[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        
        // If BFS completes without finding the destination, return false
        return false;
    }
};
