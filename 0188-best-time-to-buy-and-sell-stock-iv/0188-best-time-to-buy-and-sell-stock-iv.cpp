class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> hold(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);

        for (int price : prices) {
            for (int t = 1; t <= k; t++) {
                hold[t] = max(hold[t], sell[t - 1] - price);
                sell[t] = max(sell[t], hold[t] + price);
            }
        }

        return sell[k];
    }
};