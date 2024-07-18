class Solution {
public:
 int dfs(TreeNode* node, int maxVal) {
        if (!node) {
            return 0;
        }
        
        // Check if the current node is a good node
        int good = node->val >= maxVal ? 1 : 0;
        
        // Update the maximum value on the path to the current node
        maxVal = std::max(maxVal, node->val);
        
        // Continue DFS traversal for left and right children
        good += dfs(node->left, maxVal);
        good += dfs(node->right, maxVal);
        
        return good;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
