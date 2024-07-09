class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> res;
    if(root!=NULL) st.push(root);
    while(st.size()>0){
        TreeNode* temp=st.top();
        st.pop();
        res.push_back(temp->val);
        if(temp->right!=NULL) st.push(temp->right);
        if(temp->left!=NULL) st.push(temp->left);
       }
       return res;
    }
};