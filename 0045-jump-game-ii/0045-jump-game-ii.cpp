class Solution {
public:
    int n;
    vector<int> memo;

    int minJumpsFromIndex(vector<int>& nums, int idx) {
        if (idx >= n - 1) return 0; // Reached or exceeded the last index
        
        if (memo[idx] != -1) return memo[idx]; // Return already computed result
        
        int minJumps = INT_MAX;
        
        for (int i = 1; i <= nums[idx]; i++) {
            if (idx + i < n) {
                int jumps = minJumpsFromIndex(nums, idx + i); // Recursively calculate jumps from the next index
                if (jumps != INT_MAX) { // Check if the next jump is valid
                    minJumps = min(minJumps, 1 + jumps); // Update minimum jumps
                }
            }
        }
        
        memo[idx] = minJumps; // Store the result in memo to avoid re-computation
        return minJumps;
    }

    int jump(vector<int>& nums) {
        n = nums.size();
        memo.resize(n, -1); // Initialize memoization array with -1
        return minJumpsFromIndex(nums, 0); // Start from the first index
    }
};
