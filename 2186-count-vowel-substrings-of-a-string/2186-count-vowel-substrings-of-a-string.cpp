class Solution {
public:
    bool isVowel(char x) {
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    } 
    int countVowelSubstrings(string word) {
        int n = word.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!isVowel(word[i])) continue;
            unordered_map<char, int> freq;
            for (int j = i; j < n && isVowel(word[j]); ++j) {
                freq[word[j]]++;
                if (freq.size() == 5) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
