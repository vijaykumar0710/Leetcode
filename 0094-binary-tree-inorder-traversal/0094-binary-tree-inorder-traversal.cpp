class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        TreeNode *curr=root;
        while(curr!=NULL){ 
        if(curr->left==NULL){
            res.push_back(curr->val);
            curr=curr->right;
          }else{
            TreeNode* leftchild=curr->left;
            while(leftchild->right!=NULL){
                leftchild=leftchild->right;
            }
            leftchild->right=curr;
            // delete(set null) of curr->left
            TreeNode* temp=curr;
            curr=curr->left;
            temp->left=NULL;
          }
        }
        return res;
    }
};