class Solution {
public:
long long minOperations(vector<vector<int>>& queries) {
    long long res = 0;
    for ( auto &q : queries) {
        long long l = q[0], r = q[1], sum = 0, p = 0;
        for (long long p4 = 1; p4 <= r; p4 *= 4) { // 1, 4, 16, 64, ...
            int pl = max(l, p4), pr = min(r, p4 * 4 - 1);
            sum += max(0LL, ++p * (pr - pl + 1));
        }
        res += (sum + 1) / 2;
    }
    return res;
}
};
