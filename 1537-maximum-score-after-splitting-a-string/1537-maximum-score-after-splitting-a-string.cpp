class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        
        // Initialize prefix sum of zeros and suffix sum of ones
        int prefix_zeros = 0, suffix_ones = 0;

        // Calculate the total number of ones in the string (for initial suffix sum)
        for (char c : s) {
            if (c == '1') {
                suffix_ones++;
            }
        }

        int maxi = 0;

        // Iterate through the string up to n-1 (split point cannot be the last character)
        for (int i = 0; i < n - 1; i++) {
            // Update prefix sum of zeros
            if (s[i] == '0') {
                prefix_zeros++;
            }
            
            // Update suffix sum of ones
            if (s[i] == '1') {
                suffix_ones--;
            }

            // Calculate the score and update the maximum
            maxi = max(maxi, prefix_zeros + suffix_ones);
        }

        return maxi;
    }
};
