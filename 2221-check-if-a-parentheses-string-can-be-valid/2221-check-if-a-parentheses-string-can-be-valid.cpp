class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false;  
        int open = 0, locker = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++; 
            } else if (locked[i]=='0') {
                locker++; 
            } else { 
                if (open > 0) {
                    open--; 
                } else if (locker > 0) {
                    locker--;
                } else {
                    return false; 
                }
            } 
        }
        int close = 0, locker_back = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') {
                close++; 
            } else if (locked[i]=='0') {
                locker_back++; 
            } else { 
                if (close > 0) {
                    close--; 
                } else if (locker_back > 0) {
                    locker_back--; 
                } else {
                    return false; 
                }
            }
        }
        return true;
    }
};
