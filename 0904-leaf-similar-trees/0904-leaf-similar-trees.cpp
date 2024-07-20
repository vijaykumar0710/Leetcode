class Solution {
public:
vector<int>vec1;
vector<int>vec2;
 void help1(TreeNode* root1){
      if(root1==NULL) return;
    if(root1->left==NULL && root1->right==NULL){   
        vec1.push_back(root1->val);
        return;
    }
    help1(root1->left);
    help1(root1->right);  
}
void help2(TreeNode* root2){
    if(root2==NULL) return;
    if(root2->left==NULL && root2->right==NULL){
        vec2.push_back(root2->val);
        return;
    }
    help2(root2->left);
    help2(root2->right);  
}

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        help1(root1);
        help2(root2);
      return (vec1==vec2?1:0);
    }
};