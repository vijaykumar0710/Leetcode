/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
        if (left.first > right.first) {
            return {left.first + 1, left.second};
        } else {
            return {right.first + 1, right.second};
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};