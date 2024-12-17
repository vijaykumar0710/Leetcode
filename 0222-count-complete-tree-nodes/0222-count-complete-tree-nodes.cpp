class Solution {
public:
    int getLeftheight(TreeNode* root){
        TreeNode* temp=root;
        int lh=0;

        while(temp){
            temp=temp->left;
            lh++;
        }
        return lh;
    }

    int getRightHeight(TreeNode* root){
        TreeNode* temp=root;
        int rh=0;

        while(temp){
            temp=temp->right;
            rh++;
        }
        return rh;
    }

    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;

        int lh=getLeftheight(root);
        int rh=getRightHeight(root);

        if(lh==rh) return (pow(2,lh)-1);

        return countNodes(root->left)+countNodes(root->right)+1;
    }
};