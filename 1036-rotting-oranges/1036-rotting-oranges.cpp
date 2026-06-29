class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> rotten;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) fresh++;
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                }
            }
        }

        int minutes = 0;

        while (!rotten.empty()) {
            int size = rotten.size();

            for (int i = 0; i < size; i++) {
                auto [r, c] = rotten.front();
                rotten.pop();

                if (r - 1 >= 0 && grid[r - 1][c] == 1) {
                    grid[r - 1][c] = 2;
                    rotten.push({r - 1, c});
                    fresh--;
                }
                if (r + 1 < grid.size() && grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    rotten.push({r + 1, c});
                    fresh--;
                }
                if (c - 1 >= 0 && grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    rotten.push({r, c - 1});
                    fresh--;
                }
                if (c + 1 < grid[0].size() && grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    rotten.push({r, c + 1});
                    fresh--;
                }
            }

            if (!rotten.empty()) minutes++;
        }

        cout << fresh << endl;

        if (fresh == 0) return minutes;
        else return -1;
    }
};