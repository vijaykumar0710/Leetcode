class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>que;
        que.push(root);
        priority_queue<long,vector<long>,greater<long>>pq;
        while(!que.empty()){
            int n=que.size();
            long sum=0;
            while(n>0){
                TreeNode* num=que.front();
                que.pop();
                sum+=num->val;
               if(num->left!=NULL) que.push(num->left);
               if(num->right!=NULL) que.push(num->right);
               n--;
            }
            pq.push(sum);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.size()<k?-1:pq.top();
    }
};