class Solution {
public:
    // Function to generate all subset sums grouped by number of elements chosen
    void generateGroupedSums(vector<int>& arr, unordered_map<int, vector<int>>& grouped) {
        int n = arr.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0;
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += arr[i];
                    count++;
                }
            }
            grouped[count].push_back(sum);
        }
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int half = n / 2;

        vector<int> left(nums.begin(), nums.begin() + half);
        vector<int> right(nums.begin() + half, nums.end());

        unordered_map<int, vector<int>> leftGrouped, rightGrouped;
        generateGroupedSums(left, leftGrouped);
        generateGroupedSums(right, rightGrouped);

        // Sort all vectors in rightGrouped for binary search
        for (auto& [_, vec] : rightGrouped) {
            sort(vec.begin(), vec.end());
        }

        int res = INT_MAX;

        // Try all combinations of picking i from left and (half - i) from right
        for (int i = 0; i <= half; i++) {
            const auto& leftSums = leftGrouped[i];
            const auto& rightSums = rightGrouped[half - i];

            for (int l : leftSums) {
                int remaining = totalSum / 2 - l;

                auto it = lower_bound(rightSums.begin(), rightSums.end(), remaining);

                if (it != rightSums.end()) {
                    int s = l + *it;
                    int diff = abs(totalSum - 2 * s);
                    res = min(res, diff);
                }
                if (it != rightSums.begin()) {
                    --it;
                    int s = l + *it;
                    int diff = abs(totalSum - 2 * s);
                    res = min(res, diff);
                }
            }
        }
        return res;
    }
};
