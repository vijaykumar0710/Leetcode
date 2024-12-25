class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int>result;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
           int n=que.size();
           int maxi=INT_MIN;
           while(n--){
            TreeNode* temp=que.front();
            que.pop();
            maxi=max(maxi,temp->val);
            if(temp->left)que.push(temp->left);
            if(temp->right)que.push(temp->right);
           }
           result.push_back(maxi);
        }
        return result;
    }
};