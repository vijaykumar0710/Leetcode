class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>t(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
           t[i][0]=i;
       }
     for(int j=1;j<=n;j++){
           t[0][j]=j;
       }
       int cost;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
         if(word1[i-1]==word2[j-1]){
            cost=0;
         }else{
            cost=1;
           }
            t[i][j]=min({t[i][j-1]+1,t[i-1][j]+1,t[i-1][j-1]+cost});
        }
    }
        return t[m][n];
    }
};