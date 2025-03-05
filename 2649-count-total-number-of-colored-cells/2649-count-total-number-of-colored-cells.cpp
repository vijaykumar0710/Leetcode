class Solution {
public:
    long long coloredCells(int n) {
        return 2*(long long)n*n-2*(long long)n+1;
    }
};