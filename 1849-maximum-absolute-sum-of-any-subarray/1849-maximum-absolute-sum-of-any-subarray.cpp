class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int currSum=0,maxSum=INT_MIN;
        for(auto &num:nums){
            currSum+=num;
            maxSum=max(maxSum,currSum);
            if(currSum<0)
               currSum=0;
        }
        int curr=0,minSum=INT_MAX;
         for(auto &num:nums){
            curr+=num;
            minSum=min(minSum,curr);
            if(curr>0)
               curr=0;
        }
        return max(abs(minSum),abs(maxSum));
    }
};