class Solution {
public:
    long long MOD = 1e9+7;
    int minMaxSums(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> dp(n);
        iota(dp.begin(), dp.end(), 1L);

        long long res = 0;
        for(int j = 0; j < k-1; j++){
            for(int i = 0; i < n; i++){
                long long prev = (i == 0) ? 0L : dp[i-1];
                dp[i] = (prev + dp[n-1] - dp[i] + MOD) % MOD;
                res = (res + ((((dp[i] - prev + MOD) % MOD) * nums[i]) % MOD)) % MOD;
                res = (res + ((((dp[i] - prev + MOD) % MOD) * nums[n-i-1]) % MOD)) % MOD;
            }
        }
        for(int i : nums){
            res = (res + i) % MOD;
            res = (res + i) % MOD;
        }
        
        return res;
    }   
};