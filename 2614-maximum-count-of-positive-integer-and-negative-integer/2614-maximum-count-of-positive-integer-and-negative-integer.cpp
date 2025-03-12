class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        // Count of negative numbers = index of first non-negative number (i.e., nums[i] >= 0)
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();

        // Count of positive numbers = n - index of first positive number (i.e., nums[i] > 0)
        int pos = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        
        return max(neg, pos);
    }
};
