class Solution {
public:
int maxSum;
int solve(TreeNode* root){
    if(!root)return 0;
    int l=solve(root->left);
    int r=solve(root->right);
    int neeche_hi_milgya_ans=l+r+root->val;
    int koi_ek_achchha=max(l,r)+root->val;
    int only_root_achchha=root->val;

    maxSum=max({maxSum,neeche_hi_milgya_ans,koi_ek_achchha,only_root_achchha});
    
    return max(only_root_achchha,koi_ek_achchha);
}
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
    }
};