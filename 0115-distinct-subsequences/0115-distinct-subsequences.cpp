class Solution {
public:
int n,m;
int dp[1001][1001];
int solve(string &s,string &t,int idx,int j){
     if(j>=m){
        return 1;
    }
       if(idx>=n){
        return 0;
   }
   if(dp[idx][j]!=-1) return dp[idx][j];
   int ways=0;
    ways+=solve(s,t,idx+1,j);
    if(s[idx]==t[j]){
      ways+=solve(s,t,idx+1,j+1);
    }
    return dp[idx][j]=ways;
}
    int numDistinct(string s, string t) {
        n=s.size();
        m=t.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,t,0,0);
    }
};