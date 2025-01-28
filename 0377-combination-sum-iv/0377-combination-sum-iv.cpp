class Solution {
public:
  int solve(vector<int>& nums, int target,vector<int>&t){
       if(target==0) return 1;
        if(target<0) return 0;
        if(t[target]!=INT_MIN) return t[target];
        int cnt=0; 
        for(int i=0;i<nums.size();i++){
          cnt+=solve(nums,target-nums[i],t);
        }
        t[target]=cnt;
        return cnt;
  }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>t(1001,INT_MIN);
        return solve(nums,target,t);
    }
};