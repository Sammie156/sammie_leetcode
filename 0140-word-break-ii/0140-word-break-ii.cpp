class Solution {
public:
    unordered_set<string> dict;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());

        return dfs(s, 0);
    }

    vector<string> dfs(string s, int start) {
        if (start == s.size()) {
            return {""};
        }

        vector<string> result;

        for (int end = start; end < s.size(); end++) {
            string word = s.substr(start, end - start + 1);

            if (!dict.count(word)) {
                continue;
            }

            vector<string> suffixes = dfs(s, end + 1);

            for (string suffix: suffixes) {
                if (suffix.empty()) {
                    result.push_back(word);
                } else {
                    result.push_back(word + " " + suffix);
                }
            }
        }

        return result;
    }
};