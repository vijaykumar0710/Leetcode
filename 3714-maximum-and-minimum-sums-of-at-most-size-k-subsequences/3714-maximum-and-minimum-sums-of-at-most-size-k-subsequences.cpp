class Solution {
public:
    const long long large_mod = 1e9+7;
    int minMaxSums(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> dp(n);
        iota(dp.begin(), dp.end(), 1L);

        long long res = 0;
        for(int j = 0; j < k-1; j++){
            for(int i = 0; i < n; i++){
                long long prev = (i == 0) ? 0L : dp[i-1];
                dp[i] = (prev + dp[n-1] - dp[i] + large_mod) % large_mod;
                res = (res + ((((dp[i] - prev + large_mod) % large_mod) * nums[i]) % large_mod)) % large_mod;
                res = (res + ((((dp[i] - prev + large_mod) % large_mod) * nums[n-i-1]) % large_mod)) % large_mod;
            }
        }
        for(int i : nums){
            res = (res + i) % large_mod;
            res = (res + i) % large_mod;
        }
        
        return res;
    }   
};