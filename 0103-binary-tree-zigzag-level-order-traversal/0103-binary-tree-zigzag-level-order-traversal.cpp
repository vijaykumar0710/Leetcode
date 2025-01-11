class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>que;
        vector<vector<int>>result;
       if(root)que.push(root);
        int cnt=0;
        while(!que.empty()){
            int n=que.size();
            vector<int>vec(n); 
            if(cnt%2==0){ 
            for(int i=0;i<n;i++){
                TreeNode* temp=que.front();
                que.pop();
                vec[i]=(temp->val);
               if(temp->left)que.push(temp->left);
               if(temp->right)que.push(temp->right);
               }
            }else{
                 for(int i=n-1;i>=0;i--){
                TreeNode* temp=que.front();
                que.pop();
                vec[i]=(temp->val);
               if(temp->left)que.push(temp->left);
               if(temp->right)que.push(temp->right);
               }
            }
            result.push_back(vec);
            cnt++;
        }
        return result;
    }
};