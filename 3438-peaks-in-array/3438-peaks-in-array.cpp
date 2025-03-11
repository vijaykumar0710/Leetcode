class Solution {
public:
    // Compute whether index i is a peak.
    // For this problem, the first and last element of the entire array cannot be a peak.
    int computePeak(int i, vector<int>& nums) {
        int n = nums.size();
        if(i == 0 || i == n - 1)
            return 0;
        return (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) ? 1 : 0;
    }
    
    // Build segment tree on isPeak vector.
    // 'i' is the current tree node index, and [l, r] is the segment in the array.
    void buildSegTree(int i, int l, int r, vector<int>& segTree, vector<int>& isPeak) {
        if(l == r) {
            segTree[i] = isPeak[r];
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegTree(2 * i + 1, l, mid, segTree, isPeak);
        buildSegTree(2 * i + 2, mid + 1, r, segTree, isPeak);
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }
    
    // Update segment tree for position 'pos' with new value 'val'
    void updateSegTree(int pos, int val, int i, int l, int r, vector<int>& segTree) {
        if(l == r) {
            segTree[i] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if(pos <= mid)
            updateSegTree(pos, val, 2 * i + 1, l, mid, segTree);
        else
            updateSegTree(pos, val, 2 * i + 2, mid + 1, r, segTree);
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }
    
    // Query the segment tree for the sum (i.e., count of peaks) in range [start+1, end-1]
    int countPeak(int start, int end, int i, int l, int r, vector<int>& segTree) {
        // No valid peak if subarray length is too small
        if(end - start <= 1)
            return 0;
        // Adjust the query boundaries to skip the first and last element of the subarray.
        int ql = start + 1;
        int qr = end - 1;
        
        if(l > qr || r < ql)
            return 0; // no overlap
        if(ql <= l && r <= qr)
            return segTree[i]; // total overlap
        
        int mid = l + (r - l) / 2;
        return countPeak(start, end, 2 * i + 1, l, mid, segTree) +
               countPeak(start, end, 2 * i + 2, mid + 1, r, segTree);
    }
    
    // Main function to process queries.
    // Query type 2 is an update: [2, index, value]
    // Query type 1 is to count peaks: [1, start, end]
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> isPeak(n, 0);
        // Build isPeak array using computePeak.
        for (int i = 0; i < n; i++) {
            isPeak[i] = computePeak(i, nums);
        }
        
        // Build segment tree (size 4*n is sufficient)
        vector<int> segTree(4 * n, 0);
        buildSegTree(0, 0, n - 1, segTree, isPeak);
        
        vector<int> res;
        // Process each query.
        for(auto &query : queries) {
            int type = query[0];
            if(type == 2) {  // Update query
                int idx = query[1], val = query[2];
                nums[idx] = val;
                // Only indices idx-1, idx, and idx+1 can be affected.
                for (int j = idx - 1; j <= idx + 1; j++) {
                    if(j >= 0 && j < n) {
                        int newPeak = computePeak(j, nums);
                        if(isPeak[j] != newPeak) {
                            isPeak[j] = newPeak;
                            updateSegTree(j, newPeak, 0, 0, n - 1, segTree);
                        }
                    }
                }
            } else {  // Count peaks query
                int start = query[1], end = query[2];
                res.push_back(countPeak(start, end, 0, 0, n - 1, segTree));
            }
        }
        return res;
    }
};
