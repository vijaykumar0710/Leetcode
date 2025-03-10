class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
          if (nums[l] <= nums[r]) return nums[l];
            int mid=l+(r-l)/2;
            int prev=(mid+n-1)%n;
            int next=(mid+1)%n;
            if(nums[mid]<nums[prev] && nums[mid]<nums[next]){
                return nums[mid];
            }
            if(nums[mid]>=nums[l]){
                l=mid+1;
            }
           else if(nums[mid]<=nums[r]){
                r=mid-1;
            }
        }
        return -1;
    }
};