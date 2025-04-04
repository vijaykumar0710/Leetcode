
class Solution {
public:
pair<int, TreeNode*> dfs(TreeNode* root) {
        if (root == NULL) return {0, NULL};
        
        // Recurse for left and right subtrees
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        // If depths are the same, root is the LCA
        if (left.first == right.first) {
            return {left.first + 1, root};
        }
        // Return the subtree with greater depth
        else if (left.first > right.first) {
            return {left.first + 1, left.second};
        } else {
            return {right.first + 1, right.second};
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
         return dfs(root).second;
    }
};