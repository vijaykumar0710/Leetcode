class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        //if(n==1) return 1;
        int i=n-1;
        int sum=0;
        while(s[i]!=' '|| sum==0){
         if(s[i]!=' ') sum+=1;
          i--;
          if(i<0) break;
        }
        return sum;
    }
};