class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        unordered_map<string, vector<string>> hmap;

        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];

            sort(str.begin(), str.end());
            hmap[str].push_back(strs[i]);
        }

        for (auto& [key, value]: hmap) {
            res.push_back(value);
        }

        return res;
    }
};