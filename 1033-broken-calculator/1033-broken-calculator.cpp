class Solution {
public:
   unordered_map<int, int> dp;
    int solve(int x, int y) {
        if (x >= y) return x - y; // Direct decrements
       // if (dp.count(y)) return dp[y];

        if (y % 2 == 0)
            return  1 + solve(x, y / 2);
        else
            return  1 + solve(x, y + 1);
    }
    int brokenCalc(int startValue, int target) {
        return solve(startValue, target);
    }
};
