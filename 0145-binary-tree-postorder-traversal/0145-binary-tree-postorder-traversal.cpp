class Solution {
public:
vector<int> res;
      void helper(TreeNode* root){
       if(root==NULL) return;
        helper(root->left);
         helper(root->right);
         res.push_back(root->val);
     }
    vector<int> postorderTraversal(TreeNode* root) {
        helper(root);
        return res;
    }
};