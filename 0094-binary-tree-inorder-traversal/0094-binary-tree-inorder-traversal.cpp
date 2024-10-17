class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        while(st.size()>0 || root){ 
        if(root!=NULL){
            st.push(root);
            root=root->left;
        } else{
            TreeNode* temp=st.top();
            st.pop();
            res.push_back(temp->val);    
            root=temp->right;
            }
          }
        return res;
    }
};