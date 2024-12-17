class Solution {
public:
    int m,n;
    int t[1001][1001];
    int solver(string &s1,string &s2,int i,int j){
        if(i>=m || j>=n) return 0;
        if(t[i][j]!=-1) return t[i][j];
        if(s1[i]==s2[j]){
            return t[i][j]=1+solver(s1,s2,i+1,j+1);
         }
            return t[i][j]=max(solver(s1,s2,i+1,j),solver(s1,s2,i,j+1));
      }
    int longestCommonSubsequence(string text1, string text2) {
         m=text1.size();
         n=text2.size();

        memset(t,-1,sizeof(t));
        return solver(text1,text2,0,0);
    }
};