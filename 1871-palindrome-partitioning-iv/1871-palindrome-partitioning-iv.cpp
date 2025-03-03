class Solution {
public:
  bool isPalindrome(string &s,int i,int j){
     while(i<j){
       if(s[i]!=s[j]){
        return false;
       }
       i++;
       j--;
     }
      return true;
  }
    bool checkPartitioning(string s) {
        int n=s.length();
         for (int i = 1; i < n - 1; i++) {  // First cut
            if (isPalindrome(s, 0, i - 1)) {
                for (int j = i; j < n - 1; j++) {  // Second cut
                    if (isPalindrome(s, i, j) && isPalindrome(s, j + 1, n - 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};