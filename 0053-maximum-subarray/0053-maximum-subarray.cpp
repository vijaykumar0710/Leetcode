class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        dp[0]=nums[0];
        int max_sum=INT_MIN;
        for(int i=1;i<n;i++){
           dp[i]=max(dp[i-1]+nums[i],nums[i]);
           max_sum=max(max_sum,dp[i]);
        }
         max_sum=max(max_sum,dp[0]);
        return max_sum;
    }
};