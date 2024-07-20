class Solution {
public:
void helper(TreeNode* root,long long sum,long long& count){
    if(root==NULL) return;
        if(root->val==sum) count++;
    helper(root->left,sum-(root->val),count);
    helper(root->right,sum-(root->val),count);
}
    int pathSum(TreeNode* root, long long targetSum) { //to add the sums every nodepath
        if(root==NULL) return 0;
        long long count=0;
        helper(root,targetSum,count);
        count+=(pathSum(root->left,targetSum)+pathSum(root->right,targetSum));
        return count;
    }
};