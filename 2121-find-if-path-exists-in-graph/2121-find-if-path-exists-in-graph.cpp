class Solution {
public:
    bool dfs(int node, vector<vector<int>>& edges, unordered_set<int>& visited, int destination) {
        // If we reach the destination, return true
        if (node == destination) {
            return true;
        }
        
        visited.insert(node);  // Mark the current node as visited
        
        // Explore all edges to find connected nodes
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            // Check if the current node is part of this edge
            if (u == node && visited.find(v) == visited.end()) {
                if (dfs(v, edges, visited, destination)) {
                    return true;
                }
            } else if (v == node && visited.find(u) == visited.end()) {
                if (dfs(u, edges, visited, destination)) {
                    return true;
                }
            }
        }
        
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_set<int> visited;  // Set to keep track of visited nodes
        return dfs(source, edges, visited, destination);  // Start DFS from the source
    }
};
