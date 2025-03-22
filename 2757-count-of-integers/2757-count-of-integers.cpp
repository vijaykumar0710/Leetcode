class Solution {
public:
    long long dp[23][2][200];
    const int MOD=1e9+7;
    long long solve(string &s, int mini, int maxi, int idx, int tight, int sum) {
        if (sum > maxi) return 0;
        if (idx == s.size()) {
            return (sum >= mini && sum <= maxi) ? 1 : 0;
        }

        if (dp[idx][tight][sum] != -1) return dp[idx][tight][sum];

        int limit = tight ? s[idx] - '0' : 9;
        long long ans = 0;

        for (int i = 0; i <= limit; i++) {
            int updateSum = (sum+i)%MOD;
            ans=(ans+solve(s, mini, maxi, idx + 1, tight & (i == limit), updateSum))%MOD;
        }

        return dp[idx][tight][sum] = ans;
    }

    string subtractOne(string num) {
        int n = num.size();
        int i = n - 1;
        while (i >= 0 && num[i] == '0') {
            num[i] = '9';
            i--;
        }
        if (i >= 0) num[i]--;
        if (num[0] == '0') num = num.substr(1); 
        return num;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        long long right = solve(num2, min_sum, max_sum, 0, 1, 0);

        memset(dp, -1, sizeof(dp));
        string newNum1 = subtractOne(num1);
        long long left = solve(newNum1, min_sum, max_sum, 0, 1, 0);

        return (right - left+MOD)%MOD;
    }
};
