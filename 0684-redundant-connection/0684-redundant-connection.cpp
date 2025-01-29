class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);  // Path compression
    }

    bool Union(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false;  // Cycle detected
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;  // Initialize DSU

        for (auto &edge : edges) {
            if (!Union(edge[0], edge[1])) return edge;  // If cycle found, return the edge
        }
        return {};
    }
};
