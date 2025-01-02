class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;  // Store indices
        st.push(-1);    // Base index
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);  // Push the index of '('
            } else {
                st.pop();  // Pop the last '(' or unmatched ')'
                if (st.empty()) {
                    st.push(i);  // Update base index for unmatched ')'
                } else {
                    maxLength = max(maxLength, i - st.top());  // Calculate valid length
                }
            }
        }

        return maxLength;
    }
};
