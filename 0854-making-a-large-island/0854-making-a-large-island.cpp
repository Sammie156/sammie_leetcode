class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c, int id) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid.size())
            return 0;
        if (grid[r][c] != 1) return 0;

        grid[r][c] = id;

        int size = 1;

        size += dfs(grid, r + 1, c, id);
        size += dfs(grid, r - 1, c, id);
        size += dfs(grid, r, c + 1, id);
        size += dfs(grid, r, c - 1, id);

        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;

        vector<int> islandSize(n * n + 2);
        int id = 2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    islandSize[id] = dfs(grid, i, j, id);
                    ans = max(ans, islandSize[id]);
                    id++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int> ids;

                    int dr[4] = {1, -1, 0, 0};
                    int dc[4] = {0, 0, 1, -1};

                    for (int k = 0; k < 4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                        if (grid[nr][nc] > 1) {
                            ids.insert(grid[nr][nc]);
                        }
                    }

                    int curr = 1;
                    for (int id: ids) {
                        curr += islandSize[id];
                    }

                    ans = max(ans, curr);
                }
            }
        }

        return ans;
    }
};