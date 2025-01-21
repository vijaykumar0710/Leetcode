class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>LIS;
        LIS.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>LIS.back()){
                LIS.push_back(nums[i]);
            }else{
                int idx=lower_bound(LIS.begin(),LIS.end(),nums[i])-LIS.begin();
                LIS[idx]=nums[i];
            }
        }
        return LIS.size();
    }
};