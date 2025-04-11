class Solution {
public:
    void twoSum(vector<int>& nums, int k, int x, int& res, int& mini, int target) {
        int i = k, j = nums.size() - 1;
        while (i < j) {
            int currentSum = nums[i] + nums[j];
            int totalSum = currentSum + (target - x); // = nums[i] + nums[j] + nums[k]
            int diff = abs(totalSum - target);

            if (diff < mini) {
                mini = diff;
                res = totalSum;
            }

            if (currentSum > x) j--;
            else if (currentSum < x) i++;
            else {
                res = target;
                mini = 0;
                return;
            }
        }
    }

    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2]; // better default guess
        int mini = INT_MAX;

        for (int i = 0; i < n - 2; i++) {
            twoSum(nums, i + 1, target - nums[i], res, mini, target);
            if (mini == 0) break; // exact match found
        }

        return res;
    }
};
