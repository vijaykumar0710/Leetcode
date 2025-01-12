class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false; // Odd length cannot be valid
        
        int open = 0, flexible = 0;
        
        // Left to right pass
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0') {
                flexible++; // Flexible character
            } else if (s[i] == '(') {
                open++; // Open parenthesis
            } else { // s[i] == ')'
                if (open > 0) {
                    open--; // Match with an open parenthesis
                } else if (flexible > 0) {
                    flexible--; // Use a flexible character
                } else {
                    return false; // No match available
                }
            }
        }

        // Reset for right to left pass
        open = 0, flexible = 0;

        // Right to left pass
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '0') {
                flexible++; // Flexible character
            } else if (s[i] == ')') {
                open++; // Close parenthesis
            } else { // s[i] == '('
                if (open > 0) {
                    open--; // Match with a close parenthesis
                } else if (flexible > 0) {
                    flexible--; // Use a flexible character
                } else {
                    return false; // No match available
                }
            }
        }

        return true;
    }
};
