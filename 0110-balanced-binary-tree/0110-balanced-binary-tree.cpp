class Solution {
public:
    bool flag = true;

    int levels(TreeNode* root) {
        if (root == NULL) return 0;
        
        int leftHeight = levels(root->left);
        int rightHeight = levels(root->right);
        
        if (abs(leftHeight - rightHeight) > 1) {
            flag = false;
        }
        
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        levels(root);
        return flag;
    }
};
