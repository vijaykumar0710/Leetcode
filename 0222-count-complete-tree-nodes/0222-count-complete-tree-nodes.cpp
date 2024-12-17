class Solution {
public:
   vector<int> res;
   void helper(TreeNode* root){
   if(root==NULL) return;
   res.push_back(root->val);
   helper(root->left);
   helper(root->right);
 }
    int countNodes(TreeNode* root) {
        helper(root);
       return res.size();
   }
};