class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mid==0 && n==1) return nums[0];
            if(mid==0 && nums[mid]!=nums[mid+1]) return nums[0];
            if(mid==n-1 && nums[n-1]!=nums[n-2]) return nums[n-1];
            if(mid%2!=0) mid--;
            if(mid>0 && mid<n && nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid];
            else if(nums[mid]==nums[mid+1])
                 l=mid+2;
            else r=mid;
        }
        return -1;
    }
};