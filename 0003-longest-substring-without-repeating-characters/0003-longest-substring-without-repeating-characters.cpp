class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int maxi = 0;
        
        while (j < s.length()) {
            if (mp.find(s[j]) != mp.end() && mp[s[j]] >= i) {
                i = mp[s[j]] + 1;
            }
            mp[s[j]] = j;
            maxi = max(maxi, j - i + 1);
            j++;
        }
        
        return maxi;
    }
};
