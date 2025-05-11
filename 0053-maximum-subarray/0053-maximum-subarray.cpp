class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>vec(n);
        vec[0]=nums[0];
        int maxi=vec[0];
        for(int i=1;i<n;i++){
            vec[i]=max(nums[i],vec[i-1]+nums[i]);
            maxi=max(maxi,vec[i]);
        }
        return maxi;
    }
};