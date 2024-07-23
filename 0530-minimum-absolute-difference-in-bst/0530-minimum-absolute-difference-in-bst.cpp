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
    void helper(TreeNode* root,vector<int>& vec){
      if(root==NULL) return;
        helper(root->left,vec);
        vec.push_back(root->val);
        helper(root->right,vec);
    }
   
    int getMinimumDifference(TreeNode* root) {
     vector<int>vec;
     helper(root,vec);

     int n=vec.size();
     int minSum=INT_MAX;

     for(int i=1;i<n;i++){
       int diff=abs(vec[i]-vec[i-1]);
       minSum=min(minSum,diff);
  }
  return minSum;
    }
};