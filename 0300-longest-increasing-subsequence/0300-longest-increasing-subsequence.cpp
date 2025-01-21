class Solution {
public:
int n;
int LIS(vector<int>&nums,int i,int prev_idx,vector<vector<int>>&t){
    if(i==n)return 0;
    if(t[i][prev_idx+1]!=-1) return t[i][prev_idx+1];
    int exclude=LIS(nums,i+1,prev_idx,t);
    int include=0;
    if(prev_idx==-1 || nums[i]>nums[prev_idx]){ 
     include=1+LIS(nums,i+1,i,t);
    }
    t[i][prev_idx+1]=max(include,exclude);
    return max(include,exclude);
}
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
       vector<vector<int>>t(n,vector<int>(n+1,-1));
        return LIS(nums,0,-1,t);
    }
};