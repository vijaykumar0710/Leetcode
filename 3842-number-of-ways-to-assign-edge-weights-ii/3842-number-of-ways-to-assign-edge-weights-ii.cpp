class Solution {
public:
    static const int MAXN = 1e5 + 5;  // Maximum number of nodes + padding
    static const int LOG = 20;        // Max depth for binary lifting (2^20 > 1e6)
    long long M = 1e9 + 7;            // Modulus for modular arithmetic

    int depth[MAXN];                  // depth[node] stores depth of each node from root
    int up[MAXN][LOG];                // up[node][i] stores 2^i-th ancestor of node

    // DFS to fill depth and 'up' table for binary lifting
    void dfs(int node, int parent, unordered_map<int, vector<int>>& adj) {
        depth[node] = depth[parent] + 1;  // depth of current node is parent's depth + 1
        up[node][0] = parent;              // immediate parent (2^0-th ancestor)

        // Precompute ancestors for powers of two up to LOG
        for (int i = 1; i < LOG; i++) {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }

        // DFS on children nodes (excluding parent)
        for (int child : adj[node]) {
            if (child != parent) {
                dfs(child, node, adj);
            }
        }
    }

    // Function to find Lowest Common Ancestor (LCA) of nodes u and v using binary lifting
    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);  // ensure u is deeper or equal depth than v

        // Lift u up so both nodes are at same depth
        for (int i = LOG - 1; i >= 0; i--) {
            if (depth[u] - (1 << i) >= depth[v])
                u = up[u][i];
        }

        if (u == v)  // If they are already same after leveling depth, return u or v
            return u;

        // Lift u and v up simultaneously until their parents are different
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        // Now both u and v have same parent which is LCA
        return up[u][0];
    }

    // Fast modular exponentiation (base^exp % mod)
    long long modPower(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;

        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    // Returns distance between nodes u and v (edges count)
    int getDistance(int u, int v) {
        int ancestor = lca(u, v);
        // Distance formula using depths and LCA
        return depth[u] + depth[v] - 2 * depth[ancestor];
    }

    // Main function:
    // Given edges of tree and queries (pairs of nodes),
    // returns vector of edge weights calculated based on distance
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        // Build adjacency list from edges
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0, adj); // Preprocessing from root node 1 (assumed)

        vector<int> res;
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            if(u == v)
                res.push_back(0);   // Distance zero if same node
            else {
                int d = getDistance(u, v);
                // Weight is 2^(d-1) modulo M
                long long ans = modPower(2, d - 1, M);
                res.push_back(ans);
            }
        }
        return res;
    }
};
