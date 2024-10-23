class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>que;
        que.push(root);
        vector<int>levelSum;
        while(!que.empty()){
            int n=que.size();
            int sum=0;
            while(n--){
                TreeNode* node=que.front();
                que.pop();
                sum+=node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            levelSum.push_back(sum);
        }
        root->val=0;
        que.push(root);
        int i=1;
        while(!que.empty()){
           int n=que.size();
           while(n--){
           TreeNode* curr=que.front();
           que.pop();
           int sibling=curr->left!=NULL?curr->left->val:0;
           sibling+=curr->right!=NULL?curr->right->val:0;
           if(curr->right){
            curr->right->val=levelSum[i]-sibling;
            que.push(curr->right);
           }
           if(curr->left){
            curr->left->val=levelSum[i]-sibling;
            que.push(curr->left);
             }
           }
           i++;
        }
        return root;
    }
};