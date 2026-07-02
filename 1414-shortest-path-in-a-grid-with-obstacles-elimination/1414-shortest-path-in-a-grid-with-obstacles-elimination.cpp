class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> best(rows, vector<int>(cols, -1));
        queue<tuple<int, int, int>> q;

        int startObstacles = k - grid[0][0];
        if (startObstacles < 0) return -1;
        best[0][0] = startObstacles;
        q.push({0, 0, startObstacles});

        int steps = 0;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c, o] = q.front();
                q.pop();

                if (r == rows-1 && c == cols - 1) {
                    return steps;
                }

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

                    int newResource = o - grid[nr][nc];
                    if (newResource < 0) continue;
                    if (newResource <= best[nr][nc]) continue;

                    best[nr][nc] = newResource;
                    q.push({nr, nc, newResource});
                }
            }
            steps++;
        }

        return -1;
    }
};