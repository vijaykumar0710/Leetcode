class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>que;
        vector<double>ans;
        que.push(root);
        while(!que.empty()){
            int n=que.size();
            int m=n;
            long long sum=0;
            while(n--){
             TreeNode* node=que.front();
             que.pop();
             sum+=node->val;
           if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
            }
            double avg=(double)sum/m;
            ans.push_back(avg);
        }
        return ans;
    }
};