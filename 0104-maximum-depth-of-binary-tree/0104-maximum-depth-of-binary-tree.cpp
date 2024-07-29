class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return NULL;
        int sum=0;
       return sum=1+max(maxDepth(root->left),maxDepth(root->right));
    }
};