class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k >= prices.size() / 2) {
            int profit = 0;

            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] > prices[i - 1]) {
                    profit += prices[i] - prices[i - 1];
                }
            }

            return profit;
        }

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