class Solution {
public:
    unordered_map<string, int> memo;

    int dfs(int u, int k, int sum, int t, unordered_map<int, vector<pair<int, int>>>& graph) {
        if (k == 0) return (sum < t) ? sum : -1;

        string key = to_string(u) + "," + to_string(k) + "," + to_string(sum);
        if (memo.find(key) != memo.end()) return memo[key];

        int maxSum = -1;
            for (auto &[v, w] : graph[u]) {
                if (sum + w < t) {
                    int res = dfs(v, k - 1, sum + w, t, graph);
                    if (res != -1) {
                        maxSum = max(maxSum, res);
                    }
                }
            }

        return memo[key] = maxSum;
    }

    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
       unordered_map<int, vector<pair<int,int>>> graph;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({v, w});
        }

        int ans = -1;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i, k, 0, t, graph));
        }

        return ans;
    }
};
