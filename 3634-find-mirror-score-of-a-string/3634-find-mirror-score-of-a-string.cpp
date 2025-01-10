class Solution {
public:
    long long calculateScore(string s) {
      int n = s.size();
        long long score = 0;
        unordered_map<char, vector<int>> unmarked;
        for (int i = 0; i < n; i++) {
            char mirrorChar = 'z' - (s[i] - 'a');
            if (!unmarked[mirrorChar].empty()) {
                int j = unmarked[mirrorChar].back();  
                unmarked[mirrorChar].pop_back(); 
                score += (i - j);
            } else {
                unmarked[s[i]].push_back(i);
            }
        }
        return score;
    }
};