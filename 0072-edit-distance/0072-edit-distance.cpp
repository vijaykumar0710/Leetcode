class Solution {
public:
int m,n;
int t[501][501];
int solve(string &w1, string &w2,int m,int n){
    if(n==0 || m==0){
      return m+n;
    }
    if(t[m][n]!=-1) return t[m][n];
    if(w1[m-1]==w2[n-1]){
       return t[m][n]=solve(w1,w2,m-1,n-1);
    }else{
        int Insert=1+solve(w1,w2,m,n-1);
        int Delete=1+solve(w1,w2,m-1,n);
        int Replace=1+solve(w1,w2,m-1,n-1);
        return t[m][n]=min({Insert,Delete,Replace});
    }
    return -1; 
}
    int minDistance(string word1, string word2){
    m=word1.length();
    n=word2.length();
    memset(t,-1,sizeof(t));
    return solve(word1,word2,m,n);
    }
};