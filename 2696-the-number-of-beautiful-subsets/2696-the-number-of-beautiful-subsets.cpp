class Solution {
public:
int res;
int K;
void solve(int idx,vector<int>& nums,unordered_map<int,int>&mp){

  if(idx==nums.size()){
    res++;
    return;
  }
    solve(idx+1,nums,mp); //not take

    if(!mp[nums[idx]-K] && !mp[nums[idx]+K]){  //take
        mp[nums[idx]]++;
        solve(idx+1,nums,mp);
        mp[nums[idx]]--;
    }
}
    int beautifulSubsets(vector<int>& nums, int k) {
        res=0;
        K=k;
        unordered_map<int,int>mp;
        solve(0,nums,mp);
        return res-1; //excluding empty set
    }
};