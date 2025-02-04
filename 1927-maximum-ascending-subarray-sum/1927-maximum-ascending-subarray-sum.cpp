class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        vector<int>res(nums.size());
        res[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                res[i]=nums[i]+res[i-1];
            }else{
                res[i]=nums[i];
            }
        }
        return *max_element(res.begin(),res.end());
    }
};