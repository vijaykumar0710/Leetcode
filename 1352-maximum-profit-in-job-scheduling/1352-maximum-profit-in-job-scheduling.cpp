class Solution {
public:
    int jobScheduling(vector<int>& startTime,vector<int>& endTime,vector<int>& profit) {
        int n = startTime.size();
        vector<pair<int,pair<int,int>>>jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({profit[i], {startTime[i], endTime[i]}});
        }
        sort(jobs.begin(),jobs.end(), [](auto& a, auto& b) {
            return a.second.second < b.second.second;
        });
       vector<int> dp(n + 1, 0);
       for (int i = 1; i <= n; ++i) {
            int currentProfit = jobs[i - 1].first;
            int currentStart = jobs[i - 1].second.first;
            int left = 0, right = i - 1;
            int latestNonConflictJobIndex = 0;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (jobs[mid].second.second <= currentStart) {
                    latestNonConflictJobIndex = mid + 1;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            dp[i] =max(dp[i - 1], dp[latestNonConflictJobIndex] + currentProfit);
        }
        return dp[n];
    }
};