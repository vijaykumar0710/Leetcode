class Solution {
public:
int t[1001][1001];
int lcs(string &s1,string&s2,int m,int n){
    if(m==0 || n==0) return 0;
    if(t[m][n]!=-1) return t[m][n];
    if(s1[m-1]==s2[n-1]){
       return t[m][n]=1+lcs(s1,s2,m-1,n-1);
    }else{
      return t[m][n]=max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n));
    }
    return 0;
}
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        memset(t,-1,sizeof(t));
        return lcs(text1,text2,m,n);
    }
};