class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            int s_dig = s[i - 1] - '0';

            if (s_dig != 0) {
                dp[i] += dp[i - 1];
            }

            if (i >= 2) {
                int d_dig = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

                if (d_dig >= 10 && d_dig <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }

        return dp[n];
    }
};