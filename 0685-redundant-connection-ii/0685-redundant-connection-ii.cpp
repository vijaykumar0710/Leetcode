class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false; // cycle found

        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n + 1, -1);
        int edge1 = -1, edge2 = -1;

        // Step 1: Check if a node has two parents
        for (int i = 0; i < n; ++i) {
            int u = edges[i][0], v = edges[i][1];
            if (indegree[v] == -1) {
                indegree[v] = i;
            } else {
                edge1 = indegree[v]; // first edge to v
                edge2 = i;           // second edge to v
                break;
            }
        }

        // Step 2: Initialize DSU
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) parent[i] = i;

        // Step 3: Union-Find and check cycle
        for (int i = 0; i < n; ++i) {
            if (i == edge2) continue; // skip second edge temporarily

            int u = edges[i][0], v = edges[i][1];
            if (!Union(u, v)) {
                // cycle found
                if (edge1 != -1) return edges[edge1];
                return edges[i];
            }
        }

        // If no cycle found, edge2 is the extra edge
        return edges[edge2];
    }
};
