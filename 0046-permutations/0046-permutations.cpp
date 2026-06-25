class Solution {
public:
    void solve(
        vector<int>& nums,
        vector<int>& current,
        vector<bool>& used,
        vector<vector<int>>& ans
    )
    {
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            current.push_back(nums[i]);
            solve(nums, current, used, ans);
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);
        vector<int> current;

        solve(nums, current, used, ans);

        return ans;
    }
};