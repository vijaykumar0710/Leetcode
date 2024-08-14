class Solution {
public:
unordered_map<int,int>mp;
void help(TreeNode* root){
        if(root==NULL) return;
           mp[root->val]++;
            help(root->left);
            help(root->right);
   }
    vector<int> findMode(TreeNode* root) {
       help(root);
       priority_queue<int>pq;
        for(auto &fre:mp){
            pq.push(fre.second);
          }
          vector<int>res;
          int x=pq.top();
          pq.pop();
          for(auto &idx:mp){
             if(idx.second==x){
                res.push_back(idx.first);
             }
          }
        return res;
    }
};