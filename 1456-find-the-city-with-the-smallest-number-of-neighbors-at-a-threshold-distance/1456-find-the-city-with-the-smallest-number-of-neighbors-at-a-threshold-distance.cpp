class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> mp; // Adjacency list to store (neighbor, weight)

    void bfs(int start, int distanceThreshold, vector<int>& reachableCities) {
        vector<int> distances(reachableCities.size(), INT_MAX);
        distances[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap (distance, node)
        pq.emplace(0, start);

        while (!pq.empty()) {
            int currentDistance = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (currentDistance > distanceThreshold) {
                break;
            }

            for (auto& neighbor : mp[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                int newDistance = currentDistance + weight;

                if (newDistance < distances[v] && newDistance <= distanceThreshold) {
                    distances[v] = newDistance;
                    pq.emplace(newDistance, v);
                }
            }
        }

        for (int distance : distances) {
            if (distance != INT_MAX && distance != 0) {
                reachableCities[start]++;
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            mp[u].emplace_back(v, weight);
            mp[v].emplace_back(u, weight);
        }

        vector<int> reachableCities(n, 0);
        for (int i = 0; i < n; i++) {
            bfs(i, distanceThreshold, reachableCities);
        }

        int minReachable = INT_MAX;
        int city = -1;
        for (int i = 0; i < n; i++) {
            if (reachableCities[i] <= minReachable) {
                minReachable = reachableCities[i];
                city = i;
            }
        }

        return city;
    }
};
