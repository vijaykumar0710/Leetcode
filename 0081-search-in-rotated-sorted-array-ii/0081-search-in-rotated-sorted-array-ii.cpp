class Solution {
public:
int findPivot(vector<int>& nums){
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l < r) {
            while(l<r && nums[l]==nums[l+1]) l++;
            while(l<r && nums[r]==nums[r-1]) r--;
            int mid = l + (r - l) / 2;
             if(nums[mid]>nums[r]){
                l=mid+1;
             }else{
                r=mid;
             }
        }
             return r;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivotIdx = findPivot(nums);
        cout<<pivotIdx;
        if(nums[pivotIdx]==target) return true;
        int idx = -1;

        auto lo1 = lower_bound(nums.begin(), nums.begin() + pivotIdx, target);
        if (lo1 != nums.begin() + pivotIdx && *lo1 == target) {
            idx = lo1 - nums.begin();
        }

        if (idx == -1) {
            auto lo2 = lower_bound(nums.begin() + pivotIdx+1, nums.end(), target);
            if (lo2 != nums.end() && *lo2 == target) {
                idx = lo2 - nums.begin();
            }
        }

        if(idx==-1) return false;
        return true;
    }
};