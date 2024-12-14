class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;

        // Min-heap to store pairs with their sums
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;

        // Push the first pair of elements from nums1 and nums2
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            minHeap.push({nums1[i] + nums2[0], {i, 0}});
        }

        // Extract k smallest pairs
        while (k-- > 0 && !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();

            int i = top.second.first;  // Index in nums1
            int j = top.second.second;  // Index in nums2

            // Add the smallest pair to the result
            res.push_back({nums1[i], nums2[j]});

            // If there are more pairs with nums2[j+1], push them into the heap
            if (j + 1 < nums2.size()) {
                minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return res;
    }
};