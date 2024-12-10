class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
    int maxLength = -1;

    // Iterate over all possible lengths of the special substring
    for (int len = 1; len <= n; ++len) {
        unordered_map<string, int> substringCount;

        // Iterate through all substrings of length 'len'
        for (int i = 0; i <= n - len; ++i) {
            string substr = s.substr(i, len);

            // Check if the substring is "special" (all characters are the same)
            if (substr == string(len, substr[0])) {
                substringCount[substr]++;
            }
        }

        // Check if any special substring appears at least 3 times
        for (auto& entry : substringCount) {
            if (entry.second >= 3) {
                maxLength = max(maxLength, len);
            }
        }
    }
    return maxLength;
    }
};