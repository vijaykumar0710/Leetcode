class Solution {
public:
int t[201][10001];
bool helper(vector<int>& nums,int n,int target,int i){
    if(target==0) return true;
    if(target<0 || n==0) return false;
    if(t[i][target]!=-1) return t[i][target];
    return t[i][target]=helper(nums,n-1,target-nums[i],i+1) || helper(nums,n-1,target,i+1);
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto &num:nums) sum+=num;
        if(sum%2!=0) return false;
        memset(t,-1,sizeof(t));
        return helper(nums,n,sum/2,0);
    }
};