class Solution {
public:
    vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        // Build graph and calculate in-degrees
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            indegree[v]++;
        }

        // Perform topological sort
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo_order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo_order.push_back(node);

            for (int neighbor : graph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return topo_order;
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();

        // Build an adjacency list for the undirected graph
        vector<vector<int>> graph(n);
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Group nodes by their values
        map<int, vector<int>> value_to_nodes;
        for (int i = 0; i < n; ++i) {
            value_to_nodes[vals[i]].push_back(i);
        }

        // Initialize DSU
        vector<int> parent(n), size(n, 1);
        iota(parent.begin(), parent.end(), 0);

        // Find function for DSU
        function<int(int)> find = [&](int x) {
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        // Union function for DSU
        auto unite = [&](int u, int v) {
            int pu = find(u), pv = find(v);
            if (pu != pv) {
                if (size[pu] < size[pv]) swap(pu, pv);
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        };

        int good_paths = 0;

        // Process nodes grouped by value
        for (auto& [val, nodes] : value_to_nodes) {
            // Unite nodes with the same value
            for (int node : nodes) {
                for (int neighbor : graph[node]) {
                    if (vals[neighbor] <= val) {
                        unite(node, neighbor);
                    }
                }
            }

            // Count good paths for this value group
            unordered_map<int, int> group_count;
            for (int node : nodes) {
                group_count[find(node)]++;
            }

            for (auto& [group, count] : group_count) {
                good_paths += count * (count - 1) / 2 + count;
            }
        }

        return good_paths;
    }
};
