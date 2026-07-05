class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        
        // dp[r][c] = {max_score, ways}
        // Using n+1 size avoids out-of-bounds boundary checks
        vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n + 1, {-1, 0}));
        
        // Base case: 'S' at bottom-right
        dp[n - 1][n - 1] = {0, 1};
        
        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if ((r == n - 1 && c == n - 1) || board[r][c] == 'X') {
                    continue;
                }
                
                // Find maximum score from Down, Right, and Diagonal-Down-Right
                int max_prev = max({dp[r + 1][c].first, dp[r][c + 1].first, dp[r + 1][c + 1].first});
                
                // If all transitions are unreachable (-1), we cannot reach this cell
                if (max_prev == -1) {
                    continue;
                }
                
                long long ways = 0;
                if (dp[r + 1][c].first == max_prev) ways = (ways + dp[r + 1][c].second) % MOD;
                if (dp[r][c + 1].first == max_prev) ways = (ways + dp[r][c + 1].second) % MOD;
                if (dp[r + 1][c + 1].first == max_prev) ways = (ways + dp[r + 1][c + 1].second) % MOD;
                
                int val = (board[r][c] == 'E') ? 0 : (board[r][c] - '0');
                dp[r][c] = {max_prev + val, (int)ways};
            }
        }
        
        if (dp[0][0].second == 0) {
            return {0, 0};
        }
        
        return {dp[0][0].first, dp[0][0].second};
    }
};