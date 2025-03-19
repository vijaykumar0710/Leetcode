class Solution {
public:
    int minOperations(vector<int>& nums) {
    int n = nums.size();
    int ops = 0;

    for (int i = 0; i <= n - 3; i++) {
        if (nums[i] == 0) {
            nums[i] ^= 1;
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
            ops++;
        }
    }
    for (int i = n - 2; i < n; i++) {
        if (i >= 0 && nums[i] == 0)
            return -1;
    }

    return ops;
    }
};