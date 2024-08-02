class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int oneCount = 0;

        // Count the number of 1's in the array
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) oneCount++;
        }

        // If there are no 1's or all are 1's, no swaps needed
        if (oneCount == 0 || oneCount == n) return 0;

        // Initial window setup
        int currentOnes = 0;
        for (int i = 0; i < oneCount; i++) {
            if (nums[i] == 1) currentOnes++;
        }

        // We want to maximize the number of 1's in any window of size 'oneCount'
        int maxOnesInWindow = currentOnes;

        // Sliding window to find the max number of 1's in any window of size 'oneCount'
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] == 1) currentOnes--;
            if (nums[(i + oneCount - 1) % n] == 1) currentOnes++;
            maxOnesInWindow = max(maxOnesInWindow, currentOnes);
        }

        // Minimum swaps required is the difference between 'oneCount' and 'maxOnesInWindow'
        return oneCount - maxOnesInWindow;
    }
};
