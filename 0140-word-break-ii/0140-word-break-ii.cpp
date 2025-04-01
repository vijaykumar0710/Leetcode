class Solution {
public:
 bool isPresent(string &s, unordered_set<string>& st, int start, int i) {
        return st.find(s.substr(start, i - start + 1)) != st.end();
    }
    void solve(string &s, int start, unordered_set<string>& st, int n, vector<string>& curr, vector<vector<string>>& res) {
        if (start >= s.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = start; i < n; i++) {
            if (isPresent(s, st, start, i)) {
                curr.push_back(s.substr(start, i - start + 1));
                solve(s, i + 1, st, n, curr, res);
                curr.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<vector<string>> res;
        vector<string> curr;
        solve(s, 0, st, n, curr, res);

       vector<string>ans;
        for (auto &words : res) {
           string curr=words[0];
            for (int i=1;i<words.size();i++) {
            curr=curr+" "+words[i];
            }
            ans.push_back(curr);
        }
        return ans;
    } 
};