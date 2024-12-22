class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n + 1, 0);

        // Build the adjacency list and calculate indegree
        for (auto& vec : relations) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // Topological sorting using Kahn's algorithm
        queue<int> que;
        vector<int> topo;
        for (int i = 1; i <= n; i++) { // Fix: Changed the loop condition
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        while (!que.empty()) {
            int u = que.front();
            topo.push_back(u);
            que.pop();

            for (int& v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        // DP array to store the minimum time to complete each course
        vector<int> dp(n + 1, 0);
        for (int u : topo) {
            // If no prerequisites, time to complete is the course time
            dp[u] = max(dp[u], time[u - 1]);
            for (int v : adj[u]) {
                dp[v] = max(dp[v], dp[u] + time[v - 1]);
            }
        }

        // The result is the maximum time in the dp array
        return *max_element(dp.begin(), dp.end());
    }
};
