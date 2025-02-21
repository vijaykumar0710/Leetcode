class FindElements {
public:
unordered_set<int>st;
  void helper(TreeNode* root,int val){
    if(!root) return;
    root->val=val;
    st.insert(val); 
    if(root->left) helper(root->left,2*val+1);
    if(root->right) helper(root->right,2*val+2);
  }

    FindElements(TreeNode* root) {
         helper(root,0);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};