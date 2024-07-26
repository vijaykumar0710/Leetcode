class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> que;
        int freshOranges = 0;

        // Initialize the queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    que.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        if (freshOranges == 0) return 0; // No fresh oranges to begin with

        int minutes = 0;

        while (!que.empty()) {
            int size = que.size();
            bool rotted = false;

            for (int i = 0; i < size; i++) {
                auto [x, y] = que.front();
                que.pop();

                for (auto& dir : directions) {
                    int newX = x + dir[0];
                    int newY = y + dir[1];
        if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        que.push({newX, newY});
                        freshOranges--;
                        rotted = true;
                    }
                }
            }

            if (rotted) minutes++;
        }

        return freshOranges == 0 ? minutes : -1;
    }
};