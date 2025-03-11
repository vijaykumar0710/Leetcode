class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(nums[n-1]<target) return n;
        if(nums[0]>target) return 0;
        int l=0,r=n-1;
        int res;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(target>nums[mid]){
                res=mid+1;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return res;
    }
};