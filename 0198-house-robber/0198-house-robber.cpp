class Solution {
public:
int n;
int t[101];
int helper(vector<int>&nums,int i ){
    if(i>=n) return 0;
    if(t[i]!=-1) return t[i];
     int take=nums[i]+helper(nums,i+2);
     int skip=helper(nums,i+1);
     return t[i]=max(take,skip);
}
    int rob(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return helper(nums,0);
    }
};