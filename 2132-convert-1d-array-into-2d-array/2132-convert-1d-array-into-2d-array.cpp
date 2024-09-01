class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int oriSize=original.size();
        if(m*n!=oriSize) return {};
        vector<vector<int>>grid(m,vector<int>(n,0));
        int idx=0;
           while(idx<=n-1)
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                     grid[i][j]=original[idx];
                    idx++;
                }
            }
            return grid;
    }
};