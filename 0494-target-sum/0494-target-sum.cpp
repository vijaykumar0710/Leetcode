class Solution {
public:
int n;
int solve(vector<int>&nums,int i,long target,long long sum){
    if (i == n) { 
    return sum == target ? 1 : 0; 
}

   return solve(nums,i+1,target,(sum+nums[i]))+solve(nums,i+1,target,(sum-nums[i]));
    
}
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        
        return solve(nums,0,target,0);
    }
};