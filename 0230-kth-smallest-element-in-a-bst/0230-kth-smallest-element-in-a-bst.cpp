class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return NULL;
        vector<int>vec;
        queue<TreeNode*> q;
         q.push(root);
         while(!q.empty()){
        int n=q.size();
        TreeNode* node=q.front();
        q.pop();
        vec.push_back(node->val);
       if(node->left)q.push(node->left);
       if(node->right)q.push(node->right);
      }
      sort(vec.begin(),vec.end());
      return vec[k-1];
    }
};