class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals based on the end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int lastEnd = intervals[0][1];

        // Traverse through intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < lastEnd) {
                // There's an overlap
                count++;
            } else {
                // No overlap, update the last end
                lastEnd = intervals[i][1];
            }
        }

        return count;
    }
};
