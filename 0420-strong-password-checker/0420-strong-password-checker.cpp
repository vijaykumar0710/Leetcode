class Solution {
public:
    int strongPasswordChecker(string s) {
    int n = s.length();
    bool hasLower = false, hasUpper = false, hasDigit = false;

    // Check for lowercase, uppercase, and digit presence
    for (char c : s) {
        if (islower(c)) hasLower = true;
        else if (isupper(c)) hasUpper = true;
        else if (isdigit(c)) hasDigit = true;
    }

    int categories = hasLower + hasUpper + hasDigit;

    if (n < 6) {
        // If length is less than 6, we need to insert characters
        return max(6 - n, 3 - categories);
    } else if (n <= 20) {
        // If length is between 6 and 20, we only need replacements
        int replace = 0;
        int cnt = 2;

        // Count sequences of repeating characters
        for (int i = 2; i < n; i++) {
            if (s[i] == s[i-1] && s[i-1] == s[i-2]) {
                replace++;
                i += 2;
            }
        }

        return max(replace, 3 - categories);
    } else {
        // If length is greater than 20, we need to delete characters
        int deleteCount = n - 20;
        int replace = 0;
        vector<int> delMod(3, 0); // delMod[0]: %3==0, delMod[1]: %3==1, delMod[2]: %3==2
        
        for (int i = 2; i < n; i++) {
            if (s[i] == s[i-1] && s[i-1] == s[i-2]) {
                int len = 2;
                while (i < n && s[i] == s[i-1]) {
                    len++;
                    i++;
                }
                replace += len / 3;
                delMod[len % 3]++;
            }
        }

        // Apply deletions
        if (deleteCount <= delMod[0]) {
            replace -= deleteCount;
        } else if (deleteCount <= delMod[0] + 2 * delMod[1]) {
            replace -= delMod[0] + (deleteCount - delMod[0]) / 2;
        } else {
            replace -= delMod[0] + delMod[1] + (deleteCount - delMod[0] - 2 * delMod[1]) / 3;
        }

        return deleteCount + max(replace, 3 - categories);
    }
    }
};