class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
         int m=str1.size();
         int n=str2.size();
         int i=0,j=0;
         while(i<m && j<n){
            char temp=str1[i]+1;
            if(str1[i]=='z'){
              temp='a';
            }
            if(str1[i]==str2[j] || temp==str2[j]){
                j++;
            }
            i++;
        }
         if(j==n) return true;
         return false;
    }
};