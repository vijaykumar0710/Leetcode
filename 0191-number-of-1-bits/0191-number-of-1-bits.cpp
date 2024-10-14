class Solution {
public:
int set=0;
    int hammingWeight(int n) {
        if(n==0) return 0;
        set+=n%2;
        hammingWeight(n/2);
        return set;
    }
};