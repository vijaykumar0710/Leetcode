class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1, -1);
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            if (!dq.empty() && nums[i] != nums[dq.back()] + 1) {
                dq.clear();
            }
            
            dq.push_back(i);

            if (dq.size() == k) {
                res[i - k + 1] = nums[dq.back()];
            }
        }

        return res;
    }
};