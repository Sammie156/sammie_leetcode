class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int jumps = 0, current_end = 0, farthest = 0;

        for (int i = 0; i < nums.size(); i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == current_end) {
                current_end = farthest;
                jumps++;

                if (current_end == nums.size() - 1) {
                    break;
                }
            }
        }

        return jumps;
    }
};