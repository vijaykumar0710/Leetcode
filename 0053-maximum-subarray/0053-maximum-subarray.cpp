class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int current_sum=nums[0];
        int max_sum=nums[0];
        for(int i=1;i<n;i++){
           current_sum=max(current_sum+nums[i],nums[i]);
           max_sum=max(max_sum,current_sum);
        }
        return max_sum;
    }
};