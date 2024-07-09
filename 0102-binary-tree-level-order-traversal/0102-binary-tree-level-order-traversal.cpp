class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> pq;
        vector<vector<int>> res;

        if (root != NULL) pq.push(root);

        while (!pq.empty()) {
            int n = pq.size();
            vector<int> vec;

            while(n--) {
                TreeNode* temp = pq.front();
                pq.pop();
                vec.push_back(temp->val);

                if (temp->left != NULL) pq.push(temp->left);
                if (temp->right != NULL) pq.push(temp->right);
            }

            res.push_back(vec);
        }

        return res;
    }
};
