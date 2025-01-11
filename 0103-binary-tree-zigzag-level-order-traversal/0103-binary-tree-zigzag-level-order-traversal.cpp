class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>que;
        vector<vector<int>>result;
       if(root)que.push(root);
        int cnt=0;
        while(!que.empty()){
            int n=que.size();
            vector<int>vec; 
            while(n--){
                TreeNode* temp=que.front();
                que.pop();
                vec.push_back(temp->val);
               if(temp->left)que.push(temp->left);
               if(temp->right)que.push(temp->right);
            }
           if(cnt%2==0){
            result.push_back(vec);
           }else{
            reverse(vec.begin(),vec.end());
            result.push_back(vec);
           }
           cnt++;
        }
        return result;
    }
};