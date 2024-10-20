class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.length();
        int totalSubstrings = 0;

        // For each starting point of the substring
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);  // Frequency array for the current window
            
            // Expand the window to cover substrings starting at i
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;  // Increase the count of the current character
                
                // Check if any character in the current substring occurs at least k times
                bool valid = false;
                for (int c = 0; c < 26; c++) {
                    if (freq[c] >= k) {
                        valid = true;
                        break;
                    }
                }
                
                // If valid, this substring satisfies the condition
                if (valid) {
                    totalSubstrings++;
                }
            }
        }

        return totalSubstrings;
    }
};

