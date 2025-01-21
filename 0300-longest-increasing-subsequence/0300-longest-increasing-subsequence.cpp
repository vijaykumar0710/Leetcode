class Solution {
public:
int n;
int t[2501][2501];
int LIS(vector<int>&nums,int i,int prev_idx){
    if(i==n)return 0;
    if(t[i][prev_idx+1]!=-1) return t[i][prev_idx+1];
    int exclude=LIS(nums,i+1,prev_idx);
    int include=0;
    if(prev_idx==-1 || nums[i]>nums[prev_idx]){ 
     include=1+LIS(nums,i+1,i);
    }
    t[i][prev_idx+1]=max(include,exclude);
    return t[i][prev_idx+1];
}
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
       memset(t,-1,sizeof(t));
        return LIS(nums,0,-1);
    }
};