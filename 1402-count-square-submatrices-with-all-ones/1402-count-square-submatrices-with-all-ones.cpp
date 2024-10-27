class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int result=0;
        vector<vector<int>>t(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    t[i][j]=matrix[i][j];
                }else if(matrix[i][j]==1){
                    t[i][j]=1+min({t[i-1][j],t[i-1][j-1],t[i][j-1]});
                }
                result+=t[i][j];
            }
        }
        return result;
    }
};