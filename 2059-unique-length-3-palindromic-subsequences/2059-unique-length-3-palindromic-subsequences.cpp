class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> prefix(26, 0), suffix(26, 0);
    for (char c : s) suffix[c - 'a']++;

    unordered_set<string> uniquePalindromes;
    for (int i = 0; i < s.size(); i++) {
        suffix[s[i] - 'a']--;
        for (int ch = 0; ch < 26; ch++) {
            if (prefix[ch] > 0 && suffix[ch] > 0) {
                string palindrome = string(1, 'a' + ch) + s[i] + string(1, 'a' + ch);
                uniquePalindromes.insert(palindrome);
            }
        }
        prefix[s[i] - 'a']++;
    }

    return uniquePalindromes.size();
    }
};