class Solution {
public:
int t[1001];
  int solve(vector<int>& nums, int target){
       if(target==0) return 1;
        if(target<0) return 0;
        if(t[target]!=-1) return t[target];
        int cnt=0; 
        for(int i=0;i<nums.size();i++){
          cnt+=solve(nums,target-nums[i]);
        }
       return t[target]=cnt;
  }
    int combinationSum4(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        return solve(nums,target);
    }
};