class Solution {
public:
int m,n;
int t[1001][1001];
int solve(string& s1, string& s2,int i,int j){
      if(i>=m || j>=n) return 0;
      if(t[i][j]!=-1) return t[i][j];
      
      if(s1[i]==s2[j]){
      return t[i][j]=1+solve(s1,s2,i+1,j+1);
    } 
        return t[i][j]=max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
    
}
    int longestCommonSubsequence(string s1, string s2) {
        m=s1.length();
        n=s2.length();
         memset(t,-1,sizeof(t));
      return solve(s1,s2,0,0);
    }
};