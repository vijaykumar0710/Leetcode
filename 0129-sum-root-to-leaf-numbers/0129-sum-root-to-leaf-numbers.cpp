class Solution {
public:
int solver(TreeNode* root,int num){
    if(!root) return 0;
     num=num*10+root->val;
     if(root->right==NULL && root->left==NULL){
       return num;    
    }
    int leftNum=solver(root->left,num);
    int rightNum=solver(root->right,num);

    return leftNum+rightNum;
}
    int sumNumbers(TreeNode* root) {
        return solver(root,0);
    }
};