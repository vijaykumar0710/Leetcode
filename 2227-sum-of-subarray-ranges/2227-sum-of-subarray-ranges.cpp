class Solution {
public:
   long long sumOfMinimums(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    vector<int> pse(n), nse(n);

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        long long left = i - pse[i];
        long long right = nse[i] - i;
        res = (res + heights[i] * left * right );
    }

    return res;
}

    long long sumOfMaximums(vector<int>& heights) {
        int n = heights.size();
        vector<int> pge(n), nge(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] <= heights[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] < heights[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            res = (res + 1LL * heights[i] * left * right);
        }
        return res;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long max_sum = sumOfMaximums(nums);
        long long min_sum = sumOfMinimums(nums);
        return (max_sum - min_sum);
    }
};
