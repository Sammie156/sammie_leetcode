class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1) return -1;

        // X, Y and distance
        queue<tuple<int, int, int>> points;

        points.push({0, 0, 1});
        grid[0][0] = 1; // visited;

        while (!points.empty()) {
            auto [x, y, dist] = points.front();
            points.pop();

            if (x == rows - 1 && y == cols - 1) {
                return dist;
            }

            int dr[8] = {0, 0, 1, -1, -1, 1, -1, 1};
            int dc[8] = {1, -1, 0, 0, 1, 1, -1, -1};

            for (int i = 0; i < 8; i++) {
                int nx = x + dr[i];
                int ny = y + dc[i];

                if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) {
                    continue;
                }
                if (grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;
                    points.push({nx, ny, dist + 1});
                }
            }
        }

        return -1;
    }
};