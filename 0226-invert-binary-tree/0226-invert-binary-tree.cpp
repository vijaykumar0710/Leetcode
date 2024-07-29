/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* current=que.front();
            que.pop();

            TreeNode* temp=current->right;
            current->right=current->left;
            current->left=temp;

            if(current->left!=NULL) invertTree(current->left);
            if(current->right!=NULL) invertTree(current->right);
        }
        return root;
    }
};