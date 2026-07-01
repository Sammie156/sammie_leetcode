class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }

        int minutes = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                int dr[4] = {1, -1, 0, 0};
                int dc[4] = {0, 0, 1, -1};

                for (int j = 0; j < 4; j++) {
                    int nr = r + dr[j];
                    int nc = c + dc[j];

                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                        continue;
                    
                    if (grid[nr][nc] == 1) {
                        q.push({nr, nc});
                        fresh--;
                        grid[nr][nc] = 2;
                    }
                }

            }
            if (!q.empty()) minutes++;
        }

        if (fresh == 0) return minutes;
        else return -1;
    }
};