class Solution {
public:
    void solve(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, int index) {
        ans.push_back(curr);

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            curr.push_back(nums[i]);
            solve(nums, curr, ans, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        sort(nums.begin(), nums.end());

        solve(nums, curr, ans, 0);

        return ans;
    }
};