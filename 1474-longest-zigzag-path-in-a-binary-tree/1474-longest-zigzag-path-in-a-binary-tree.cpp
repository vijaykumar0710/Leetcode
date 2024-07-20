class Solution {
public:
    int maxsteps=0;
void solve(TreeNode* root,bool flag,int steps){
    if(root==NULL) return;

    maxsteps=max(maxsteps,steps);  

    if(flag==true){
        solve(root->left,false,steps+1);
        solve(root->right,true,1);
    }else{
        solve(root->right,true,steps+1);
        solve(root->left,false,1);
    }  
}
    int longestZigZag(TreeNode* root) {
      
      solve(root,true,0);
      solve(root,false,0);
       return maxsteps;
    }
};