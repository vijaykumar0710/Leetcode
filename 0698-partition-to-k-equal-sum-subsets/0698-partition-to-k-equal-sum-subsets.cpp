class Solution {
public:
    bool backtrack(vector<int>& nums, vector<bool>& used, int k, int start, int target, int currentSum) {
        if (k == 0) return true; // All subsets formed
        if (currentSum == target) // One subset formed, move to the next
            return backtrack(nums, used, k - 1, 0, target, 0);

        for (int i = start; i < nums.size(); i++) {
            if (!used[i] && currentSum + nums[i] <= target) {
                used[i] = true; // Mark the element as used
                if (backtrack(nums, used, k, i + 1, target, currentSum + nums[i]))
                    return true;
                used[i] = false; // Backtrack
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % k != 0) return false;
        int target = totalSum / k;

        // Sort in descending order to optimize
        sort(nums.rbegin(), nums.rend());
        vector<bool> used(nums.size(), false);

        return backtrack(nums, used, k, 0, target, 0);
    }
};
