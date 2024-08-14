class Solution {
public:
    void inorder(TreeNode* root, unordered_map<int, int>& mp) {
        if (root == NULL) return;
        inorder(root->left, mp);
        mp[root->val]++;
        inorder(root->right, mp);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        inorder(root, mp);

        priority_queue<int> pq;
        for (auto &fre : mp) {
            pq.push(fre.second);
        }

        vector<int> res;
        int maxFreq = pq.top();

        for (auto &fre : mp) {
            if (fre.second == maxFreq) {
                res.push_back(fre.first);
            }
        }

        return res;
    }
};
