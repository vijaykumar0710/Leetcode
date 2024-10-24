class Solution {
public:
int count(TreeNode* root){
    if(root==NULL) return 0;
    return 1+count(root->left)+count(root->right);
    }
    bool DFS(TreeNode* root,int i,int totalNodes){
        if(root==NULL) return true;
        if(i>totalNodes) return false;
        return DFS(root->left,2*i,totalNodes) && DFS(root->right,2*i+1,totalNodes);
    }
    bool isCompleteTree(TreeNode* root) {
        int totalNodes=count(root);
         int i=1;
        return DFS(root,i,totalNodes);
    }
};