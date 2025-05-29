class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node found
            if (!root->left && !root->right) {
                delete(root);
                return NULL;
            }
            else if (!root->left) {
                TreeNode* temp = root->right;
                delete(root);
                return temp;
            }
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete(root);
                return temp;
            }
            else {
                // Node with two children: find inorder successor (smallest in right subtree)
                TreeNode* succ = findMin(root->right);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
        }
        return root;
    }

private:
    TreeNode* findMin(TreeNode* root) {
        while (root && root->left) {
            root = root->left;
        }
        return root;
    }
};
