class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        for (int i = 0; i <= n - k; i++) {
            bool isConsecutiveSorted = true;
            int maxElement = nums[i];

            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] != nums[j - 1] + 1) {
                    isConsecutiveSorted = false;
                    break;
                }
                maxElement = max(maxElement, nums[j]);
            }

            if (isConsecutiveSorted) {
                res.push_back(maxElement);
            } else {
                res.push_back(-1);
            }
        }

        return res;
    }
};