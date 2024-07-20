class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxsum=INT_MIN;
        int maxlevel=0;
        queue<TreeNode*>que;
        que.push(root);
        int currlvl=1;
        while(!que.empty()){
            int n=que.size();
            int sum=0;
            while(n--){   
             TreeNode* temp=que.front();
             que.pop();
             sum+=temp->val;
             if(temp->left){
                que.push(temp->left);
             }
             if(temp->right){
                que.push(temp->right);
               }
            }
            if(sum>maxsum){
                maxsum=sum;
                maxlevel=currlvl;
            }
            currlvl++;
        }
        return maxlevel;
    }
};