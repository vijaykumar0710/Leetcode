class Solution {
public:
    long long coloredCells(int n) {
        long long ans=2*(long long)n*n-2*(long long)n+1;
        return ans;
    }
};