class Solution {
public:
// void helper(int n,int set){
//     if(n==0){
//         return;
//     }
//     set+=n%2;
//     helper(n/2,set);
// }
int set=0;
    int hammingWeight(int n) {
        if(n==0) return 0;
        set+=n%2;
        hammingWeight(n/2);
        return set;
    }
};