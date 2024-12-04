class Solution {
public:
int t[201][10001];
bool helper(vector<int>&nums,int target,int i,int n){
    if(target==0) return true;
    if(target<0 || n==0) return false;
    if(t[i][target]!=-1) return t[i][target];
    return t[i][target]=helper(nums,target-nums[i],i+1,n-1) || helper(nums,target,i+1,n-1);
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto &num:nums) sum+=num;
        if(sum%2!=0) return false;
        memset(t,-1,sizeof(t));
        return helper(nums,sum/2,0,n);
    }
};