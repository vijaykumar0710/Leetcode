class Solution {
public:
int countSubsets(int idx,int currOr,vector<int>&nums,int maxim){
    if(idx==nums.size()){
        if(currOr==maxim) return 1;
        return 0;
    }
    int take=countSubsets(idx+1,currOr | nums[idx],nums,maxim);
    int notTake=countSubsets(idx+1,currOr,nums,maxim);

    return take+notTake;
}
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int maxim=nums[0];
        for(auto &num:nums){
          maxim=(maxim | num);
        }
       int currOr=0;
        return countSubsets(0,currOr,nums,maxim);
    }
};