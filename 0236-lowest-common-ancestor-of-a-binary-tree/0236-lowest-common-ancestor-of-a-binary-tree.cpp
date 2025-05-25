class Solution {
public:
    static const int LOG = 20;
    unordered_map<TreeNode*, vector<TreeNode*>> up;  // up[node][i] = 2^i-th ancestor
    unordered_map<TreeNode*, int> depth;

    // DFS to fill depth and binary lifting table
    void dfs(TreeNode* node, TreeNode* parent) {
        if (!node) return;

        depth[node] = parent ? depth[parent] + 1 : 0;
        up[node] = vector<TreeNode*>(LOG, nullptr);
        up[node][0] = parent;

        for (int i = 1; i < LOG; ++i) {
            if (up[node][i - 1])
                up[node][i] = up[up[node][i - 1]][i - 1];
        }

        dfs(node->left, node);
        dfs(node->right, node);
    }

    TreeNode* lift(TreeNode* node, int k) {
        for (int i = LOG - 1; i >= 0; --i) {
            if ((1 << i) <= k && node) {
                node = up[node][i];
                k -= (1 << i);
            }
        }
        return node;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, nullptr);  // Build binary lifting table

        if (depth[p] < depth[q]) swap(p, q);
        p = lift(p, depth[p] - depth[q]);

        if (p == q) return p;

        for (int i = LOG - 1; i >= 0; --i) {
            if (up[p][i] && up[p][i] != up[q][i]) {
                p = up[p][i];
                q = up[q][i];
            }
        }

        return up[p][0];  // Return the LCA
    }
};
