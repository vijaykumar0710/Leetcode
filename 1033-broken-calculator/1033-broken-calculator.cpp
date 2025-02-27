class Solution {
public:
   unordered_map<int, int> dp;
    int solve(int x, int y) {
        if (x >= y) return x - y; 
        if (dp.count(y)) return dp[y];
        if (y % 2 == 0)
            return dp[y] = 1 + solve(x, y / 2);
        else
            return dp[y] = 1 + solve(x, y+1);
    }
    int brokenCalc(int startValue, int target) {
        return solve(startValue, target);
    }
};
