class Solution {
public:
    void solve(
        vector<int>& nums, 
        vector<int>&current, 
        vector<vector<int>>& ans, 
        int index) 
    {
            
        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        solve(nums, current, ans, index + 1);
        current.pop_back();
        solve(nums, current, ans, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;

        solve(nums, current, ans, 0);

        return ans;
    }
};