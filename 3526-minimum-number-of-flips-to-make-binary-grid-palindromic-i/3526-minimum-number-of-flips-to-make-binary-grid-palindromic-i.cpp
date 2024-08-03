class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
    int m = grid.size();
        int n = grid[0].size();
        int rowFlips = 0, colFlips = 0;

        for (int i = 0; i < m; i++) {
            int flips = 0;
            for (int j = 0; j < n / 2; j++) {
                if (grid[i][j] != grid[i][n - j - 1]) {
                    flips++;
                }
            }
            rowFlips += min(flips, n - flips);
        }

        for (int j = 0; j < n; j++) {
            int flips = 0;
            for (int i = 0; i < m / 2; i++) {
                if (grid[i][j] != grid[m - i - 1][j]) {
                    flips++;
                }
            }
            colFlips += min(flips, m - flips);
        }

        return min(rowFlips, colFlips);
    }
};