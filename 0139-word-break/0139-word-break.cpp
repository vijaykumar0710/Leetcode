class Solution {
public:
int t[301];
    bool isPresent(string &s, unordered_set<string> &st, int start, int i) {
        string str = s.substr(start, i - start + 1);
        return st.find(str) != st.end();
    }

    bool solve(string &s, int start, unordered_set<string> &st, int n, vector<string> &curr) {
        if (start >= s.size()) {
            return true;
        }
       if(t[start]!=-1) return t[start];
        for (int i = start; i < n; i++) {
            if (isPresent(s, st, start, i)) {
                curr.push_back(s.substr(start, i - start + 1));
                if (solve(s, i + 1, st, n, curr)) {
                    return t[start]=true;
                }
                curr.pop_back(); // Backtrack
            }
        }
        return t[start]=false;
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<string> curr;
        memset(t,-1,sizeof(t));
        return solve(s, 0, st, n, curr);
    }
};
