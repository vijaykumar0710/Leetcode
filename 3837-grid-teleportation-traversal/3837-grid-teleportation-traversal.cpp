class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int minMoves(vector<string>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_map<char, vector<pair<int, int>>> portals;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (isupper(matrix[i][j]))
                    portals[matrix[i][j]].push_back({i, j});

        deque<tuple<int, int, int>> q;
        q.push_back({0, 0, 0}); // row, col, moves

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        unordered_set<char> used_portals;

        while (!q.empty()) {
            auto [row, col, moves] = q.front(); q.pop_front();

            if (visited[row][col]) continue;  // Mark visited when popping
            visited[row][col] = true;

            if (row == m - 1 && col == n - 1)
                return moves;

            char ch = matrix[row][col];
            if (isupper(ch) && !used_portals.count(ch)) {
                used_portals.insert(ch);
                for (auto &[pr, pc] : portals[ch]) {
                    if (!visited[pr][pc] && pr != row || pc != col) {
                        q.push_front({pr, pc, moves});  // zero cost teleport
                    }
                }
            }

            for (auto &d : dirs) {
                int nr = row + d[0], nc = col + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    !visited[nr][nc] && matrix[nr][nc] != '#') {
                    q.push_back({nr, nc, moves + 1});
                }
            }
        }
        return -1;
    }
};
