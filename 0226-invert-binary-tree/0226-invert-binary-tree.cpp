class Solution {
public:
void helper(TreeNode* root){
          if(root==NULL) return;
            TreeNode* temp=root->left;
            root->left=root->right;
            root->right=temp;
           if(root->left) helper(root->left);
           if(root->right) helper(root->right);
}
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};