class Solution {
public:
    int helper(string& s, int k, int start, int end) {
        if (end - start < k) return 0;

        unordered_map<char, int> freq;
        for (int i = start; i < end; i++) {
            freq[s[i]]++;
        }

        for (int i = start; i < end; i++) {
            if (freq[s[i]] < k) {
                return max(helper(s, k, start, i), helper(s, k, i + 1, end));
            }
        }

        return end - start;
    }

    int longestSubstring(string s, int k) {
        return helper(s, k, 0, s.size());
    }
};
