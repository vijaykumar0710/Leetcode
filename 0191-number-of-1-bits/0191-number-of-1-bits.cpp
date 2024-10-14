class Solution {
public:
int helper(int n,int &set){
    if(n==0) return 0;
    set+=n%2;
    helper(n/2,set);
    return set;
}
    int hammingWeight(int n) {
        int set=0;
        return helper(n,set);
    }
};