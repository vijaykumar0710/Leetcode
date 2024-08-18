class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0; // If there's only one element, no jump is needed

        vector<int> dp(n, INT_MAX); // Initialize the dp array
        dp[0] = 0; // No jump needed to stay at the first index

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        
        return dp[n - 1]; // Return the minimum jumps needed to reach the last index
    }
};
