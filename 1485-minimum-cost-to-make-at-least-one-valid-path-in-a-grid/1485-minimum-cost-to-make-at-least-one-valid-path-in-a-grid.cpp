class Solution {
public:
    int m, n;

    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) ^ hash<T2>()(p.second);
        }
    };

    int dikshtra(unordered_map<pair<int, int>, vector<pair<pair<int, int>, int>>, pair_hash>& adj) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        res[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int cost = pq.top().first;
            pair<int, int> node = pq.top().second;
            pq.pop();

            for (auto& edge : adj[node]) {
                pair<int, int> neigh = edge.first;
                int weight = edge.second;

                if (cost + weight < res[neigh.first][neigh.second]) {
                    res[neigh.first][neigh.second] = cost + weight;
                    pq.push({cost + weight, {neigh.first, neigh.second}});
                }
            }
        }
        return res[m - 1][n - 1];
    }
    
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        unordered_map<pair<int, int>, vector<pair<pair<int, int>, int>>, pair_hash> adj;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (j + 1 < n) adj[{i, j}].push_back({{i, j + 1}, 0});
                    if (j - 1 >= 0) adj[{i, j}].push_back({{i, j - 1}, 1});
                    if (i + 1 < m) adj[{i, j}].push_back({{i + 1, j}, 1});
                    if (i - 1 >= 0) adj[{i, j}].push_back({{i - 1, j}, 1});
                }
                if (grid[i][j] == 2) {
                    if (j + 1 < n) adj[{i, j}].push_back({{i, j + 1}, 1});
                    if (j - 1 >= 0) adj[{i, j}].push_back({{i, j - 1}, 0});
                    if (i + 1 < m) adj[{i, j}].push_back({{i + 1, j}, 1});
                    if (i - 1 >= 0) adj[{i, j}].push_back({{i - 1, j}, 1});
                }
                if (grid[i][j] == 3) {
                    if (j + 1 < n) adj[{i, j}].push_back({{i, j + 1}, 1});
                    if (j - 1 >= 0) adj[{i, j}].push_back({{i, j - 1}, 1});
                    if (i + 1 < m) adj[{i, j}].push_back({{i + 1, j}, 0});
                    if (i - 1 >= 0) adj[{i, j}].push_back({{i - 1, j}, 1});
                }
                if (grid[i][j] == 4) {
                    if (j + 1 < n) adj[{i, j}].push_back({{i, j + 1}, 1});
                    if (j - 1 >= 0) adj[{i, j}].push_back({{i, j - 1}, 1});
                    if (i + 1 < m) adj[{i, j}].push_back({{i + 1, j}, 1});
                    if (i - 1 >= 0) adj[{i, j}].push_back({{i - 1, j}, 0});
                }
            }
        }
        return dikshtra(adj);
    }
};
