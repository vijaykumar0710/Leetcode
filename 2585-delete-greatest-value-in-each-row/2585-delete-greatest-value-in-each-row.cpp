class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int sum = 0;
        
        // Sort each row in descending order
        for (auto &row:grid) {
            sort(row.begin(), row.end(), greater<int>());
        }
        
        // Add the greatest values in each column
        for (int j = 0; j < n; j++) {
            int maxVal = 0;
            for (int i = 0; i < m; i++) {
                maxVal = max(maxVal, grid[i][j]);
            }
            sum += maxVal;
        }
        
        return sum;
    }
};
