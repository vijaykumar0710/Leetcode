class Solution {
public:
    // Function to compute all possible sums from the left half
    unordered_set<int> computeLeftSums(const vector<vector<int>>& mat, int mid) {
        unordered_set<int> sums = {0};

        for (int i = 0; i < mid; ++i) {
            unordered_set<int> temp;
            for (int val : mat[i]) {
                for (int sum : sums) {
                    temp.insert(sum + val);
                }
            }
            sums = move(temp);
        }

        return sums;
    }

    // Function to compute all possible sums from the right half
    unordered_set<int> computeRightSums(const vector<vector<int>>& mat, int mid, int m) {
        unordered_set<int> sums = {0};

        for (int i = mid; i < m; ++i) {
            unordered_set<int> temp;
            for (int val : mat[i]) {
                for (int sum : sums) {
                    temp.insert(sum + val);
                }
            }
            sums = move(temp);
        }

        return sums;
    }

    // Main function
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int mid = m / 2;

        // Get left and right half sums
        unordered_set<int> leftSet = computeLeftSums(mat, mid);
        unordered_set<int> rightSet = computeRightSums(mat, mid, m);

        // Convert right half to sorted vector for binary search
        vector<int> rightSums(rightSet.begin(), rightSet.end());
        sort(rightSums.begin(), rightSums.end());

        int ans = INT_MAX;

        // For each left sum, find the closest right sum using binary search
        for (int leftSum : leftSet) {
            int rem = target - leftSum;

            auto it = lower_bound(rightSums.begin(), rightSums.end(), rem);

            if (it != rightSums.end()) {
                ans = min(ans, abs(leftSum + *it - target));
            }
            if (it != rightSums.begin()) {
                --it;
                ans = min(ans, abs(leftSum + *it - target));
            }
        }

        return ans;
    }
};
