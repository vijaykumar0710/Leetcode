class Solution {
public:
int DPT(TreeNode* root,int &res){
    if(root==NULL)
        return 0;

    int l=DPT(root->left,res);
    int r=DPT(root->right,res);

    int temp=max(l,r)+1;
    int ans=max(temp,l+r+1);
        res=max(res,ans);

   return temp;
}
    int diameterOfBinaryTree(TreeNode* root) {
        int res=INT_MIN;
        DPT(root,res);
        return res-1;
    }
};