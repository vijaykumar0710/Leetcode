class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int sum = accumulate(coins.begin(), coins.end(), 0);
        vector<bool> dp(sum + 1, false);
        dp[0] = true;  // Base case: We can always form sum 0.
        for (int coin : coins) {
            for (int j = sum; j >= coin; j--) {  
                dp[j] = dp[j] || dp[j - coin];
            }
        }
        int cnt = 0;
        while (cnt <= sum && dp[cnt]) cnt++;

        return cnt;
    }
};