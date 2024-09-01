class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        if(original.size()!=m*n) return {};
        for(int i=0;i<original.size();i++){
            int row=i/n;
            int col=i%n;
            grid[row][col]=original[i];
        }
        return grid;
    }
};