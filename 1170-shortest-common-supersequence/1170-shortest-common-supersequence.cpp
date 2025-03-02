class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
         int m=s1.length();
       int  n=s2.length();
      vector<vector<int>> t(m+1,vector<int>(n+1,0));
     for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(s1[i-1]==s2[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
      }
      string scs="";
      int i=m,j=n;
      while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            scs+=s1[i-1];
            i--;
            j--;
        }else{
            if(t[i-1][j]>t[i][j-1]){
                scs+=s1[i-1];
                i--;
            }else{
                scs+=s2[j-1];
                j--;
            }
        }
      }
      while(i>0){
        scs+=s1[i-1];
          i--;
      }
      while(j>0){
        scs+=s2[j-1];
          j--;
      }
      reverse(begin(scs),end(scs));
     return scs;
    }
};