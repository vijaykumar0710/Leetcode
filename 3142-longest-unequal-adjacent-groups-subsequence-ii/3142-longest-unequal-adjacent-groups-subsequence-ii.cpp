class Solution {
public:
    int n;
    vector<string> words;
    vector<int> groups;
    // dp[i][j] = max length from i with last chosen index = j-1 (so j=0 means lastIdx=-1)
    vector<vector<int>> dp;

    bool isValid(int lastIdx, const string& w) {
        if (lastIdx == -1) return true;
        const string& last = words[lastIdx];
        if (last.size() != w.size()) return false;
        int diff = 0;
        for (int k = 0; k < last.size(); ++k)
            if (last[k] != w[k] && ++diff > 1)
                return false;
        return true;
    }

    int dfs(int i, int lastIdx) {
        if (i == n) return 0;
        int &ans = dp[i][lastIdx+1];
        if (ans != -1) return ans;

        // 1) skip
        ans = dfs(i+1, lastIdx);

        // 2) take?
        if (groups[i] != (lastIdx == -1 ? -1 : groups[lastIdx])
            && isValid(lastIdx, words[i])) {
            ans = max(ans, 1 + dfs(i+1, i));
        }
        return ans;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& _words,
                                                vector<int>& _groups) {
        words = _words;
        groups = _groups;
        n = words.size();
        dp.assign(n+1, vector<int>(n+1, -1));

        // fill dp
        dfs(0, -1);

        // reconstruct
        vector<string> res;
        int i = 0, lastIdx = -1;
        while (i < n) {
            int skip = dfs(i+1, lastIdx);
            int take = 0;
            if (groups[i] != (lastIdx == -1 ? -1 : groups[lastIdx])
                && isValid(lastIdx, words[i])) {
                take = 1 + dfs(i+1, i);
            }
            if (take > skip) {
                res.push_back(words[i]);
                lastIdx = i;
                ++i;
            } else {
                ++i;
            }
        }
        return res;
    }
};
