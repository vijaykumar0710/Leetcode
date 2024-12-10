class Solution {
public:
    int trailingZeroes(int n) {
        int cnt=0;
        if(n<5) return 0;
        cnt+=n/5;
        cnt+=n/25;
        cnt+=n/125;
        cnt+=n/625;
        cnt+=n/3125;
        return cnt;
    }
};