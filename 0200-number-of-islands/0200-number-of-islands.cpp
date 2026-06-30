class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() ||
            c < 0 || c >= grid[0].size()) {
            return;
        }

        if (grid[r][c] == '0') return;

        grid[r][c] = '0';

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    ans++;
                    dfs(grid, r, c);
                }
            }
        }

        return ans;
    }
};