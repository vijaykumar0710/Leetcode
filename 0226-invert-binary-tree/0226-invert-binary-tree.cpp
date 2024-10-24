class Solution {
public:
void helper(TreeNode* root){
    
}
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
            TreeNode* temp=root->left;
            root->left=root->right;
            root->right=temp;
           if(root->left) invertTree(root->left);
           if(root->right) invertTree(root->right);
          return root;
    }
};