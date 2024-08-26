class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days; 
        
        sort(meetings.begin(), meetings.end());
        
        int freeDays = 0;
        int currentEnd = 0;
        
        for (auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            if (start > currentEnd) {
                freeDays += start - currentEnd - 1;
            }
            currentEnd = max(currentEnd, end);
        }
        if (currentEnd < days) {
            freeDays += days - currentEnd;
        }
        return freeDays;
    }
};
