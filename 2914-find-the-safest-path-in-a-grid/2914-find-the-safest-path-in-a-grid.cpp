class Solution {
public:
    bool canReach(int threshold, vector<vector<int>>& dist) {
        int n = dist.size();

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        if (dist[0][0] < threshold) return false;
        if (dist[n - 1][n - 1] < threshold) return false;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1) return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;
                if (visited[nr][nc])
                    continue;
                if (dist[nr][nc] < threshold)
                    continue;
                
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        queue<pair<int, int>> q;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    dist[r][c] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r + 1 < grid.size() && dist[r + 1][c] == INT_MAX) {
                dist[r + 1][c] = dist[r][c] + 1;
                q.push({r + 1, c});
            }
            if (r - 1 >= 0 && dist[r - 1][c] == INT_MAX) {
                dist[r - 1][c] = dist[r][c] + 1;
                q.push({r - 1, c});
            }
            if (c - 1 >= 0 && dist[r][c - 1] == INT_MAX) {
                dist[r][c - 1] = dist[r][c] + 1;
                q.push({r, c - 1});
            }
            if (c + 1 < grid[0].size() && dist[r][c + 1] == INT_MAX) {
                dist[r][c + 1] = dist[r][c] + 1;
                q.push({r, c + 1});
            }
        }

        int high = 0, low = 0, ans = 0;

        for (auto &row: dist) {
            for (int dist : row) {
                high = max(high, dist);
            }
        }

        while (low <= high) {
            int mid = (low + high) / 2;

            if (canReach(mid, dist)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};