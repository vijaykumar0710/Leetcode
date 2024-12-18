class Solution {
public:
    int sumNumbers(TreeNode* root,int num=0) {
        if(!root) return 0;
        num=num*10+root->val;
         if(root->right==NULL && root->left==NULL){
          return num;    
        }
       return sumNumbers(root->left,num)+sumNumbers(root->right,num);
    }
};