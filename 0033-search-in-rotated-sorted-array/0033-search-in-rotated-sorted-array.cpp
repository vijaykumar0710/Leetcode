class Solution {
public:
    int findPivot(vector<int>& nums){
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
             if (nums[l] <= nums[r]) return l;
            // Handle edge cases safely
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;

            if (nums[mid] < nums[prev] && nums[mid] < nums[next])
                return mid;
            else if (nums[mid] >= nums[l])
                l = mid + 1;
            else if(nums[mid]<=nums[r])
                r = mid - 1;
        }
        return -1;  // Fallback
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivotIdx = findPivot(nums);
        if(nums[pivotIdx]==target) return pivotIdx;
        int idx = -1;

        // First part: from 0 to pivotIdx - 1
        auto lo1 = lower_bound(nums.begin(), nums.begin() + pivotIdx, target);
        if (lo1 != nums.begin() + pivotIdx && *lo1 == target) {
            idx = lo1 - nums.begin();
        }

        // Second part: from pivotIdx to n - 1
        if (idx == -1) {
            auto lo2 = lower_bound(nums.begin() + pivotIdx+1, nums.end(), target);
            if (lo2 != nums.end() && *lo2 == target) {
                idx = lo2 - nums.begin();
            }
        }

        return idx;
    }
};
