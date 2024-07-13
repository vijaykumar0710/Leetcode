class Solution {
public:
vector<int> res;
void inorder(TreeNode* root){
 if(root==NULL) return;
   inorder(root->left);
   cout<<root->val;
   res.push_back(root->val);
   inorder(root->right);
}
    bool isValidBST(TreeNode* root) {
        inorder(root);
       for (int i = 1; i < res.size(); i++) {
            if (res[i] <= res[i - 1]) return false;
        }
        return true;
    }
};