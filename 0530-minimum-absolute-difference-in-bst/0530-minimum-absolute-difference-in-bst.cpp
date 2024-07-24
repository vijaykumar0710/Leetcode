class Solution {
public:
  int minDiff=INT_MAX;
    void helper(TreeNode* root,TreeNode* &prev){
      if(root==NULL) return;
        helper(root->left,prev);
        if(prev!=NULL){
     minDiff=min(minDiff,root->val-prev->val);
        }
        prev=root;
        helper(root->right,prev);
    }
   
    int getMinimumDifference(TreeNode* root) {
     TreeNode* prev=NULL;
     helper(root,prev);
      return minDiff;
    }
};