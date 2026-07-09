class Solution {
public:
    void dfs(
        vector<vector<char>>& grid,
        int r,
        int c
    ) {
        if (grid[r][c] == '0') return;

        grid[r][c] = '0';

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size()) {
                continue;
            }

            dfs(grid, nr, nc);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};