class Solution {
public:
int n;
int solve(vector<int>&nums,int i,long target,long long sum,unordered_map<string ,int>&mp){
    if (i == n) { 
    return sum == target ? 1 : 0; 
}
   string key=to_string(i)+"_"+to_string(sum);
   if(mp.count(key)) return mp[key];
   return mp[key]=solve(nums,i+1,target,(sum+nums[i]),mp)+solve(nums,i+1,target,(sum-nums[i]),mp);   
}
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        unordered_map<string ,int>mp;
        return solve(nums,0,target,0,mp);
    }
};