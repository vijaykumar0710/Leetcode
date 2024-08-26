class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        
        int sum = 0;
        int lastEnd = 0;
        for (int i = 0; i < n; i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            if (start > lastEnd) {
                sum += (end - start + 1);
                lastEnd = end;
            } else if (end > lastEnd) {
                sum += (end - lastEnd);
                lastEnd = end;
            }
        }
        return days - sum;
    }
};
