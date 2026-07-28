class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0, prev2 = 0;

        for (int amount : nums) {
            int curr = max(prev1, prev2 + amount);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};