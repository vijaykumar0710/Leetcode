class Solution {
public:
    bool dfs(int node, unordered_map<int, vector<int>>& adj, unordered_set<int>& visited, int destination) {
        // If we reach the destination, return true
        if (node == destination) {
            return true;
        }
        
        visited.insert(node);  // Mark the current node as visited
        
        // Explore all adjacent nodes
        for (auto &neighbor : adj[node]) {
            if (visited.find(neighbor) == visited.end()) {  // Only visit unvisited nodes
                if (dfs(neighbor, adj, visited, destination)) {
                    return true;
                }
            }
        }
        
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adj;
        
        // Build the adjacency list
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_set<int> visited;  // Set to keep track of visited nodes
        
        return dfs(source, adj, visited, destination);  // Start DFS from the source
    }
};
