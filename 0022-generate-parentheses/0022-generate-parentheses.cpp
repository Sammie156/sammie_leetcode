class Solution {
public:
    void solve(vector<string>& ans, string curr, int size, int open, int close) {
        if (curr.size() == 2 * size) {
            ans.push_back(curr);
            return;
        }

        if (open < size) {
            curr.push_back('(');
            solve(ans, curr, size, open + 1, close);
            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');
            solve(ans, curr, size, open, close + 1);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(ans, "", n, 0, 0);

        return ans;
    }
};