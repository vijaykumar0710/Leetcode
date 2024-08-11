class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        int l = 0, r = n - 1;

        // Step 1: Find the pivot (smallest element in the rotated array)
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        int pivot = l; // 'l' now points to the pivot
        l = 0, r = n - 1;

        // Step 2: Perform binary search considering the rotation
        if (target >= nums[pivot] && target <= nums[r]) {
            l = pivot; // Search in the right side of the pivot
        } else {
            r = pivot - 1; // Search in the left side of the pivot
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return -1; // Target not found
    }
};
