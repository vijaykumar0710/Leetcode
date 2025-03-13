class Solution {
public:
    int n;

    // Helper function to check if the first 'k' queries are enough to make nums a zero array
    bool check(vector<int>& nums, vector<vector<int>>& queries, int k) {
        // Create a difference array to apply range updates efficiently
        vector<unsigned long long> diffArr(n, 0);

        // Apply the first 'k' queries using difference array technique
        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            // Add 'val' at index 'l'
            diffArr[l] += val;

            // Subtract 'val' from index 'r+1' to limit the range
            if (r + 1 < n)
                diffArr[r + 1] -= val;
        }

        // Convert difference array into prefix sum to get actual decrements per index
        vector<unsigned long long> prefix(n, 0);
        prefix[0] = diffArr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + diffArr[i];
        }

        // Now check if all elements in nums can be reduced to 0
        // i.e., prefix[i] (total decrement at i) should be ≥ nums[i]
        for (int i = 0; i < n; i++) {
            if (prefix[i] < nums[i]) {
                return false; // not enough decrement at this index
            }
        }

        return true; // all elements can be reduced to zero
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size(); // store size globally for easy access

        // Binary search on the minimum number of queries needed
        int l = 0;
        int r = queries.size(); // we can try up to all queries
        int ans = -1; // default answer if not possible

        while (l <= r) {
            int mid = l + (r - l) / 2; // avoid overflow

            // Check if first 'mid' queries are enough
            if (check(nums, queries, mid)) {
                ans = mid; // update answer
                r = mid - 1; // try for a smaller k (minimum)
            } else {
                l = mid + 1; // try for a higher k
            }
        }

        return ans;
    }
};
