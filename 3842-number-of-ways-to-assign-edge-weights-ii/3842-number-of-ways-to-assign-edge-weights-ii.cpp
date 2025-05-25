class Solution {
public:
    static const int MAXN = 1e5 + 5;
    static const int LOG = 20;
    long long M = 1e9 + 7;

    int depth[MAXN];
    int up[MAXN][LOG];

    void dfs(int node, int parent, unordered_map<int, vector<int>>& adj) {
        depth[node] = depth[parent] + 1;
        up[node][0] = parent;

        for (int i = 1; i < LOG; i++) {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }

        for (int child : adj[node]) {
            if (child != parent) {
                dfs(child, node, adj);
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        for (int i = LOG - 1; i >= 0; i--) {
            if (depth[u] - (1 << i) >= depth[v])
                u = up[u][i];
        }

        if (u == v)
            return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

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

    int getDistance(int u, int v) {
        int ancestor = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[ancestor];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0, adj); // Assuming node 1 is the root

        vector<int> res;
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            if(u==v) res.push_back(0);
            else{ 
            int d = getDistance(u, v);
            long long ans = modPower(2, d - 1, M);
            res.push_back(ans);
            }
        }
        return res;
    }
};
