class Solution {
public:
int countSubsets(int idx,int currOr,vector<int>&nums,int maxim,vector<vector<int>>&t){
    if(idx==nums.size()){
        if(currOr==maxim) return 1;
        return 0;
    }
    if(t[idx][currOr]!=-1) return t[idx][currOr];
    int take=countSubsets(idx+1,currOr | nums[idx],nums,maxim,t);
    int notTake=countSubsets(idx+1,currOr,nums,maxim,t);

    return t[idx][currOr]=take+notTake;
}
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int maxim=nums[0];
        for(auto &num:nums){
          maxim=(maxim | num);
        }
       int currOr=0;
       vector<vector<int>> t(n+1,vector<int>(maxim+1,-1));
        return countSubsets(0,currOr,nums,maxim,t);
    }
};