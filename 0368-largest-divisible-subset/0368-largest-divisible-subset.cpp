class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> t(n);
        for (int i = 0; i < n; i++) {
            t[i].push_back(nums[i]);
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && t[j].size() + 1 > t[i].size()) {
                    t[i] = t[j];
                    t[i].push_back(nums[i]);
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (t[i].size() > res.size()) {
                res = t[i];
            }
        }

        return res;
    }
};
