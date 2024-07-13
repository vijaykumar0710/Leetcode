class Solution {
public:
      vector<int> res;
      void helper(TreeNode* root){
       if(root==NULL) return;
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
     }
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);
        return res;
    }
};