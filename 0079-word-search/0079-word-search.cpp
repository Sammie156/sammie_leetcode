class Solution {
public:
    bool dfs(vector<vector<char>>& board, int r, int c, string& word, int index) {
        if (index == word.size()) return true;

        
        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size()) {
                return false;
            }
        
        if (board[r][c] == '#') return false;
        if (board[r][c] != word[index]) return false;

        char temp = board[r][c];
        board[r][c] = '#';

        bool down = dfs(board, r + 1, c, word, index + 1);
        bool up = dfs(board, r - 1, c, word, index + 1);
        bool right = dfs(board, r, c + 1, word, index + 1);
        bool left = dfs(board, r, c - 1, word, index + 1);

        board[r][c] = temp;

        return down || up || right || left;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, i, j, word, 0))
                    return true;
            }
        }

        return false;
    }
};