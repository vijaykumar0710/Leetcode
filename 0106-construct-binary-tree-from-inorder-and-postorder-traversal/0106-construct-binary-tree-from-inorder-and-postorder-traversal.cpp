class Solution {
public:
TreeNode* build(vector<int>& inorder, vector<int>& postorder,int inStart,int inEnd,int postStart,int postEnd){

      if(inStart>inEnd) return NULL;

      TreeNode* root=new TreeNode(postorder[postEnd]);

      int i=inStart;
      for(;i<=inEnd;i++){
        if(inorder[i]==root->val){
            break;
        }
      }

      int leftsize=i-inStart;
      int rightsize=inEnd-i;

     root->left=build(inorder,postorder,inStart,i-1,postStart,postStart+leftsize-1);
     root->right=build(inorder,postorder,i+1,inEnd,postEnd-rightsize,postEnd-1);

     return root;
   }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n=inorder.size();
        int inStart=0;
        int inEnd=n-1;
        
        int postStart=0;
        int postEnd=n-1;

        return build(inorder,postorder,inStart,inEnd,postStart,postEnd);
    }
};