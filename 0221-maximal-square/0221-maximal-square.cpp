class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int j=0;j<n;j++) dp[0][j]=matrix[0][j]=='0'?0:1;
        for(int i=0;i<m;i++) dp[i][0]=matrix[i][0]=='0'?0:1;
         
         int maxSquareSide=0;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='1'){
                   dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxSquareSide=max(maxSquareSide,dp[i][j]);
            }
        }
         return maxSquareSide*maxSquareSide;
    }
};