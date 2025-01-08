class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 if(matrix[i][j]==0){
                    for(int k=0;k<n;k++){
                       if(matrix[i][k]!=0)matrix[i][k]=2e9;
                    }
                    for(int v=0;v<m;v++){
                        if(matrix[v][j]!=0)matrix[v][j]=2e9;
                    }
                 }
            }
        }
       for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 if(matrix[i][j]==2e9){
                    matrix[i][j]=0;
                 }
            }
        }
    }
};