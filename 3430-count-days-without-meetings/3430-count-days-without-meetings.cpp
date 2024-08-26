class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days; // If there are no meetings, all days are free
        
        // Sort meetings by starting day
        sort(meetings.begin(), meetings.end());
        
        int freeDays = 0;
        int currentEnd = 0;
        
        for (auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            
            // Count the days between the end of the last meeting and the start of the current one
            if (start > currentEnd) {
                freeDays += start - currentEnd - 1;
            }
            
            // Update the end of the current meeting range
            currentEnd = max(currentEnd, end);
        }
        
        // Count the days after the last meeting
        if (currentEnd < days) {
            freeDays += days - currentEnd;
        }
        
        return freeDays;
    }
};
