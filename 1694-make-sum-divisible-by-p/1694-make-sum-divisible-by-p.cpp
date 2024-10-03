class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int totalSum = 0;

        // Calculate total sum of the array
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }
        
        if (totalSum == 0) return 0;  // If the total sum is already divisible by p

        int targetMod = totalSum;  // We need to remove a subarray with this sum mod p
        unordered_map<int, int> prefixModIndex;
        prefixModIndex[0] = -1;  // Initialize with a base case
        
        int currMod = 0;
        int minLength = n;

        for (int i = 0; i < n; ++i) {
            currMod = (currMod + nums[i]) % p;

            // Calculate required mod to remove from prefix to make remaining sum divisible by p
            int requiredMod = (currMod - targetMod + p) % p;

            if (prefixModIndex.find(requiredMod) != prefixModIndex.end()) {
                minLength = min(minLength, i - prefixModIndex[requiredMod]);
            }
            
            // Store the current mod and its index
            prefixModIndex[currMod] = i;
        }

        // If minLength is n, no valid subarray found, return -1
        return (minLength == n) ? -1 : minLength;
    }
};
