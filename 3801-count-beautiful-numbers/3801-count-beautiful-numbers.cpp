class Solution {
public:
    map<tuple<int, int, int, int>, int> dp;  // Using map with tuple key for safe memoization

    int solve(string &s, int idx, int tight, int sum, int product) {
        if (idx == s.size()) {
            if (sum != 0 && product % sum == 0) return 1;
            return 0;
        }

        auto key = make_tuple(idx, tight, sum, product);
        if (dp.find(key) != dp.end()) return dp[key];

        int limit = tight ? s[idx] - '0' : 9;
        int ans = 0;

        for (int i = 0; i <= limit; ++i) {
            int newSum = sum + i;
            int newProduct;
            // Edge case handling: if product is 0 (only at beginning), treat it as neutral (i.e., 1)
            if (sum == 0 && product == 1 && i == 0) newProduct = 1;
            else newProduct = product * i;

            ans += solve(s, idx + 1, tight & (i == s[idx] - '0'), newSum, newProduct);
        }

        return dp[key] = ans;
    }

    int beautifulNumbers(int l, int r) {
        string re = to_string(r);
        dp.clear();
        int right = solve(re, 0, 1, 0, 1); // from 1 to r

        string le = to_string(l - 1);
        dp.clear();
        int left = solve(le, 0, 1, 0, 1); // from 1 to l-1

        return right - left;
    }
};
