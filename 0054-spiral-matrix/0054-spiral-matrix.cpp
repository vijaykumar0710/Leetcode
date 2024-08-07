class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
       
        int minr = 0, maxr = m - 1, minc = 0, maxc = n - 1;
        vector<int> res;
        while(minr <= maxr && minc <= maxc) {
            // Right
            if(minr <= maxr && minc <= maxc)
                for(int i = minc; i <= maxc; i++) {
                    res.push_back(matrix[minr][i]);
                }
            minr++;
            // Down
            if(minr <= maxr && minc <= maxc)
                for(int i = minr; i <= maxr; i++) {
                    res.push_back(matrix[i][maxc]);
                }
            maxc--;
            // Left
            if(minr <= maxr && minc <= maxc)
                for(int i = maxc; i >= minc; i--) {
                    res.push_back(matrix[maxr][i]);
                }
            maxr--;
            // Up
            if(minr <= maxr && minc <= maxc)
                for(int i = maxr; i >= minr; i--) {
                    res.push_back(matrix[i][minc]);
                }
            minc++;
        }
        return res;
    }        
};
