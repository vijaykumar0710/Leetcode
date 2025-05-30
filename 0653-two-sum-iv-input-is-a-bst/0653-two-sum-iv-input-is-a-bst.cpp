class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>st;
        queue<TreeNode*>q;
       q.push(root);
       while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        int x=node->val;
        int y=k-x;
        if(st.find(y)!=st.end()){ 
           return true;
        }
        st.insert(x);
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
       }
       return false;
    }
};