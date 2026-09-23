class Solution {
public:
    vector<vector<int>> memo;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        memo.assign(rows, vector<int>(cols, 0));

        int answer = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                answer = max(answer, dfs(matrix, i, j));
            }
        }

        return answer;
    }

    int dfs(
        vector<vector<int>>& matrix,
        int r,
        int c
    ) {
        if (memo[r][c] != 0) {
            return memo[r][c];
        }

        int best = 1;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= matrix.size() ||
                nc < 0 || nc >= matrix[0].size()) {
                continue;
            }

            if (matrix[nr][nc] > matrix[r][c]) {
                best = max(best, 1 + dfs(matrix, nr, nc));
            }
        }

        memo[r][c] = best;
        return best;
    }
};