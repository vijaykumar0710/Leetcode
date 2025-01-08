class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<pair<int,int>>vec;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 if(matrix[i][j]==0){
                    vec.push_back({i,j});
                 }
            }
        }
    for(auto idx:vec){
            for(int j=0;j<n;j++){
                matrix[idx.first][j]=0;
        }
            for(int i=0;i<m;i++){
                matrix[i][idx.second]=0;
        }
      }
    }
};