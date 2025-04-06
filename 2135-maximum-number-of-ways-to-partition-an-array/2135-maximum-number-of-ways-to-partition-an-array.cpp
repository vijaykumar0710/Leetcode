class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        long long total = prefix[n - 1];
        unordered_map<long long, int> right, left;

        // Populate right with all prefix sums except full sum
        for (int i = 0; i < n - 1; ++i) {
            right[prefix[i]]++;
        }

        // Count ways with no change
        int maxWays = 0;
        if (total % 2 == 0) {
            maxWays = right[total / 2];
        }

        for (int i = 0; i < n; ++i) {
            long long delta = k - nums[i];
            long long newSum = total + delta;

            if (newSum % 2 == 0) {
                long long half = newSum / 2;
                int count = left[half] + right[half - delta];
                maxWays = max(maxWays, count);
            }

            // update maps as prefix[i] moves from right to left
            if (i < n - 1) {
                left[prefix[i]]++;
                right[prefix[i]]--;
            }
        }

        return maxWays;
    }
};