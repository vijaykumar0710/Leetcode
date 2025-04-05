class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        long long totalSum=prefix[n-1];

        // Initial partition count without any change
        unordered_map<long long, int> right;
        for (int i = 0; i < n - 1; ++i) {
            right[prefix[i]]++;
        }

        int maxWays = 0;
        if (totalSum % 2 == 0) {
            maxWays = right[totalSum / 2];
        }

        unordered_map<long long, int> left;

        // Try changing nums[i] to k
        for (int i = 0; i < n; ++i) {
            long long delta = (long long)k - nums[i];
            long long newTotal = totalSum + delta;

            if (newTotal % 2 == 0) {
                long long newTarget = newTotal / 2;
                int ways = 0;

                // Left unaffected
                ways += left[newTarget];

                // Right affected by delta
                ways += right[newTarget - delta];

                maxWays = max(maxWays, ways);
            }

            // Shift prefix[i] from right to left if not at last index
            if (i < n - 1) {
                right[prefix[i]]--;
                left[prefix[i]]++;
            }
        }

        return maxWays;
    }
};
