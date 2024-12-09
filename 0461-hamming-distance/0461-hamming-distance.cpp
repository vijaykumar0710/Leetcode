class Solution {
public:
    int hammingDistance(int x, int y) {
        int n=x^y;
        return __builtin_popcount(n);
    }
};