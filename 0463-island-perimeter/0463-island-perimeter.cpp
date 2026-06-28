class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() ||
            c < 0 || c >= grid[0].size()) {
                return 1;
            }
        
        if (grid[r][c] == 0) return 1;
        if (grid[r][c] == 2) return 0;

        grid[r][c] = 2;

        int down = dfs(grid, r + 1, c);
        int up = dfs(grid, r - 1, c);
        int right = dfs(grid, r, c + 1);
        int left = dfs(grid, r, c - 1);

        return down + up + right + left;
    } 

    int islandPerimeter(vector<vector<int>>& grid) {
        int per = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    per = dfs(grid, r, c);
                }
            }
        }

        return per;
    }
};