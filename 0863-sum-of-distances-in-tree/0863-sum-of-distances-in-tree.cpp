class Solution {
public:
    vector<int> res, count;
    vector<vector<int>> tree;
    
    void dfs(int node, int parent) {
        for (int child : tree[node]) {
            if (child == parent) continue;
            dfs(child, node);
            count[node] += count[child];
            res[node] += res[child] + count[child];
        }
        count[node] += 1; // including the node itself
    }
    
    void dfs2(int node, int parent, int N) {
        for (int child : tree[node]) {
            if (child == parent) continue;
            res[child] = res[node] - count[child] + (N - count[child]);
            dfs2(child, node, N);
        }
    }
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        tree.resize(N);
        res.resize(N);
        count.resize(N);
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1);  // Step 1: Calculate subtree sizes and initial distances
        dfs2(0, -1, N); // Step 2: Re-rooting DFS to calculate results for other nodes
        return res;
    }
};
