class Solution {
public:
int dfs(int i, int d, vector<int>& jobs, vector<vector<int>>& dp) {
    if (d == 0 && i == jobs.size()) return 0;
    if (d == 0 || i == jobs.size()) return 1e9;
    if (dp[i][d] != -1) return dp[i][d];

    int maxJob = 0, res = 1e9;

    for (int j = i; j <= jobs.size() - d; j++) {
        maxJob = max(maxJob, jobs[j]);
        res = min(res, maxJob + dfs(j + 1, d - 1, jobs, dp));
    }

    return dp[i][d] = res;
}
    int minDifficulty(vector<int>& jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if (n < d) return -1;
    vector<vector<int>> dp(n + 1, vector<int>(d + 1, -1));
    return dfs(0, d, jobDifficulty, dp);
    }
};