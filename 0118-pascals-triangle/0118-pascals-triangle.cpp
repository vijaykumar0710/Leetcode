class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        
        for(int i = 0; i < numRows; i++) {
            res[i].resize(i + 1);  // Resize the vector to hold i+1 elements
            res[i][0] = res[i][i] = 1;  // The first and last elements are always 1
            
            for(int j = 1; j < i; j++) {
                // Each element is the sum of the two elements above it
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        
        return res;
    }
};
