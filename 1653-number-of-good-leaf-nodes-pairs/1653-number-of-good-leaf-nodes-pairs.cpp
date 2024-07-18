class Solution {
public:
void makeGraph(TreeNode* root,TreeNode* prevNode,unordered_map<TreeNode*,vector<TreeNode*>> &adj,unordered_set<TreeNode*> &st){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        st.insert(root);
    }
    if(prevNode!=NULL){
        adj[root].push_back(prevNode);
        adj[prevNode].push_back(root);
    }
   makeGraph(root->left,root,adj,st);
   makeGraph(root->right,root,adj,st); 
}
    int countPairs(TreeNode* root, int distance) {
          unordered_map<TreeNode*,vector<TreeNode*>>adj;
          unordered_set<TreeNode*> st;

          makeGraph(root,NULL,adj,st);

          int count=0;
          for(auto &leaf:st){
            queue<TreeNode*>que;
            unordered_set<TreeNode*>visited;
            que.push(leaf);
            visited.insert(leaf);

            for(int level=0;level<=distance;level++){
              int size=que.size();
              while(size--){
                TreeNode* curr=que.front();
                que.pop();
                if(curr!=leaf && st.count(curr)) count++;

                for(auto &neigh:adj[curr]){
                if(!visited.count(neigh)){
                    que.push(neigh);
                    visited.insert(neigh);
                }
              }
              }
            }
          }
          return count/2;
     }
};