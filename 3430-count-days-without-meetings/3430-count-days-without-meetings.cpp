class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        if(n == 0) return days;
        sort(meetings.begin(), meetings.end());
        // Step 2: Count total meeting days (including overlaps)
        long long  totalDays = 0;
        for(auto &meeting : meetings) {
            totalDays += (meeting[1] - meeting[0] + 1);
        }
        // Step 3: Count overlapping days and subtract
        long long overlap = 0;
        long long prevEnd = meetings[0][1];
        for(int i = 1; i < n; i++) {
            long long currStart = meetings[i][0];
            long long currEnd = meetings[i][1];

            if(currStart <= prevEnd) {
                // Calculate the actual overlapping portion
                overlap += min(prevEnd, currEnd) - currStart + 1;
                // Update prevEnd to the maximum end so far (to handle chain overlaps)
                prevEnd = max(prevEnd, currEnd);
            } else {
                // No overlap
                prevEnd = currEnd;
            }
        }

        // Subtract overlapping days to get distinct meeting days
        long long actualMeetingDays = totalDays - overlap;

        return days - actualMeetingDays;
    }
};
