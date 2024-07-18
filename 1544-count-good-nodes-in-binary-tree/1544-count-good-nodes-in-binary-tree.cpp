class Solution {
public:
 int good=0;
 int dfs(TreeNode* node, int maxVal) {
        if (node==NULL) {
            return 0;
        }  
        // Check if the current node is a good node
        if(node->val>=maxVal){
            good++;
        }
        // Update the maximum value on the path to the current node
        maxVal =max(maxVal, node->val);
        // Continue DFS traversal for left and right children
         dfs(node->left, maxVal);
         dfs(node->right, maxVal);
        
        return good;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
