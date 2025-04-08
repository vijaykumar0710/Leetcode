class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Subset sums grouped by element count
        vector<vector<int>> leftSums(half + 1), rightSums(half + 1);

        // Generate all subset sums for left half
        for (int mask = 0; mask < (1 << half); ++mask) {
            int sum = 0, count = 0;
            for (int j = 0; j < half; ++j) {
                if (mask & (1 << j)) {
                    sum += nums[j];
                    count++;
                }
            }
            leftSums[count].push_back(sum);
        }

        // Generate all subset sums for right half
        for (int mask = 0; mask < (1 << (n - half)); ++mask) {
            int sum = 0, count = 0;
            for (int j = 0; j < (n - half); ++j) {
                if (mask & (1 << j)) {
                    sum += nums[half + j];
                    count++;
                }
            }
            rightSums[count].push_back(sum);
        }

        for (int i = 0; i <= half; ++i) {
            sort(rightSums[i].begin(), rightSums[i].end());
        }

        int res = INT_MAX;

        // Try combining i elements from left with (half - i) from right
        for (int i = 0; i <= half; ++i) {
            for (int lSum : leftSums[i]) {
                int rCount = half - i;
                const auto& rVec = rightSums[rCount];

                int target = totalSum / 2 - lSum;

                // Binary search to find closest rSum
                auto it = lower_bound(rVec.begin(), rVec.end(), target);
                
                // check it and previous (if exists)
                if (it != rVec.end()) {
                    int pickedSum = lSum + *it;
                    int otherSum = totalSum - pickedSum;
                    res = min(res, abs(pickedSum - otherSum));
                }
                if (it != rVec.begin()) {
                    --it;
                    int pickedSum = lSum + *it;
                    int otherSum = totalSum - pickedSum;
                    res = min(res, abs(pickedSum - otherSum));
                }
            }
        }

        return res;
    }
};
