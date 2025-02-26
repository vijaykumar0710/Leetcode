class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currSum=0,maxSum=INT_MIN;
        for(auto &num:nums){
            currSum+=num;
            maxSum=max(maxSum,currSum);
            if(currSum<0)
               currSum=0;
        }
        return maxSum;
    }
};