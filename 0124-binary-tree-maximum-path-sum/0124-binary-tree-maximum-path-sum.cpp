class Solution {
public:
int DPT(TreeNode* root,int &res){
    if(root==NULL)
        return 0;

    int l=DPT(root->left,res);
    int r=DPT(root->right,res);

    int temp=max(max(l,r)+root->val,root->val);
    int ans=max(temp,l+r+root->val);
        res=max(res,ans);

   return temp;
}
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        DPT(root,res);
        return res;
    }
};