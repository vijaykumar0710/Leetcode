class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>que;
        que.push(root);
        bool past=false;
        while(!que.empty()){ 
            TreeNode* node=que.front();
            que.pop();
            if(node==NULL){
                past=true;
            }else{
                if(past==true){
                    return false;
                }
            que.push(node->left);
            que.push(node->right);
               }
            }
        return true;
    }
};