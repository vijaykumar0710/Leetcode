class Solution {
public:
TreeNode* helpInDelete(TreeNode* root,unordered_set<int>& st,vector<TreeNode*>& result){
    if(root==NULL) return NULL;

    root->left=helpInDelete(root->left,st,result);
    root->right=helpInDelete(root->right,st,result);

    if(st.find(root->val)!=st.end()){
        if(root->left!=NULL) result.push_back(root->left);
        if(root->right!=NULL) result.push_back(root->right);
        return NULL;
    }else{
        return root;
    }
}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        unordered_set<int> st;
        for(int &num:to_delete){
            st.insert(num);
        }
        helpInDelete(root,st,result);
        
        if(st.find(root->val)==st.end()){
            result.push_back(root);
        }
        return result;
    }
};