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
        for(int i=0;i<n-1;i++){
            if(isPalindrome(s,0,i)){
                for(int j=i+1;j<n-1;j++){
                    if(isPalindrome(s,i+1,j) && (isPalindrome(s,j+1,n-1))){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};