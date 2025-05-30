class BSTIterator {
    stack<TreeNode*> st;
    bool reverse; // false -> in-order, true -> reverse in-order

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = reverse ? node->right : node->left;
        }
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if (reverse) pushAll(temp->left);
        else pushAll(temp->right);
        return temp->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        
        BSTIterator l(root, false); // in-order
        BSTIterator r(root, true);  // reverse in-order

        int i = l.next();
        int j = r.next();

        while (i < j) {
            int sum = i + j;
            if (sum == k) return true;
            else if (sum < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};
