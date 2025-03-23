class Solution {
public:
    typedef pair<long long, int> pi;
    const int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pi>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], cost = road[2];
            adj[u].push_back({cost, v});
            adj[v].push_back({cost, u});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<pi, vector<pi>, greater<pi>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});  

        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            if (currDist > dist[node]) continue;

            for (auto& [cost, adjNode] : adj[node]) {
                long long newDist = currDist + cost;

                if (newDist < dist[adjNode]) {
                    dist[adjNode] = newDist;
                    ways[adjNode] = ways[node]; 
                    pq.push({newDist, adjNode});
                } else if (newDist == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};