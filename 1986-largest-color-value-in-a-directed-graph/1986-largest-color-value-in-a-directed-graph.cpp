class Solution {
public:
    int dp[100005][26];  // Only 26 letters needed
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        if(edges.size()==0) return 1;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build graph
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        // Initialize: if indegree is 0, push to queue and set color count
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
            dp[i][colors[i] - 'a'] = 1;
        }

        int ans = 0;
        int visited = 0;
      
        while (!q.empty()) {
            int u = q.front(); q.pop();
            visited++;
            for (int v : adj[u]) {
                for (int c = 0; c < 26; ++c) {
                    int extra = (colors[v] - 'a' == c) ? 1 : 0;
                    dp[v][c] = max(dp[v][c], dp[u][c] + extra);
                    ans=max(ans,dp[v][c]);
                }
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }
        // Check for cycles
        if (visited < n) return -1;

        return ans;
    }
};
