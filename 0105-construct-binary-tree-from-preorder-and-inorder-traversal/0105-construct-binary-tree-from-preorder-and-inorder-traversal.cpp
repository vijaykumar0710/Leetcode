class Solution {
public:
TreeNode* solve(vector<int>&preorder, vector<int>&inorder,unordered_map<int,int>&mp,int &idx,int start,int end){
    if(start>end) return NULL;
    int rootVal=preorder[idx];
    idx++;
    int i=mp[rootVal];
    TreeNode* root=new TreeNode(rootVal);
    root->left=solve(preorder,inorder,mp,idx,start,i-1);
    root->right=solve(preorder,inorder,mp,idx,i+1,end);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int idx=0;
        return solve(preorder,inorder,mp,idx,0,n-1);
    }
};