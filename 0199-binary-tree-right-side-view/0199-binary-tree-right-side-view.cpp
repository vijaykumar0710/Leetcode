class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> pq;
        vector<int> res;

        if (root != NULL) pq.push(root);

        while (!pq.empty()) {
            int n = pq.size();
            
            // Loop to iterate through all nodes at the current level
            for(int i = 0; i < n; i++) {
                TreeNode* temp = pq.front();
                pq.pop();
                
                // Check if it's the last node of the current level
                if (i == n - 1) {
                    res.push_back(temp->val);
                }
                
                if (temp->left != NULL) pq.push(temp->left);
                if (temp->right != NULL) pq.push(temp->right);
            }
        }

        return res;
    }
};
