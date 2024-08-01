class Solution {
public:
 int lengthOfLongestSubstring(string s) {
 unordered_map<char, int> seen;
 int ret = 0, slow = 0, n = s.size();
 for (int fast = 0; fast < n; ++fast) {
 if (seen.count(s[fast]) != 0) slow = max(slow, seen[s[fast]] + 1);
 seen[s[fast]] = fast;
 ret = max(ret, fast - slow + 1);
 }
 return ret;
 }
};