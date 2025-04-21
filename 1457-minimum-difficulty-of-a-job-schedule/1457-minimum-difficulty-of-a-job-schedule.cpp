class Solution {
public:
int t[301][11];
int dfs(int i, int d, vector<int>& jobs) {
    if (d == 0 && i == jobs.size()) return 0;
    if (d == 0 || i == jobs.size()) return 1e9;
    if (t[i][d] != -1) return t[i][d];

    int maxJob = 0, res = 1e9;

    for (int j = i; j <= jobs.size() - d; j++) {
        maxJob = max(maxJob, jobs[j]);
        res = min(res, maxJob + dfs(j + 1, d - 1, jobs));
    }

    return t[i][d] = res;
}
    int minDifficulty(vector<int>& jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if (n < d) return -1;
    memset(t,-1,sizeof(t));
    return dfs(0, d, jobDifficulty);
    }
};