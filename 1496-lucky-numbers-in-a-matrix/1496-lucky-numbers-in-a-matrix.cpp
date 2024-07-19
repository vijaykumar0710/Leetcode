class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        
        for(int i = 0; i < m; i++) {
            // Find the minimum element in the ith row
            int minRow = matrix[i][0];
            int colIndex = 0;
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] < minRow) {
                    minRow = matrix[i][j];
                    colIndex = j;
                }
            }
            
            // Check if the minimum element in the ith row is the maximum in its column
            bool isLucky = true;
            for(int k = 0; k < m; k++) {
                if(matrix[k][colIndex] > minRow) {
                    isLucky = false;
                    break;
                }
            }
            
            if(isLucky) {
                result.push_back(minRow);
            }
        }
        
        return result;
    }
};
