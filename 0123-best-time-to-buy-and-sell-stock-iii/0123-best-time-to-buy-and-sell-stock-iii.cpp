class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN, sell1 = 0, hold2 = INT_MIN, sell2 = 0;

        for (int price : prices) {
            hold1 = max(hold1, -price);
            sell1 = max(sell1, hold1 + price);
            hold2 = max(hold2, sell1 - price);
            sell2 = max(sell2, hold2 + price);
        }

        return sell2;
    }
};