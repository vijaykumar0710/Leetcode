class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Start from the top-right corner of the matrix
        int row = 0;
        int col = n - 1;
        
        // While we are within the bounds of the matrix
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true; // Found the target
            } else if (matrix[row][col] > target) {
                col--; // Move left
            } else {
                row++; // Move down
            }
        }
        
        return false; // Target not found
    }
};
