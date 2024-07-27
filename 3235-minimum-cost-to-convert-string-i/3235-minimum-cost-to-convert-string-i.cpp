class Pair {
public:
    int node;
    int cost;
    Pair(int n, int c) : node(n), cost(c) {}
};

class Solution {
public:
    vector<int> dijkstra(vector<vector<Pair>>& adj, int src) {
        int n = 26;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        priority_queue<Pair, vector<Pair>, function<bool(Pair, Pair)>> pq(
            [](Pair a, Pair b) { return a.cost > b.cost; });
        pq.push(Pair(src, 0));

        while (!pq.empty()) {
            Pair pair = pq.top();
            pq.pop();
            int node = pair.node;
            int cost = pair.cost;

            for (auto it : adj[node]) {
                int adjNode = it.node;
                int adjCost = it.cost;

                if (dist[node] != INT_MAX && dist[node] + adjCost < dist[adjNode]) {
                    dist[adjNode] = dist[node] + adjCost;
                    pq.push(Pair(adjNode, dist[adjNode]));
                }
            }
        }
        return dist;
    }

    long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int len = source.length();
        int n = 26;

        // Converting it into adj List
        vector<vector<Pair>> adj(n);
        for (int i = 0; i < original.size(); i++) {
            int src = original[i] - 'a';
            int des = changed[i] - 'a';
            int cos = cost[i];
            adj[src].push_back(Pair(des, cos));
        }

        // Compute shortest paths from every node to every other node using Dijkstra's algorithm
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            dist[i] = dijkstra(adj, i);
        }

        // Calculate the minimum cost to transform the source string into the target string
        long ans = 0;
        for (int i = 0; i < len; i++) {
            int start = source[i] - 'a';
            int end = target[i] - 'a';
            if (start == end) continue;
            else {
                if (dist[start][end] == INT_MAX) return -1;
                ans += dist[start][end];
            }
        }
        return ans;
    }
};
