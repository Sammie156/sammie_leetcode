class Solution {
public:
    void solve(
        vector<int>& nums,
        vector<int>& curr,
        vector<vector<int>>& ans,
        int remain,
        int index
    )
    {
        if (remain == 0) {
            ans.push_back(curr);
            return;
        }

        if (remain < 0) return;

        for (int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            solve(nums, curr, ans, remain - nums[i], i);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(candidates, curr, ans, target, 0);

        return ans;
    }
};