class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // -1 means uncolored, 0 and 1 are the two colors
        
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {  // not yet colored
                if (!dfs(graph, color, i, 0)) {
                    return false;
                }
            }
        }

        return true;
    }
    
private:
    bool dfs(const vector<vector<int>>& graph, vector<int>& color, int node, int c) {
        color[node] = c;
        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) {  // not colored
                if (!dfs(graph, color, neighbor, 1 - c)) {
                    return false;
                }
            } else if (color[neighbor] == color[node]) {
                // neighbor has the same color as the current node
                return false;
            }
        }
        return true;
    }
};