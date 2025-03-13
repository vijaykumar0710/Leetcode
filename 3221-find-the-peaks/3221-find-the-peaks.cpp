class Solution {
public:
    vector<int> findPeaks(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
               res.push_back(i) ;
            }
        }
        return res;
    }
};